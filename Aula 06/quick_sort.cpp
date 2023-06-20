#include <stdio.h>

void swap(int *vetor, int i, int j) {
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void quick_sort(int *vetor, int start, int end) {
  if (start == end) {
    return;
  }
  if (end - start == 1) {
    if (vetor[start] < vetor[end]) {
      return;
    } else {
      swap(vetor, start, end);
    }
  }

  int pivo = vetor[start];
  int pos = qnt_menores(vetor, pivo);
  swap(vetor, start, pos);

  particiona(vetor, start, end, pos);

  if (pos > 0) {
    quick_sort(vetor, start, pos - 1);
  }
  quick_sort(vetor, pos + 1, end);
}

int main(int argc, char const *argv[]) {
  int vetor[] = {8, 7, 3, 9, 2};
  quick_sort(vetor, 0, 4);
  return 0;
}
