flex lexer.l
bison -d parser.y
g++ -o a lex.yy.c parser.tab.c -lfl
