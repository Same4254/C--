/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

    #include <math.h>
    #include <stdlib.h>
    #include "../include/Driver.hpp"
    #define YYERROR_VERBOSE

#line 77 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 199 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (Driver &driver);

#endif /* !YY_YY_HOME_SAM_CODINGPROJECTS_COMP_COMPILER_ASSIGNMENTS_SRC_GRAMMAR_H_INCLUDED  */


/* Unqualified %code blocks.  */
#line 32 "grammar.y"

    int yyerror(Driver &driver, const char *s);
    int yylex(YYSTYPE*);

#line 220 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   132,   133,   136,   137,   140,   141,   142,
     145,   146,   149,   151,   167,   169,   170,   172,   173,   175,
     176,   178,   179,   180,   182,   186,   187,   190,   191,   194,
     195,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   212,   213,   215,   217,   218,   220,
     235,   237,   240,   241,   243,   245,   246,   248,   251,   252,
     253,   254,   256,   257,   258,   259,   263,   266,   267,   270,
     271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COMMA", "KEYWORD_NEW",
  "KEYWORD_RETURN", "KEYWORD_PRINT_INT", "KEYWORD_PRINT_BOOL",
  "KEYWORD_PRINT_LN", "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN",
  "LESS_THAN_OR_EQUAL", "GREATER_THAN_OR_EQUAL", "EQUIVALENT",
  "IS_NOT_EQUAL", "LESS_THAN", "GREATER_THAN", "OR", "AND", "MINUS",
  "PLUS", "DIVIDE", "TIMES", "NEGATE", "DOT", "OPEN_PARENTHESIS",
  "CLOSE_PARENTHESIS", "OPEN_BRACE", "CLOSE_BRACE", "SQUARE_PAIR",
  "KEYWORD_WHILE", "KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_THIS",
  "KEYWORD_CLASS", "KEYWORD_EXTENDS", "KEYWORD_INT", "KEYWORD_BOOL",
  "KEYWORD_VOID", "KEYWORD_TRUE", "KEYWORD_FALSE", "INTEGER", "ID",
  "UNKOWN", "$accept", "class_list", "class_klein", "class_declaration",
  "member_declaration", "member_declaration_klein", "statement",
  "statement_klein", "actuals", "actuals_optional", "expr", "lvalue",
  "type", "formal", "formals_list", "formals_optional", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -24,    23,   -27,    28,  -126,  -126,   -27,    29,   -12,
    -126,     8,    30,    41,     3,    29,    36,    37,    45,  -126,
    -126,  -126,    52,  -126,  -126,    77,     0,    29,    58,    39,
      89,    66,  -126,  -126,    52,    75,  -126,    52,  -126,    80,
      87,   122,    89,    79,    98,  -126,  -126,  -126,    63,    35,
     101,   102,   112,   105,   105,   105,    79,   114,   115,  -126,
    -126,  -126,  -126,   -19,    79,    86,   152,    -8,   100,    79,
      44,   135,  -126,   124,   174,     7,   105,   105,   126,   204,
    -126,   229,   177,   105,   105,   105,  -126,  -126,  -126,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   108,   205,   199,   105,   105,  -126,   245,
     261,   251,  -126,  -126,   277,   293,   227,   217,   335,   346,
     356,   162,   139,   182,   113,   201,   204,    40,   232,  -126,
     309,   196,   243,  -126,  -126,   244,   323,   268,   283,  -126,
      79,    79,  -126,   105,  -126,  -126,  -126,   105,  -126,  -126,
    -126,  -126,  -126,   253,   217,   260,    79,  -126,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     4,    11,     0,
       3,    58,    59,    60,    61,    11,     0,     0,     0,    62,
      63,    64,    68,    65,    10,     0,     0,    11,    61,     0,
      70,     0,     5,     7,    68,     0,    66,     0,    67,     0,
       0,     0,    70,    26,     0,     6,    69,    24,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,    57,
      47,    48,    46,    52,    26,     0,     0,    51,     0,    26,
      61,     0,    20,    52,     0,    51,     0,     0,     0,    44,
      45,     0,     0,     0,     0,    28,    25,     9,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    19,     0,
       0,     0,    35,    18,     0,     0,     0,    30,    40,    42,
      38,    39,    41,    43,    37,    36,    34,    33,    32,    31,
       0,     0,    55,    13,     8,     0,     0,     0,     0,    23,
       0,     0,    53,     0,    27,    54,    14,    28,    49,    50,
      21,    22,    17,    15,    30,     0,     0,    29,    56,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   295,   303,  -126,    -5,  -125,   -45,   -92,   150,
     -48,   -43,   116,   281,   285,   339
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    15,    16,    64,    65,   116,   144,
      66,    75,    68,    30,    31,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    74,   101,    33,   102,    79,    80,    81,    85,     1,
      24,    82,    23,    67,   135,   152,   153,   101,   103,    86,
       4,    67,    35,     5,   105,   -61,    67,    34,   109,   110,
      22,   159,    18,   103,    23,   114,   115,   117,    72,    19,
      48,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   155,    53,     8,   117,   136,
      54,    20,    55,    99,   100,     9,    25,    11,    12,    13,
      59,   106,    21,    14,    27,    23,    60,    61,    62,    73,
      32,    26,    47,    36,    48,    49,    50,    51,    52,    23,
      11,    12,    13,    37,    39,   154,    28,    67,    67,   117,
      53,    11,    12,    13,    54,    41,    55,    70,    56,    43,
      48,    57,    58,    67,    59,    44,    87,    11,    12,    13,
      60,    61,    62,    63,    17,    45,    53,    69,    76,    77,
      54,    17,    55,    96,    97,    98,    99,   100,    29,    78,
      59,    83,    84,    17,   104,   107,    60,    61,    62,    73,
      29,    85,   132,    29,   111,    88,   -62,    94,    95,    96,
      97,    98,    99,   100,    71,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   108,   -62,    93,
      94,    95,    96,    97,    98,    99,   100,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   146,
     -62,    95,    96,    97,    98,    99,   100,   113,   133,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   143,    97,    98,    99,   100,    98,    99,   100,   134,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   139,   142,   100,   112,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     147,   150,   148,   137,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   151,   156,   158,   138,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    10,     3,   157,   140,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    42,    40,
     145,   141,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   149,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   -62,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     -62,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   -62,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    46
};

