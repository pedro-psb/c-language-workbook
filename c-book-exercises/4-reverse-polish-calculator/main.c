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

int getop(char s[]) {
  //
  return 0;
}

// STACK

void push(double number){
    //
};

double pop(void) {
  double number = 0;
  return number;
}
