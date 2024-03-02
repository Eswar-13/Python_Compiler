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

map<string,int> m;


#line 90 "parser.tab.c"

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
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_simple_stmt = 64,               /* simple_stmt  */
  YYSYMBOL_more_expr = 65,                 /* more_expr  */
  YYSYMBOL_small_stmt = 66,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 67,                 /* expr_stmt  */
  YYSYMBOL_right_assign = 68,              /* right_assign  */
  YYSYMBOL_Assign_stmt = 69,               /* Assign_stmt  */
  YYSYMBOL_annassign = 70,                 /* annassign  */
  YYSYMBOL_break_stmt = 71,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 72,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 73,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 74,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 75,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 76,           /* elif_statements  */
  YYSYMBOL_else_statement = 77,            /* else_statement  */
  YYSYMBOL_while_stmt = 78,                /* while_stmt  */
  YYSYMBOL_for_stmt = 79,                  /* for_stmt  */
  YYSYMBOL_funcdef = 80,                   /* funcdef  */
  YYSYMBOL_parameters = 81,                /* parameters  */
  YYSYMBOL_typedargslist = 82,             /* typedargslist  */
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
  YYSYMBOL_test_nocond = 95,               /* test_nocond  */
  YYSYMBOL_or_test = 96,                   /* or_test  */
  YYSYMBOL_or_and_test_plus = 97,          /* or_and_test_plus  */
  YYSYMBOL_and_test = 98,                  /* and_test  */
  YYSYMBOL_and_not_test_plus = 99,         /* and_not_test_plus  */
  YYSYMBOL_not_test = 100,                 /* not_test  */
  YYSYMBOL_comparison = 101,               /* comparison  */
  YYSYMBOL_opt_expr = 102,                 /* opt_expr  */
  YYSYMBOL_expr = 103,                     /* expr  */
  YYSYMBOL_opt_xor = 104,                  /* opt_xor  */
  YYSYMBOL_xor_expr = 105,                 /* xor_expr  */
  YYSYMBOL_opt_and_plus = 106,             /* opt_and_plus  */
  YYSYMBOL_and_expr = 107,                 /* and_expr  */
  YYSYMBOL_opt_shift = 108,                /* opt_shift  */
  YYSYMBOL_shift_expr = 109,               /* shift_expr  */
  YYSYMBOL_opt_arith = 110,                /* opt_arith  */
  YYSYMBOL_arith_expr = 111,               /* arith_expr  */
  YYSYMBOL_opt_term = 112,                 /* opt_term  */
  YYSYMBOL_term = 113,                     /* term  */
  YYSYMBOL_opt_factor = 114,               /* opt_factor  */
  YYSYMBOL_factor = 115,                   /* factor  */
  YYSYMBOL_oper = 116,                     /* oper  */
  YYSYMBOL_power = 117,                    /* power  */
  YYSYMBOL_atom_expr = 118,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 119,              /* opt_trailer  */
  YYSYMBOL_atom = 120,                     /* atom  */
  YYSYMBOL_testlist_comp = 121,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 122,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 123,                  /* trailer  */
  YYSYMBOL_subscriptlist = 124,            /* subscriptlist  */
  YYSYMBOL_opt_subscript = 125,            /* opt_subscript  */
  YYSYMBOL_subscript = 126,                /* subscript  */
  YYSYMBOL_sliceop = 127,                  /* sliceop  */
  YYSYMBOL_testlist = 128,                 /* testlist  */
  YYSYMBOL_exprlist = 129                  /* exprlist  */
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
#define YYLAST   477

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

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
       0,    50,    50,    50,    51,    54,    55,    56,    57,    60,
      61,    63,    64,    66,    67,    68,    69,    72,    74,    75,
      76,    78,    78,    80,    81,    84,    86,    88,    89,    93,
      94,    95,    96,    97,    99,   100,   101,   102,   104,   105,
     107,   110,   111,   114,   115,   118,   119,   122,   123,   126,
     127,   130,   131,   133,   134,   136,   137,   139,   140,   142,
     143,   145,   146,   147,   149,   150,   152,   153,   155,   156,
     160,   161,   162,   164,   165,   168,   169,   171,   173,   174,
     176,   177,   179,   180,   182,   183,   185,   186,   188,   189,
     191,   192,   194,   195,   197,   198,   200,   201,   203,   204,
     206,   207,   209,   210,   212,   213,   215,   216,   218,   219,
     221,   222,   224,   225,   227,   228,   230,   231,   233,   234,
     236,   237,   239,   240,   242,   243,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   259,   260,
     261,   263,   264,   266,   267,   268,   269,   270,   271,   273,
     274,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     288,   289,   292,   292,   295,   295
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
  "$accept", "module", "$@1", "stmt", "simple_stmt", "more_expr",
  "small_stmt", "expr_stmt", "right_assign", "Assign_stmt", "annassign",
  "break_stmt", "continue_stmt", "return_stmt", "compound_stmt", "if_stmt",
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

