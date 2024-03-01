%option yylineno
%option noyywrap
%{
    #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
    int startline=1;
    int start=1;
    int curr_indent=0;
    int count_dedent=0;
    int countspace(char *str) {
        int count = 0;
        while (*str) {
            if (*str == ' ') {
                count++;
            }
            str++;
        }
        return count;
    }

%}

arithmetic     "*"|"/"|"//"|"%"
relational      "=="|"!="|">"|"<"|">="|"<="          
bitwise         "&"|"|"|"^"|"~"|"<<"|">>"
assignment      "="
augassignment   "+="|"-="|"*="|"/="|"//="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="
data_type       "int"|"float"|"bool"|"str"
WS              [ \t\f\n\r]*
identifier      [A-Za-z_]+
DIGIT           [0-9]
INTEGER         {DIGIT}+
INT_LITERAL     {INTEGER}
SIGNED_INT      [+-]{INT_LITERAL}
SIGNIFICAND     ({INTEGER}"."{DIGIT}*)|"."{INTEGER}
REAL_LITERAL    ({INTEGER}[DEde][+-]?{INTEGER})|({SIGNIFICAND}([DEde][+-]?{INTEGER})?)
SIGNED_REAL     [+-]{REAL_LITERAL}

%x DEDENTATION

%%
{arithmetic}        { cout<<yytext; return ARITHMETIC_OPERATOR; }
{relational}        { cout<<yytext; return RELATIONAL_OPERATOR; }
"and"               {cout<<yytext;return AND;}
"or"               {cout<<yytext;return OR;}
"not"               {cout<<yytext;return NOT;}
"&"                 {cout<<yytext; return BIT_AND;}
"|"                 {cout<<yytext; return BIT_OR;}
"^"                 {cout<<yytext; return XOR;}
"~"                 {cout<<yytext; return BIT_NOT;}
"+"|"-"             {cout<<yytext; return ADD_SUB;}
"**"                {cout<<yytext; return POWER;}
"<<"|">>"						{cout<<yytext; return SHIFT;}
{assignment}  { cout<<yytext; return ASSIGNMENT_OPERATOR; }
{augassignment}  {cout<<yytext; return AUGASSIGNMENT_OPERATOR; }
{data_type}    {cout<<yytext; return DATA_TYPE; } 
{INT_LITERAL}|{SIGNED_INT}|{REAL_LITERAL}|{SIGNED_REAL} {cout<<yytext;return NUMBER;}
\"[^\"]*\"    {cout<<yytext; return STRING;}
"list"{WS}"\["{WS}{data_type}{WS}"\]" {cout<<yytext; return LIST; }
"if"                   {cout<<yytext; return IF;}
"elif"                 {cout<<yytext; return ELIF;}
"else"                  {cout<<yytext; return ELSE;}
"for"                   {cout<<yytext; return FOR;}
"in"                    {cout<<yytext; return IN;}
"while"                 {cout<<yytext; return WHILE;}
"break"                 {cout<<yytext; return BREAK;}
"continue"              {cout<<yytext; return CONTINUE;}
"def"                   {cout<<yytext; return DEF;}
"class"                 {cout<<yytext; return CLASS;}
";"                     {cout<<yytext; return SEMICOLON;}
":"                     {cout<<yytext; return COLON;}
"->"                    {cout<<yytext; return RETURN_ARROW;}
"("                     {cout<<yytext; return LEFT_BRACKET;}
")"                     {cout<<yytext; return RIGHT_BRACKET;}
"\["                    {cout<<yytext; return LEFT_SQUARE_BRACKET;}
"\]"                    {cout<<yytext; return RIGHT_SQUARE_BRACKET;}
"\{"                    {cout<<yytext; return LEFT_CURLY_BRACKET;}
"\}"                    {cout<<yytext; return RIGHT_CURLY_BRACKET;}
","                     {cout<<yytext; return COMMA;}
"return"                {cout<<yytext; return RETURN;}
"\n"                    {cout<<yytext; return NEWLINE;}
^"  "*                  {cout<<yytext;
                            if(countspace(yytext)>curr_indent){
                            curr_indent=countspace(yytext);
                            return INDENT;
                            }
                            else if(countspace(yytext)<curr_indent){
                            count_dedent=(curr_indent-countspace(yytext))/2;
                            count_dedent--;
                            curr_indent=countspace(yytext);
                            BEGIN(DEDENTATION);
                            return DEDENT;
                            }
                            else curr_indent=countspace(yytext);
                        }
<DEDENTATION>.        { 
                        unput(yytext[0]);
                        if(count_dedent>0){
                            count_dedent--;
                            return DEDENT;
                        }else BEGIN(INITIAL);
                        }
"None"                  {cout<<yytext; return NONE;}
"True"                  {cout<<yytext; return TRUE;}
"False"                 {cout<<yytext; return FALSE;}
"."                        {cout<<yytext; return DOT;}
{identifier}            {cout<<yytext; return NAME;}
.  {printf("%s",yytext); }

%%
