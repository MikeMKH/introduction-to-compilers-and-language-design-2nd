#include <stdio.h>
#include "expr.h"

extern int yyparse();
extern struct expr * result;

int main()
{
  printf("***Expression Compiler***\n");
  printf("Enter an infix expression using the operators +-*/() ending with ;\n\n");

	if(yyparse() == 0) {
		expr_print(result);
	  printf("\n = %d\n", expr_evaluate(result));
	} else {
	  printf("Parse failed.\n");
    return 1;
	}
	
	return 0;
}
