#include <math.h>
#include <stdio.h>

#define LIMITE 2

/* calcula distancia entre pontos num plano */
float distancia_euclidiana(float pontoA[], float pontoB[]) {
  float delta_x = pontoB[0] - pontoA[0];
  float delta_y = pontoB[1] - pontoA[1];
  return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int main() {
  float pontoA[LIMITE];
  float pontoB[LIMITE];

  for (int i = 0; i < LIMITE; i++) {
    pontoA[i] = i + 2 * 3;
    pontoB[i] = i - 2 * 1.5;
  }
  printf("A distancia entre os pontos é %f\n",
         distancia_euclidiana(pontoA, pontoB));
  return 0;
}