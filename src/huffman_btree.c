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
  printf("Node '%c'\t", node->symbol);
  printf("%d\n", node->count);
  printf("Adress %p", (void*)node);
  printf("\tParent %p", (void*)node->parent);
  printf("\t\tLeft %p", (void*)node->left);
  printf("\tRight %p\n", (void*)node->right);
}
