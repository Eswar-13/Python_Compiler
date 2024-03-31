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
        int list_type;
        int list_number;
        int funct_return_type;
        string parent_class="None";
        vector<int>func_parameter;
        int line_number;
        string class_type;
        map<string,content>func_content;
        content(){}
        content(int type_num,int line) {
            type=type_num;
            line_number=line;
        }
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
        else if(s[i]==']')break;
        else if(a&&s[i]!=' ')t+=s[i];
    }
    return typedetector(t);
}

vector<string>code;
map<string,map<string,content>>table;
string curr_func="global";
string curr_class="None";
int total_class_type=11;
map<string,int>classes_type;
map<int,string>type_to_class;
void update_class_type(string key){
    classes_type[key]=total_class_type;
    type_to_class[total_class_type]=key;
    total_class_type++;
}
extern stack<string>current_attributes;
int current_func_type=-1;
int is_return=0;
int is_self=0;
int check_type(int type1, int type2){
    if(type1>10&&type2>10){
        if(type1==type2)return type1;
        string parent="";
        while(type1!=type2&&parent!="None"){
            parent=table["global"][type_to_class[type2]].parent_class;
            if(parent!="None")type2=table["global"][parent].type;
            if(type1==type2)return type1;
        }
        return 0;
    }
    if(type1==type2)return type1;
    else if(type1==1&&type2==3||type1==3&&type2==1)return type1;
    else if(type1==1&&type2==2||type1==2&&type2==1)return type2;
    else {
        yyerror("type");
        return 0;
    }
}
void update_table(string key,int type,int line_number){
    table[curr_func][key]=content(type,line_number);
    current_attributes.push(key);
    cout<<key<<endl;
}
bool check(string s){
    if(s=="__name__"){update_table(s,4,0);return 0;}
    if(table[curr_func].find(s)==table[curr_func].end() && table["global"].find(s)==table["global"].end()){yyerror("dec");return 1;}
    else return 0;
}
int get_type(string key){
    if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].type;
    return table[curr_func][key].type;
}
int get_listtype(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return 0;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].list_type;
    return table[curr_func][key].list_type;
}
int get_listnumber(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return -1;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].list_number;
    return table[curr_func][key].list_number;
}
int get_funct_type(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return -1;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].funct_return_type;
    return table[curr_func][key].funct_return_type;
}
vector<int> get_func_parameter(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return {};}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].func_parameter;
    return table[curr_func][key].func_parameter;
}
int match_vector(vector<int>a,vector<int>b){
    if(a.size()!=b.size()){yyerror("type");return 0;}
    for(int i=0;i<a.size();i++){
        if(!check_type(a[i],b[i]))return 0;
    }
    return 1;
}
void add_class(string target,string input){
    for(auto it:table[input]){
        table[target][it.first]=it.second;
    }
}
void copy_content(string key){
    for(auto it:table[key]){
        table[curr_func][key].func_content[it.first]=it.second;
    }
    table.erase(key);
}

void find_and_replace(string a,string b,int l,int r){
    for(int i=l;i<r;i++){
        string s=code[i];
        size_t pos = 0;
        while ((pos = s.find(a, pos)) != string::npos) {
            s.replace(pos, a.length(), b);
            pos += b.length();
        }
        code[i]=s;
    }
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
struct other{
    vector<int>types;
    vector<string>lexemes;
    vector<string>regs;
};
// types
// 0:None
// 1:int
// 2:float
// 3:bool
// 4:str
// 5:class
// 6:function
// 7:list
// 8:class as data_type
%}

%union{
   struct{
     int top;
     char * reg;
     int type;
     int jump;
     int line;
     int dot;
     int list_type;
     int count;
     char* lexeme;
     struct other* other;
   }attributes;
}
%token<attributes> ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BITWISE_OPERATOR ASSIGNMENT_OPERATOR DATA_TYPE FOR WHILE IF ELIF ELSE BREAK CLASS CONTINUE LIST 
%token<attributes> SEMICOLON AUGASSIGNMENT_OPERATOR COLON LEFT_BRACKET RIGHT_BRACKET RETURN_ARROW COMMA NAME
%token<attributes> LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET NONE TRUE FALSE
%token<attributes> IN DEF NOT RETURN NEWLINE INDENT DEDENT AND OR XOR BIT_NOT ADD SUB POWER BIT_AND BIT_OR
%token<attributes> INT FLOAT STRING DOT L_SHIFT R_SHIFT STRING_1
%token<attributes> LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET INVALID SELF RANGE LEN PRINT

