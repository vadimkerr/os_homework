// Child process is assigned with PID equal to PARENT_PID + 1

#include <stdio.h>
#include <unistd.h>

int main() {
  int n = 42;
  
  if (fork() == 0) {
    printf("Hello from child [%d]\n", getpid()-n);
  } else {
    printf("Hello from parent [%d]\n", getpid()-n);
  }

  return 0;
}
