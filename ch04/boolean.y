%token TOKEN_TRUE
%token TOKEN_FALSE
%token TOKEN_OR
%token TOKEN_AND
%token TOKEN_IMPLIES
%token TOKEN_LEFT_PAREN
%token TOKEN_RIGHT_PAREN
%token TOKEN_SEMI

%{

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define YYSTYPE bool

extern char *yytext;
extern int yylex();
extern int yyerror( const char *s );

bool result = true;

%}

%%

program : expr TOKEN_SEMI { result = $1; return 0; }

expr: TOKEN_TRUE                              { $$ = true; }
  | TOKEN_FALSE                               { $$ = false; }
  | expr TOKEN_AND expr                       { $$ = $1 && $3; }
  | expr TOKEN_OR expr                        { $$ = $1 || $3; }
  | expr TOKEN_IMPLIES expr                   { $$ = !$1 || $3; }
  | TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN { $$ = $2; }
  ;

%%

int yyerror(const char *s)
{
  fprintf(stderr, "Parse error: %s\n", s);
  return 0;
}