static const yytype_int16 yycheck[] =
{
      43,    49,    10,     3,    12,    53,    54,    55,    27,    36,
      15,    56,    31,    56,   106,   140,   141,    10,    26,    64,
      44,    64,    27,     0,    69,    44,    69,    27,    76,    77,
      27,   156,    44,    26,    31,    83,    84,    85,     3,    31,
       5,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   147,    21,    29,   106,   107,
      25,    31,    27,    23,    24,    37,    30,    38,    39,    40,
      35,    27,    31,    44,    29,    31,    41,    42,    43,    44,
       3,    44,     3,    44,     5,     6,     7,     8,     9,    31,
      38,    39,    40,     4,    28,   143,    44,   140,   141,   147,
      21,    38,    39,    40,    25,    30,    27,    44,    29,    29,
       5,    32,    33,   156,    35,    28,    30,    38,    39,    40,
      41,    42,    43,    44,     8,     3,    21,    29,    27,    27,
      25,    15,    27,    20,    21,    22,    23,    24,    22,    27,
      35,    27,    27,    27,    44,    10,    41,    42,    43,    44,
      34,    27,    44,    37,    28,     3,    17,    18,    19,    20,
      21,    22,    23,    24,    48,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     3,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     3,
      18,    19,    20,    21,    22,    23,    24,    30,     3,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     4,    21,    22,    23,    24,    22,    23,    24,    30,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     3,    28,    24,    28,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      27,     3,    28,    28,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     3,    34,    28,    28,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     7,     0,   154,    28,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    37,    34,
      11,    28,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    47,    49,    44,     0,    48,    49,    29,    37,
      48,    38,    39,    40,    44,    50,    51,    58,    44,    31,
      31,    31,    27,    31,    51,    30,    44,    29,    44,    58,
      59,    60,     3,     3,    27,    51,    44,     4,    61,    28,
      60,    30,    59,    29,    28,     3,    61,     3,     5,     6,
       7,     8,     9,    21,    25,    27,    29,    32,    33,    35,
      41,    42,    43,    44,    52,    53,    56,    57,    58,    29,
      44,    58,     3,    44,    56,    57,    27,    27,    27,    56,
      56,    56,    53,    27,    27,    27,    53,    30,     3,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    10,    12,    26,    44,    53,    27,    10,     3,    56,
      56,    28,    28,    30,    56,    56,    54,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    44,     3,    30,    54,    56,    28,    28,     3,
      28,    28,    28,     4,    55,    11,     3,    27,    28,    11,
       3,     3,    52,    52,    56,    54,    34,    55,    28,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    60,    60,    61,
      61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     8,     3,     8,     7,
       2,     0,     2,     3,     4,     5,     7,     5,     3,     3,
       2,     5,     5,     4,     1,     2,     0,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     5,
       5,     1,     1,     4,     4,     3,     6,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     0,     3,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (driver, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, driver); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Driver &driver)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (driver);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Driver &driver)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, driver);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, Driver &driver)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , driver);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, driver); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Driver &driver)
{
  YYUSE (yyvaluep);
  YYUSE (driver);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Driver &driver)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 129 "grammar.y"
                                  { driver.ast.root.AddClass((yyvsp[-1].clazz)); }
