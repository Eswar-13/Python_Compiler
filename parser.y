%{
#include <bits/stdc++.h>
using namespace std;

extern int yyparse();
extern int yylex();
extern int yylineno;
extern char* yytext;

extern FILE* yyin;  
extern FILE* yyout;

%}

%token ARITHMETIC_OPERATOR RELATIONAL_OPERATOR LOGICAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CONTINUE LIST 
%token SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA
%start module

%% 
module : simple_stmt|compound_stmt
simple_stmt: small_stmt more_expr SEMICOLON
|  small_stmt more_expr
more_expr: SEMICOLON small_stmt more_expr
| 
small_stmt: expr_stmt
|break_stmt
|continue_stmt
expr_stmt: testlist_star_expr right_assign
right_assign: annassign 
| AUGASSIGNMENT_OPERATOR testlist 
|Assign_stmt
Assign_stmt: ASSIGNMENT_OPERATOR testlist_star_expr Assign_stmt
|
annassign: COLON test ASSIGNMENT_OPERATOR test
|COLON test
break_stmt: BREAK
continue_stmt: CONTINUE


compound_stmt: if_stmt|while_stmt|for_stmt|funcdef|classdef|decorated|async_stmt
async_stmt: ASYNC funcdef
|ASYNC for_stmt
;

if_stmt: IF test COLON suite elif_statements else_statement_opt

elif_statements:%empty
| ELIF test COLON suite elif_statements
;

else_statement_opt:%empty
| ELSE COLON suite
;

while_stmt: WHILE test COLON suite else_statement_opt

for_stmt: FOR exprlist IN testlist COLON suite else_statement_opt

funcdef: DEF NAME parameters return_arrow_opt COLON suite

return_arrow_opt:%empty
|RETURN_ARROW test
;

parameters: LEFT_BRACKET typedargslist_opt RIGHT_BRACKET

typedargslist_opt: %empty
|typedargslist

typedargslist: tfpdef_list
| tfpdef_list ',' STAR [tfpdef_list] opt_tfpdef_comma opt_double_star tfpdef [opt_tfpdef_comma]
| tfpdef_list ',' DOUBLE_STAR tfpdef [opt_tfpdef_comma]
;

assign_test_opt:%empty
|ASSIGNMENT_OPERATOR test
;

opt_tfpdef_comma:%empty
|COMMA tfpdef assign_test_opt
|opt_tfpdef_comma opt_tfpdef_comma
;

tfpdef_opt:%empty
|tfpdef
;







%%

void yyerror(char * s){
   return ;
}


int main ( int argc, char *argv[]){
   if(argc<5){
      ;
   }
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   yyparse();
   fclose(yyin);
   fclose(yyout);
   return 0;
}