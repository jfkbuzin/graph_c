#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> //necessaria para o malloc
#include "fila.h"

TipoFila* cria_fila(void)
{
       return NULL;
}

TipoFila* insere (TipoFila *l, int dado)
{
       TipoFila *novo; //novo elemento
       TipoFila *ant = NULL; //ponteiro auxiliar para a posição anterior
       TipoFila *ptaux = l; //ponteiro auxiliar para percorrer a lista

       /*aloca um novo nodo */
       novo = (TipoFila*) malloc(sizeof(TipoFila));

       /*insere a informação no novo nodo*/
       novo->info = dado;
       novo->prox = NULL;

       /*achando o final da fila*/
       while (ptaux!=NULL)
       {
             ant = ptaux;
             ptaux = ptaux->prox;
       }

       /*encaeia o elemento*/
       if (ant == NULL) /*o anterior não existe, logo o elemento será inserido na primeira posição*/
       {
               novo->prox = l;
               l = novo;
       }
       else
       {
           novo->prox = ant->prox;
           ant->prox = novo;
       }

       return l;
}

int vazia (TipoFila* l)
{
     if (l == NULL) return 1;
     else return 0;
}


int remove(TipoFila **l)
{
    TipoFila *rem = *l;
    int aux;
    //puts("aqui");

    if (!vazia(*l))
    {
      aux = (*l)->info;
      *l = (*l)->prox;
      free(rem);
      //puts("aqui2");
      return (aux);
    }
    else
    {
        //puts("aqui3");
        return -1;
    }
}

void imprime(TipoFila* l)
{
     TipoFila* ptaux;
     for (ptaux=l; ptaux!=NULL; ptaux=ptaux->prox)
         printf(" %d \n",ptaux->info);
}

int tamanho(TipoFila* l)
{
     int tam = 0;
     TipoFila* ptaux;
     for (ptaux=l; ptaux!=NULL; ptaux=ptaux->prox)
         tam++;
    printf("tamanho: %d \n",tam);
    return tam;
}

TipoFila* remover(TipoFila* l, int remov)
{
     TipoFila *ant = NULL; //ponteiro auxiliar para a posição anterior
     TipoFila *ptaux = l; //ponteiro auxiliar para percorrer a lista

     /*procura o elemento na lista*/
     while ((ptaux->info != remov)&&(ptaux->prox != NULL))//(ptaux !=NULL && ptaux->info != remov)
     {
          ant = ptaux;
          ptaux = ptaux->prox;
     }

     /*verifica se achou*/
     if (ptaux == NULL)
     {
        return l; /*retorna a lista original*/
     }


    if (ant == NULL) /*vai remover o primeiro elemento*/
    {
        l = ptaux->prox;
    }
    else /*vai remover do meio ou do final*/
    {
      ant->prox = ptaux->prox;
    }

    free(ptaux); /*libera a memória alocada*/

    return l;
}

TipoFila* destroi(TipoFila* l)
{
   TipoFila *ptaux; //ponteiro auxiliar para percorrer a lista
   while (l != NULL)
   {
         ptaux = l;
         l = l->prox;
         free(ptaux);
   }
   free(l);
   return NULL;
}

int primeiro(TipoFila* l)
{
    return l->info;
}
