#include "decl.h"
#include "type.h"
#include "expr.h"
#include "stmt.h"
#include <stdio.h>

struct decl * decl_create(
  char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next)
{
  struct decl *d = malloc(sizeof(*d));
  d->name = name;
  d->type = type;
  d->value = value;
  d->code = code;
  d->next = next;
}

void decl_print(struct decl *d, int indent )
{
  if (!d) return;
  
  printf("%*s: ", indent, d->name);
  type_print(d->type);
  if (d->value) { printf(" = "); expr_print(d->value); }
  if (d->code) { printf(" { "); stmt_print(d->code, indent*2); printf(" }"); }
  printf("\n");
  decl_print(d->next, indent);
}