%type<attributes>  module stmt simple_stmt compound_stmt testlist expr more_expr small_stmt expr_stmt break_stmt continue_stmt return_stmt annassign Assign_stmt test if_stmt if_test elif_test while_stmt while_test for_stmt for_test range funcdef classdef suite else_statement elif_statements parameters typedargslist full_tfpdef opt_class_arg arglist argument comparison stmt_list or_test and_test not_test xor_expr and_expr shift_expr arith_expr term factor power atom_expr atom opt_trailer trailer 
%type<attributes>  a_o r_o param_list name data_type func_name class_name dec_name
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
%precedence NEWLINE SEMICOLON STRING_1 COLON ASSIGNMENT_OPERATOR AUGASSIGNMENT_OPERATOR ADD SUB AND ARITHMETIC_OPERATOR BIT_AND BIT_NOT BIT_OR BITWISE_OPERATOR BREAK LEFT_BRACKET RIGHT_BRACKET LEFT_CURLY_BRACKET LEFT_SQUARE_BRACKET RIGHT_CURLY_BRACKET RIGHT_SQUARE_BRACKET CLASS COMMA CONTINUE DATA_TYPE DEDENT DEF DOT ELIF ELSE FALSE FOR IF IN INDENT LIST NAME NONE NOT INT FLOAT OR POWER RELATIONAL_OPERATOR RETURN RETURN_ARROW SHIFT STRING TRUE WHILE XOR YYEOF SELF LEN PRINT

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
dec_name annassign  {string c=convert($1.lexeme); c=c+"="+convert($2.reg); code.push_back(c); 
                    update_table($1.lexeme,$2.type,$1.line);
                    if($2.type==7){
                        table[curr_func][$1.lexeme].list_type=$2.list_type;
                        table[curr_func][$1.lexeme].list_number=$2.count;
                    }
                    if($1.type==1)table[curr_class][$1.lexeme]=table[curr_func][$1.lexeme];
                }
|test AUGASSIGNMENT_OPERATOR test {if(!check_type($1.type,$3.type))return 0;}
|Assign_stmt   
;

Assign_stmt:  
test ASSIGNMENT_OPERATOR test {string c=convert($1.lexeme); c=c+"="+convert($3.reg); code.push_back(c);  $$.reg=$3.reg;
                                    if($1.type==7){
                                        int list_type=get_listtype($1.lexeme);
                                        if(!check_type(list_type,$3.type))return 0;
                                        if(get_listnumber($1.lexeme)!=$3.count){yyerror("type");return 0;}
                                    }else{
                                        if(!check_type($1.type,$3.type))return 0;$$.type=$1.type;
                                    }
                                }
;
dec_name: SELF DOT name %prec high{$$.type=1;$$.reg=$3.reg;$$.lexeme=$3.lexeme;$$.line=$3.line;if(!is_self){yyerror("type");return 0;}}
|name {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.line=$1.line;}

name: NAME {$$.lexeme=$1.lexeme; string c=convert($1.lexeme); $$.reg=new char[c.size()]; strcpy($$.reg, c.c_str()); $$.line=yylineno;}
;

annassign:
COLON data_type param_list %prec high{  $$.reg=$3.reg;$$.type=$2.type;
                                        if($2.type==7){
                                            int list_type=typelist($2.lexeme);
                                            if(!check_type(list_type,$3.type))return 0;
                                            $$.list_type=list_type;
                                            $$.count=$3.count;
                                        }else{
                                            if(!check_type($2.type,$3.type))return 0;
                                        }
                                    }
|COLON data_type %prec low  {$$.type=$2.type;if($2.type==8)$$.lexeme=$2.lexeme;}
;
data_type: DATA_TYPE {$$.type=typedetector($1.lexeme);}
|LIST {$$.type=7;$$.lexeme=$1.lexeme;}
|NONE {$$.type=0;}
|NAME {if(check($1.lexeme)&&get_type($1.lexeme)!=5)return 0;$$.type=classes_type[$1.lexeme]; }
;
param_list:
ASSIGNMENT_OPERATOR test  {$$.reg=$2.reg; $$.type=$2.type;$$.count=$2.count;}

