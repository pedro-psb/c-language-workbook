#include <stdio.h>
#include <stdlib.h>

enum bool { False, True };

enum bool DEBUG = False;
enum bool TEST = False;

/** Main function */
int divide_numbers(int a, int b, int *result);

/** Read, parse and apply envvar options to the program */
int test_exact_division();
int test_division_by_zero_error();

/** Read, parse and apply envvar options to the program */
void apply_envvar_options();

/** Utility function to assert if a == b
 * varname is the name that will be printed as '@varname=a'
 */
int assert_equal(char *varname, int a, int b);

/** My program
 */
int main() {
  /* TESTS */
  apply_envvar_options();
  if (TEST == True) {
    enum bool passed = True;
    // TEST HERE
    passed += test_exact_division();
    passed += test_division_by_zero_error();

    // REPORT
    if (passed == True) {
      printf("\nAll tests have passed.\n");
    } else {
      printf("\nSome tests have failed.\n");
    }
    return passed;
  }

  /* PROGRAM */
  // input
  int number_a, number_b;
  int *result;
  enum bool numbers_assigned = False;

  // input handling

  // run program
  if (numbers_assigned == False) {
    fprintf(stderr, "The input values were not correctly assigned.\n");
    return 1;
  }
  return divide_numbers(number_a, number_b, result);
}

/* PROGRAM */

int divide_numbers(int a, int b, int *result) {
  if (b == 0) {
    *result = 0;
    fprintf(stderr, "Can't didive by zero.\n");
    return 1;
  }

  *result = a / b;
  return 0;
}

/* TESTS */

int test_exact_division() {
  int exit_code;
  int *result;
  exit_code = divide_numbers(12, 6, result);

  int passed = 0;
  passed += assert_equal("divide_number(exit_code)", exit_code, 0);
  passed += assert_equal("divide_numbers(12, 6)", *result, 2);
  return passed;
}

int test_division_by_zero_error() {
  int exit_code;
  int *result;
  exit_code = divide_numbers(12, 0, result);

  int passed = 0;
  passed += assert_equal("divide_number(12, 0):exit_code", exit_code, 1);
  passed += assert_equal("divide_numbers(12, 0)", *result, 0);
  return passed;
}

/* UTILITIES */

int assert_equal(char *varname, int a, int b) {
  if (a == b) {
    return 0;
  }
  fprintf(stderr, "[Assertion Error]\ngot: %s = %d\n", varname, a);
  fprintf(stderr, "expected: %s = %d\n", varname, b);
  return 1;
}
void apply_envvar_options() {
  char ENV_DEBUG[2] = "";
  char ENV_TEST[2] = "";
  char *envvar_pointer;

  if ((envvar_pointer = getenv("MYPRG_DEBUG")) != NULL &&
      envvar_pointer[0] == '1') {
    DEBUG = True;
  }

  if ((envvar_pointer = getenv("MYPRG_TEST")) != NULL &&
      envvar_pointer[0] == '1') {
    TEST = True;
  }
}