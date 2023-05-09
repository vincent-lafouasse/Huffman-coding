#include "huffman_queue.h"

#include <stdio.h>
#include <stdlib.h>

PriorityQueue* new_queue(void) {
  PriorityQueue* new = malloc(sizeof(PriorityQueue));
  for (int i = 0; i < N_MAX_SYMBOLS; i++) {
    new->elements[i] = NULL;
  }
  new->len = 0;
  return new;
}

void print_queue(PriorityQueue* queue) {
  for (int i = 0; i < queue->len; i++) {
    print_node(queue->elements[i]);
  }
}
