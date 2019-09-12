// Total number of processes will be equal to 2^n,
// where n is number of fork() calls.
// It happens because each process will create new child process,
// so every fork() doubles the number of process.

#include <stdio.h>
#include <unistd.h>

int main() {
  int n = 5;

  for (int i = 0; i < n; i++) {
    fork();
  }
  sleep(5);

  return 0;
}
