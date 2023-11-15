#include <math.h>
#include <stdio.h>

// tamanho do vetor de binários
// 2^10=1024, então 10 posições são suficientes para representar 'n'
#define len_vetor 10

/* recursivamente preenche o vetor binário com o número certo*/
void converter_binario(int vetor[], int n, int valor) {
  // caso base
  if (valor == 0) {
    return;
  }

  // caso base
  if (valor == 1) {
    vetor[n] = 1;
    return;
  }

  // caso recursivo (valor > 1)

  // arredonda expoente para baixo por ser int
  // usa expoente de base 2 atravez de conversao de base
  int expoente = log(valor) / log(2);

  // sendo expoente=i, coloca valor 1 na i-esimo posição da direita para
  // esquerda
  vetor[n - expoente] = 1;

  // recursa no resto, se houver
  float exponencial_mais_proximo = pow(2, expoente);
  if (exponencial_mais_proximo < valor) {
    int novo_valor = valor - exponencial_mais_proximo;
    converter_binario(vetor, n, novo_valor);
  }
}

/* imprime vetor de tamanho n */
void imprime_vetor(int vetor[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

/* representar um número inteiro entre 0 e 1024 como
 * um array com elementos binários.
 */
int main() {
  // ler e validar número
  int n;
  printf("Entre um número natural menor que 1024.\n");
  scanf("%d", &n);
  printf("n=%d\n", n);
  if (n < 0 || n >= 1024) {
    printf("Você deve entrar um número entre 0 e 1024.\n");
    return 1;
  }

  // inicia vetor com zeros
  int vetor[len_vetor] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  converter_binario(vetor, len_vetor - 1, n);
  imprime_vetor(vetor, len_vetor);
  return 0;
}
