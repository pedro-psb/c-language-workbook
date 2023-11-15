#include <stdio.h>
#include <stdlib.h>
#define test(fn, exp)                                                          \
  { printf("%s, %f = %s\n", #fn, fn, exp); }

/* popula vetor com números aleatórios */
void popula_vetor(float vetor[], int n){
  for (int i=0; i<n; i++){
    vetor[i] = drand48() * 10;
  }
}

/* calcula média de `n` valores geradoes aleatoriamente em `vetor` */
float calcula_media(float vetor[], int n) {
  float media = 0;
  for (int i = 0; i < n; i++) {
    media += vetor[i];
  }
  media = media / n;
  return media;
}

/* */
int main() {
  // caso 1
  // (1 + 2 + 3 + 4 + 5) / 5
  // 15 / 5 = 3
  float vetor[] = {1, 2, 3, 4, 5};
  test(calcula_media(vetor, 5), "3");

  // caso 2
  // (1 - 2 + 3 - 4 + 5) / 5
  // 3 / 5 = 3/5
  float vetor2[] = {1, -2, 3, -4, 5};
  test(calcula_media(vetor2, 5), "3/5 = 0.6");

  // caso 3 (aleatório)
  float vetor3[10];
  popula_vetor(vetor3, 10);
  test(calcula_media(vetor3, 10), "? (aleatório)");
  return 0;
}
