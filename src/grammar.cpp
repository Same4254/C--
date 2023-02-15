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
    #include "../include/Driver.hpp"
    #define YYERROR_VERBOSE

#line 78 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"

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
  YYSYMBOL_class_list = 44,                /* class_list  */
  YYSYMBOL_class_klein = 45,               /* class_klein  */
  YYSYMBOL_class_declaration = 46,         /* class_declaration  */
  YYSYMBOL_member_declaration = 47,        /* member_declaration  */
  YYSYMBOL_member_declaration_klein = 48,  /* member_declaration_klein  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_statement_klein = 50,           /* statement_klein  */
  YYSYMBOL_actuals = 51,                   /* actuals  */
  YYSYMBOL_actuals_optional = 52,          /* actuals_optional  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_lvalue = 54,                    /* lvalue  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_formal = 56,                    /* formal  */
  YYSYMBOL_formals_list = 57,              /* formals_list  */
  YYSYMBOL_formals_optional = 58           /* formals_optional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 32 "grammar.y"

    int yyerror(Driver &driver, const char *s);
    int yylex(YYSTYPE*);

#line 176 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

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
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   128,   129,   132,   133,   136,   137,   138,
     141,   142,   145,   147,   163,   165,   166,   168,   169,   171,
     172,   175,   176,   179,   180,   183,   184,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     201,   202,   204,   206,   207,   209,   224,   226,   229,   230,
     232,   234,   235,   237,   240,   241,   242,   243,   245,   246,
     247,   248,   252,   255,   256,   259,   260
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
  "UNKOWN", "$accept", "class_list", "class_klein", "class_declaration",
  "member_declaration", "member_declaration_klein", "statement",
  "statement_klein", "actuals", "actuals_optional", "expr", "lvalue",
  "type", "formal", "formals_list", "formals_optional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -14,    32,   -20,    -9,  -109,  -109,   -20,    24,    13,
    -109,    28,    36,    38,   -12,    24,    42,    34,    50,  -109,
    -109,  -109,   290,  -109,  -109,    87,     2,    24,    64,    58,
      89,    82,  -109,  -109,   290,    81,  -109,   290,  -109,    84,
      86,   109,    89,    65,    88,  -109,  -109,  -109,   293,    91,
      91,    91,    91,    65,   100,   103,  -109,  -109,  -109,  -109,
     -17,    65,    98,   123,    -1,   110,    65,    29,   121,   144,
     142,     8,   146,  -109,   191,   143,    91,    91,    91,  -109,
    -109,  -109,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,   128,   181,   158,    91,
      91,  -109,  -109,  -109,   207,   223,   162,   179,   265,   276,
     286,   295,   303,   101,   129,    60,   146,    52,   165,  -109,
     239,   161,   164,  -109,  -109,   188,   253,    65,    65,  -109,
      91,  -109,  -109,  -109,    91,  -109,  -109,  -109,   183,   179,
     190,    65,  -109,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     4,    11,     0,
       3,    54,    55,    56,    57,    11,     0,     0,     0,    58,
      59,    60,    64,    61,    10,     0,     0,    11,    57,     0,
      66,     0,     5,     7,    64,     0,    62,     0,    63,     0,
       0,     0,    66,    22,     0,     6,    65,    20,     0,     0,
       0,     0,     0,    22,     0,     0,    53,    43,    44,    42,
      48,    22,     0,     0,    47,     0,    22,    57,     0,    48,
       0,    47,    40,    41,     0,     0,     0,     0,    24,    21,
       9,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,    19,    31,    18,     0,     0,     0,    26,    36,    38,
      34,    35,    37,    39,    33,    32,    30,    29,    28,    27,
       0,     0,    51,    13,     8,     0,     0,     0,     0,    49,
       0,    23,    50,    14,    24,    45,    46,    17,    15,    26,
       0,     0,    25,    52,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   222,   230,  -109,    -6,  -108,    -3,   -85,    92,
     -48,   -43,    40,   208,   212,   220
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,     7,    15,    16,    61,    62,   106,   131,
      63,    71,    65,    30,    31,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    70,    72,    73,    74,    33,    94,    78,    95,    24,
      64,    23,    22,     1,   125,    94,    23,     8,    64,   137,
     138,    35,    96,    64,   -57,     9,    34,     4,   104,   105,
     107,    96,     5,   144,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    17,   140,
      75,   107,   126,    99,    18,    17,    19,    23,    79,    11,
      12,    13,    29,    98,    20,    14,    21,    17,    47,    25,
      48,    49,    92,    93,    29,    26,    27,    29,    90,    91,
      92,    93,   139,    50,    64,    64,   107,    51,    68,    52,
      32,    53,    23,    37,    54,    55,    48,    56,    64,    36,
      11,    12,    13,    57,    58,    59,    60,    39,    41,    50,
      43,    44,    45,    51,    66,    52,   -58,    88,    89,    90,
      91,    92,    93,    56,    76,    80,    81,    77,   100,    57,
      58,    59,    69,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   101,    89,    90,    91,    92,
      93,    97,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   133,    91,    92,    93,    78,   122,
     103,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   130,   123,   124,    93,   129,   134,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   135,   141,   143,   102,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    10,
       3,   142,   127,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    42,    40,   132,   128,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   136,    46,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   -58,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,   -58,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   -58,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   -58,    86,
      87,    88,    89,    90,    91,    92,    93,   -58,    87,    88,
      89,    90,    91,    92,    93,    11,    12,    13,    11,    12,
      13,    28,     0,     0,    67
};

static const yytype_int16 yycheck[] =
{
      43,    49,    50,    51,    52,     3,     7,    24,     9,    15,
      53,    28,    24,    33,    99,     7,    28,    26,    61,   127,
     128,    27,    23,    66,    41,    34,    24,    41,    76,    77,
      78,    23,     0,   141,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     8,   134,
      53,    99,   100,    24,    41,    15,    28,    28,    61,    35,
      36,    37,    22,    66,    28,    41,    28,    27,     3,    27,
       5,     6,    20,    21,    34,    41,    26,    37,    18,    19,
      20,    21,   130,    18,   127,   128,   134,    22,    48,    24,
       3,    26,    28,     4,    29,    30,     5,    32,   141,    41,
      35,    36,    37,    38,    39,    40,    41,    25,    27,    18,
      26,    25,     3,    22,    26,    24,    15,    16,    17,    18,
      19,    20,    21,    32,    24,    27,     3,    24,     7,    38,
      39,    40,    41,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     3,    17,    18,    19,    20,
      21,    41,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     3,    19,    20,    21,    24,    41,
      27,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     4,     3,    27,    21,    25,    24,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    25,    31,    25,    25,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
       0,   139,    25,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    37,    34,     8,    25,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     8,    42,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    14,    15,    16,
      17,    18,    19,    20,    21,    35,    36,    37,    35,    36,
      37,    41,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    44,    46,    41,     0,    45,    46,    26,    34,
      45,    35,    36,    37,    41,    47,    48,    55,    41,    28,
      28,    28,    24,    28,    48,    27,    41,    26,    41,    55,
      56,    57,     3,     3,    24,    48,    41,     4,    58,    25,
      57,    27,    56,    26,    25,     3,    58,     3,     5,     6,
      18,    22,    24,    26,    29,    30,    32,    38,    39,    40,
      41,    49,    50,    53,    54,    55,    26,    41,    55,    41,
      53,    54,    53,    53,    53,    50,    24,    24,    24,    50,
      27,     3,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     7,     9,    23,    41,    50,    24,
       7,     3,    25,    27,    53,    53,    51,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    41,     3,    27,    51,    53,    25,    25,    25,
       4,    52,     8,     3,    24,    25,     8,    49,    49,    53,
      51,    31,    52,    25,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     8,     3,     8,     7,
       2,     0,     2,     3,     4,     5,     7,     5,     3,     3,
       1,     2,     0,     2,     0,     3,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     5,     5,     1,     1,     4,
       4,     3,     6,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     3,     0
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
        yyerror (driver, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, driver); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Driver &driver)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (driver);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Driver &driver)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, driver);
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
                 int yyrule, Driver &driver)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], driver);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, Driver &driver)
{
  YY_USE (yyvaluep);
  YY_USE (driver);
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
yyparse (Driver &driver)
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
  case 2: /* class_list: class_declaration class_klein  */
