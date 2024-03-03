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
#line 1 "parser.y"

#include <bits/stdc++.h>
using namespace std;

#define YYDEBUG 1

extern int yydebug;
extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern char* yytext;
extern FILE* yyin;  
extern FILE* yyout;
extern int yychar;

int node=0;
map<string,int>m;


#line 92 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ARITHMETIC_OPERATOR = 3,        /* ARITHMETIC_OPERATOR  */
  YYSYMBOL_RELATIONAL_OPERATOR = 4,        /* RELATIONAL_OPERATOR  */
  YYSYMBOL_BITWISE_OPERATOR = 5,           /* BITWISE_OPERATOR  */
  YYSYMBOL_ASSIGNMENT_OPERATOR = 6,        /* ASSIGNMENT_OPERATOR  */
  YYSYMBOL_DATA_TYPE = 7,                  /* DATA_TYPE  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELIF = 11,                      /* ELIF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_LIST = 16,                      /* LIST  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_AUGASSIGNMENT_OPERATOR = 18,    /* AUGASSIGNMENT_OPERATOR  */
  YYSYMBOL_COLON = 19,                     /* COLON  */
  YYSYMBOL_LEFT_BRACKET = 20,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 21,             /* RIGHT_BRACKET  */
  YYSYMBOL_RETURN_ARROW = 22,              /* RETURN_ARROW  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_NAME = 24,                      /* NAME  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 25,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 26,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_NONE = 27,                      /* NONE  */
  YYSYMBOL_TRUE = 28,                      /* TRUE  */
  YYSYMBOL_FALSE = 29,                     /* FALSE  */
  YYSYMBOL_IN = 30,                        /* IN  */
  YYSYMBOL_DEF = 31,                       /* DEF  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_NEWLINE = 34,                   /* NEWLINE  */
  YYSYMBOL_INDENT = 35,                    /* INDENT  */
  YYSYMBOL_DEDENT = 36,                    /* DEDENT  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_XOR = 39,                       /* XOR  */
  YYSYMBOL_BIT_NOT = 40,                   /* BIT_NOT  */
  YYSYMBOL_ADD = 41,                       /* ADD  */
  YYSYMBOL_SUB = 42,                       /* SUB  */
  YYSYMBOL_POWER = 43,                     /* POWER  */
  YYSYMBOL_BIT_AND = 44,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 45,                    /* BIT_OR  */
  YYSYMBOL_NUMBER = 46,                    /* NUMBER  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_SHIFT = 49,                     /* SHIFT  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 50,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 51,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_low = 52,                       /* low  */
  YYSYMBOL_low1 = 53,                      /* low1  */
  YYSYMBOL_low2 = 54,                      /* low2  */
  YYSYMBOL_low3 = 55,                      /* low3  */
  YYSYMBOL_low4 = 56,                      /* low4  */
  YYSYMBOL_low5 = 57,                      /* low5  */
  YYSYMBOL_low6 = 58,                      /* low6  */
  YYSYMBOL_high = 59,                      /* high  */
  YYSYMBOL_high1 = 60,                     /* high1  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_module = 62,                    /* module  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_simple_stmt = 64,               /* simple_stmt  */
  YYSYMBOL_more_expr = 65,                 /* more_expr  */
  YYSYMBOL_small_stmt = 66,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 67,                 /* expr_stmt  */
  YYSYMBOL_Assign_stmt = 68,               /* Assign_stmt  */
  YYSYMBOL_annassign = 69,                 /* annassign  */
  YYSYMBOL_break_stmt = 70,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 71,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 72,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 73,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 74,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 75,           /* elif_statements  */
  YYSYMBOL_else_statement = 76,            /* else_statement  */
  YYSYMBOL_while_stmt = 77,                /* while_stmt  */
  YYSYMBOL_for_stmt = 78,                  /* for_stmt  */
  YYSYMBOL_funcdef = 79,                   /* funcdef  */
  YYSYMBOL_parameters = 80,                /* parameters  */
  YYSYMBOL_typedargslist = 81,             /* typedargslist  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_full_tfpdef = 83,               /* full_tfpdef  */
  YYSYMBOL_classdef = 84,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 85,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 86,               /* opt_arglist  */
  YYSYMBOL_arglist = 87,                   /* arglist  */
  YYSYMBOL_argument = 88,                  /* argument  */
  YYSYMBOL_comp_iter = 89,                 /* comp_iter  */
  YYSYMBOL_comp_for = 90,                  /* comp_for  */
  YYSYMBOL_comp_if = 91,                   /* comp_if  */
  YYSYMBOL_suite = 92,                     /* suite  */
  YYSYMBOL_stmt_list = 93,                 /* stmt_list  */
  YYSYMBOL_test = 94,                      /* test  */
  YYSYMBOL_or_test = 95,                   /* or_test  */
  YYSYMBOL_and_test = 96,                  /* and_test  */
  YYSYMBOL_not_test = 97,                  /* not_test  */
  YYSYMBOL_98_2 = 98,                      /* $@2  */
  YYSYMBOL_comparison = 99,                /* comparison  */
  YYSYMBOL_expr = 100,                     /* expr  */
  YYSYMBOL_xor_expr = 101,                 /* xor_expr  */
  YYSYMBOL_and_expr = 102,                 /* and_expr  */
  YYSYMBOL_shift_expr = 103,               /* shift_expr  */
  YYSYMBOL_arith_expr = 104,               /* arith_expr  */
  YYSYMBOL_term = 105,                     /* term  */
  YYSYMBOL_factor = 106,                   /* factor  */
  YYSYMBOL_power = 107,                    /* power  */
  YYSYMBOL_atom_expr = 108,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 109,              /* opt_trailer  */
  YYSYMBOL_atom = 110,                     /* atom  */
  YYSYMBOL_testlist_comp = 111,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 112,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 113,                  /* trailer  */
  YYSYMBOL_testlist = 114,                 /* testlist  */
  YYSYMBOL_exprlist = 115                  /* exprlist  */
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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   431

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    53,    56,    57,    58,    59,    62,    63,
      66,    67,    71,    72,    73,    74,    78,    79,    80,    83,
      84,    87,    88,    92,    95,    98,    99,   106,   107,   108,
     109,   110,   113,   114,   115,   116,   119,   120,   123,   127,
     128,   132,   133,   136,   137,   140,   141,   145,   145,   147,
     151,   152,   155,   156,   159,   160,   163,   164,   167,   168,
     171,   172,   173,   176,   177,   180,   181,   184,   185,   190,
     191,   192,   195,   196,   199,   200,   203,   204,   207,   208,
     211,   211,   213,   215,   216,   218,   219,   221,   222,   224,
     225,   227,   228,   231,   232,   233,   235,   236,   239,   240,
     241,   242,   245,   246,   248,   249,   252,   253,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     272,   273,   274,   276,   277,   281,   282,   283,   284,   288,
     289,   293,   294
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
  "\"end of file\"", "error", "\"invalid token\"", "ARITHMETIC_OPERATOR",
  "RELATIONAL_OPERATOR", "BITWISE_OPERATOR", "ASSIGNMENT_OPERATOR",
  "DATA_TYPE", "FOR", "WHILE", "IF", "ELIF", "ELSE", "BREAK", "CLASS",
  "CONTINUE", "LIST", "SEMICOLON", "AUGASSIGNMENT_OPERATOR", "COLON",
  "LEFT_BRACKET", "RIGHT_BRACKET", "RETURN_ARROW", "COMMA", "NAME",
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "NONE", "TRUE", "FALSE",
  "IN", "DEF", "NOT", "RETURN", "NEWLINE", "INDENT", "DEDENT", "AND", "OR",
  "XOR", "BIT_NOT", "ADD", "SUB", "POWER", "BIT_AND", "BIT_OR", "NUMBER",
  "STRING", "DOT", "SHIFT", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET",
  "low", "low1", "low2", "low3", "low4", "low5", "low6", "high", "high1",
  "$accept", "module", "stmt", "simple_stmt", "more_expr", "small_stmt",
  "expr_stmt", "Assign_stmt", "annassign", "break_stmt", "continue_stmt",
  "return_stmt", "compound_stmt", "if_stmt", "elif_statements",
  "else_statement", "while_stmt", "for_stmt", "funcdef", "parameters",
  "typedargslist", "$@1", "full_tfpdef", "classdef", "opt_class_arg",
  "opt_arglist", "arglist", "argument", "comp_iter", "comp_for", "comp_if",
  "suite", "stmt_list", "test", "or_test", "and_test", "not_test", "$@2",
  "comparison", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "factor", "power", "atom_expr", "opt_trailer", "atom",
  "testlist_comp", "opt_test_stmt", "trailer", "testlist", "exprlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,  -147,   384,   374,   374,  -147,    21,  -147,  -147,    19,
    -147,   290,  -147,  -147,  -147,    34,  -147,   374,  -147,   384,
     384,   384,  -147,  -147,    63,   226,  -147,    53,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
      14,    46,  -147,    82,    43,    54,    52,    72,    38,   127,
    -147,  -147,    61,    -7,    13,    43,     7,   112,   113,    70,
    -147,   126,   117,   116,  -147,   118,   123,   374,  -147,  -147,
    -147,  -147,  -147,  -147,   262,   374,   374,   374,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   318,   374,   121,
      -7,  -147,   374,   374,   374,   374,   140,  -147,   384,   374,
      95,    95,    95,   346,   128,   384,  -147,  -147,   374,  -147,
      47,    50,  -147,  -147,    13,     0,    46,  -147,    43,    52,
      52,    72,    38,   127,   127,  -147,  -147,  -147,    33,  -147,
      69,   122,  -147,  -147,   129,   129,   143,  -147,   374,    43,
       6,   115,  -147,   139,    87,  -147,  -147,   132,   133,    95,
      32,  -147,  -147,   141,    55,  -147,    95,   374,   374,  -147,
     374,   374,  -147,  -147,   374,   129,    95,   226,   144,  -147,
     374,   101,  -147,  -147,   374,  -147,   374,  -147,  -147,  -147,
    -147,   145,  -147,  -147,  -147,  -147,   139,  -147,   185,    95,
     146,   374,  -147,    12,   135,    95,  -147,  -147,  -147,  -147,
    -147,    95,   147,   374,  -147,  -147,  -147,  -147,  -147,  -147,
      95,    12,  -147,  -147
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   114,     0,     0,     0,    23,     0,    24,   119,     0,
     112,     0,   116,   117,   118,     0,    80,    25,     4,     0,
       0,     0,   113,   115,     0,     3,     5,     8,    11,    12,
      13,    14,    15,     6,    27,    28,    29,    30,    31,   130,
      75,    77,    79,    82,    84,    86,    88,    90,    92,    95,
      97,   101,   103,   105,     7,   132,     0,     0,     0,     0,
     109,   123,     0,   122,   110,     0,     0,     0,    26,   100,
      98,    99,     1,     2,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   107,     0,     0,     0,     0,    18,    16,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   108,   121,   111,
       0,     0,    81,    10,     0,     0,    76,    78,    83,    85,
      87,    89,    91,    93,    94,    96,   102,   126,     0,    59,
      60,     0,   128,   106,    20,    17,    22,   129,     0,   131,
       0,     0,    69,    39,    32,    53,    54,     0,    57,     0,
       0,   124,    45,    51,     0,    49,     0,     0,     0,   125,
       0,     0,    61,   127,     0,    19,     0,     0,     0,    40,
       0,    34,    33,    55,    56,    52,     0,    50,    46,    47,
      43,     0,    74,    58,    62,    21,    41,    73,     0,     0,
       0,     0,    35,    65,     0,     0,    42,    71,    70,    72,
      38,     0,     0,     0,    66,    63,    64,    48,    44,    37,
       0,    67,    36,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,   137,  -146,     3,  -147,    94,  -147,  -147,    20,  -147,
    -147,  -147,  -147,  -147,  -147,  -137,  -147,  -147,  -147,  -147,
    -147,  -147,   -22,  -147,  -147,  -147,    71,  -107,   -36,   -57,
    -147,   -92,  -147,    -3,   -70,   100,   -44,  -147,  -147,     9,
    -147,    37,    96,    97,    42,    -4,  -147,  -147,  -147,  -147,
     167,  -147,    90,     2,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    24,    25,   142,    27,    28,    29,    96,    97,    30,
      31,    32,    33,    34,   171,   169,    35,    36,    37,   111,
     154,   194,   155,    38,   104,   147,   128,   129,   204,   205,
     206,   143,   188,    39,    40,    41,    42,    67,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    90,    53,
      62,    63,    91,   114,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    54,    26,   106,   115,    61,   172,    61,   144,
     145,    55,   158,    87,    68,    69,    70,    71,    88,    92,
     105,   187,   203,   112,    75,   166,     1,    54,    26,    95,
      98,    93,    94,   117,   192,     8,    95,    99,    76,     9,
      60,    89,   199,    10,    11,    59,    12,    13,    14,   196,
      76,    16,    76,   183,   159,    98,   160,   175,    66,    19,
      20,    21,   176,    72,   180,    22,    23,   183,   152,   156,
      74,   153,   157,   162,   186,   161,   178,   105,   179,    83,
      84,   125,   126,    77,   130,   131,    78,   118,    79,   102,
     103,   136,   137,    80,   134,   135,    81,   200,   170,   168,
     130,   140,     1,   208,    86,   151,   193,   139,     5,   209,
       7,     8,   191,   168,    55,     9,   119,   120,   212,    10,
      11,    82,    12,    13,    14,   123,   124,    16,    17,   141,
      85,   100,   101,   211,   105,    19,    20,    21,   107,   108,
     165,    22,    23,   110,   109,   132,   138,   149,   163,   164,
     167,   168,    95,   173,   181,   182,   174,   130,   184,   153,
      94,   185,    73,   189,   195,   201,   210,   190,   113,    54,
      26,   130,   207,   177,   148,   213,   116,   121,    65,   122,
     133,   150,     0,     0,     0,   197,     0,     0,   202,     0,
      54,    26,     1,     2,     3,     4,     0,     0,     5,     6,
       7,     8,     0,     0,     0,     9,     0,     0,     0,    10,
      11,     0,    12,    13,    14,     0,    15,    16,    17,    18,
       0,   198,     0,     0,     0,    19,    20,    21,     0,     0,
       0,    22,    23,     1,     2,     3,     4,     0,     0,     5,
       6,     7,     8,     0,     0,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,    21,     1,
       0,     0,    22,    23,     0,     5,     0,     7,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,     0,     0,    16,    17,     0,     1,     0,     0,
       0,     0,    19,    20,    21,     0,     8,     0,    22,    23,
       9,     0,     0,     0,    10,    11,    64,    12,    13,    14,
       0,     0,    16,     0,     0,     1,     0,     0,     0,     0,
      19,    20,    21,     0,     8,     0,    22,    23,     9,   127,
       0,     0,    10,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     1,     0,     0,     0,     0,    19,    20,
      21,     0,     8,     0,    22,    23,     9,   146,     0,     0,
      10,    11,     0,    12,    13,    14,     0,     0,    16,     0,
       0,     1,     0,     0,     0,     0,    19,    20,    21,     0,
       8,     1,    22,    23,     9,     0,     0,     0,    10,    11,
       8,    12,    13,    14,     9,     0,    16,     0,    10,    11,
       0,    12,    13,    14,    19,    20,    21,     0,     0,     0,
      22,    23,     0,     0,    19,    20,    21,     0,     0,     0,
      22,    23
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    61,    75,     9,   144,    11,   101,
     102,     2,    12,    20,    17,    19,    20,    21,    25,     6,
       8,   167,    10,    67,    10,    19,     7,    25,    25,    23,
      23,    18,    19,    77,   171,    16,    23,    30,    38,    20,
      21,    48,   188,    24,    25,    24,    27,    28,    29,   186,
      38,    32,    38,   160,    21,    23,    23,   149,    24,    40,
      41,    42,    30,     0,   156,    46,    47,   174,    21,    19,
      17,    24,    22,   130,   166,     6,    21,     8,    23,    41,
      42,    85,    86,    37,    87,    88,     4,    78,    45,    19,
      20,    94,    95,    39,    92,    93,    44,   189,    11,    12,
     103,    99,     7,   195,    43,   108,   176,    98,    13,   201,
      15,    16,    11,    12,   105,    20,    79,    80,   210,    24,
      25,    49,    27,    28,    29,    83,    84,    32,    33,    34,
       3,    19,    19,   203,     8,    40,    41,    42,    21,    23,
     138,    46,    47,    20,    26,    24,     6,    19,    26,     6,
      35,    12,    23,    21,   157,   158,    23,   160,   161,    24,
      19,   164,    25,    19,    19,    19,    19,   170,    74,   167,
     167,   174,   194,   153,   103,   211,    76,    81,    11,    82,
      90,   105,    -1,    -1,    -1,     0,    -1,    -1,   191,    -1,
     188,   188,     7,     8,     9,    10,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      -1,    36,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    47,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,     7,
      -1,    -1,    46,    47,    -1,    13,    -1,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    33,    -1,     7,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,    47,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    16,    -1,    46,    47,    20,    21,
      -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    16,    -1,    46,    47,    20,    21,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      16,     7,    46,    47,    20,    -1,    -1,    -1,    24,    25,
      16,    27,    28,    29,    20,    -1,    32,    -1,    24,    25,
      -1,    27,    28,    29,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    73,    74,    77,    78,    79,    84,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   110,   114,   100,   115,    94,    94,    24,
      21,    94,   111,   112,    26,   111,    24,    98,    94,   106,
     106,   106,     0,    62,    17,    10,    38,    37,     4,    45,
      39,    44,    49,    41,    42,     3,    43,    20,    25,    48,
     109,   113,     6,    18,    19,    23,    68,    69,    23,    30,
      19,    19,    19,    20,    85,     8,    90,    21,    23,    26,
      20,    80,    97,    66,   114,    95,    96,    97,   100,   102,
     102,   103,   104,   105,   105,   106,   106,    21,    87,    88,
      94,    94,    24,   113,   114,   114,    94,    94,     6,   100,
     114,    34,    64,    92,    92,    92,    21,    86,    87,    19,
     115,    94,    21,    24,    81,    83,    19,    22,    12,    21,
      23,     6,    90,    26,     6,   114,    19,    35,    12,    76,
      11,    75,    76,    21,    23,    92,    30,    69,    21,    23,
      92,    94,    94,    88,    94,    94,    92,    63,    93,    19,
      94,    11,    76,    95,    82,    19,    76,     0,    36,    63,
      92,    19,    94,    10,    89,    90,    91,    83,    92,    92,
      19,    95,    92,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    71,    72,    72,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    82,    81,    81,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      98,    97,    97,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     2,     3,
       2,     4,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     5,     4,     3,     4,
       5,     6,     7,     5,     7,     2,     3,     0,     4,     1,
       2,     1,     5,     4,     2,     3,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     4,     5,     2,     3,     1,
       4,     4,     2,     1,     5,     1,     3,     1,     3,     1,
       0,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     2,     2,
       2,     1,     3,     1,     2,     1,     2,     1,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     3,     3,     2,     3,     2,     3,
       1,     3,     1
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
  case 2: /* module: stmt module  */
