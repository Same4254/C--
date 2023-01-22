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

#ifndef YY_YY_GRAMMAR_H_INCLUDED
# define YY_YY_GRAMMAR_H_INCLUDED
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
    ASSIGN = 260,
    LESS_THAN_OR_EQUAL = 261,
    GREATER_THAN_OR_EQUAL = 262,
    EQUIVALENT = 263,
    IS_NOT_EQUAL = 264,
    LESS_THAN = 265,
    GREATER_THAN = 266,
    OR = 267,
    AND = 268,
    MINUS = 269,
    PLUS = 270,
    DIVIDE = 271,
    TIMES = 272,
    NEGATE = 273,
    DOT = 274,
    OPEN_SQUARE = 275,
    CLOSE_SQUARE = 276,
    OPEN_PARENTHESIS = 277,
    CLOSE_PARENTHESIS = 278,
    OPEN_BRACE = 279,
    CLOSE_BRACE = 280,
    SQUARE_PAIR = 281,
    KEYWORD_WHILE = 282,
    KEYWORD_IF = 283,
    KEYWORD_ELSE = 284,
    KEYWORD_THIS = 285,
    KEYWORD_CLASS = 286,
    KEYWORD_EXTENDS = 287,
    KEYWORD_NEW = 288,
    KEYWORD_RETURN = 289,
    KEYWORD_INT = 290,
    KEYWORD_BOOL = 291,
    KEYWORD_VOID = 292,
    KEYWORD_TRUE = 293,
    KEYWORD_FALSE = 294,
    INTEGER = 295,
    ID = 296,
    UNKOWN = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "grammar.y"

	int val;
    char *id;

	ASTNode* node;
    ASTNode_Actuals* actual;

#line 108 "grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (Parser *parser);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */
