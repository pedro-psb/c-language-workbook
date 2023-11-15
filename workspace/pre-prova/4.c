#include <stdio.h>

#define n 10

void popular_vetor(float vetor[]) {
  for (int i = 0; i < n; i++) {
    scanf("%f", &vetor[i]);
  }
}

void imprimir_vetor(float vetor[], int tamanho) {
  for (int i=0; i<tamanho; i++){
    printf("%.2f ", vetor[i]);
  }
  printf("\n");
}

int main() {
  float x[n];
  float y[n];
  printf("Entre os 10 valores para o vetor X:\n");
  popular_vetor(x);
  printf("Entre os 10 valores para o vetor Y:\n");
  popular_vetor(y);
  printf("Feito.\n");

  // intercalar x,y em novo vetor z
  float z[n * 2];
  int next = 0;
  for (int i = 0; i < n; i++) {
    z[next] = x[i];
    z[next + 1] = y[i];
    next += 2;
  }
  printf("O valor final Z é:\n");
  imprimir_vetor(z, 20);
  return 0;
}
