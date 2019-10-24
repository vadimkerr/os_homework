#include <stdio.h>
#include <dirent.h>

#define CAPACITY 256

int get_index(long int *array, int length, long int item) {
  for (int i = 0; i < length; i++) {
    if (array[i] == item) {
      return i;
    }
  }
  return -1;
}

int main() {
  DIR *directory = opendir("./tmp");
  if (directory == NULL) return 1;

  long int inodes[CAPACITY];
  int inodes_length = 0;

  int counts[CAPACITY];
  int index;

  struct dirent *files[CAPACITY];
  int files_length = 0;
  struct dirent *file;

  file = readdir(directory);  
  while (file != NULL) {
    files[files_length] = file;
    files_length++;

    index = get_index(inodes, inodes_length, file->d_ino);
    if (index == -1) {
      inodes[inodes_length] = file->d_ino;
      counts[inodes_length] = 1;
      inodes_length++;
    } else {
      counts[index]++;
    }
    file = readdir(directory);
  }

  for (int i = 0; i < inodes_length; i++) {
    if (counts[i] > 1) {
      printf("%li: ", inodes[i]);
      for (int j = 0; j < files_length; j++) {
        if (files[j]->d_ino == inodes[i]) {
          printf("%s ", files[j]->d_name);
        }
      }
      printf("\n");
    }
  }

  return 0;
}
