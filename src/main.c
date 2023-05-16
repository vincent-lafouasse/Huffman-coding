#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "frequency_map.h"
#include "huffman_btree.h"
#include "huffman_queue.h"

#define BUFFER_SIZE 256

int main(int argc, char* argv[]) {
  // take care of sysargs
  char input[BUFFER_SIZE];
  if (argc == 1) {
    strcpy(input, "420 lol bjr,,,");
  } else {
    strcpy(input, argv[1]);
  }
  // printf("Input: %s\n", input);

  // create frequency map
  FrequencyMap* frequency_map = frequency_map_from_string(input);

  // construct huffman tree
  Node* root = construct_huffman_tree_from_map(frequency_map);
  print_node(root);

  // encoding
  //

  free(frequency_map);
  free_btree(root);
}
