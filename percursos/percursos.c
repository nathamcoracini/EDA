#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 501

typedef int T;

struct node {
  struct node *esq, *dir;
  T data;
};

struct queue {
  struct node *q[MAXSIZE];
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

struct node *init (T data) {
  struct node* newNode = (struct node*) malloc (sizeof(struct node));
  newNode->esq = newNode->dir = NULL;
  newNode->data = data;
  return newNode;
}

void pos_order(struct node* node) {

  if (node) {
    if (node->esq)
      pos_order(node->esq);

    if (node->dir)
      pos_order(node->dir);

    printf(" %d", node->data);
  }
  return;
}

void pre_order(struct node* node) {
  if (node) {
    printf(" %d", node->data);

    if (node->esq)
      pre_order(node->esq);

    if (node->dir)
      pre_order(node->dir);
  }
  return;
}

void in_order(struct node* node) {
  if (node) {

    if (node->esq)
      in_order(node->esq);

    printf(" %d", node->data);

    if (node->dir)
      in_order(node->dir);
  }
  return;
}

void in_level(struct node* node) {

  struct queue q;
  initqueue(&q);
  struct node *p = node;
  enqueue(p, &q);

  while (q.size > 0) {
    p = dequeue(&q);
    printf(" %d", p->data);

    if (p->esq)
        enqueue(p->esq, &q);

    if (p->dir)
        enqueue(p->dir, &q);
  }
}

struct node *insert(struct node *node, T data) {

  if (node == NULL) {
    node = init(data);
    return node;
  }
  if (data < node->data)
    node->esq = insert(node->esq, data);
  else if (data > node->data)
    node->dir = insert(node->dir, data);

  return node;
}

void destroy_tree(struct node* node) {

  if (node) {
    if (node->esq)
      destroy_tree(node->esq);

    if (node->dir)
      destroy_tree(node->dir);

    free(node);
  }
  return;
}

void print(struct node* node) {
  printf("Pr.:");
  pre_order(node);
  printf("\n");

  printf("In.:");
  in_order(node);
  printf("\n");

  printf("Po.:");
  pos_order(node);
  printf("\n");

  printf("Ni.:");
  in_level(node);
  printf("\n");
}

int main() {

  struct node* raiz = NULL;

  int n;
  scanf("%d", &n);

  int data;
  scanf("%d", &data);
  raiz = insert(raiz, data); //Inserir primeiro elemento

  for (int i = 1; i < n; i++) { //Insere os demais elementos
    scanf("%d", &data);
    insert(raiz, data);
  }

  print(raiz); //Printa os percursos na tela
  destroy_tree(raiz); //Desaloca a memoria
  return 0;
}
