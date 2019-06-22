#include <stdio.h>
#include <stdlib.h>

typedef int T;

struct node {
  struct node *esq, *dir;
  T data;
};

struct node *init (T data) {
  struct node* newNode = (struct node*) malloc (sizeof(struct node));
  newNode->esq = newNode->dir = NULL;
  newNode->data = data;
  return newNode;
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

struct node* getFloor(struct node* node, T data) {
  if (node == NULL)
    return NULL;

  if (data == node->data)
      return node;
  else if (data < node->data)
    return getFloor(node->esq, data);

  struct node* r = getFloor(node->dir, data);
  if (r == NULL)
    return node;
  else
    return r;
}


struct node* getCeiling(struct node* node, T data) {
  if (node == NULL)
    return NULL;

  if (data == node->data)
      return node;
  else if (data > node->data)
    return getCeiling(node->dir, data);

  struct node* l = getCeiling(node->esq, data);
  if (l == NULL)
    return node;
  else
    return l;
}

int main() {

  struct node* pocoes = NULL;
  struct node* embalagens = NULL;
  int garrafas[1000];

  int p;
  scanf("%d", &p);

  int n;
  scanf("%d", &n);
  pocoes = insert(pocoes, n);

  for (int i = 1; i < p; i++) {
    scanf("%d", &n);
    insert(pocoes, n);
  }

  int e;
  scanf("%d", &e);

  scanf("%d", &n);
  embalagens = insert(embalagens, n);

  for (int i = 1; i < e; i++) {
    scanf("%d", &n);
    insert(embalagens, n);
  }

  int g;
  scanf("%d", &g);

  for (int i = 0; i < g; i++) {
    scanf("%d", &n);
    garrafas[i] = n;
  }

  //Printar floor e ceiling de pocao e embalagem para cada garrafa
  for (int i = 0; i < g; i++) {
    if (getFloor(pocoes, garrafas[i]) != NULL && getCeiling(embalagens, garrafas[i]) != NULL)
      printf("%d %d\n", getFloor(pocoes, garrafas[i])->data, getCeiling(embalagens, garrafas[i])->data);
    else //Se floor ou celing forem nulos
      printf("descartar\n");
  }

  //Liberar memoria
  destroy_tree(pocoes);
  destroy_tree(embalagens);

  return 0;
}
