/* Exercicios

1. Calcular a soma dos N primeiros nº naturais.
2. Imprimir os múltiplos de 7 menores que N.
3. Calcular e imprimir os números divisíveis por 4 menores que N.
4. Calcular os divisores de N.
5. Calcular o fatorial de N.
6. Retornar o menor inteiro positivo cujo quadrado é superior ao valor de N.
7. Imprimir a tabuada de N.
8. Retornar a média aritmética dos números pares#include <stdio.h>
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* marcro para facilitar teste manual dos valores */
#define test(fn, esperado)                                                     \
  printf("> %s == %s\noutput: ", #fn, esperado);                               \
  printf("return: %d\n", fn);

/* Calcular a soma dos N primeiros nº naturais. */
int somatorio_naturais(int n) {
  int soma = 0;
  for (int i = 1; i <= n; i++) {
    soma += i;
  }
  return soma;
}

/* Imprimir os múltiplos de 7 menores que N. */
int multiplos_sete(int n) {
  for (int i = 7; i < n; i += 7) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}

/* Calcular e imprimir os números divisíveis por 4 menores que N. */
int divisiveis_por_quatro(int n) {
  for (int i = 4; i < n; i += 4) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}

/* Calcular os divisores de N. */
int divisores_de_numero(int n) {
  for (int i = n; i > 0; i--) {
    if (n % i == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}

/* Calcular o fatorial de N. */
int fatorial_de_numero(int n) {
  if (n == 0) {
    return 1;
  }
  int fatorial = 1;
  for (int i = n; i > 0; i--) {
    fatorial *= i;
  }
  return fatorial;
}

/* Retornar o menor inteiro positivo cujo quadrado é superior ao valor de N. */
int menor_inteiro_com_quadrado_maior_que_numero(int n) {
  int n_sqrt = (int)sqrt(n);
  return n_sqrt + 1;
}

/* Imprimir a tabuada de N. */
int tabuada_de_numero(int n) {
  for (int i = 1; i <= 12; i++) {
    printf("%d ", n * i);
  }
  printf("\n");
  return 0;
}

/* Retornar a média aritmética dos números pares ate n*/
int media_aritmetica_de_pares(int n) {
  int soma = 0;
  int n_pares = 0;
  for (int i = 2; i < n; i += 2) {
    soma += i;
    n_pares++;
  }
  return n_pares != 0 ? soma / n_pares : 0;
}

int main() {
  // somatorio de naturais
  printf("Exercicio 1\n");
  test(somatorio_naturais(0), "0");
  test(somatorio_naturais(1), "1");
  test(somatorio_naturais(2), "3");
  test(somatorio_naturais(3), "6");

  // multiplos de 7 menores que n
  printf("\nExercicio 2\n");
  test(multiplos_sete(8), "[7]");
  test(multiplos_sete(14), "[7]");
  test(multiplos_sete(15), "[7 14]");
  test(multiplos_sete(22), "[7 14 21]");

  // divisiveis por 4 menores que n
  printf("\nExercicio 3\n");
  test(divisiveis_por_quatro(1), "[]");
  test(divisiveis_por_quatro(4), "[]");
  test(divisiveis_por_quatro(5), "[4]");
  test(divisiveis_por_quatro(9), "[4 8]");
  test(divisiveis_por_quatro(13), "[4 8 12]");

  // divisiveis por 4 menores que n
  printf("\nExercicio 4\n");
  test(divisores_de_numero(1), "[1]");
  test(divisores_de_numero(2), "[2 1]");
  test(divisores_de_numero(3), "[3 1]");
  test(divisores_de_numero(6), "[6 3 2 1]");
  test(divisores_de_numero(15), "[15 5 3 1]");

  // fatorial de n
  printf("\nExercicio 5\n");
  test(fatorial_de_numero(0), "1");
  test(fatorial_de_numero(1), "1");
  test(fatorial_de_numero(2), "2");
  test(fatorial_de_numero(3), "6");
  test(fatorial_de_numero(4), "24");
  test(fatorial_de_numero(5), "120");

  // menor inteiro com quadrado maior que numero
  printf("\nExercicio 6\n");
  test(menor_inteiro_com_quadrado_maior_que_numero(1), "2");  // 1 <= 1 < 4
  test(menor_inteiro_com_quadrado_maior_que_numero(4), "3");  // 4 <= 4 < 9
  test(menor_inteiro_com_quadrado_maior_que_numero(5), "3");  // 4 <= 5 < 9
  test(menor_inteiro_com_quadrado_maior_que_numero(8), "3");  // 4 <= 8 < 9
  test(menor_inteiro_com_quadrado_maior_que_numero(9), "4");  // 9 <= 9 < 16
  test(menor_inteiro_com_quadrado_maior_que_numero(17), "5"); // 16 <= 17 < 25

  // tabuada de numero
  printf("\nExercicio 7\n");
  test(tabuada_de_numero(1), "[1 2 3 4 5 6 7 8 9 10 11 12]");
  test(tabuada_de_numero(2), "[2 4 6 8 10 12 14 16 18 20 22 24]");
  test(tabuada_de_numero(3), "[3 6 9 12 15 18 21 24 27 30 33 36]");
  test(tabuada_de_numero(5), "[5 10 15 20 25 30 35 40 45 50 55 60]");

  // media aritmetica de pares até numero
  printf("\nExercicio 8\n");
  test(media_aritmetica_de_pares(1), "0"); // pares: []
  test(media_aritmetica_de_pares(2), "0"); // pares: []
  test(media_aritmetica_de_pares(3), "2"); // pares: [2]
  test(media_aritmetica_de_pares(5), "3"); // pares: [2 4]
  test(media_aritmetica_de_pares(7), "4"); // pares: [2 4 6]
  test(media_aritmetica_de_pares(9), "5"); // pares: [2 4 6 8]
  return 0;
}
