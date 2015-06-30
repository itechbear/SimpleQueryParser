%{
#include "parser.tab.h"

extern YYSTYPE yylval;

int fileno(FILE *stream);
char *strdup(const char *str);
%}

%option nodefault noyywrap

CHAR [^ \t\n()]

%%

AND      { return(AND); }
OR       { return(OR); }
NOT      { return(NOT); }
{CHAR}+  { yylval.token = strdup(yytext); return(TOKEN); }
[ \t\n]+ /* do nothing */
.        { return(yytext[0]); }

%%
