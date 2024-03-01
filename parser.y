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
%token LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD_SUB POWER 
%token NUMBER STRING DOT SHIFT
%token LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
%start module 

%% 
module : stmt module
|/* empty */
;
stmt: simple_stmt
|compound_stmt
;
simple_stmt: small_stmt more_expr SEMICOLON
|  small_stmt more_expr
;
more_expr: SEMICOLON small_stmt more_expr
|/* empty */
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
Assign_stmt: ASSIGNMENT_OPERATOR testlist Assign_stmt
|/* empty */
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
elif_statements: /* empty */
| ELIF test COLON suite elif_statements
;
else_statement_opt: /* empty */
| ELSE COLON suite
;

while_stmt: WHILE test COLON suite else_statement_opt
;

for_stmt: FOR exprlist IN testlist COLON suite else_statement_opt
;


funcdef: DEF NAME parameters return_arrow_opt COLON suite
;
return_arrow_opt:/* empty */
|RETURN_ARROW test
;
parameters: LEFT_BRACKET typedargslist_opt RIGHT_BRACKET
;
typedargslist_opt: /* empty */
|typedargslist
;
typedargslist: full_tfpdef tfpdef_list
;
tfpdef_list: COMMA full_tfpdef tfpdef_list
|/* empty */
;
full_tfpdef: NAME annassign
|NAME
;



classdef: CLASS NAME opt_class_arg COLON suite
;
opt_class_arg:/* empty */
|LEFT_BRACKET opt_arglist RIGHT_BRACKET
;
opt_arglist:/* empty */
|arglist
;
arglist: argument comma_arg_star  opt_comma
;
opt_comma:/* empty */
|COMMA
;
comma_arg_star:/* empty */
|COMMA argument comma_arg_star
;
argument: test opt_comp_for
|test ASSIGNMENT_OPERATOR test
;
opt_comp_for:/* empty */
|comp_for
;
comp_iter: comp_for 
| comp_if
;
opt_comp_iter:/* empty */
|comp_iter
;
comp_for: FOR exprlist IN or_test opt_comp_iter
;
comp_if: IF test_nocond opt_comp_iter
;


suite: simple_stmt | NEWLINE INDENT stmt_list DEDENT
stmt_list : stmt stmt_list | /* empty */

test: or_test opt_if_or_test_else_test
;
opt_if_or_test_else_test:/* empty */
|IF or_test ELSE test
;
test_nocond:or_test 
;
or_test: and_test or_and_test_star
;
or_and_test_star: /* empty */
|OR and_test or_and_test_star
;
and_test: not_test and_not_test_star
;
and_not_test_star: /* empty */
|AND not_test and_not_test_star
;
not_test: NOT not_test 
|comparison
;
comparison: expr opt_expr
;
opt_expr : RELATIONAL_OPERATOR expr opt_expr
|/* empty */
;
expr: xor_expr opt_xor
;
opt_xor: /* empty */
|OR xor_expr opt_xor
;
xor_expr: and_expr opt_and
;
opt_and: /* empty */
|XOR and_expr opt_and
;
and_expr: shift_expr opt_shift
;
opt_shift: /* empty */
|AND shift_expr opt_shift
;
shift_expr: arith_expr opt_arith
;
opt_arith: /* empty */
|SHIFT arith_expr opt_arith
;
arith_expr: term opt_term
;
opt_term: /* empty */
|ADD_SUB term opt_term
;
term: factor opt_factor
;
opt_factor: /* empty */
|ARITHMETIC_OPERATOR factor opt_factor
;
factor: oper factor
|power
;
oper: ADD_SUB
|BIT_NOT
;
power: atom_expr opt_atom
;
opt_atom: POWER factor ;
|/* empty */
;
atom_expr: atom opt_trailer
;
opt_trailer: trailer opt_trailer
|/* empty */
;
atom: LEFT_BRACKET testlist_comp RIGHT_BRACKET
|LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET
|NAME
|NUMBER
|DATA_TYPE
|STRING
|NONE
|TRUE
|FALSE
;
testlist_comp: test comp_for
| test opt_test_stmt opt_comma
;
opt_test_stmt: /* empty */ 
|COMMA test opt_test_stmt
;
trailer: LEFT_BRACKET opt_arglist RIGHT_BRACKET
| LEFT_SQUARE_BRACKET subscriptlist RIGHT_SQUARE_BRACKET
| DOT NAME
subscriptlist: subscript opt_subscript opt_comma
;
opt_subscript: COMMA subscript opt_subscript
|/* empty */
;
subscript: test
|opt_test_sub COLON opt_test_sub opt_sliceop
;
opt_test_sub : test 
| /* empty */
;

opt_sliceop : sliceop
| /* empty */
;

sliceop: COLON opt_test_sub
;





testlist: test opt_testlist opt_comma
;
opt_testlist: /* empty */
|COMMA test opt_testlist
;


exprlist: expr opt_exprlist opt_comma
;
opt_exprlist: /* empty */
|COMMA expr opt_exprlist
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
   
   yyparse();
   
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}