#line 125 "grammar.y"
                                  { driver.ast.root.AddClass((yyvsp[-1].clazz)); }
#line 1267 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 3: /* class_klein: class_declaration class_klein  */
#line 128 "grammar.y"
                                  { driver.ast.root.AddClass((yyvsp[-1].clazz)); }
#line 1273 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 5: /* class_declaration: KEYWORD_CLASS ID OPEN_BRACE member_declaration_klein CLOSE_BRACE SEMICOLON  */
#line 132 "grammar.y"
                                                                               { (yyval.clazz) = new ASTNode_Class((yyvsp[-4].id), (yyvsp[-2].member_declaration_list)); }
#line 1279 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 6: /* class_declaration: KEYWORD_CLASS ID KEYWORD_EXTENDS ID OPEN_BRACE member_declaration_klein CLOSE_BRACE SEMICOLON  */
#line 133 "grammar.y"
                                                                                                    { (yyval.clazz) = new ASTNode_Class_Child((yyvsp[-6].id), (yyvsp[-4].id), (yyvsp[-2].member_declaration_list)); }
#line 1285 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 7: /* member_declaration: type ID SEMICOLON  */
#line 136 "grammar.y"
                      { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Variable((yyvsp[-2].type), (yyvsp[-1].id)); }
#line 1291 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 8: /* member_declaration: type ID OPEN_PARENTHESIS formals_list CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE  */
#line 137 "grammar.y"
                                                                                                     { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Function((yyvsp[-7].type), (yyvsp[-4].formals), (yyvsp[-6].id), (yyvsp[-1].body)); }
