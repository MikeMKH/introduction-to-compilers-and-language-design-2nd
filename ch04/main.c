#include <stdio.h>
#include <stdbool.h>

extern int yyparse();
extern bool result;

int main()
{
  printf("***Boolean Expression Interpreter***\n");
  printf("Enter an infix expression using the operators and or -> () ending with ;\n\n");

	if(yyparse() == 0) {
	  printf(" = %s\n", result ? "true" : "false");
	} else {
	  printf("Parse failed.\n");
    return 1;
	}
	
	return 0;
}