break_stmt: 
BREAK  
;

continue_stmt: 
CONTINUE  
;

return_stmt: 
RETURN test %prec high  {if(!check_type(current_func_type,$2.type))return 0;is_return=1;}
| RETURN %prec low  {if(current_func_type!=0||current_func_type==-1){yyerror("type");return 0;}}

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
for_test 
| for_test else_statement 
;

for_test:
FOR name IN range{string c=convert($2.lexeme); c=c+"="+convert($4.lexeme); code.push_back(c); $1.jump=code.size()+1; c="r"+to_string(node); node++; c=c+"="+convert($2.lexeme); code.push_back(c); c="r"+to_string(node-1); c=c+"="+c+"<"+convert($4.reg); code.push_back(c); c="if r"+to_string(node-1)+" jump line "+to_string(code.size()+3); code.push_back(c); c="jump line "; code.push_back(c);} COLON suite{ fill(code.size()+2,1); string c="jump line "+to_string($1.jump); code.push_back(c);}

range:
RANGE LEFT_BRACKET test COMMA test RIGHT_BRACKET {$$.lexeme=$3.reg; $$.reg=$5.reg;  if($3.type!=1||$5.type!=1){yyerror("type");return 0;}}
|RANGE LEFT_BRACKET test  RIGHT_BRACKET {string c="0"; $$.lexeme=new char[c.size()+1]; strcpy($$.lexeme, c.c_str()); $$.reg=$3.reg;  if($3.type!=1){yyerror("type");return 0;}}
;

funcdef: 
DEF func_name parameters COLON {
                                current_func_type=0; 
                                string c=""; code.push_back(c); c=convert($2.lexeme);
                                c=c+" :"; code.push_back(c); 
                                code.push_back("funcbegin");
                                for(auto x : $3.other->types){
                                    c="r"+to_string(node); node++;
                                    c=c+"=popparameter";
                                    code.push_back(c);
                                }
                                $1.jump=code.size();
                                $4.jump=node-1;
                                } 
                                suite{
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        update_table($2.lexeme,6,$2.line);
                                        copy_content($2.lexeme);
                                        table[curr_func][$2.lexeme].func_parameter=($3.other)->types;
                                        table[curr_func][$2.lexeme].funct_return_type=0;
                                        curr_func="global";
                                        current_func_type=-1;
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        int i=0;
                                        for(auto x : $3.other->lexemes){
                                            c="r"+to_string($4.jump-i); 
                                            find_and_replace(x,c,$1.jump,code.size());
                                            i++;
                                        }
                                        c="funcend"; code.push_back(c);
                                        c=""; code.push_back(c);
                                    }
| DEF func_name parameters RETURN_ARROW data_type{current_func_type=$5.type;  } COLON{
                                string c=""; code.push_back(c); c=convert($2.lexeme);
                                c=c+" :"; code.push_back(c); 
                                code.push_back("funcbegin");
                                for(auto x : $3.other->types){
                                    c="r"+to_string(node); node++;
                                    c=c+"=popparameter";
                                    code.push_back(c);
                                }
                                $1.jump=code.size();
                                $4.jump=node-1;
                                }  
                                 suite{
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        update_table($2.lexeme,6,$2.line);
                                        copy_content($2.lexeme);
                                        table[curr_func][$2.lexeme].func_parameter=($3.other)->types;
                                        table[curr_func][$2.lexeme].funct_return_type=$5.type;
                                        curr_func="global";
                                        current_func_type=-1;
                                        if(!is_return && $5.type){yyerror("type");return 0;}
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        int i=0;
                                        for(auto x : $3.other->lexemes){
                                            c="r"+to_string($4.jump-i); 
                                            find_and_replace(x,c,$1.jump,code.size());
                                            i++;
                                        }
                                        c="funcend"; code.push_back(c);
                                        c=""; code.push_back(c);
                                    }
;
func_name:name{curr_func=$1.lexeme;$$.lexeme=$1.lexeme;}
;
parameters: LEFT_BRACKET RIGHT_BRACKET   {$$.other=new other;}
| LEFT_BRACKET typedargslist RIGHT_BRACKET  {$$.other=$2.other;}
;

