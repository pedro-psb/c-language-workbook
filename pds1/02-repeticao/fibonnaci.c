#include <stdio.h>
#include <limits.h>

/* calcula os n primeiros digitos da sequencia de fibonacci */
int main(){
  int atual = 1;
  int anterior = 1;
  int proximo;
  printf("1");
  for (int i=0; i < 100; i++) {
    proximo = atual + anterior;
    anterior = atual;
    atual = proximo;
    if (proximo < 0) {
      printf("\nExceeded int storage limit.\n");
      return 1;
    }
    printf(" %d", proximo);
  }
  printf("\n");
  return 0;
}