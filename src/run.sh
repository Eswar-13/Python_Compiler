#!/usr/bin/env bash
flex lexer.l
bison -d parser.y
rm -f *.csv
#rm ac.txt
g++ -o ir lex.yy.c parser.tab.c -lfl
./ir -input $1 -output out.txt
rm -f *.csv
g++ loop.cpp -o loop
./loop out.txt ac.txt
g++ string.cpp -o string
./string ac.txt asm.s
gcc asm.s -o asm.o -no-pie
./asm.o