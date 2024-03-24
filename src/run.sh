flex lexer.l
bison -d parser.y
g++ -o ast lex.yy.c parser.tab.c -lfl
./ast -input a.py -output out.txt 
