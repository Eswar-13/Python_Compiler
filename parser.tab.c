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

map<string,int> m;


#line 91 "parser.tab.c"

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
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_stmt = 64,                      /* stmt  */
  YYSYMBOL_simple_stmt = 65,               /* simple_stmt  */
  YYSYMBOL_more_expr = 66,                 /* more_expr  */
  YYSYMBOL_small_stmt = 67,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 68,                 /* expr_stmt  */
  YYSYMBOL_right_assign = 69,              /* right_assign  */
  YYSYMBOL_Assign_stmt = 70,               /* Assign_stmt  */
  YYSYMBOL_annassign = 71,                 /* annassign  */
  YYSYMBOL_break_stmt = 72,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 73,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 74,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 75,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 76,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 77,           /* elif_statements  */
  YYSYMBOL_else_statement = 78,            /* else_statement  */
  YYSYMBOL_while_stmt = 79,                /* while_stmt  */
  YYSYMBOL_for_stmt = 80,                  /* for_stmt  */
  YYSYMBOL_funcdef = 81,                   /* funcdef  */
  YYSYMBOL_parameters = 82,                /* parameters  */
  YYSYMBOL_typedargslist = 83,             /* typedargslist  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_full_tfpdef = 85,               /* full_tfpdef  */
  YYSYMBOL_classdef = 86,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 87,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 88,               /* opt_arglist  */
  YYSYMBOL_arglist = 89,                   /* arglist  */
  YYSYMBOL_argument = 90,                  /* argument  */
  YYSYMBOL_comp_iter = 91,                 /* comp_iter  */
  YYSYMBOL_comp_for = 92,                  /* comp_for  */
  YYSYMBOL_comp_if = 93,                   /* comp_if  */
  YYSYMBOL_suite = 94,                     /* suite  */
  YYSYMBOL_stmt_list = 95,                 /* stmt_list  */
  YYSYMBOL_test = 96,                      /* test  */
  YYSYMBOL_or_test = 97,                   /* or_test  */
  YYSYMBOL_and_test = 98,                  /* and_test  */
  YYSYMBOL_not_test = 99,                  /* not_test  */
  YYSYMBOL_100_3 = 100,                    /* $@3  */
  YYSYMBOL_comparison = 101,               /* comparison  */
  YYSYMBOL_expr = 102,                     /* expr  */
  YYSYMBOL_xor_expr = 103,                 /* xor_expr  */
  YYSYMBOL_and_expr = 104,                 /* and_expr  */
  YYSYMBOL_shift_expr = 105,               /* shift_expr  */
  YYSYMBOL_arith_expr = 106,               /* arith_expr  */
  YYSYMBOL_term = 107,                     /* term  */
  YYSYMBOL_factor = 108,                   /* factor  */
  YYSYMBOL_power = 109,                    /* power  */
  YYSYMBOL_atom_expr = 110,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 111,              /* opt_trailer  */
  YYSYMBOL_atom = 112,                     /* atom  */
  YYSYMBOL_testlist_comp = 113,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 114,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 115,                  /* trailer  */
  YYSYMBOL_testlist = 116,                 /* testlist  */
  YYSYMBOL_exprlist = 117                  /* exprlist  */
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
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

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
       0,    51,    51,    51,    52,    55,    56,    57,    58,    61,
      62,    65,    66,    70,    71,    72,    73,    77,    80,    81,
      82,    85,    86,    89,    90,    94,    97,   100,   101,   108,
     109,   110,   111,   112,   115,   116,   117,   118,   121,   122,
     125,   129,   130,   134,   135,   138,   139,   142,   143,   147,
     147,   149,   153,   154,   157,   158,   161,   162,   165,   166,
     169,   170,   173,   174,   175,   178,   179,   182,   183,   186,
     187,   192,   193,   194,   197,   198,   201,   202,   205,   206,
     209,   210,   213,   213,   215,   217,   218,   220,   221,   223,
     224,   226,   227,   229,   230,   233,   234,   235,   237,   238,
     242,   243,   244,   245,   248,   249,   251,   252,   255,   256,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   275,   276,   277,   279,   280,   284,   285,   286,
     287,   291,   292,   296,   297
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
  "$accept", "module", "$@1", "stmt", "simple_stmt", "more_expr",
  "small_stmt", "expr_stmt", "right_assign", "Assign_stmt", "annassign",
  "break_stmt", "continue_stmt", "return_stmt", "compound_stmt", "if_stmt",
  "elif_statements", "else_statement", "while_stmt", "for_stmt", "funcdef",
  "parameters", "typedargslist", "$@2", "full_tfpdef", "classdef",
  "opt_class_arg", "opt_arglist", "arglist", "argument", "comp_iter",
  "comp_for", "comp_if", "suite", "stmt_list", "test", "or_test",
  "and_test", "not_test", "$@3", "comparison", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "factor", "power",
  "atom_expr", "opt_trailer", "atom", "testlist_comp", "opt_test_stmt",
  "trailer", "testlist", "exprlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,  -149,   357,   347,   347,  -149,   -19,  -149,  -149,   235,
    -149,   263,  -149,  -149,  -149,    -4,  -149,   347,  -149,   357,
     357,   357,  -149,  -149,    45,  -149,  -149,    56,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
      -1,    42,  -149,    79,    18,    49,    61,    44,    85,    97,
    -149,  -149,    66,    -7,    80,    18,    26,   103,   111,    77,
    -149,   132,   122,   126,  -149,   138,   145,   347,  -149,  -149,
    -149,  -149,  -149,   104,   207,   347,   347,   347,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   291,   347,   134,
      -7,  -149,   347,   347,   347,   347,  -149,   160,  -149,   357,
     347,   171,   171,   171,   319,   148,   357,  -149,  -149,   347,
    -149,    46,    55,  -149,  -149,  -149,    80,    -2,    42,  -149,
      18,    61,    61,    44,    85,    97,    97,  -149,  -149,  -149,
      59,  -149,   115,   142,  -149,  -149,   147,   147,   168,  -149,
     347,    18,    35,   140,  -149,   164,   136,  -149,  -149,   156,
     157,   171,    39,  -149,  -149,   162,   118,  -149,   171,   347,
     347,  -149,   347,   347,  -149,  -149,   347,   147,   171,   104,
     163,  -149,   347,   141,  -149,  -149,   347,  -149,   347,  -149,
    -149,  -149,  -149,   166,  -149,  -149,  -149,  -149,   164,  -149,
      19,   171,   169,   347,  -149,    30,   155,   171,  -149,  -149,
    -149,  -149,  -149,   171,   170,   347,  -149,  -149,  -149,  -149,
    -149,  -149,   171,    30,  -149,  -149
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   116,     0,     0,     0,    25,     0,    26,   121,     0,
     114,     0,   118,   119,   120,     0,    82,    27,     5,     0,
       0,     0,   115,   117,     0,     2,     6,     9,    12,    13,
      14,    15,    16,     7,    29,    30,    31,    32,    33,   132,
      77,    79,    81,    84,    86,    88,    90,    92,    94,    97,
      99,   103,   105,   107,     8,   134,     0,     0,     0,     0,
     111,   125,     0,   124,   112,     0,     0,     0,    28,   102,
     100,   101,     1,     4,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   109,     0,     0,     0,     0,    17,    20,    18,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   110,   123,
     113,     0,     0,    83,     3,    11,     0,     0,    78,    80,
      85,    87,    89,    91,    93,    95,    96,    98,   104,   128,
       0,    61,    62,     0,   130,   108,    22,    19,    24,   131,
       0,   133,     0,     0,    71,    41,    34,    55,    56,     0,
      59,     0,     0,   126,    47,    53,     0,    51,     0,     0,
       0,   127,     0,     0,    63,   129,     0,    21,     0,     0,
       0,    42,     0,    36,    35,    57,    58,    54,     0,    52,
      48,    49,    45,     0,    76,    60,    64,    23,    43,    75,
       0,     0,     0,     0,    37,    67,     0,     0,    44,    73,
      72,    74,    40,     0,     0,     0,    68,    65,    66,    50,
      46,    39,     0,    69,    38,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,   110,  -149,  -148,     3,  -149,   120,  -149,  -149,  -149,
      47,  -149,  -149,  -149,  -149,  -149,  -149,  -116,  -149,  -149,
    -149,  -149,  -149,  -149,     1,  -149,  -149,  -149,   102,  -145,
     -12,   -54,  -149,   -87,  -149,    -3,   -71,   131,   -55,  -149,
    -149,     9,  -149,    75,   127,   128,    78,     4,  -149,  -149,
    -149,  -149,   198,  -149,   125,     2,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    24,    73,    25,   144,    27,    28,    29,    96,    97,
      98,    30,    31,    32,    33,    34,   173,   171,    35,    36,
      37,   112,   156,   196,   157,    38,   105,   149,   130,   131,
     206,   207,   208,   145,   190,    39,    40,    41,    42,    67,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      90,    53,    62,    63,    91,   116,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    54,    26,   117,    59,    61,   107,    61,    75,
     160,    55,   113,    87,    68,   146,   147,   185,    88,   199,
      66,   189,   119,    69,    70,    71,     1,     2,     3,     4,
     174,   185,     5,     6,     7,     8,    76,    76,   106,     9,
     205,    89,   201,    10,    11,    72,    12,    13,    14,    99,
      15,    16,    17,    18,   168,   200,   100,   194,    95,    19,
      20,    21,    99,    79,   177,    22,    23,   154,    76,   178,
     155,   182,   198,    74,   158,    54,    26,   159,   164,    77,
     161,   188,   162,    78,   132,   133,    92,   120,    80,   127,
     128,   138,   139,    82,   136,   137,   103,   104,    93,    94,
      85,   132,   142,    95,   202,    81,   153,   195,   141,    86,
     210,     1,     2,     3,     4,    55,   211,     5,     6,     7,
       8,   163,   101,   106,     9,   214,    83,    84,    10,    11,
     102,    12,    13,    14,   213,    15,    16,    17,    18,   180,
     106,   181,   167,   108,    19,    20,    21,   172,   170,   109,
      22,    23,   193,   170,   121,   122,   183,   184,   134,   132,
     186,   125,   126,   187,   110,   111,   140,   151,   165,   192,
      95,    54,    26,   132,   166,   169,   170,   175,     1,   155,
     176,    94,   191,   114,     5,   197,     7,     8,   203,   212,
     204,     9,    54,    26,   115,    10,    11,   209,    12,    13,
      14,   215,   179,    16,    17,   143,   150,   118,   123,    65,
     124,    19,    20,    21,     1,   135,     0,    22,    23,   152,
       5,     0,     7,     8,     0,     0,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     0,     0,    16,
      17,     0,     1,     0,     0,     0,     0,    19,    20,    21,
       0,     8,     0,    22,    23,     9,    60,     0,     0,    10,
      11,     0,    12,    13,    14,     0,     0,    16,     0,     0,
       1,     0,     0,     0,     0,    19,    20,    21,     0,     8,
       0,    22,    23,     9,     0,     0,     0,    10,    11,    64,
      12,    13,    14,     0,     0,    16,     0,     0,     1,     0,
       0,     0,     0,    19,    20,    21,     0,     8,     0,    22,
      23,     9,   129,     0,     0,    10,    11,     0,    12,    13,
      14,     0,     0,    16,     0,     0,     1,     0,     0,     0,
       0,    19,    20,    21,     0,     8,     0,    22,    23,     9,
     148,     0,     0,    10,    11,     0,    12,    13,    14,     0,
       0,    16,     0,     0,     1,     0,     0,     0,     0,    19,
      20,    21,     0,     8,     1,    22,    23,     9,     0,     0,
       0,    10,    11,     8,    12,    13,    14,     9,     0,    16,
       0,    10,    11,     0,    12,    13,    14,    19,    20,    21,
       0,     0,     0,    22,    23,     0,     0,    19,    20,    21,
       0,     0,     0,    22,    23
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    75,    24,     9,    61,    11,    10,
      12,     2,    67,    20,    17,   102,   103,   162,    25,     0,
      24,   169,    77,    19,    20,    21,     7,     8,     9,    10,
     146,   176,    13,    14,    15,    16,    38,    38,     8,    20,
      10,    48,   190,    24,    25,     0,    27,    28,    29,    23,
      31,    32,    33,    34,    19,    36,    30,   173,    23,    40,
      41,    42,    23,    45,   151,    46,    47,    21,    38,    30,
      24,   158,   188,    17,    19,    73,    73,    22,   132,    37,
      21,   168,    23,     4,    87,    88,     6,    78,    39,    85,
      86,    94,    95,    49,    92,    93,    19,    20,    18,    19,
       3,   104,   100,    23,   191,    44,   109,   178,    99,    43,
     197,     7,     8,     9,    10,   106,   203,    13,    14,    15,
      16,     6,    19,     8,    20,   212,    41,    42,    24,    25,
      19,    27,    28,    29,   205,    31,    32,    33,    34,    21,
       8,    23,   140,    21,    40,    41,    42,    11,    12,    23,
      46,    47,    11,    12,    79,    80,   159,   160,    24,   162,
     163,    83,    84,   166,    26,    20,     6,    19,    26,   172,
      23,   169,   169,   176,     6,    35,    12,    21,     7,    24,
      23,    19,    19,    73,    13,    19,    15,    16,    19,    19,
     193,    20,   190,   190,    74,    24,    25,   196,    27,    28,
      29,   213,   155,    32,    33,    34,   104,    76,    81,    11,
      82,    40,    41,    42,     7,    90,    -1,    46,    47,   106,
      13,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    16,    -1,    46,    47,    20,    21,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    16,
      -1,    46,    47,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,
      47,    20,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    16,    -1,    46,    47,    20,
      21,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    16,     7,    46,    47,    20,    -1,    -1,
      -1,    24,    25,    16,    27,    28,    29,    20,    -1,    32,
      -1,    24,    25,    -1,    27,    28,    29,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    62,    64,    65,    66,    67,    68,
      72,    73,    74,    75,    76,    79,    80,    81,    86,    96,
      97,    98,    99,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   112,   116,   102,   117,    96,    96,    24,
      21,    96,   113,   114,    26,   113,    24,   100,    96,   108,
     108,   108,     0,    63,    17,    10,    38,    37,     4,    45,
      39,    44,    49,    41,    42,     3,    43,    20,    25,    48,
     111,   115,     6,    18,    19,    23,    69,    70,    71,    23,
      30,    19,    19,    19,    20,    87,     8,    92,    21,    23,
      26,    20,    82,    99,    62,    67,   116,    97,    98,    99,
     102,   104,   104,   105,   106,   107,   107,   108,   108,    21,
      89,    90,    96,    96,    24,   115,   116,   116,    96,    96,
       6,   102,   116,    34,    65,    94,    94,    94,    21,    88,
      89,    19,   117,    96,    21,    24,    83,    85,    19,    22,
      12,    21,    23,     6,    92,    26,     6,   116,    19,    35,
      12,    78,    11,    77,    78,    21,    23,    94,    30,    71,
      21,    23,    94,    96,    96,    90,    96,    96,    94,    64,
      95,    19,    96,    11,    78,    97,    84,    19,    78,     0,
      36,    64,    94,    19,    96,    10,    91,    92,    93,    85,
      94,    94,    19,    97,    94,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    62,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    69,    69,
      69,    70,    70,    71,    71,    72,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    84,
      83,    83,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,   100,    99,    99,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   114,   114,   115,   115,   115,
     115,   116,   116,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     2,     4,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     5,     4,
       3,     4,     5,     6,     7,     5,     7,     2,     3,     0,
       4,     1,     2,     1,     5,     4,     2,     3,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     4,     5,     2,
       3,     1,     4,     4,     2,     1,     5,     1,     3,     1,
       3,     1,     0,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     1,
       2,     2,     2,     1,     3,     1,     2,     1,     2,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     3,     3,     2,     3,
       2,     3,     1,     3,     1
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
#line 51 "parser.y"
             {fprintf(yyout,"module--stmt%d;\n",m["stmt"]); m["stmt"]++; }
