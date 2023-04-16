/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_SAM_CODINGPROJECTS_COMP_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED
# define YY_YY_HOME_SAM_CODINGPROJECTS_COMP_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    COMMA = 259,
    KEYWORD_NEW = 260,
    KEYWORD_RETURN = 261,
    KEYWORD_PRINT_INT = 262,
    KEYWORD_PRINT_BOOL = 263,
    KEYWORD_PRINT_LN = 264,
    OPEN_SQUARE = 265,
    CLOSE_SQUARE = 266,
    ASSIGN = 267,
    LESS_THAN_OR_EQUAL = 268,
    GREATER_THAN_OR_EQUAL = 269,
    EQUIVALENT = 270,
    IS_NOT_EQUAL = 271,
    LESS_THAN = 272,
    GREATER_THAN = 273,
    OR = 274,
    AND = 275,
    MINUS = 276,
    PLUS = 277,
    DIVIDE = 278,
    TIMES = 279,
    NEGATE = 280,
    DOT = 281,
    OPEN_PARENTHESIS = 282,
    CLOSE_PARENTHESIS = 283,
    OPEN_BRACE = 284,
    CLOSE_BRACE = 285,
    SQUARE_PAIR = 286,
    KEYWORD_WHILE = 287,
    KEYWORD_IF = 288,
    KEYWORD_ELSE = 289,
    KEYWORD_THIS = 290,
    KEYWORD_CLASS = 291,
    KEYWORD_EXTENDS = 292,
    KEYWORD_INT = 293,
    KEYWORD_BOOL = 294,
    KEYWORD_VOID = 295,
    KEYWORD_TRUE = 296,
    KEYWORD_FALSE = 297,
    INTEGER = 298,
    ID = 299,
    UNKOWN = 300
  };
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

#line 127 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (Driver &driver);

#endif /* !YY_YY_HOME_SAM_CODINGPROJECTS_COMP_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED  */
