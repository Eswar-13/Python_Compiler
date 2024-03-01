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
identifier      [A-Za-z_][A-Za-z_0-9]*
DIGIT           [0-9]
INTEGER         {DIGIT}+
INT_LITERAL     {INTEGER}
SIGNED_INT      [+-]{INT_LITERAL}
SIGNIFICAND     ({INTEGER}"."{DIGIT}*)|"."{INTEGER}
REAL_LITERAL    ({INTEGER}[DEde][+-]?{INTEGER})|({SIGNIFICAND}([DEde][+-]?{INTEGER})?)
SIGNED_REAL     [+-]{REAL_LITERAL}

%x DEDENTATION
%x LINE_START

%%
<LINE_START>^"  "*[^ \n]    {cout<<" 23"<<yytext;
                            int s=countspace(yytext);
                            unput(yytext[s]);
                            BEGIN(INITIAL);
                            if(s>curr_indent){
                            curr_indent=s;
                            cout<<'!';
                            return INDENT;
                            }
                            else if(s<curr_indent){
                            count_dedent=(curr_indent-s)/2;
                            count_dedent--;
                            curr_indent=s;
                            if(count_dedent)BEGIN(DEDENTATION);
                            cout<<'?';
                            return DEDENT;
                            }
                        }
<DEDENTATION>.        { cout<<" 24";
                        unput(yytext[0]);
                        if(count_dedent>0){
                            count_dedent--;
                            return DEDENT;
                        }else {
                            cout<<curr_indent;
                            BEGIN(INITIAL);}
                        }
{arithmetic}        { cout<<yytext; return ARITHMETIC_OPERATOR; }
{relational}        { cout<<yytext; return RELATIONAL_OPERATOR; }
"and"               {cout<<yytext;return AND;}
"or"                {cout<<yytext;return OR;}
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
\'[^\']*\'    {cout<<yytext; return STRING;}
"list"{WS}"\["{WS}{data_type}{WS}"\]" {cout<<yytext; return LIST; }
"if"                   {cout<<" 1"<<yytext; return IF;}
"elif"                 {cout<<" 2"<<yytext; return ELIF;}
"else"                 {cout<<" 3"<<yytext; return ELSE;}
"for"                   {cout<<" 4"<<yytext; return FOR;}
"in"                    {cout<<" 5"<<yytext; return IN;}
"while"                 {cout<<" 6"<<yytext; return WHILE;}
"break"                 {cout<<" 7"<<yytext; return BREAK;}
"continue"              {cout<<" 8"<<yytext; return CONTINUE;}
"def"                   {cout<<" 9"<<yytext; return DEF;}
"class"                 {cout<<" 10"<<yytext; return CLASS;}
";"                     {cout<<" 11"<<yytext; return SEMICOLON;}
":"                     {cout<<" 12"<<yytext; return COLON;}
"->"                    {cout<<" 13"<<yytext; return RETURN_ARROW;}
"("                     {cout<<" 14"<<yytext; return LEFT_BRACKET;}
")"                     {cout<<" 15"<<yytext; return RIGHT_BRACKET;}
"\["                    {cout<<" 16"<<yytext; return LEFT_SQUARE_BRACKET;}
"\]"                    {cout<<" 17"<<yytext; return RIGHT_SQUARE_BRACKET;}
"\{"                    {cout<<" 18"<<yytext; return LEFT_CURLY_BRACKET;}
"\}"                    {cout<<" 19"<<yytext; return RIGHT_CURLY_BRACKET;}
","                     {cout<<" 20"<<yytext; return COMMA;}
"return"                {cout<<" 21"<<yytext; return RETURN;}
"\n"+                   {cout<<" 22"<<yytext; BEGIN(LINE_START); return NEWLINE;}
"None"                  {cout<<" 25"<<yytext; return NONE;}
"True"                  {cout<<" 26"<<yytext; return TRUE;}
"False"                 {cout<<" 27"<<yytext; return FALSE;}
"."                        {cout<<" 28"<<yytext; return DOT;}
{identifier}            {cout<<" 29"<<yytext; return NAME;}
.  {printf("30%s",yytext); }

%%
