%{
#include <bits/stdc++.h>
using namespace std;

extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern char* yytext;

extern FILE* yyin;  
extern FILE* yyout;

%}

%token ARITHMETIC_OPERATOR RELATIONAL_OPERATOR LOGICAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token IN DEF OR AND NOT RETURN

%start module 

%% 
module : stmt module
|%empty
;
stmt: simple_stmt
|compound_stmt
;
simple_stmt: small_stmt more_expr SEMICOLON
|  small_stmt more_expr
;
more_expr: SEMICOLON small_stmt more_expr
|%empty
;
small_stmt: expr_stmt
|break_stmt
|continue_stmt
|return_stmt
;

expr_stmt: testlist right_assign
;
right_assign: annassign 
| AUGASSIGNMENT_OPERATOR testlist 
|Assign_stmt
;
Assign_stmt: ASSIGNMENT_OPERATOR testlist_star_expr Assign_stmt
|%empty
;
annassign: COLON test ASSIGNMENT_OPERATOR test
|COLON test
;

break_stmt: BREAK
;
continue_stmt: CONTINUE
;
return_stmt: RETURN 
| RETURN testlist


compound_stmt: if_stmt|while_stmt|for_stmt|funcdef|classdef
;
if_stmt: IF test COLON suite elif_statements else_statement_opt
;
elif_statements:%empty
| ELIF test COLON suite elif_statements
;
else_statement_opt:%empty
| ELSE COLON suite
;

while_stmt: WHILE test COLON suite else_statement_opt
;

for_stmt: FOR exprlist IN testlist COLON suite else_statement_opt
;


funcdef: DEF NAME parameters return_arrow_opt COLON suite
;
return_arrow_opt:%empty
|RETURN_ARROW test
;
parameters: LEFT_BRACKET typedargslist_opt RIGHT_BRACKET
;
typedargslist_opt: %empty
|typedargslist
;
typedargslist: full_tfpdef tfpdef_list
;
tfpdef_list: COMMA full_tfpdef tfpdef_list
|%empty
;
full_tfpdef: NAME annassign
|NAME
;



classdef: CLASS NAME opt_class_arg COLON suite
;
opt_class_arg:%empty
|LEFT_BRACKET opt_arglist RIGHT_BRACKET
;
opt_arglist:%empty
|arglist
;
arglist: argument comma_arg_star  opt_comma
;
opt_comma:%empty
|COMMA
;
comma_arg_star:%empty
|COMMA argument comma_arg_star
;
argument: test opt_comp_for
|test ASSIGNMENT_OPERATOR test
;
opt_comp_for:%empty
|comp_for
;
comp_iter: comp_for 
| comp_if
;
opt_comp_iter:%empty
|comp_iter
;
comp_for: FOR exprlist IN or_test opt_comp_iter
;
comp_if: IF test_nocond opt_comp_iter
;





test: or_test opt_if_or_test_else_test
;
opt_if_or_test_else_test:%empty
|IF or_test ELSE test
;
test_nocond:or_test 
;
or_test: and_test or_and_test_star
;
or_and_test_star: %empty
|OR and_test or_and_test_star
;
and_test: not_test and_not_test_star
;
and_not_test_star: %empty
|AND not_test and_not_test_star
;
not_test: NOT not_test 
|comparison
;



testlist_star_expr:%empty
;

testlist: test opt_testlist opt_comma
;
opt_testlist: %empty
|COMMA test opt_testlist
;

suite: %empty
;
exprlist: %empty
;
comparison :%empty
;
%%

void yyerror(const char *s){
   cout<<"f u";
   return ;
}


int main ( int argc, char *argv[]){
     
   cout<<argv[2];
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   string s;
   fscanf(yyin,"%s",&s);
   fprintf(yyout,"%s",s);
   
   yyparse();
   
   fclose(yyin);
   fclose(yyout);
   
   
   return 0;
}