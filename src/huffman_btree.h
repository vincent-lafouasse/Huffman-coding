#pragma once

#include "frequency_map.h"

typedef struct Node {
  char symbol;
  int count;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
} Node;

Node* construct_huffman_tree_from_map(FrequencyMap* map);

Node* new_node(char symbol, int count);
void print_node(Node* node);
