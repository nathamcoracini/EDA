#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prox;
};

struct lista {
  struct node *n;
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
  g->lista_adj = (struct lista *) malloc (size * sizeof(struct lista));
  return g;
}

void newConn(int u, int v, struct graph *g) {
  struct node* n = newNode(v);
  n->prox = g->lista_adj[u].n;
  g->lista_adj[u].n = n;
}

void depthFirst(int V, graph *g) {
  int visitado[V];
  for (int i = 0; i < V; v++)
    visitado[i] = 0;

  for (int i = 0; i < V; i++) {
    for (int j = )
      visitado[g->lista_adj[v]->n->data] = 1;
  }

}

int main() {
  int ruas, intersec;

  while (1) {
    scanf("%d%d", &intersec, &ruas);
    if (intersec == 0 && ruas == 0) //entrada 0 0 sai do programa
      return 0;

    struct graph *g = newGraph(intersec);

    int v, w, isUnica; //v e w sao identificadores de interesecao
    for(int i = 0; i < ruas; i++) {
      scanf("%d%d%d", &v, &w, &isUnica);
      if (isUnica == 1) {
        newConn(v, w, g);
      }
      else if (isUnica == 2) {
        newConn(v, w, g);
        newConn(w, v, g);
      }
    }

  }
}
