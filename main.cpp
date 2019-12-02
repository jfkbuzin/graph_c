#include "grafo.h"
//O primeiro vertice(1) deve participar do maior clique/conjunto independente para que código funcione
//Só para grafos sem laços e não valorados

int main()
{
  TipoFila *VA;
  TipoFila *CLIQUE;

  int i,j;
  int v;
  int v2;
  int grafo[max+1][max+1];
  int vis[max+1];

  int omega[max+1][max+2];
  int alpha[max+1][max+2];

  int grafoc[max+1][max+1];
  int visc[max+1];


  //para inicializar o gráfo com 0
  for(i=1;i<=max;i++)
    for(j=1;j<=max;j++)
    {
        grafo[i][j]=0;
        grafoc[i][j]=0;
    }

  for(i=1;i<=max;i++)
    for(j=1;j<=(max+1);j++)
    {
        omega[i][j]=0;
        alpha[i][j]=0;
    }



    for (i=1;i<=max;i++)
    {
        vis[i]=false; //inicializando vetor de vertices visitados
        visc[i]=false; //inicializando vetor de vertices visitados
    }


    grafo[1][2]=1;
    grafo[2][1]=1;
    grafo[1][3]=1;
    grafo[3][1]=1;
    grafo[1][4]=1;
    grafo[4][1]=1;
    grafo[2][3]=1;
    grafo[3][2]=1;
    grafo[2][4]=1;
    grafo[4][2]=1;
    grafo[3][4]=1;
    grafo[4][3]=1;

    grafo[1][5]=1;
    grafo[5][1]=1;

    grafo[2][5]=1;
    grafo[5][2]=1;

    grafo[6][5]=1;
    grafo[5][6]=1;

    grafo[6][4]=1;
    grafo[4][6]=1;


    for(v=1; v<=max; v++)
    {
        VA = cria_fila();
        CLIQUE = cria_fila();
        //VA = DFS(VA, grafo, v, vis);
        VA = vertadj2(VA, grafo, v, vis);

        for (i=1;i<=max;i++)
            vis[i]=false;

        puts("Cliques Maximais de G:");
        v2 = 0;
        BronKerbosch2(VA, CLIQUE,v2, grafo, vis, omega, v);

        destroi(VA);

        system("PAUSE");

    }

    puts("Omega de G:");
    maior(omega);

    system("PAUSE");

    grafocomp(grafo, grafoc);

    for(v=1; v<=max; v++)
    {
        VA = cria_fila();
        CLIQUE = cria_fila();
        //VA = DFS(VA, grafoc, v, visc);
        VA = vertadj2(VA, grafoc, v, visc);

        for (i=1;i<=max;i++)
            visc[i]=false;

        puts("Conjuntos Independentes Maximais de G:");
        v2 = 0;
        BronKerbosch2(VA, CLIQUE,v2, grafoc, visc, alpha, v);

        destroi(VA);

        system("PAUSE");

    }

    puts("Alpha de G:");
    maior(alpha);

    system("PAUSE");


}
