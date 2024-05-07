//andreia zanette - 6/5/2023
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Rand
#define TAM_MAX 400000
#define TAM_MIN 100000
#define STEP 100000
int i, n;
   clock_t start, end;
double cpu_time_used;



int buscaSequencial(int Vet1[],  int tam, int chave);
int buscaSequencial(int Vet1[],  int tam, int chave){
    int i=0;
    chave =0;
    for(i=0; i<tam; i++){
        if(Vet1[i] == chave)
            return i;
    }
    return-1 ;// se ele nao achar
}

int buscaBinaria(int vet[], int tam, int chave);
int buscaBinaria(int vet[], int tam, int chave){
    int posIni=0, posFim=tam-1, posMeio;
    while(posIni <= posFim){ //enquanto o vetor tiver pelo menos 1 elemento
        posMeio = (posIni+posFim)/2;
        if(vet[posMeio] == chave)
            return posMeio;
        else if(vet[posMeio] > chave)
            posFim = posMeio - 1;
        else
            posIni = posMeio + 1;
    }
    return -1;
}

int comparaTempo()
{
    printf("comparaTempo() começa agora \n");
    printf("Press enter pare comparaTempo\n");
    /*while(1)
    {
        if (getchar())
            break;
    }*/
    printf("comparaTempo() termina aqui \n");
    return 0;
}

//int rand(int i);

int el;
//  measures time taken by comparaTempo()
int main() {
    int tam = 0;
    int Vet1[tam];
    int pos, i=0, chave = 0;// el =0;
    
  //  printf("%i\n",buscaSequencial(&Vet1[TAM_MAX], TAM_MIN, TAM_MAX));
    printf("Gerando 10 valores aleatorios :\n\n");

    //int buscaSequencial(Vet1[i], tam , el);
    //inicializar o vetor com os valores -1
    for(i=0; i < TAM_MAX; i++) {
         Vet1[i]=i;

        /* Do the work. */
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n",cpu_time_used);
        printf("Vet1[%d] = %d\n", i, Vet1[i]);

    }

    comparaTempo();


     // gerando valores aleatórios entre zero e 3 para o pior caso */
        
    for (i = 0; i < 3; i++) {

                start = clock();

        buscaBinaria(&Vet1[TAM_MAX+1], TAM_MAX +1, chave);
 
            /* Do the work. */
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("%f\n",cpu_time_used);
      
    }

       /// int chave =0;
        for (i = 0; i < 100; i++) {
            if (chave < Vet1[i])
                chave = Vet1[i];

            // buscaSequencial(&Vet1[i], 10, 8);
            // buscaSequencial(&Vet1[i], n , chave);
            //buscaBinaria(&Vet1[i], tam=10 , chave=0);

            printf("%d, ", Vet1[i]);
            printf("\n");

            printf("%d ", rand() % 100);
            pos = buscaBinaria(&Vet1[TAM_MAX], rand()%TAM_MIN, rand()%TAM_MAX);

                if(pos != -1)
            printf("A posicao da chave 15 no vetor ´e: %d\n", pos);
                else
            printf("A chave 15 n~ao est´a no vetor! \n");
            printf("%d ", rand() % 100);
            //  printf("%d", Vet1[i]);// busca sequencial

            printf("%i\nbuscaBinaria", buscaBinaria(&Vet1[TAM_MAX], rand()%TAM_MIN, rand()%TAM_MAX ));
            //chave = rand(0-TAM_MAX);
             start = clock();
                /* Do the work. */
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

              printf("%f",cpu_time_used);

        }




    // Calcula o  tempo  com a função comparaTempo()
    clock_t t=clock();
    t=clock() -t;
    int time = ((int)t)/CLOCKS_PER_SEC; // in seconds
    printf("comparaTempo() took %f seconds to execute \n", time);

  //  getch();

    return 0;
}
