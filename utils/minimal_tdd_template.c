/** My Program
 *
 * This is my program
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// SETUP TEST
#define _assert(test)                                                          \
  do {                                                                         \
    printf("> Running '%s' (%d)\n", __func__, __LINE__);                       \
    assert(test);                                                              \
  } while (0)
#define TEST_ENVVAR "PRG_TEST"
int TEST = 0;
int run_tests();

// PROGRAM

/** My feature does that */
int feature();

int main() {
  // TEST
  char *envvar_pointer;
  if ((envvar_pointer = getenv(TEST_ENVVAR)) != NULL) {
    TEST = envvar_pointer[0] - '0';
  }

  if (TEST) {
    return run_tests();
  }

  // PROGRAM
  printf("Not implemented\n");
  return 1;

  return 0;
}

/** PROGRAM */

int feature() { return 0; }

/** TEST SUITE */

int test_trivial() {
  _assert(1 == 1);
  return 0;
}

/** Test runner */
int run_tests() {
  test_trivial();
  return 0;
}