#line 1398 "parser.tab.c"
    break;

  case 5: /* stmt: NEWLINE  */
#line 55 "parser.y"
              { fprintf(yyout,"stmt%d--NEWLINE%d;\n",m["stmt"],m["NEWLINE"]); m["NEWLINE"]++;}
#line 1404 "parser.tab.c"
    break;

  case 6: /* stmt: simple_stmt  */
#line 56 "parser.y"
              { fprintf(yyout,"stmt%d--simple_stmt%d;\n",m["stmt"],m["simple_stmt"]); m["simple_stmt"]++;}
#line 1410 "parser.tab.c"
    break;

  case 7: /* stmt: compound_stmt  */
#line 57 "parser.y"
                {fprintf(yyout,"stmt%d--compound_stmt%d;\n",m["stmt"],m["compound_stmt"]); m["compound_stmt"]++; }
#line 1416 "parser.tab.c"
    break;

  case 8: /* stmt: testlist  */
#line 58 "parser.y"
           {fprintf(yyout,"stmt%d--testlist%d;\n",m["stmt"],m["testlist"]); m["testlist"]++; }
#line 1422 "parser.tab.c"
    break;

  case 13: /* small_stmt: expr_stmt  */
#line 70 "parser.y"
               {fprintf(yyout,"simple_stmt%d--expr_stmt%d;\n",m["simple_stmt"],m["expr_stmt"]); m["expr_stmt"]++; }
