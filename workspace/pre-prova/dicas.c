/******************************************************************************

Em C, uma matriz e passada por referencia, o que significa que, quando voce
passa uma matriz como um argumento para uma funcao, na verdade esta passando um
ponteiro para o primeiro elemento da matriz. Se voce esta trabalhando com
endereco de memoria, quer dizer que ao alterar o valor dentro da funcao, voce
estara alterando o valor a estrutura original.

Isso tambem se aplica a vetores.

CURIOSIDADE: Ambos os recursos, vetor e matrizes, sao representados da mesma
maneira 7 pelo compilador. Veja o exemplo:

int vetor[5] = {1, 2, 3, 4, 5};
Memoria:
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 5 |
+---+---+---+---+---+

int matriz[2][2] = {
    {1, 2},
    {3, 4}
}

Memoria:
+---+---+---+---+---+
| 1 | 2 | 3 | 4 |
+---+---+---+---+---+

*******************************************************************************/

#include <math.h>
#include <stdio.h>

#define LINHAS 2
#define COLUNAS 2

/*
Uma das formas de passar uma matriz de parametro e como mostrado a seguir.
Neste caso, estaremos passado a matriz como um array de arrays (ou vetor de
vetores), onde cada elemento do array principal e um array representando uma
linha da matriz.

A sintaxe do C exige que seja passado o numero de colunas junto a matriz. O
numero de linhas o proprio compilador consegue induzir. Vale ressaltar que
o valor passado precisa ser uma constante, nao e permitido variaveis.
*/
void imprima_matriz(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

/*
CUIDADO: se voce inserir espaco apos a definicao do tipo de dados no scanf,
podeser que o resultado do seu programa nao seja o esperado. Entao fique
atento.

scanf("%d",&matriz[i][j]);

PODE NAO TER O MESMO RESULTADO QUE

scanf("%d ",&matriz[i][j]);
*/
void preencha_matriz(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("LENDO POSICAO [%d %d]", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void preencha_vetor(int vetor[], int tamanho) {
  for (int j = 0; j < tamanho; j++) {
    printf("LENDO POSICAO [%d]", j);
    scanf("%d", &vetor[j]);
  }
}

void altere_vetor(int vetor[], int tamanho) {
  for (int j = 0; j < tamanho; j++) {
    vetor[j] = vetor[j] * 2;
  }
}

void imprima_vetor(int vetor[], int tamanho) {
  for (int j = 0; j < tamanho; j++) {
    printf("%d ", vetor[j]);
  }
}

void passagem_por_valor(int x) { x = x + 10; }

/*
O operador de desreferenciamento * em C e usado para acessar o valor
que um ponteiro aponta.

Tambem pode ser usado para criar e modificar valores em locais de memoria
especificos, atraves de ponteiros. */
void pasasgem_por_referencia(int *x) { *x = *x + 10; }
int main() {
  // EXEMPLO DE MANIPULACAO DE VETOR UTILIZANDO VETOR
  int vetor[COLUNAS];
  preencha_vetor(vetor, COLUNAS);
  printf("\n");
  altere_vetor(vetor, COLUNAS);
  imprima_vetor(vetor, COLUNAS);
  printf("\n\n");

  // EXEMPLO DE MANIPULACAO DE MATRIZES UTILIZANDO FUNCAO
  int matriz[LINHAS][COLUNAS];
  preencha_matriz(matriz, LINHAS, COLUNAS);
  printf("\n");
  imprima_matriz(matriz, LINHAS, COLUNAS);

  // COMPLEMENTO: VARIAVEL PASSADA POR VALOR E REFERENCIA PARA UMA FUNCAO

  /*
     Quando uma variavel e passada por valor, quer dizer que foi criada
     uma copia do valor original e enviada para a funcao. Isso significa que
     se a variavel for alterada dentro da funcao, isso nao reflete no restante
     do programa.

     Se for passada por referencia, ou seja, utilizando ponteiros,
     a alteracao ira refletir em todo o programa. Isso acontece porque voce
     estara alterando a posicao da memoria original da variavel.
  */

  int x = 3;
  passagem_por_valor(x);
  printf(" \n %d \n", x);
  // O operador & e usado para passar o endereco de memoria da variavel x
  pasasgem_por_referencia(&x);
  printf("%d", x);
}