#line 1297 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 9: /* member_declaration: ID OPEN_PARENTHESIS formals_list CLOSE_PARENTHESIS OPEN_BRACE statement_klein CLOSE_BRACE  */
#line 138 "grammar.y"
                                                                                                { (yyval.member_declaration) = new ASTNode_MemberDeclaration_Constructor((yyvsp[-4].formals), (yyvsp[-6].id), (yyvsp[-1].body)); }
#line 1303 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 10: /* member_declaration_klein: member_declaration member_declaration_klein  */
#line 141 "grammar.y"
                                                { (yyval.member_declaration_list) = (yyvsp[0].member_declaration_list); (yyval.member_declaration_list)->AddDeclaration((yyvsp[-1].member_declaration)); }
#line 1309 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 11: /* member_declaration_klein: %empty  */
#line 142 "grammar.y"
             { (yyval.member_declaration_list) = new ASTNode_MemberDeclaration_List(); }
#line 1315 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 12: /* statement: expr SEMICOLON  */
#line 145 "grammar.y"
                   { (yyval.statement) = new ASTNode_Statement_ExprOnly((yyvsp[-1].expr)); }
#line 1321 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 13: /* statement: type ID SEMICOLON  */
#line 147 "grammar.y"
                        { (yyval.statement) = new ASTNode_Statement_VariableDeclaration((yyvsp[-2].type), (yyvsp[-1].id)); }
