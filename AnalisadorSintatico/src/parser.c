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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode*
static char * savedName;
static char * savedName2; /* for use in assignments */
static int savedLineNo;
static int savedLineNo2;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *);


#line 90 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_TIMES = 11,                     /* TIMES  */
  YYSYMBOL_OVER = 12,                      /* OVER  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LET = 14,                       /* LET  */
  YYSYMBOL_BT = 15,                        /* BT  */
  YYSYMBOL_BET = 16,                       /* BET  */
  YYSYMBOL_EQUAL = 17,                     /* EQUAL  */
  YYSYMBOL_DIF = 18,                       /* DIF  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 20,                      /* SEMI  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_NUM = 28,                       /* NUM  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_programa = 32,                  /* programa  */
  YYSYMBOL_declaracao_lista = 33,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 34,                /* declaracao  */
  YYSYMBOL_var_declaracao = 35,            /* var_declaracao  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_38_3 = 38,                      /* $@3  */
  YYSYMBOL_tipo_especificador = 39,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 40,            /* fun_declaracao  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_param_lista = 42,               /* param_lista  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_composto_decl = 44,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 45,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 46,           /* statement_lista  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expressao_decl = 48,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 49,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 50,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 51,              /* retorno_decl  */
  YYSYMBOL_expressao = 52,                 /* expressao  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_simples_expressao = 54,         /* simples_expressao  */
  YYSYMBOL_relacional = 55,                /* relacional  */
  YYSYMBOL_soma_expressao = 56,            /* soma_expressao  */
  YYSYMBOL_soma = 57,                      /* soma  */
  YYSYMBOL_termo = 58,                     /* termo  */
  YYSYMBOL_mult = 59,                      /* mult  */
  YYSYMBOL_fator = 60,                     /* fator  */
  YYSYMBOL_ativacao = 61,                  /* ativacao  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_arg_lista = 63                  /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   95

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    39,    50,    54,    55,    59,    59,    69,
      70,    69,    98,   104,   113,   124,   125,   129,   136,   140,
     146,   155,   164,   176,   182,   194,   200,   201,   202,   203,
     204,   208,   212,   219,   225,   235,   244,   248,   256,   262,
     266,   271,   280,   287,   291,   292,   293,   294,   295,   296,
     300,   307,   311,   312,   316,   323,   327,   328,   332,   333,
     334,   335,   343,   352,   354,   360,   371
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "RETURN", "VOID", "WHILE", "PLUS", "MINUS", "TIMES", "OVER", "LT", "LET",
  "BT", "BET", "EQUAL", "DIF", "ASSIGN", "SEMI", "COMMA", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "NUM", "ID",
  "ERROR", "$accept", "programa", "declaracao_lista", "declaracao",
  "var_declaracao", "$@1", "$@2", "$@3", "tipo_especificador",
  "fun_declaracao", "params", "param_lista", "param", "composto_decl",
  "local_declaracoes", "statement_lista", "statement", "expressao_decl",
  "selecao_decl", "iteracao_decl", "retorno_decl", "expressao", "var",
  "simples_expressao", "relacional", "soma_expressao", "soma", "termo",
  "mult", "fator", "ativacao", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      14,   -92,   -92,     6,    14,   -92,   -92,    -5,   -92,   -92,
     -92,     8,    36,    -4,    42,    38,     2,    44,    48,   -92,
     -92,    31,    46,    45,    14,   -92,    47,   -92,   -92,   -92,
      49,   -92,    14,    53,   -92,    50,     7,   -92,    51,    54,
     -11,    55,   -92,   -21,   -92,   -92,    33,   -92,   -92,   -92,
     -92,   -92,   -92,    58,    61,   -92,    35,    27,   -92,   -92,
     -21,   -92,    62,   -21,    60,   -21,   -21,   -92,   -21,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -21,   -21,   -92,
     -92,   -21,    63,   -92,    64,   -92,   -92,    65,    68,    56,
     -92,   -92,    37,    27,   -92,    34,    34,   -92,   -21,   -92,
      80,   -92,   -92,    34,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,     0,     2,     4,     5,     0,     6,     1,
       3,     7,     0,     0,     0,    13,     0,     0,    15,    18,
       8,     0,    19,     0,     0,    10,     0,    23,    14,    17,
       0,    20,    25,     0,    22,     0,     0,    11,     7,     0,
       0,     0,    32,     0,    21,    61,    40,    27,    24,    26,
      28,    29,    30,     0,    59,    39,    43,    51,    55,    60,
       0,    36,     0,     0,     0,    64,     0,    31,     0,    52,
      53,    45,    44,    46,    47,    48,    49,     0,     0,    56,
      57,     0,     0,    37,     0,    58,    66,     0,    63,     0,
      38,    59,    42,    50,    54,     0,     0,    62,     0,    41,
      33,    35,    65,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,    81,    59,   -92,   -92,   -92,   -10,   -92,
     -92,   -92,    66,    69,   -92,   -92,   -91,   -92,   -92,   -92,
     -92,   -40,   -13,   -92,   -92,    16,   -92,    17,   -92,    13,
     -92,   -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    13,    14,    30,     7,     8,
      17,    18,    19,    47,    32,    36,    48,    49,    50,    51,
      52,    53,    54,    55,    77,    56,    78,    57,    81,    58,
      59,    87,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    43,    16,    64,   100,   101,     9,    45,    46,    61,
      39,    43,   104,    40,    16,    41,    20,    45,    46,     1,
      82,     2,    35,    84,    11,    86,    89,    42,    90,    43,
      12,    22,    -9,    27,    44,    45,    46,    39,    79,    80,
      40,     1,    41,    15,    69,    70,    69,    70,    71,    72,
      73,    74,    75,    76,    42,    65,    43,    66,   102,    25,
      27,   -16,    45,    46,    91,    91,    21,    23,    91,    24,
      26,    27,    31,    37,    33,    -9,    60,    63,    67,    38,
      68,    99,    83,    85,   103,    10,    95,    96,    97,    98,
      29,    34,    28,    92,    94,    93
};

static const yytype_int8 yycheck[] =
{
      40,    22,    12,    43,    95,    96,     0,    28,    29,    20,
       3,    22,   103,     6,    24,     8,    20,    28,    29,     5,
      60,     7,    32,    63,    29,    65,    66,    20,    68,    22,
      22,    29,    24,    26,    27,    28,    29,     3,    11,    12,
       6,     5,     8,     7,     9,    10,     9,    10,    13,    14,
      15,    16,    17,    18,    20,    22,    22,    24,    98,    28,
      26,    23,    28,    29,    77,    78,    24,    23,    81,    21,
      24,    26,    25,    20,    25,    24,    22,    22,    20,    29,
      19,    25,    20,    23,     4,     4,    23,    23,    23,    21,
      24,    32,    23,    77,    81,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    32,    33,    34,    35,    39,    40,     0,
      34,    29,    22,    36,    37,     7,    39,    41,    42,    43,
      20,    24,    29,    23,    21,    28,    24,    26,    44,    43,
      38,    25,    45,    25,    35,    39,    46,    20,    29,     3,
       6,     8,    20,    22,    27,    28,    29,    44,    47,    48,
      49,    50,    51,    52,    53,    54,    56,    58,    60,    61,
      22,    20,    52,    22,    52,    22,    24,    20,    19,     9,
      10,    13,    14,    15,    16,    17,    18,    55,    57,    11,
      12,    59,    52,    20,    52,    23,    52,    62,    63,    52,
      52,    53,    56,    58,    60,    23,    23,    23,    21,    25,
      47,    47,    52,     4,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    36,    35,    37,
      38,    35,    39,    39,    40,    41,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    61,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       0,     8,     1,     1,     6,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     1,     0,     3,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
  case 2: /* programa: declaracao_lista  */
