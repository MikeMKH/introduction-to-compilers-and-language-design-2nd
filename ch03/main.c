#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main(int argc, char **argv)
{
  yyin = fopen(argv[1], "r");
  if (!yyin)
  {
    printf("could not open %s\n", argv[1]);
    return 1;
  }
  
  while(1)
  {
    token_t t = yylex();
    if (t == TOKEN_EOF) break;
    printf("token: %d text: %s\n", t, yytext);
  }
  return 0;
}