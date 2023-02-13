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

%token ASSIGN

/* Relational Operators have lowest precendence, they are also not associative */
%nonassoc LESS_THAN_OR_EQUAL
%nonassoc GREATER_THAN_OR_EQUAL
%nonassoc EQUIVALENT
%nonassoc IS_NOT_EQUAL
%nonassoc LESS_THAN
%nonassoc GREATER_THAN

%left OR
%left AND

/* Follow PEMDAS. Prcendence is the lowest token */
%left MINUS
%left PLUS
%left DIVIDE
%left TIMES

%right NEGATE

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

class_list:
    class_declaration class_list_klein

class_list_klein:
    class_declaration class_list_klein
    | %empty

class_declaration:
    KEYWORD_CLASS ID OPEN_BRACE decl_klein CLOSE_BRACE SEMICOLON
    | KEYWORD_CLASS ID KEYWORD_EXTENDS ID OPEN_BRACE decl_klein CLOSE_BRACE SEMICOLON

decl:
    type ID SEMICOLON
    | type ID OPEN_PARENTHESIS optional_formals CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE
    | ID OPEN_PARENTHESIS optional_formals CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE

decl_klein:
    decl decl_klein
    | %empty

formals:
    formal
    | formal COMMA formals

formal:
    type ID

optional_formals:
    formals
    | %empty

statement:
    expr SEMICOLON
    | type ID
    | lvalue ASSIGN expr SEMICOLON
    | OPEN_BRACE statement_klein CLOSE_BRACE
    | KEYWORD_WHILE OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement

    
    | KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement
    | KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement KEYWORD_ELSE statement
    

    | KEYWORD_RETURN expr SEMICOLON
    | SEMICOLON

statement_klein:
    statement statement_klein
    | %empty

expr:
    expr TIMES expr
    | expr DIVIDE expr
    | expr PLUS expr
    | expr MINUS expr
    | OPEN_PARENTHESIS expr CLOSE_PARENTHESIS

    | expr AND expr
    | expr OR expr
    | expr EQUIVALENT expr
    | expr IS_NOT_EQUAL expr
    | expr LESS_THAN_OR_EQUAL expr
    | expr LESS_THAN expr
    | expr GREATER_THAN_OR_EQUAL expr
    | expr GREATER_THAN expr

    | MINUS expr
    | NEGATE expr

    | INTEGER
    | KEYWORD_TRUE
    | KEYWORD_FALSE

    | lvalue

    | KEYWORD_NEW ID OPEN_PARENTHESIS CLOSE_PARENTHESIS
    | KEYWORD_NEW ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS
    | KEYWORD_NEW type OPEN_SQUARE expr CLOSE_SQUARE

type:
    KEYWORD_INT optional_array_type
    | KEYWORD_BOOL optional_array_type
    | KEYWORD_VOID optional_array_type
    | ID optional_array_type

optional_array_type:
    %empty
    | SQUARE_PAIR

lvalue:
    ID
    | ID OPEN_PARENTHESIS CLOSE_PARENTHESIS
    | ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS

    | lvalue OPEN_SQUARE expr CLOSE_SQUARE

    | lvalue DOT ID
    | lvalue DOT ID OPEN_PARENTHESIS CLOSE_PARENTHESIS
    | lvalue DOT ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS

    | KEYWORD_THIS

actuals:
    expr actuals_optional_expr

actuals_optional_expr:
    COMMA expr actuals_optional_expr
    | %empty
%%
