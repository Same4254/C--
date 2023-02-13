%{
    #include <iostream>
    #include <iomanip>
    #include "../include/Driver.hpp"
    #include "grammar.h"
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*
INTEGER {DIGIT}+

WHITESPACE [ \n\t\r]+

%%

";" { return SEMICOLON; }
"," { return COMMA; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return TIMES; }
"/" { return DIVIDE; }
"<=" { return LESS_THAN_OR_EQUAL; }
">=" { return GREATER_THAN_OR_EQUAL; }
"==" { return EQUIVALENT; }
"!=" { return IS_NOT_EQUAL; }
"<" { return LESS_THAN; }
">" { return GREATER_THAN; }
"&&" { return AND; }
"||" { return OR; }
"=" { return ASSIGN; }
"!" { return NEGATE; }
"." { return DOT; }

"[]" { return SQUARE_PAIR; }

"[" { return OPEN_SQUARE; }
"]" { return CLOSE_SQUARE; }

"(" { return OPEN_PARENTHESIS; }
")" { return CLOSE_PARENTHESIS; }

"{" { return OPEN_BRACE; }
"}" { return CLOSE_BRACE; }

"while" { return KEYWORD_WHILE; }
"if" { return KEYWORD_IF; }
"else" { return KEYWORD_ELSE; }
"this" { return KEYWORD_THIS; }
"class" { return KEYWORD_CLASS; }
"extends" { return KEYWORD_EXTENDS; }
"new" { return KEYWORD_NEW; }
"return" { return KEYWORD_RETURN; }
"int" { return KEYWORD_INT; }
"bool" { return KEYWORD_BOOL; }
"void" { return KEYWORD_VOID; }

"true" { yylval->val = 1; return KEYWORD_TRUE; }
"false" { yylval->val = 0; return KEYWORD_FALSE; }

"//".* { ; }

{ID} {
    yylval->id = strdup(yytext);
   
    return ID;
}

{INTEGER} {
    yylval->val = atoi(yytext);
   
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
