#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#include "symbol_counter.h"

int main(void) {
  const char* input = "420 lol bjr,,,";
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