#line 35 "cminus.y"
                     { savedTree = yyvsp[0]; }
#line 1210 "parser.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 40 "cminus.y"
    { 
        YYSTYPE t = yyvsp[-1];
        if (t != NULL) {
            while (t->sibling != NULL) t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        } else {
            yyval = yyvsp[0];
        }
    }
#line 1225 "parser.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 50 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1231 "parser.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 54 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1237 "parser.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 55 "cminus.y"
                     { yyval = yyvsp[0]; }
#line 1243 "parser.c"
    break;

  case 7: /* $@1: %empty  */
#line 59 "cminus.y"
                          { savedName = copyString(lastTokenString);
                   savedLineNo = lineno; }
#line 1250 "parser.c"
    break;

  case 8: /* var_declaracao: tipo_especificador ID $@1 SEMI  */
#line 61 "cminus.y"
    { 
        yyval = yyvsp[-3];
        YYSTYPE newNodeS2 = newExpNode(IdK);
        fprintf(stdout, "savedName = %s\n", savedName);
        newNodeS2->attr.name = savedName;
        newNodeS2->lineno = savedLineNo;
        yyvsp[-3]->child[0] = newNodeS2;
    }
#line 1263 "parser.c"
    break;

  case 9: /* $@2: %empty  */
#line 69 "cminus.y"
                            { savedName = copyString(lastTokenString);
                   savedLineNo = lineno; }