#define YYPACT_NINF (-178)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     247,  -178,   431,   408,   408,  -178,    28,  -178,  -178,    14,
    -178,   293,  -178,  -178,  -178,    32,   408,   408,  -178,  -178,
    -178,  -178,  -178,    26,  -178,  -178,    49,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    61,
      42,    51,  -178,    85,    52,    67,    60,    62,    74,   113,
     431,  -178,    75,     0,    64,  -178,    -1,    99,   100,    17,
    -178,   114,   102,    98,  -178,   103,   104,  -178,   105,  -178,
     247,   270,   408,   408,    87,   408,    89,   431,   123,   431,
      88,   431,    91,   431,    92,   431,    83,   431,    93,   431,
     134,  -178,   431,   316,   339,   116,     0,  -178,   408,   408,
     408,   408,  -178,   132,  -178,   431,   408,   137,   137,   137,
     362,   122,   431,  -178,  -178,   408,  -178,    29,    57,  -178,
    -178,    64,   133,  -178,   408,  -178,   408,  -178,   431,  -178,
     431,  -178,   431,  -178,   431,  -178,   431,  -178,   431,  -178,
     431,  -178,  -178,    63,  -178,    86,   385,   128,   125,   126,
    -178,  -178,  -178,   105,   105,   142,  -178,   408,  -178,     9,
     120,  -178,   144,    33,  -178,  -178,   139,   135,   137,    10,
    -178,  -178,   148,    81,  -178,   137,   408,   408,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   408,   408,
    -178,   408,   149,  -178,   385,  -178,   339,   408,   105,   137,
     247,   153,  -178,   408,    50,  -178,  -178,   408,  -178,   408,
    -178,  -178,   152,  -178,   160,  -178,  -178,  -178,  -178,  -178,
     149,  -178,  -178,  -178,   144,  -178,   207,   137,   161,   408,
    -178,   101,  -178,   137,  -178,  -178,  -178,  -178,  -178,  -178,
     137,   162,   408,  -178,  -178,  -178,  -178,  -178,   137,   101,
    -178,  -178,  -178
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   132,     0,     0,     0,    25,     0,    26,   137,     0,
     130,     0,   134,   135,   136,     0,     0,    27,     5,   119,
     118,   131,   133,     0,     2,     6,     9,    12,    13,    14,
      15,    16,     7,    29,    30,    31,    32,    33,   163,    76,
      79,    83,    87,    89,    93,    97,   101,   105,   109,   113,
       0,   117,   121,   123,     8,   165,     0,     0,     0,     0,
     128,   141,     0,   140,   129,     0,     0,    86,    28,     1,
       4,    10,     0,     0,    78,     0,    82,     0,    88,     0,
      92,     0,    96,     0,   100,     0,   104,     0,   108,     0,
     112,   116,     0,     0,     0,     0,   122,   125,     0,     0,
       0,     0,    17,    20,    18,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   126,   139,   127,     0,     0,     3,
      11,     0,     0,    80,     0,    84,     0,    91,     0,    94,
       0,    98,     0,   102,     0,   106,     0,   110,     0,   114,
       0,   120,   144,     0,    60,    61,   159,   151,     0,   148,
     150,   146,   124,    22,    19,    24,   162,     0,   164,     0,
       0,    70,    41,    34,    54,    55,     0,    58,     0,     0,
     142,    47,    52,     0,    50,     0,     0,     0,    81,    85,
      90,    95,    99,   103,   107,   111,   115,   143,     0,     0,
      62,   161,   155,   158,   157,   145,   147,     0,    21,     0,
       0,     0,    42,     0,    36,    35,    56,    57,    53,     0,
      51,    48,     0,    45,     0,    75,    59,    63,   160,   154,
     153,   156,   149,    23,    43,    74,     0,     0,     0,     0,
      37,    66,    49,     0,   152,    44,    72,    71,    73,    40,
       0,     0,     0,    67,    64,    65,    46,    39,     0,    68,
      77,    38,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   117,  -178,  -177,     3,  -178,   118,  -178,  -178,  -178,
      -9,  -178,  -178,  -178,  -178,  -178,  -178,  -147,  -178,  -178,
    -178,  -178,  -178,   -28,  -178,  -178,  -178,    80,  -176,   -57,
     -50,  -178,   -94,  -178,    -3,  -178,   -67,  -178,   -66,  -178,
     -12,  -178,  -178,     8,  -178,   -62,  -178,   -68,  -178,   -65,
    -178,   -61,  -178,   -60,  -178,   -41,  -178,  -178,  -178,  -178,
    -178,   184,  -178,   109,  -178,  -178,     1,  -127,     2,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    70,    24,   161,    26,    27,    28,   102,   103,
     104,    29,    30,    31,    32,    33,   204,   202,    34,    35,
      36,   118,   173,   174,    37,   111,   166,   143,   144,   243,
     244,   245,   162,   226,    38,   249,    39,    74,    40,    76,
      41,    42,    78,    43,    80,    44,    82,    45,    84,    46,
      86,    47,    88,    48,    90,    49,    50,    51,    52,    96,
      53,    62,    63,    97,   148,   149,   150,   193,   121,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    54,    25,    67,   122,    61,   123,    61,    91,
      55,   113,   216,   131,   163,   164,   205,   129,   133,    68,
      93,     1,   105,   225,   135,    94,    69,   137,   199,   106,
       8,   216,   101,   105,     9,    60,   109,   110,    10,    11,
     209,    12,    13,    14,   203,   201,    16,    95,   139,   238,
     171,   141,    59,   172,    19,    20,    66,   230,   178,    21,
      22,   229,   201,   125,   182,   219,    71,   221,   181,   183,
      98,    72,    54,    25,   208,   184,   175,   235,   185,   176,
      73,   213,    99,   100,   187,   127,   188,   101,    75,    77,
     145,   147,   189,   234,   112,   190,    79,   155,   156,   186,
     153,   154,   211,    83,   212,   224,    81,   145,   159,   112,
      85,   242,   170,   158,   179,    87,    89,    92,   107,   108,
      55,   115,   112,   114,   117,   124,   126,   128,   101,   116,
     132,   136,   130,   239,   138,   134,   180,   140,   157,   246,
     151,   168,   231,   192,     1,   177,   247,   194,   197,   196,
       5,   195,     7,     8,   251,   200,   201,     9,   207,   198,
     206,    10,    11,   210,    12,    13,    14,   100,   191,    16,
      17,   160,   227,   214,   215,   250,   172,    19,    20,   233,
     240,   248,    21,    22,   232,   145,   217,   119,   218,   120,
     167,   220,   252,   147,   223,    65,   169,   222,     0,     0,
     228,     0,    54,    25,   145,   152,     0,   236,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       5,     6,     7,     8,     0,     0,   241,     9,    54,    25,
       0,    10,    11,     0,    12,    13,    14,     0,    15,    16,
      17,    18,     0,   237,     0,     0,     0,    19,    20,     0,
       0,     0,    21,    22,     1,     2,     3,     4,     0,     0,
       5,     6,     7,     8,     0,     0,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     1,    15,    16,
      17,    18,     0,     5,     0,     7,     8,    19,    20,     0,
       9,     0,    21,    22,    10,    11,     0,    12,    13,    14,
       1,     0,    16,    17,     0,     0,     0,     0,     0,     8,
      19,    20,     0,     9,     0,    21,    22,    10,    11,    64,
      12,    13,    14,     1,     0,    16,     0,     0,     0,     0,
       0,     0,     8,    19,    20,     0,     9,   142,    21,    22,
      10,    11,     0,    12,    13,    14,     1,     0,    16,     0,
       0,     0,     0,     0,     0,     8,    19,    20,   146,     9,
       0,    21,    22,    10,    11,     0,    12,    13,    14,     1,
       0,    16,     0,     0,     0,     0,     0,     0,     8,    19,
      20,     0,     9,   165,    21,    22,    10,    11,     0,    12,
      13,    14,     1,     0,    16,     0,     0,     0,     0,     0,
       0,     8,    19,    20,   191,     9,     0,    21,    22,    10,
      11,     0,    12,    13,    14,     1,     0,    16,     0,     0,
       0,     0,     0,     0,     8,    19,    20,     0,     9,     0,
      21,    22,    10,    11,     0,    12,    13,    14,     1,     0,
      16,     0,     0,     0,     0,     0,     0,     8,    19,    20,
       0,     9,     0,    21,    22,    10,    11,     0,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    16,    72,     9,    73,    11,    50,
       2,    61,   188,    81,   108,   109,   163,    79,    83,    17,
      20,     7,    23,   200,    85,    25,     0,    87,    19,    30,
      16,   207,    23,    23,    20,    21,    19,    20,    24,    25,
      30,    27,    28,    29,    11,    12,    32,    47,    89,   226,
      21,    92,    24,    24,    40,    41,    24,   204,   124,    45,
      46,    11,    12,    75,   132,   192,    17,   194,   130,   134,
       6,    10,    70,    70,   168,   136,    19,   224,   138,    22,
      38,   175,    18,    19,    21,    77,    23,    23,    37,     4,
      93,    94,     6,   220,     8,   145,    44,   100,   101,   140,
      98,    99,    21,    43,    23,   199,    39,   110,   106,     8,
      48,    10,   115,   105,   126,    41,     3,    42,    19,    19,
     112,    23,     8,    21,    20,    38,    37,     4,    23,    26,
      39,    48,    44,   227,    41,    43,   128,     3,     6,   233,
      24,    19,   209,   146,     7,    12,   240,    19,     6,    23,
      13,    26,    15,    16,   248,    35,    12,    20,    23,   157,
      21,    24,    25,   172,    27,    28,    29,    19,    19,    32,
      33,    34,    19,   176,   177,   242,    24,    40,    41,    19,
      19,    19,    45,    46,   212,   188,   189,    70,   191,    71,
     110,   194,   249,   196,   197,    11,   112,   196,    -1,    -1,
     203,    -1,   200,   200,   207,    96,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,   229,    20,   226,   226,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    -1,    36,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    45,    46,     7,     8,     9,    10,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,     7,    31,    32,
      33,    34,    -1,    13,    -1,    15,    16,    40,    41,    -1,
      20,    -1,    45,    46,    24,    25,    -1,    27,    28,    29,
       7,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    16,
      40,    41,    -1,    20,    -1,    45,    46,    24,    25,    26,
      27,    28,    29,     7,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    40,    41,    -1,    20,    21,    45,    46,
      24,    25,    -1,    27,    28,    29,     7,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    40,    41,    19,    20,
      -1,    45,    46,    24,    25,    -1,    27,    28,    29,     7,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    16,    40,
      41,    -1,    20,    21,    45,    46,    24,    25,    -1,    27,
      28,    29,     7,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    40,    41,    19,    20,    -1,    45,    46,    24,
      25,    -1,    27,    28,    29,     7,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    40,    41,    -1,    20,    -1,
      45,    46,    24,    25,    -1,    27,    28,    29,     7,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    16,    40,    41,
      -1,    20,    -1,    45,    46,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    45,    46,    61,    63,    64,    65,    66,    67,    71,
      72,    73,    74,    75,    78,    79,    80,    84,    94,    96,
      98,   100,   101,   103,   105,   107,   109,   111,   113,   115,
     116,   117,   118,   120,   128,   103,   129,    94,    94,    24,
      21,    94,   121,   122,    26,   121,    24,   100,   128,     0,
      62,    17,    10,    38,    97,    37,    99,     4,   102,    44,
     104,    39,   106,    43,   108,    48,   110,    41,   112,     3,
     114,   115,    42,    20,    25,    47,   119,   123,     6,    18,
      19,    23,    68,    69,    70,    23,    30,    19,    19,    19,
      20,    85,     8,    90,    21,    23,    26,    20,    81,    61,
      66,   128,    96,    98,    38,   100,    37,   103,     4,   105,
      44,   107,    39,   109,    43,   111,    48,   113,    41,   115,
       3,   115,    21,    87,    88,    94,    19,    94,   124,   125,
     126,    24,   123,   128,   128,    94,    94,     6,   103,   128,
      34,    64,    92,    92,    92,    21,    86,    87,    19,   129,
      94,    21,    24,    82,    83,    19,    22,    12,    98,   100,
     103,   105,   107,   109,   111,   113,   115,    21,    23,     6,
      90,    19,    94,   127,    19,    26,    23,     6,   128,    19,
      35,    12,    77,    11,    76,    77,    21,    23,    92,    30,
      70,    21,    23,    92,    94,    94,    88,    94,    94,   127,
      94,   127,   126,    94,    92,    63,    93,    19,    94,    11,
      77,    96,    83,    19,   127,    77,     0,    36,    63,    92,
      19,    94,    10,    89,    90,    91,    92,    92,    19,    95,
      96,    92,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    62,    61,    61,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    67,    68,    68,
      68,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   122,   122,   123,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     2,     4,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     5,     4,
       3,     4,     5,     6,     7,     5,     7,     2,     3,     3,
       1,     2,     1,     5,     4,     2,     3,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     4,     5,     2,     3,
       1,     4,     4,     2,     1,     5,     1,     1,     2,     1,
       2,     3,     2,     1,     2,     3,     2,     1,     2,     1,
       3,     2,     2,     1,     2,     3,     2,     1,     2,     3,
       2,     1,     2,     3,     2,     1,     2,     3,     2,     1,
       2,     3,     2,     1,     2,     3,     2,     1,     1,     1,
       3,     1,     2,     1,     2,     1,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     3,     3,     2,     3,     2,     2,     1,     3,
       1,     1,     4,     3,     3,     2,     3,     2,     2,     1,
       2,     1,     3,     1,     3,     1
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
  case 2: /* $@1: %empty  */