#line 1538 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 3:
#line 132 "grammar.y"
                                  { driver.ast.root.AddClass((yyvsp[-1].clazz)); }
#line 1544 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 5:
#line 136 "grammar.y"
                                                                               { (yyval.clazz) = new ASTNode_Class((yyvsp[-4].id), (yyvsp[-2].member_declaration_list)); }
#line 1550 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 6:
#line 137 "grammar.y"
                                                                                                    { (yyval.clazz) = new ASTNode_Class_Child((yyvsp[-6].id), (yyvsp[-4].id), (yyvsp[-2].member_declaration_list)); }
#line 1556 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 7:
#line 140 "grammar.y"
                      { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Variable((yyvsp[-2].type), (yyvsp[-1].id)); }
#line 1562 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 8:
#line 141 "grammar.y"
                                                                                                     { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Function((yyvsp[-7].type), (yyvsp[-4].formals), (yyvsp[-6].id), (yyvsp[-1].body)); }
#line 1568 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 9:
#line 142 "grammar.y"
                                                                                                { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Constructor((yyvsp[-4].formals), (yyvsp[-6].id), (yyvsp[-1].body)); }
#line 1574 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 10:
#line 145 "grammar.y"
                                                { (yyval.member_declaration_list) = (yyvsp[0].member_declaration_list); (yyval.member_declaration_list)->AddDeclaration((yyvsp[-1].member_declaration)); }
#line 1580 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 11:
#line 146 "grammar.y"
             { (yyval.member_declaration_list) = new ASTNode_MemberDeclaration_List(); }
#line 1586 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 12:
#line 149 "grammar.y"
                   { (yyval.statement) = new ASTNode_Statement_ExprOnly((yyvsp[-1].expr)); }
#line 1592 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 13:
#line 151 "grammar.y"
                        { (yyval.statement) = new ASTNode_Statement_VariableDeclaration((yyvsp[-2].type), (yyvsp[-1].id)); }
