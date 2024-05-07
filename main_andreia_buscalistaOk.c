//Andreia Zanette 6/5/2024
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 400000
#define false -1
#define FALSE 0
#define TRUE !0

/*void insere_ordenado(No *l,int info// int ch) Insere o elemento info de
maneira ordenada na lista
{
 Noh *ant;
 No *aux=( No*) malloc(sizeof(No));
 aux->valor=info;
   for (l->valor!=NULL, l->valor =< aux->valor)
   {


}*/

  int i, n;
     clock_t start, end;
  double cpu_time_used;
int numero_randomico;
  

struct NO {
  int valor;
  struct NO
      *proximo, *aux; // estrutura da lista, um valor e o no apontando pra proximo
};

typedef struct NO No, l;

int ultimo_elemento(No *L);
void mostra_lista(No *in);
int vazia(No *f);
void * lista_busca(No * l, int busca);
No *novaFila();
void* cria();
int lista_vazia(No* l);
void insere_ultimo(No *l, int x);
void insere_primeiro(No *l, int info);
void insere_depois(No *no, int info);
int retira_primeiro(No *l);
int retira_depois(No *no);
int retira_ultimo(No *l);
No* imprime(No* l, No *aux);
/* função de criação de lista: retorna lista vazia*/

void* cria() {
    return NULL;
}

/* função vazia: retorno 1 se vazia ou 0 se não vazia*/

int lista_vazia(No* l) {

   if(l == NULL)

      return 1;  // Retorna 1 que significa verdadeiro, a lista está vazia 

    else

       insere_primeiro(l, numero_randomico);
      return 0; // Retorna 0 que significa falso, a lista não está vazia

}

int ultimo_elemento(No *L) // Retorna a informação do último elemento da Lista
{
  No *p;
  if (L == NULL)
    exit(0);
  else {
    p = L;
    while (p->proximo) // enqto tiver p->proximo
      p = p->proximo;  // guarda ultimo elemento antes de NULL e imprime valor
    return (p->valor);
  }
}

void mostra_lista(No *in) {
  No *p;
  for (p = in; p != NULL; p = p->proximo) // percorre lista imprimindo
    printf("%d\n", p->valor);
}

int vazia(No *f) {
  if (f == NULL)
    return 1;
  else
    return 0;
    printf("fila vazia");
  // return 0;//retorna  se eh vazia
}

No *novaFila() {
  return (NULL); // vai retornar no main a fila como sendo vazia
}

void insere_ultimo(No *l, int x) {
  No *p;
  No *novo_no = (No *)malloc(sizeof(No));

  novo_no->valor = x;
  novo_no->proximo = NULL;

  if (l == NULL)
    l = novo_no;
  else {
    p = l;
    while (p->proximo) // enqto tiver p->proximo
      p = p->proximo;
    p->proximo = novo_no;
  }
}

void insere_primeiro(No *l, int info) {
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = info;
    novo->proximo = l;
    l = novo; //acessa o endereço de l e coloca o novo no inicio da lista

  } else 
    printf("Erro ao alocar memoria!\n");
}

void insere_depois(No *no, int info) // Insere o elemento info depois do nó No
{
  No *novo_no = (No *)malloc(sizeof(No));
  No *z;
  z = no->proximo;
  no->proximo = novo_no;
  novo_no->proximo = z;
  novo_no->valor = info;
}

int retira_primeiro(No *l) // Retira o primeiro elemento da Lista e retorna o
                           // valor da info do No
{
  No *p;
  int num = -1;
  if (l == NULL)
    printf("nao eh possivel retirar, lista vazia");
  else {
    p = l;
    num = p->valor;
    l = p->proximo;
    free(p);
  }
  return (num);
}

int retira_depois(
    No *no) // Retira o elemento posterior ao nó No e retorna a sua informação
{
  No *morta;
  int num = -1;
  if ((no != NULL) && (no->proximo != NULL)) {
    morta = no->proximo;
    num = morta->valor;
    no->proximo = morta->proximo;
    free(morta);
  }
  return (num);
}

int retira_ultimo(
    No *l) // Retira o último elemento da Lista e retorna a informação do Nó
{
  No *p;
  No *z;
  int num = -1;
  if (l == NULL)
    printf("nao eh possivel remover, lista vazia");
  else {
    p = l;
    while (p->proximo) { // enqto tiver p->proximo
      z = p->proximo;
      p = p->proximo;
    }
    num = p->valor;
    p = NULL;
    free(z);
  }
  return (num);
}


