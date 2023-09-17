#include <stdio.h>

float calculo_imc(float peso, float altura);
float diferenca_para_imc_recomendado(float imc_atual);
float imc_para_peso(float altura, float imc);

// cálculo do IMC
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

  // calcular diferenca do (imc-ideal) - (imc-recomendado)
  float delta_imc_brutus = diferenca_para_imc_recomendado(imc_brutus);
  float delta_imc_olivia = diferenca_para_imc_recomendado(peso_olivia);

  printf("delta-imc-olivia %.2f", delta_imc_olivia);
  printf("delta-imc-brutus %.2f", delta_imc_brutus);

  // peso restante para imc
  float peso_restante_brutus = imc_para_peso(altura_brutus, delta_imc_brutus);
  float peso_restante_olivia = imc_para_peso(altura_olivia, delta_imc_olivia);

  // imprimir resultados
  if (peso_restante_brutus < 0) {
    printf("\nBrutus precisa ganhar %.2fkg.", peso_restante_brutus);
  } else {
    printf("\nBrutus precisa perder %.2fkg.", peso_restante_brutus);
  }

  if (peso_restante_olivia < 0) {
    printf("\nOlivia precisa ganhar %.2fkg.", peso_restante_olivia);
  } else {
    printf("\nOlivia precisa perder %.2fkg.", peso_restante_olivia);
  }
  printf("\n");

  return 0;
}

float calculo_imc(float peso, float altura) {
  return peso / (altura * altura);
}

float diferenca_para_imc_recomendado(float imc_atual) {
  float delta = 0;
  float imc_saudavel_min = 18.5;
  float imc_saudavel_max = 25;

  if (imc_atual < imc_saudavel_min) {
    delta = imc_saudavel_min - imc_atual;
  } else if (imc_atual > imc_saudavel_max) {
    delta = imc_atual - imc_saudavel_max;
  }

  // debug
  // printf("atual: %.2f, delta: %.2f", imc_atual, delta);

  return delta;
}

float imc_para_peso(float altura, float imc) {
  // printf("\n");
  // printf("i");
  return (imc * (altura * altura));
}
