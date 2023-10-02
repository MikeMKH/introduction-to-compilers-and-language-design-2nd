#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>

struct symbol * symbol_create(symbol_t kind, struct type *type, char *name) {
  struct symbol *s = malloc(sizeof(*s));
  
  s->kind = kind;
  s->type = type;
  s->name = name;
  
  return s;
}