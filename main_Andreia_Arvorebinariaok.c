#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 1000000
#define false -1
#define FALSE 0
#define TRUE !0

  int i, n;
     clock_t start, end;
  double cpu_time_used;


  typedef struct No {
  int dado;
  struct No *esq, *dir; /* *pai */
  } No;

  No *criar_no(int x) {
  No *r = malloc(sizeof(No));
  r->dado = x;
  r->esq = NULL;
  r->dir = NULL;
  return r;
  }

  void inserir_no(No *raiz, int x) {
      No *novo = criar_no(x);
      No *atual = raiz;

      while( atual!= NULL){
          if(atual->esq == NULL){
              atual->esq=novo; 
              return;
          } else if (atual->dir == NULL){
              atual->dir = novo;
              return;
          } else{
              atual = atual -> esq;
          }
      }

  }

  void print(No *raiz){
      if(raiz != NULL) {
          printf("%d\n", raiz->dado);
          print(raiz->esq);
          print(raiz->dir);
      }
  }

  void destruir_arvore(No *raiz) {
      No *atual = raiz;

      if(atual!=NULL) {
          destruir_arvore(atual->esq);
          destruir_arvore(atual->dir);
          free(atual);
      }
  }

  No *buscar(No *raiz, int x){
      No *atual = raiz;
      while (atual != NULL)
      {
          if(atual->dado == x) return atual;
          else{
              No *val = buscar(raiz->dir, x);
              if (val == NULL)
              val = buscar(raiz->esq,x);
              return val;

          }
      }
//busca da arvore binaria escolher um dos lados se for menor vai pra esquerda 
//se for maior vai pra direita
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
  int main(void) {

      int x;
      //inicializar o vetor com os valores -1
      for(i=0; i < tam; i++) {
          criar_no(i) ;
      }


    comparaTempo();

    No *tree = criar_no(10);
      for (i = 0; i < 100; i++) {
      inserir_no(tree,11);


            start = clock();
            /* Do the work. */
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            // Calcula o  tempo  com a função comparaTempo()
            clock_t t=clock();
            t=clock() -t;

          printf("%f",cpu_time_used);
            // Calcula o  tempo  com a função comparaTempo()
            int time_taken = ((int)t)/CLOCKS_PER_SEC; // in seconds
            printf("comparaTempo() took %i seconds to execute \n", time_taken);

          printf("%d ", rand() % 100);
      }


        No *n = buscar(tree, 8);


          if(n!= NULL)

           printf("achou %d \n", n->dado);
           else
           printf("nao achou %d \n");
    print(tree);


//      printf("comparaTempo() took %i seconds to execute \n", time_taken);

    return 0;
  }