%{
#include <stdio.h>

#include "node.h"

int yylex();
void yyerror(struct Node **node, const char *s);
%}

%start query
%token TOKEN
%token AND
%token NOT
%token OR
%left AND OR
%right NOT

%union {
  char *token;
  struct Node *node;
}
%type<node> query expression
%type<token> TOKEN

%parse-param {struct Node **node}

%%
query : expression                { *node = GetTree($1); };

expression : TOKEN                { $$ = TokenNode($1); }
    | expression AND expression   { $$ = AndNode($1, $3); }
    | expression OR expression    { $$ = OrNode($1, $3); }
    | NOT expression              { $$ = NotNode($2); }
    | expression expression       { $$ = SideBySideNode($1, $2); }
    | '(' expression ')'          { $$ = ParenNode($2); }
  ;

%%

void yyerror(struct Node **node, const char *s) {
  DestroyTree(*node);
};
