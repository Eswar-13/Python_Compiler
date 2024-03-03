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
extern int yychar;

int node=0;
map<string,int>m;

%}

%union{
   struct{
      int top;
   }attributes;
}

%token<attributes> ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token<attributes> SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token<attributes> LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token<attributes> IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD SUB POWER BIT_AND BIT_OR
%token<attributes> NUMBER STRING DOT SHIFT
%token<attributes> LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET

%type<attributes>  module stmt simple_stmt compound_stmt testlist expr more_expr small_stmt expr_stmt break_stmt continue_stmt return_stmt annassign Assign_stmt test if_stmt while_stmt for_stmt funcdef classdef suite else_statement elif_statements exprlist parameters typedargslist full_tfpdef opt_class_arg opt_arglist arglist argument comp_for comp_if comp_iter comparison stmt_list or_test and_test not_test xor_expr and_expr shift_expr arith_expr term factor power atom_expr atom opt_trailer trailer testlist_comp opt_test_stmt  

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
%precedence NEWLINE SEMICOLON COLON ASSIGNMENT_OPERATOR AUGASSIGNMENT_OPERATOR ADD SUB AND ARITHMETIC_OPERATOR BIT_AND BIT_NOT BIT_OR BITWISE_OPERATOR BREAK LEFT_BRACKET RIGHT_BRACKET LEFT_CURLY_BRACKET LEFT_SQUARE_BRACKET RIGHT_CURLY_BRACKET RIGHT_SQUARE_BRACKET CLASS COMMA CONTINUE DATA_TYPE DEDENT DEF DOT ELIF ELSE FALSE FOR IF IN INDENT LIST NAME NONE NOT NUMBER OR POWER RELATIONAL_OPERATOR RETURN RETURN_ARROW SHIFT STRING TRUE WHILE XOR YYEOF 


%% 
module : stmt module %prec high {fprintf(yyout,"module--%d;\n",$1.top);}
|stmt {fprintf(yyout,"module--%d;\n",$1.top);}
;

stmt: NEWLINE { fprintf(yyout,"stmt%d--NEWLINE%d;\n",m["stmt"],m["NEWLINE"]); m["NEWLINE"]++;}
| simple_stmt {$$.top=$1.top;}
| compound_stmt {fprintf(yyout,"stmt%d--compound_stmt%d;\n",m["stmt"],m["compound_stmt"]); m["compound_stmt"]++; } 
| testlist {fprintf(yyout,"stmt%d--testlist%d;\n",m["stmt"],m["testlist"]); m["testlist"]++; }
;

simple_stmt: more_expr %prec low {$$.top=$1.top;}
| more_expr SEMICOLON %prec high
;
more_expr:
more_expr SEMICOLON small_stmt 
|small_stmt {$$.top=$1.top;}
;

small_stmt: 
expr_stmt      {$$.top=$1.top;}
|break_stmt    {fprintf(yyout,"simple_stmt%d--break_stmt%d;\n",m["simple_stmt"],m["break_stmt"]); m["break_stmt"]++; }
|continue_stmt             {fprintf(yyout,"simple_stmt%d--continue_stmt%d;\n",m["simple_stmt"],m["expr_stmt"]); m["continue_stmt"]++; }
|return_stmt               {fprintf(yyout,"simple_stmt%d--return_stmt%d;\n",m["simple_stmt"],m["return_stmt"]); m["return_stmt"]++; }
;

