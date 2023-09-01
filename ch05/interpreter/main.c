/*
  validate if input follows the grammar
*/

#include <stdio.h>
extern int yyparse();
extern int result;

int main()
{
  printf("***Expression Interpreter***\n");
  printf("Enter an infix expression using the operators +-*/() ending with ;\n\n");

	if(yyparse() == 0) {
	  printf(" = %d\n", result);
	} else {
	  printf("Parse failed.\n");
    return 1;
	}
	
	return 0;
}
