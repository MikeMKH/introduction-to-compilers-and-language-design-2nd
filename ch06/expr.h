#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

typedef enum {
  EXPR_ADD,
  EXPR_SUB,
  EXPR_MUL,
  EXPR_DIV,
  EXPR_NAME,
  EXPR_INT,
  EXPR_BOOL,
  EXPR_CHAR,
  EXPR_STR
} expr_t;

struct expr {
  expr_t kind;
  
  /* used by operators exprs */
  struct expr *left;
  struct expr *right;
  
  /* used by leaf exprs */
  const char *name;
  int literal_value;
  const char * string_literal;
  struct symbol *symbol;
};

struct expr * expr_create(
  expr_t kind, struct expr *left, struct expr *right);

struct expr * expr_create_name(const char *n);
struct expr * expr_create_integer_literal(int i);
struct expr * expr_create_boolean_literal(int b);
struct expr * expr_create_char_literal(char c);
struct expr * expr_create_string_literal(const char *s);

void expr_print(struct expr *e);

#endif