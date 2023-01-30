/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
    #include "parser.h"
    #define YYERROR_VERBOSE

#line 78 "grammar.c"

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

#include "grammar.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_KEYWORD_NEW = 5,                /* KEYWORD_NEW  */
  YYSYMBOL_KEYWORD_RETURN = 6,             /* KEYWORD_RETURN  */
  YYSYMBOL_OPEN_SQUARE = 7,                /* OPEN_SQUARE  */
  YYSYMBOL_CLOSE_SQUARE = 8,               /* CLOSE_SQUARE  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL = 10,        /* LESS_THAN_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL = 11,     /* GREATER_THAN_OR_EQUAL  */
  YYSYMBOL_EQUIVALENT = 12,                /* EQUIVALENT  */
  YYSYMBOL_IS_NOT_EQUAL = 13,              /* IS_NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 14,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 15,              /* GREATER_THAN  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_DIVIDE = 20,                    /* DIVIDE  */
  YYSYMBOL_TIMES = 21,                     /* TIMES  */
  YYSYMBOL_NEGATE = 22,                    /* NEGATE  */
  YYSYMBOL_DOT = 23,                       /* DOT  */
  YYSYMBOL_OPEN_PARENTHESIS = 24,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_CLOSE_PARENTHESIS = 25,         /* CLOSE_PARENTHESIS  */
  YYSYMBOL_OPEN_BRACE = 26,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 27,               /* CLOSE_BRACE  */
  YYSYMBOL_SQUARE_PAIR = 28,               /* SQUARE_PAIR  */
  YYSYMBOL_KEYWORD_WHILE = 29,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_IF = 30,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 31,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_THIS = 32,              /* KEYWORD_THIS  */
  YYSYMBOL_KEYWORD_CLASS = 33,             /* KEYWORD_CLASS  */
  YYSYMBOL_KEYWORD_EXTENDS = 34,           /* KEYWORD_EXTENDS  */
  YYSYMBOL_KEYWORD_INT = 35,               /* KEYWORD_INT  */
  YYSYMBOL_KEYWORD_BOOL = 36,              /* KEYWORD_BOOL  */
  YYSYMBOL_KEYWORD_VOID = 37,              /* KEYWORD_VOID  */
  YYSYMBOL_KEYWORD_TRUE = 38,              /* KEYWORD_TRUE  */
  YYSYMBOL_KEYWORD_FALSE = 39,             /* KEYWORD_FALSE  */
  YYSYMBOL_INTEGER = 40,                   /* INTEGER  */
  YYSYMBOL_ID = 41,                        /* ID  */
  YYSYMBOL_UNKOWN = 42,                    /* UNKOWN  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_root = 44,                      /* root  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_statement_klein = 46,           /* statement_klein  */
  YYSYMBOL_actuals = 47,                   /* actuals  */
  YYSYMBOL_actuals_optional = 48,          /* actuals_optional  */
  YYSYMBOL_expr = 49,                      /* expr  */
  YYSYMBOL_lvalue = 50                     /* lvalue  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 22 "grammar.y"

    int yyerror(Parser *p, const char *s);
    int yylex(YYSTYPE*);

#line 168 "grammar.c"

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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   101,   101,   104,   106,   107,   108,   109,   111,   112,
     113,   114,   116,   118,   119,   121,   122,   124,   125,   128,
     129,   132,   133,   136,   137,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   154,   155,
     157,   159,   160,   162,   163,   164,   166,   167,   168,   170,
     171,   172,   174,   177,   178,   180,   182,   183,   185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "KEYWORD_NEW", "KEYWORD_RETURN", "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN",
  "LESS_THAN_OR_EQUAL", "GREATER_THAN_OR_EQUAL", "EQUIVALENT",
  "IS_NOT_EQUAL", "LESS_THAN", "GREATER_THAN", "OR", "AND", "MINUS",
  "PLUS", "DIVIDE", "TIMES", "NEGATE", "DOT", "OPEN_PARENTHESIS",
  "CLOSE_PARENTHESIS", "OPEN_BRACE", "CLOSE_BRACE", "SQUARE_PAIR",
  "KEYWORD_WHILE", "KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_THIS",
  "KEYWORD_CLASS", "KEYWORD_EXTENDS", "KEYWORD_INT", "KEYWORD_BOOL",
  "KEYWORD_VOID", "KEYWORD_TRUE", "KEYWORD_FALSE", "INTEGER", "ID",
  "UNKOWN", "$accept", "root", "statement", "statement_klein", "actuals",
  "actuals_optional", "expr", "lvalue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,   -67,    16,     1,     1,     1,     1,   115,   -23,   -15,
     -67,   -17,     8,     9,   -67,   -67,   -67,   -20,    30,   -67,
      72,    20,     3,     6,     7,    -2,    -4,   154,     5,    87,
     -67,    84,   115,    11,     1,     1,    14,    45,    17,    70,
      36,    76,     1,    69,   113,   -67,   -67,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    89,     1,   121,     1,   124,     1,   125,     1,     1,
     128,   -67,   -67,   -67,   -67,   203,   219,   133,   -67,   135,
     -67,   143,   -67,   118,   191,   145,   -67,   359,   370,   380,
     389,   397,   404,   106,   140,    87,    24,   141,   -67,   235,
     173,   139,   249,     1,   263,     1,   277,     1,   291,   152,
       1,   115,   115,   -67,   -67,   -67,   -67,     1,   -67,   -67,
     -67,   -67,     1,   -67,   305,   -67,   319,   -67,   333,   -67,
     -67,   347,   -67,   147,   191,   155,   -67,   -67,   -67,   -67,
     115,   -67,   -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,     0,     0,     0,     0,     0,    20,     0,     0,
      58,     0,     0,     0,    41,    42,    40,    53,     0,     2,
       0,    52,     0,     0,     0,     0,    53,     0,    52,    38,
      39,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    17,    29,    19,    16,     0,     0,     0,     4,     0,
       5,     0,     6,     0,    24,     0,     7,    34,    36,    32,
      33,    35,    37,    31,    30,    28,    27,    26,    25,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    54,     0,    21,    11,
      55,    12,    22,    43,     0,    44,     0,    45,     0,    50,
      49,     0,    15,    13,    24,     0,    46,    47,    48,    51,
       0,    23,    57,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,     2,   117,   -66,    47,    12,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    18,    32,    33,    83,   118,    20,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    34,    19,   109,    42,    68,     2,    21,    43,    35,
      62,    36,    59,    64,    66,    27,    29,    30,    31,     4,
      42,    44,    69,     5,    37,     6,    70,    59,    61,    60,
      45,    63,    21,    10,    65,    67,    38,    40,    74,    14,
      15,    16,    26,    61,    57,    58,    75,    76,    78,    39,
      41,    22,    23,    24,    84,    77,   135,    25,    79,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    80,   102,    46,   104,    81,   106,    82,
     108,    84,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    56,    57,    58,    72,
      85,    21,    21,   132,   133,   124,    86,   126,     1,   128,
       2,     3,   131,    54,    55,    56,    57,    58,   103,   134,
     101,   105,   107,     4,    84,   110,   113,     5,   114,     6,
      21,     7,   143,   116,     8,     9,   115,    10,   119,    73,
      11,    12,    13,    14,    15,    16,    17,    71,    55,    56,
      57,    58,    58,   122,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   121,   130,   140,     0,
     142,   141,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   117,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,   111,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,   120,   112,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   123,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   125,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   127,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   129,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   136,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   137,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   138,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   139,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    52,    53,    54,    55,    56,    57,    58,    -1,
      53,    54,    55,    56,    57,    58
};

static const yytype_int16 yycheck[] =
{
       0,    24,     0,    69,    24,     7,     5,     7,    28,    24,
       7,    28,     7,     7,     7,     3,     4,     5,     6,    18,
      24,    41,    24,    22,    41,    24,    28,     7,    23,     9,
       0,    28,    32,    32,    28,    28,    28,    28,    27,    38,
      39,    40,    41,    23,    20,    21,    34,    35,     3,    41,
      41,    35,    36,    37,    42,    41,   122,    41,    41,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     3,    62,     3,    64,    41,    66,     3,
      68,    69,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    19,    20,    21,    25,
      41,   111,   112,   111,   112,   103,     3,   105,     3,   107,
       5,     6,   110,    17,    18,    19,    20,    21,     7,   117,
      41,     7,     7,    18,   122,     7,     3,    22,     3,    24,
     140,    26,   140,    25,    29,    30,     3,    32,     3,    32,
      35,    36,    37,    38,    39,    40,    41,     3,    18,    19,
      20,    21,    21,    24,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,    25,    31,    -1,
      25,   134,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    25,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,     8,    25,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    14,    15,    16,    17,    18,    19,    20,    21,    15,
      16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    18,    22,    24,    26,    29,    30,
      32,    35,    36,    37,    38,    39,    40,    41,    44,    45,
      49,    50,    35,    36,    37,    41,    41,    49,    50,    49,
      49,    49,    45,    46,    24,    24,    28,    41,    28,    41,
      28,    41,    24,    28,    41,     0,     3,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
       9,    23,     7,    28,     7,    28,     7,    28,     7,    24,
      28,     3,    25,    46,    27,    49,    49,    41,     3,    41,
       3,    41,     3,    47,    49,    41,     3,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    41,    49,     7,    49,     7,    49,     7,    49,    47,
       7,    25,    25,     3,     3,     3,    25,     4,    48,     3,
       8,     3,    24,     8,    49,     8,    49,     8,    49,     8,
      25,    49,    45,    45,    49,    47,     8,     8,     8,     8,
      31,    48,    25,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     5,     7,     5,     3,     3,     1,     2,
       0,     2,     0,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     5,     5,     5,     6,     6,     6,     5,
       5,     6,     1,     1,     4,     4,     3,     6,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (parser, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parser); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Parser *parser)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parser);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Parser *parser)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parser);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, Parser *parser)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parser); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, Parser *parser)
{
  YY_USE (yyvaluep);
  YY_USE (parser);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (Parser *parser)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* root: statement  */
