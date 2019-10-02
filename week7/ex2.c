#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int *array;

  printf("Please enter the number of elements: ");
  scanf("%d", &n);

  array = (int*) calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    array[i] = i;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);

  return 0;
}
