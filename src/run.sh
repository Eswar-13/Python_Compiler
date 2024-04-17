#!/usr/bin/env bash
flex lexer.l
bison -d parser.y
rm -f *.csv
g++ -o ir lex.yy.c parser.tab.c -lfl
./ir -input $1 -output out.txt 
