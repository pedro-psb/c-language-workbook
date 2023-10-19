/* Faça um programa que leia 10 números do teclado e
 * mostre o maior dentre eles.
 */
#include <stdio.h>

int main() {
  float lido;
  float maior;
  printf("digite 10 numeros\n");
  scanf("%f", &lido);
  maior = lido;
  for (int i = 0; i < 9; i++) {
    scanf("%f", &lido);
    if (lido > maior) {
      maior = lido;
    }
  }
  printf("O maior foi %f\n", maior);
  return 0;
}
