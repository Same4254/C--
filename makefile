BUILD_FILES := build
GENERATED_FILES := build/GeneratedFiles

INCLUDE_FILES := ./include/

all: ${GENERATED_FILES}/grammar.c ${GENERATED_FILES}/grammar.h ${GENERATED_FILES}/scanner.c
	mkdir -p ${GENERATED_FILES}
	clang++ -Iinclude -g main.cpp src/Driver.cpp ${GENERATED_FILES}/grammar.c ${GENERATED_FILES}/scanner.c -o ${BUILD_FILES}/out

${GENERATED_FILES}/grammar.c ${GENERATED_FILES}/grammar.h: grammar.y
	mkdir -p ${GENERATED_FILES}
	bison --debug -dv $< -o ${GENERATED_FILES}/grammar.c

${GENERATED_FILES}/scanner.c: scanner.lex ${GENERATED_FILES}/grammar.h
	mkdir -p ${GENERATED_FILES}
	flex --bison-bridge -o $@ $<

clean:
	rm -rf build