#line 1270 "parser.c"
    break;

  case 10: /* $@3: %empty  */
#line 70 "cminus.y"
                                                        { savedName2 = copyString(tokenString);
                   savedLineNo2 = lineno; }
#line 1277 "parser.c"
    break;

  case 11: /* var_declaracao: tipo_especificador ID $@2 LBRACKET NUM $@3 RBRACKET SEMI  */
#line 72 "cminus.y"
    { 
        yyval = yyvsp[-7];
        YYSTYPE newNodeS2 = newExpNode(IdK);
        fprintf(stdout, "savedName = %s\n", savedName);
        newNodeS2->attr.name = savedName;
        newNodeS2->lineno = savedLineNo;
        yyvsp[-7]->child[0] = newNodeS2;
        fprintf(stdout, "savedName2 = %s\n", savedName2);

        YYSTYPE newNodeS3 = newExpNode(ConstK);
        newNodeS3->attr.val = atoi(savedName2);
        newNodeS3->lineno = savedLineNo2;
        newNodeS2->child[0] = newNodeS3;

        /*antigo
        $$ = newDecNode(ArrDecK);
        $1->child[0] = $$; // Linking tipo_especificador node as child
        $$->attr.name = copyString($2->attr.name); 
        $$->attr.val = $4->attr.val;
        $$->type = $1->type;
        */
    }
#line 1304 "parser.c"
    break;

  case 12: /* tipo_especificador: INT  */
#line 99 "cminus.y"
    { 
        yyval = newDecNode(DeclarationK); 
        yyval->type = Integer;
        yyval->attr.name = copyString("int");
    }
#line 1314 "parser.c"
    break;

  case 13: /* tipo_especificador: VOID  */
#line 105 "cminus.y"
    { 
        yyval = newDecNode(DeclarationK); 
        yyval->type = Void;
        yyval->attr.name = copyString("void");
    }
#line 1324 "parser.c"
    break;

  case 14: /* fun_declaracao: tipo_especificador ID LPAREN params RPAREN composto_decl  */