#line 101 "grammar.y"
                { parser->ast.root = std::make_shared<ASTNode_Root>((yyvsp[0].statement)); }
#line 1270 "grammar.c"
    break;

  case 3: /* statement: expr SEMICOLON  */
#line 104 "grammar.y"
                   { (yyval.statement) = std::make_shared<ASTNode_Statement_ExprOnly>((yyvsp[-1].expr)); }
#line 1276 "grammar.c"
    break;

  case 4: /* statement: KEYWORD_INT ID SEMICOLON  */
#line 106 "grammar.y"
                               { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Int>((yyvsp[-1].id)); }
#line 1282 "grammar.c"
    break;

  case 5: /* statement: KEYWORD_BOOL ID SEMICOLON  */
#line 107 "grammar.y"
                                { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Bool>((yyvsp[-1].id)); }
#line 1288 "grammar.c"
    break;

  case 6: /* statement: KEYWORD_VOID ID SEMICOLON  */
#line 108 "grammar.y"
                                { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Void>((yyvsp[-1].id)); }
#line 1294 "grammar.c"
    break;

  case 7: /* statement: ID ID SEMICOLON  */
#line 109 "grammar.y"
                      { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Custom>((yyvsp[-2].id), (yyvsp[-1].id)); }
#line 1300 "grammar.c"
    break;

  case 8: /* statement: KEYWORD_INT SQUARE_PAIR ID SEMICOLON  */
