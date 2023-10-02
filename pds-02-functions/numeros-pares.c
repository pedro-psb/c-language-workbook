#include <stdio.h>

/* retorna se `numero` é par */
int eh_par(int numero) {
  if (numero % 2 == 0) {
    return 1;
  }
  return 0;
}

/* soma n primeiros numeros inteiros */
int somar_n_primeiros(int n) {
  int soma = 0;
  for (int i = 0; i <= n; i++) {
    soma += i * 2;
  }
  return soma;
}

/* maximo divisor comum. */
int mdc(int a, int b) {
  int _mdc = 1;
  int max, min;
  if (a > b) {
    max = a;
    min = b;
  } else {
    max = b;
    min = a;
  }
  for (int i = min; i > 0; i--) {
    if (max % i == 0 && min % i == 0) {
      return i;
    }
  }
  return 1;
}

/* fatorial */
int fatorial(int n) {
  if (n == 0) {
    return 1;
  }
  int resultado = 1;
  for (int i = n; i >= 1; i--) {
    resultado = resultado * i;
  }
  return resultado;
}

int main() {
  // imprime 1000 primeiros numeros
  for (int i = 0; i <= 1000; i++) {
    if (eh_par(i)) {
      printf("%d ", i);
    }
  }
  printf("\n\n");

  // soma 1000 primeiros numeros
  int n = 1;
  printf("somatorio-de-pares(0-%d) = %d", n, somar_n_primeiros(n));
  printf("\n");
  n = 4;
  printf("somatorio-de-pares(0-%d) = %d", n, somar_n_primeiros(n));
  printf("\n");
  n = 5;
  printf("somatorio-de-pares(0-%d) = %d", n, somar_n_primeiros(n));
  printf("\n");

  int a, b, result;
  a = 15;
  b = 10;
  result = 5;
  printf("mdc(%d, %d)=%d\t%d\n", a, b, mdc(a, b), result);
  a = 21;
  b = 3;
  result = 3;
  printf("mdc(%d, %d)=%d\t%d\n", a, b, mdc(a, b), result);
  a = 3;
  b = 21;
  result = 3;
  printf("mdc(%d, %d)=%d\t%d\n", a, b, mdc(a, b), result);
  a = 6;
  b = 20;
  result = 2;
  printf("mdc(%d, %d)=%d\t%d\n", a, b, mdc(a, b), result);
  a = 23;
  b = 37;
  result = 1;
  printf("mdc(%d, %d)=%d\t%d\n", a, b, mdc(a, b), result);

  printf("%d!=%d\t(%d)\n", 0, fatorial(0), 1);
  printf("%d!=%d\t(%d)\n", 2, fatorial(1), 1);
  printf("%d!=%d\t(%d)\n", 2, fatorial(2), 2);
  printf("%d!=%d\t(%d)\n", 3, fatorial(3), 6);
  printf("%d!=%d\t(%d)\n", 4, fatorial(4), 24);
  printf("%d!=%d\t(%d)\n", 5, fatorial(5), 120);
  return 0;
}
