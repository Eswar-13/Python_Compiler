%option yylineno
%option noyywrap
%{
    #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
    int curr_indent=0;
    int count_dedent=0;
    char* lexeme;
    stack<string>current_attributes;
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
    int operatorToInteger(const std::string& op) {
    // Map each operator to its corresponding integer value
    if (op == "+=") {
        return 0;
    } else if (op == "-=") {
        return 1;
    } else if (op == "*=") {
        return 2;
    } else if (op == "/=") {
        return 3;
    } else if (op == "//=") {
        return 4;
    } else if (op == "%=") {
        return 5;
    } else if (op == "**=") {
        return 6;
    } else if (op == "&=") {
        return 7;
    } else if (op == "|=") {
        return 8;
    } else if (op == "^=") {
        return 9;
    } else if (op == "<<=") {
        return 10;
    } else if (op == ">>=") {
        return 11;
    } else {
        return -1; // Return -1 if operator not found
    }
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
SIGNIFICAND     ({INTEGER}"."{DIGIT}*)|"."{INTEGER}

%x DEDENTATION
%x LINE_START

%%
<LINE_START>^"  "*[^ #\n]    {
                            int s=countspace(yytext);
                            unput(yytext[s]);
                            BEGIN(INITIAL);
                            if(s>curr_indent){
                            curr_indent=s;
                            current_attributes.push("INDENT");
                            return INDENT;
                            }
                            else if(s<curr_indent){
                            count_dedent=(curr_indent-s)/2;
                            count_dedent--;
                            curr_indent=s;
                            if(count_dedent)BEGIN(DEDENTATION);
                            
                            return DEDENT;
                            }
                        }
<LINE_START>#[^\n]*   {;}
<LINE_START>"\n"+     {;}
<DEDENTATION>.        { 
                        unput(yytext[0]);
                        if(count_dedent>0){
                            count_dedent--;
                            return DEDENT;
                        }else {
                            BEGIN(INITIAL);}
                        }
{arithmetic}        { yylval.attributes.lexeme=yytext; return ARITHMETIC_OPERATOR; }
{relational}        { yylval.attributes.lexeme=yytext; return RELATIONAL_OPERATOR; }
"and"               { return AND;}
"or"                { return OR;}
"not"               { return NOT;}
"&"                 {  return BIT_AND;}
"|"                 {  return BIT_OR;}
"^"                 {  return XOR;}
"~"                 {  return BIT_NOT;}
"+"                 {  return ADD;}
"-"                 {  return SUB;}
"**"                {  return POWER;}
"<<"                {  return L_SHIFT;}
">>"						{  return R_SHIFT;}
{assignment}  {  return ASSIGNMENT_OPERATOR; }
{augassignment}  { yylval.attributes.top=operatorToInteger(yytext); yylval.attributes.lexeme=yytext; return AUGASSIGNMENT_OPERATOR; }
{data_type}    { yylval.attributes.lexeme=yytext; return DATA_TYPE; } 
{INT_LITERAL}|{SIGNIFICAND} {yylval.attributes.lexeme=yytext; return NUMBER;}
\"[^\"]*\"    { yylval.attributes.lexeme=yytext; return STRING;}
\'[^\']*\'    { yylval.attributes.lexeme=yytext; return STRING_1;}
"list"{WS}"\["{WS}{data_type}{WS}"\]" { yylval.attributes.lexeme=yytext; return LIST; }
"if"                   {  return IF;}
"elif"                 {  return ELIF;}
"else"                 {  return ELSE;}
"for"                   {  return FOR;}
"in"                    {  return IN;}
"while"                 {  return WHILE;}
"break"                 {  return BREAK;}
"continue"              {  return CONTINUE;}
"def"                   {  return DEF;}
"class"                 {  return CLASS;}
";"                     {  return SEMICOLON;}
":"                     {  return COLON;}
"->"                    {  return RETURN_ARROW;}
"("                     {  return LEFT_BRACKET;}
")"                     {  return RIGHT_BRACKET;}
"\["                    {  return LEFT_SQUARE_BRACKET;}
"\]"                    {  return RIGHT_SQUARE_BRACKET;}
"\{"                    {  return LEFT_CURLY_BRACKET;}
"\}"                    {  return RIGHT_CURLY_BRACKET;}
","                     {  return COMMA;}
"return"                {  return RETURN;}
"\n"+                   { BEGIN(LINE_START);  return NEWLINE;}
"None"                  { yylval.attributes.lexeme = strdup(yytext); return NONE;}
"True"                  { yylval.attributes.lexeme = strdup(yytext); return TRUE;}
"False"                 { yylval.attributes.lexeme = strdup(yytext); return FALSE;}
"."                        {  return DOT;}
{identifier}            { yylval.attributes.lexeme = strdup(yytext); return NAME;}
#[^\n]*                 {;}
" "                     {;}
.  { yylval.attributes.lexeme=yytext; return INVALID; }

%%
