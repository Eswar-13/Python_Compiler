#!/usr/bin/env bash
flex lexer.l
bison -d parser.y
rm -f *.csv
#rm ac.txt
g++ -o ir lex.yy.c parser.tab.c -lfl
./ir -input $1 -output out.txt 
g++ loop.cpp -o loop
./loop out.txt out.3ac
g++ string.cpp -o string
./string ac.txt asm.s