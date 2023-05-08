#pragma once

typedef struct Node {
  char symbol;
  double weight;
  struct Node* left;
  struct Node* right;
  struct Node* parent;

} Node;

Node* new_node(char symbol, double weight);
void print_node(Node* node);
