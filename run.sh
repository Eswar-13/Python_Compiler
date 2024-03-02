flex lexer.l
bison -d parser.y
g++ -o ast lex.yy.c parser.tab.c -lfl
./ast -input testcases/a.py -output out.dot 
dot -o out.pdf -Tpdf out.dot