typedargslist: 
typedargslist COMMA full_tfpdef {$$.other=$1.other;if($3.type)(($$.other)->types).push_back($3.type); if($3.type)(($$.other)->lexemes).push_back($3.lexeme);}
| full_tfpdef {$$.other=new other;if($1.type)(($$.other)->types).push_back($1.type); if($1.type)(($$.other)->lexemes).push_back($1.lexeme);}
;

full_tfpdef: 
name COLON data_type %prec low  {$$.lexeme=strdup($1.lexeme); update_table($1.lexeme,$3.type,$1.line);$$.type=$3.type;if($$.type==7)table[curr_func][$1.lexeme].list_type=typelist($3.lexeme);}
|NAME %prec high  {$$.lexeme=strdup($1.lexeme);}
|SELF {$$.type=0;is_self=1;}
;


classdef: 
CLASS class_name opt_class_arg COLON{
                                    string c=""; code.push_back(c);
                                    c=convert($2.lexeme);
                                    c=c+" :"; code.push_back(c);
                                    c="Parent : ";
                                    code.push_back(c+convert($3.lexeme));
                                    code.push_back("classbegin");
                                    cout<<curr_class<<endl;
                                } 
                               suite   {
                                update_table($2.lexeme,5,$2.line);curr_class="None";table["global"][$2.lexeme].parent_class=$3.lexeme;
                                string c="classend"; code.push_back(c);
                                c=""; code.push_back(c);
                                }
|CLASS class_name COLON {
                        string c=""; code.push_back(c);
                        c=convert($2.lexeme);
                        c=c+" :"; code.push_back(c);
                        code.push_back("classbegin");
}
                  suite   {
                            update_table($2.lexeme,5,$2.line);curr_class="None";
                            string c="classend"; code.push_back(c);
                                c=""; code.push_back(c);
                                }
;
class_name:name{curr_class=$1.lexeme;$$.lexeme=$1.lexeme;update_class_type(curr_class);}
;
opt_class_arg: 
LEFT_BRACKET RIGHT_BRACKET  {$$.lexeme=(char*)"None";}
|LEFT_BRACKET argument RIGHT_BRACKET  {add_class(curr_class,$2.lexeme);$$.lexeme=$2.lexeme;$$.other =$2.other;}  
;

arglist: 
arglist COMMA argument %prec high {$$.other=$1.other;if($3.type)(($$.other)->types).push_back($3.type);if($3.type)(($$.other)->lexemes).push_back($3.lexeme); if($3.type)(($$.other)->regs).push_back($3.reg);}
| argument %prec low  {$$.other=new other;if($1.type)(($$.other)->types).push_back($1.type); if($1.type)(($$.other)->lexemes).push_back($1.lexeme); if($1.type)(($$.other)->regs).push_back($1.reg);}
;

argument: 
test   {$$.type=$1.type; $$.lexeme=$1.lexeme; $$.reg=$1.reg;}     
|test ASSIGNMENT_OPERATOR test  {if(!check_type($1.type,$3.type))return 0;}
|SELF  {$$.type=0; string c="self"; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str());}
;



suite: 
simple_stmt 
| NEWLINE INDENT stmt_list DEDENT  
| NEWLINE INDENT stmt_list YYEOF 
;
stmt_list : 
stmt_list stmt  
| stmt 
;

test: or_test %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.count=$1.count;}    
;

or_test: or_test OR and_test %prec high {string c=convert($1.reg); c=c+"="+c+"or"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}   
|and_test %prec low {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}       
;

and_test: and_test AND not_test   {string c=convert($1.reg); c=c+"="+c+"and"+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}  
|not_test {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}              
;

not_test: NOT not_test  {string c=convert($2.reg); c=c+"=""not"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if(!($2.type==1||$2.type==3)){yyerror("type");return 0;}$$.type=3;}
|comparison  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;} 
;

comparison: comparison r_o expr %prec high  {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;if(!check_type($1.type,$3.type))return 0;$$.type=3;} 
|expr %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}   
;

r_o: RELATIONAL_OPERATOR {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); }
;

expr: expr BIT_OR xor_expr %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"|"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|xor_expr  %prec low   {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}     
;

xor_expr: xor_expr XOR and_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"^"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|and_expr   %prec low    {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}    
;

