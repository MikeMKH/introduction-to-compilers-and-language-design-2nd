#ifndef EXPR_H
#define EXPR_H

typedef enum {
	EXPR_ADD,
	EXPR_SUBTRACT,
	EXPR_DIVIDE,
	EXPR_MULTIPLY,
	EXPR_VALUE
} expr_t;

struct expr {
  expr_t kind;
  int value;
  struct expr *left;
  struct expr *right;
};

struct expr* expr_create(expr_t kind, struct expr *left, struct expr *right);
struct expr* expr_create_value(int value);

void expr_print(struct expr *e);
void expr_delete(struct expr *e);
int  expr_evaluate(struct expr *e);

#endif
