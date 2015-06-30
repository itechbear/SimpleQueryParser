//
// Created by hudong on 6/29/15.
//

#include "node.h"

#include <stdio.h>
#include <stdlib.h>

char *strdup(const char *s);

struct Node *GetTree(struct Node *node) {
  return node;
}

struct Node *TokenNode(char *text) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->text = strdup(text);
  node->children_count = 0;
  return node;
}

struct Node *AndNode(struct Node *first, struct Node *second) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->text = "AND";
  node->children_count = 2;
  node->children = (struct Node **) malloc(2 * sizeof(struct Node *));
  node->children[0] = first;
  node->children[1] = second;
  return node;
}

struct Node *OrNode(struct Node *first, struct Node *second) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->text = "OR";
  node->children_count = 2;
  node->children = (struct Node **) malloc(2 * sizeof(struct Node *));
  node->children[0] = first;
  node->children[1] = second;
  return node;
}

struct Node *NotNode(struct Node *node) {
  struct Node *parent = (struct Node *) malloc(sizeof(struct Node));
  parent->text = "NOT";
  parent->children_count = 1;
  parent->children = (struct Node **) malloc(sizeof(struct Node *));
  parent->children[0] = node;
  return parent;
}

struct Node *SideBySideNode(struct Node *first, struct Node *second) {
  return AndNode(first, second);
}

struct Node *ParenNode(struct Node *node) {
  return node;
}

void DestroyTree(struct Node *node) {
  if (node == NULL) {
    return;
  }
  for (int i = 0; i < node->children_count; ++i) {
    DestroyTree(node->children[i]);
  }
  free(node);
}

void PrintTree(struct Node *node) {
  if (node == NULL) {
    return;
  }

  printf("%s\n", node->text);
  for (int i = 0; i < node->children_count; ++i) {
    PrintTree(node->children[i]);
  }
}