and_expr: and_expr BIT_AND shift_expr  %prec high {string c=convert($1.reg); c=c+"="+convert($1.reg)+"&"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|shift_expr  %prec low     {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;

shift_expr: shift_expr L_SHIFT arith_expr %prec high  {string c=convert($1.reg); c=c+"="+convert($1.reg)+"<<"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|shift_expr R_SHIFT arith_expr %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+">>"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;if(!(($1.type==1||$1.type==3)&&($3.type==1||$3.type==3))){yyerror("type");return 0;}$$.type=3;}
|arith_expr %prec low    {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;

arith_expr: 
arith_expr ADD term %prec high    {string c=convert($1.reg); c=c+"="+convert($1.reg)+"+"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(!type){return 0;}$$.type=type;}
|arith_expr SUB term %prec high   {string c=convert($1.reg); c=c+"="+convert($1.reg)+"-"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>3)yyerror("type");if(type<1||type>3)return 0;$$.type=type;}
|term %prec low   {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;

term: term a_o factor %prec high   {string c=convert($1.reg); c=c+"="+c+convert($2.reg)+convert($3.reg); code.push_back(c); $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if($2.lexeme!="//"){$$.type=type;}else $$.type=1;  }
|factor %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}

a_o: ARITHMETIC_OPERATOR  {string c=convert($1.lexeme); $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str());$$.lexeme=$1.lexeme; }
;

factor:
ADD  factor {string c=convert($2.reg); c=c+"=""+"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type!=1&&$2.type!=2){yyerror("type");return 0;}$$.type=$2.type;}
|SUB factor {string c=convert($2.reg); c=c+"=""-"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type!=1&&$2.type!=2){yyerror("type");return 0;}$$.type=$2.type;}
|BIT_NOT factor {string c=convert($2.reg); c=c+"=""~"+convert($2.reg); code.push_back(c);  $$.reg=$2.reg;if($2.type<1||$2.type>3){yyerror("type");return 0;}$$.type=$2.type;}
|power {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;

power:
atom_expr POWER factor %prec high {string c=convert($1.reg); c=c+"="+c+"**"+convert($3.reg); code.push_back(c);  $$.reg=$1.reg;int type=check_type($1.type,$3.type);if(type>2)yyerror("type");if(type<1||type>2)return 0;$$.type=type;}
|atom_expr %prec low  {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;

atom_expr: 
atom opt_trailer %prec high { 
                              if(get_type($1.lexeme)==7){
                                string c=convert($1.lexeme); c+=convert($2.lexeme); $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); c="r"+to_string(node); node++;
                                $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str());  c=c+"="+convert($1.lexeme)+convert($2.lexeme); code.push_back(c); 
                                if($2.list_type!=1){yyerror("type");return 0;}
                                $$.type=get_listtype($1.lexeme);
                              }
                              else{
                                if($2.list_type==1){yyerror("type");return 0;}
                                if($1.type==6){
                                    if(!match_vector(get_func_parameter($1.lexeme),$2.other->types)){return 0;}
                                    for(auto x: $2.other->regs){
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                    string c= "call ";
                                    c=c+convert($1.lexeme)+",1";
                                    code.push_back(c);
                                    $$.type=get_funct_type($1.lexeme);
                                    if($$.type){c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str());
                                    c=c+"=popparameter"; code.push_back(c);
                                    }
                                }
                                if($1.type==5){
                                    if(!$2.dot){
                                        $$.type=classes_type[$1.lexeme];
                                        if(!match_vector(table[$1.lexeme]["__init__"].func_parameter,$2.other->types)){return 0;}
                                    }else{
                                        $$.type=table[$1.lexeme][$2.lexeme].type;
                                        //cout<<$$.type<<" "<<$1.lexeme<<endl;
                                        if($$.type==6&&!match_vector(table[$1.lexeme][$2.lexeme].func_parameter,$2.other->types)){return 0;}
                                    }

                                }
                                if($1.type>10){
                                    if($2.dot){
                                        $$.type=table[type_to_class[$1.type]][$2.lexeme].type;
                                        if($$.type==6&&!match_vector(table[type_to_class[$1.type]][$2.lexeme].func_parameter,$2.other->types)){return 0;}
                                    }
                                }
                              }
                            }
