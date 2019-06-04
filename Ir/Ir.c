#include <stdio>

struct _node {
  int data;
  structo node* prox;
} node;

int main() {
  int ruas, intersec;

  while (true) {
    scanf("%d%d", &intersec, &ruas);
    if (intersec == 0 && ruas == 0) //entrada 0 0 sai do programa
      return 0;

    int v, w, isUnica; //v e w sao identificadores de interesecao
    for(int i = 0; i < ruas; i++)
      scanf("%d%d%d", &v, &w, &isUnica);


  }
}
