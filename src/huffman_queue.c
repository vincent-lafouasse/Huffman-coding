#include "huffman_queue.h"

#include <stdio.h>
#include <stdlib.h>

static void push(PriorityQueue* queue, Node* node);

PriorityQueue* new_queue(void) {
  PriorityQueue* new = malloc(sizeof(PriorityQueue));
  for (int i = 0; i < N_MAX_SYMBOLS; i++) {
    new->elements[i] = NULL;
  }
  new->len = 0;
  return new;
}

static void push(PriorityQueue* queue, Node* node) {
  if (queue->len == N_MAX_SYMBOLS) {
    printf("Queue is full, cannot insert/push elements\n");
    exit(1);
  }
}

bool queue_is_empty(PriorityQueue* queue) {
  return queue->len == 0;
}

void print_queue(PriorityQueue* queue) {
  for (int i = 0; i < queue->len; i++) {
    print_node(queue->elements[i]);
  }
}
