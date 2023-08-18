%{
#include "token.h"
%}
DIGIT  [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
 \+         { return TOKEN_ADD; }
while       { return TOKEN_WHILE; }
{LETTER}+   { return TOKEN_LETTER; }
{DIGIT}+    { return TOKEN_NUMBER; }
.           { return TOKEN_OTHER; }
%%
int yywrap() { return 1; }