#line 1327 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 14: /* statement: lvalue ASSIGN expr SEMICOLON  */
#line 163 "grammar.y"
                                   { (yyval.statement) = new ASTNode_Statement_Assignment((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1333 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 15: /* statement: KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement  */
#line 165 "grammar.y"
                                                                   { (yyval.statement) = new ASTNode_Statement_If((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1339 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 16: /* statement: KEYWORD_IF OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement KEYWORD_ELSE statement  */
#line 166 "grammar.y"
                                                                                          { (yyval.statement) = new ASTNode_Statement_IfElse((yyvsp[-4].expr), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1345 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 17: /* statement: KEYWORD_WHILE OPEN_PARENTHESIS expr CLOSE_PARENTHESIS statement  */
#line 168 "grammar.y"
                                                                      { (yyval.statement) = new ASTNode_Statement_While((yyvsp[-2].expr), (yyvsp[0].statement)); }
#line 1351 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 18: /* statement: OPEN_BRACE statement_klein CLOSE_BRACE  */
#line 169 "grammar.y"
                                             { (yyval.statement) = (yyvsp[-1].body); }
#line 1357 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 19: /* statement: KEYWORD_RETURN expr SEMICOLON  */
#line 171 "grammar.y"
                                    { (yyval.statement) = new ASTNode_Statement_Return((yyvsp[-1].expr)); }
#line 1363 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 20: /* statement: SEMICOLON  */
#line 172 "grammar.y"
                { (yyval.statement) = new ASTNode_Statement_Empty(); }
#line 1369 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 21: /* statement_klein: statement statement_klein  */
#line 175 "grammar.y"
                              { (yyval.body) = (yyvsp[0].body); (yyval.body)->AddStatement((yyvsp[-1].statement)); }
#line 1375 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 22: /* statement_klein: %empty  */
#line 176 "grammar.y"
             { (yyval.body) = new ASTNode_Statement_Body(); }
#line 1381 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 23: /* actuals: expr actuals_optional  */
#line 179 "grammar.y"
                          { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1387 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 24: /* actuals: %empty  */
#line 180 "grammar.y"
             { (yyval.actual) = new ASTNode_Actuals(); }
#line 1393 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 25: /* actuals_optional: COMMA expr actuals_optional  */
#line 183 "grammar.y"
                                { (yyval.actual) = (yyvsp[0].actual); (yyval.actual)->AddExpression((yyvsp[-1].expr)); }
#line 1399 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 26: /* actuals_optional: %empty  */
#line 184 "grammar.y"
             { (yyval.actual) = new ASTNode_Actuals(); }
#line 1405 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 27: /* expr: expr TIMES expr  */
#line 187 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_Times((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1411 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 28: /* expr: expr DIVIDE expr  */
#line 188 "grammar.y"
                       { (yyval.expr) = new ASTNode_Expr_Divide((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1417 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 29: /* expr: expr PLUS expr  */
#line 189 "grammar.y"
                     { (yyval.expr) = new ASTNode_Expr_Plus((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1423 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 30: /* expr: expr MINUS expr  */
#line 190 "grammar.y"
                      { (yyval.expr) = new ASTNode_Expr_Minus((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1429 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 31: /* expr: OPEN_PARENTHESIS expr CLOSE_PARENTHESIS  */
#line 191 "grammar.y"
                                              { (yyval.expr) = new ASTNode_Expr_Parenthesis((yyvsp[-1].expr)); }
#line 1435 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 32: /* expr: expr AND expr  */
#line 192 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_And((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1441 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 33: /* expr: expr OR expr  */
#line 193 "grammar.y"
                   { (yyval.expr) = new ASTNode_Expr_Or((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1447 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 34: /* expr: expr EQUIVALENT expr  */
#line 194 "grammar.y"
                           { (yyval.expr) = new ASTNode_Expr_Equivalent((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1453 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 35: /* expr: expr IS_NOT_EQUAL expr  */
#line 195 "grammar.y"
                             { (yyval.expr) = new ASTNode_Expr_IsNotEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1459 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 36: /* expr: expr LESS_THAN_OR_EQUAL expr  */
#line 196 "grammar.y"
                                   { (yyval.expr) = new ASTNode_Expr_LessThanOrEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1465 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 37: /* expr: expr LESS_THAN expr  */
#line 197 "grammar.y"
                          { (yyval.expr) = new ASTNode_Expr_LessThan((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1471 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 38: /* expr: expr GREATER_THAN_OR_EQUAL expr  */
#line 198 "grammar.y"
                                      { (yyval.expr) = new ASTNode_Expr_GreaterThanOrEqual((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1477 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 39: /* expr: expr GREATER_THAN expr  */
#line 199 "grammar.y"
                             { (yyval.expr) = new ASTNode_Expr_GreaterThan((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1483 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 40: /* expr: MINUS expr  */
#line 201 "grammar.y"
                 { (yyval.expr) = new ASTNode_Expr_UnaryMinus((yyvsp[0].expr)); }
#line 1489 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 41: /* expr: NEGATE expr  */
#line 202 "grammar.y"
                  { (yyval.expr) = new ASTNode_Expr_BooleanNegate((yyvsp[0].expr)); }
#line 1495 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 42: /* expr: INTEGER  */
#line 204 "grammar.y"
              { (yyval.expr) = new ASTNode_Expr_Integer((yyvsp[0].val)); }
#line 1501 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 43: /* expr: KEYWORD_TRUE  */
#line 206 "grammar.y"
                   { (yyval.expr) = new ASTNode_Expr_Boolean((yyvsp[0].val)); }
#line 1507 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 44: /* expr: KEYWORD_FALSE  */
#line 207 "grammar.y"
                    { (yyval.expr) = new ASTNode_Expr_Boolean((yyvsp[0].val)); }
#line 1513 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 45: /* expr: KEYWORD_NEW ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 209 "grammar.y"
                                                                { (yyval.expr) = new ASTNode_Expr_New_Obj((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1519 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 46: /* expr: KEYWORD_NEW type OPEN_SQUARE expr CLOSE_SQUARE  */
#line 224 "grammar.y"
                                                     { (yyval.expr) = new ASTNode_Expr_New_Array((yyvsp[-3].type), (yyvsp[-1].expr)); }
#line 1525 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 47: /* expr: lvalue  */
#line 226 "grammar.y"
             { (yyval.expr) = (yyvsp[0].lvalue); }
#line 1531 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 48: /* lvalue: ID  */
#line 229 "grammar.y"
       { (yyval.lvalue) = new ASTNode_LValue_ID((yyvsp[0].id)); }
#line 1537 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 49: /* lvalue: ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 230 "grammar.y"
                                                    { (yyval.lvalue) = new ASTNode_LValue_MethodCall((yyvsp[-1].actual), (yyvsp[-3].id)); }
#line 1543 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 50: /* lvalue: lvalue OPEN_SQUARE expr CLOSE_SQUARE  */
#line 232 "grammar.y"
                                           { (yyval.lvalue) = new ASTNode_LValue_Array((yyvsp[-3].lvalue), (yyvsp[-1].expr)); }
#line 1549 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 51: /* lvalue: lvalue DOT ID  */
#line 234 "grammar.y"
                    { (yyval.lvalue) = new ASTNode_LValue_Obj_Access((yyvsp[-2].lvalue), (yyvsp[0].id)); }
#line 1555 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 52: /* lvalue: lvalue DOT ID OPEN_PARENTHESIS actuals CLOSE_PARENTHESIS  */
#line 235 "grammar.y"
                                                               { (yyval.lvalue) = new ASTNode_LValue_Obj_MethodCall((yyvsp[-5].lvalue), (yyvsp[-3].id), (yyvsp[-1].actual)); }
#line 1561 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 53: /* lvalue: KEYWORD_THIS  */
#line 237 "grammar.y"
                   { (yyval.lvalue) = new ASTNode_LValue_This(); }
#line 1567 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 54: /* type: KEYWORD_INT  */
#line 240 "grammar.y"
                { (yyval.type) = new ASTNode_Type_Int(); }
#line 1573 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 55: /* type: KEYWORD_BOOL  */
#line 241 "grammar.y"
                   { (yyval.type) = new ASTNode_Type_Bool(); }
#line 1579 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 56: /* type: KEYWORD_VOID  */
#line 242 "grammar.y"
                   { (yyval.type) = new ASTNode_Type_Void(); }
#line 1585 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 57: /* type: ID  */
#line 243 "grammar.y"
         { (yyval.type) = new ASTNode_Type_ID((yyvsp[0].id)); }
#line 1591 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 58: /* type: KEYWORD_INT SQUARE_PAIR  */
#line 245 "grammar.y"
                              { (yyval.type) = new ASTNode_Type_Int_Array(); }
#line 1597 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 59: /* type: KEYWORD_BOOL SQUARE_PAIR  */
#line 246 "grammar.y"
                               { (yyval.type) = new ASTNode_Type_Bool_Array(); }
#line 1603 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 60: /* type: KEYWORD_VOID SQUARE_PAIR  */
#line 247 "grammar.y"
                               { (yyval.type) = new ASTNode_Type_Void_Array(); }
#line 1609 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 61: /* type: ID SQUARE_PAIR  */
#line 248 "grammar.y"
                     { (yyval.type) = new ASTNode_Type_ID_Array((yyvsp[-1].id)); }
#line 1615 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 62: /* formal: type ID  */
#line 252 "grammar.y"
            { (yyval.formal) = new ASTNode_Formal((yyvsp[-1].type), (yyvsp[0].id)); }
#line 1621 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 63: /* formals_list: formal formals_optional  */
#line 255 "grammar.y"
                            { (yyval.formals) = (yyvsp[0].formals); (yyval.formals)->AddFormal((yyvsp[-1].formal)); }
#line 1627 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 64: /* formals_list: %empty  */
#line 256 "grammar.y"
             { (yyval.formals) = new ASTNode_Formal_List(); }
#line 1633 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 65: /* formals_optional: COMMA formal formals_optional  */
#line 259 "grammar.y"
                                  { (yyval.formals) = (yyvsp[0].formals); (yyval.formals)->AddFormal((yyvsp[-1].formal)); }
#line 1639 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;

  case 66: /* formals_optional: %empty  */
#line 260 "grammar.y"
             { (yyval.formals) = new ASTNode_Formal_List(); }
#line 1645 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"
    break;


#line 1649 "/home/sam/CodingProjects/Compiler-Assignments/src/grammar.cpp"

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
      yyerror (driver, YY_("syntax error"));
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, driver);
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
  yyerror (driver, YY_("memory exhausted"));
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
                  yytoken, &yylval, driver);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, driver);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 262 "grammar.y"

