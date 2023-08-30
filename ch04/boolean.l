%{
#include <stdbool.h>
#include "boolean.yacc.h" // Include the generated Bison header
%}

%%

"true"      { yylval.boolean_value = true; return TRUE; }
"false"     { yylval.boolean_value = false; return FALSE; }
"and"       { return AND; }
"or"        { return OR; }
"=>"        { return IMPLIES; }
"("         { return '('; }
")"         { return ')'; }
[ \t\n]     ; // Skip whitespace and newline characters
.           { return yytext[0]; } // Return any other character as is

%%
