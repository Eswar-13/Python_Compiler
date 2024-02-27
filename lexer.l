%option yylineno
%option noyywrap
%{
    #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
    int startline=1;
    int start=1;
%}
arithmetic     "+"|"-"|"*"|"/"|"//"|"%"|"**" 
relational      "=="|"!="|">"|"<"|">="|"<="
logical         "and"|"or"|"not"
bitwise         "&"|"|"|"^"|"~"|"<<"|">>"
assignment      "="|"+="|"-="|"*="|"/="|"//="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="
data_type       "int"|"float"|"bool"|"str"
WS              [ \t\f\n\r]*
%%
{arithmetic}        { return ARITHMETIC_OPERATOR; }
{relational}          { return RELATIONAL_OPERATOR; }
{logical}                     { return LOGICAL_OPERATOR; }
{bitwise}            { return BITWISE_OPERATOR; }
{assignment}  { return ASSIGNMENT_OPERATOR; }
{data_type}    {return DATA_TYPE; } 
"list"{WS}"\["{WS}{data_type}{WS}"\]" {return LIST; }
"if"                   {return IF;}
"elif"                 {return ELIF;}
"else"                  {return ELSE;}
"for"                   {return FOR;}
"while"                 {return WHILE;}
"break"                 {return BREAK;}
"continue"              {return CONTINUE;}


%%

