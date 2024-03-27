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
class content{
    public:
        int type;
        content(){}
        content(int type) : type(type) {}
};
int typedetector(string s){
    if(s=="int")return 1;
    if(s=="float")return 2;
    if(s=="bool")return 3;
    if(s=="str")return 4;
    if(s=="class")return 5;
    return 0;
}
int typelist(string s){
    int a=0;
    string t="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='[')a=1;
        else if(s[i]==']')a=0;
        else if(a&&s[i]!=' ')t+=s[i];
    }
    return typedetector(t);
}
int check_type(int type1, int type2){
    if(type1==type2)return type1;
    else if(type1==1&&type2==3||type1==3&&type2==1)return type1;
    else if(type1==1&&type2==2||type1==2&&type2==1)return type2;
    else {
        yyerror("type");
        return 0;
    }
}
vector<string>code;

map<string,content>table;
extern stack<string>current_attributes;
int current_func_type;
bool check(string s){
    if(table.find(s)==table.end()){yyerror("dec");return 1;}
    else return 0;
}
void update_table(string key,int type){
    table[key]=content(type);
    current_attributes.push(key);
    cout<<"push "<<key<<endl;
}
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
%token<attributes> INT FLOAT STRING DOT L_SHIFT R_SHIFT STRING_1
%token<attributes> LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET INVALID

%type<attributes>  module stmt simple_stmt compound_stmt testlist expr more_expr small_stmt expr_stmt break_stmt continue_stmt return_stmt annassign Assign_stmt test if_stmt if_test elif_test while_stmt while_test for_stmt funcdef classdef suite else_statement elif_statements parameters typedargslist full_tfpdef opt_class_arg opt_arglist arglist argument comparison stmt_list or_test and_test not_test xor_expr and_expr shift_expr arith_expr term factor power atom_expr atom opt_trailer trailer 
%type<attributes>  a_o r_o param_list name data_type
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
%precedence NEWLINE SEMICOLON STRING_1 COLON ASSIGNMENT_OPERATOR AUGASSIGNMENT_OPERATOR ADD SUB AND ARITHMETIC_OPERATOR BIT_AND BIT_NOT BIT_OR BITWISE_OPERATOR BREAK LEFT_BRACKET RIGHT_BRACKET LEFT_CURLY_BRACKET LEFT_SQUARE_BRACKET RIGHT_CURLY_BRACKET RIGHT_SQUARE_BRACKET CLASS COMMA CONTINUE DATA_TYPE DEDENT DEF DOT ELIF ELSE FALSE FOR IF IN INDENT LIST NAME NONE NOT INT FLOAT OR POWER RELATIONAL_OPERATOR RETURN RETURN_ARROW SHIFT STRING TRUE WHILE XOR YYEOF 

%% 
module : module stmt %prec high 
|stmt %prec low
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
more_expr SEMICOLON small_stmt %prec high 
|small_stmt %prec low
;

small_stmt: 
expr_stmt      
|break_stmt    
|continue_stmt 
|return_stmt   
;

expr_stmt: 
name annassign  {string c=convert($1.lexeme); c=c+"="+convert($2.reg); code.push_back(c); update_table($1.lexeme,$2.type);}
|test AUGASSIGNMENT_OPERATOR test {if(!check_type($1.type,$3.type))return 0;}
|Assign_stmt   
;

Assign_stmt:  
test ASSIGNMENT_OPERATOR Assign_stmt {string c=convert($1.lexeme); c=c+"="+convert($3.reg); code.push_back(c);  $$.reg=$3.reg;if(!check_type($1.type,$3.type))return 0;$$.type=$1.type;}
|test ASSIGNMENT_OPERATOR test {string c=convert($1.lexeme); c=c+"="+convert($3.reg); code.push_back(c);  $$.reg=$3.reg;if(!check_type($1.type,$3.type))return 0;$$.type=$1.type;}
;

name: NAME {$$.lexeme=$1.lexeme; string c=convert($1.lexeme); $$.reg=new char[c.size()]; strcpy($$.reg, c.c_str());}
;

annassign:
COLON data_type param_list %prec high  {$$.reg=$3.reg; $$.type=$2.type;if(!check_type($2.type,$3.type))return 0;}
|COLON data_type %prec low  {$$.type=$2.type;}
;
data_type: DATA_TYPE {$$.type=typedetector($1.lexeme);}
|LIST {$$.type=typelist($1.lexeme);}
;
param_list:
ASSIGNMENT_OPERATOR test  {$$.reg=$2.reg; $$.type=$2.type;}

break_stmt: 
BREAK  
;

continue_stmt: 
CONTINUE  
;

return_stmt: 
RETURN test %prec high  {if(!check_type(current_func_type,$2.type))return 0;}
| RETURN %prec low 
 
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
while_test 
|while_test else_statement 
;

while_test:
WHILE{$1.jump=code.size()+1;} test  {$3.jump=code.size()+1; string c="if "+convert($3.reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);} COLON suite {string c=code[$3.jump]; c=c+to_string(code.size()+2); code[$3.jump]=c; c="jump line "+to_string($1.jump); code.push_back(c);}

for_stmt: 
FOR expr IN test COLON suite %prec low  
| FOR expr IN test COLON suite else_statement %prec high
;

