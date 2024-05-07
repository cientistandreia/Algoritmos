#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM_MAX 100000


   clock_t start, end;
double cpu_time_used;

void comparaTempo()
{
    printf("comparaTempo() começa agora \n");
    printf("Press enter pare comparaTempo\n");
    while(1)
    {
        if (getchar())
            break;
    }
    printf("comparaTempo() termina aqui \n");
}



int buscaSequencial(int vet1[TAM_MAX], int valor){
    //cria vetor novo, passar o vetor como parametro 
    int chave = valor;
    int i, contador=0;

    for(i=0; i<TAM_MAX; i++){


         contador++;
        if(vet1[i] == chave) {
printf("%d", contador);


   return 0;
        }

    }
printf("%d se nao achou", contador);
    return -1;
}


// The main program calls fun() and measures time taken by fun()
int main()
{
     int VetOrdenado[TAM_MAX], PosMaior, PosMenor;

    int menor, maior, chave = 0;
    int i, j;

    for (i=0;i <TAM_MAX;i++){

VetOrdenado[i]= rand() %TAM_MAX;

}

//busca pior caso

        // Calcula o  tempo  com a função comparaTempo()
        clock_t t;
        t = clock();
        t = clock() - t;
//conta as comparações, 
//memoria
for(i=0;i<3;i++)
{
        start = clock();

buscaSequencial(VetOrdenado,  TAM_MAX+1);//fora do range nunca pega o valor
//
 
    /* Do the work. */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n",cpu_time_used);

    

}

    for(i=0;i<100;i++)
    {
            start = clock();

    buscaSequencial(VetOrdenado,  rand()%TAM_MAX);//fora do range nunca pega o valor
    //

        /* Do the work. */
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n",cpu_time_used);



    }

    //fazer a media de comparações e desvio padrão no excel
    return 0;
}