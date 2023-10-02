#include "expr.h"
#include <stdio.h>
#include <stdlib.h>

struct expr * expr_create(expr_t kind, struct expr *left, struct expr *right) {
  struct expr *e = malloc(sizeof(*e));
  
  e->kind = kind;
  e->left = left;
  e->right = right;
  
  return e;   
}

struct expr * expr_create_name(const char *n) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = EXPR_NAME;
  e->name = n;
  return e;
}

struct expr * expr_create_integer_literal(int i) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = EXPR_INT;
  e->literal_value = i;
  return e;
}

struct expr * expr_create_boolean_literal(int b) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = EXPR_BOOL;
  e->literal_value = b;
  return e;
}

struct expr * expr_create_char_literal(char c) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = EXPR_CHAR;
  e->literal_value = c;
  return e;
}
struct expr * expr_create_string_literal(const char *s) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = EXPR_STR;
  e->string_literal = s;
  return e;
}

void expr_print(struct expr *e) {
  if (!e) return;
  
  switch (e->kind)
  {
    case EXPR_ADD:
      expr_print(e->left);
      printf(" + ");
      expr_print(e->right);
      break;
    case EXPR_SUB:
      expr_print(e->left);
      printf(" - ");
      expr_print(e->right);
      break;
    case EXPR_MUL:
      expr_print(e->left);
      printf(" * ");
      expr_print(e->right);
      break;
    case EXPR_DIV:
      expr_print(e->left);
      printf(" / ");
      expr_print(e->right);
      break;
    case EXPR_BOOL:
      e->literal_value ? printf("true") : printf("false");
      break;
    case EXPR_CHAR:
      printf("%c", e->literal_value);
      break;
    case EXPR_INT:
      printf("%d", e->literal_value);
      break;
    case EXPR_NAME:
      printf("%s", e->name);
      break;
    case EXPR_STR:
      printf("%s", e->string_literal);
      break;
    default:
      break;
  }
}