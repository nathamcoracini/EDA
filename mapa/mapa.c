#include <stdio.h>
#include <stdlib.h>

/* Estruturas*/
struct node {
  int data;
  int peso;
  struct node *prox;
};

struct lista {
  struct node *n; //no cabeca
};

struct graph {
  int size; //numero de vertices
  struct lista *lista_adj;
};

/* Funcoes auxiliares*/
struct node* newNode(int data, int peso;) {
  struct node* n = (struct node *) malloc (sizeof(struct node));
  n->data = data;
  n->prox = NULL;
  n->peso = peso;
  return n;
}

struct graph* newGraph(int size) {
  struct graph *g = (struct graph *) malloc (sizeof(struct graph));
  g->size = size;
  g->lista_adj = (struct lista *) malloc (size * sizeof(struct lista));

  for (int i = 0; i < size; i++)
    g->lista_adj[i].n = NULL;

  return g;
}

//cria nova conexao no grafo
void newConn(int u, int v, int peso, struct graph *g) {
  struct node* n = newNode(v - 1, peso); //-1 pois os numeros vao de 1 a n na main
  n->prox = g->lista_adj[u - 1].n;
  g->lista_adj[u - 1].n = n;

  n = newNode(u - 1, peso);
  n->prox = g->lista_adj[v - 1].n;
  g->lista_adj[v - 1].n = n;
}

//funcao auxiliar para busca em profundidade
void buscaProfundidadeAux(struct graph *g, int n, int *visited) {
  for (int i = 0; i < g->size; i++)
    visited[i] = 0;

  buscaProfundidade(g, n, visited);
}

//funcao para busca em profundidade
void buscaProfundidade(struct graph *g, int n, int *visited) {
  struct node* perc = g->lista_adj[n].n;
  visited[n] = 1;

  while(perc) {
    if (visited[perc->data] == 0)
      buscaProfundidade(g, perc->data, visited);
    perc = perc->prox;
  }
}


int main() {

  int N, M, A, B, C;
  scanf("%d%d", &N, &M);

  struct graph *g = newGraph(N); //cria um grafo com N vertices

  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &A, &B, C);
    newConn(A, B, C, g);
  }

  return 0;
}
