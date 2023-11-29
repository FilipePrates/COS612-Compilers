all: minijs entrada.txt
	./minijs < entrada.txt

lex.yy.c: mini_js.l
	lex mini_js.l

y.tab.c: mini_js.y
	yacc mini_js.y -v

minijs: lex.yy.c y.tab.c
	g++ -o minijs y.tab.c -lfl