#include <stdio.h>


int main(){
  // mes 1 (inicio da conta)
  float saldo = 789.54;
  float rendimento_mensal = 0.56 / 100;

  // mes 2
  saldo = saldo * (1.0 + rendimento_mensal);
  saldo = saldo + 303.2;

  // mes 3
  saldo = saldo * (1.0 + rendimento_mensal);
  saldo = saldo - 58.25;

  // mes 4
  saldo = saldo * (1.0 + rendimento_mensal);
  printf("A conta terá R$%.2f no quarto mês.\n", saldo);
  
  return 0;
}