#line 50 "parser.y"
             {fprintf(yyout,"module--stmt%d;\n",m["stmt"]); m["stmt"]++; }
#line 1449 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 55 "parser.y"
              { fprintf(yyout,"stmt%d--simple_stmt%d;\n",m["stmt"],m["simple_stmt"]); m["simple_stmt"]++;}
#line 1455 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 56 "parser.y"
                {fprintf(yyout,"stmt%d--compound_stmt%d;\n",m["stmt"],m["compound_stmt"]); m["compound_stmt"]++; }
#line 1461 "parser.tab.c"
    break;

  case 8: /* stmt: testlist  */
#line 57 "parser.y"
           {fprintf(yyout,"stmt%d--simple_stmt%d;\n",m["stmt"],m["simple_stmt"]); m["simple_stmt"]++; }
#line 1467 "parser.tab.c"
    break;

  case 29: /* compound_stmt: if_stmt  */
#line 93 "parser.y"
                       {fprintf(yyout,"compound_stmt%d--if_stmt%d;\n",m["compound_stmt"],m["if_stmt"]); m["if_stmt"]++;}
#line 1473 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF test COLON suite  */
#line 99 "parser.y"
                             { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;}
#line 1479 "parser.tab.c"
    break;

  case 71: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 161 "parser.y"
                                  { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--DEDENT%d;\n",m["suite"],m["DEDENT"]); m["DEDENT"]++;}
#line 1485 "parser.tab.c"
    break;

  case 74: /* stmt_list: stmt  */
#line 165 "parser.y"
       {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
#line 1491 "parser.tab.c"
    break;


#line 1495 "parser.tab.c"

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

#line 299 "parser.y"


void yyerror(const char *s){
   cout<<" f u \n"<<yytext;
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
