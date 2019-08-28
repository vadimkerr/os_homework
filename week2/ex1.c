#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
  int a;
  float b;
  double c;

  a = INT_MAX;
  b = FLT_MAX;
  c = DBL_MAX;

  printf("Value of a: %d, size of a: %zu\nValue of b: %f, size of b: %zu\nValue of c: %f, size of c: %zu\n", 
          a, sizeof(a), b, sizeof(b), c, sizeof(c));

  return 0;
}
