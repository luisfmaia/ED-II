#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cel {
  int num = 0;
  cel *ant = NULL;
  cel *prox = NULL;
} celula;

typedef struct list {
  celula *inicio = NULL;
  celula *fim = NULL;
  int tamanho = 0;
} lista;

void anexar_inicio(lista *nova, lista *lista) {
  if ((lista == NULL) || (lista->tamanho == 0)) {
    return;
  }
  nova->tamanho += lista->tamanho;
  nova->inicio->ant = lista->fim;
  lista->fim->prox = nova->inicio;
  nova->inicio = lista->inicio;
}

void anexar_fim(lista *nova, lista *lista) {
  if ((lista == NULL) || (lista->tamanho == 0)) {
    return;
  }
  nova->tamanho += lista->tamanho;
  nova->fim->prox = lista->inicio;
  lista->inicio->ant = nova->fim;
  nova->fim = lista->fim;
}

void remover(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL) || (lst->tamanho == 0)) {
    return;
  }

  if ((lst->inicio == elemento) && (lst->fim == elemento)) {
    lst->tamanho = 0;
    lst->inicio = NULL;
    lst->fim = NULL;
  }

  lst->tamanho--;

  if (lst->inicio == elemento) {
    lst->inicio = lst->inicio->prox;
    lst->inicio->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  if (lst->fim == elemento) {
    lst->fim = lst->fim->ant;
    lst->fim->prox = NULL;
    elemento->ant = NULL;
    return;
  }

  celula *antElem = elemento->ant;
  celula *proxElem = elemento->prox;
  antElem->prox = proxElem;
  proxElem->ant = antElem;

  elemento->ant = NULL;
  elemento->prox = NULL;
}

void inserir_inicio(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL)) {
    return;
  }

  if (lst->tamanho == 0) {
    lst->inicio = elemento;
    lst->fim = elemento;
    lst->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  elemento->ant = NULL;
  elemento->prox = lst->inicio;
  lst->inicio->ant = elemento;
  lst->inicio = elemento;
  lst->tamanho++;
}

void inserir_fim(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL)) {
    return;
  }

  if (lst->tamanho == 0) {
    lst->inicio = elemento;
    lst->fim = elemento;
    lst->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  elemento->prox = NULL;
  elemento->ant = lst->fim;
  lst->fim->prox = elemento;
  lst->fim = elemento;
  lst->tamanho++;
}

void quick_sort(lista *lst) {
  if ((lst == NULL) || (lst->tamanho <= 1)) {
    return;
  }

  int tam_metade = lst->tamanho / 2;
  celula *pivo = lst->inicio;
  for (int i = 0; i < tam_metade; i++) {
    pivo = pivo->prox;
  }
  lista menores;
  lista maiores;

  celula *aux = lst->inicio;
  celula *elemento = NULL;
  while (aux != NULL) {
    elemento = aux;
    aux = aux->prox;
    if (elemento == pivo) {
      continue;
    }
    remover(lst, elemento);
    if (elemento->num < pivo->num) {
      inserir_inicio(&menores, elemento);
    } else {
      inserir_fim(&maiores, elemento);
    }
  }

  quick_sort(&menores);
  anexar_inicio(lst, &menores);

  quick_sort(&maiores);
  anexar_fim(lst, &maiores);
}

void divide(lista *lista1, lista *lista2) {
  int tam_metade = lista1->tamanho / 2;
  celula *inicio2 = lista1->inicio;
  for (int i = 0; i < tam_metade; i++) {
    inicio2 = inicio2->prox;
  }

  celula *fim1 = inicio2->ant;
  fim1->prox = NULL;
  inicio2->ant = NULL;

  lista2->inicio = inicio2;
  lista2->fim = lista1->fim;
  lista2->tamanho = lista1->tamanho - tam_metade;

  lista1->fim = fim1;
  lista1->tamanho = tam_metade;
}

void imprimir(lista *lst) {
  celula *aux = lst->inicio;
  while (aux != NULL) {
    printf("%d -> ", aux->num);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void gerar_aleatorios(lista *lst, int qnt) {
  celula *elem;
  for (int i = 0; i < qnt; i++) {
    elem = new celula;
    elem->num = rand() % 10;
    inserir_inicio(lst, elem);
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  lista *lst = new lista;
  gerar_aleatorios(lst, 10);
  imprimir(lst);
  quick_sort(lst);
  imprimir(lst);

  return 0;
}
