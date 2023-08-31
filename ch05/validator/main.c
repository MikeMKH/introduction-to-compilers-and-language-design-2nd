/*
  validate if input follows the grammar
*/

#include <stdio.h>
extern int yyparse();

int main()
{
  printf("***Expression Validator***\n");
  printf("Enter an infix expression using the operators +-*/() ending with ;\n\n");

	if(yyparse() == 0) {
	  printf("Parse successful!\n");
	} else {
	  printf("Parse failed.\n");
    return 1;
	}
	
	return 0;
}
