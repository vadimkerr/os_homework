#include <pthread.h>
#include <stdio.h>
#define THREAD_NUM 5

int counter = 0;
pthread_mutex_t mutex;

void *print_thread(void *arg) {
  pthread_mutex_lock(&mutex);
  printf("Thread #%d is created\n", counter);
  printf("Hello from thread #%d!\n", counter);
  printf("Thread #%d exited\n", counter);
  counter++;
  pthread_mutex_unlock(&mutex);
}

int main() {
  pthread_t threads[THREAD_NUM];

  for (int i = 0; i < THREAD_NUM; i++) {
    pthread_create(&threads[i], NULL, print_thread, NULL);
  }

  for (int i = 0; i < THREAD_NUM; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
