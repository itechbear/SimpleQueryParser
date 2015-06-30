#include "stdio.h"

#include "node.h"
#include <stdlib.h>

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern "C" {
  int yyparse(struct Node **node);
  YY_BUFFER_STATE yy_scan_string(char *base);
}

int main(int argc, char *argv[]) {
  yy_scan_string(argv[1]);
  struct Node *node = NULL;
  if (0 == yyparse(&node)) {
    PrintTree(node);
    DestroyTree(node);
  }
  return 0;
}