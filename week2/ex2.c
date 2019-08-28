#include <stdio.h>
#include <string.h>

int main() {
  char user_input[50];

  fgets(user_input, 50, stdin);
  int input_length = strlen(user_input) - 1;

  for (int i = input_length - 1; i >= 0; i--) {
    printf("%c", user_input[i]);
  }
  printf("\n");

  return 0;
}
