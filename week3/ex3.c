#include <stdio.h>
#include <stdlib.h>

struct Node {
  int content;
  struct Node *next;
};

struct List {
  struct Node *head;
  int length; 
};

struct Node* new_node(int content, struct Node *next) {
  struct Node* node = malloc(sizeof(struct Node));
  node->content = content;
  node->next = next;

  return node;
}

struct List* new_list(struct Node *head, int length) {
  struct List* list = malloc(sizeof(struct List));
  list->head = head;
  list->length = length;

  return list;
}

void insert_node(struct List *list, int content, int index) {
  struct Node* prev_node = NULL;
  struct Node* current_node = list->head;

  for (int i = 0; i < index; i++) {
    prev_node = current_node;
    current_node = current_node->next;
  }

  if (prev_node == NULL) {
    list->head = new_node(content, current_node);
  } else {
    prev_node->next = new_node(content, current_node);
  }

  list->length += 1;
}

void delete_node(struct List *list, int index) {
  struct Node* prev_node = NULL;
  struct Node* current_node = list->head;

  for (int i = 0; i < index; i++) {
    prev_node = current_node;
    current_node = current_node->next;
  }

  if (prev_node == NULL) {
    list->head = current_node->next;
  } else {
    prev_node->next = current_node->next;
  }
  free(current_node);

  list->length -= 1;
}

void print_list(struct List *list) {
  struct Node* current_node = list->head;

  while (current_node != NULL) {
    printf("%d ", current_node->content);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  struct List* list = new_list(NULL, 0);

  insert_node(list, 10, 0);
  insert_node(list, 156, 1);
  insert_node(list, -19, 2);
  insert_node(list, 28, 3);
  insert_node(list, -1, 0);
  insert_node(list, 0, 0);
  insert_node(list, 100, 6);

  delete_node(list, 0);
  delete_node(list, 0);
  delete_node(list, 2);
  delete_node(list, 3);

  // list should be [10 156 28] at this point
  print_list(list);

  return 0;
}
