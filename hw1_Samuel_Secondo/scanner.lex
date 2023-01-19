%{
	#include <iostream>
    #include <iomanip>
    #include "parser.h"
    #include "grammar.h"
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*
INTEGER {DIGIT}+

WHITESPACE [ \n\t\r]+

%%

";" { printf(";\n"); return SEMICOLON; }
"," { printf(",\n"); return COMMA; }
"+" { printf("+\n"); return PLUS; }
"-" { printf("-\n"); return MINUS; }
"*" { printf("*\n"); return TIMES; }
"/" { printf("/\n"); return DIVIDE; }
"<=" { printf("<=\n"); return LESS_THAN_OR_EQUAL; }
">=" { printf(">=\n"); return GREATER_THAN_OR_EQUAL; }
"==" { printf("==\n"); return EQUIVALENT; }
"!=" { printf("!=\n"); return IS_NOT_EQUAL; }
"<" { printf("<\n"); return LESS_THAN; }
">" { printf(">\n"); return GREATER_THAN; }
"&&" { printf("&&\n"); return AND; }
"||" { printf("||\n"); return OR; }
"=" { printf("=\n"); return ASSIGN; }
"!" { printf("!\n"); return NEGATE; }
"." { printf(".\n"); return DOT; }

"[]" { printf("[]\n"); return SQUARE_PAIR; }

"[" { printf("[\n"); return OPEN_SQUARE; }
"]" { printf("]\n"); return OPEN_SQUARE; }

"(" { printf("(\n"); return OPEN_PARENTHESIS; }
")" { printf(")\n"); return CLOSE_PARENTHESIS; }

"{" { printf("{\n"); return OPEN_BRACE; }
"}" { printf("}\n"); return CLOSE_BRACE; }

"while" { printf("WHILE\n"); return KEYWORD_WHILE; }
"if" { printf("IF\n"); return KEYWORD_IF; }
"else" { printf("ELSE\n"); return KEYWORD_ELSE; }
"this" { printf("THIS\n"); return KEYWORD_THIS; }
"class" { printf("CLASS\n"); return KEYWORD_CLASS; }
"extends" { printf("EXTENDS\n"); return KEYWORD_EXTENDS; }
"new" { printf("NEW\n"); return KEYWORD_NEW; }
"return" { printf("RETURN\n"); return KEYWORD_RETURN; }
"int" { printf("INT\n"); return KEYWORD_INT; }
"bool" { printf("BOOL\n"); return KEYWORD_BOOL; }
"void" { printf("VOID\n"); return KEYWORD_VOID; }

"true" { printf("TRUE\n"); return KEYWORD_TRUE; }
"false" { printf("FALSE\n"); return KEYWORD_FALSE; }

"//".* { ; }

{ID} {
	yylval->id = strdup(yytext);
    printf("ID(%s)\n", yytext);
    return ID;
}

{INTEGER} {
    yylval->val = atoi(yytext);
    printf("NUMBER(%d)\n", yylval->val);
	return INTEGER;
}

{WHITESPACE} { ; }

. { 
	printf("UNKOWN: %s. Hex: ", yytext);
	char *string = yytext;
	while (*string) printf("%02x ", *string++);
    printf("\n");

    return UNKOWN; }

%%

int yywrap() {
	return 1;
}
