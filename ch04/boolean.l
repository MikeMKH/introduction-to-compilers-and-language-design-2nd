%{
#include <stdbool.h>
#include "parser.h"
%}

%option nounput
%option noinput

%%

"true"      { return TOKEN_TRUE; }
"false"     { return TOKEN_FALSE; }
"and"       { return TOKEN_AND; }
"or"        { return TOKEN_OR; }
"->"        { return TOKEN_IMPLIES; }
"("         { return TOKEN_LEFT_PAREN; }
")"         { return TOKEN_RIGHT_PAREN; }
";"         { return TOKEN_SEMI; }
[ \t\n]     ; // skip whitespace and newline characters
.           { return yytext[0]; } // return any other character as is

%%

int yywrap()
{
	return 0;
}
