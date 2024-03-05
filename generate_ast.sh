arg1=$1
flex lexer.l
bison -d parser.y
g++ -o ast lex.yy.c parser.tab.c -lfl
./ast -input $1 -output out.dot 
./string out.dot out.dot
dot -o out.pdf -Tpdf out.dot