#line 1598 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 14:
#line 167 "grammar.y"
                                   { (yyval.statement) = new ASTNode_Statement_Assignment((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1604 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 15:
#line 169 "grammar.y"
                                                                   { (yyval.statement) = new ASTNode_Statement_If((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1610 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 16:
#line 170 "grammar.y"
                                                                                          { (yyval.statement) = new ASTNode_Statement_IfElse((yyvsp[-4].expr), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1616 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 17:
#line 172 "grammar.y"
                                                                      { (yyval.statement) = new ASTNode_Statement_While((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1622 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 18:
#line 173 "grammar.y"
                                             { (yyval.statement) = (yyvsp[-1].body); }
#line 1628 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 19:
#line 175 "grammar.y"
                                    { (yyval.statement) = new ASTNode_Statement_Return((yyvsp[-1].expr)); }
#line 1634 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 20:
#line 176 "grammar.y"
                               { (yyval.statement) = new ASTNode_Statement_ReturnVoid(); }
#line 1640 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 21:
#line 178 "grammar.y"
                                                                          { (yyval.statement) = new ASTNode_Statement_Print_Int((yyvsp[-2].expr)); }
#line 1646 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 22:
#line 179 "grammar.y"
                                                                           { (yyval.statement) = new ASTNode_Statement_Print_Bool((yyvsp[-2].expr)); }
#line 1652 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 23:
#line 180 "grammar.y"
                                                                    { (yyval.statement) = new ASTNode_Statement_Print_Line(); }
#line 1658 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 24:
#line 182 "grammar.y"
                { (yyval.statement) = new ASTNode_Statement_Empty(); }
#line 1664 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 25:
#line 186 "grammar.y"
                              { (yyval.body) = (yyvsp[0].body); (yyval.body)->AddStatement((yyvsp[-1].statement)); }
#line 1670 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 26:
#line 187 "grammar.y"
             { (yyval.body) = new ASTNode_Statement_Body(); }
#line 1676 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 27:
#line 190 "grammar.y"
                          { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1682 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 28:
#line 191 "grammar.y"
             { (yyval.actual) = new ASTNode_Actuals(); }
#line 1688 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 29:
#line 194 "grammar.y"
                                { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1694 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 30:
#line 195 "grammar.y"
             { (yyval.actual) = new ASTNode_Actuals(); }
#line 1700 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 31:
#line 198 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_Times((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1706 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 32:
#line 199 "grammar.y"
                       { (yyval.expr) = new ASTNode_Expr_Divide((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1712 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 33:
#line 200 "grammar.y"
                     { (yyval.expr) = new ASTNode_Expr_Plus((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1718 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 34:
#line 201 "grammar.y"
                      { (yyval.expr) = new ASTNode_Expr_Minus((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1724 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 35:
#line 202 "grammar.y"
                                              { (yyval.expr) = new ASTNode_Expr_Parenthesis((yyvsp[-1].expr)); }
#line 1730 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 36:
#line 203 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_And((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1736 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 37:
#line 204 "grammar.y"
                   { (yyval.expr) = new ASTNode_Expr_Or((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1742 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 38:
#line 205 "grammar.y"
                           { (yyval.expr) = new ASTNode_Expr_Equivalent((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1748 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 39:
#line 206 "grammar.y"
                             { (yyval.expr) = new ASTNode_Expr_IsNotEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1754 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 40:
#line 207 "grammar.y"
                                   { (yyval.expr) = new ASTNode_Expr_LessThanOrEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1760 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 41:
#line 208 "grammar.y"
                          { (yyval.expr) = new ASTNode_Expr_LessThan((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1766 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 42:
#line 209 "grammar.y"
                                      { (yyval.expr) = new ASTNode_Expr_GreaterThanOrEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1772 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 43:
#line 210 "grammar.y"
                             { (yyval.expr) = new ASTNode_Expr_GreaterThan((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1778 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 44:
#line 212 "grammar.y"
                 { (yyval.expr) = new ASTNode_Expr_UnaryMinus((yyvsp[0].expr)); }
#line 1784 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 45:
#line 213 "grammar.y"
                  { (yyval.expr) = new ASTNode_Expr_BooleanNegate((yyvsp[0].expr)); }
#line 1790 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 46:
#line 215 "grammar.y"
              { (yyval.expr) = new ASTNode_Expr_Integer((yyvsp[0].val)); }
#line 1796 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 47:
#line 217 "grammar.y"
                   { (yyval.expr) = new ASTNode_Expr_Boolean((yyvsp[0].val)); }
#line 1802 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 48:
#line 218 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_Boolean((yyvsp[0].val)); }
#line 1808 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 49:
#line 220 "grammar.y"
                                                                { (yyval.expr) = new ASTNode_Expr_New_Obj((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1814 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 50:
#line 235 "grammar.y"
                                                     { (yyval.expr) = new ASTNode_Expr_New_Array((yyvsp[-3].type), (yyvsp[-1].expr)); }
#line 1820 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 51:
#line 237 "grammar.y"
             { (yyval.expr) = (yyvsp[0].lvalue); }
#line 1826 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 52:
#line 240 "grammar.y"
       { (yyval.lvalue) = new ASTNode_LValue_ID((yyvsp[0].id)); }
#line 1832 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 53:
#line 241 "grammar.y"
                                                    { (yyval.lvalue) = new ASTNode_LValue_MethodCall((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1838 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 54:
#line 243 "grammar.y"
                                           { (yyval.lvalue) = new ASTNode_LValue_Array((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1844 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 55:
#line 245 "grammar.y"
                    { (yyval.lvalue) = new ASTNode_LValue_Obj_Access((yyvsp[-2].lvalue), (yyvsp[0].id)); }
#line 1850 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 56:
#line 246 "grammar.y"
                                                               { (yyval.lvalue) = new ASTNode_LValue_Obj_MethodCall((yyvsp[-5].lvalue), (yyvsp[-3].id), (yyvsp[-1].actual)); }
#line 1856 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 57:
#line 248 "grammar.y"
                   { (yyval.lvalue) = new ASTNode_LValue_This(); }
#line 1862 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 58:
#line 251 "grammar.y"
                { (yyval.type) = new ASTNode_Type_Int(); }
#line 1868 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 59:
#line 252 "grammar.y"
                   { (yyval.type) = new ASTNode_Type_Bool(); }
#line 1874 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 60:
#line 253 "grammar.y"
                   { (yyval.type) = new ASTNode_Type_Void(); }
#line 1880 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 61:
#line 254 "grammar.y"
         { (yyval.type) = new ASTNode_Type_ID((yyvsp[0].id)); }
#line 1886 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 62:
#line 256 "grammar.y"
                              { (yyval.type) = new ASTNode_Type_Int_Array(); }
#line 1892 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 63:
#line 257 "grammar.y"
                               { (yyval.type) = new ASTNode_Type_Bool_Array(); }
#line 1898 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 64:
#line 258 "grammar.y"
                               { (yyval.type) = new ASTNode_Type_Void_Array(); }
#line 1904 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 65:
#line 259 "grammar.y"
                     { (yyval.type) = new ASTNode_Type_ID_Array((yyvsp[-1].id)); }
#line 1910 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 66:
#line 263 "grammar.y"
            { (yyval.formal) = new ASTNode_Formal((yyvsp[-1].type), (yyvsp[0].id)); }
#line 1916 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 67:
#line 266 "grammar.y"
                            { (yyval.formals) = (yyvsp[0].formals); (yyval.formals)->AddFormal((yyvsp[-1].formal)); }
#line 1922 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 68:
#line 267 "grammar.y"
             { (yyval.formals) = new ASTNode_Formal_List(); }
#line 1928 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 69:
#line 270 "grammar.y"
                                  { (yyval.formals) = (yyvsp[0].formals); (yyval.formals)->AddFormal((yyvsp[-1].formal)); }
#line 1934 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;

  case 70:
#line 271 "grammar.y"
             { (yyval.formals) = new ASTNode_Formal_List(); }
#line 1940 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"
    break;


#line 1944 "/home/sam/CodingProjects/Comp/Compiler-Assignments/src/grammar.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (driver, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (driver, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, driver);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, driver);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (driver, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, driver);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, driver);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 273 "grammar.y"

