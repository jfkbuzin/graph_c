#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void visita2 (int vis[max+1], int v)
{
     vis[v]= true;
}


void grafocomp(int grafo[max+1][max+1], int grafo2[max+1][max+1])
{
    int i,j;

    for(i=1;i<=max;i++)
        for(j=1;j<=max;j++)
            if (i != j)
            {
                if(grafo[i][j] == 0)
                    grafo2[i][j]=1;
                else
                    grafo2[i][j]=0;
            }

}

TipoFila* vertadj2(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1])
{
    int w;
    TipoFila *FV;


    visita2(vis,v);
    FV = cria_fila();
    FV = insere(FV,v);
    l = insere(l,v);
    while (!vazia(FV))
    {
       v = remove(&FV);
       for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
          if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
          {
              FV = insere(FV,w);
              l = insere(l,w);
              visita2(vis,w);
           }

    }
    return l;
}


TipoFila* DFS(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1])
{
    int w;
    visita2(vis,v);
    l = insere(l,v);
    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
      if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
         DFS(l, grafo, w, vis); //chamada recursiva para o vértice adjacente a v
    return l;
}

TipoFila* intersec(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1])
{

    TipoFila *vizi;
    int w;
    int i;

    visita2(vis,v); //visitou o primeiro vertice, printf v
    vizi = cria_fila();

    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
        if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
        {

            vizi = insere(vizi,w); //insere o vertice adjacente na lista
            visita2(vis,w);
        }

    for (i=1;i<=max;i++)
        vis[i]=false;

    //puts("lista de adjacentes criada");
    //imprime(vizi);


    TipoFila *ptaux = vizi;
    TipoFila *VA = l;
    TipoFila *ptaux2 = ptaux;

    int temp;

    while(VA != NULL)
    {
        temp = VA->info;;

        while((ptaux2!=NULL)&&(ptaux2->info!=temp))
        {
            ptaux2 = ptaux2->prox;
        }
        if(ptaux2 == NULL)
        {
            l = remover(l, temp);
            VA = l;
            //puts("menos 1");
            if(VA == NULL)
                break;
        }

        VA = VA->prox;
        ptaux2 = ptaux;
    }

    for (i=1;i<=max;i++)
        vis[i]=false;


    destroi(vizi);

    return l;

}


void BronKerbosch2(TipoFila *VA, TipoFila *CLIQUES, int v, int grafo[max+1][max+1], int vis[max+1], int m[max+1][max+2], int v2)
{
    int i;
    int u, w;

    TipoFila *ptaux;


    v = primeiro(VA);
    CLIQUES = insere(CLIQUES, v);

    while(!(vazia(VA)))
    {


            VA = intersec(VA, grafo, v, vis);

            if(!(vazia(VA)))
            {
                v = primeiro(VA);
                CLIQUES = insere(CLIQUES, v);
            }

    }

    if (vazia(VA))
    {

        ptaux = CLIQUES;

        while(ptaux != NULL)
        {
            if(ptaux->prox != NULL)
            {

                u = ptaux->info;
                w = ptaux->prox->info;
            }
            if(grafo[u][w] == 0)
            {
                v = grafo[u][w];

                CLIQUES = remover(CLIQUES, v);

            }
            ptaux = ptaux->prox;

        }

        m[v2][1] = tamanho(CLIQUES); //CLIQUES é  um lista com vertices do clique maximal
        puts("Vertices:");
        imprime(CLIQUES);


        for(i=2;i<=max+2;i++)
        {
            if(vazia(CLIQUES))
                m[v2][i] = 0;
            else
                m[v2][i] = remove(&CLIQUES);
        }
    }
}

void maior(int m[max+1][max+2])
{
    int i,j;

    i = 1;
    j = 1;

    int maximo[max+2];

    for(j=1;j<=(max+1);j++)
            maximo[j] = m[i][j];

    for(i=1;i<=max;i++)
    {
        j = 1;
        if(m[i][j] > maximo[j])
        {
            for(j=1;j<=(max+1);j++)
                    maximo[j] = m[i][j];
        }
    }

    printf(" %d", maximo[1]);

    puts("\nArestas:\n");

    for(j=2;j<=(max+1);j++)
    {
        if(maximo[j] != 0)
            printf(" %d\n", maximo[j]);
    }

}
