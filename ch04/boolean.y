%{
#include <stdbool.h>
#include <stdio.h>
#include "boolean.yacc.h"

int yylex(void);
int yyerror(const char* s);
%}

%union {
    bool boolean_value;
}

%token <boolean_value> TRUE FALSE
%type <boolean_value> expression

%left OR
%left AND
%right IMPLIES

%%

expression: TRUE               { $$ = true; }
          | FALSE              { $$ = false; }
          | expression AND expression { $$ = $1 && $3; }
          | expression OR expression { $$ = $1 || $3; }
          | expression IMPLIES expression { $$ = !$1 || $3; }
          | '(' expression ')' { $$ = $2; }
          ;

%%

int main() {
    yyparse();
    // printf("Result: %s\n", ($$) ? "true" : "false");
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    return 0;
}
