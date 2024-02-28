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
assignment      "="
augassignment   "+="|"-="|"*="|"/="|"//="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="
data_type       "int"|"float"|"bool"|"str"
WS              [ \t\f\n\r]*
identifier      [A-Za-z_]+

%%
{arithmetic}        { return ARITHMETIC_OPERATOR; }
{relational}          { return RELATIONAL_OPERATOR; }
{logical}                     { return LOGICAL_OPERATOR; }
{bitwise}            { return BITWISE_OPERATOR; }
{assignment}  { return ASSIGNMENT_OPERATOR; }
{augassignment}  {return AUGASSIGNMENT_OPERATOR; }
{data_type}    {return DATA_TYPE; } 
"list"{WS}"\["{WS}{data_type}{WS}"\]" {return LIST; }
"if"                   {return IF;}
"elif"                 {return ELIF;}
"else"                  {return ELSE;}
"for"                   {return FOR;}
"in"                    {return IN;}
"while"                 {return WHILE;}
"break"                 {return BREAK;}
"continue"              {return CONTINUE;}
"def"                   {return DEF;}
"class"                 {return CLASS;}
";"                     {return SEMICOLON;}
":"                     {return COLON;}
"->"                    {return RETURN_ARROW;}
"("                     {return LEFT_BRACKET;}
")"                     {return RIGHT_BRACKET;}
","                     {return COMMA;}


%%

