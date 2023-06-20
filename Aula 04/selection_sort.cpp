#include <stdio.h>

int pos_min(int *vetor, int start, int n) {
  int p_min = start;
  for (int i = start; i < n; i++) {
    if (vetor[p_min] > vetor[i]) {
      p_min = i;
    }
  }
  return p_min;
}

void selection_sort() {
  int vetor[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = 10;
  for (int i = 0; i < n - 1; i++) {
    int p_min = i;

    for (int j = i; j < n; j++) {
      if (vetor[p_min] > vetor[j]) {
        p_min = j;
      }
    }

    if (p_min != i) {
      int aux = vetor[i];
      vetor[i] = vetor[p_min];
      vetor[p_min] = aux;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("-> %d", vetor[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  selection_sort();
  return 0;
}
