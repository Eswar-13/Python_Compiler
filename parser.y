%{
#include <bits/stdc++.h>
using namespace std;

#define YYDEBUG 1

extern int yydebug;
extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern char * lexeme;
extern FILE* yyin;  
extern FILE* yyout;
extern int yychar;

int node=0;

char* integerToOperator(int value) {
    // Map each integer value to its corresponding operator string
    if (value == 0) {
        return (char *) "+=";
    } else if (value == 1) {
        return (char *) "-=";
    } else if (value == 2) {
        return (char *) "*=";
    } else if (value == 3) {
        return (char *) "/=";
    } else if (value == 4) {
        return (char *) "//=";
    } else if (value == 5) {
        return (char *) "%=";
    } else if (value == 6) {
        return (char *) "**=";
    } else if (value == 7) {
        return (char *) "&=";
    } else if (value == 8) {
        return (char *) "|=";
    } else if (value == 9) {
        return (char *) "^=";
    } else if (value == 10) {
        return (char *) "<<=";
    } else if (value == 11) {
        return (char *) ">>=";
    } else {
        return (char *)""; // Return empty string for invalid integer values
    }
}

%}

%union{
   struct{
     int top;
     int low;
   }attributes;
}

%token<attributes> ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token<attributes> SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token<attributes> LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token<attributes> IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD SUB POWER BIT_AND BIT_OR
  %token<attributes> NUMBER STRING DOT L_SHIFT R_SHIFT STRING_1
  %token<attributes> LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET INVALID

%type<attributes>  module stmt simple_stmt compound_stmt testlist expr more_expr small_stmt expr_stmt break_stmt continue_stmt return_stmt annassign Assign_stmt test if_stmt while_stmt for_stmt funcdef classdef suite else_statement elif_statements exprlist parameters typedargslist full_tfpdef opt_class_arg opt_arglist arglist argument comp_for comp_if comp_iter comparison stmt_list or_test and_test not_test xor_expr and_expr shift_expr arith_expr term factor power atom_expr atom opt_trailer trailer testlist_comp opt_test_stmt  
%type<attributes>  a_o r_o param_list name
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
%precedence NEWLINE SEMICOLON STRING_1 COLON ASSIGNMENT_OPERATOR AUGASSIGNMENT_OPERATOR ADD SUB AND ARITHMETIC_OPERATOR BIT_AND BIT_NOT BIT_OR BITWISE_OPERATOR BREAK LEFT_BRACKET RIGHT_BRACKET LEFT_CURLY_BRACKET LEFT_SQUARE_BRACKET RIGHT_CURLY_BRACKET RIGHT_SQUARE_BRACKET CLASS COMMA CONTINUE DATA_TYPE DEDENT DEF DOT ELIF ELSE FALSE FOR IF IN INDENT LIST NAME NONE NOT NUMBER OR POWER RELATIONAL_OPERATOR RETURN RETURN_ARROW SHIFT STRING TRUE WHILE XOR YYEOF 

%% 
module : module stmt%prec high { if($2.top!=-1)fprintf(yyout,"module--%d;\n",$2.top);}
|stmt { if($1.top!=-1)fprintf(yyout,"module--%d;\n",$1.top);}
;

stmt: 
NEWLINE {$$.top=-1;}
| simple_stmt {$$.top=$1.top;}
| compound_stmt {$$.top=$1.top;}
| testlist {$$.top=$1.top;}
;

