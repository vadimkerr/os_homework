#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define BIT_NUMBER 8

int get_min_index(int *array, int length) {
  int index = 0;
  for (int i = 0; i < length; i++) {
    if (array[i] < array[index]) {
      index = i;
    }
  }
  return index;
}

int get_index(int *array, int length, int value) {
  for (int i = 0; i < length; i++) {
    if (array[i] == value) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Please provide number of frame pages as an argument!\n");
    return 0;
  }

  int page_number = strtol(argv[1], NULL, 10);

  int *page_frames = calloc(page_number, sizeof(int));
  int *ratings = calloc(page_number, sizeof(int));

  memset(page_frames, 0, page_number);
  memset(ratings, 0, page_number);

  FILE *file;
  file = fopen("Lab 09 input.txt", "r");

  int hit_count = 0; 
  int miss_count = 0;
  
  int page_req = 0;
  fscanf(file, "%d", &page_req);
  while (!feof(file)) {
    int page_index = get_index(page_frames, page_number, page_req);
    if (page_index == -1) {
      int min_index = get_min_index(ratings, page_number);
      page_frames[min_index] = page_req;
      ratings[min_index] = (int) pow(2, BIT_NUMBER-1);
      miss_count++;
    } else {
      ratings[page_index] >>= 1;
      ratings[page_index] += (int) pow(2, BIT_NUMBER-1);
      hit_count++;
    }
    
    fscanf(file, "%d", &page_req);
  }
  
  printf("HIT=%d, MISS=%d, H/M=%f\n", hit_count, miss_count, (float) hit_count / miss_count);
}
