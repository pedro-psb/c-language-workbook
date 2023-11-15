#include <stdio.h>
#define test(fn, exp)                                                          \
  { printf("%s\n%f == %s\n", #fn, fn, exp); }
#define MAX_N

/* Retorna produto escalar dos vetores `u` e `v` de dinemnsão `n` */
float produto_escalar(int *u, int *v, int n) {
  float total = 0;
  for (int i = 0; i < n; i++) {
    total += u[i] * v[i];
  }
  return total;
}

int main() {
  // caso 1
  // 2.1 + 2.2 + 2.3 = 12
  int n = 3;
  int u[MAX_N] = {2, 2, 2};
  int v[MAX_N] = {1, 2, 3};
  test(produto_escalar(u, v, n), "12");

  // caso 2
  // 2.1 - 2.2 + 2.3 - 2.4 + 2.5 = 12
  // 2 - 4 + 6 - 8 + 10 = 6
  n = 5;
  int u2[MAX_N] = {2, -2, 2, -2, 2};
  int v2[MAX_N] = {1, 2, 3, 4, 5};
  test(produto_escalar(u2, v2, n), "6");
  return 0;
  ;
}
