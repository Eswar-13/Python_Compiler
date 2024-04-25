#!/usr/bin/env bash
flex lexer.l
bison -d parser.y
g++ -o ir lex.yy.c parser.tab.c -lfl
./ir -input $1 -output out.txt
rm -f *.csv
g++ loop.cpp -o loop
./loop out.txt out.3ac
g++ -o string string.cpp 
./string out.3ac asm.s
gcc asm.s -o asm.o -no-pie
./asm.o