#line 111 "grammar.y"
                                           { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Int_Array>((yyvsp[-1].id)); }
#line 1306 "grammar.c"
    break;

  case 9: /* statement: KEYWORD_BOOL SQUARE_PAIR ID SEMICOLON  */
#line 112 "grammar.y"
                                            { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Bool_Array>((yyvsp[-1].id)); }
#line 1312 "grammar.c"
    break;

  case 10: /* statement: KEYWORD_VOID SQUARE_PAIR ID SEMICOLON  */
#line 113 "grammar.y"
                                            { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Void_Array>((yyvsp[-1].id)); }
#line 1318 "grammar.c"
    break;

  case 11: /* statement: ID SQUARE_PAIR ID SEMICOLON  */
#line 114 "grammar.y"
                                  { (yyval.statement) = std::make_shared<ASTNode_Statement_VariableDeclaration_Custom_Array>((yyvsp[-3].id), (yyvsp[-1].id)); }
#line 1324 "grammar.c"
    break;

  case 12: /* statement: lvalue ASSIGN expr SEMICOLON  */
#line 116 "grammar.y"
                                   { (yyval.statement) = std::make_shared<ASTNode_Statement_Assignment>((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1330 "grammar.c"
    break;

  case 13: /* statement: KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement  */
#line 118 "grammar.y"
                                                                   { (yyval.statement) = std::make_shared<ASTNode_Statement_If>((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1336 "grammar.c"
    break;

  case 14: /* statement: KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement KEYWORD_ELSE statement  */
#line 119 "grammar.y"
                                                                                          { (yyval.statement) = std::make_shared<ASTNode_Statement_IfElse>((yyvsp[-4].expr), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1342 "grammar.c"
    break;

  case 15: /* statement: KEYWORD_WHILE OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement  */
#line 121 "grammar.y"
                                                                      { (yyval.statement) = std::make_shared<ASTNode_Statement_While>((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1348 "grammar.c"
    break;

  case 16: /* statement: OPEN_BRACE statement_klein CLOSE_BRACE  */
#line 122 "grammar.y"
                                             { (yyval.statement) = (yyvsp[-1].body); }
#line 1354 "grammar.c"
    break;

  case 17: /* statement: KEYWORD_RETURN expr SEMICOLON  */
#line 124 "grammar.y"
                                    { (yyval.statement) = std::make_shared<ASTNode_Statement_Return>((yyvsp[-1].expr)); }
#line 1360 "grammar.c"
    break;

  case 18: /* statement: SEMICOLON  */
#line 125 "grammar.y"
                { (yyval.statement) = std::make_shared<ASTNode_Statement_Empty>(); }
#line 1366 "grammar.c"
    break;

  case 19: /* statement_klein: statement statement_klein  */
#line 128 "grammar.y"
                              { (yyval.body) = (yyvsp[0].body); (yyval.body)->AddStatement((yyvsp[-1].statement)); }
#line 1372 "grammar.c"
    break;

  case 20: /* statement_klein: %empty  */
#line 129 "grammar.y"
             { (yyval.body) = std::make_shared<ASTNode_Statement_Body>(); }
#line 1378 "grammar.c"
    break;

  case 21: /* actuals: expr actuals_optional  */
#line 132 "grammar.y"
                          { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1384 "grammar.c"
    break;

  case 22: /* actuals: %empty  */
#line 133 "grammar.y"
             { (yyval.actual) = std::make_shared<ASTNode_Actuals>(); }
#line 1390 "grammar.c"
    break;

  case 23: /* actuals_optional: COMMA expr actuals_optional  */
#line 136 "grammar.y"
                                { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1396 "grammar.c"
    break;

  case 24: /* actuals_optional: %empty  */
#line 137 "grammar.y"
             { (yyval.actual) = std::make_shared<ASTNode_Actuals>(); }
#line 1402 "grammar.c"
    break;

  case 25: /* expr: expr TIMES expr  */
#line 140 "grammar.y"
                    { (yyval.expr) = std::make_shared<ASTNode_Expr_Times>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1408 "grammar.c"
    break;

  case 26: /* expr: expr DIVIDE expr  */
#line 141 "grammar.y"
                       { (yyval.expr) = std::make_shared<ASTNode_Expr_Divide>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1414 "grammar.c"
    break;

  case 27: /* expr: expr PLUS expr  */
#line 142 "grammar.y"
                     { (yyval.expr) = std::make_shared<ASTNode_Expr_Plus>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1420 "grammar.c"
    break;

  case 28: /* expr: expr MINUS expr  */
#line 143 "grammar.y"
                      { (yyval.expr) = std::make_shared<ASTNode_Expr_Minus>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1426 "grammar.c"
    break;

  case 29: /* expr: OPEN_PARENTHESIS expr CLOSE_PARENTHESIS  */
#line 144 "grammar.y"
                                              { (yyval.expr) = std::make_shared<ASTNode_Expr_Parenthesis>((yyvsp[-1].expr)); }
#line 1432 "grammar.c"
    break;

  case 30: /* expr: expr AND expr  */
#line 145 "grammar.y"
                    { (yyval.expr) = std::make_shared<ASTNode_Expr_And>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1438 "grammar.c"
    break;

  case 31: /* expr: expr OR expr  */
#line 146 "grammar.y"
                   { (yyval.expr) = std::make_shared<ASTNode_Expr_Or>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1444 "grammar.c"
    break;

  case 32: /* expr: expr EQUIVALENT expr  */
#line 147 "grammar.y"
                           { (yyval.expr) = std::make_shared<ASTNode_Expr_Equivalent>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1450 "grammar.c"
    break;

  case 33: /* expr: expr IS_NOT_EQUAL expr  */
#line 148 "grammar.y"
                             { (yyval.expr) = std::make_shared<ASTNode_Expr_IsNotEqual>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1456 "grammar.c"
    break;

  case 34: /* expr: expr LESS_THAN_OR_EQUAL expr  */
#line 149 "grammar.y"
                                   { (yyval.expr) = std::make_shared<ASTNode_Expr_LessThanOrEqual>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1462 "grammar.c"
    break;

  case 35: /* expr: expr LESS_THAN expr  */
#line 150 "grammar.y"
                          { (yyval.expr) = std::make_shared<ASTNode_Expr_LessThan>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1468 "grammar.c"
    break;

  case 36: /* expr: expr GREATER_THAN_OR_EQUAL expr  */
#line 151 "grammar.y"
                                      { (yyval.expr) = std::make_shared<ASTNode_Expr_GreaterThanOrEqual>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1474 "grammar.c"
    break;

  case 37: /* expr: expr GREATER_THAN expr  */
#line 152 "grammar.y"
                             { (yyval.expr) = std::make_shared<ASTNode_Expr_GreaterThan>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1480 "grammar.c"
    break;

  case 38: /* expr: MINUS expr  */
#line 154 "grammar.y"
                 { (yyval.expr) = std::make_shared<ASTNode_Expr_UnaryMinus>((yyvsp[0].expr)); }
#line 1486 "grammar.c"
    break;

  case 39: /* expr: NEGATE expr  */
#line 155 "grammar.y"
                  { (yyval.expr) = std::make_shared<ASTNode_Expr_BooleanNegate>((yyvsp[0].expr)); }
#line 1492 "grammar.c"
    break;

  case 40: /* expr: INTEGER  */
#line 157 "grammar.y"
              { (yyval.expr) = std::make_shared<ASTNode_Expr_Integer>((yyvsp[0].val)); }
#line 1498 "grammar.c"
    break;

  case 41: /* expr: KEYWORD_TRUE  */
#line 159 "grammar.y"
                   { (yyval.expr) = std::make_shared<ASTNode_Expr_Boolean>((yyvsp[0].val)); }
#line 1504 "grammar.c"
    break;

  case 42: /* expr: KEYWORD_FALSE  */
#line 160 "grammar.y"
                    { (yyval.expr) = std::make_shared<ASTNode_Expr_Boolean>((yyvsp[0].val)); }
#line 1510 "grammar.c"
    break;

  case 43: /* expr: KEYWORD_NEW KEYWORD_INT OPEN_SQUARE expr CLOSE_SQUARE  */
#line 162 "grammar.y"
                                                            { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_Int>((yyvsp[-1].expr)); }
#line 1516 "grammar.c"
    break;

  case 44: /* expr: KEYWORD_NEW KEYWORD_BOOL OPEN_SQUARE expr CLOSE_SQUARE  */
#line 163 "grammar.y"
                                                             { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_Bool>((yyvsp[-1].expr)); }
#line 1522 "grammar.c"
    break;

  case 45: /* expr: KEYWORD_NEW KEYWORD_VOID OPEN_SQUARE expr CLOSE_SQUARE  */
#line 164 "grammar.y"
                                                             { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_Void>((yyvsp[-1].expr)); }
#line 1528 "grammar.c"
    break;

  case 46: /* expr: KEYWORD_NEW KEYWORD_INT SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE  */
#line 166 "grammar.y"
                                                                        { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_IntArray>((yyvsp[-1].expr)); }
#line 1534 "grammar.c"
    break;

  case 47: /* expr: KEYWORD_NEW KEYWORD_BOOL SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE  */
#line 167 "grammar.y"
                                                                         { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_BoolArray>((yyvsp[-1].expr)); }
#line 1540 "grammar.c"
    break;

  case 48: /* expr: KEYWORD_NEW KEYWORD_VOID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE  */
#line 168 "grammar.y"
                                                                         { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_VoidArray>((yyvsp[-1].expr)); }
#line 1546 "grammar.c"
    break;

  case 49: /* expr: KEYWORD_NEW ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 170 "grammar.y"
                                                                { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Obj>((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1552 "grammar.c"
    break;

  case 50: /* expr: KEYWORD_NEW ID OPEN_SQUARE expr CLOSE_SQUARE  */
#line 171 "grammar.y"
                                                   { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_Custom>((yyvsp[-1].expr), (yyvsp[-3].id)); }
#line 1558 "grammar.c"
    break;

  case 51: /* expr: KEYWORD_NEW ID SQUARE_PAIR OPEN_SQUARE expr CLOSE_SQUARE  */
#line 172 "grammar.y"
                                                               { (yyval.expr) = std::make_shared<ASTNode_Expr_New_Array_CustomArray>((yyvsp[-1].expr), (yyvsp[-4].id)); }
#line 1564 "grammar.c"
    break;

  case 52: /* expr: lvalue  */
#line 174 "grammar.y"
             { (yyval.expr) = (yyvsp[0].lvalue); }
#line 1570 "grammar.c"
    break;

  case 53: /* lvalue: ID  */
#line 177 "grammar.y"
       { (yyval.lvalue) = std::make_shared<ASTNode_LValue_ID>((yyvsp[0].id)); }
#line 1576 "grammar.c"
    break;

  case 54: /* lvalue: ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 178 "grammar.y"
                                                    { (yyval.lvalue) = std::make_shared<ASTNode_LValue_MethodCall>((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1582 "grammar.c"
    break;

  case 55: /* lvalue: lvalue OPEN_SQUARE expr CLOSE_SQUARE  */
#line 180 "grammar.y"
                                           { (yyval.lvalue) = std::make_shared<ASTNode_LValue_Array>((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1588 "grammar.c"
    break;

  case 56: /* lvalue: lvalue DOT ID  */
#line 182 "grammar.y"
                    { (yyval.lvalue) = std::make_shared<ASTNode_LValue_Obj_Access>((yyvsp[-2].lvalue), (yyvsp[0].id)); }
#line 1594 "grammar.c"
    break;

  case 57: /* lvalue: lvalue DOT ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 183 "grammar.y"
                                                               { (yyval.lvalue) = std::make_shared<ASTNode_LValue_Obj_MethodCall> ((yyvsp[-5].lvalue), (yyvsp[-3].id), (yyvsp[-1].actual)); }
#line 1600 "grammar.c"
    break;

  case 58: /* lvalue: KEYWORD_THIS  */
#line 185 "grammar.y"
                   { (yyval.lvalue) = std::make_shared<ASTNode_LValue_This>(); }
#line 1606 "grammar.c"
    break;


#line 1610 "grammar.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (parser, YY_("syntax error"));
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
                      yytoken, &yylval, parser);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parser, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parser);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 187 "grammar.y"

