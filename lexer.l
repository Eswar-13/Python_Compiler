%option yylineno
%option noyywrap
%{
    #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
    int startline=1;
    int start=1;
%}

arithmetic     "*"|"/"|"//"|"%"
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
{relational}        { return RELATIONAL_OPERATOR; }
{logical}           { return LOGICAL_OPERATOR; }
"&"                 {return AND;}
"|"                 {return OR;}
"^"                 {return XOR;}
"~"                 {return BIT_NOT;}
"+"|"-"             {return ADD_SUB;}
"**"                {return POWER;}
"<<"|">>"						{return SHIFT;}
{assignment}  { return ASSIGNMENT_OPERATOR; }
{augassignment}  {return AUGASSIGNMENT_OPERATOR; }
{data_type}    {return DATA_TYPE; } 
[0-9]+       {return NUMBER;}
\"[^\"]*\"    {return STRING;}
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
"\["                    {return LEFT_SQUARE_BRACKET;}
"\]"                    {return RIGHT_SQUARE_BRACKET;}
"\{"                    {return LEFT_CURLY_BRACKET;}
"\}"                    {return RIGHT_CURLY_BRACKET;}
","                     {return COMMA;}
"return"                {return RETURN;}
"\n"                    {return NEWLINE;}
" "                     {;}
"None"                  {return NONE;}
"True"                  {return TRUE;}
"False"                 {return FALSE;}
"."                        {return DOT;}
{identifier}            {return NAME;}
.  {fprintf(yyout,"%s",yytext)};

%%