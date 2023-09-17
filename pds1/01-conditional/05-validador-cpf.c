#include <stdio.h>

int assert_equal(char *nome, int a, int b);

/** Validador de CPF */
int main() {
  /* 0. entrada de dados
   */

  char char_digitos[12];
  printf("Por favor, entre o cpf desejado:\n");
  scanf("%s", char_digitos);

  // char *char_digitos = "12345678918";

  // converter para int
  int digitos[12];
  int i = 0;
  while (char_digitos[i] != '\0') {
    digitos[i] = char_digitos[i] - '0';
    i++;
  }

  // valida tamanho de 11 digitos
  // (i incrementa uma vez a mais para testar o \o)
  if (i != 11) {
    printf("Você entrou %d digitos. ", i);
    printf("Por favor, coloque um número com 11 dígitos.\n");
    return 1;
  }

  /* 1. soma dos 9 digitos com peso igual a posição do dígito + 1 */

  int soma_produtos = 0;
  for (i = 8; i >= 0; i--) {
    // indice 8 (unidade) = (9 - 8) + 1 = peso 2
    // indice 0 (centena de milhar) = (9 - 0) + 1 = peso 10
    int peso = (9 - i) + 1;
    // printf("calculando (peso * digito) %d * %d\n", peso, digitos[i]);
    soma_produtos = soma_produtos + digitos[i] * peso;
  }
  // printf("soma_produtos=%d\n", soma_produtos);

  // printf("%d", soma_produtos); // para 123456789xx = 210

  /* 2. digito_dezena (dezena do digito verificador):
   * - digito_dezena = 0 se (soma_produtos // 11 == 0 ou 1
   * - digito_dezena = 11 - ( soma_produtos // 11)
   */

  int digito_dezena;
  if (soma_produtos % 11 == 1 || soma_produtos % 11 == 0) {
    digito_dezena = 0;
  } else {
    digito_dezena = 11 - (soma_produtos % 11);
  }

  // printf("digito_dezena=%d\n", digito_dezena); // para soma_produto = 210,

  if (digito_dezena != digitos[9]) {
    printf("O cpf é inválido. ");
    printf("O dígito verificador das dezenas deveria ser %d, não %d.\n",
           digito_dezena, digitos[9]);
    return 1;
  }

  /* 3. soma dos 10 digitos (com digito_dezena acrescido) com pesos:
   * - digito-dezena = 2
   * - unidade (número de 9 digitos) = 3
   * - dezena (número de 9 digitos) = 4
   * - ...
   */

  // recalcula soma_produtos
  soma_produtos = 0;
  for (i = 9; i >= 0; i--) {
    int peso = (10 - i) + 1;
    // printf("calculando (peso * digito) %d * %d\n", peso, digitos[i]);
    soma_produtos = soma_produtos + digitos[i] * peso;
  }
  // printf("soma_produtos=%d\n", soma_produtos);

  /* 4. digito_uniade (unidade do dígito verificador)
   * digito_dezena = 0 se (soma_produtos // 11 == 0 ou 1
   * digito_dezena = 11 - ( soma_produtos // 11)
   */

  // calcula digito verificador das unidades
  int digito_unidade;
  if (soma_produtos % 11 == 1 || soma_produtos % 11 == 0) {
    digito_unidade = 0;
  } else {
    digito_unidade = 11 - (soma_produtos % 11);
  }

  // printf("digito_unidade=%d\n", digito_unidade); // para soma_produto = 210,

  if (digito_unidade != digitos[10]) {
    printf("O cpf é inválido. ");
    printf("O dígito verificador das unidades deveria ser %d, não %d.\n",
           digito_unidade, digitos[10]);
    return 1;
  }

  printf("O cpf %s é válido!\n", char_digitos);
  return 0;
}

int assert_equal(char *nome, int a, int b) {
  if (a != b) {
    printf("%s=%d, esperado=%d\n", nome, a, b);
    return 1;
  }
  return 0;
}
