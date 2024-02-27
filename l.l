%option yylineno
%option noyywrap
%option caseless
%{
    #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
     int startline=1;
     int start=1;
%}
WS              [ \t\f\n\r]|\r\n
NUM             [\"]?{WS}*[0-9]*{WS}*[\"]?
W             {WS}*
%x QUIZ_STATE
%x QUESTION_STATE
%%
<INITIAL>"<"{W}"quiz"{W}">"         { BEGIN(QUIZ_STATE);
                                        start=startline;
                                        startline=yylineno;
                                        return T_QUIZ_OPEN; }
<QUIZ_STATE>"<"{W}"singleselect "{W}"marks"{W}"="{W}{NUM}{W}">" {
                                        BEGIN(QUESTION_STATE);
                                        start=startline;
                                        startline=yylineno;
                                        return T_SINGLESELECT_OPEN; }
<QUESTION_STATE>"<"{W}"/"{W}"singleselect"{W}">"        {
                                        BEGIN(QUIZ_STATE);
                                        start=startline;
                                        startline=yylineno; 
                                        return T_SINGLESELECT_CLOSE; }
<QUIZ_STATE>"<"{W}"multiselect "{W}"marks"{W}"="{W}"\""{NUM}"\""{W}">"  {
                                        BEGIN(QUESTION_STATE);
                                        start=startline;
                                        startline=yylineno; 
                                        return T_MULTISELECT_OPEN; }

<QUESTION_STATE>"<"{W}"/"{W}"multiselect"{W}">"         {
                                        BEGIN(QUIZ_STATE);
                                        start=startline;
                                        startline=yylineno; 
                                        return T_MULTISELECT_CLOSE; }
<QUESTION_STATE>"<"{W}"choice"{W}">"              {
                                        start=startline;
                                        startline=yylineno; 
                                        return T_CHOICE_OPEN; }
<QUESTION_STATE>"<"{W}"/"{W}"choice"{W}">"             {
                                        start=startline;
                                        startline=yylineno; 
                                        return T_CHOICE_CLOSE; }
<QUESTION_STATE>"<"{W}"correct"{W}">"             {
                                        start=startline;
                                        startline=yylineno; 
                                        return T_CORRECT_OPEN; }
<QUESTION_STATE>"<"{W}"/"{W}"correct"{W}">"            {
                                        start=startline;
                                        startline=yylineno; 
                                        return T_CORRECT_CLOSE; }
<QUIZ_STATE>"<"{W}"/"{W}"quiz"{W}">"  {
                                        BEGIN(INITIAL);
                                        start=startline;
                                        startline=yylineno; 
                                        return T_QUIZ_CLOSE;}

<INITIAL,QUIZ_STATE,QUESTION_STATE>{WS}                  {startline=yylineno;}
<INITIAL,QUIZ_STATE,QUESTION_STATE>.                     { /* Ignore other characters */ }
%%

