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

struct queue {
  struct node *q[100];
  int size, front, rear;
};

void initqueue (struct queue *q) {
  q->size = 0;
  q->front = -1;
  q->rear = -1;
}

void enqueue(struct node *node, struct queue *q) {
  if (q->rear == -1) {
    q->q[++(q->rear)] = node;
    q->size++;
    q->front = 0;
  }
  else {
    q->q[++(q->rear)] = node;
    q->size++;
  }
}

struct node *dequeue(struct queue *q) {
  q->front++;
  q->size--;
  return (q->q[q->front - 1]);
}

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

//cria nova conexao no grafo
void newConn(int u, int v, struct graph *g) {
  struct node* n = newNode(v - 1); //-1 pois os numeros vao de 1 a n na main
  n->prox = g->lista_adj[u - 1].n;
  g->lista_adj[u - 1].n = n;
}

int buscaLargura(struct graph *g, int ent, int saida, int dist) {
  struct queue *q;
  int visited[g->size];

  for(int i = 0; i < g->size; i++) {
    visited[i] = 0;

  }
}

int main() {
  int N, M, C[10][10], ent, saida;
  scanf("%d%d", &N, &M);

  struct graph *g = newGraph(M * N);

  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      scanf("%d", &C[N][M]);
      if (C[N][M] == 3)
        ent = C[N][M];
      else if (C[N][M] == 1) {
        newConn(N, M, g);
        newConn(M, N, g);
      }
    }


  return 0;
}
