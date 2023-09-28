/*
This is a starter point for the exercise.
Do not modify directly: make a copy to work on.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 1000 /* max size of operand or operator */
#define NUMBER '0' /* signal that number was found */

/* getop: get next operator or numeric operand */
int getop(char[]);
/* push: push from stack */
void push(double);
/* pop: pop from stack */
double pop(void);

/* reverse polish calculator */
int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      push(pop() / op2);
      break;
    case '\n':
      printf("\t%.8f\n", pop());
      break;
    default:
      printf("error: unknown command");
      return 1;
    }
  }
  return 0;
}

// READ STRING GROUPS

#define BUFFSIZE 100

int buff_position;   /* next free position on the buffer */
char buff[BUFFSIZE]; /* buffer for ungetch */

/* get a possibly pushed back character */
int getch(void) {
  //
  return 0;
}

/* push character back to input */
void ungetch(int c) {
  //
}

int getop(char s[]) {
  //
  return 0;
}

// STACK

#define MAXVAL 100 /* maximum depth of values in the stack */

int stack_position = 0; /* next free position on the stack */
double stack[MAXVAL];   /* value stack */

void push(double number){
    //
};

double pop(void) {
  double number = 0;
  return number;
}