|atom %prec low {$$.reg=$1.reg;$$.lexeme=$1.lexeme;$$.type=$1.type;$$.count=$1.count;}
;
|SELF opt_trailer %prec low{
                            if($2.dot){
                                $$.type=table[curr_class][$2.lexeme].type;
                                if($$.type==6&&!match_vector(table[curr_class][$2.lexeme].func_parameter,$2.other->types)){return 0;}
                            }
                            if(!is_self){yyerror("type");return 0;}
                            $$.lexeme=$2.lexeme; $$.reg=$2.reg;
                        }
|LEN LEFT_BRACKET test RIGHT_BRACKET {
                                if($3.type!=7){yyerror("type");return 0;}
                                $$.type=1;
                                $$.lexeme=$3.lexeme;
                                $$.reg=$$.lexeme;
                            }
|PRINT LEFT_BRACKET arglist RIGHT_BRACKET{
                                for(auto x: $3.other->regs){
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                string c= "call print,1";
                                code.push_back(c);
                                $$.type=0;
                                $$.lexeme=$3.lexeme;
                                $$.reg=$$.lexeme;
                            }
;

opt_trailer:
opt_trailer trailer {$$.lexeme=$1.lexeme;$$.other=$2.other;$$.list_type=5;$$.dot=$1.dot+$2.dot;}
|trailer   {$$.type=$1.type;$$.list_type=$1.list_type;$$.lexeme=$1.lexeme;$$.other=$1.other;$$.dot=$1.dot;}
;

atom:
LEFT_BRACKET testlist RIGHT_BRACKET {$$.type=$2.type;$$.count=$2.count;$$.reg=$2.reg;}
|LEFT_BRACKET  RIGHT_BRACKET                 
|LEFT_SQUARE_BRACKET  RIGHT_SQUARE_BRACKET     
|LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET {string c="["; c+=convert($2.lexeme); c+="]"; $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($$.lexeme); code.push_back(c); $$.type=$2.type;$$.count=$2.count;}
|NAME   {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c);  $$.lexeme=$1.lexeme;if(check($1.lexeme))return 0; $$.type=get_type($1.lexeme);}
|INT  {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c); $$.lexeme=$1.lexeme;$$.type=1;}
|FLOAT  {string c="r"+to_string(node); node++; $$.reg=new char[c.size() + 1]; strcpy($$.reg, c.c_str()); c=c+"=";  c=c+convert($1.lexeme); code.push_back(c); $$.lexeme=$1.lexeme;$$.type=2;}
|DATA_TYPE  {$$.type=typedetector($1.lexeme);$$.lexeme=$1.lexeme;}
|STRING   {$$.type=4;$$.reg=$1.lexeme;}
|STRING_1  {$$.type=4;}
|NONE       {$$.type=0;}
|TRUE {$$.lexeme=$1.lexeme;$$.type=3;}
|FALSE {$$.lexeme=$1.lexeme;$$.type=3;}
|LIST {$$.type=7;}
;


trailer: 
LEFT_BRACKET arglist RIGHT_BRACKET   {$$.other=$2.other;}
| LEFT_BRACKET RIGHT_BRACKET  {$$.other=new other;}         
| LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  {string c="["; c+=convert($2.reg); c+="]"; $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); if($2.type!=1){yyerror("type");return 0;}$$.type=$2.type;$$.list_type=1;}
| DOT name {$$.lexeme=$2.lexeme; $$.reg=$2.reg; $$.dot=1;}
;

testlist: 
testlist COMMA test {string c=convert($1.lexeme); c=c+","+convert($3.reg); $$.lexeme=new char[c.size() + 1]; strcpy($$.lexeme, c.c_str()); $$.type=$1.type;$$.count=$1.count+1;$$.reg=$1.reg;}
| test {$$.lexeme=$1.reg; $$.type=$1.type;$$.count=1;$$.reg=$1.reg;}
;


%%

const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   if(s=="dec"){cout<<"declaration error"<<endl;}
   if(s=="type"){cout<<"Type error"<<endl;}
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
   for(auto x: table){
    cout<<x.first<<'\n';
    for(auto y: x.second){
        cout<<" "<<y.first<<' '<<y.second.line_number<<'\n';
        if(y.second.type==6){
            for(auto it:y.second.func_content){
                cout<<"  "<<it.first<<' '<<it.second.line_number<<'\n';
            }
        }
    }
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