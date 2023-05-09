#include "huffman_btree.h"

#include <stdio.h>
#include <stdlib.h>

Node* new_node(char symbol, int count) {
  Node* new = malloc(sizeof(Node));
  new->symbol = symbol;
  new->count = count;
  new->parent = NULL;
  new->right = NULL;
  new->left = NULL;
  return new;
}

void print_node(Node* node) {
  printf("Node %c\t", node->symbol);
  printf("\tAdress %p", (void*)node);
  printf("\tParent %p\n", (void*)node->parent);
  printf("Count %d", node->count);
  printf("\tLeft %p", (void*)node->left);
  printf("\tRight %p\n", (void*)node->right);
}
