#include <stdio.h>
#include <stdlib.h>
#define N 60

/* popula vetor com valores aleatórios */
void popular_vetor(float vetor[]) {
  for (int i = 0; i < N; i++) {
    vetor[i] = drand48() * 365;
  }
}

/* imprime um `vetor` de tamanho `n` */
void imprimir_vetor(float vetor[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%.2f  ", vetor[i]);
  }
  printf("\n");
}

/* verifica se `valor` está contido em `vetor`.
 *
 * 0=Falso
 * 1=Verdadeiro
 */
int valor_contido_em(float valor, float vetor[], int n) {
  for (int i = 0; i < n; i++) {
    if (valor == vetor[i]) {
      return 1;
    }
  }
  return 0;
}

/* união de vetores */
int main() {
  float x[N];
  float y[N];
  popular_vetor(x);
  popular_vetor(y);

  printf("\nVetor X:\n");
  imprimir_vetor(x, N);

  printf("\nVetor Y:\n");
  imprimir_vetor(y, N);

  // imprime união de x e y
  float uniao[N * 2];
  printf("\nUnião de X e Y é:\n");

  // adiciona todos os elementos de X ao vetor união
  for (int i = 0; i < N; i++) {
    uniao[i] = x[i];
  }

  // adiciona todos os element de Y não presentes em X ao vetor uniao
  int next = N; /* proximo indice livre de uniao */
  for (int i = 0; i < N; i++) {
    if (!valor_contido_em(y[i], x, N)) {
      uniao[next] = x[i];
      next++;
    }
  }

  imprimir_vetor(uniao, next);
  printf("(total de %d elementos)\n", next);

  return 0;
}
