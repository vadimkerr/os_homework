#include <stdio.h>

int main(int argc, char *argv[]) {
  int height;
  sscanf(argv[1], "%d", &height);

  for (int i = 0; i < height; i++) {
    for (int j = 1; j < height * 2; j++) {
      if (j >= height-i && j <= height+i) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
