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


#line 88 "parser.tab.c"

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
  YYSYMBOL_ADD_SUB = 41,                   /* ADD_SUB  */
  YYSYMBOL_POWER = 42,                     /* POWER  */
  YYSYMBOL_BIT_AND = 43,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 44,                    /* BIT_OR  */
  YYSYMBOL_NUMBER = 45,                    /* NUMBER  */
  YYSYMBOL_STRING = 46,                    /* STRING  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_SHIFT = 48,                     /* SHIFT  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 49,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 50,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_low = 51,                       /* low  */
  YYSYMBOL_low1 = 52,                      /* low1  */
  YYSYMBOL_low2 = 53,                      /* low2  */
  YYSYMBOL_low3 = 54,                      /* low3  */
  YYSYMBOL_low4 = 55,                      /* low4  */
  YYSYMBOL_low5 = 56,                      /* low5  */
  YYSYMBOL_low6 = 57,                      /* low6  */
  YYSYMBOL_high = 58,                      /* high  */
  YYSYMBOL_high1 = 59,                     /* high1  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_module = 61,                    /* module  */
  YYSYMBOL_stmt = 62,                      /* stmt  */
  YYSYMBOL_simple_stmt = 63,               /* simple_stmt  */
  YYSYMBOL_more_expr = 64,                 /* more_expr  */
  YYSYMBOL_small_stmt = 65,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 66,                 /* expr_stmt  */
  YYSYMBOL_right_assign = 67,              /* right_assign  */
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
  YYSYMBOL_full_tfpdef = 82,               /* full_tfpdef  */
  YYSYMBOL_classdef = 83,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 84,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 85,               /* opt_arglist  */
  YYSYMBOL_arglist = 86,                   /* arglist  */
  YYSYMBOL_argument = 87,                  /* argument  */
  YYSYMBOL_comp_iter = 88,                 /* comp_iter  */
  YYSYMBOL_comp_for = 89,                  /* comp_for  */
  YYSYMBOL_comp_if = 90,                   /* comp_if  */
  YYSYMBOL_suite = 91,                     /* suite  */
  YYSYMBOL_stmt_list = 92,                 /* stmt_list  */
  YYSYMBOL_test = 93,                      /* test  */
  YYSYMBOL_test_nocond = 94,               /* test_nocond  */
  YYSYMBOL_or_test = 95,                   /* or_test  */
  YYSYMBOL_or_and_test_plus = 96,          /* or_and_test_plus  */
  YYSYMBOL_and_test = 97,                  /* and_test  */
  YYSYMBOL_and_not_test_plus = 98,         /* and_not_test_plus  */
  YYSYMBOL_not_test = 99,                  /* not_test  */
  YYSYMBOL_comparison = 100,               /* comparison  */
  YYSYMBOL_opt_expr = 101,                 /* opt_expr  */
  YYSYMBOL_expr = 102,                     /* expr  */
  YYSYMBOL_opt_xor = 103,                  /* opt_xor  */
  YYSYMBOL_xor_expr = 104,                 /* xor_expr  */
  YYSYMBOL_opt_and_plus = 105,             /* opt_and_plus  */
  YYSYMBOL_and_expr = 106,                 /* and_expr  */
  YYSYMBOL_opt_shift = 107,                /* opt_shift  */
  YYSYMBOL_shift_expr = 108,               /* shift_expr  */
  YYSYMBOL_opt_arith = 109,                /* opt_arith  */
  YYSYMBOL_arith_expr = 110,               /* arith_expr  */
  YYSYMBOL_opt_term = 111,                 /* opt_term  */
  YYSYMBOL_term = 112,                     /* term  */
  YYSYMBOL_opt_factor = 113,               /* opt_factor  */
  YYSYMBOL_factor = 114,                   /* factor  */
  YYSYMBOL_oper = 115,                     /* oper  */
  YYSYMBOL_power = 116,                    /* power  */
  YYSYMBOL_atom_expr = 117,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 118,              /* opt_trailer  */
  YYSYMBOL_atom = 119,                     /* atom  */
  YYSYMBOL_testlist_comp = 120,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 121,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 122,                  /* trailer  */
  YYSYMBOL_subscriptlist = 123,            /* subscriptlist  */
  YYSYMBOL_opt_subscript = 124,            /* opt_subscript  */
  YYSYMBOL_subscript = 125,                /* subscript  */
  YYSYMBOL_sliceop = 126,                  /* sliceop  */
  YYSYMBOL_testlist = 127,                 /* testlist  */
  YYSYMBOL_exprlist = 128                  /* exprlist  */
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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    40,    42,    42,    42,    42,    45,    46,
      48,    49,    51,    52,    53,    54,    57,    59,    60,    61,
      63,    63,    65,    66,    69,    71,    73,    74,    78,    78,
      78,    78,    78,    80,    81,    82,    83,    85,    86,    88,
      91,    92,    95,    96,    99,   100,   103,   104,   107,   108,
     111,   112,   114,   115,   117,   118,   120,   121,   123,   124,
     126,   127,   128,   130,   131,   133,   134,   136,   137,   141,
     141,   142,   144,   144,   147,   148,   150,   152,   153,   155,
     156,   158,   159,   161,   162,   164,   165,   167,   168,   170,
     171,   173,   174,   176,   177,   179,   180,   182,   183,   185,
     186,   188,   189,   191,   192,   194,   195,   197,   198,   200,
     201,   203,   204,   206,   207,   209,   210,   212,   213,   215,
     216,   218,   219,   221,   222,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   238,   239,   240,
     242,   243,   245,   246,   247,   248,   249,   250,   252,   253,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   267,
     268,   271,   271,   274,   274
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
  "XOR", "BIT_NOT", "ADD_SUB", "POWER", "BIT_AND", "BIT_OR", "NUMBER",
  "STRING", "DOT", "SHIFT", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET",
  "low", "low1", "low2", "low3", "low4", "low5", "low6", "high", "high1",
  "$accept", "module", "stmt", "simple_stmt", "more_expr", "small_stmt",
  "expr_stmt", "right_assign", "Assign_stmt", "annassign", "break_stmt",
  "continue_stmt", "return_stmt", "compound_stmt", "if_stmt",
  "elif_statements", "else_statement", "while_stmt", "for_stmt", "funcdef",
  "parameters", "typedargslist", "full_tfpdef", "classdef",
  "opt_class_arg", "opt_arglist", "arglist", "argument", "comp_iter",
  "comp_for", "comp_if", "suite", "stmt_list", "test", "test_nocond",
  "or_test", "or_and_test_plus", "and_test", "and_not_test_plus",
  "not_test", "comparison", "opt_expr", "expr", "opt_xor", "xor_expr",
  "opt_and_plus", "and_expr", "opt_shift", "shift_expr", "opt_arith",
  "arith_expr", "opt_term", "term", "opt_factor", "factor", "oper",
  "power", "atom_expr", "opt_trailer", "atom", "testlist_comp",
  "opt_test_stmt", "trailer", "subscriptlist", "opt_subscript",
  "subscript", "sliceop", "testlist", "exprlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,  -179,   425,   402,   402,  -179,    10,  -179,  -179,    16,
    -179,   287,  -179,  -179,  -179,    15,   402,   402,  -179,  -179,
    -179,  -179,  -179,    51,   136,  -179,    59,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    71,
      48,    52,  -179,    88,    60,    67,    53,    61,    70,   113,
     425,  -179,    76,    13,    65,  -179,     1,   100,   101,    39,
    -179,   114,   102,    98,  -179,    99,   104,  -179,   105,  -179,
    -179,   264,   402,   402,    91,   402,    89,   425,   126,   425,
      87,   425,    96,   425,    93,   425,    86,   425,    97,   425,
     134,  -179,   425,   310,   333,   115,    13,  -179,   402,   402,
     402,   402,  -179,   141,  -179,   425,   402,   241,   241,   241,
     356,   135,   425,  -179,  -179,   402,  -179,     4,    55,  -179,
      65,   143,  -179,   402,  -179,   402,  -179,   425,  -179,   425,
    -179,   425,  -179,   425,  -179,   425,  -179,   425,  -179,   425,
    -179,  -179,    57,  -179,    79,   379,   138,   127,   139,  -179,
    -179,  -179,   105,   105,   153,  -179,   402,  -179,    31,   131,
    -179,   159,    58,  -179,  -179,   154,   155,   241,    12,  -179,
    -179,   160,    72,  -179,   241,   402,   402,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,   402,   402,  -179,
     402,   161,  -179,   379,  -179,   333,   402,   105,   241,   136,
     164,  -179,   402,   103,  -179,  -179,   402,  -179,   402,  -179,
    -179,   162,  -179,   169,  -179,  -179,  -179,  -179,  -179,   161,
    -179,  -179,  -179,   159,  -179,   206,   241,   170,   402,  -179,
      95,  -179,   241,  -179,  -179,  -179,  -179,  -179,  -179,   241,
     172,   402,  -179,  -179,  -179,  -179,  -179,   241,    95,  -179,
    -179,  -179
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,   131,     0,     0,     0,    24,     0,    25,   136,     0,
     129,     0,   133,   134,   135,     0,     0,    26,     4,   118,
     117,   130,   132,     0,     3,     5,     8,    11,    12,    13,
      14,    15,     6,    28,    29,    30,    31,    32,   162,    75,
      78,    82,    86,    88,    92,    96,   100,   104,   108,   112,
       0,   116,   120,   122,     7,   164,     0,     0,     0,     0,
     127,   140,     0,   139,   128,     0,     0,    85,    27,     1,
       2,     9,     0,     0,    77,     0,    81,     0,    87,     0,
      91,     0,    95,     0,    99,     0,   103,     0,   107,     0,
     111,   115,     0,     0,     0,     0,   121,   124,     0,     0,
       0,     0,    16,    19,    17,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   125,   138,   126,     0,     0,    10,
       0,     0,    79,     0,    83,     0,    90,     0,    93,     0,
      97,     0,   101,     0,   105,     0,   109,     0,   113,     0,
     119,   143,     0,    59,    60,   158,   150,     0,   147,   149,
     145,   123,    21,    18,    23,   161,     0,   163,     0,     0,
      69,    40,    33,    53,    54,     0,    57,     0,     0,   141,
      46,    51,     0,    49,     0,     0,     0,    80,    84,    89,
      94,    98,   102,   106,   110,   114,   142,     0,     0,    61,
     160,   154,   157,   156,   144,   146,     0,    20,     0,     0,
       0,    41,     0,    35,    34,    55,    56,    52,     0,    50,
      47,     0,    44,     0,    74,    58,    62,   159,   153,   152,
     155,   148,    22,    42,    73,     0,     0,     0,     0,    36,
      65,    48,     0,   151,    43,    71,    70,    72,    39,     0,
       0,     0,    66,    63,    64,    45,    38,     0,    67,    76,
      37,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,   171,  -178,     3,  -179,   123,  -179,  -179,  -179,    25,
    -179,  -179,  -179,  -179,  -179,  -179,  -150,  -179,  -179,  -179,
    -179,  -179,   -14,  -179,  -179,  -179,    90,  -157,   -44,   -50,
    -179,   -99,  -179,    -3,  -179,   -67,  -179,   -59,  -179,   -12,
    -179,  -179,     5,  -179,   -64,  -179,   -65,  -179,   -66,  -179,
     -63,  -179,   -58,  -179,   -37,  -179,  -179,  -179,  -179,  -179,
     187,  -179,   109,  -179,  -179,    14,  -173,     2,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,   160,    26,    27,    28,   102,   103,   104,
      29,    30,    31,    32,    33,   203,   201,    34,    35,    36,
     118,   172,   173,    37,   111,   165,   142,   143,   242,   243,
     244,   161,   225,    38,   248,    39,    74,    40,    76,    41,
      42,    78,    43,    80,    44,    82,    45,    84,    46,    86,
      47,    88,    48,    90,    49,    50,    51,    52,    96,    53,
      62,    63,    97,   147,   148,   149,   192,   120,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    54,    25,    67,   121,    61,    55,    61,   162,
     163,   113,   204,    91,   122,   128,   130,   132,   218,    68,
     220,   224,   134,     1,   105,   170,    54,    25,   171,   136,
     215,   106,     8,    93,    59,   105,     9,    60,    94,    66,
      10,    11,   208,    12,    13,    14,   233,   237,    16,   215,
     198,    69,   138,   229,   101,   140,    19,    20,   109,   110,
      95,    21,    22,   124,   177,   180,   181,   182,   207,   202,
     200,    98,   183,   234,   174,   212,    71,   175,   186,   184,
     187,    72,   126,    99,   100,   188,    73,   112,   101,    75,
     144,   146,    77,   210,   189,   211,    83,   154,   155,   223,
     152,   153,   185,   112,    79,   241,    81,   144,   158,    85,
     157,    87,   169,   178,   228,   200,    89,    55,    92,   107,
     108,   115,   112,   114,   117,   116,   125,   238,   101,   123,
     127,   129,   179,   245,   135,   131,   133,   139,   137,   150,
     246,   230,   191,     1,     2,     3,     4,   156,   250,     5,
       6,     7,     8,   194,   167,   176,     9,   193,   197,   196,
      10,    11,   195,    12,    13,    14,   199,    15,    16,    17,
      18,   200,   213,   214,   249,   205,    19,    20,   206,   100,
     190,    21,    22,   226,   144,   216,   171,   217,   232,   239,
     219,   247,   146,   222,   119,    70,   209,   231,    65,   227,
     166,    54,    25,   144,   251,   151,   235,     0,     0,   221,
       0,     0,     0,     1,     2,     3,     4,     0,   168,     5,
       6,     7,     8,     0,     0,   240,     9,    54,    25,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,    17,
      18,     0,   236,     0,     0,     0,    19,    20,     1,     0,
       0,    21,    22,     0,     5,     0,     7,     8,     0,     0,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,     1,     0,    16,    17,   159,     0,     5,     0,     7,
       8,    19,    20,     0,     9,     0,    21,    22,    10,    11,
       0,    12,    13,    14,     1,     0,    16,    17,     0,     0,
       0,     0,     0,     8,    19,    20,     0,     9,     0,    21,
      22,    10,    11,    64,    12,    13,    14,     1,     0,    16,
       0,     0,     0,     0,     0,     0,     8,    19,    20,     0,
       9,   141,    21,    22,    10,    11,     0,    12,    13,    14,
       1,     0,    16,     0,     0,     0,     0,     0,     0,     8,
      19,    20,   145,     9,     0,    21,    22,    10,    11,     0,
      12,    13,    14,     1,     0,    16,     0,     0,     0,     0,
       0,     0,     8,    19,    20,     0,     9,   164,    21,    22,
      10,    11,     0,    12,    13,    14,     1,     0,    16,     0,
       0,     0,     0,     0,     0,     8,    19,    20,   190,     9,
       0,    21,    22,    10,    11,     0,    12,    13,    14,     1,
       0,    16,     0,     0,     0,     0,     0,     0,     8,    19,
      20,     0,     9,     0,    21,    22,    10,    11,     0,    12,
      13,    14,     1,     0,    16,     0,     0,     0,     0,     0,
       0,     8,    19,    20,     0,     9,     0,    21,    22,    10,
      11,     0,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
      21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    16,    72,     9,     2,    11,   108,
     109,    61,   162,    50,    73,    79,    81,    83,   191,    17,
     193,   199,    85,     7,    23,    21,    24,    24,    24,    87,
     187,    30,    16,    20,    24,    23,    20,    21,    25,    24,
      24,    25,    30,    27,    28,    29,   219,   225,    32,   206,
      19,     0,    89,   203,    23,    92,    40,    41,    19,    20,
      47,    45,    46,    75,   123,   129,   131,   133,   167,    11,
      12,     6,   135,   223,    19,   174,    17,    22,    21,   137,
      23,    10,    77,    18,    19,     6,    38,     8,    23,    37,
      93,    94,     4,    21,   144,    23,    43,   100,   101,   198,
      98,    99,   139,     8,    44,    10,    39,   110,   106,    48,
     105,    41,   115,   125,    11,    12,     3,   112,    42,    19,
      19,    23,     8,    21,    20,    26,    37,   226,    23,    38,
       4,    44,   127,   232,    48,    39,    43,     3,    41,    24,
     239,   208,   145,     7,     8,     9,    10,     6,   247,    13,
      14,    15,    16,    26,    19,    12,    20,    19,   156,     6,
      24,    25,    23,    27,    28,    29,    35,    31,    32,    33,
      34,    12,   175,   176,   241,    21,    40,    41,    23,    19,
      19,    45,    46,    19,   187,   188,    24,   190,    19,    19,
     193,    19,   195,   196,    71,    24,   171,   211,    11,   202,
     110,   199,   199,   206,   248,    96,     0,    -1,    -1,   195,
      -1,    -1,    -1,     7,     8,     9,    10,    -1,   112,    13,
      14,    15,    16,    -1,    -1,   228,    20,   225,   225,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    40,    41,     7,    -1,
      -1,    45,    46,    -1,    13,    -1,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,     7,    -1,    32,    33,    34,    -1,    13,    -1,    15,
      16,    40,    41,    -1,    20,    -1,    45,    46,    24,    25,
      -1,    27,    28,    29,     7,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    16,    40,    41,    -1,    20,    -1,    45,
      46,    24,    25,    26,    27,    28,    29,     7,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    40,    41,    -1,
      20,    21,    45,    46,    24,    25,    -1,    27,    28,    29,
       7,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      40,    41,    19,    20,    -1,    45,    46,    24,    25,    -1,
      27,    28,    29,     7,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    40,    41,    -1,    20,    21,    45,    46,
      24,    25,    -1,    27,    28,    29,     7,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    40,    41,    19,    20,
      -1,    45,    46,    24,    25,    -1,    27,    28,    29,     7,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    16,    40,
      41,    -1,    20,    -1,    45,    46,    24,    25,    -1,    27,
      28,    29,     7,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    40,    41,    -1,    20,    -1,    45,    46,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    45,    46,    61,    62,    63,    64,    65,    66,    70,
      71,    72,    73,    74,    77,    78,    79,    83,    93,    95,
      97,    99,   100,   102,   104,   106,   108,   110,   112,   114,
     115,   116,   117,   119,   127,   102,   128,    93,    93,    24,
      21,    93,   120,   121,    26,   120,    24,    99,   127,     0,
      61,    17,    10,    38,    96,    37,    98,     4,   101,    44,
     103,    39,   105,    43,   107,    48,   109,    41,   111,     3,
     113,   114,    42,    20,    25,    47,   118,   122,     6,    18,
      19,    23,    67,    68,    69,    23,    30,    19,    19,    19,
      20,    84,     8,    89,    21,    23,    26,    20,    80,    65,
     127,    95,    97,    38,    99,    37,   102,     4,   104,    44,
     106,    39,   108,    43,   110,    48,   112,    41,   114,     3,
     114,    21,    86,    87,    93,    19,    93,   123,   124,   125,
      24,   122,   127,   127,    93,    93,     6,   102,   127,    34,
      63,    91,    91,    91,    21,    85,    86,    19,   128,    93,
      21,    24,    81,    82,    19,    22,    12,    97,    99,   102,
     104,   106,   108,   110,   112,   114,    21,    23,     6,    89,
      19,    93,   126,    19,    26,    23,     6,   127,    19,    35,
      12,    76,    11,    75,    76,    21,    23,    91,    30,    69,
      21,    23,    91,    93,    93,    87,    93,    93,   126,    93,
     126,   125,    93,    91,    62,    92,    19,    93,    11,    76,
      95,    82,    19,   126,    76,     0,    36,    62,    91,    19,
      93,    10,    88,    89,    90,    91,    91,    19,    94,    95,
      91,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   120,
     121,   121,   122,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     2,     4,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     5,     5,     6,     5,     4,     3,
       4,     5,     6,     7,     5,     7,     2,     3,     3,     1,
       2,     1,     5,     4,     2,     3,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     4,     5,     2,     3,     1,
       4,     4,     2,     1,     5,     1,     1,     2,     1,     2,
       3,     2,     1,     2,     3,     2,     1,     2,     1,     3,
       2,     2,     1,     2,     3,     2,     1,     2,     3,     2,
       1,     2,     3,     2,     1,     2,     3,     2,     1,     2,
       3,     2,     1,     2,     3,     2,     1,     1,     1,     3,
       1,     2,     1,     2,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     3,     3,     2,     3,     2,     2,     1,     3,     1,
       1,     4,     3,     3,     2,     3,     2,     2,     1,     2,
       1,     3,     1,     3,     1
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
  case 10: /* more_expr: more_expr SEMICOLON small_stmt  */
#line 48 "parser.y"
                                         {cout<<"y";}
#line 1446 "parser.tab.c"
    break;


#line 1450 "parser.tab.c"

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

#line 278 "parser.y"


void yyerror(const char *s){
   cout<<" f u \n"<<yytext;
   return ;
}


int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   
   yydebug=0;
   yyparse();
   
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}
