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

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

%}

%%

program : expr TOKEN_SEMI { return 0; }
	;

expr : expr TOKEN_PLUS term
	| expr TOKEN_MINUS term
	| term
	;

term : term TOKEN_MUL factor
	| term TOKEN_DIV factor
	| factor
	;

factor : TOKEN_MINUS factor
	| TOKEN_LPAREN expr TOKEN_RPAREN
	| TOKEN_INT
	;

%%

int yyerror( char *str )
{
  printf("parse error: %s\n",str);
	return 0;
}