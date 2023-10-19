/*
 * Complete o programa abaixo para encontrar a quantidade de vezes que o
 * caracter representado pela variável ch aparece na string str.
 */
#include <stdio.h>

int main() {
  char ch = 'l';
  char str[40] = "qwertyuiopasdfghjklqwertyuiopasdfghjklç";
  int espaco = 0;
  for (int i=0; i<40; i++) {
    if (str[i] == ch) {
      espaco++;
    }
  }
  printf("%d\n", espaco);
  return 0;
}
