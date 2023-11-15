# Exercicio PDS 1 - Arrays e Sizeof



    1) Explique em detalhes como o operador sizeof é utilizado na linguagem de
    programação C e descreva seu funcionamento. Por que a informação obtida com
    esse comando pode ser valiosa no contexto da programação em C.

O operador `sizeof` é utilizado na linguagem C para retorna o tamanho que uma
estrutura ocupa em memória, que é dado em número de bytes. Um `int`, por exemplo,
tem tamanho 4 na maioria dos sistemas.

No caso de arrays, ele retornará o tamanho em bytes do array, que é o produto do
tamanho de cada elemento (definido pelo tipo do array) por seu número de elementos.

De forma inversa, podemos obter o número de elementos se soubermos o tamanho do
tipo do array e seu tamanho total, informações que podem ser obtidas pelo usuario
com o `sizeof`.

O número de elementos de um array é um dado muito importante em programas C, porque
permite iterar sobre um array de forma segura, isto é, acessando apenas espaços de
memória que foram alocados para ele. Com a informação de onde na memória e quantos
elementos ele tem, podemos facilmente calcular seu fim e parar uma iteração incremental
exatamente no ultimo espaço de memoria disponível.

É preciso estar atento porque os arrays tem um relação estreita com ponteiros,
mas eles nao são a mesma coisa. Sizeof não computa o tamanho se receber um ponteiro explícito.



    2) Complete o código abaixo, substituindo a interrogação pelo comando
    correspondente para obter a quantidade de posições do vetor.

```c
#include <stdio.h>

#define LIMITE 3

float media(int vetor[]){
  // int quantidade = sizeof(vetor) / sizeof(int);
  // Nao funciona porque 'vetor' aqui é efetivamente um ponteiro, por ter sido
  // passado como parametro de função. Nesse caso, sizeof vai retornar o tamanho
  // de um ponteiro para um inteiro, que pode ser 4 ou 8.

  int quantidade = LIMITE;
  float soma = 0;
  for (int i = 0; i < quantidade; i++) {
    soma = soma + vetor[i];
  }
  float media = soma / quantidade;
  return media;
}

int main() {
  int x[LIMITE];
  for (int i = 0; i < LIMITE; i++) {
    x[i] = i * 5;
  }
  printf("A MEDIA É IGUAL A %f\n", media(x));
  return 0;
}
```



    3) Complete o código abaixo para calcular a distancia euclidiana entre
    os pontos A e B.

```c
#include <math.h>
#include <stdio.h>

#define LIMITE 2

/* calcula distancia entre pontos num plano */
float distancia_euclidiana(float pontoA[], float pontoB[]) {
  float delta_x = pontoB[0] - pontoA[0];
  float delta_y = pontoB[1] - pontoA[1];
  return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int main() {
  float pontoA[LIMITE];
  float pontoB[LIMITE];

  for (int i = 0; i < LIMITE; i++) {
    pontoA[i] = i + 2 * 3;
    pontoB[i] = i - 2 * 1.5;
  }
  printf("A distancia entre os pontos é %f\n",
         distancia_euclidiana(pontoA, pontoB));
  return 0;
}
```
