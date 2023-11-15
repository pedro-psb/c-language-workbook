#include <stdio.h>

#define LIMITE 3

float media(int vetor[]) {
  // int quantidade = sizeof(vetor) / sizeof(int);
  int quantidade = LIMITE;
  float soma = 0;
  for (int i = 0; i < quantidade; i++) {
    soma = soma + vetor[i];
  }
  float media = soma / quantidade;
  return media;
}

int main() {
  int x[LIMITE];
  for (int i = 0; i < LIMITE; i++) {
    x[i] = i * 5;
  }
  printf("A MEDIA É IGUAL A %f\n", media(x));
  return 0;
}
