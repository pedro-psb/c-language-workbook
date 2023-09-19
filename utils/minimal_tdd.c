/** Minimal TDD sample in C
 *
 * TEST_ENVVAR=1 ./binary                RUN TEST SUITE
 * TEST_ENVVAR=0 ./binary or ./binary    RUN PROGRAM
 */

#include <assert.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

// SETUP TESTS

#define TEST_ENVVAR "PRG_TEST"
#define _assert(test)                                                          \
  do {                                                                         \
    printf("> Running '%s' (%d)\n", __func__, __LINE__);                       \
    assert(test);                                                              \
  } while (0)

int TEST = 0;
int test_suite();

// PROGRAM

/** Divide floats @a and @b
 *
 * Returns FLT_MAX if b is zero;
 */
float divide(int a, int b);

/** Reads a float from stdin */
float input_float(char *input_msg);

int main() {
  // Integrated Test
  char *envvar_pointer;
  if ((envvar_pointer = getenv(TEST_ENVVAR)) != NULL) {
    int test_flag = envvar_pointer[0] - '0';
    printf("Setting TEST=%d\n", test_flag);
    TEST = test_flag;
  }

  if (TEST) {
    test_suite();
    return 0;
  }

  // Program
  float a, b, result;
  a = input_float("> Please, enter the first number: ");
  b = input_float("> Please, enter the second number: ");

  if ((result = divide(a, b)) == FLT_MAX) {
    fprintf(stderr, "Can't divide by zero.\n");
    return 1;
  }

  printf("> %f / %f = %f\n", a, b, result);
  return 0;
}

float divide(int a, int b) {
  if (b == 0) {
    return FLT_MAX;
  }
  float result = (float)a / b;
  return result;
}

float input_float(char *input_msg) {
  float value;
  printf("%s\n", input_msg);
  scanf("%f", &value);
  return value;
}

/* TEST-SUITE*/
int test_valid_division() {
  _assert(divide(12, 6) == 2);
  _assert(divide(12, 6) == 2.0);
  _assert(divide(-12, 6) == -2.0);
  _assert(divide(12, -6) == -2.0);
  _assert(divide(-12, -6) == 2.0);
  return 0;
}

int test_division_by_zero() {
  _assert(divide(12, 0) == FLT_MAX);
  return 0;
}

int test_float_result() {
  _assert(divide(5, 2) == 2.5);
  return 0;
}

/* test runner */
int test_suite() {
  test_valid_division();
  test_division_by_zero();
  test_float_result();
  return 0;
};
