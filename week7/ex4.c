#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, int old_size, int new_size) {
  if (ptr == NULL) {
    return malloc(new_size);
  }

  if (new_size == 0) {
    free(ptr);
    return NULL;
  }


  if (new_size < old_size) {
    return ptr;
  }

  void *new_ptr = malloc(new_size);
  memcpy(new_ptr, ptr, old_size);
  
  return new_ptr;
}

int main() {
  return 0;
}
