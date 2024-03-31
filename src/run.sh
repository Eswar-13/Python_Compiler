#!/usr/bin/env bash
flex lexer.l
bison -d parser.y
rm -f *.csv
g++ -o ast lex.yy.c parser.tab.c -lfl
./ast -input $1 -output out.txt 
