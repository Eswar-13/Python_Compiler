%{
#include <bits/stdc++.h>
using namespace std;

extern int yyparse();
extern int yylex();
extern int yylineno;
extern char* yytext;

%}

%token ARITHMETIC_OPERATOR RELATIONAL_OPERATOR LOGICAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CONTINUE LIST 
%start module

%% 
module : ARITHMETIC_OPERATOR {;}
%%

void yyerror(char * s){
   return ;
}


int main ( int argc, char **argv){
   yyparse();
   cout<<argc;
   cout<<argv[0];
   return 0;
}