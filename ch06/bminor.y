%union {
  struct decl *decl;
  struct expr *expr;
  struct param_list *param_list;
  struct symbol *symbol;
  struct type *type;
  struct stmt *stmt;
  char *name;
  int literal_int;
}

%token TOKEN_FOR
%token TOKEN_PRINT
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_FUNCTION
%token TOKEN_RETURN
%token TOKEN_INT
%token TOKEN_ID
%token TOKEN_ASSIGN
%token TOKEN_COLON
%token TOKEN_LBRACE
%token TOKEN_RBRACE
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_SEMI

%type <decl> program

%{

#include "decl.h"
#include "expr.h"
#include "param_list.h"
#include "stmt.h"
#include "symbol.h"
#include "type.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

%}

%%

program : name TOKEN_COLON TOKEN_FUNCTION type TOKEN_LPAREN TOKEN_RPAREN TOKEN_ASSIGN TOKEN_LBRACE stmt_list TOKEN_RPAREN
	;

stmt_list : stmt stmt_list
  | stmt
  ;

stmt : TOKEN_RETURN TOKEN_INT TOKEN_SEMI
  ;

name : TOKEN_ID
  ;

type : TOKEN_ID
  ;

%%

int yyerror( char *str )
{
  printf("parse error: %s\n",str);
	return 0;
}