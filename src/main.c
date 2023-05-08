#include <stdlib.h>

#include "btree.h"
#include "symbol_counter.h"

int main(void) {
  FrequencyMap* frequency_map = new_frequency_map();
  add_occurence(frequency_map, '4');
  add_occurence(frequency_map, '2');
  add_occurence(frequency_map, '0');
  add_occurence(frequency_map, '0');
  add_occurence(frequency_map, 'q');
  print_frequency_map(frequency_map);

  Node* root = new_node('\0', 0.0);
  Node* left_leaf = new_node('6', 4.2);
  Node* right_leaf = new_node('9', -4.2);
  root->left = left_leaf;
  root->right = right_leaf;
  left_leaf->parent = root;
  right_leaf->parent = root;
  print_node(root);
  print_node(left_leaf);
  print_node(right_leaf);

  free(root);
  free(left_leaf);
  free(right_leaf);
  free(frequency_map);
}
