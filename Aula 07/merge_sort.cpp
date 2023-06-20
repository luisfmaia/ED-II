#include <stdio.h>
// #include <math.h>

void divide(int *vetor, int start, int end) {
  if (end == start) {
    printf("Caso base 1 elemento: %d\n", vetor[start]);
    return;
  }

  if (end - start == 1) {
    printf("Caso base 2 elementos: (%d,%d)\n", vetor[start], vetor[end]);
    return;
  }

  int meio = (start + end) / 2.0;
  int *metade1 = divide(vetor, start, meio);
  int *metade2 = divide(vetor, meio + 1, end);

  int *res = merge(metade1, metade2);
  return res;
}

int main(int argc, char const *argv[]) {
  int vetor[] = {8, 7, 3, 9, 2, 5, 6, 1, 4, 10};
  divide(vetor, 0, 9);
  return 0;
}