#line 52 "parser.y"
                                {fprintf(yyout,"module--%d;\n",(yyvsp[-1].attributes).top);}
#line 1402 "parser.tab.c"
    break;

  case 3: /* module: stmt  */
#line 53 "parser.y"
      {fprintf(yyout,"module--%d;\n",(yyvsp[0].attributes).top);}
#line 1408 "parser.tab.c"
    break;

  case 4: /* stmt: NEWLINE  */
#line 56 "parser.y"
              { fprintf(yyout,"stmt%d--NEWLINE%d;\n",m["stmt"],m["NEWLINE"]); m["NEWLINE"]++;}
#line 1414 "parser.tab.c"
    break;

  case 5: /* stmt: simple_stmt  */
#line 57 "parser.y"
              {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1420 "parser.tab.c"
    break;

  case 6: /* stmt: compound_stmt  */
#line 58 "parser.y"
                {fprintf(yyout,"stmt%d--compound_stmt%d;\n",m["stmt"],m["compound_stmt"]); m["compound_stmt"]++; }
#line 1426 "parser.tab.c"
    break;

  case 7: /* stmt: testlist  */
#line 59 "parser.y"
           {fprintf(yyout,"stmt%d--testlist%d;\n",m["stmt"],m["testlist"]); m["testlist"]++; }
#line 1432 "parser.tab.c"
    break;

  case 8: /* simple_stmt: more_expr  */
#line 62 "parser.y"
                                 {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1438 "parser.tab.c"
    break;

  case 11: /* more_expr: small_stmt  */
#line 67 "parser.y"
            {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1444 "parser.tab.c"
    break;

  case 12: /* small_stmt: expr_stmt  */
#line 71 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1450 "parser.tab.c"
    break;

  case 13: /* small_stmt: break_stmt  */
#line 72 "parser.y"
               {fprintf(yyout,"simple_stmt%d--break_stmt%d;\n",m["simple_stmt"],m["break_stmt"]); m["break_stmt"]++; }
#line 1456 "parser.tab.c"
    break;

  case 14: /* small_stmt: continue_stmt  */
#line 73 "parser.y"
                           {fprintf(yyout,"simple_stmt%d--continue_stmt%d;\n",m["simple_stmt"],m["expr_stmt"]); m["continue_stmt"]++; }
#line 1462 "parser.tab.c"
    break;

  case 15: /* small_stmt: return_stmt  */
#line 74 "parser.y"
                           {fprintf(yyout,"simple_stmt%d--return_stmt%d;\n",m["simple_stmt"],m["return_stmt"]); m["return_stmt"]++; }
#line 1468 "parser.tab.c"
    break;

  case 16: /* expr_stmt: testlist annassign  */
#line 78 "parser.y"
                       {fprintf(yyout,"right_assign%d--annassign%d;\n",m["right_assign"],m["annassign"]); m["annassign"]++; }
#line 1474 "parser.tab.c"
    break;

  case 17: /* expr_stmt: testlist AUGASSIGNMENT_OPERATOR testlist  */
#line 79 "parser.y"
                                            {fprintf(yyout,"right_assign%d--AUGASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["AUGASSIGNMENT_OPERATOR"]); m["AUGASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
#line 1480 "parser.tab.c"
    break;

  case 18: /* expr_stmt: testlist Assign_stmt  */
#line 80 "parser.y"
                        {(yyval.attributes).top=(yyvsp[0].attributes).top; fprintf(yyout,"%d--%d;\n",(yyvsp[0].attributes).top,(yyvsp[-1].attributes).top);}
#line 1486 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: Assign_stmt ASSIGNMENT_OPERATOR testlist  */
#line 83 "parser.y"
                                          {fprintf(yyout,"right_assign%d--ASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
#line 1492 "parser.tab.c"
    break;

  case 20: /* Assign_stmt: ASSIGNMENT_OPERATOR testlist  */
#line 84 "parser.y"
                                 {fprintf(yyout,"%d--%d; %d[label=\"Operator (=)\"];\n",node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1498 "parser.tab.c"
    break;

  case 21: /* annassign: COLON test ASSIGNMENT_OPERATOR test  */
#line 87 "parser.y"
                                                   {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;fprintf(yyout,"annassign%d--ASSIGNMENT_OPERATOR%d;\n",m["annassign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++; fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;}
#line 1504 "parser.tab.c"
    break;

  case 22: /* annassign: COLON test  */
#line 88 "parser.y"
                           {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); }
#line 1510 "parser.tab.c"
    break;

  case 23: /* break_stmt: BREAK  */
#line 92 "parser.y"
       {fprintf(yyout,"break_stmt%d--BREAK%d;\n",m["break_stmt"],m["BREAK"]); m["BREAK"]++; }
#line 1516 "parser.tab.c"
    break;

  case 24: /* continue_stmt: CONTINUE  */
#line 95 "parser.y"
            {fprintf(yyout,"continue_stmt%d--CONTINUE%d;\n",m["continue_stmt"],m["CONTINUE"]); m["CONTINUE"]++; }
#line 1522 "parser.tab.c"
    break;

  case 25: /* return_stmt: RETURN  */
#line 98 "parser.y"
                   {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; }
#line 1528 "parser.tab.c"
    break;

  case 26: /* return_stmt: RETURN test  */
#line 99 "parser.y"
                           {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; fprintf(yyout,"return_stmt%d--test%d;\n",m["return_stmt"],m["test"]); m["test"]++; }
#line 1534 "parser.tab.c"
    break;

  case 27: /* compound_stmt: if_stmt  */
#line 106 "parser.y"
               {fprintf(yyout,"compound_stmt%d--if_stmt%d;\n",m["compound_stmt"],m["if_stmt"]); m["if_stmt"]++;}
#line 1540 "parser.tab.c"
    break;

  case 28: /* compound_stmt: while_stmt  */
#line 107 "parser.y"
               {fprintf(yyout,"compound_stmt%d--while_stmt%d;\n",m["compound_stmt"],m["while_stmt"]); m["while_stmt"]++;}
#line 1546 "parser.tab.c"
    break;

  case 29: /* compound_stmt: for_stmt  */
#line 108 "parser.y"
               {fprintf(yyout,"compound_stmt%d--for_stmt%d;\n",m["compound_stmt"],m["for_stmt"]); m["for_stmt"]++;}
#line 1552 "parser.tab.c"
    break;

  case 30: /* compound_stmt: funcdef  */
#line 109 "parser.y"
               {fprintf(yyout,"compound_stmt%d--funcdef%d;\n",m["compound_stmt"],m["funcdef"]); m["funcdef"]++;}
#line 1558 "parser.tab.c"
    break;

  case 31: /* compound_stmt: classdef  */
#line 110 "parser.y"
               {fprintf(yyout,"compound_stmt%d--classdef%d;\n",m["compound_stmt"],m["classdef"]); m["classdef"]++;}
#line 1564 "parser.tab.c"
    break;

  case 32: /* if_stmt: IF test COLON suite  */
#line 113 "parser.y"
                           { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;}
#line 1570 "parser.tab.c"
    break;

  case 33: /* if_stmt: IF test COLON suite else_statement  */
#line 114 "parser.y"
                                      { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1576 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF test COLON suite elif_statements  */
#line 115 "parser.y"
                                       { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;}
#line 1582 "parser.tab.c"
    break;

  case 35: /* if_stmt: IF test COLON suite elif_statements else_statement  */
#line 116 "parser.y"
                                                      { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1588 "parser.tab.c"
    break;

  case 36: /* elif_statements: elif_statements ELIF test COLON suite  */
#line 119 "parser.y"
                                        { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
#line 1594 "parser.tab.c"
    break;

  case 37: /* elif_statements: ELIF test COLON suite  */
#line 120 "parser.y"
                                         { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
#line 1600 "parser.tab.c"
    break;

  case 38: /* else_statement: ELSE COLON suite  */
#line 123 "parser.y"
                       { fprintf(yyout,"else_statement%d--ELSE%d;\n",m["else_statement"],m["ELSE"]); m["ELSE"]++; fprintf(yyout,"else_statement%d--COLON%d;\n",m["else_statement"],m["COLON"]); m["COLON"]++; fprintf(yyout,"else_statement%d--suite%d;\n",m["else_statement"],m["suite"]); m["suite"]++;}
#line 1606 "parser.tab.c"
    break;

  case 39: /* while_stmt: WHILE test COLON suite  */
#line 127 "parser.y"
                                    { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;}
#line 1612 "parser.tab.c"
    break;

  case 40: /* while_stmt: WHILE test COLON suite else_statement  */
#line 128 "parser.y"
                                                   { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"while_stmt%d--else_statement%d;\n",m["while_stmt"],m["else_statement"]);}
#line 1618 "parser.tab.c"
    break;

  case 41: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 132 "parser.y"
                                                  { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;}
#line 1624 "parser.tab.c"
    break;

  case 42: /* for_stmt: FOR exprlist IN testlist COLON suite else_statement  */
#line 133 "parser.y"
                                                                     { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"for_stmt%d--else_statement%d;\n",m["for_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1630 "parser.tab.c"
    break;

  case 43: /* funcdef: DEF NAME parameters COLON suite  */
#line 136 "parser.y"
                                             { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
#line 1636 "parser.tab.c"
    break;

  case 44: /* funcdef: DEF NAME parameters RETURN_ARROW test COLON suite  */
#line 137 "parser.y"
                                                      { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++;fprintf(yyout,"funcdef%d--RETURN_ARROW%d;\n",m["funcdef"],m["RETURN_ARROW"]); m["RETURN_ARROW"]++;fprintf(yyout,"funcdef%d--test%d;\n",m["funcdef"],m["test"]); m["test"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
#line 1642 "parser.tab.c"
    break;

  case 45: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 140 "parser.y"
                                             {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1648 "parser.tab.c"
    break;

  case 46: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 141 "parser.y"
                                             {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--typedargslist%d;\n",m["parameters"],m["typedargslist"]); m["typedargslist"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1654 "parser.tab.c"
    break;

  case 47: /* $@1: %empty  */
#line 145 "parser.y"
                    {fprintf(yyout,"typedargslist%d--COMMA%d;\n",m["typedargslist"],m["COMMA"]); m["COMMA"]++;}
#line 1660 "parser.tab.c"
    break;

  case 50: /* full_tfpdef: NAME annassign  */
#line 151 "parser.y"
                           {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;fprintf(yyout,"typedargslist%d--annassign%d;\n",m["typedargslist"],m["annassign"]); m["annassign"]++;}
#line 1666 "parser.tab.c"
    break;

  case 51: /* full_tfpdef: NAME  */
#line 152 "parser.y"
                    {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;}
#line 1672 "parser.tab.c"
    break;

  case 52: /* classdef: CLASS NAME opt_class_arg COLON suite  */
#line 155 "parser.y"
                                         { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--opt_class_arg%d;\n",m["classdef"],m["opt_class_arg"]); m["opt_class_arg"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
#line 1678 "parser.tab.c"
    break;

  case 53: /* classdef: CLASS NAME COLON suite  */
#line 156 "parser.y"
                              { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
#line 1684 "parser.tab.c"
    break;

  case 54: /* opt_class_arg: LEFT_BRACKET RIGHT_BRACKET  */
#line 159 "parser.y"
                              {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1690 "parser.tab.c"
    break;

  case 55: /* opt_class_arg: LEFT_BRACKET opt_arglist RIGHT_BRACKET  */
#line 160 "parser.y"
                                             {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--opt_arglist%d;\n",m["opt_class_arg"],m["opt_arglist"]); m["opt_arglist"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1696 "parser.tab.c"
    break;

  case 56: /* opt_arglist: arglist COMMA  */
#line 163 "parser.y"
                               {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;fprintf(yyout,"opt_arglist%d--COMMA%d;\n",m["opt_arglist"],m["COMMA"]); m["COMMA"]++;}
#line 1702 "parser.tab.c"
    break;

  case 57: /* opt_arglist: arglist  */
#line 164 "parser.y"
                              {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;}
#line 1708 "parser.tab.c"
    break;

  case 58: /* arglist: arglist COMMA argument  */
#line 167 "parser.y"
                                    {fprintf(yyout,"arglist%d--COMMA%d;\n",m["arglist"],m["COMMA"]); m["COMMA"]++;fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
#line 1714 "parser.tab.c"
    break;

  case 59: /* arglist: argument  */
#line 168 "parser.y"
                                             {fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
#line 1720 "parser.tab.c"
    break;

  case 60: /* argument: test  */
#line 171 "parser.y"
              {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
#line 1726 "parser.tab.c"
    break;

  case 61: /* argument: test comp_for  */
#line 172 "parser.y"
                        {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--comp_for%d;\n",m["argument"],m["comp_for"]); m["comp_for"]++;}
#line 1732 "parser.tab.c"
    break;

  case 62: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 173 "parser.y"
                                    {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--ASSIGNMENT_OPERATOR%d;\n",m["argument"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
#line 1738 "parser.tab.c"
    break;

  case 63: /* comp_iter: comp_for  */
#line 176 "parser.y"
             {fprintf(yyout,"comp_iter%d--comp_for%d;\n",m["comp_iter"],m["comp_for"]); m["comp_for"]++;}
#line 1744 "parser.tab.c"
    break;

  case 64: /* comp_iter: comp_if  */
#line 177 "parser.y"
                        {fprintf(yyout,"comp_iter%d--comp_if%d;\n",m["comp_iter"],m["comp_if"]); m["comp_if"]++;}
#line 1750 "parser.tab.c"
    break;

  case 65: /* comp_for: FOR exprlist IN or_test  */
#line 180 "parser.y"
                             { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; }
#line 1756 "parser.tab.c"
    break;

  case 66: /* comp_for: FOR exprlist IN or_test comp_iter  */
#line 181 "parser.y"
                                       { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_for%d--comp_iter%d;\n",m["comp_for"],m["comp_iter"]); m["comp_iter"]++;}
#line 1762 "parser.tab.c"
    break;

  case 67: /* comp_if: IF or_test  */
#line 184 "parser.y"
                     { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; }
#line 1768 "parser.tab.c"
    break;

  case 68: /* comp_if: IF or_test comp_iter  */
#line 185 "parser.y"
                              { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_if%d--comp_iter%d;\n",m["comp_if"],m["comp_iter"]); m["comp_iter"]++;}
#line 1774 "parser.tab.c"
    break;

  case 70: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 191 "parser.y"
                                  { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--DEDENT%d;\n",m["suite"],m["DEDENT"]); m["DEDENT"]++;}
#line 1780 "parser.tab.c"
    break;

  case 71: /* suite: NEWLINE INDENT stmt_list $end  */
#line 192 "parser.y"
                                 { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--YYEOF%d;\n",m["suite"],m["YYEOF"]); m["YYEOF"]++;}
#line 1786 "parser.tab.c"
    break;

  case 72: /* stmt_list: stmt_list stmt  */
#line 195 "parser.y"
                {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
#line 1792 "parser.tab.c"
    break;

  case 73: /* stmt_list: stmt  */
#line 196 "parser.y"
       {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
#line 1798 "parser.tab.c"
    break;

  case 74: /* test: or_test IF or_test ELSE test  */
#line 199 "parser.y"
                                                   {fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--IF%d;\n",m["test"],m["IF"]); m["IF"]++;fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--ELSE%d;\n",m["test"],m["ELSE"]); m["ELSE"]++;}
#line 1804 "parser.tab.c"
    break;

  case 75: /* test: or_test  */
#line 200 "parser.y"
                       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1810 "parser.tab.c"
    break;

  case 76: /* or_test: or_test OR and_test  */
#line 203 "parser.y"
                                          {fprintf(yyout,"test%d--OR%d;\n",m["test"],m["OR"]); fprintf(yyout,"OR%d--and_test%d;\n",m["OR"],m["and_test"]);m["OR"]++; m["and_test"]++;}
#line 1816 "parser.tab.c"
    break;

  case 77: /* or_test: and_test  */
#line 204 "parser.y"
                          {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1822 "parser.tab.c"
    break;

  case 78: /* and_test: and_test AND not_test  */
#line 207 "parser.y"
                                          {fprintf(yyout,"and_test%d--AND%d;\n",m["and_test"],m["AND"]); m["AND"]++;fprintf(yyout,"and_test%d--not_test%d;\n",m["and_test"],m["not_test"]); m["not_test"]++;}
#line 1828 "parser.tab.c"
    break;

  case 79: /* and_test: not_test  */
#line 208 "parser.y"
                       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1834 "parser.tab.c"
    break;

  case 80: /* $@2: %empty  */
#line 211 "parser.y"
              {fprintf(yyout,"not_test%d--NOT%d;\n",m["not_test"],m["NOT"]); m["NOT"]++;}
#line 1840 "parser.tab.c"
    break;

  case 82: /* not_test: comparison  */
#line 213 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1846 "parser.tab.c"
    break;

  case 83: /* comparison: comparison RELATIONAL_OPERATOR expr  */
#line 215 "parser.y"
                                                               {fprintf(yyout,"comparison%d--RELATIONAL_OPERATOR%d;\n",m["comparison"],m["RELATIONAL_OPERATOR"]); m["RELATIONAL_OPERATOR"]++;fprintf(yyout,"comparison%d--expr%d;\n",m["comparison"],m["expr"]); m["expr"]++;}
#line 1852 "parser.tab.c"
    break;

  case 84: /* comparison: expr  */
#line 216 "parser.y"
                    {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1858 "parser.tab.c"
    break;

  case 85: /* expr: expr BIT_OR and_expr  */
#line 218 "parser.y"
                                          {fprintf(yyout,"expr%d--BIT_OR%d;\n",m["expr"],m["BIT_OR"]); m["BIT_OR"]++;fprintf(yyout,"expr%d--xor_expr%d;\n",m["expr"],m["xor_expr"]); m["xor_expr"]++;}
#line 1864 "parser.tab.c"
    break;

  case 86: /* expr: xor_expr  */
#line 219 "parser.y"
                           {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1870 "parser.tab.c"
    break;

  case 87: /* xor_expr: xor_expr XOR and_expr  */
#line 221 "parser.y"
                                             {fprintf(yyout,"xor_expr%d--XOR%d;\n",m["xor_expr"],m["XOR"]); m["XOR"]++;fprintf(yyout,"xor_expr%d--and_expr%d;\n",m["xor_expr"],m["and_expr"]); m["and_expr"]++;}
#line 1876 "parser.tab.c"
    break;

  case 88: /* xor_expr: and_expr  */
#line 222 "parser.y"
                            {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1882 "parser.tab.c"
    break;

  case 89: /* and_expr: and_expr BIT_AND shift_expr  */
#line 224 "parser.y"
                                                   {fprintf(yyout,"and_expr%d--BIT_AND%d;\n",m["and_expr"],m["BIT_AND"]); m["BIT_AND"]++;fprintf(yyout,"and_expr%d--shift_expr%d;\n",m["and_expr"],m["shift_expr"]); m["shift_expr"]++;}
#line 1888 "parser.tab.c"
    break;

  case 90: /* and_expr: shift_expr  */
#line 225 "parser.y"
                          {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1894 "parser.tab.c"
    break;

  case 91: /* shift_expr: shift_expr SHIFT arith_expr  */
#line 227 "parser.y"
                                                      {fprintf(yyout,"shift_expr%d--SHIFT%d;\n",m["shift_expr"],m["SHIFT"]); m["SHIFT"]++;fprintf(yyout,"shift_expr%d--arith_expr%d;\n",m["shift_expr"],m["arith_expr"]); m["arith_expr"]++;}
#line 1900 "parser.tab.c"
    break;

  case 92: /* shift_expr: arith_expr  */
#line 228 "parser.y"
                         {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1906 "parser.tab.c"
    break;

  case 93: /* arith_expr: arith_expr ADD term  */
#line 231 "parser.y"
                                      {fprintf(yyout,"arith_expr%d--ADD%d;\n",m["arith_expr"],m["ADD"]); m["ADD"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
#line 1912 "parser.tab.c"
    break;

  case 94: /* arith_expr: arith_expr SUB term  */
#line 232 "parser.y"
                                       {fprintf(yyout,"arith_expr%d--SUB%d;\n",m["arith_expr"],m["SUB"]); m["SUB"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
#line 1918 "parser.tab.c"
    break;

  case 95: /* arith_expr: term  */
#line 233 "parser.y"
                 {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1924 "parser.tab.c"
    break;

  case 96: /* term: term ARITHMETIC_OPERATOR factor  */
#line 235 "parser.y"
                                                      {fprintf(yyout,"term%d--ARITHMETIC_OPERATOR%d;\n",m["term"],m["ARITHMETIC_OPERATOR"]); m["ARITHMETIC_OPERATOR"]++;fprintf(yyout,"term%d--factor%d;\n",m["term"],m["factor"]); m["factor"]++;}
#line 1930 "parser.tab.c"
    break;

  case 97: /* term: factor  */
#line 236 "parser.y"
                   {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1936 "parser.tab.c"
    break;

  case 98: /* factor: ADD factor  */
#line 239 "parser.y"
            {fprintf(yyout,"factor%d--ADD%d;\n",m["factor"],m["ADD"]); m["ADD"]++;}
#line 1942 "parser.tab.c"
    break;

  case 99: /* factor: SUB factor  */
#line 240 "parser.y"
            {fprintf(yyout,"factor%d--SUB%d;\n",m["factor"],m["SUB"]); m["SUB"]++;}
#line 1948 "parser.tab.c"
    break;

  case 100: /* factor: BIT_NOT factor  */
#line 241 "parser.y"
               {fprintf(yyout,"factor%d--BIT_NOT%d;\n",m["factor"],m["BIT_NOT"]); m["BIT_NOT"]++;}
#line 1954 "parser.tab.c"
    break;

  case 101: /* factor: power  */
#line 242 "parser.y"
       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1960 "parser.tab.c"
    break;

  case 102: /* power: atom_expr POWER factor  */
#line 245 "parser.y"
                                   {fprintf(yyout,"power%d--atom_expr%d;\n",m["power"],m["atom_expr"]); m["atom_expr"]++;fprintf(yyout,"power%d--POWER%d;\n",m["power"],m["POWER"]); m["POWER"]++;fprintf(yyout,"power%d--factor%d;\n",m["power"],m["factor"]); m["factor"]++;}
#line 1966 "parser.tab.c"
    break;

  case 103: /* power: atom_expr  */
#line 246 "parser.y"
                      {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1972 "parser.tab.c"
    break;

  case 104: /* atom_expr: atom opt_trailer  */
#line 248 "parser.y"
                                       {fprintf(yyout,"atom_expr%d--atom%d;\n",m["atom_expr"],m["atom"]); m["atom"]++; fprintf(yyout,"atom_expr%d--opt_trailer%d;\n",m["atom_expr"],m["opt_trailer"]); m["opt_trailer"]++;}
#line 1978 "parser.tab.c"
    break;

  case 105: /* atom_expr: atom  */
#line 249 "parser.y"
                {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1984 "parser.tab.c"
    break;

  case 106: /* opt_trailer: opt_trailer trailer  */
#line 252 "parser.y"
                    {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
#line 1990 "parser.tab.c"
    break;

  case 107: /* opt_trailer: trailer  */
#line 253 "parser.y"
         {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
#line 1996 "parser.tab.c"
    break;

  case 108: /* atom: LEFT_BRACKET testlist_comp RIGHT_BRACKET  */
#line 257 "parser.y"
                                         {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2002 "parser.tab.c"
    break;

  case 109: /* atom: LEFT_BRACKET RIGHT_BRACKET  */
#line 258 "parser.y"
                             {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2008 "parser.tab.c"
    break;

  case 110: /* atom: LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET  */
#line 259 "parser.y"
                                           {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 2014 "parser.tab.c"
    break;

  case 111: /* atom: LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET  */
#line 260 "parser.y"
                                                        {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 2020 "parser.tab.c"
    break;

  case 112: /* atom: NAME  */
#line 261 "parser.y"
      {fprintf(yyout,"%d[label=\"Name( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2026 "parser.tab.c"
    break;

  case 113: /* atom: NUMBER  */
#line 262 "parser.y"
        {fprintf(yyout,"atom%d--NUMBER%d;\n",m["atom"],m["NUMBER"]); m["NUMBER"]++;}
#line 2032 "parser.tab.c"
    break;

  case 114: /* atom: DATA_TYPE  */
#line 263 "parser.y"
           {fprintf(yyout,"atom%d--DATA_TYPE%d;\n",m["atom"],m["DATA_TYPE"]); m["DATA_TYPE"]++;}
#line 2038 "parser.tab.c"
    break;

  case 115: /* atom: STRING  */
#line 264 "parser.y"
        {fprintf(yyout,"atom%d--STRING%d;\n",m["atom"],m["STRING"]); m["STRING"]++;}
#line 2044 "parser.tab.c"
    break;

  case 116: /* atom: NONE  */
#line 265 "parser.y"
      {fprintf(yyout,"atom%d--NONE%d;\n",m["atom"],m["NONE"]); m["NONE"]++;}
#line 2050 "parser.tab.c"
    break;

  case 117: /* atom: TRUE  */
#line 266 "parser.y"
      {fprintf(yyout,"atom%d--TRUE%d;\n",m["atom"],m["TRUE"]); m["TRUE"]++;}
#line 2056 "parser.tab.c"
    break;

  case 118: /* atom: FALSE  */
#line 267 "parser.y"
       {fprintf(yyout,"atom%d--FALSE%d;\n",m["atom"],m["FALSE"]); m["FALSE"]++;}
#line 2062 "parser.tab.c"
    break;

  case 119: /* atom: LIST  */
#line 268 "parser.y"
      {fprintf(yyout,"atom%d--LIST%d;\n",m["atom"],m["LIST"]); m["LIST"]++;}
#line 2068 "parser.tab.c"
    break;

  case 120: /* testlist_comp: test comp_for  */
#line 272 "parser.y"
              {fprintf(yyout,"testlist_comp%d--test%d;\n",m["testlist_comp"],m["test"]); m["test"]++; fprintf(yyout,"testlist_comp%d--comp_for%d;\n",m["testlist_comp"],m["comp_for"]); m["comp_for"]++; }
#line 2074 "parser.tab.c"
    break;

  case 121: /* testlist_comp: opt_test_stmt COMMA  */
#line 273 "parser.y"
                      {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++; fprintf(yyout,"testlist_comp%d--COMMA%d;\n",m["testlist_comp"],m["COMMA"]); m["COMMA"]++; }
#line 2080 "parser.tab.c"
    break;

  case 122: /* testlist_comp: opt_test_stmt  */
#line 274 "parser.y"
                {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++;}
#line 2086 "parser.tab.c"
    break;

  case 123: /* opt_test_stmt: test  */
#line 276 "parser.y"
                    {fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;}
#line 2092 "parser.tab.c"
    break;

  case 124: /* opt_test_stmt: opt_test_stmt COMMA test  */
#line 277 "parser.y"
                          {fprintf(yyout,"opt_test_stmt%d--COMMA%d;\n",m["opt_test_stmt"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;}
#line 2098 "parser.tab.c"
    break;

  case 125: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 281 "parser.y"
                                   {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--arglist%d;\n",m["trailer"],m["arglist"]); m["arglist"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2104 "parser.tab.c"
    break;

  case 126: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 282 "parser.y"
                             {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2110 "parser.tab.c"
    break;

  case 127: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 283 "parser.y"
                                                {fprintf(yyout,"trailer%d--LEFT_SQUARE_BRACKET%d;\n",m["trailer"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"trailer%d--test%d;\n",m["trailer"],m["test"]); m["test"]++; fprintf(yyout,"trailer%d--RIGHT_SQUARE_BRACKET%d;\n",m["trailer"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 2116 "parser.tab.c"
    break;

  case 128: /* trailer: DOT NAME  */
#line 284 "parser.y"
           {fprintf(yyout,"trailer%d--DOT%d;\n",m["trailer"],m["DOT"]); m["DOT"]++; fprintf(yyout,"trailer%d--NAME%d;\n",m["trailer"],m["NAME"]); m["NAME"]++;}
#line 2122 "parser.tab.c"
    break;

  case 129: /* testlist: testlist COMMA test  */
#line 288 "parser.y"
                    {fprintf(yyout,"testlist%d--COMMA%d;\n",m["testlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"testlist%d--test%d;\n",m["testlist"],m["test"]); m["test"]++;}
#line 2128 "parser.tab.c"
    break;

  case 130: /* testlist: test  */
#line 289 "parser.y"
       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2134 "parser.tab.c"
    break;

  case 131: /* exprlist: exprlist COMMA expr  */
#line 293 "parser.y"
                    {fprintf(yyout,"exprlist%d--COMMA%d;\n",m["exprlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;}
#line 2140 "parser.tab.c"
    break;

  case 132: /* exprlist: expr  */
#line 294 "parser.y"
       {fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;}
#line 2146 "parser.tab.c"
    break;


#line 2150 "parser.tab.c"

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

#line 297 "parser.y"

const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   cout<<"Error in Line no "<<yylineno<<endl;
   cout<< "The Last Lexem is "<<yytext<<endl;
   cout<< "The Last Token is "<<token_name(yychar)<<endl;
   return ;
}

int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   fprintf(yyout,"Graph {\n");
   yydebug=0;
   yyparse();
   fprintf(yyout,"}");
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}
