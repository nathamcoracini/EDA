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
  int *visited;
};

struct node* newNode(int data) {
  struct node* n = (struct node *) malloc (sizeof(struct node));
  n->data = data;
  n->prox = NULL;
  return n;
}

struct graph* newGraph(int size) {
  struct graph *g = (struct graph *) malloc (sizeof(struct graph));
  g->visited = (int *) malloc (size * sizeof(int));
  g->size = size;
  g->lista_adj = (struct lista *) malloc (size * sizeof(struct lista));

  for (int i = 0; i < size; i++) {
    g->lista_adj[i].n = NULL;
    g->visited = 0;
  }

  return g;
}

void buscaProfundidade(struct graph *g, int v) {
  struct node* perc = g->lista_adj[v].n;
  g->visited[v] = 1;

  while(perc) {
    if(!g->visited[perc->data])
      buscaProfundidade(g, perc->data);
  }
}

void newConn(int u, int v, struct graph *g) {
  struct node* n = newNode(v - 1);
  n->prox = g->lista_adj[u - 1].n;
  g->lista_adj[u - 1].n = n;
}

int fortConnected(struct graph *g, struct graph *g_transp) {
  buscaProfundidade(g, g->lista_adj[0].n->data);

  for (int i = 0; i < g->size; i++) {
    if (g->visited[i] == 0)
      return 0;
  }

  buscaProfundidade(g_transp, g_transp->lista_adj[0].n->data);

  for (int i = 0; i < g_transp->size; i++) {
    if (g_transp->visited[i] == 0)
      return 0;
  }
  return 1;

}

int main() {
  int ruas, intersec;

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

    printf("%d\n", fortConnected(g, g_transp));

  }
}
