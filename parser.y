%{
#include <bits/stdc++.h>
using namespace std;

#define YYDEBUG 1

extern int yydebug;
extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern char* yytext;
extern FILE* yyin;  
extern FILE* yyout;

%}

%token ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD_SUB POWER BIT_AND BIT_OR
%token NUMBER STRING DOT SHIFT
%token LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
%start module 

%precedence low
%precedence low1
%precedence low2
%precedence low3
%precedence low4
%precedence low5
%precedence low6
%precedence high
%precedence high1
%precedence NEWLINE SEMICOLON COLON ASSIGNMENT_OPERATOR AUGASSIGNMENT_OPERATOR ADD_SUB AND ARITHMETIC_OPERATOR BIT_AND BIT_NOT BIT_OR BITWISE_OPERATOR BREAK LEFT_BRACKET RIGHT_BRACKET LEFT_CURLY_BRACKET LEFT_SQUARE_BRACKET RIGHT_CURLY_BRACKET RIGHT_SQUARE_BRACKET CLASS COMMA CONTINUE DATA_TYPE DEDENT DEF DOT ELIF ELSE FALSE FOR IF IN INDENT LIST NAME NONE NOT NUMBER OR POWER RELATIONAL_OPERATOR RETURN RETURN_ARROW SHIFT STRING TRUE WHILE XOR YYEOF 


%% 
module : stmt module %prec high
|/* empty */ %prec low
;
stmt: NEWLINE | simple_stmt | compound_stmt | testlist
;

simple_stmt: more_expr %prec low
| more_expr SEMICOLON %prec high
;
more_expr:more_expr SEMICOLON small_stmt {cout<<"y";}
|small_stmt
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
Assign_stmt:  Assign_stmt ASSIGNMENT_OPERATOR testlist | ASSIGNMENT_OPERATOR testlist
;
annassign: COLON test ASSIGNMENT_OPERATOR test %prec high
|COLON test %prec low
;

break_stmt: BREAK
;
continue_stmt: CONTINUE
;
return_stmt: RETURN %prec low
| RETURN testlist %prec high
;


compound_stmt: if_stmt|while_stmt|for_stmt|funcdef|classdef 
;
if_stmt: IF test COLON suite 
|IF test COLON suite else_statement
|IF test COLON suite elif_statements 
|IF test COLON suite elif_statements else_statement
;
elif_statements: elif_statements ELIF test COLON suite 
| ELIF test COLON suite 
;
else_statement: ELSE COLON suite
;

while_stmt: WHILE test COLON suite %prec low
|WHILE test COLON suite else_statement %prec high
;

for_stmt: FOR exprlist IN testlist COLON suite %prec low
| FOR exprlist IN testlist COLON suite else_statement %prec high
;

funcdef: DEF NAME parameters COLON suite
| DEF NAME parameters RETURN_ARROW test COLON suite
;

parameters: LEFT_BRACKET RIGHT_BRACKET
| LEFT_BRACKET typedargslist RIGHT_BRACKET
;

typedargslist: typedargslist COMMA full_tfpdef 
| full_tfpdef 
;

full_tfpdef: NAME annassign %prec high
|NAME %prec low
;
classdef: CLASS NAME opt_class_arg COLON suite|
CLASS NAME COLON suite
;
opt_class_arg: LEFT_BRACKET RIGHT_BRACKET
|LEFT_BRACKET opt_arglist RIGHT_BRACKET
;
opt_arglist: arglist COMMA %prec high
|arglist %prec low
;
arglist: arglist COMMA argument %prec high
| argument %prec low
;
argument: test 
| test comp_for
|test ASSIGNMENT_OPERATOR test
;
comp_iter: comp_for 
| comp_if
;
comp_for: FOR exprlist IN or_test 
| FOR exprlist IN or_test comp_iter
;
comp_if: IF test_nocond 
| IF test_nocond comp_iter
;


suite: simple_stmt | NEWLINE INDENT stmt_list DEDENT
|NEWLINE INDENT stmt_list YYEOF
;
stmt_list : stmt_list stmt| stmt
;

test: or_test IF or_test ELSE test %prec high
|or_test %prec low
;
test_nocond:or_test 
;
or_test: and_test or_and_test_plus %prec high
|and_test %prec low
;
or_and_test_plus: OR and_test
|or_and_test_plus OR and_test
;
and_test: not_test and_not_test_plus
|not_test
;
and_not_test_plus: AND not_test
|and_not_test_plus AND not_test 
;
not_test: NOT not_test 
|comparison
;
comparison: expr opt_expr
|expr
;
opt_expr : opt_expr RELATIONAL_OPERATOR expr
|RELATIONAL_OPERATOR expr
;
expr: xor_expr opt_xor
|xor_expr
;
opt_xor: BIT_OR xor_expr
|opt_xor BIT_OR xor_expr
;
xor_expr: and_expr opt_and_plus
|and_expr
;
opt_and_plus: XOR and_expr
|opt_and_plus XOR and_expr 
;
and_expr: shift_expr opt_shift
|shift_expr
;
opt_shift: BIT_AND shift_expr 
|opt_shift BIT_AND shift_expr 
;
shift_expr: arith_expr opt_arith
|arith_expr
;
opt_arith: SHIFT arith_expr
|opt_arith SHIFT arith_expr 
;
arith_expr: term opt_term %prec high
|term %prec low
;
opt_term: ADD_SUB term
|opt_term ADD_SUB term
;
term: factor opt_factor %prec high
|factor %prec low
;
opt_factor: ARITHMETIC_OPERATOR factor
|opt_factor ARITHMETIC_OPERATOR factor 
;
factor: oper factor
|power
;
oper: ADD_SUB
|BIT_NOT
;
power: atom_expr POWER factor %prec high
|atom_expr %prec low
;
atom_expr: atom opt_trailer %prec high
|atom %prec low
;
opt_trailer:opt_trailer trailer 
|trailer
;
atom: LEFT_BRACKET testlist_comp RIGHT_BRACKET
|LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET
|LEFT_BRACKET  RIGHT_BRACKET
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET
|NAME
|NUMBER
|DATA_TYPE
|STRING
|NONE
|TRUE
|FALSE
|LIST
;

testlist_comp: test comp_for
| opt_test_stmt COMMA
|opt_test_stmt
;
opt_test_stmt: test
|opt_test_stmt COMMA test 
;
trailer: LEFT_BRACKET arglist RIGHT_BRACKET
|LEFT_BRACKET RIGHT_BRACKET
| LEFT_SQUARE_BRACKET subscriptlist RIGHT_SQUARE_BRACKET
| DOT NAME
subscriptlist: opt_subscript COMMA
|opt_subscript
;
opt_subscript:opt_subscript COMMA subscript
|subscript
;
subscript: test
|test COLON test sliceop
|test COLON test 
| COLON test sliceop
| COLON test 
|test COLON  sliceop
|test COLON 
| COLON  sliceop
| COLON 
;


sliceop: COLON test
|COLON
;

testlist: testlist COMMA test | test 
;

exprlist: exprlist COMMA expr |expr 
;


%%

void yyerror(const char *s){
   cout<<" f u \n"<<yytext;
   return ;
}


int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   
   yydebug=0;
   yyparse();
   
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}