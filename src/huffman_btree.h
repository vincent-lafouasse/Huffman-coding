#pragma once

typedef struct Node {
  char symbol;
  int count;
  struct Node* left;
  struct Node* right;
  struct Node* parent;

} Node;

Node* new_node(char symbol, int count);
void print_node(Node* node);