/* função que busca um elemento na lista*/

void * lista_busca(No * l, int busca) {

   No *aux;

   if(!vazia(l)) {

       for(aux=l;aux!=NULL;aux=aux->proximo) {

           if(aux->valor == busca) {
      
               busca=rand()%tam;

               printf("Valor encontrado.\n");

               return aux;

           }

       }

      return NULL;

  }

  else {

      printf("\nTentou buscar de uma lista vazia");

      return NULL; 

}

}

/* função que imprime elementos da lista*/

No* imprime(No* l, No *aux) {


if(!lista_vazia(l)) {



    for(aux=l; aux != NULL; aux=aux->proximo)

           printf("valor = %d\n",aux->valor);

}

else

   printf("\nTentou imprimir uma lista vazia");

}

int comparaTempo() {
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

int main() {
  int tabela;
  char tamanhoTabela[1000000], linha[1000000];
     srand((unsigned) time(NULL));
       numero_randomico = rand()%tam;
    
  No *l, * elemento1;

  /* cria dados para inserir */
  int x = 10, y = 25;
  /* cria a lista */

  int info;

  l = cria();

 
  //  insere_primeiro(l, rand()%tam);


/*l=imprime(l, 10);
        l=imprime(l, 20);
          l=imprime(l, 30);
          l=imprime(l, 40);
          l=imprime(l, 50);
          l=imprime(l, 60);
          l=imprime(l, 70);
          l=imprime(l, 80);
          l=imprime(l, 90);
          l=imprime(l, 100);

*/

  /* cria elementos iniciais da lista */
// l= rand()%tam;
    mostra_lista(l);

    
  int num;


/*  for (i = 0; i < 10; i++) {
    insere_primeiro(l, num);

    l = rand();



  }
*/

    for(i=0;i<100;i++)
    {
            start = clock();
         /* testa se lista e’ vazia */
          if (lista_vazia(l))
          printf("Lista vazia\n\n");
          else
          insere_primeiro(l, numero_randomico);
        l=lista_busca( l,  numero_randomico);
        printf("Lista inicial:\n", numero_randomico);
         printf("Lista nao vazia\n\n", numero_randomico);

        if (l <= i)
        
           // l = i;
        printf("insere primeiro valor x lista %i",(&l, numero_randomico));

     //   insere_primeiro(l, y);
             // printf ("%d",insere_primeiro(&lista,x));

            // printf("insere primeiro valor y lista %d",(&l, ));
             // Calcula o  tempo  com a função comparaTempo()
              clock_t t = clock();
              t = clock() - t;
              int time = ((int)t) / CLOCKS_PER_SEC; // in seconds
              printf("comparaTempo() took %f seconds to execute \n", time);

        //lista->valor = i;
           // insere_ultimo(&lista, num);
            /*lê números positivos e armazena na lista*/
          do {
             scanf("%d", &num);
            // No lista;


            insere_primeiro(l, numero_randomico);
              /* testa se estão na lista */
              if(lista_busca(l, x) != NULL) {
                  printf("Hoooray! Ao buscar encontrei X %i (numero_randomico)...\n", numero_randomico);
              } else {
                  printf("ERRO! Ao buscar nao encontrei X %i (numero_randomico)...\n", numero_randomico);
              }

             /* if (lista_busca(l, y) != NULL) {
                  printf("Hoooray! Ao buscar encontrei Y (25)...\n");
              } else {
                  printf("ERRO! Ao buscar nao encontrei Y (25)...\n");
              }
*/
            //  printf("Insere o valor %d na lista\n", num);
              if (num > 0)
                  insere_primeiro(l, numero_randomico);
                  printf("Gerando 100 valores aleatorios %i:\n\n", numero_randomico);
                  printf ("sizeof (No) = %d\n",    sizeof (tam));
                mostra_lista(l);
                } while (num > 0);

        //para o pior caso
        for(i=0;i<3;i++)
        {
            start = clock();

            lista_busca(numero_randomico,  tam+1);//fora do range nunca pega o valor
        
            /* Do the work. */
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("%f\n",cpu_time_used);

        }




    }

    
  }