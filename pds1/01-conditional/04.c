#include <stdio.h>

#define IMC_SAUDAVEL_MIN 18.5
#define IMC_SAUDAVEL_MAX 25

/** Calcula o imc baseado no peso e altura */
float calculo_imc(float peso, float altura);

/** Calcula a diferença entre o peso real e o peso ideal (baseado no imc)
 *
 * Delta negativo significa que o peso real está abaixo do recomenado.
 * Delta positivo, significa que o peso real está acima do recomenado.
 */
float calculo_delta_peso_ideal(float peso, float altura);

/** IMC
 *
 * Exercício: Calcular IMC de Brutus e Olivia e o peso necessário para que
 * eles fiquem na faixa saudável.
 */
int main() {
  // dados iniciais
  float peso_brutus, peso_olivia, altura_brutus, altura_olivia;
  peso_brutus = 122;
  altura_brutus = 1.84;

  peso_olivia = 45;
  altura_olivia = 1.76;

  // calcular IMC de Brutos e Olivia
  float imc_brutus = calculo_imc(peso_brutus, altura_brutus);
  float imc_olivia = calculo_imc(peso_olivia, altura_olivia);

  printf("IMC de Brutus é %.2f.", imc_brutus);
  printf("\n");
  printf("IMC de Olivia é %.2f.", imc_olivia);

  // calcular diferenca do (peso-real) - (peso-ideal-imc)
  float delta_peso_ideal_brutus =
      calculo_delta_peso_ideal(peso_brutus, altura_brutus);
  float delta_peso_ideal_olivia =
      calculo_delta_peso_ideal(peso_olivia, altura_olivia);

  // imprimir resultados
  if (delta_peso_ideal_brutus < 0) {
    printf("\nBrutus precisa ganhar %.2fkg.", -delta_peso_ideal_brutus);
  } else {
    printf("\nBrutus precisa perder %.2fkg.", delta_peso_ideal_brutus);
  }

  if (delta_peso_ideal_olivia < 0) {
    printf("\nolivia precisa ganhar %.2fkg.", -delta_peso_ideal_olivia);
  } else {
    printf("\nolivia precisa perder %.2fkg.", delta_peso_ideal_olivia);
  }

  printf("\n");
  return 0;
}

float calculo_imc(float peso, float altura) { return peso / (altura * altura); }

float calculo_delta_peso_ideal(float peso, float altura) {
  float peso_ideal_min = IMC_SAUDAVEL_MIN * (altura * altura);
  float peso_ideal_max = IMC_SAUDAVEL_MAX* (altura * altura);

  if (peso < peso_ideal_min) {
    return peso - peso_ideal_min;
  } else if (peso > peso_ideal_max) {
    return peso - peso_ideal_max;
  } else {
    return 0;
  }
}
