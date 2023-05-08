#include <stdlib.h>

#include "btree.h"

int main(void) {
  Node* root = new_node('\0', 0.0);
  print_node(root);

  free(root);
}
