#include <stdio.h>

/** Troca de valores
/* Troque os valores de a e b sem alterar código existente.
*/
int main() {
  // não mudar
  float a = 3.14159, b = 2.71828;

  // trocar variaveis aqui
  float tmp = a;
  a = b;
  b = tmp;

  // não mudar
  printf("\nPI = %f", b);
  printf("\nEULER = %f", a);

  printf("\n");
  return 0;
}