expr_stmt: 
testlist annassign     {fprintf(yyout,"right_assign%d--annassign%d;\n",m["right_assign"],m["annassign"]); m["annassign"]++; }
|testlist AUGASSIGNMENT_OPERATOR testlist   {fprintf(yyout,"right_assign%d--AUGASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["AUGASSIGNMENT_OPERATOR"]); m["AUGASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
|testlist Assign_stmt   {$$.top=$2.top; fprintf(yyout,"%d--%d;\n",$2.top,$1.top);}
;
Assign_stmt:  
Assign_stmt ASSIGNMENT_OPERATOR testlist  {fprintf(yyout,"right_assign%d--ASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
| ASSIGNMENT_OPERATOR testlist   {fprintf(yyout,"%d--%d; %d[label=\"Operator (=)\"];\n",node,$2.top,node); node++; $$.top=node-1;}
;
annassign:
COLON test ASSIGNMENT_OPERATOR test %prec high     {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;fprintf(yyout,"annassign%d--ASSIGNMENT_OPERATOR%d;\n",m["annassign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++; fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;}
|COLON test %prec low      {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); }
;

break_stmt: 
BREAK  {fprintf(yyout,"break_stmt%d--BREAK%d;\n",m["break_stmt"],m["BREAK"]); m["BREAK"]++; }
;
continue_stmt: 
CONTINUE    {fprintf(yyout,"continue_stmt%d--CONTINUE%d;\n",m["continue_stmt"],m["CONTINUE"]); m["CONTINUE"]++; }
;
return_stmt: 
RETURN %prec low   {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; }
| RETURN test %prec high   {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; fprintf(yyout,"return_stmt%d--test%d;\n",m["return_stmt"],m["test"]); m["test"]++; }
;




compound_stmt: 
if_stmt        {fprintf(yyout,"compound_stmt%d--if_stmt%d;\n",m["compound_stmt"],m["if_stmt"]); m["if_stmt"]++;}
|while_stmt    {fprintf(yyout,"compound_stmt%d--while_stmt%d;\n",m["compound_stmt"],m["while_stmt"]); m["while_stmt"]++;}
|for_stmt      {fprintf(yyout,"compound_stmt%d--for_stmt%d;\n",m["compound_stmt"],m["for_stmt"]); m["for_stmt"]++;}
|funcdef       {fprintf(yyout,"compound_stmt%d--funcdef%d;\n",m["compound_stmt"],m["funcdef"]); m["funcdef"]++;}
|classdef      {fprintf(yyout,"compound_stmt%d--classdef%d;\n",m["compound_stmt"],m["classdef"]); m["classdef"]++;}
;
if_stmt: 
IF test COLON suite        { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;}
|IF test COLON suite else_statement   { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
|IF test COLON suite elif_statements   { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;}
|IF test COLON suite elif_statements else_statement   { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
;
elif_statements: 
elif_statements ELIF test COLON suite   { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
| ELIF test COLON suite                  { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
;
else_statement: 
ELSE COLON suite       { fprintf(yyout,"else_statement%d--ELSE%d;\n",m["else_statement"],m["ELSE"]); m["ELSE"]++; fprintf(yyout,"else_statement%d--COLON%d;\n",m["else_statement"],m["COLON"]); m["COLON"]++; fprintf(yyout,"else_statement%d--suite%d;\n",m["else_statement"],m["suite"]); m["suite"]++;}
;

while_stmt: 
WHILE test COLON suite %prec low    { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;}
|WHILE test COLON suite else_statement %prec high  { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"while_stmt%d--else_statement%d;\n",m["while_stmt"],m["else_statement"]);}
;

for_stmt: 
FOR exprlist IN testlist COLON suite %prec low    { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;}
| FOR exprlist IN testlist COLON suite else_statement %prec high     { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"for_stmt%d--else_statement%d;\n",m["for_stmt"],m["else_statement"]); m["else_statement"]++;}
;

funcdef: DEF NAME parameters COLON suite     { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
| DEF NAME parameters RETURN_ARROW test COLON suite   { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++;fprintf(yyout,"funcdef%d--RETURN_ARROW%d;\n",m["funcdef"],m["RETURN_ARROW"]); m["RETURN_ARROW"]++;fprintf(yyout,"funcdef%d--test%d;\n",m["funcdef"],m["test"]); m["test"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
;

parameters: LEFT_BRACKET RIGHT_BRACKET       {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
| LEFT_BRACKET typedargslist RIGHT_BRACKET   {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--typedargslist%d;\n",m["parameters"],m["typedargslist"]); m["typedargslist"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
;

typedargslist: 
typedargslist COMMA {fprintf(yyout,"typedargslist%d--COMMA%d;\n",m["typedargslist"],m["COMMA"]); m["COMMA"]++;}
full_tfpdef 
| full_tfpdef 
;

full_tfpdef: 
NAME annassign %prec high  {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;fprintf(yyout,"typedargslist%d--annassign%d;\n",m["typedargslist"],m["annassign"]); m["annassign"]++;}
|NAME %prec low     {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;}
;
classdef: 
CLASS NAME opt_class_arg COLON suite     { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--opt_class_arg%d;\n",m["classdef"],m["opt_class_arg"]); m["opt_class_arg"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
|CLASS NAME COLON suite       { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
;
opt_class_arg: 
LEFT_BRACKET RIGHT_BRACKET    {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
|LEFT_BRACKET opt_arglist RIGHT_BRACKET      {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--opt_arglist%d;\n",m["opt_class_arg"],m["opt_arglist"]); m["opt_arglist"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
;
opt_arglist: 
arglist COMMA %prec high       {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;fprintf(yyout,"opt_arglist%d--COMMA%d;\n",m["opt_arglist"],m["COMMA"]); m["COMMA"]++;}
|arglist %prec low            {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;}
;
arglist: 
arglist COMMA argument %prec high   {fprintf(yyout,"arglist%d--COMMA%d;\n",m["arglist"],m["COMMA"]); m["COMMA"]++;fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
| argument %prec low                         {fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
;
argument: 
test          {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
| test comp_for         {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--comp_for%d;\n",m["argument"],m["comp_for"]); m["comp_for"]++;}
|test ASSIGNMENT_OPERATOR test      {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--ASSIGNMENT_OPERATOR%d;\n",m["argument"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
;
comp_iter: 
comp_for     {fprintf(yyout,"comp_iter%d--comp_for%d;\n",m["comp_iter"],m["comp_for"]); m["comp_for"]++;}
| comp_if               {fprintf(yyout,"comp_iter%d--comp_if%d;\n",m["comp_iter"],m["comp_if"]); m["comp_if"]++;}
;
comp_for: 
FOR exprlist IN or_test      { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; }
| FOR exprlist IN or_test comp_iter    { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_for%d--comp_iter%d;\n",m["comp_for"],m["comp_iter"]); m["comp_iter"]++;}
;
comp_if: 
IF or_test           { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; }
| IF or_test comp_iter        { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_if%d--comp_iter%d;\n",m["comp_if"],m["comp_iter"]); m["comp_iter"]++;}
;


suite: 
simple_stmt 
| NEWLINE INDENT stmt_list DEDENT { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--DEDENT%d;\n",m["suite"],m["DEDENT"]); m["DEDENT"]++;}
| NEWLINE INDENT stmt_list YYEOF { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--YYEOF%d;\n",m["suite"],m["YYEOF"]); m["YYEOF"]++;}
;
stmt_list : 
stmt_list stmt  {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
| stmt {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
;

test: or_test IF or_test ELSE test %prec high      {fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--IF%d;\n",m["test"],m["IF"]); m["IF"]++;fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--ELSE%d;\n",m["test"],m["ELSE"]); m["ELSE"]++;}
|or_test %prec low     {$$.top=$1.top;}
;

or_test: or_test OR and_test %prec high   {fprintf(yyout,"test%d--OR%d;\n",m["test"],m["OR"]); fprintf(yyout,"OR%d--and_test%d;\n",m["OR"],m["and_test"]);m["OR"]++; m["and_test"]++;}
|and_test %prec low       {$$.top=$1.top;}
;

and_test: and_test AND not_test           {fprintf(yyout,"and_test%d--AND%d;\n",m["and_test"],m["AND"]); m["AND"]++;fprintf(yyout,"and_test%d--not_test%d;\n",m["and_test"],m["not_test"]); m["not_test"]++;}
|not_test              {$$.top=$1.top;}
;

not_test: NOT {fprintf(yyout,"not_test%d--NOT%d;\n",m["not_test"],m["NOT"]); m["NOT"]++;}
   not_test  
|comparison    {$$.top=$1.top;}
;
comparison: comparison RELATIONAL_OPERATOR expr %prec high     {fprintf(yyout,"comparison%d--RELATIONAL_OPERATOR%d;\n",m["comparison"],m["RELATIONAL_OPERATOR"]); m["RELATIONAL_OPERATOR"]++;fprintf(yyout,"comparison%d--expr%d;\n",m["comparison"],m["expr"]); m["expr"]++;}
|expr %prec low     {$$.top=$1.top;}
;
expr: expr BIT_OR and_expr %prec high     {fprintf(yyout,"expr%d--BIT_OR%d;\n",m["expr"],m["BIT_OR"]); m["BIT_OR"]++;fprintf(yyout,"expr%d--xor_expr%d;\n",m["expr"],m["xor_expr"]); m["xor_expr"]++;}
|xor_expr  %prec low       {$$.top=$1.top;}
;
xor_expr: xor_expr XOR and_expr  %prec high  {fprintf(yyout,"xor_expr%d--XOR%d;\n",m["xor_expr"],m["XOR"]); m["XOR"]++;fprintf(yyout,"xor_expr%d--and_expr%d;\n",m["xor_expr"],m["and_expr"]); m["and_expr"]++;}
|and_expr   %prec low       {$$.top=$1.top;}
;
and_expr: and_expr BIT_AND shift_expr  %prec high  {fprintf(yyout,"and_expr%d--BIT_AND%d;\n",m["and_expr"],m["BIT_AND"]); m["BIT_AND"]++;fprintf(yyout,"and_expr%d--shift_expr%d;\n",m["and_expr"],m["shift_expr"]); m["shift_expr"]++;}
|shift_expr  %prec low    {$$.top=$1.top;}
;
shift_expr: shift_expr SHIFT arith_expr %prec high    {fprintf(yyout,"shift_expr%d--SHIFT%d;\n",m["shift_expr"],m["SHIFT"]); m["SHIFT"]++;fprintf(yyout,"shift_expr%d--arith_expr%d;\n",m["shift_expr"],m["arith_expr"]); m["arith_expr"]++;}
|arith_expr %prec low    {$$.top=$1.top;}
;
arith_expr: 
arith_expr ADD term %prec high        {fprintf(yyout,"arith_expr%d--ADD%d;\n",m["arith_expr"],m["ADD"]); m["ADD"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
|arith_expr SUB term %prec high        {fprintf(yyout,"arith_expr%d--SUB%d;\n",m["arith_expr"],m["SUB"]); m["SUB"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
|term %prec low  {$$.top=$1.top;}
;
term: term ARITHMETIC_OPERATOR factor %prec high      {fprintf(yyout,"term%d--ARITHMETIC_OPERATOR%d;\n",m["term"],m["ARITHMETIC_OPERATOR"]); m["ARITHMETIC_OPERATOR"]++;fprintf(yyout,"term%d--factor%d;\n",m["term"],m["factor"]); m["factor"]++;}
|factor %prec low  {$$.top=$1.top;}

factor:
ADD  factor {fprintf(yyout,"factor%d--ADD%d;\n",m["factor"],m["ADD"]); m["ADD"]++;}
|SUB factor {fprintf(yyout,"factor%d--SUB%d;\n",m["factor"],m["SUB"]); m["SUB"]++;} 
|BIT_NOT factor{fprintf(yyout,"factor%d--BIT_NOT%d;\n",m["factor"],m["BIT_NOT"]); m["BIT_NOT"]++;} 
|power {$$.top=$1.top;}
;
power:
atom_expr POWER factor %prec high  {fprintf(yyout,"power%d--atom_expr%d;\n",m["power"],m["atom_expr"]); m["atom_expr"]++;fprintf(yyout,"power%d--POWER%d;\n",m["power"],m["POWER"]); m["POWER"]++;fprintf(yyout,"power%d--factor%d;\n",m["power"],m["factor"]); m["factor"]++;}
|atom_expr %prec low  {$$.top=$1.top;}
;
atom_expr: atom opt_trailer %prec high {fprintf(yyout,"atom_expr%d--atom%d;\n",m["atom_expr"],m["atom"]); m["atom"]++; fprintf(yyout,"atom_expr%d--opt_trailer%d;\n",m["atom_expr"],m["opt_trailer"]); m["opt_trailer"]++;}
|atom %prec low {$$.top=$1.top;}
;
opt_trailer:
opt_trailer trailer {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
|trailer {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
;
;
atom:
LEFT_BRACKET testlist_comp RIGHT_BRACKET {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
|LEFT_BRACKET  RIGHT_BRACKET {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
|LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
|NAME {fprintf(yyout,"%d[label=\"Name( %s )\"];\n",node,yytext);node++; $$.top=node-1;}
|NUMBER {fprintf(yyout,"atom%d--NUMBER%d;\n",m["atom"],m["NUMBER"]); m["NUMBER"]++;}
|DATA_TYPE {fprintf(yyout,"atom%d--DATA_TYPE%d;\n",m["atom"],m["DATA_TYPE"]); m["DATA_TYPE"]++;}
|STRING {fprintf(yyout,"atom%d--STRING%d;\n",m["atom"],m["STRING"]); m["STRING"]++;}
|NONE {fprintf(yyout,"atom%d--NONE%d;\n",m["atom"],m["NONE"]); m["NONE"]++;}
|TRUE {fprintf(yyout,"atom%d--TRUE%d;\n",m["atom"],m["TRUE"]); m["TRUE"]++;}
|FALSE {fprintf(yyout,"atom%d--FALSE%d;\n",m["atom"],m["FALSE"]); m["FALSE"]++;}
|LIST {fprintf(yyout,"atom%d--LIST%d;\n",m["atom"],m["LIST"]); m["LIST"]++;}
;

testlist_comp: 
test comp_for {fprintf(yyout,"testlist_comp%d--test%d;\n",m["testlist_comp"],m["test"]); m["test"]++; fprintf(yyout,"testlist_comp%d--comp_for%d;\n",m["testlist_comp"],m["comp_for"]); m["comp_for"]++; }
| opt_test_stmt COMMA {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++; fprintf(yyout,"testlist_comp%d--COMMA%d;\n",m["testlist_comp"],m["COMMA"]); m["COMMA"]++; }
| opt_test_stmt {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++;}
;
opt_test_stmt: test {fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;}
|opt_test_stmt COMMA test {fprintf(yyout,"opt_test_stmt%d--COMMA%d;\n",m["opt_test_stmt"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;} 
;

trailer: 
LEFT_BRACKET arglist RIGHT_BRACKET {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--arglist%d;\n",m["trailer"],m["arglist"]); m["arglist"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
| LEFT_BRACKET RIGHT_BRACKET {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
| LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET {fprintf(yyout,"trailer%d--LEFT_SQUARE_BRACKET%d;\n",m["trailer"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"trailer%d--test%d;\n",m["trailer"],m["test"]); m["test"]++; fprintf(yyout,"trailer%d--RIGHT_SQUARE_BRACKET%d;\n",m["trailer"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
| DOT NAME {fprintf(yyout,"trailer%d--DOT%d;\n",m["trailer"],m["DOT"]); m["DOT"]++; fprintf(yyout,"trailer%d--NAME%d;\n",m["trailer"],m["NAME"]); m["NAME"]++;}


testlist: 
testlist COMMA test {fprintf(yyout,"testlist%d--COMMA%d;\n",m["testlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"testlist%d--test%d;\n",m["testlist"],m["test"]); m["test"]++;} 
| test {$$.top=$1.top;}
;

exprlist: 
exprlist COMMA expr {fprintf(yyout,"exprlist%d--COMMA%d;\n",m["exprlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;} 
| expr {fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;}
;

%%
const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   cout<<"Error in Line no "<<yylineno<<endl;
   cout<< "The Last Lexem is "<<yytext<<endl;
   cout<< "The Last Token is "<<token_name(yychar)<<endl;
   return ;
}

int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   fprintf(yyout,"Graph {\n");
   yydebug=0;
   yyparse();
   fprintf(yyout,"}");
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}