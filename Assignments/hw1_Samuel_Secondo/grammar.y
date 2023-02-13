%{
	#include <math.h>
    #include <stdlib.h>
    #include "parser.h"
    #define YYERROR_VERBOSE
%}

%union {
	int val;
    char *id;
}

%code {
	int yyerror(Parser *p, const char *s);
    int yylex(YYSTYPE*);
}

%pure-parser
%parse-param { Parser *parser }

%token SEMICOLON
%token COMMA
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token LESS_THAN_OR_EQUAL
%token GREATER_THAN_OR_EQUAL
%token EQUIVALENT
%token IS_NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token AND
%token OR
%token ASSIGN
%token NEGATE
%token DOT

%token OPEN_SQUARE
%token CLOSE_SQUARE

%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS

%token OPEN_BRACE
%token CLOSE_BRACE

%token SQUARE_PAIR

%token KEYWORD_WHILE
%token KEYWORD_IF
%token KEYWORD_ELSE
%token KEYWORD_THIS
%token KEYWORD_CLASS
%token KEYWORD_EXTENDS
%token KEYWORD_NEW
%token KEYWORD_RETURN
%token KEYWORD_INT
%token KEYWORD_BOOL
%token KEYWORD_VOID

%token KEYWORD_TRUE
%token KEYWORD_FALSE

%token INTEGER

%token ID

%token UNKOWN;

%%

Top:
	| SEMICOLON Top
	| COMMA Top 
	| PLUS Top
	| MINUS Top
	| TIMES Top
	| DIVIDE Top
	| LESS_THAN_OR_EQUAL Top
	| GREATER_THAN_OR_EQUAL Top
	| EQUIVALENT Top
	| IS_NOT_EQUAL Top
	| LESS_THAN Top
	| GREATER_THAN Top
	| AND Top
	| OR Top
	| ASSIGN Top
	| NEGATE Top
	| DOT Top
	 
	| OPEN_SQUARE Top
	| CLOSE_SQUARE Top
	 
	| OPEN_PARENTHESIS Top
	| CLOSE_PARENTHESIS Top
	 
	| OPEN_BRACE Top
	| CLOSE_BRACE Top
	 
	| SQUARE_PAIR Top
	 
	| KEYWORD_WHILE Top
	| KEYWORD_IF Top
	| KEYWORD_ELSE Top
	| KEYWORD_THIS Top
	| KEYWORD_CLASS Top
	| KEYWORD_EXTENDS Top
	| KEYWORD_NEW Top
	| KEYWORD_RETURN Top
	| KEYWORD_INT Top
	| KEYWORD_BOOL Top
	| KEYWORD_VOID Top
	 
	| KEYWORD_TRUE Top
	| KEYWORD_FALSE Top
	 
	| INTEGER Top
	 
	| ID Top

	| UNKOWN Top
    | %empty
;
%%
