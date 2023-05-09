#include "huffman_queue.h"

#include <stdio.h>
#include <stdlib.h>

static void swap(Node** node1, Node** node2);
static void normalize_queue(PriorityQueue* queue);

PriorityQueue* new_queue_from_frequency_map(FrequencyMap* frequency_map) {
  PriorityQueue* queue = new_queue();
  for (int i = 0; i < frequency_map->len; i++) {
    SymbolCount current = frequency_map->map[i];
    emplace_into_queue(current.symbol, current.count, queue);
  }
  return queue;
}

void emplace_into_queue(char symbol, int count, PriorityQueue* queue) {
  Node* new = new_node(symbol, count);
  insert_into_queue(new, queue);
}

void insert_into_queue(Node* node, PriorityQueue* queue) {
  push(queue, node);
  normalize_queue(queue);
}

Node* pop(PriorityQueue* queue) {
  if (queue->len == 0) {
    printf("Queue is empty, cannot pop\n");
    exit(1);
  }
  (queue->len)--;
  return queue->elements[queue->len - 1];
}

static void normalize_queue(PriorityQueue* queue) {
  int min_count = -1;
  int min_arg;
  for (int i = 0; i < queue->len; i++) {
    int current_count = queue->elements[i]->count;
    if (current_count < min_count || min_count == -1) {
      min_count = current_count;
      min_arg = i;
    }
  }
  if (min_arg != queue->len - 1) {
    swap(&(queue->elements[queue->len - 1]), &(queue->elements[min_arg]));
  }
}

static void swap(Node** node1, Node** node2) {
  Node* temp = *node1;
  *node1 = *node2;
  *node2 = temp;
}

void push(PriorityQueue* queue, Node* node) {
  if (queue->len == N_MAX_SYMBOLS) {
    printf("Queue is full, cannot insert/push elements\n");
    exit(1);
  }
  queue->elements[queue->len] = node;
  (queue->len)++;
}

PriorityQueue* new_queue(void) {
  PriorityQueue* new = malloc(sizeof(PriorityQueue));
  for (int i = 0; i < N_MAX_SYMBOLS; i++) {
    new->elements[i] = NULL;
  }
  new->len = 0;
  return new;
}

bool queue_is_empty(PriorityQueue* queue) {
  return queue->len == 0;
}

void print_queue(PriorityQueue* queue) {
  printf("Priority queue:\n");
  for (int i = 0; i < queue->len; i++) {
    print_node(queue->elements[i]);
  }
  printf("\n");
}
