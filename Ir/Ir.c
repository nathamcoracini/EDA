#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prox;
};

struct lista {
  struct node *n; //no cabeca
};

struct graph {
  int size; //numero de vertices
  struct lista *lista_adj;
};

struct node* newNode(int data) {
  struct node* n = (struct node *) malloc (sizeof(struct node));
  n->data = data;
  n->prox = NULL;
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

//funcao para busca em profundidade
void buscaProfundidadeRecur(struct graph *g, int n, int *visited) {
  struct node* perc = g->lista_adj[n].n;
  visited[n] = 1;

  while(perc) {
    if (visited[perc->data] == 0)
      buscaProfundidadeRecur(g, perc->data, visited);
    perc = perc->prox;
  }
}

//funcao para checar se o grafo e fortemente conexo
int strongConnected(struct graph *g, struct graph *g_transp, int n, int *visited) {
  visited = (int *) malloc (sizeof(int) * g->size);

  for (int i = 0; i < g->size; i++)
    visited[i] = 0;

  buscaProfundidadeRecur(g, n, visited);

  for (int i = 0; i < g->size; i++)
    if (visited[i] == 0)
      return 0;

  for (int i = 0; i < g->size; i++)
    visited[i] = 0;

  buscaProfundidadeRecur(g_transp, n, visited);

  for (int i = 0; i < g->size; i++)
    if (visited[i] == 0)
      return 0;

  return 1;
}

//cria nova conexao no grafo
void newConn(int u, int v, struct graph *g) {
  struct node* n = newNode(v - 1); //-1 pois os numeros vao de 1 a n na main
  n->prox = g->lista_adj[u - 1].n;
  g->lista_adj[u - 1].n = n;
}

int main() {
  int ruas, intersec, *visited;

  while (1) {
    scanf("%d%d", &intersec, &ruas);
    if (intersec == 0 && ruas == 0) //entrada 0 0 sai do programa
      return 0;

    struct graph *g = newGraph(intersec);
    struct graph *g_transp = newGraph(intersec);

    int v, w, isUnica; //v e w sao identificadores de interesecao
    for(int i = 0; i < ruas; i++) {
      scanf("%d%d%d", &v, &w, &isUnica);
      if (isUnica == 1) {
        newConn(v, w, g);
        newConn(w, v, g_transp);
      }
      else if (isUnica == 2) {
        newConn(v, w, g);
        newConn(w, v, g);
        newConn(w, v, g_transp);
        newConn(v, w, g_transp);
      }
    }

    printf("%d\n", strongConnected(g, g_transp, 0, visited));

  }
}
