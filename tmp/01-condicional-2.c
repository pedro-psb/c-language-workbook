#include <stdio.h>


int main(){
  // não mudar
  float a = 3.14159, b = 2.71828;

  // trocar variaveis aqui
  float tmp = a;
  a = b;
  b = tmp;

  // não mudar
  printf("\nPI = %f", b);
  printf("\nEULER = %f", a);

  printf("\n");
  return 0;
}