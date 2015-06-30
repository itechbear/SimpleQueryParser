//
// Created by hudong on 6/29/15.
//

#ifndef PARSER_NODE_H_
#define PARSER_NODE_H_

#ifdef __cplusplus
extern "C" {
#endif

struct Node {
  char *text;
  struct Node **children;
  int children_count;
};

struct Node *GetTree(struct Node *node);

struct Node *TokenNode(char *text);

struct Node *AndNode(struct Node *first, struct Node *second);

struct Node *OrNode(struct Node *first, struct Node *second);

struct Node *NotNode(struct Node *node);

struct Node *SideBySideNode(struct Node *first, struct Node *second);

struct Node *ParenNode(struct Node *node);

void PrintTree(struct Node *root);

void DestroyTree(struct Node *node);

#ifdef __cplusplus
}
#endif

#endif  // PARSER_NODE_H_
