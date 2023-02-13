all: grammar.c grammar.h scanner.c
	clang++ -g main.cpp grammar.c parser.cpp scanner.c -o out

grammar.c grammar.h: grammar.y
	bison --debug -dv $< -o grammar.c

scanner.c: scanner.lex grammar.h
	flex --bison-bridge -o $@ $<

clean:
	rm *.o out grammar.c grammar.h scanner.c grammar.output
