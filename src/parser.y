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
map<string,int>table;
extern stack<string>current_attributes;

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
module : module stmt%prec high 
|stmt 
;

stmt: 
NEWLINE 
| simple_stmt
| compound_stmt 
| testlist 
;

simple_stmt: more_expr %prec low 
| more_expr SEMICOLON %prec high 
;
more_expr:
more_expr SEMICOLON small_stmt 
|small_stmt 
;


small_stmt: 
expr_stmt      
|break_stmt    
|continue_stmt 
|return_stmt   
;

expr_stmt: 
testlist annassign {
                    string entry="";
                    char a=(char)('a'+node);
                    entry+=a;
                    table[entry]=node;
                    current_attributes.push(entry);
                    cout<<"push "<<entry<<endl;
                    node++;
                   }
|testlist AUGASSIGNMENT_OPERATOR testlist 
|testlist Assign_stmt   
;
Assign_stmt:  
Assign_stmt ASSIGNMENT_OPERATOR testlist 
| ASSIGNMENT_OPERATOR testlist
;
annassign:
COLON test param_list %prec high  
|COLON test %prec low  
;

param_list:
ASSIGNMENT_OPERATOR test  

break_stmt: 
BREAK  
;
continue_stmt: 
CONTINUE  
;
return_stmt: 
RETURN %prec low 
| RETURN test %prec high  
;



compound_stmt: 
if_stmt        
|while_stmt    
|for_stmt      
|funcdef       
|classdef      
;
if_stmt: 
IF test COLON suite        
|IF test COLON suite else_statement  
|IF test COLON suite elif_statements 
|IF test COLON suite elif_statements else_statement
;
elif_statements: 
elif_statements ELIF test COLON suite  
|ELIF test COLON suite  
;
else_statement: 
ELSE COLON suite  
;

while_stmt: 
WHILE test COLON suite %prec low  
|WHILE test COLON suite else_statement %prec high
;

for_stmt: 
FOR exprlist IN testlist COLON suite %prec low  
| FOR exprlist IN testlist COLON suite else_statement %prec high
;

funcdef: 
DEF name parameters COLON suite  
| DEF name parameters RETURN_ARROW test COLON suite  
;

parameters: LEFT_BRACKET RIGHT_BRACKET     
| LEFT_BRACKET typedargslist RIGHT_BRACKET  
;

typedargslist: 
typedargslist COMMA full_tfpdef 
| full_tfpdef 
;

full_tfpdef: 
name COLON test %prec low  
|NAME %prec high  
;

name: NAME 
;

classdef: 
CLASS name opt_class_arg COLON suite   
|CLASS name COLON suite   
;

opt_class_arg: 
LEFT_BRACKET RIGHT_BRACKET  
|LEFT_BRACKET opt_arglist RIGHT_BRACKET  
;

opt_arglist: 
arglist COMMA %prec high   
|arglist %prec low            
;

arglist: 
arglist COMMA argument %prec high 
| argument %prec low  
;

argument: 
test          
| test comp_for   
|test ASSIGNMENT_OPERATOR test  
;


comp_iter: 
comp_for     
| comp_if    
;

comp_for: 
FOR exprlist IN or_test   
| FOR exprlist IN or_test comp_iter  
;

comp_if: 
IF or_test        
| IF or_test comp_iter  
;

suite: 
simple_stmt 
| NEWLINE INDENT stmt_list DEDENT   {
                                        while(current_attributes.top()!="INDENT"){
                                            cout<<"pop "<<current_attributes.top()<<endl;
                                            table.erase(current_attributes.top());
                                            current_attributes.pop();
                                        }
                                        cout<<"pop "<<current_attributes.top()<<endl;
                                        current_attributes.pop();
                                    }
| NEWLINE INDENT stmt_list YYEOF 
;
stmt_list : 
stmt_list stmt  
| stmt 
;

test: or_test IF or_test ELSE test %prec high  
|or_test %prec low     
;

or_test: or_test OR and_test %prec high  
|and_test %prec low       
;

and_test: and_test AND not_test   
|not_test              
;

not_test: NOT not_test    
|comparison    
;
comparison: comparison r_o expr %prec high   
|expr %prec low     
;
r_o: RELATIONAL_OPERATOR 
;
expr: expr BIT_OR and_expr %prec high    
|xor_expr  %prec low       
;
xor_expr: xor_expr XOR and_expr  %prec high 
|and_expr   %prec low       
;
and_expr: and_expr BIT_AND shift_expr  %prec high 
|shift_expr  %prec low    
;
shift_expr: shift_expr L_SHIFT arith_expr %prec high  
|shift_expr R_SHIFT arith_expr %prec high   
|arith_expr %prec low    
;
arith_expr: 
arith_expr ADD term %prec high    
|arith_expr SUB term %prec high   
|term %prec low  
;
term: term a_o factor %prec high   
|factor %prec low  

a_o: ARITHMETIC_OPERATOR  
;
factor:
ADD  factor 
|SUB factor 
|BIT_NOT factor
|power 
;
power:
atom_expr POWER factor %prec high 
|atom_expr %prec low  
;
atom_expr: 
atom opt_trailer %prec high 
|atom %prec low 
;
opt_trailer:
opt_trailer trailer 
|trailer   
;
atom:
LEFT_BRACKET testlist_comp RIGHT_BRACKET   
|LEFT_BRACKET  RIGHT_BRACKET                 
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET     
|LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET   
|NAME      
|NUMBER   
|DATA_TYPE  
|STRING 
|STRING_1 
|NONE 
|TRUE 
|FALSE 
|LIST 
;


testlist_comp: 
test comp_for 
| opt_test_stmt COMMA  
| opt_test_stmt 
;

opt_test_stmt: test 
|opt_test_stmt COMMA test  
;


trailer: 
LEFT_BRACKET arglist RIGHT_BRACKET     
| LEFT_BRACKET RIGHT_BRACKET           
| LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  
| DOT name 
;

testlist: 
testlist COMMA test 
| test 
;

exprlist: 
exprlist COMMA expr 
| expr 
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