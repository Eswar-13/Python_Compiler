flex lexer.l
bison -d parser.y
g++ -o ast lex.yy.c parser.tab.c 
./ast -input a.py -output out.txt 
