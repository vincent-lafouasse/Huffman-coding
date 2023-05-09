#pragma once

#include <stdbool.h>

#include "btree.h"
#include "symbol_counter.h"

#define N_MAX_SYMBOLS 128

typedef struct {
  Node* elements[N_MAX_SYMBOLS];
  int len;
} PriorityQueue;

PriorityQueue* new_queue(void);
PriorityQueue* new_queue_from_frequency_map(FrequencyMap* frequency_map);
void insert_into_queue(Node* node, PriorityQueue* queue);
void emplace_into_queue(char symbol, int count, PriorityQueue* queue);
Node* peek(PriorityQueue* queue);
Node* pop(PriorityQueue* queue);
bool queue_is_empty(PriorityQueue* queue);
void print_queue(PriorityQueue* queue);