#line 114 "cminus.y"
    { 
        yyval = newDecNode(FunDecK);
        yyval->attr.name = copyString(yyvsp[-4]->attr.name);
        yyval->type = yyvsp[-5]->type;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1336 "parser.c"
    break;

  case 15: /* params: param_lista  */
#line 124 "cminus.y"
                { yyval = yyvsp[0]; }
#line 1342 "parser.c"
    break;

  case 16: /* params: VOID  */
#line 125 "cminus.y"
           { yyval = NULL; }
#line 1348 "parser.c"
    break;

  case 17: /* param_lista: param_lista COMMA param  */
#line 130 "cminus.y"
    { 
        YYSTYPE t = yyvsp[-2];
        while (t->sibling) t = t->sibling;
        t->sibling = yyvsp[0];
        yyval = yyvsp[-2];
    }
#line 1359 "parser.c"
    break;

  case 18: /* param_lista: param  */
#line 136 "cminus.y"
            { yyval = yyvsp[0]; }
#line 1365 "parser.c"
    break;

  case 19: /* param: tipo_especificador ID  */
#line 141 "cminus.y"
    {
        yyval = newDecNode(VarDecK); // Adaptacao para o nó de declaracao
        yyval->attr.name = copyString(yyvsp[0]->attr.name);
        yyval->type = yyvsp[-1]->type;
    }
#line 1375 "parser.c"
    break;

  case 20: /* param: tipo_especificador ID LBRACKET RBRACKET  */
#line 147 "cminus.y"
    {
        yyval = newDecNode(ArrDecK); // Adaptacao para o nó de declaracao de array
        yyval->attr.name = copyString(yyvsp[-2]->attr.name);
        yyval->type = yyvsp[-3]->type;
    }
#line 1385 "parser.c"
    break;

  case 21: /* composto_decl: LBRACE local_declaracoes statement_lista RBRACE  */
#line 156 "cminus.y"
        {
            yyval = newStmtNode(CompoundK);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[-1];
        }
#line 1395 "parser.c"
    break;

  case 22: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 165 "cminus.y"
        {
            YYSTYPE t = yyvsp[-1];
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1410 "parser.c"
    break;

  case 23: /* local_declaracoes: %empty  */
#line 176 "cminus.y"
        {
            yyval = NULL;
        }
#line 1418 "parser.c"
    break;

  case 24: /* statement_lista: statement_lista statement  */
#line 183 "cminus.y"
        {
            YYSTYPE t = yyvsp[-1];
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1433 "parser.c"
    break;

  case 25: /* statement_lista: %empty  */
#line 194 "cminus.y"
        {
            yyval = NULL;
        }
#line 1441 "parser.c"
    break;

  case 31: /* expressao_decl: expressao SEMI  */
#line 209 "cminus.y"
        {
            yyval = yyvsp[-1];
        }
#line 1449 "parser.c"
    break;

  case 32: /* expressao_decl: SEMI  */
#line 213 "cminus.y"
        {
            yyval = NULL;
        }
#line 1457 "parser.c"
    break;

  case 33: /* selecao_decl: IF LPAREN expressao RPAREN statement  */
#line 220 "cminus.y"
        {
            yyval = newStmtNode(IfK);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1467 "parser.c"
    break;

  case 34: /* selecao_decl: IF LPAREN expressao RPAREN statement ELSE statement  */
#line 226 "cminus.y"
        {
            yyval = newStmtNode(IfK);
            yyval->child[0] = yyvsp[-4];
            yyval->child[1] = yyvsp[-2];
            yyval->child[2] = yyvsp[0];
        }
#line 1478 "parser.c"
    break;

  case 35: /* iteracao_decl: WHILE LPAREN expressao RPAREN statement  */
#line 236 "cminus.y"
        {
            yyval = newStmtNode(WhileK);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1488 "parser.c"
    break;

  case 36: /* retorno_decl: RETURN SEMI  */
#line 245 "cminus.y"
        {
            yyval = newStmtNode(ReturnK);
        }
#line 1496 "parser.c"
    break;

  case 37: /* retorno_decl: RETURN expressao SEMI  */
#line 249 "cminus.y"
        {
            yyval = newStmtNode(ReturnK);
            yyval->child[0] = yyvsp[-1];
        }
#line 1505 "parser.c"
    break;

  case 38: /* expressao: var ASSIGN expressao  */
#line 257 "cminus.y"
        {
            yyval = newStmtNode(AssignK);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1515 "parser.c"
    break;

  case 40: /* var: ID  */
#line 267 "cminus.y"
        {
            yyval = newExpNode(IdK);
            yyval->attr.name = copyString(yyvsp[0]->attr.name);
        }
#line 1524 "parser.c"
    break;

  case 41: /* var: ID LBRACKET expressao RBRACKET  */
#line 272 "cminus.y"
        {
            yyval = newExpNode(ArrK);
            yyval->attr.name = copyString(yyvsp[-3]->attr.name);
            yyval->child[0] = yyvsp[-1];
        }
#line 1534 "parser.c"
    break;

  case 42: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 281 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1545 "parser.c"
    break;

  case 44: /* relacional: LET  */
#line 291 "cminus.y"
        { yyval->attr.op = LET; }
#line 1551 "parser.c"
    break;

  case 45: /* relacional: LT  */
#line 292 "cminus.y"
         { yyval->attr.op = LT; }
#line 1557 "parser.c"
    break;

  case 46: /* relacional: BT  */
#line 293 "cminus.y"
         { yyval->attr.op = BT; }
#line 1563 "parser.c"
    break;

  case 47: /* relacional: BET  */
#line 294 "cminus.y"
          { yyval->attr.op = BET; }
#line 1569 "parser.c"
    break;

  case 48: /* relacional: EQUAL  */
#line 295 "cminus.y"
            { yyval->attr.op = EQUAL; }
#line 1575 "parser.c"
    break;

  case 49: /* relacional: DIF  */
#line 296 "cminus.y"
          { yyval->attr.op = DIF; }
#line 1581 "parser.c"
    break;

  case 50: /* soma_expressao: soma_expressao soma termo  */
#line 301 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1592 "parser.c"
    break;

  case 52: /* soma: PLUS  */
#line 311 "cminus.y"
         { yyval->attr.op = PLUS; }
#line 1598 "parser.c"
    break;

  case 53: /* soma: MINUS  */
#line 312 "cminus.y"
            { yyval->attr.op = MINUS; }
#line 1604 "parser.c"
    break;

  case 54: /* termo: termo mult fator  */
#line 317 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
        }
#line 1615 "parser.c"
    break;

  case 56: /* mult: TIMES  */
#line 327 "cminus.y"
          { yyval->attr.op = TIMES; }
#line 1621 "parser.c"
    break;

  case 57: /* mult: OVER  */
#line 328 "cminus.y"
           { yyval->attr.op = OVER; }
#line 1627 "parser.c"
    break;

  case 58: /* fator: LPAREN expressao RPAREN  */
#line 332 "cminus.y"
                            { yyval = yyvsp[-1]; }
#line 1633 "parser.c"
    break;

  case 61: /* fator: NUM  */
#line 336 "cminus.y"
        {
            yyval = newExpNode(ConstK);
            yyval->attr.val = yyvsp[0]->attr.val;
        }
#line 1642 "parser.c"
    break;

  case 62: /* ativacao: ID LPAREN args RPAREN  */
#line 344 "cminus.y"
        {
            yyval = newExpNode(CallK);
            yyval->attr.name = copyString(yyvsp[-3]->attr.name);
            yyval->child[0] = yyvsp[-1];
        }
#line 1652 "parser.c"
    break;

  case 64: /* args: %empty  */
#line 354 "cminus.y"
        {
            yyval = NULL;
        }
#line 1660 "parser.c"
    break;

  case 65: /* arg_lista: arg_lista COMMA expressao  */
#line 361 "cminus.y"
        {
            YYSTYPE t = yyvsp[-2];
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-2];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1675 "parser.c"
    break;


#line 1679 "parser.c"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 374 "cminus.y"


int yyerror(char * message)
{ pce("Syntax error at line %d: %s\n",lineno,message);
  pce("Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ 
    strncpy(lastTokenString, tokenString, MAXTOKENLEN);
    return getToken(); }

TreeNode * parse(void)
{ 
    yyparse();
  return savedTree;
}

