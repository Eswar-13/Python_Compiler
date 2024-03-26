%{
#include <bits/stdc++.h>
using namespace std;

#define YYDEBUG 1

extern int yydebug;
extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern FILE* yyin;  
extern FILE* yyout;
extern int yychar;
extern char * yytext;

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

vector<string>code;

map<string,int>table;
extern stack<string>current_attributes;

void pop_functional_attributes(){
    while(current_attributes.top()!="INDENT"){
        cout<<"pop "<<current_attributes.top()<<endl;
        table.erase(current_attributes.top());
        current_attributes.pop();
    }
    //cout<<"pop "<<current_attributes.top()<<endl;
    current_attributes.pop();
}

string convert( string in){
    string out = in;
    return out;
}

void fill(int l,int c){
    int t=code.size()-1;
    while(c){
       if(code[t].compare("jump line ")==0){
        code[t]=code[t]+to_string(l);
        c--;
       }else t--;
    }
    return ;
}
%}

%union{
   struct{
     int top;
     char * reg;
     int type;
     int jump;
     char* lexeme;
   }attributes;
}

%token<attributes> ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token<attributes> SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token<attributes> LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token<attributes> IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD SUB POWER BIT_AND BIT_OR
%token<attributes> NUMBER STRING DOT L_SHIFT R_SHIFT STRING_1
%token<attributes> LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET INVALID

%type<attributes>  module stmt simple_stmt compound_stmt testlist expr more_expr small_stmt expr_stmt break_stmt continue_stmt return_stmt annassign Assign_stmt test if_stmt if_test elif_test while_stmt for_stmt funcdef classdef suite else_statement elif_statements exprlist parameters typedargslist full_tfpdef opt_class_arg opt_arglist arglist argument comp_for comp_if comp_iter comparison stmt_list or_test and_test not_test xor_expr and_expr shift_expr arith_expr term factor power atom_expr atom opt_trailer trailer testlist_comp opt_test_stmt  
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
name annassign  {
                    table[$1.lexeme]=node;
                    current_attributes.push($1.lexeme);
                    cout<<"push "<<$1.lexeme<<endl;
                    node++;
                }
|testlist AUGASSIGNMENT_OPERATOR testlist 
|Assign_stmt   
;

Assign_stmt:  
name ASSIGNMENT_OPERATOR Assign_stmt {string c=convert($1.reg); c=c+"="+convert($3.reg); code.push_back(c);  $$.reg=$3.reg;}
|name ASSIGNMENT_OPERATOR testlist {string c=convert($1.reg); c=c+"="+convert($3.reg); code.push_back(c);  $$.reg=$3.reg;}
;

name: NAME {$$.lexeme=$1.lexeme; string c=convert($1.lexeme); $$.reg=new char[c.size()]; strcpy($$.reg, c.c_str()); }
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
if_test  {fill(code.size()+1,1);}
|if_test  else_statement  {fill(code.size()+1,1);}
|if_test  elif_statements else_statement {fill(code.size()+1,$2.jump+1);}
|if_test  elif_statements {fill(code.size()+1,$2.jump+1);}
;

if_test:
IF test {$1.jump=code.size()+1; string c="if "+convert($2.reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);} COLON suite {string c=code[$1.jump]; c=c+to_string(code.size()+2); code[$1.jump]=c; c="jump line "; code.push_back(c);}

elif_statements: 
elif_statements elif_test {$$.jump=$1.jump+1;}
|elif_test  {$$.jump=1;}
;

elif_test:
ELIF test {$1.jump=code.size()+1; string c="if "+convert($2.reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);} COLON suite {string c=code[$1.jump]; c=c+to_string(code.size()+2); code[$1.jump]=c; c="jump line "; code.push_back(c);}

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
                                        pop_functional_attributes();
                                    }
| NEWLINE INDENT stmt_list YYEOF {pop_functional_attributes();}
;
stmt_list : 
stmt_list stmt  
| stmt 
;

test: or_test %prec low  {$$.reg=$1.reg;}    
;

or_test: or_test OR and_test %prec high {string c=convert($1.reg); c=c+"="+c+"or"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;}   
|and_test %prec low {$$.reg=$1.reg;}       
;

and_test: and_test AND not_test   {string c=convert($1.reg); c=c+"="+c+"and"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;}  
|not_test {$$.reg=$1.reg;}              
;

not_test: NOT not_test  {string c=convert($2.reg); c=c+"=""not"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;}
|comparison  {$$.reg=$1.reg;} 
;

comparison: comparison r_o expr %prec high  {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;} 
|expr %prec low  {$$.reg=$1.reg;}   
;

r_o: RELATIONAL_OPERATOR {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); }
;

expr: expr BIT_OR xor_expr %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"|"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|xor_expr  %prec low   {$$.reg=$1.reg;}     
;

xor_expr: xor_expr XOR and_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"^"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|and_expr   %prec low    {$$.reg=$1.reg;}    
;

and_expr: and_expr BIT_AND shift_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"&"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|shift_expr  %prec low     {$$.reg=$1.reg;}
;

shift_expr: shift_expr L_SHIFT arith_expr %prec high  {string c=convert($1.reg); c=c+"="+convert($1.reg)+"<<"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|shift_expr R_SHIFT arith_expr %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+">>"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|arith_expr %prec low    {$$.reg=$1.reg;}
;

arith_expr: 
arith_expr ADD term %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"+"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|arith_expr SUB term %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+"-"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|term %prec low   {$$.reg=$1.reg;}
;

term: term a_o factor %prec high   {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;}
|factor %prec low  {$$.reg=$1.reg;}

a_o: ARITHMETIC_OPERATOR  {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); }
;

factor:
ADD  factor {string c=convert($2.reg); c=c+"=""+"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;}
|SUB factor {string c=convert($2.reg); c=c+"=""-"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;}
|BIT_NOT factor {string c=convert($2.reg); c=c+"=""~"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;}
|power {$$.reg=$1.reg;}
;

power:
atom_expr POWER factor %prec high {string c=convert($1.reg); c=c+"="+c+"**"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;}
|atom_expr %prec low  {$$.reg=$1.reg;}
;

atom_expr: 
atom opt_trailer %prec high 
|atom %prec low {$$.reg=$1.reg;}
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
|NAME   {string c="r"+to_string(node); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c);  node++;}
|NUMBER   {string c="r"+to_string(node); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c);  node++;}
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
   cout<< "The Last Lexeme is "<<yytext<<endl;
   cout<< "The Last Token is "<<token_name(yychar)<<endl;
   return ;
}

int main ( int argc, char *argv[]){
   
   if(argc==5){ 
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   yydebug=0;
   yyparse();
   for(auto x:code){
    fprintf(yyout,"%s\n",x.data());
   }
   fclose(yyin);
   fclose(yyout);
   }else if(argc==2){
     cout<<" Use ./ast -input input_file -output output_file for proper execution\n";
   }else{
     cout<<" Use ./ast -help\n";
   }
   
   return 0;
}