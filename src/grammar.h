/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_SAM_CODINGPROJECTS_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED
# define YY_YY_HOME_SAM_CODINGPROJECTS_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    KEYWORD_NEW = 260,             /* KEYWORD_NEW  */
    KEYWORD_RETURN = 261,          /* KEYWORD_RETURN  */
    OPEN_SQUARE = 262,             /* OPEN_SQUARE  */
    CLOSE_SQUARE = 263,            /* CLOSE_SQUARE  */
    ASSIGN = 264,                  /* ASSIGN  */
    LESS_THAN_OR_EQUAL = 265,      /* LESS_THAN_OR_EQUAL  */
    GREATER_THAN_OR_EQUAL = 266,   /* GREATER_THAN_OR_EQUAL  */
    EQUIVALENT = 267,              /* EQUIVALENT  */
    IS_NOT_EQUAL = 268,            /* IS_NOT_EQUAL  */
    LESS_THAN = 269,               /* LESS_THAN  */
    GREATER_THAN = 270,            /* GREATER_THAN  */
    OR = 271,                      /* OR  */
    AND = 272,                     /* AND  */
    MINUS = 273,                   /* MINUS  */
    PLUS = 274,                    /* PLUS  */
    DIVIDE = 275,                  /* DIVIDE  */
    TIMES = 276,                   /* TIMES  */
    NEGATE = 277,                  /* NEGATE  */
    DOT = 278,                     /* DOT  */
    OPEN_PARENTHESIS = 279,        /* OPEN_PARENTHESIS  */
    CLOSE_PARENTHESIS = 280,       /* CLOSE_PARENTHESIS  */
    OPEN_BRACE = 281,              /* OPEN_BRACE  */
    CLOSE_BRACE = 282,             /* CLOSE_BRACE  */
    SQUARE_PAIR = 283,             /* SQUARE_PAIR  */
    KEYWORD_WHILE = 284,           /* KEYWORD_WHILE  */
    KEYWORD_IF = 285,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 286,            /* KEYWORD_ELSE  */
    KEYWORD_THIS = 287,            /* KEYWORD_THIS  */
    KEYWORD_CLASS = 288,           /* KEYWORD_CLASS  */
    KEYWORD_EXTENDS = 289,         /* KEYWORD_EXTENDS  */
    KEYWORD_INT = 290,             /* KEYWORD_INT  */
    KEYWORD_BOOL = 291,            /* KEYWORD_BOOL  */
    KEYWORD_VOID = 292,            /* KEYWORD_VOID  */
    KEYWORD_TRUE = 293,            /* KEYWORD_TRUE  */
    KEYWORD_FALSE = 294,           /* KEYWORD_FALSE  */
    INTEGER = 295,                 /* INTEGER  */
    ID = 296,                      /* ID  */
    UNKOWN = 297                   /* UNKOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "grammar.y"

    int val;
    char *id;

    ASTNode *node;
    ASTNode_Expr *expr;
    ASTNode_Statement *statement;

    ASTNode_Actuals *actual;
    ASTNode_Statement_Body *body;

    ASTNode_LValue *lvalue;
    ASTNode_Type *type;

    ASTNode_Formal_List *formals;
    ASTNode_Formal *formal;

    ASTNode_MemberDeclaration *member_declaration;
    ASTNode_MemberDeclaration_List *member_declaration_list;

    ASTNode_Class *clazz;
    ASTNode_Class_List *class_list;

#line 130 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (Driver &driver);


#endif /* !YY_YY_HOME_SAM_CODINGPROJECTS_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED  */
