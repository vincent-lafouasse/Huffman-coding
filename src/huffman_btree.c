#include "huffman_btree.h"

#include <stdio.h>
#include <stdlib.h>

#include "huffman_queue.h"

Node* construct_huffman_tree_from_map(FrequencyMap* map) {
  PriorityQueue* queue = new_queue_from_frequency_map(map);

  while (queue->len >= 2) {
    Node* left = pop(queue);
    Node* right = pop(queue);

    Node* internal = new_node('\0', left->count + right->count);
    internal->left = left;
    internal->right = right;
    left->parent = internal;
    right->parent = internal;
    push(queue, internal);
  }
  Node* root = pop(queue);
  free(queue);
  return root;
}

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

static int max(int a, int b) {
  return (a >= b) * a + (a < b) * b;
}

int tree_height(Node* node) {
  int height = 0;

  if (node == NULL) {
    return height;
  }

  return 1 + max(tree_height(node->left), tree_height(node->right));
}

void free_btree(Node* root) {
  if (root->left != NULL) {
    free(root->left);
  }
  if (root->right != NULL) {
    free(root->right);
  }
  free(root);
}
