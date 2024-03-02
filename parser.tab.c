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

extern int yyparse();
extern int yylex();
extern void yyerror(const char *);
extern int yylineno;
extern char* yytext;
extern FILE* yyin;  
extern FILE* yyout;


#line 85 "parser.tab.c"

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
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_module = 52,                    /* module  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_simple_stmt = 54,               /* simple_stmt  */
  YYSYMBOL_more_expr = 55,                 /* more_expr  */
  YYSYMBOL_small_stmt = 56,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 57,                 /* expr_stmt  */
  YYSYMBOL_right_assign = 58,              /* right_assign  */
  YYSYMBOL_Assign_stmt = 59,               /* Assign_stmt  */
  YYSYMBOL_annassign = 60,                 /* annassign  */
  YYSYMBOL_break_stmt = 61,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 62,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 63,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 64,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 65,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 66,           /* elif_statements  */
  YYSYMBOL_else_statement_opt = 67,        /* else_statement_opt  */
  YYSYMBOL_while_stmt = 68,                /* while_stmt  */
  YYSYMBOL_for_stmt = 69,                  /* for_stmt  */
  YYSYMBOL_funcdef = 70,                   /* funcdef  */
  YYSYMBOL_return_arrow_opt = 71,          /* return_arrow_opt  */
  YYSYMBOL_parameters = 72,                /* parameters  */
  YYSYMBOL_typedargslist_opt = 73,         /* typedargslist_opt  */
  YYSYMBOL_typedargslist = 74,             /* typedargslist  */
  YYSYMBOL_tfpdef_list = 75,               /* tfpdef_list  */
  YYSYMBOL_full_tfpdef = 76,               /* full_tfpdef  */
  YYSYMBOL_classdef = 77,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 78,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 79,               /* opt_arglist  */
  YYSYMBOL_arglist = 80,                   /* arglist  */
  YYSYMBOL_opt_comma = 81,                 /* opt_comma  */
  YYSYMBOL_comma_arg_star = 82,            /* comma_arg_star  */
  YYSYMBOL_argument = 83,                  /* argument  */
  YYSYMBOL_opt_comp_for = 84,              /* opt_comp_for  */
  YYSYMBOL_comp_iter = 85,                 /* comp_iter  */
  YYSYMBOL_opt_comp_iter = 86,             /* opt_comp_iter  */
  YYSYMBOL_comp_for = 87,                  /* comp_for  */
  YYSYMBOL_comp_if = 88,                   /* comp_if  */
  YYSYMBOL_suite = 89,                     /* suite  */
  YYSYMBOL_stmt_list = 90,                 /* stmt_list  */
  YYSYMBOL_test = 91,                      /* test  */
  YYSYMBOL_opt_if_or_test_else_test = 92,  /* opt_if_or_test_else_test  */
  YYSYMBOL_test_nocond = 93,               /* test_nocond  */
  YYSYMBOL_or_test = 94,                   /* or_test  */
  YYSYMBOL_or_and_test_star = 95,          /* or_and_test_star  */
  YYSYMBOL_and_test = 96,                  /* and_test  */
  YYSYMBOL_and_not_test_star = 97,         /* and_not_test_star  */
  YYSYMBOL_not_test = 98,                  /* not_test  */
  YYSYMBOL_comparison = 99,                /* comparison  */
  YYSYMBOL_opt_expr = 100,                 /* opt_expr  */
  YYSYMBOL_expr = 101,                     /* expr  */
  YYSYMBOL_opt_xor = 102,                  /* opt_xor  */
  YYSYMBOL_xor_expr = 103,                 /* xor_expr  */
  YYSYMBOL_opt_and = 104,                  /* opt_and  */
  YYSYMBOL_and_expr = 105,                 /* and_expr  */
  YYSYMBOL_opt_shift = 106,                /* opt_shift  */
  YYSYMBOL_shift_expr = 107,               /* shift_expr  */
  YYSYMBOL_opt_arith = 108,                /* opt_arith  */
  YYSYMBOL_arith_expr = 109,               /* arith_expr  */
  YYSYMBOL_opt_term = 110,                 /* opt_term  */
  YYSYMBOL_term = 111,                     /* term  */
  YYSYMBOL_opt_factor = 112,               /* opt_factor  */
  YYSYMBOL_factor = 113,                   /* factor  */
  YYSYMBOL_oper = 114,                     /* oper  */
  YYSYMBOL_power = 115,                    /* power  */
  YYSYMBOL_opt_atom = 116,                 /* opt_atom  */
  YYSYMBOL_atom_expr = 117,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 118,              /* opt_trailer  */
  YYSYMBOL_atom = 119,                     /* atom  */
  YYSYMBOL_opt_testlist_comp = 120,        /* opt_testlist_comp  */
  YYSYMBOL_testlist_comp = 121,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 122,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 123,                  /* trailer  */
  YYSYMBOL_subscriptlist = 124,            /* subscriptlist  */
  YYSYMBOL_opt_subscript = 125,            /* opt_subscript  */
  YYSYMBOL_subscript = 126,                /* subscript  */
  YYSYMBOL_opt_test_sub = 127,             /* opt_test_sub  */
  YYSYMBOL_opt_sliceop = 128,              /* opt_sliceop  */
  YYSYMBOL_sliceop = 129,                  /* sliceop  */
  YYSYMBOL_testlist = 130,                 /* testlist  */
  YYSYMBOL_exprlist = 131,                 /* exprlist  */
  YYSYMBOL_opt_exprlist = 132              /* opt_exprlist  */
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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    24,    24,    25,    27,    27,    27,    30,    30,    32,
      33,    35,    36,    37,    38,    41,    43,    44,    45,    47,
      48,    50,    51,    54,    56,    58,    62,    62,    62,    62,
      62,    64,    66,    67,    69,    70,    73,    76,    80,    82,
      83,    85,    87,    88,    90,    92,    93,    95,    96,   101,
     103,   104,   106,   107,   109,   111,   112,   114,   115,   117,
     118,   120,   121,   123,   124,   126,   127,   129,   131,   135,
     135,   136,   138,   138,   140,   142,   143,   145,   147,   149,
     150,   152,   154,   155,   157,   158,   160,   162,   163,   165,
     167,   168,   170,   172,   173,   175,   177,   178,   180,   182,
     183,   185,   187,   188,   190,   192,   193,   195,   196,   198,
     199,   201,   203,   204,   206,   208,   209,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   222,   223,   225,
     226,   228,   229,   231,   232,   233,   234,   236,   237,   239,
     240,   242,   243,   246,   247,   250,   253,   253,   257,   259,
     260
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
  "$accept", "module", "stmt", "simple_stmt", "more_expr", "small_stmt",
  "expr_stmt", "right_assign", "Assign_stmt", "annassign", "break_stmt",
  "continue_stmt", "return_stmt", "compound_stmt", "if_stmt",
  "elif_statements", "else_statement_opt", "while_stmt", "for_stmt",
  "funcdef", "return_arrow_opt", "parameters", "typedargslist_opt",
  "typedargslist", "tfpdef_list", "full_tfpdef", "classdef",
  "opt_class_arg", "opt_arglist", "arglist", "opt_comma", "comma_arg_star",
  "argument", "opt_comp_for", "comp_iter", "opt_comp_iter", "comp_for",
  "comp_if", "suite", "stmt_list", "test", "opt_if_or_test_else_test",
  "test_nocond", "or_test", "or_and_test_star", "and_test",
  "and_not_test_star", "not_test", "comparison", "opt_expr", "expr",
  "opt_xor", "xor_expr", "opt_and", "and_expr", "opt_shift", "shift_expr",
  "opt_arith", "arith_expr", "opt_term", "term", "opt_factor", "factor",
  "oper", "power", "opt_atom", "atom_expr", "opt_trailer", "atom",
  "opt_testlist_comp", "testlist_comp", "opt_test_stmt", "trailer",
  "subscriptlist", "opt_subscript", "subscript", "opt_test_sub",
  "opt_sliceop", "sliceop", "testlist", "exprlist", "opt_exprlist", YY_NULLPTR
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

