#include <stdio.h>

int eh_par(int numero) {
  if (numero % 2 == 0) {
    return 1;
  }
  return 0;
}

int main() {
  for (int i = 0; i <= 1000; i++) {
    if (eh_par(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