#line 1428 "parser.tab.c"
    break;

  case 14: /* small_stmt: break_stmt  */
#line 71 "parser.y"
               {fprintf(yyout,"simple_stmt%d--break_stmt%d;\n",m["simple_stmt"],m["break_stmt"]); m["break_stmt"]++; }
#line 1434 "parser.tab.c"
    break;

  case 15: /* small_stmt: continue_stmt  */
#line 72 "parser.y"
                           {fprintf(yyout,"simple_stmt%d--continue_stmt%d;\n",m["simple_stmt"],m["expr_stmt"]); m["continue_stmt"]++; }
#line 1440 "parser.tab.c"
    break;

  case 16: /* small_stmt: return_stmt  */
#line 73 "parser.y"
                           {fprintf(yyout,"simple_stmt%d--return_stmt%d;\n",m["simple_stmt"],m["return_stmt"]); m["return_stmt"]++; }
#line 1446 "parser.tab.c"
    break;

  case 17: /* expr_stmt: testlist right_assign  */
#line 77 "parser.y"
                           {fprintf(yyout,"expr_stmt%d--testlist%d;\n",m["expr_stmt"],m["testlist"]); m["testlist"]++;fprintf(yyout,"expr_stmt%d--right_assign%d;\n",m["expr_stmt"],m["right_assign"]); m["right_assign"]++; }
#line 1452 "parser.tab.c"
    break;

  case 18: /* right_assign: annassign  */
#line 80 "parser.y"
              {fprintf(yyout,"right_assign%d--annassign%d;\n",m["right_assign"],m["annassign"]); m["annassign"]++; }
#line 1458 "parser.tab.c"
    break;

  case 19: /* right_assign: AUGASSIGNMENT_OPERATOR testlist  */
