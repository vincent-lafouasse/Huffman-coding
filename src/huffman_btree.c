#include "huffman_btree.h"

#include <stdio.h>
#include <stdlib.h>

Node* new_node(char symbol, double weight) {
  Node* new = malloc(sizeof(Node));
  new->symbol = symbol;
  new->weight = weight;
  new->parent = NULL;
  new->right = NULL;
  new->left = NULL;
  return new;
}

void print_node(Node* node) {
  printf("Node %c\t", node->symbol);
  printf("\tWeight %f", node->weight);
  printf("\tAdress %p\n", (void*)node);
  printf("\tLeft %p", (void*)node->left);
  printf("\tRight %p", (void*)node->right);
  printf("\tParent %p", (void*)node->parent);
}