funcdef: 
DEF name parameters COLON suite  {update_table($2.lexeme,6);}
| DEF name parameters RETURN_ARROW data_type{current_func_type=$5.type;} COLON suite  {update_table($2.lexeme,6);}
;

parameters: LEFT_BRACKET RIGHT_BRACKET     
| LEFT_BRACKET typedargslist RIGHT_BRACKET  
;

typedargslist: 
typedargslist COMMA full_tfpdef 
| full_tfpdef 
;

full_tfpdef: 
name COLON test %prec low  {update_table($1.lexeme,$3.type);}
|NAME %prec high  
;

classdef: 
CLASS name opt_class_arg COLON suite   {update_table($1.lexeme,5);}
|CLASS name COLON suite   {update_table($1.lexeme,5);}
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
|test ASSIGNMENT_OPERATOR test  {if(!check_type($1.type,$3.type))return 0;}
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

test: or_test %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;}    
;

or_test: or_test OR and_test %prec high {string c=convert($1.reg); c=c+"="+c+"or"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}   
|and_test %prec low {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}       
;

and_test: and_test AND not_test   {string c=convert($1.reg); c=c+"="+c+"and"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}  
|not_test {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}              
;

not_test: NOT not_test  {string c=convert($2.reg); c=c+"=""not"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if(!($1.type==1||$1.type==3)){yyerror("type");return 0;}$$.type=3;}
|comparison  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;} 
;

comparison: comparison r_o expr %prec high  {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!check_type($1.type,$3.type))return 0;$$.type=3;} 
|expr %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}   
;

r_o: RELATIONAL_OPERATOR {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); }
;

expr: expr BIT_OR xor_expr %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"|"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|xor_expr  %prec low   {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}     
;

xor_expr: xor_expr XOR and_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"^"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|and_expr   %prec low    {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}    
;

and_expr: and_expr BIT_AND shift_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"&"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|shift_expr  %prec low     {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

shift_expr: shift_expr L_SHIFT arith_expr %prec high  {string c=convert($1.reg); c=c+"="+convert($1.reg)+"<<"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|shift_expr R_SHIFT arith_expr %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+">>"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|arith_expr %prec low    {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

arith_expr: 
arith_expr ADD term %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"+"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(!type){return 0;}$$.type=type;}
|arith_expr SUB term %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+"-"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>3)yyerror("type");if(type<1||type>3)return 0;$$.type=type;}
|term %prec low   {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

term: term a_o factor %prec high   {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if($2.lexeme!="//"){$$.type=type;}else $$.type=1;  }
|factor %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}

a_o: ARITHMETIC_OPERATOR  {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str());$$.lexeme=$1.lexeme; }
;

factor:
ADD  factor {string c=convert($2.reg); c=c+"=""+"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type!=1&&$2.type!=2){yyerror("type");return 0;}$$.type=$2.type;}
|SUB factor {string c=convert($2.reg); c=c+"=""-"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type!=1&&$2.type!=2){yyerror("type");return 0;}$$.type=$2.type;}
|BIT_NOT factor {string c=convert($2.reg); c=c+"=""~"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type<1||$2.type>3){yyerror("type");return 0;}$$.type=$2.type;}
|power {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

power:
atom_expr POWER factor %prec high {string c=convert($1.reg); c=c+"="+c+"**"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>2)yyerror("type");if(type<1||type>2)return 0;$$.type=type;}
|atom_expr %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

atom_expr: 
atom opt_trailer %prec high {string c=convert($1.lexeme); c+=convert($2.lexeme); $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str());  c=c+"="+convert($1.lexeme)+convert($2.lexeme); code.push_back(c); }
|atom %prec low {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;}
;

opt_trailer:
opt_trailer trailer {int type=check_type($1.type,$2.type);if(!type){return 0;}$$.type=type;}
|trailer   {$$.type=$1.type;}
;

atom:
LEFT_BRACKET testlist RIGHT_BRACKET {$$.type=$2.type;}
|LEFT_BRACKET  RIGHT_BRACKET                 
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET     
|LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET {$$.type=$2.type;}
|NAME   {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c);  $$.lexeme=$1.lexeme;if(check($1.lexeme))return 0;$$.type=table[$1.lexeme].type;}
|INT  {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c); $$.lexeme=$1.lexeme;$$.type=1;}
|FLOAT  {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c); $$.lexeme=$1.lexeme;$$.type=2;}
|DATA_TYPE  {$$.type=typedetector($1.lexeme);$$.lexeme=$1.lexeme;}
|STRING   {$$.type=4;}
|STRING_1  {$$.type=4;}
|NONE       {$$.type=0;}
|TRUE {$$.lexeme=$1.lexeme;$$.type=3;}
|FALSE {$$.lexeme=$1.lexeme;$$.type=3;}
|LIST {$$.type=7;}
;


trailer: 
LEFT_BRACKET arglist RIGHT_BRACKET     
| LEFT_BRACKET RIGHT_BRACKET           
| LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  {string c="["; c+=convert($2.reg); c+="]"; $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); if($2.type!=1){yyerror("type");return 0;}}
| DOT name 
;

testlist: 
testlist COMMA test {int type=check_type($1.type,$3.type);if(!type){return 0;}$$.type=type;}
| test {$$.type=$1.type;}
;


%%

const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   if(s=="dec"){cout<<"declaration error"<<endl;return;}
   if(s=="type"){cout<<"Type error"<<endl;return;}
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