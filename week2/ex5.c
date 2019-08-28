#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wrong_usage() {
  printf("Usage: ./ex5 n shape\nExample: ./ex5 10 rectangle\n");
  exit(1);
}

void print_rectangle(int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height; j++) {
      printf("*");
    }

    printf("\n");
  }
}

void print_triangle_up(int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= i; j++) {
      printf("*");
    }

    printf("\n");
  }
}

void print_triangle_right(int height) {
  for (int i = 0; i < height/2; i++) {
    for (int j = 0; j <= i; j++) {
      printf("*");
    }

    printf("\n");
  }
  
  for (int i = height/2+1; i <= height; i++) {
    for (int j = 0; j <= height-i; j++) {
      printf("*");
    }

    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int height;
  char *shape;

  if (argc != 3) {
    wrong_usage();
  }

  sscanf(argv[1], "%d", &height);
  sscanf(argv[2], "%s", shape);

  if (strcmp(shape, "rectangle") == 0) {
    print_rectangle(height);
  } else if (strcmp(shape, "triangle_up") == 0) {
    print_triangle_up(height);
  } else if (strcmp(shape, "triangle_right") == 0) {
    print_triangle_right(height);
  } else {
    printf("Shape '%s' is not supported!\nSupported shapes: rectangle/triangle_up/triangle_right\n", shape);
  }
}