#line 81 "parser.y"
                                    {fprintf(yyout,"right_assign%d--AUGASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["AUGASSIGNMENT_OPERATOR"]); m["AUGASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
#line 1464 "parser.tab.c"
    break;

  case 21: /* Assign_stmt: Assign_stmt ASSIGNMENT_OPERATOR testlist  */
#line 85 "parser.y"
                                          {fprintf(yyout,"right_assign%d--ASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
#line 1470 "parser.tab.c"
    break;

  case 22: /* Assign_stmt: ASSIGNMENT_OPERATOR testlist  */
#line 86 "parser.y"
                                        {fprintf(yyout,"right_assign%d--ASSIGNMENT_OPERATOR%d;\n",m["right_assign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"right_assign%d--testlist%d;\n",m["right_assign"],m["testlist"]); m["testlist"]++; }
#line 1476 "parser.tab.c"
    break;

  case 23: /* annassign: COLON test ASSIGNMENT_OPERATOR test  */
#line 89 "parser.y"
                                                   {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;fprintf(yyout,"annassign%d--ASSIGNMENT_OPERATOR%d;\n",m["annassign"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++; fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); m["test"]++;}
#line 1482 "parser.tab.c"
    break;

  case 24: /* annassign: COLON test  */
#line 90 "parser.y"
                           {fprintf(yyout,"annassign%d--COLON%d;\n",m["annassign"],m["COLON"]); m["COLON"]++;fprintf(yyout,"annassign%d--test%d;\n",m["annassign"],m["test"]); }
#line 1488 "parser.tab.c"
    break;

  case 25: /* break_stmt: BREAK  */
#line 94 "parser.y"
       {fprintf(yyout,"break_stmt%d--BREAK%d;\n",m["break_stmt"],m["BREAK"]); m["BREAK"]++; }
#line 1494 "parser.tab.c"
    break;

  case 26: /* continue_stmt: CONTINUE  */
#line 97 "parser.y"
            {fprintf(yyout,"continue_stmt%d--CONTINUE%d;\n",m["continue_stmt"],m["CONTINUE"]); m["CONTINUE"]++; }
#line 1500 "parser.tab.c"
    break;

  case 27: /* return_stmt: RETURN  */
#line 100 "parser.y"
                   {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; }
#line 1506 "parser.tab.c"
    break;

  case 28: /* return_stmt: RETURN test  */
#line 101 "parser.y"
                           {fprintf(yyout,"return_stmt%d--RETURN%d;\n",m["return_stmt"],m["RETURN"]); m["RETURN"]++; fprintf(yyout,"return_stmt%d--test%d;\n",m["return_stmt"],m["test"]); m["test"]++; }
#line 1512 "parser.tab.c"
    break;

  case 29: /* compound_stmt: if_stmt  */
#line 108 "parser.y"
               {fprintf(yyout,"compound_stmt%d--if_stmt%d;\n",m["compound_stmt"],m["if_stmt"]); m["if_stmt"]++;}
#line 1518 "parser.tab.c"
    break;

  case 30: /* compound_stmt: while_stmt  */
#line 109 "parser.y"
               {fprintf(yyout,"compound_stmt%d--while_stmt%d;\n",m["compound_stmt"],m["while_stmt"]); m["while_stmt"]++;}
#line 1524 "parser.tab.c"
    break;

  case 31: /* compound_stmt: for_stmt  */
#line 110 "parser.y"
               {fprintf(yyout,"compound_stmt%d--for_stmt%d;\n",m["compound_stmt"],m["for_stmt"]); m["for_stmt"]++;}
#line 1530 "parser.tab.c"
    break;

  case 32: /* compound_stmt: funcdef  */
#line 111 "parser.y"
               {fprintf(yyout,"compound_stmt%d--funcdef%d;\n",m["compound_stmt"],m["funcdef"]); m["funcdef"]++;}
#line 1536 "parser.tab.c"
    break;

  case 33: /* compound_stmt: classdef  */
#line 112 "parser.y"
               {fprintf(yyout,"compound_stmt%d--classdef%d;\n",m["compound_stmt"],m["classdef"]); m["classdef"]++;}
#line 1542 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF test COLON suite  */
#line 115 "parser.y"
                           { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;}
#line 1548 "parser.tab.c"
    break;

  case 35: /* if_stmt: IF test COLON suite else_statement  */
#line 116 "parser.y"
                                      { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1554 "parser.tab.c"
    break;

  case 36: /* if_stmt: IF test COLON suite elif_statements  */
#line 117 "parser.y"
                                       { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;}
#line 1560 "parser.tab.c"
    break;

  case 37: /* if_stmt: IF test COLON suite elif_statements else_statement  */
#line 118 "parser.y"
                                                      { fprintf(yyout,"if_stmt%d--IF%d;\n",m["if_stmt"],m["IF"]); m["IF"]++; fprintf(yyout,"if_stmt%d--test%d;\n",m["if_stmt"],m["test"]); m["test"]++; fprintf(yyout,"if_stmt%d--COLON%d;\n",m["if_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"if_stmt%d--suite%d;\n",m["if_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"if_stmt%d--elif_statements%d;\n",m["if_stmt"],m["elif_statements"]); m["elif_statements"]++;fprintf(yyout,"if_stmt%d--else_statement%d;\n",m["if_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1566 "parser.tab.c"
    break;

  case 38: /* elif_statements: elif_statements ELIF test COLON suite  */
#line 121 "parser.y"
                                        { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
#line 1572 "parser.tab.c"
    break;

  case 39: /* elif_statements: ELIF test COLON suite  */
#line 122 "parser.y"
                                         { fprintf(yyout,"elif_statements%d--ELIF%d;\n",m["elif_statements"],m["ELIF"]); m["ELIF"]++; fprintf(yyout,"elif_statements%d--test%d;\n",m["elif_statements"],m["test"]); m["test"]++; fprintf(yyout,"elif_statements%d--COLON%d;\n",m["elif_statements"],m["COLON"]); m["COLON"]++; fprintf(yyout,"elif_statements%d--suite%d;\n",m["elif_statements"],m["suite"]); m["suite"]++;}
#line 1578 "parser.tab.c"
    break;

  case 40: /* else_statement: ELSE COLON suite  */
#line 125 "parser.y"
                       { fprintf(yyout,"else_statement%d--ELSE%d;\n",m["else_statement"],m["ELSE"]); m["ELSE"]++; fprintf(yyout,"else_statement%d--COLON%d;\n",m["else_statement"],m["COLON"]); m["COLON"]++; fprintf(yyout,"else_statement%d--suite%d;\n",m["else_statement"],m["suite"]); m["suite"]++;}
#line 1584 "parser.tab.c"
    break;

  case 41: /* while_stmt: WHILE test COLON suite  */
#line 129 "parser.y"
                                    { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;}
#line 1590 "parser.tab.c"
    break;

  case 42: /* while_stmt: WHILE test COLON suite else_statement  */
#line 130 "parser.y"
                                                   { fprintf(yyout,"while_stmt%d--WHILE%d;\n",m["while_stmt"],m["WHILE"]); m["WHILE"]++; fprintf(yyout,"while_stmt%d--test%d;\n",m["while_stmt"],m["test"]); m["test"]++; fprintf(yyout,"while_stmt%d--COLON%d;\n",m["while_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"while_stmt%d--suite%d;\n",m["while_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"while_stmt%d--else_statement%d;\n",m["while_stmt"],m["else_statement"]);}
#line 1596 "parser.tab.c"
    break;

  case 43: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 134 "parser.y"
                                                  { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;}
#line 1602 "parser.tab.c"
    break;

  case 44: /* for_stmt: FOR exprlist IN testlist COLON suite else_statement  */
#line 135 "parser.y"
                                                                     { fprintf(yyout,"for_stmt%d--FOR%d;\n",m["for_stmt"],m["FOR"]);m["FOR"]++;fprintf(yyout,"for_stmt%d--exprlist%d;\n",m["for_stmt"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"for_stmt%d--IN%d;\n",m["for_stmt"],m["IN"]); m["IN"]++; fprintf(yyout,"for_stmt%d--testlist%d;\n",m["for_stmt"],m["testlist"]); m["testlist"]++; fprintf(yyout,"for_stmt%d--COLON%d;\n",m["for_stmt"],m["COLON"]); m["COLON"]++; fprintf(yyout,"for_stmt%d--suite%d;\n",m["for_stmt"],m["suite"]); m["suite"]++;fprintf(yyout,"for_stmt%d--else_statement%d;\n",m["for_stmt"],m["else_statement"]); m["else_statement"]++;}
#line 1608 "parser.tab.c"
    break;

  case 45: /* funcdef: DEF NAME parameters COLON suite  */
#line 138 "parser.y"
                                             { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
#line 1614 "parser.tab.c"
    break;

  case 46: /* funcdef: DEF NAME parameters RETURN_ARROW test COLON suite  */
#line 139 "parser.y"
                                                      { fprintf(yyout,"funcdef%d--DEF%d;\n",m["funcdef"],m["DEF"]); m["DEF"]++; fprintf(yyout,"funcdef%d--NAME%d;\n",m["funcdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"funcdef%d--parameters%d;\n",m["funcdef"],m["parameters"]); m["parameters"]++;fprintf(yyout,"funcdef%d--RETURN_ARROW%d;\n",m["funcdef"],m["RETURN_ARROW"]); m["RETURN_ARROW"]++;fprintf(yyout,"funcdef%d--test%d;\n",m["funcdef"],m["test"]); m["test"]++; fprintf(yyout,"funcdef%d--COLON%d;\n",m["funcdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"funcdef%d--suite%d;\n",m["funcdef"],m["suite"]); m["suite"]++;}
#line 1620 "parser.tab.c"
    break;

  case 47: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 142 "parser.y"
                                             {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1626 "parser.tab.c"
    break;

  case 48: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 143 "parser.y"
                                             {fprintf(yyout,"parameters%d--LEFT_BRACKET%d;\n",m["parameters"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"parameters%d--typedargslist%d;\n",m["parameters"],m["typedargslist"]); m["typedargslist"]++;fprintf(yyout,"parameters%d--RIGHT_BRACKET%d;\n",m["parameters"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1632 "parser.tab.c"
    break;

  case 49: /* $@2: %empty  */
#line 147 "parser.y"
                    {fprintf(yyout,"typedargslist%d--COMMA%d;\n",m["typedargslist"],m["COMMA"]); m["COMMA"]++;}
#line 1638 "parser.tab.c"
    break;

  case 52: /* full_tfpdef: NAME annassign  */
#line 153 "parser.y"
                           {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;fprintf(yyout,"typedargslist%d--annassign%d;\n",m["typedargslist"],m["annassign"]); m["annassign"]++;}
#line 1644 "parser.tab.c"
    break;

  case 53: /* full_tfpdef: NAME  */
#line 154 "parser.y"
                    {fprintf(yyout,"typedargslist%d--NAME%d;\n",m["typedargslist"],m["NAME"]); m["NAME"]++;}
#line 1650 "parser.tab.c"
    break;

  case 54: /* classdef: CLASS NAME opt_class_arg COLON suite  */
#line 157 "parser.y"
                                         { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--opt_class_arg%d;\n",m["classdef"],m["opt_class_arg"]); m["opt_class_arg"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
#line 1656 "parser.tab.c"
    break;

  case 55: /* classdef: CLASS NAME COLON suite  */
#line 158 "parser.y"
                              { fprintf(yyout,"classdef%d--CLASS%d;\n",m["classdef"],m["CLASS"]); m["CLASS"]++; fprintf(yyout,"classdef%d--NAME%d;\n",m["classdef"],m["NAME"]); m["NAME"]++; fprintf(yyout,"classdef%d--COLON%d;\n",m["classdef"],m["COLON"]); m["COLON"]++; fprintf(yyout,"classdef%d--suite%d;\n",m["classdef"],m["suite"]); m["suite"]++;}
#line 1662 "parser.tab.c"
    break;

  case 56: /* opt_class_arg: LEFT_BRACKET RIGHT_BRACKET  */
#line 161 "parser.y"
                              {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1668 "parser.tab.c"
    break;

  case 57: /* opt_class_arg: LEFT_BRACKET opt_arglist RIGHT_BRACKET  */
#line 162 "parser.y"
                                             {fprintf(yyout,"opt_class_arg%d--LEFT_BRACKET%d;\n",m["opt_class_arg"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++;fprintf(yyout,"opt_class_arg%d--opt_arglist%d;\n",m["opt_class_arg"],m["opt_arglist"]); m["opt_arglist"]++;fprintf(yyout,"opt_class_arg%d--RIGHT_BRACKET%d;\n",m["opt_class_arg"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1674 "parser.tab.c"
    break;

  case 58: /* opt_arglist: arglist COMMA  */
#line 165 "parser.y"
                               {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;fprintf(yyout,"opt_arglist%d--COMMA%d;\n",m["opt_arglist"],m["COMMA"]); m["COMMA"]++;}
#line 1680 "parser.tab.c"
    break;

  case 59: /* opt_arglist: arglist  */
#line 166 "parser.y"
                              {fprintf(yyout,"opt_arglist%d--arglist%d;\n",m["opt_arglist"],m["arglist"]); m["arglist"]++;}
#line 1686 "parser.tab.c"
    break;

  case 60: /* arglist: arglist COMMA argument  */
#line 169 "parser.y"
                                    {fprintf(yyout,"arglist%d--COMMA%d;\n",m["arglist"],m["COMMA"]); m["COMMA"]++;fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
#line 1692 "parser.tab.c"
    break;

  case 61: /* arglist: argument  */
#line 170 "parser.y"
                                             {fprintf(yyout,"arglist%d--argument%d;\n",m["arglist"],m["argument"]); m["argument"]++;}
#line 1698 "parser.tab.c"
    break;

  case 62: /* argument: test  */
#line 173 "parser.y"
              {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
#line 1704 "parser.tab.c"
    break;

  case 63: /* argument: test comp_for  */
#line 174 "parser.y"
                        {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--comp_for%d;\n",m["argument"],m["comp_for"]); m["comp_for"]++;}
#line 1710 "parser.tab.c"
    break;

  case 64: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 175 "parser.y"
                                    {fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;fprintf(yyout,"argument%d--ASSIGNMENT_OPERATOR%d;\n",m["argument"],m["ASSIGNMENT_OPERATOR"]); m["ASSIGNMENT_OPERATOR"]++;fprintf(yyout,"argument%d--test%d;\n",m["argument"],m["test"]); m["test"]++;}
#line 1716 "parser.tab.c"
    break;

  case 65: /* comp_iter: comp_for  */
#line 178 "parser.y"
             {fprintf(yyout,"comp_iter%d--comp_for%d;\n",m["comp_iter"],m["comp_for"]); m["comp_for"]++;}
#line 1722 "parser.tab.c"
    break;

  case 66: /* comp_iter: comp_if  */
#line 179 "parser.y"
                        {fprintf(yyout,"comp_iter%d--comp_if%d;\n",m["comp_iter"],m["comp_if"]); m["comp_if"]++;}
#line 1728 "parser.tab.c"
    break;

  case 67: /* comp_for: FOR exprlist IN or_test  */
#line 182 "parser.y"
                             { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; }
#line 1734 "parser.tab.c"
    break;

  case 68: /* comp_for: FOR exprlist IN or_test comp_iter  */
#line 183 "parser.y"
                                       { fprintf(yyout,"comp_for%d--FOR%d;\n",m["comp_for"],m["FOR"]);m["FOR"]++;fprintf(yyout,"comp_for%d--exprlist%d;\n",m["comp_for"],m["exprlist"]);m["exprlist"]++;fprintf(yyout,"comp_for%d--IN%d;\n",m["comp_for"],m["IN"]); m["IN"]++; fprintf(yyout,"comp_for%d--or_test%d;\n",m["comp_for"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_for%d--comp_iter%d;\n",m["comp_for"],m["comp_iter"]); m["comp_iter"]++;}
#line 1740 "parser.tab.c"
    break;

  case 69: /* comp_if: IF or_test  */
#line 186 "parser.y"
                     { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; }
#line 1746 "parser.tab.c"
    break;

  case 70: /* comp_if: IF or_test comp_iter  */
#line 187 "parser.y"
                              { fprintf(yyout,"comp_if%d--IF%d;\n",m["comp_if"],m["IF"]); m["IF"]++; fprintf(yyout,"comp_if%d--or_test%d;\n",m["comp_if"],m["or_test"]); m["or_test"]++; fprintf(yyout,"comp_if%d--comp_iter%d;\n",m["comp_if"],m["comp_iter"]); m["comp_iter"]++;}
#line 1752 "parser.tab.c"
    break;

  case 72: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 193 "parser.y"
                                  { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--DEDENT%d;\n",m["suite"],m["DEDENT"]); m["DEDENT"]++;}
#line 1758 "parser.tab.c"
    break;

  case 73: /* suite: NEWLINE INDENT stmt_list $end  */
#line 194 "parser.y"
                                 { fprintf(yyout,"suite%d--NEWLINE%d;\n",m["suite"],m["NEWLINE"]); m["NEWLINE"]++; fprintf(yyout,"suite%d--INDENT%d;\n",m["suite"],m["INDENT"]); m["INDENT"]++; fprintf(yyout,"suite%d--stmt_list%d;\n",m["suite"],m["stmt_list"]); m["stmt_list"]++; fprintf(yyout,"suite%d--YYEOF%d;\n",m["suite"],m["YYEOF"]); m["YYEOF"]++;}
#line 1764 "parser.tab.c"
    break;

  case 74: /* stmt_list: stmt_list stmt  */
#line 197 "parser.y"
                {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
#line 1770 "parser.tab.c"
    break;

  case 75: /* stmt_list: stmt  */
#line 198 "parser.y"
       {fprintf(yyout,"stmt_list%d--stmt%d;\n",m["stmt_list"],m["stmt"]); m["stmt"]++;}
#line 1776 "parser.tab.c"
    break;

  case 76: /* test: or_test IF or_test ELSE test  */
#line 201 "parser.y"
                                                   {fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--IF%d;\n",m["test"],m["IF"]); m["IF"]++;fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;fprintf(yyout,"test%d--ELSE%d;\n",m["test"],m["ELSE"]); m["ELSE"]++;}
#line 1782 "parser.tab.c"
    break;

  case 77: /* test: or_test  */
#line 202 "parser.y"
                        {fprintf(yyout,"test%d--or_test%d;\n",m["test"],m["or_test"]); m["or_test"]++;}
#line 1788 "parser.tab.c"
    break;

  case 78: /* or_test: or_test OR and_test  */
#line 205 "parser.y"
                                          {fprintf(yyout,"or_test%d--OR%d;\n",m["or_test"],m["OR"]); m["OR"]++;fprintf(yyout,"or_test%d--and_test%d;\n",m["or_test"],m["and_test"]); m["and_test"]++;}
#line 1794 "parser.tab.c"
    break;

  case 79: /* or_test: and_test  */
#line 206 "parser.y"
                           {fprintf(yyout,"or_test%d--and_test%d;\n",m["or_test"],m["and_test"]);m["and_test"]++;}
#line 1800 "parser.tab.c"
    break;

  case 80: /* and_test: and_test AND not_test  */
#line 209 "parser.y"
                                          {fprintf(yyout,"and_test%d--AND%d;\n",m["and_test"],m["AND"]); m["AND"]++;fprintf(yyout,"and_test%d--not_test%d;\n",m["and_test"],m["not_test"]); m["not_test"]++;}
#line 1806 "parser.tab.c"
    break;

  case 81: /* and_test: not_test  */
#line 210 "parser.y"
                        {fprintf(yyout,"and_test%d--not_test%d;\n",m["and_test"],m["not_test"]); m["not_test"]++;}
#line 1812 "parser.tab.c"
    break;

  case 82: /* $@3: %empty  */
#line 213 "parser.y"
              {fprintf(yyout,"not_test%d--NOT%d;\n",m["not_test"],m["NOT"]); m["NOT"]++;}
#line 1818 "parser.tab.c"
    break;

  case 84: /* not_test: comparison  */
#line 215 "parser.y"
               {fprintf(yyout,"not_test%d--comparison%d;\n",m["not_test"],m["comparison"]); m["comparison"]++;}
#line 1824 "parser.tab.c"
    break;

  case 85: /* comparison: comparison RELATIONAL_OPERATOR expr  */
#line 217 "parser.y"
                                                               {fprintf(yyout,"comparison%d--RELATIONAL_OPERATOR%d;\n",m["comparison"],m["RELATIONAL_OPERATOR"]); m["RELATIONAL_OPERATOR"]++;fprintf(yyout,"comparison%d--expr%d;\n",m["comparison"],m["expr"]); m["expr"]++;}
#line 1830 "parser.tab.c"
    break;

  case 86: /* comparison: expr  */
#line 218 "parser.y"
                     {;fprintf(yyout,"comparison%d--expr%d;\n",m["comparison"],m["expr"]); m["expr"]++;}
#line 1836 "parser.tab.c"
    break;

  case 87: /* expr: expr BIT_OR and_expr  */
#line 220 "parser.y"
                                          {fprintf(yyout,"expr%d--BIT_OR%d;\n",m["expr"],m["BIT_OR"]); m["BIT_OR"]++;fprintf(yyout,"expr%d--xor_expr%d;\n",m["expr"],m["xor_expr"]); m["xor_expr"]++;}
#line 1842 "parser.tab.c"
    break;

  case 88: /* expr: xor_expr  */
#line 221 "parser.y"
                           {fprintf(yyout,"expr%d--xor_expr%d;\n",m["expr"],m["xor_expr"]); m["xor_expr"]++;}
#line 1848 "parser.tab.c"
    break;

  case 89: /* xor_expr: xor_expr XOR and_expr  */
#line 223 "parser.y"
                                             {fprintf(yyout,"xor_expr%d--XOR%d;\n",m["xor_expr"],m["XOR"]); m["XOR"]++;fprintf(yyout,"xor_expr%d--and_expr%d;\n",m["xor_expr"],m["and_expr"]); m["and_expr"]++;}
#line 1854 "parser.tab.c"
    break;

  case 90: /* xor_expr: and_expr  */
#line 224 "parser.y"
                              {fprintf(yyout,"xor_expr%d--and_expr%d;\n",m["xor_expr"],m["and_expr"]); m["and_expr"]++;}
#line 1860 "parser.tab.c"
    break;

  case 91: /* and_expr: and_expr BIT_AND shift_expr  */
#line 226 "parser.y"
                                                   {fprintf(yyout,"and_expr%d--BIT_AND%d;\n",m["and_expr"],m["BIT_AND"]); m["BIT_AND"]++;fprintf(yyout,"and_expr%d--shift_expr%d;\n",m["and_expr"],m["shift_expr"]); m["shift_expr"]++;}
#line 1866 "parser.tab.c"
    break;

  case 92: /* and_expr: shift_expr  */
#line 227 "parser.y"
                              {fprintf(yyout,"and_expr%d--shift_expr%d;\n",m["and_expr"],m["shift_expr"]); m["shift_expr"]++;}
#line 1872 "parser.tab.c"
    break;

  case 93: /* shift_expr: shift_expr SHIFT arith_expr  */
#line 229 "parser.y"
                                                      {fprintf(yyout,"shift_expr%d--SHIFT%d;\n",m["shift_expr"],m["SHIFT"]); m["SHIFT"]++;fprintf(yyout,"shift_expr%d--arith_expr%d;\n",m["shift_expr"],m["arith_expr"]); m["arith_expr"]++;}
#line 1878 "parser.tab.c"
    break;

  case 94: /* shift_expr: arith_expr  */
#line 230 "parser.y"
                              {fprintf(yyout,"shift_expr%d--arith_expr%d;\n",m["shift_expr"],m["arith_expr"]); m["arith_expr"]++;}
#line 1884 "parser.tab.c"
    break;

  case 95: /* arith_expr: arith_expr ADD term  */
#line 233 "parser.y"
                                      {fprintf(yyout,"arith_expr%d--ADD%d;\n",m["arith_expr"],m["ADD"]); m["ADD"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
#line 1890 "parser.tab.c"
    break;

  case 96: /* arith_expr: arith_expr SUB term  */
#line 234 "parser.y"
                                       {fprintf(yyout,"arith_expr%d--SUB%d;\n",m["arith_expr"],m["SUB"]); m["SUB"]++;fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
#line 1896 "parser.tab.c"
    break;

  case 97: /* arith_expr: term  */
#line 235 "parser.y"
                                             {fprintf(yyout,"arith_expr%d--term%d;\n",m["arith_expr"],m["term"]); m["term"]++;}
#line 1902 "parser.tab.c"
    break;

  case 98: /* term: term ARITHMETIC_OPERATOR factor  */
#line 237 "parser.y"
                                                      {fprintf(yyout,"term%d--ARITHMETIC_OPERATOR%d;\n",m["term"],m["ARITHMETIC_OPERATOR"]); m["ARITHMETIC_OPERATOR"]++;fprintf(yyout,"term%d--factor%d;\n",m["term"],m["factor"]); m["factor"]++;}
#line 1908 "parser.tab.c"
    break;

  case 99: /* term: factor  */
#line 238 "parser.y"
                              {fprintf(yyout,"term%d--factor%d;\n",m["term"],m["factor"]); m["factor"]++;}
#line 1914 "parser.tab.c"
    break;

  case 100: /* factor: ADD factor  */
#line 242 "parser.y"
            {fprintf(yyout,"factor%d--ADD%d;\n",m["factor"],m["ADD"]); m["ADD"]++;}
#line 1920 "parser.tab.c"
    break;

  case 101: /* factor: SUB factor  */
#line 243 "parser.y"
            {fprintf(yyout,"factor%d--SUB%d;\n",m["factor"],m["SUB"]); m["SUB"]++;}
#line 1926 "parser.tab.c"
    break;

  case 102: /* factor: BIT_NOT factor  */
#line 244 "parser.y"
               {fprintf(yyout,"factor%d--BIT_NOT%d;\n",m["factor"],m["BIT_NOT"]); m["BIT_NOT"]++;}
#line 1932 "parser.tab.c"
    break;

  case 103: /* factor: power  */
#line 245 "parser.y"
         {fprintf(yyout,"factor%d--power%d;\n",m["factor"],m["power"]); m["power"]++;}
#line 1938 "parser.tab.c"
    break;

  case 104: /* power: atom_expr POWER factor  */
#line 248 "parser.y"
                                   {fprintf(yyout,"power%d--atom_expr%d;\n",m["power"],m["atom_expr"]); m["atom_expr"]++;fprintf(yyout,"power%d--POWER%d;\n",m["power"],m["POWER"]); m["POWER"]++;fprintf(yyout,"power%d--factor%d;\n",m["power"],m["factor"]); m["factor"]++;}
#line 1944 "parser.tab.c"
    break;

  case 105: /* power: atom_expr  */
#line 249 "parser.y"
                        {fprintf(yyout,"power%d--atom_expr%d;\n",m["power"],m["atom_expr"]); m["atom_expr"]++;}
#line 1950 "parser.tab.c"
    break;

  case 106: /* atom_expr: atom opt_trailer  */
#line 251 "parser.y"
                                       {fprintf(yyout,"atom_expr%d--atom%d;\n",m["atom_expr"],m["atom"]); m["atom"]++; fprintf(yyout,"atom_expr%d--opt_trailer%d;\n",m["atom_expr"],m["opt_trailer"]); m["opt_trailer"]++;}
#line 1956 "parser.tab.c"
    break;

  case 107: /* atom_expr: atom  */
#line 252 "parser.y"
                {fprintf(yyout,"atom_expr%d--atom%d;\n",m["atom_expr"],m["atom"]); m["atom"]++; }
#line 1962 "parser.tab.c"
    break;

  case 108: /* opt_trailer: opt_trailer trailer  */
#line 255 "parser.y"
                    {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
#line 1968 "parser.tab.c"
    break;

  case 109: /* opt_trailer: trailer  */
#line 256 "parser.y"
         {fprintf(yyout,"opt_trailer%d--trailer%d;\n",m["opt_trailer"],m["trailer"]); m["trailer"]++; }
#line 1974 "parser.tab.c"
    break;

  case 110: /* atom: LEFT_BRACKET testlist_comp RIGHT_BRACKET  */
#line 260 "parser.y"
                                         {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1980 "parser.tab.c"
    break;

  case 111: /* atom: LEFT_BRACKET RIGHT_BRACKET  */
#line 261 "parser.y"
                             {fprintf(yyout,"atom%d--LEFT_BRACKET%d;\n",m["atom"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_BRACKET%d;\n",m["atom"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 1986 "parser.tab.c"
    break;

  case 112: /* atom: LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET  */
#line 262 "parser.y"
                                           {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 1992 "parser.tab.c"
    break;

  case 113: /* atom: LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET  */
#line 263 "parser.y"
                                                        {fprintf(yyout,"atom%d--LEFT_SQUARE_BRACKET%d;\n",m["atom"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"atom%d--testlist_comp%d;\n",m["atom"],m["testlist_comp"]); m["testlist_comp"]++; fprintf(yyout,"atom%d--RIGHT_SQUARE_BRACKET%d;\n",m["atom"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 1998 "parser.tab.c"
    break;

  case 114: /* atom: NAME  */
#line 264 "parser.y"
      {fprintf(yyout,"atom%d--NAME%d;\n",m["atom"],m["NAME"]); m["NAME"]++;}
#line 2004 "parser.tab.c"
    break;

  case 115: /* atom: NUMBER  */
#line 265 "parser.y"
        {fprintf(yyout,"atom%d--NUMBER%d;\n",m["atom"],m["NUMBER"]); m["NUMBER"]++;}
#line 2010 "parser.tab.c"
    break;

  case 116: /* atom: DATA_TYPE  */
#line 266 "parser.y"
           {fprintf(yyout,"atom%d--DATA_TYPE%d;\n",m["atom"],m["DATA_TYPE"]); m["DATA_TYPE"]++;}
#line 2016 "parser.tab.c"
    break;

  case 117: /* atom: STRING  */
#line 267 "parser.y"
        {fprintf(yyout,"atom%d--STRING%d;\n",m["atom"],m["STRING"]); m["STRING"]++;}
#line 2022 "parser.tab.c"
    break;

  case 118: /* atom: NONE  */
#line 268 "parser.y"
      {fprintf(yyout,"atom%d--NONE%d;\n",m["atom"],m["NONE"]); m["NONE"]++;}
#line 2028 "parser.tab.c"
    break;

  case 119: /* atom: TRUE  */
#line 269 "parser.y"
      {fprintf(yyout,"atom%d--TRUE%d;\n",m["atom"],m["TRUE"]); m["TRUE"]++;}
#line 2034 "parser.tab.c"
    break;

  case 120: /* atom: FALSE  */
#line 270 "parser.y"
       {fprintf(yyout,"atom%d--FALSE%d;\n",m["atom"],m["FALSE"]); m["FALSE"]++;}
#line 2040 "parser.tab.c"
    break;

  case 121: /* atom: LIST  */
#line 271 "parser.y"
      {fprintf(yyout,"atom%d--LIST%d;\n",m["atom"],m["LIST"]); m["LIST"]++;}
#line 2046 "parser.tab.c"
    break;

  case 122: /* testlist_comp: test comp_for  */
#line 275 "parser.y"
              {fprintf(yyout,"testlist_comp%d--test%d;\n",m["testlist_comp"],m["test"]); m["test"]++; fprintf(yyout,"testlist_comp%d--comp_for%d;\n",m["testlist_comp"],m["comp_for"]); m["comp_for"]++; }
#line 2052 "parser.tab.c"
    break;

  case 123: /* testlist_comp: opt_test_stmt COMMA  */
#line 276 "parser.y"
                      {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++; fprintf(yyout,"testlist_comp%d--COMMA%d;\n",m["testlist_comp"],m["COMMA"]); m["COMMA"]++; }
#line 2058 "parser.tab.c"
    break;

  case 124: /* testlist_comp: opt_test_stmt  */
#line 277 "parser.y"
                {fprintf(yyout,"testlist_comp%d--opt_test_stmt%d;\n",m["testlist_comp"],m["opt_test_stmt"]); m["opt_test_stmt"]++;}
#line 2064 "parser.tab.c"
    break;

  case 125: /* opt_test_stmt: test  */
#line 279 "parser.y"
                    {fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;}
#line 2070 "parser.tab.c"
    break;

  case 126: /* opt_test_stmt: opt_test_stmt COMMA test  */
#line 280 "parser.y"
                          {fprintf(yyout,"opt_test_stmt%d--COMMA%d;\n",m["opt_test_stmt"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"opt_test_stmt%d--test%d;\n",m["opt_test_stmt"],m["test"]); m["test"]++;}
#line 2076 "parser.tab.c"
    break;

  case 127: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 284 "parser.y"
                                   {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--arglist%d;\n",m["trailer"],m["arglist"]); m["arglist"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2082 "parser.tab.c"
    break;

  case 128: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 285 "parser.y"
                             {fprintf(yyout,"trailer%d--LEFT_BRACKET%d;\n",m["trailer"],m["LEFT_BRACKET"]); m["LEFT_BRACKET"]++; fprintf(yyout,"trailer%d--RIGHT_BRACKET%d;\n",m["trailer"],m["RIGHT_BRACKET"]); m["RIGHT_BRACKET"]++;}
#line 2088 "parser.tab.c"
    break;

  case 129: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 286 "parser.y"
                                                {fprintf(yyout,"trailer%d--LEFT_SQUARE_BRACKET%d;\n",m["trailer"],m["LEFT_SQUARE_BRACKET"]); m["LEFT_SQUARE_BRACKET"]++; fprintf(yyout,"trailer%d--test%d;\n",m["trailer"],m["test"]); m["test"]++; fprintf(yyout,"trailer%d--RIGHT_SQUARE_BRACKET%d;\n",m["trailer"],m["RIGHT_SQUARE_BRACKET"]); m["RIGHT_SQUARE_BRACKET"]++;}
#line 2094 "parser.tab.c"
    break;

  case 130: /* trailer: DOT NAME  */
#line 287 "parser.y"
           {fprintf(yyout,"trailer%d--DOT%d;\n",m["trailer"],m["DOT"]); m["DOT"]++; fprintf(yyout,"trailer%d--NAME%d;\n",m["trailer"],m["NAME"]); m["NAME"]++;}
#line 2100 "parser.tab.c"
    break;

  case 131: /* testlist: testlist COMMA test  */
#line 291 "parser.y"
                    {fprintf(yyout,"testlist%d--COMMA%d;\n",m["testlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"testlist%d--test%d;\n",m["testlist"],m["test"]); m["test"]++;}
#line 2106 "parser.tab.c"
    break;

  case 132: /* testlist: test  */
#line 292 "parser.y"
       {fprintf(yyout,"testlist%d--test%d;\n",m["testlist"],m["test"]); m["test"]++;}
#line 2112 "parser.tab.c"
    break;

  case 133: /* exprlist: exprlist COMMA expr  */
#line 296 "parser.y"
                    {fprintf(yyout,"exprlist%d--COMMA%d;\n",m["exprlist"],m["COMMA"]); m["COMMA"]++; fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;}
#line 2118 "parser.tab.c"
    break;

  case 134: /* exprlist: expr  */
#line 297 "parser.y"
       {fprintf(yyout,"exprlist%d--expr%d;\n",m["exprlist"],m["expr"]); m["expr"]++;}
#line 2124 "parser.tab.c"
    break;


#line 2128 "parser.tab.c"

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

#line 301 "parser.y"

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
