%{
    #include <math.h>
    #include <stdlib.h>
    #include "parser.h"
    #define YYERROR_VERBOSE
%}

%union {
    int val;
    char *id;

    ASTNode* node;
	ASTNode_Expr* expr;
    ASTNode_Statement* statement;

    ASTNode_Actuals* actual;
    ASTNode_Statement_Body* body;
}

%code {
    int yyerror(Parser *p, const char *s);
    int yylex(YYSTYPE*);
}

%pure-parser
%parse-param { Parser *parser }

%token SEMICOLON
%token COMMA

%token KEYWORD_NEW
%token KEYWORD_RETURN

%token OPEN_SQUARE
%token CLOSE_SQUARE

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
%token KEYWORD_INT 
%token KEYWORD_BOOL
%token KEYWORD_VOID

%token <val> KEYWORD_TRUE
%token <val> KEYWORD_FALSE

%token <val> INTEGER

%token <id> ID

%token UNKOWN;

%type <expr> expr
%type <statement> statement
%type <body> statement_klein
%type <actual> actuals
%type <actual> actuals_optional

%%

statement:
    expr SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_ExprOnly>($1)); }

    | KEYWORD_INT ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Int>($2)); }
    | KEYWORD_BOOL ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Bool>($2)); }
    | KEYWORD_VOID ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Void>($2)); }
    | ID ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Custom>($1, $2)); }

    | KEYWORD_INT SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Int_Array>($3)); }
    | KEYWORD_BOOL SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Bool_Array>($3)); }
    | KEYWORD_VOID SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Void_Array>($3)); }
    | ID SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Custom_Array>($1, $3)); }

/*
    | lvalue ASSIGN expr SEMICOLON
*/
    
    | KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_If>($3, $5)); }
    | KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement KEYWORD_ELSE statement { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_IfElse>($3, $5, $7)); }

    | KEYWORD_WHILE OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_While>($3, $5)); }
    | OPEN_BRACE statement_klein CLOSE_BRACE { $$ = $2; }

    | KEYWORD_RETURN expr SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_Return>($2)); }
    | SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_Empty>()); }

statement_klein:
	statement statement_klein { $$ = $2; $$->AddStatement($1); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_Body>()); }

actuals:
    expr actuals_optional { $$ = $2; $$->AddExpression($1); }

actuals_optional:
    COMMA expr actuals_optional { $$ = $3; $$->AddExpression($2); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Actuals>()); }

expr:
    expr TIMES expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Times>($1, $3)); }
    | expr DIVIDE expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Divide>($1, $3)); }
    | expr PLUS expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Plus>($1, $3)); }
    | expr MINUS expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Minus>($1, $3)); }
    | OPEN_PARENTHESIS expr CLOSE_PARENTHESIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Parenthesis>($2)); }
    | expr AND expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_And>($1, $3)); }
    | expr OR expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Or>($1, $3)); }
    | expr EQUIVALENT expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Equivalent>($1, $3)); }
    | expr IS_NOT_EQUAL expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_IsNotEqual>($1, $3)); }
    | expr LESS_THAN_OR_EQUAL expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_LessThanOrEqual>($1, $3)); }
    | expr LESS_THAN expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_LessThan>($1, $3)); }
    | expr GREATER_THAN_OR_EQUAL expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_GreaterThanOrEqual>($1, $3)); }
    | expr GREATER_THAN expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_GreaterThan>($1, $3)); }

    | MINUS expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_UnaryMinus>($2)); }
    | NEGATE expr { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_BooleanNegate>($2)); }

    | INTEGER { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Integer>($1)); }

    | KEYWORD_TRUE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Boolean>($1)); }
    | KEYWORD_FALSE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_Boolean>($1)); }

    | KEYWORD_NEW KEYWORD_INT OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Int>($4)); }
    | KEYWORD_NEW KEYWORD_BOOL OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Bool>($4)); }
    | KEYWORD_NEW KEYWORD_VOID OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Void>($4)); }

    | KEYWORD_NEW KEYWORD_INT SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_IntArray>($5)); }
    | KEYWORD_NEW KEYWORD_BOOL SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_BoolArray>($5)); }
    | KEYWORD_NEW KEYWORD_VOID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_VoidArray>($5)); }

    | KEYWORD_NEW ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Obj>($4, $2)); }
    | KEYWORD_NEW ID OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Custom>($4, $2)); }
    | KEYWORD_NEW ID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_CustomArray>($5, $2)); }

%%
