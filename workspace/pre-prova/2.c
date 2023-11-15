#include <stdio.h>

/* Mostra n-ésimo número da sequencia de fibonnaci menor que 1000 */
int main() {
  unsigned long int sequencia_fib[1000];
  /* CALCULAR SEQUENCIA */
  sequencia_fib[0] = 1;
  sequencia_fib[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    sequencia_fib[i] = sequencia_fib[i - 1] + sequencia_fib[i - 2];
  }

  /* PROCESSAR ENTRADA DE USUÁRIOS */
  int n;
  while (n >= 0 && n <= 1000) {
    scanf("%d", &n);
    printf("fib[%d]=%lu\n", n, sequencia_fib[n]);
  }
  return 0;
}
