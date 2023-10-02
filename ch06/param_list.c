#include "param_list.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

struct param_list * param_list_create(char *name, struct type *type, struct param_list *next) {
  struct param_list *a = malloc(sizeof(*a));
  
  a->name = name;
  a->type = type;
  a->next = next;
  
  return a;
}
  
void param_list_print(struct param_list *a) {
  if (!a) return;
  
  printf("%s: ", a->name);
  type_print(a->type);
  
  if (!a->next) return;
  
  printf(", ");
  param_list_print(a->next);
}