#include <stdio.h>

/* imprime matriz 3x3 */
void imprime_matriz(int matriz[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

/* calcula quantas linhas e colunas com soma par na matriz 3x3 */
int main() {
  // entrada de dados (linha por linha)
  printf("Entre uma matriz 3x3 (linha por linha)\n");
  int matriz[3][3];
  for (int i = 0; i < 3; i++) {
    scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
  }
  printf("Entrou:\n");
  imprime_matriz(matriz);

  // verificar linhas e colunas com soma par
  int n_linha_col_par = 0; /* numero de linhas ou colunas com soma par */
  int soma_linha;
  int soma_coluna;
  for (int i = 0; i < 3; i++) {
    soma_linha = 0;
    soma_coluna = 0;
    for (int j = 0; j < 3; j++) {
      soma_linha += matriz[i][j];
      soma_coluna += matriz[j][i];
    }
    if (soma_linha % 2 == 0) {
      n_linha_col_par++;
    }
    if (soma_coluna % 2 == 0) {
      n_linha_col_par++;
    }
  }
  printf("Resultado: %d\n", n_linha_col_par);
  return 0;
}
