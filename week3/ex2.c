#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble_sort(int array[], int size) {
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (array[j] > array[j+1]) {
        swap(&array[j], &array[j+1]);
      }
    }
  }
}

int main() {
  int array[10] = {201, 12, 1, 0, -12, -2, 0, 56, 29, -245};
  bubble_sort(array, 10);

  return 0;
}
