#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 6 //tamanho total de vertices do grafo
#define true 1
#define false 0



void grafocomp(int grafo[max+1][max+1], int grafo2[max+1][max+1]);
TipoFila* intersec(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1]);
TipoFila* vertadj2(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1]);
void BronKerbosch2(TipoFila *VA, TipoFila *CLIQUES, int v, int grafo[max+1][max+1], int vis[max+1], int m[max+1][max+2], int v2);
void maior(int m[max+1][max+2]);
TipoFila* DFS(TipoFila *l, int grafo[max+1][max+1], int v, int vis[max+1]);
