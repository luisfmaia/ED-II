#include <stdio.h>

void bubble_sort() {
  int vetor[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = 9;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < n; i++) {
      if (vetor[i] > vetor[i + 1]) {
        int aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("-> %d", vetor[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  bubble_sort();
  return 0;
}
