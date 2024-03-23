arg1=$1
flex lexer.l
bison -d parser.y
g++ -o ast lex.yy.c parser.tab.c -lfl