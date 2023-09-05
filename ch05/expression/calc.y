/*
  declare token types to be automatically generated in parser.tab.h for scanner.c.
*/

%token TOKEN_ID
%token TOKEN_INTEGER
%token TOKEN_INT
%token TOKEN_SEMI
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN

%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

#define YYSTYPE struct expr *

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

struct expr * result = 0;

%}

%%

program : expr TOKEN_SEMI { result = $1; return 0; }
	;

expr : expr TOKEN_PLUS term { $$ = expr_create(EXPR_ADD, $1, $3); }
	| expr TOKEN_MINUS term   { $$ = expr_create(EXPR_SUBTRACT, $1, $3); }
	| term                    { $$ = $1; }
	;

term : term TOKEN_MUL factor { $$ = expr_create(EXPR_MULTIPLY, $1, $3); }
	| term TOKEN_DIV factor    { $$ = expr_create(EXPR_DIVIDE, $1, $3); }
	| factor                   { $$ = $1; }
	;

factor : TOKEN_MINUS factor        { $$ = expr_create(EXPR_SUBTRACT, expr_create_value(0), $2); }
	| TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
	| TOKEN_INT                      { $$ = expr_create_value(atoi(yytext)); }
	;

%%

int yyerror( char *str )
{
  printf("parse error: %s\n",str);
	return 0;
}