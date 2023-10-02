%{
#include "parser.h"
%}

%option nounput
%option noinput

DIGIT 	[0-9]
LETTER	[a-zA-Z_]

%%

[ \n\r\t]* ;
"for"      return TOKEN_FOR;
"print"    return TOKEN_PRINT;
"if"       return TOKEN_IF;
"else"     return TOKEN_ELSE;
"function" return TOKEN_FUNCTION;
"return"   return TOKEN_RETURN;
{DIGIT}*   return TOKEN_INT;
{LETTER}*  return TOKEN_ID;
"="        return TOKEN_ASSIGN;
":"        return TOKEN_COLON;
"{"        return TOKEN_LBRACE;
"}"        return TOKEN_RBRACE;
\(         return TOKEN_LPAREN;
\)         return TOKEN_RPAREN;
\;         return TOKEN_SEMI;
.          { printf("scan error: bad token: %c\n",yytext[0]); }

%%

int yywrap()
{
	return 0;
}
