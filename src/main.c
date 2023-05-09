#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
#include "huffman_queue.h"
#include "symbol_counter.h"

#define BUFFER_SIZE 256

int main(int argc, char* argv[]) {
  char input[BUFFER_SIZE];
  if (argc == 1) {
    strcpy(input, "420 lol bjr,,,");
  } else {
    strcpy(input, argv[1]);
  }
  printf("Input: %s\n", input);
  FrequencyMap* frequency_map = frequency_map_from_string(input);
  print_frequency_map(frequency_map);

  // Node* root = new_node('\0', 0.0);
  // Node* left_leaf = new_node('6', 4.2);
  // Node* right_leaf = new_node('9', -4.2);
  // root->left = left_leaf;
  // root->right = right_leaf;
  // left_leaf->parent = root;
  // right_leaf->parent = root;
  // print_node(root);
  // print_node(left_leaf);
  // print_node(right_leaf);

  // free(root);
  // free(left_leaf);
  // free(right_leaf);
  free(frequency_map);
}
