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

    ASTNode_LValue* lvalue;
    ASTNode_Type* type;

    ASTNode_Formal_List* formals;
    ASTNode_Formal* formal;

    ASTNode_MemberDeclaration* member_declaration;
    ASTNode_MemberDeclaration_List* member_declaration_list;

    ASTNode_Class* clazz;
    ASTNode_Class_List* class_list;
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

%type <formal> formal

%type <formals> formals_list
%type <formals> formals_optional

%type <lvalue> lvalue
%type <type> type

%type <member_declaration_list> member_declaration_klein
%type <member_declaration> member_declaration

%type <clazz> class_declaration
%type <class_list> class_list
%type <class_list> class_klein

%%

class_list:
    class_declaration class_klein { $$ = $2; $$->AddClass($1); }

class_klein:
    class_declaration class_klein { $$ = $2; $$->AddClass($1); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Class_List>()); }

class_declaration:
    KEYWORD_CLASS ID OPEN_BRACE member_declaration_klein CLOSE_BRACE SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Class>($2, $4)); }
    | KEYWORD_CLASS ID KEYWORD_EXTENDS ID OPEN_BRACE member_declaration_klein CLOSE_BRACE SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Class_Child>($2, $4, $6)); }

member_declaration:
    type ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_MemberDeclaration_Variable>($1, $2)); }
    | type ID OPEN_PARENTHESIS formals_list CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_MemberDeclaration_Function>($1, $4, $2, $7)); }
    | ID OPEN_PARENTHESIS formals_list CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_MemberDeclaration_Constructor>($3, $1, $6)); }

member_declaration_klein:
    member_declaration member_declaration_klein { $$ = $2; $$->AddDeclaration($1); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_MemberDeclaration_List>()); }

statement:
    expr SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_ExprOnly>($1)); }

    | type ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration>($1, $2)); }

    /*
    | KEYWORD_INT ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Int>($2)); }
    | KEYWORD_BOOL ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Bool>($2)); }
    | KEYWORD_VOID ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Void>($2)); }
    | ID ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Custom>($1, $2)); }
    */

    /*
    | KEYWORD_INT SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Int_Array>($3)); }
    | KEYWORD_BOOL SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Bool_Array>($3)); }
    | KEYWORD_VOID SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Void_Array>($3)); }
    | ID SQUARE_PAIR ID SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_VariableDeclaration_Custom_Array>($1, $3)); }
    */

    | lvalue ASSIGN expr SEMICOLON { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Statement_Assignment>($1, $3)); }
    
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
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Actuals>()); }

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

    | KEYWORD_NEW ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Obj>($4, $2)); }

    /*
    | KEYWORD_NEW KEYWORD_INT OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Int>($4)); }
    | KEYWORD_NEW KEYWORD_BOOL OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Bool>($4)); }
    | KEYWORD_NEW KEYWORD_VOID OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Void>($4)); }

    | KEYWORD_NEW KEYWORD_INT SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_IntArray>($5)); }
    | KEYWORD_NEW KEYWORD_BOOL SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_BoolArray>($5)); }
    | KEYWORD_NEW KEYWORD_VOID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_VoidArray>($5)); }

    | KEYWORD_NEW ID OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_Custom>($4, $2)); }
    | KEYWORD_NEW ID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array_CustomArray>($5, $2)); }
    */

    | KEYWORD_NEW type OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Expr_New_Array>($2, $4)); }

    | lvalue { $$ = $1; }

lvalue:
    ID { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_ID>($1)); }
    | ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_MethodCall>($3, $1)); }

    | lvalue OPEN_SQUARE expr CLOSE_SQUARE { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_Array>($1, $3)); }

    | lvalue DOT ID { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_Obj_Access>($1, $3)); }
    | lvalue DOT ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_Obj_MethodCall> ($1, $3, $5)); }

    | KEYWORD_THIS { $$ = parser->ast.AddNode(std::make_unique<ASTNode_LValue_This>()); }

type:
    KEYWORD_INT { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Int>()); }
    | KEYWORD_BOOL { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Bool>()); }
    | KEYWORD_VOID { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Void>()); }
    | ID { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_ID>($1)); }
    
    | KEYWORD_INT SQUARE_PAIR { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Int_Array>()); }
    | KEYWORD_BOOL SQUARE_PAIR { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Bool_Array>()); }
    | KEYWORD_VOID SQUARE_PAIR { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_Void_Array>()); }
    | ID SQUARE_PAIR { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Type_ID_Array>($1)); }


formal:
    type ID { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Formal>($1, $2)); }

formals_list:
    formal formals_optional { $$ = $2; $$->AddFormal($1); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Formal_List>()); }

formals_optional:
    COMMA formal formals_optional { $$ = $3; $$->AddFormal($2); }
    | %empty { $$ = parser->ast.AddNode(std::make_unique<ASTNode_Formal_List>()); }

%%
