#include <assert.h>
#include <math.h>
#include <stdio.h>

#define _assert(test)                                                          \
  do {                                                                         \
    printf("/nRunning '%s' (%d)", __func__, __LINE__);                         \
    assert(test);                                                              \
  } while (0)

float cauchy(float x);
float gumbel(float x, float u, float b);
float laplace(float x, float u, float b);

/* exercicio 1 */
int main() {
  _assert(cauchy(123) == 0);
  _assert(gumbel(1, 2, 3) == 0);
  _assert(laplace(1, 2, 3) == 0);
  return 0;
}

float cauchy(float x) {
  float expression = (1 / (M_PI * (1 + x * x)));
  return expression;
}

float gumbel(float x, float u, float b) {
  float z = (x - u) / b;
  float e_exp = -1 * (z + exp(-z));
  float result = (1 / b) * exp(e_exp);
  return result;
}

float laplace(float x, float u, float b) {
  float e_exp = -(fabs(x - u) / b);
  float result = (1 / (2 * b)) * exp(e_exp);
  return result;
}
