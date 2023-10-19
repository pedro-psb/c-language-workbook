/*
 * Escreva um programa que leia, do teclado, valores para dois
 * vetores A e B de tamanho 3.
 * Posteriormente, crie uma lógia capaz de criar um vetor C
 * resultante da subtração de  A e B (A-B).
 */
#include <stdio.h>

int main() {
  int vetorA[3];
  int vetorB[3];
  int vetorC[3];
  printf("Digite os valores [x,y,z] para dois vetores\n");
  scanf("%d %d %d", &vetorA[0], &vetorA[1], &vetorA[2]);
  scanf("%d %d %d", &vetorB[0], &vetorB[1], &vetorB[2]);
  for (int i = 0; i < 3; i++) {
    vetorC[i] = vetorB[i] - vetorA[i];
  }

  printf("A - B = [%d, %d, %d]\n", vetorC[0], vetorC[1], vetorC[2]);

  return 0;
}
