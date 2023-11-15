#include <stdio.h>
#define N_MAX 100

/* popula vetor e retorna número de elementos que ele contém
 * Em caso de erro, retorna -1
 */
int popular_vetor(float vetor[]) {
  int n;
  printf("Entre o número de elementos que o vetor terá:\n");
  scanf("%d", &n);
  if (n > N_MAX) {
    printf("Error: o número máximo do vetor é %d\n", N_MAX);
    return -1;
  }

  // Lê valor dos elementos
  printf("Entre o valor dos elementos do vetor:\n");
  for (int i = 0; i < n; i++) {
    scanf("%f", &vetor[i]);
  }
  return n;
}

/* imprime um `vetor` de tamanho `n` */
void imprimir_vetor(float vetor[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%.2f ", vetor[i]);
  }
  printf("\n");
}

/* calcula inverso de um vetor */
int main() {
  // entrada de dados
  float vetor[N_MAX];
  int n;
  if ((n = popular_vetor(vetor)) < 0) {
    return 1; // erro
  }

  // criar vetor invertido
  float invertido[n];
  for (int i = 0; i < n; i++) {
    invertido[n - i - 1] = vetor[i];
  }

  // imprime resultados
  printf("Vetor original:\n");
  imprimir_vetor(vetor, n);
  printf("Vetor invertido:\n");
  imprimir_vetor(invertido, n);
  return 0;
}
