Exercício
1) Em C, existem vários tipos de dados que podem ser usados para declarar variáveis e estruturar programas. Dado os tipos de dados em C abaixo, descreva o que é armazenado em cada tipo e quantos bytes são utilizados. 

a) char
b) short 
c) int
d) long
e) float
f) double
g) long double

2) A função scanf é utilizada para ler algum dado digitado pelo usuário. Ou seja, sempre que esse comando for usado, o programa irá pausar e esperar a entrada de um dado via teclado, que quando inserido será armazenado em uma variável.

Exemplos:

Espera que o usuário digite um inteiro. O valor digitado será o conteúdo da variável n.
      scanf("%d", &n);
      
Espera que o usuário digite dois inteiros. O primeiro valor digitado será o conteúdo da variável m e o segundo valor será o conteúdo da variável n.
      scanf("%d %d", &m, &n);
      
O usuário deve digitar n números. Note que o printf tem como finalidade somente orientar o usuário para a digitação dos números.
      for (i = 0; i < n; i++){
        printf("Digite mais um número: ");
        scanf("%d", &num);
      }
Faça um programa que leia 10 números do teclado e mostre o maior dentre eles. Para resolver esse exercício, importe a biblioteca <stdio.h>.

3) Escreva um programa que leia, do teclado, valores para dois vetores A e B de tamanho 3. Posteriormente, crie uma lógia capaz de criar um vetor C resultante da subtração de  A e B (A-B). 

4) Na programação de computadores, uma cadeia de caracteres é denominada string. Geralmente, é utilizada para representar palavras, frases ou textos de um programa. Em C, Strings são representados internamente como vetores de caracteres. 

Complete o programa abaixo para encontrar a quantidade de vezes que o caracter representado pela variável ch aparece na string str. 

#include <stdio.h>

void main()
{
    char ch = 'l';
    char str[40] = "qwertyuiopasdfghjklqwertyuiopasdfghjklç";
    int espaco = 0;
}

5) Faça um programa que leia 10 números inteiros, armazene-os em um vetor, solicite um valor de referência inteiro e:

a) imprima os números do vetor que são maiores que o valor referência
b) retorne quantos números armazenados no vetor são menores que o valor de referência
c) retorne quantas vezes o valor de referência aparece no vetor