simple_stmt: more_expr %prec low {$$.top=$1.top;}
| more_expr SEMICOLON %prec high {fprintf(yyout,"%d--%d; %d[label=\" DELIMITER(;)\"];\n",$1.top,node,node); node++; $$.top=$1.top;}
;
more_expr:
more_expr SEMICOLON small_stmt {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(;)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
|small_stmt {fprintf(yyout,"%d--%d; %d[label=\" Stmt List\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;


small_stmt: 
expr_stmt      {$$.top=$1.top;}
|break_stmt    {$$.top=$1.top;}
|continue_stmt {$$.top=$1.top;}
|return_stmt   {$$.top=$1.top;}
;

expr_stmt: 
testlist annassign {fprintf(yyout,"%d--%d;\n",$2.top,$1.top); $$.top=$2.top;}
|testlist AUGASSIGNMENT_OPERATOR testlist {fprintf(yyout,"%d--%d; %d--%d; %d[label=\"Operator (%s)\"];\n",$1.low,node,node,$3.top,node,integerToOperator($2.top)); node++; fprintf(yyout,"%d--%d; %d[label=\" Expr\"];\n",node,$1.top,node); node++; $$.top=node-1; }   
|testlist Assign_stmt   { fprintf(yyout,"%d--%d;\n",$1.low,$2.top); fprintf(yyout,"%d--%d; %d[label=\" Expr\"];\n",node,$1.top,node); node++; $$.top=node-1;}
;
Assign_stmt:  
Assign_stmt ASSIGNMENT_OPERATOR testlist  {fprintf(yyout,"%d--%d; %d--%d;%d[label=\"assignment\"];\n",node,$3.top,$1.low,node,node); node++; $$.top=$1.top; $$.low=$3.low;}
| ASSIGNMENT_OPERATOR testlist   {fprintf(yyout,"%d--%d; %d[label=\"assignment\"];\n",node,$2.top,node); node++; $$.top=node-1; $$.low=$2.low;}
;
annassign:
COLON test param_list %prec high  {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node,$2.top,$3.top); fprintf(yyout,"%d[label=\" COLON\"];\n",node); node++;  fprintf(yyout,"%d--%d; %d--%d;  %d--%d; %d[label=\" Annassign\"];\n",node,$2.top,node,$3.top,node,node-1,node); node++; $$.top=node-1;  }
|COLON test %prec low    {fprintf(yyout,"{rank = same; %d -- %d  [ style=invis ];rankdir = LR;}",node,$2.top); fprintf(yyout,"%d[label=\" COLON\"];\n",node); node++; $$.top=node-1; fprintf(yyout,"%d--%d; %d--%d; %d[label=\" Annassign\"];\n",node,$2.top,node,node-1,node); node++; $$.top=node-1;}
;

param_list:
ASSIGNMENT_OPERATOR test  {fprintf(yyout,"%d[label=\"assignment\"];\n",node); node++; fprintf(yyout,"%d--%d; %d--%d; %d[label=\" param_list \"];\n",node,node-1,node-1,$2.top,node); node++; $$.top=node-1;}

break_stmt: 
BREAK  {fprintf(yyout,"%d[label=\" KEYWORD(break) \"];\n",node); node++; $$.top=node-1;}
;
continue_stmt: 
CONTINUE    {fprintf(yyout,"%d[label=\" KEYWORD(continue) \"];\n",node); node++; $$.top=node-1;}
;
return_stmt: 
RETURN %prec low   {fprintf(yyout,"%d[label=\" KEYWORD(return) \"];\n",node); node++; fprintf(yyout,"%d--%d;%d[label=\" return_stmt \"];\n",node,node-1,node); node++; $$.top=node-1;}
| RETURN test %prec high   {fprintf(yyout,"{rank = same; %d -- %d [ style=invis ];rankdir = LR;}",node,$2.top); fprintf(yyout,"%d[label=\" KEYWORD(return) \"];\n",node); node++;  fprintf(yyout,"%d--%d;%d--%d;%d[label=\" return_stmt \"];\n",node,node-1,node,$2.top,node); node++; $$.top=node-1;}
;



compound_stmt: 
if_stmt        {$$.top=$1.top;}
|while_stmt    {$$.top=$1.top;}
|for_stmt      {$$.top=$1.top;}
|funcdef       {$$.top=$1.top;}
|classdef      {$$.top=$1.top;}
;
if_stmt: 
IF test COLON suite        {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);node=node+3;$$.top=node-3;}
|IF test COLON suite else_statement    {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top,$5.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
|IF test COLON suite elif_statements   {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top,$5.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
|IF test COLON suite elif_statements else_statement   {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d[ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top,$5.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;\n",node,$5.top);fprintf(yyout,"%d--%d;\n",$5.low,$6.top); node=node+3; $$.top=node-3;}
;
elif_statements: 
elif_statements ELIF test COLON suite  { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$3.top,node+2,$5.top); fprintf(yyout,"%d--%d;\n",$1.top,node); fprintf(yyout,"%d--%d;%d[label=\"Keyword(elif)\"];%d[label=\"elif_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$3.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=$1.top; $$.low=node-3;}
|ELIF test COLON suite                { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(elif)\"];%d[label=\"elif_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top); fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2); fprintf(yyout,"%d--%d;\n",node,$4.top); node=node+3; $$.top=node-3; $$.low=node-3;}
;
else_statement: 
ELSE COLON suite        { fprintf(yyout,"{rank = same; %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,node+2,$3.top);  fprintf(yyout,"%d--%d;%d[label=\"Keyword(else)\"];%d[label=\"else_statement\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$3.top);node=node+3;$$.top=node-3;}
;

while_stmt: 
WHILE test COLON suite %prec low    { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(while)\"];%d[label=\"while_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);node=node+3;$$.top=node-3;}
|WHILE test COLON suite else_statement %prec high   { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(while)\"];%d[label=\"while_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
;

for_stmt: 
FOR exprlist IN testlist COLON suite %prec low     { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top,node+3,$6.top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"for_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,$6.top);node=node+4;$$.top=node-4;}
| FOR exprlist IN testlist COLON suite else_statement %prec high     { fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d -- %d -- %d[ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top,node+3,$6.top,$7.top);  fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"for_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,$6.top);fprintf(yyout,"%d--%d;\n",node,$7.top);node=node+4;$$.top=node-4;}
;

funcdef: 
DEF name parameters COLON suite      {fprintf(yyout,"{rank = same;%d -- %d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,$2.top,$3.top,node+2,$5.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(def)\"];%d[label=\"funcdef\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,$2.top); fprintf(yyout,"%d--%d;\n",node,$3.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
| DEF name parameters RETURN_ARROW test COLON suite   {fprintf(yyout,"{rank = same;%d -- %d -- %d -- %d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,$2.top,$3.top,node+2,$5.top,node+3,$7.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(def)\"];%d[label=\"funcdef\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,$2.top); fprintf(yyout,"%d--%d;\n",node,$3.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(->)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$5.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,$7.top);node=node+4;$$.top=node-4;}
;

parameters: LEFT_BRACKET RIGHT_BRACKET       {fprintf(yyout,"{rank = same;  %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+2);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(()\"];%d[label=\"parameters\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER())\"];\n",node,node+2,node+2);node=node+3;$$.top=node-3;}
| LEFT_BRACKET typedargslist RIGHT_BRACKET   {fprintf(yyout,"{rank = same;  %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(()\"];%d[label=\"parameters\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER())\"];\n",node,node+2,node+2);node=node+3;$$.top=node-3;}
;

typedargslist: 
typedargslist COMMA full_tfpdef {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
| full_tfpdef {fprintf(yyout,"%d--%d; %d[label=\"typedef_list\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;

full_tfpdef: 
name COLON test %prec low  {fprintf(yyout,"{rank = same;  %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.top,node+1,$3.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];%d[label=\"typedef\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,$1.top);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=2 ;$$.top=node-2;}
|NAME %prec high     {fprintf(yyout,"%d[label=\"NAME( %s )\"];\n",node,lexeme);node++;$$.top=node-1;}
;

name: NAME {fprintf(yyout,"%d[label=\"NAME( %s )\"];\n",node,lexeme);node++;$$.top=node-1;}
;

classdef: 
CLASS name opt_class_arg COLON suite    {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,$3.top,node+2,$5.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(class)\"];%d[label=\"class_def\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,$2.top); fprintf(yyout,"%d--%d;\n",node,$3.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
|CLASS name COLON suite      {fprintf(yyout,"{rank = same; %d -- %d -- %d -- %d [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2,$4.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(class)\"];%d[label=\"class_def\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);node=node+3;$$.top=node-3;}
;

opt_class_arg: 
LEFT_BRACKET RIGHT_BRACKET    {fprintf(yyout,"{rank = same;  %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+2);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER({)\"];%d[label=\"opt_class_arg\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(})\"];\n",node,node+2,node+2);node=node+3;$$.top=node-3;}
|LEFT_BRACKET opt_arglist RIGHT_BRACKET     {fprintf(yyout,"{rank = same;  %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER({)\"];%d[label=\"opt_class_arg\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(})\"];\n",node,node+2,node+2);node=node+3;$$.top=node-3;}
;

opt_arglist: 
arglist COMMA %prec high      {fprintf(yyout,"%d--%d;\n",node,$1.top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(,)\"];%d[label=\"opt_arglist\"];\n",node,node+1,node+1,node);node=node+2;$$.top=node-2;}
|arglist %prec low            {$$.top=$1.top;}
;

arglist: 
arglist COMMA argument %prec high  {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
| argument %prec low                 {fprintf(yyout,"%d--%d; %d[label=\" arglist\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;

argument: 
test          {$$.top=$1.top;}
| test comp_for        {fprintf(yyout,"%d--%d;%d[label=\"argument\"];\n",node,$1.top,node); fprintf(yyout,"%d--%d;\n",node,$2.top);node=node+1;$$.top=node-1;}
|test ASSIGNMENT_OPERATOR test    {fprintf(yyout,"%d--%d;%d[label=\"Operator(=)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
;


comp_iter: 
comp_for     {$$.top=$1.top;}
| comp_if    {$$.top=$1.top;}
;

comp_for: 
FOR exprlist IN or_test      {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"comp_for\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);node=node+3;$$.top=node-3;}
| FOR exprlist IN or_test comp_iter   {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"comp_for\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,$4.top);fprintf(yyout,"%d--%d;\n",node,$5.top);node=node+3;$$.top=node-3;}
;

comp_if: 
IF or_test           { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"comp_if\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top);node=node+2;$$.top=node-2;}
| IF or_test comp_iter    { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"comp_if\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,$2.top); fprintf(yyout,"%d--%d;\n",node,$3.top);node=node+2;$$.top=node-2;}
;

suite: 
simple_stmt {$$.top=$1.top;}
| NEWLINE INDENT stmt_list DEDENT {$$.top=$3.top;}
| NEWLINE INDENT stmt_list YYEOF {$$.top=$3.top;}
;
stmt_list : 
stmt_list stmt  {if($2.top!=-1) fprintf(yyout,"%d--%d;\n",$1.top,$2.top); $$.top=$1.top;}
| stmt {if($1.top!=-1)fprintf(yyout,"%d--%d; %d[label=\" Suite\"];\n",node,$1.top,node); fprintf(yyout,"%d[label=\" Suite\"];\n",node); node++; $$.top=node-1; }
;

test: or_test IF or_test ELSE test %prec high      {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+2,node+2,$1.top,node,$3.top,node+1,$5.top);fprintf(yyout,"%d--%d;\n",node+2,$1.top);fprintf(yyout,"%d--%d;%d[label=\"test\"];%d[label=\"Keyword(if)\"];\n",node+2,node,node+2,node);fprintf(yyout,"%d--%d;\n",node+2,$3.top);fprintf(yyout,"%d--%d;%d[label=\"test\"];%d[label=\"Keyword(else)\"];\n",node+2,node+1,node+2,node+1);fprintf(yyout,"%d--%d;\n",node+2,$5.top);node+=3; $$.top=node-1;}
|or_test %prec low     {$$.top=$1.top;}
;

or_test: or_test OR and_test %prec high   {fprintf(yyout,"%d--%d;%d[label=\"Keyword(or)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|and_test %prec low       {$$.top=$1.top;}
;

and_test: and_test AND not_test           {fprintf(yyout,"%d--%d;%d[label=\"Keyword(and)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|not_test              {$$.top=$1.top;}
;

not_test: NOT not_test        {fprintf(yyout,"%d--%d;%d[label=\"Keyword(not)\"];\n",node,$2.top,node);node+=1; $$.top=node-1;}
|comparison    {$$.top=$1.top;}
;
comparison: comparison r_o expr %prec high     {fprintf(yyout,"%d--%d;\n",$2.top,$1.top);fprintf(yyout,"%d--%d;\n",$2.top,$3.top); $$.top=$2.top;}
|expr %prec low     {$$.top=$1.top;}
;
r_o: RELATIONAL_OPERATOR   {fprintf(yyout,"%d[label=\"Operator( %s )\"];\n",node,lexeme);node++; $$.top=node-1;}
;
expr: expr BIT_OR and_expr %prec high     {fprintf(yyout,"%d--%d;%d[label=\"Operator(|)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|xor_expr  %prec low       {$$.top=$1.top;}
;
xor_expr: xor_expr XOR and_expr  %prec high  {fprintf(yyout,"%d--%d;%d[label=\"Operator(^)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|and_expr   %prec low       {$$.top=$1.top;}
;
and_expr: and_expr BIT_AND shift_expr  %prec high  {fprintf(yyout,"%d--%d;%d[label=\"Operator(&)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|shift_expr  %prec low    {$$.top=$1.top;}
;
shift_expr: shift_expr L_SHIFT arith_expr %prec high    {fprintf(yyout,"%d--%d;%d[label=\"Operator(<<)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|shift_expr R_SHIFT arith_expr %prec high    {fprintf(yyout,"%d--%d;%d[label=\"Operator(>>)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|arith_expr %prec low    {$$.top=$1.top;}
;
arith_expr: 
arith_expr ADD term %prec high        {fprintf(yyout,"%d--%d;%d[label=\"Operator(+)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|arith_expr SUB term %prec high        {fprintf(yyout,"%d--%d;%d[label=\"Operator(-)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|term %prec low  {$$.top=$1.top;}
;
term: term a_o factor %prec high      {fprintf(yyout,"%d--%d;\n",$2.top,$1.top);fprintf(yyout,"%d--%d;\n",$2.top,$3.top); $$.top=$2.top;}
|factor %prec low  {$$.top=$1.top;}
a_o: ARITHMETIC_OPERATOR   {fprintf(yyout,"%d[label=\"Operator( %s )\"];\n",node,lexeme);node++; $$.top=node-1;}
;
factor:
ADD  factor {fprintf(yyout,"%d--%d;%d[label=\"Operator(+)\"];\n",node,$2.top,node);node+=1; $$.top=node-1;}
|SUB factor {fprintf(yyout,"%d--%d;%d[label=\"Operator(-)\"];\n",node,$2.top,node);node+=1; $$.top=node-1;}
|BIT_NOT factor{fprintf(yyout,"%d--%d;%d[label=\"Operator(~)\"];\n",node,$2.top,node);node+=1; $$.top=node-1;}
|power {$$.top=$1.top;}
;
power:
atom_expr POWER factor %prec high  {fprintf(yyout,"%d--%d;%d[label=\"Operator(**)\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$3.top);node+=1; $$.top=node-1;}
|atom_expr %prec low  {$$.top=$1.top;}
;
atom_expr: 
atom opt_trailer %prec high {fprintf(yyout,"%d--%d;%d[label=\"atom_expr\"];\n",node,$1.top,node);fprintf(yyout,"%d--%d;\n",node,$2.top);node+=1; $$.top=node-1;}
|atom %prec low {$$.top=$1.top;}
;
opt_trailer:
opt_trailer trailer {fprintf(yyout,"{rank = same; %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,$2.top); fprintf(yyout,"%d--%d;\n",$1.top,$2.top); $$.top=$1.top; $$.low=$2.top;}
|trailer    {fprintf(yyout,"%d--%d; %d[label=\"trailer_list\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;
atom:
LEFT_BRACKET testlist_comp RIGHT_BRACKET           {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
|LEFT_BRACKET  RIGHT_BRACKET                       {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET         {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
|LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET     {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
|NAME       {fprintf(yyout,"%d[label=\"Name( %s )\"];\n",node,lexeme);node++; $$.top=node-1;}
|NUMBER     {fprintf(yyout,"%d[label=\"Number( %s )\"];\n",node,lexeme);node++; $$.top=node-1;}
|DATA_TYPE  {fprintf(yyout,"%d[label=\"Data Type( %s )\"];\n",node,lexeme);node++; $$.top=node-1;}
|STRING {fprintf(yyout,"%d[label=\"String(%s)\"];\n",node,lexeme);node++; $$.top=node-1;} 
|STRING_1 {fprintf(yyout,"%d[label=\"String(%s)\"];\n",node,lexeme);node++; $$.top=node-1;} 
|NONE {fprintf(yyout,"%d[label=\"Keyword(None)\"];\n",node);node++; $$.top=node-1;}
|TRUE {fprintf(yyout,"%d[label=\"Keyword(True)\"];\n",node);node++; $$.top=node-1;}
|FALSE {fprintf(yyout,"%d[label=\"Keyword(False)\"];\n",node);node++; $$.top=node-1;}
|LIST {fprintf(yyout,"%d[label=\"List \"];\n",node);node++; $$.top=node-1;}
;


testlist_comp: 
test comp_for {fprintf(yyout,"%d--%d;%d[label=\"testlist_comp\"];\n",node,$1.top,node); fprintf(yyout,"%d--%d;\n",node,$2.top);node=node+1;$$.top=node-1;}
| opt_test_stmt COMMA  {$$.top = $1.top;fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node);node++;}
| opt_test_stmt {$$.top = $1.top;}
;

opt_test_stmt: test {fprintf(yyout,"%d--%d; %d[label=\" testlist_comp\"];\n",node,$1.top,node); node++; $$.top=node-1;$$.low=$1.top;}
|opt_test_stmt COMMA test  {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
;


trailer: 
LEFT_BRACKET arglist RIGHT_BRACKET           {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
| LEFT_BRACKET RIGHT_BRACKET                 {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
| LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET    {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d -- %d  [ style=invis ];rankdir = LR;}",node+1,node+1,node,$2.top,node+2);fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; $$.top=node-2;}
| DOT name                                   {fprintf(yyout,"{rank = same; rank%d[style=invisible]; rank%d -- %d -- %d   [ style=invis ];rankdir = LR;}",node+1,node+1,node,$2.top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(.)\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,$2.top);node+=2; $$.top=node-1;}
;

testlist: 
testlist COMMA test {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
| test {fprintf(yyout,"%d--%d; %d[label=\" testlist\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;

exprlist: 
exprlist COMMA expr {fprintf(yyout,"{rank = same; %d -- %d -- %d  [ style=invis ];rankdir = LR;}",$1.low,node,$3.top);fprintf(yyout,"%d--%d; %d[label=\" Delimiter(,)\"];\n",$1.top,node,node); fprintf(yyout,"%d--%d;\n",$1.top,$3.top); node++; $$.top=$1.top; $$.low=$3.top;}
| expr {fprintf(yyout,"%d--%d; %d[label=\" exprlist\"];\n",node,$1.top,node); node++; $$.top=node-1; $$.low=$1.top;}
;

%%
const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   cout<<"Error in Line no "<<yylineno<<endl;
   cout<< "The Last Lexeme is "<<lexeme<<endl;
   cout<< "The Last Token is "<<token_name(yychar)<<endl;
   return ;
}

int main ( int argc, char *argv[]){

   if(argc==5){ 
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   fprintf(yyout,"Graph { \n");
   yydebug=0;
   yyparse();
   fprintf(yyout,"}");
   fclose(yyin);
   fclose(yyout);
   }else if(argc==2){
     cout<<" Use ./ast -input input_file -output output_file for proper execution\n";
   }else{
     cout<<" Use ./ast -help\n";
   }
   
   return 0;
}