#define YYTABLE_NINF (-142)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,  -179,   227,   204,   204,  -179,    -8,  -179,  -179,   204,
    -179,   204,  -179,  -179,  -179,    -7,   204,   204,  -179,  -179,
    -179,  -179,  -179,    38,   109,  -179,    25,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    24,    10,
      21,    23,  -179,    54,    26,    28,    30,    27,    22,    61,
     227,  -179,    29,    -1,    15,    45,    44,    57,    58,    59,
      14,    60,  -179,    52,    62,  -179,  -179,  -179,  -179,   177,
     204,   204,  -179,   204,  -179,   204,  -179,   227,  -179,   227,
    -179,   227,  -179,   227,  -179,   227,  -179,   227,  -179,   227,
    -179,  -179,   227,  -179,   204,   204,    63,  -179,    -1,   204,
     204,   204,  -179,  -179,  -179,   227,    65,   204,    16,    16,
     204,    64,   227,   204,  -179,    65,  -179,  -179,    66,    67,
    -179,  -179,    72,    21,    23,    54,    26,    28,    30,    27,
      22,    61,  -179,    75,  -179,    70,    19,    78,    73,    77,
      84,  -179,  -179,    98,  -179,    99,    45,  -179,  -179,    87,
      74,  -179,   100,   102,    90,    16,    91,    97,  -179,   107,
     106,  -179,   108,   204,   113,   204,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,   204,    65,   204,  -179,
    -179,  -179,   204,    65,   204,  -179,   204,  -179,    16,   109,
     116,  -179,   204,   100,  -179,  -179,   204,  -179,  -179,  -179,
      66,  -179,  -179,    16,  -179,    70,  -179,  -179,    77,  -179,
    -179,   120,  -179,   100,   109,    18,    16,   125,  -179,    20,
     108,  -179,  -179,  -179,   204,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,    16,   204,  -179,  -179,  -179,  -179,  -179,  -179,
     102,    20,  -179,  -179,  -179
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,   121,     0,     0,     0,    23,     0,    24,   126,   128,
     119,   128,   123,   124,   125,     0,     0,     0,     4,   110,
     109,   120,   122,     0,     3,     5,     7,    10,    11,    12,
      13,    14,     6,    26,    27,    28,    29,    30,   147,    75,
      79,    82,    85,    88,    90,    93,    96,    99,   102,   105,
       0,   108,   113,   116,    20,   149,     0,     0,     0,    50,
     131,     0,   127,     0,     0,    84,    25,     1,     2,     8,
       0,     0,    74,     0,    78,     0,    81,     0,    86,     0,
      89,     0,    92,     0,    95,     0,    98,     0,   101,     0,
     104,   107,     0,   111,    52,   142,     0,   114,   116,     0,
       0,     0,    15,    18,    16,     0,    55,     0,     0,     0,
      52,     0,     0,     0,   129,    55,   117,   118,    42,    39,
       9,   146,     0,    79,    82,    88,    90,    93,    96,    99,
     102,   105,   112,     0,    53,    57,    61,   139,     0,   138,
       0,   135,   115,    20,    17,    22,   149,    56,   148,     0,
       0,    69,    34,    32,     0,     0,     0,   131,   130,    48,
       0,    43,    46,     0,     0,     0,    80,    83,    87,    91,
      94,    97,   100,   103,   106,   133,     0,    55,     0,    59,
      62,   134,   142,    55,   142,    19,     0,   150,     0,    73,
       0,    36,     0,    34,    51,    49,     0,   132,    47,    41,
       0,    44,    40,     0,    76,    57,    54,    60,   138,   136,
     141,   144,    21,    34,    73,     0,     0,     0,    31,    65,
      46,    38,    58,   137,   142,   140,   143,    37,    72,    71,
      70,    35,     0,     0,    66,    67,    63,    64,    45,   145,
      32,    65,    77,    33,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,   121,  -175,     2,  -179,    79,  -179,  -179,     4,   -13,
    -179,  -179,  -179,  -179,  -179,   -89,  -178,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,   -67,   -48,  -179,  -179,    46,  -179,
    -111,   -47,   -19,  -179,  -179,   -82,   -51,  -179,  -102,   -53,
      -3,  -179,  -179,   -68,    40,    93,    43,    -6,  -179,    39,
       3,    42,    92,    47,    88,    48,    89,    41,    95,    55,
     101,    51,   -37,  -179,  -179,  -179,  -179,    80,  -179,   166,
    -179,    37,  -179,  -179,   -22,     5,  -173,  -179,  -179,    -5,
      83,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,   151,    26,    27,    28,   102,   103,   104,
      29,    30,    31,    32,    33,   193,   191,    34,    35,    36,
     164,   119,   160,   161,   201,   162,    37,   111,   133,   134,
     148,   177,   135,   179,   234,   235,   236,   237,   152,   215,
      38,    72,   241,    39,    74,    40,    76,    41,    42,    78,
      43,    80,    44,    82,    45,    84,    46,    86,    47,    88,
      48,    90,    49,    50,    51,    93,    52,    97,    53,    61,
      62,   115,    98,   138,   183,   139,   140,   225,   226,    54,
      56,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    58,    25,   122,   158,    55,    60,   153,    60,   114,
      65,   211,    66,    91,   214,   218,    59,    64,   229,    94,
      71,    99,   112,     1,    95,   178,    25,   112,   112,     5,
     233,     7,     8,   100,   101,   227,     9,   113,    67,   214,
      10,    11,    69,    12,    13,    14,    96,    70,    16,    17,
     150,   239,   131,   195,   230,   132,    19,    20,    77,    73,
      75,    21,    22,    87,    89,   121,   206,    81,   105,   124,
      79,    92,   209,    83,   107,    85,   108,   109,   117,   110,
     125,   116,   118,   155,   165,   180,   213,   141,   147,   163,
     159,   136,   137,   176,   143,   144,   175,  -141,   145,   181,
     182,   221,   149,   184,    99,   186,   188,   136,   146,   189,
     157,   194,   190,   192,   231,    55,     1,     2,     3,     4,
     113,   196,     5,     6,     7,     8,   101,   199,   219,     9,
     240,   200,   203,    10,    11,   216,    12,    13,    14,   224,
      15,    16,    17,    18,   232,    68,   198,   185,   120,    19,
      20,   243,   220,   238,    21,    22,   154,   205,   222,   244,
     202,   228,   204,   166,   168,   242,   123,   167,   169,   127,
     172,   126,   128,   136,   170,   207,   171,    63,   142,   137,
     129,   210,   174,   212,     1,   173,   223,   208,   130,   217,
       5,    25,     7,     8,   197,   156,   187,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     0,     0,    16,
      17,     1,     0,     0,     0,     0,    25,    19,    20,     0,
       8,   210,    21,    22,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,     1,     0,    16,     0,     0,     0,
       0,     0,     0,     8,    19,    20,     0,     9,     0,    21,
      22,    10,    11,     0,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,    71,   115,     2,     9,   109,    11,    60,
      16,   184,    17,    50,   189,   193,    24,    24,     0,    20,
      10,     6,     8,     7,    25,     6,    24,     8,     8,    13,
      10,    15,    16,    18,    19,   213,    20,    23,     0,   214,
      24,    25,    17,    27,    28,    29,    47,    23,    32,    33,
      34,   224,    89,   155,    36,    92,    40,    41,     4,    38,
      37,    45,    46,    41,     3,    70,   177,    39,    23,    75,
      44,    42,   183,    43,    30,    48,    19,    19,    26,    20,
      77,    21,    20,    19,    12,   136,   188,    24,    23,    22,
      24,    94,    95,    23,    99,   100,    21,    19,   101,    26,
      23,   203,   107,    19,     6,     6,    19,   110,   105,    35,
     113,    21,    12,    11,   216,   112,     7,     8,     9,    10,
      23,    30,    13,    14,    15,    16,    19,    21,   196,    20,
     232,    23,    19,    24,    25,    19,    27,    28,    29,    19,
      31,    32,    33,    34,    19,    24,   159,   143,    69,    40,
      41,   240,   200,   220,    45,    46,   110,   176,   205,   241,
     163,   214,   165,   123,   125,   233,    73,   124,   126,    81,
     129,    79,    83,   176,   127,   178,   128,    11,    98,   182,
      85,   184,   131,   186,     7,   130,   208,   182,    87,   192,
      13,   189,    15,    16,   157,   112,   146,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      33,     7,    -1,    -1,    -1,    -1,   214,    40,    41,    -1,
      16,   224,    45,    46,    20,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,     7,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    40,    41,    -1,    20,    -1,    45,
      46,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    45,    46,    52,    53,    54,    55,    56,    57,    61,
      62,    63,    64,    65,    68,    69,    70,    77,    91,    94,
      96,    98,    99,   101,   103,   105,   107,   109,   111,   113,
     114,   115,   117,   119,   130,   101,   131,    91,    91,    24,
      91,   120,   121,   120,    24,    98,   130,     0,    52,    17,
      23,    10,    92,    38,    95,    37,    97,     4,   100,    44,
     102,    39,   104,    43,   106,    48,   108,    41,   110,     3,
     112,   113,    42,   116,    20,    25,    47,   118,   123,     6,
      18,    19,    58,    59,    60,    23,   132,    30,    19,    19,
      20,    78,     8,    23,    87,   122,    21,    26,    20,    72,
      56,   130,    94,    96,    98,   101,   103,   105,   107,   109,
     111,   113,   113,    79,    80,    83,    91,    91,   124,   126,
     127,    24,   118,   130,   130,    91,   101,    23,    81,   130,
      34,    54,    89,    89,    79,    19,   131,    91,    81,    24,
      73,    74,    76,    22,    71,    12,    95,    97,   100,   102,
     104,   106,   108,   110,   112,    21,    23,    82,     6,    84,
      87,    26,    23,   125,    19,    59,     6,   132,    19,    35,
      12,    67,    11,    66,    21,    89,    30,   122,    60,    21,
      23,    75,    91,    19,    91,    83,    81,    91,   126,    81,
      91,   127,    91,    89,    53,    90,    19,    91,    67,    94,
      76,    89,    82,   125,    19,   128,   129,    67,    90,     0,
      36,    89,    19,    10,    85,    86,    87,    88,    75,   127,
      89,    93,    94,    66,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    63,    64,    64,    64,    64,
      64,    65,    66,    66,    67,    67,    68,    69,    70,    71,
      71,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    89,
      89,    89,    90,    90,    91,    92,    92,    93,    94,    95,
      95,    96,    97,    97,    98,    98,    99,   100,   100,   101,
     102,   102,   103,   104,   104,   105,   106,   106,   107,   108,
     108,   109,   110,   110,   111,   112,   112,   113,   113,   114,
     114,   115,   116,   116,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   130,   130,   131,   132,
     132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     3,
       0,     4,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     6,     0,     5,     0,     3,     5,     7,     6,     0,
       2,     3,     0,     1,     2,     3,     0,     2,     1,     5,
       0,     3,     0,     1,     3,     0,     1,     0,     3,     2,
       3,     0,     1,     1,     1,     0,     1,     5,     3,     1,
       4,     4,     2,     0,     2,     0,     4,     1,     2,     0,
       3,     2,     0,     3,     2,     1,     2,     3,     0,     2,
       0,     3,     2,     0,     3,     2,     0,     3,     2,     0,
       3,     2,     0,     3,     2,     0,     3,     2,     1,     1,
       1,     2,     2,     0,     2,     2,     0,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       3,     0,     3,     3,     3,     2,     3,     3,     0,     1,
       4,     1,     0,     1,     0,     2,     3,     1,     3,     0,
       3
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
  case 9: /* more_expr: more_expr SEMICOLON small_stmt  */
#line 32 "parser.y"
                                         {cout<<"y";}
#line 1406 "parser.tab.c"
    break;


#line 1410 "parser.tab.c"

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

#line 263 "parser.y"


void yyerror(const char *s){
   cout<<yytext<<" f u\n";
   return ;
}


int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   
   yyparse();
   
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}
