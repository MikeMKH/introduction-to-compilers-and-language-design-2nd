#include "stmt.h"
#include "expat.h"
#include <stdio.h>

struct stmt * stmt_create(
  stmt_t kind, struct decl *decl,
  struct expr *init_expr, struct expr *expr, struct expr *next_expr,
  struct stmt *body, struct stmt *else_body, struct stmt *next) {
    struct stmt *s = malloc(sizeof(*s));
    
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    
    return s;
  }
  
void stmt_print(struct stmt *s, int indent) {
  if (!s) return;
  
  switch (s->kind)
  {
    case STMT_DECL:
      stmt_print(s->decl, indent);
      break;
    case STMT_EXPR:
      expr_print(s->decl);
      break;
    case STMT_IF_ELSE:
      for(int i; i < indent; i++) printf(" ");
      printf("if(");
      expr_print(s->expr);
      printf(") {\n");
      stmt_print(s->body, indent*2);
      for(int i; i < indent; i++) printf(" ");
      printf("} else {\n");
      stmt_print(s->else_body, indent*2);
      stmt_print(s->body, indent*2);
      for(int i; i < indent; i++) printf(" ");
      printf("}");
    case STMT_FOR:
      for(int i; i < indent; i++) printf(" ");
      printf("for(");
      expr_print(s->init_expr);
      printf("; ");
      expr_print(s->expr);
      printf("; ");
      expr_print(s->next_expr);
      printf(") {\n");
      stmt_print(s->body, indent*2);
      for(int i; i < indent; i++) printf(" ");
      printf("}");
      break;
    case STMT_PRINT:
      for(int i; i < indent; i++) printf(" ");
      printf("print ");
      expr_print(s->expr);
    case STMT_BLOCK:
      for(int i; i < indent; i++) printf(" ");
      printf("{\n");
      for(int i; i < indent; i++) printf(" ");
      expr_print(s->body);
      printf("}");
    default: 
      break;
  }
  
  printf("\n");
  stmt_print(s->next, indent);
}
