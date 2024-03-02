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
  YYSYMBOL_opt_semicolon = 55,             /* opt_semicolon  */
  YYSYMBOL_more_expr = 56,                 /* more_expr  */
  YYSYMBOL_small_stmt = 57,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 58,                 /* expr_stmt  */
  YYSYMBOL_right_assign = 59,              /* right_assign  */
  YYSYMBOL_Assign_stmt = 60,               /* Assign_stmt  */
  YYSYMBOL_annassign = 61,                 /* annassign  */
  YYSYMBOL_break_stmt = 62,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 63,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 64,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 65,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 66,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 67,           /* elif_statements  */
  YYSYMBOL_else_statement_opt = 68,        /* else_statement_opt  */
  YYSYMBOL_while_stmt = 69,                /* while_stmt  */
  YYSYMBOL_for_stmt = 70,                  /* for_stmt  */
  YYSYMBOL_funcdef = 71,                   /* funcdef  */
  YYSYMBOL_return_arrow_opt = 72,          /* return_arrow_opt  */
  YYSYMBOL_parameters = 73,                /* parameters  */
  YYSYMBOL_typedargslist_opt = 74,         /* typedargslist_opt  */
  YYSYMBOL_typedargslist = 75,             /* typedargslist  */
  YYSYMBOL_tfpdef_list = 76,               /* tfpdef_list  */
  YYSYMBOL_full_tfpdef = 77,               /* full_tfpdef  */
  YYSYMBOL_classdef = 78,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 79,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 80,               /* opt_arglist  */
  YYSYMBOL_arglist = 81,                   /* arglist  */
  YYSYMBOL_opt_comma = 82,                 /* opt_comma  */
  YYSYMBOL_comma_arg_star = 83,            /* comma_arg_star  */
  YYSYMBOL_argument = 84,                  /* argument  */
  YYSYMBOL_opt_comp_for = 85,              /* opt_comp_for  */
  YYSYMBOL_comp_iter = 86,                 /* comp_iter  */
  YYSYMBOL_opt_comp_iter = 87,             /* opt_comp_iter  */
  YYSYMBOL_comp_for = 88,                  /* comp_for  */
  YYSYMBOL_comp_if = 89,                   /* comp_if  */
  YYSYMBOL_suite = 90,                     /* suite  */
  YYSYMBOL_stmt_list = 91,                 /* stmt_list  */
  YYSYMBOL_test = 92,                      /* test  */
  YYSYMBOL_opt_if_or_test_else_test = 93,  /* opt_if_or_test_else_test  */
  YYSYMBOL_test_nocond = 94,               /* test_nocond  */
  YYSYMBOL_or_test = 95,                   /* or_test  */
  YYSYMBOL_or_and_test_star = 96,          /* or_and_test_star  */
  YYSYMBOL_and_test = 97,                  /* and_test  */
  YYSYMBOL_and_not_test_star = 98,         /* and_not_test_star  */
  YYSYMBOL_not_test = 99,                  /* not_test  */
  YYSYMBOL_comparison = 100,               /* comparison  */
  YYSYMBOL_opt_expr = 101,                 /* opt_expr  */
  YYSYMBOL_expr = 102,                     /* expr  */
  YYSYMBOL_opt_xor = 103,                  /* opt_xor  */
  YYSYMBOL_xor_expr = 104,                 /* xor_expr  */
  YYSYMBOL_opt_and = 105,                  /* opt_and  */
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
  YYSYMBOL_opt_atom = 117,                 /* opt_atom  */
  YYSYMBOL_atom_expr = 118,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 119,              /* opt_trailer  */
  YYSYMBOL_atom = 120,                     /* atom  */
  YYSYMBOL_opt_testlist_comp = 121,        /* opt_testlist_comp  */
  YYSYMBOL_testlist_comp = 122,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 123,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 124,                  /* trailer  */
  YYSYMBOL_subscriptlist = 125,            /* subscriptlist  */
  YYSYMBOL_opt_subscript = 126,            /* opt_subscript  */
  YYSYMBOL_subscript = 127,                /* subscript  */
  YYSYMBOL_opt_test_sub = 128,             /* opt_test_sub  */
  YYSYMBOL_opt_sliceop = 129,              /* opt_sliceop  */
  YYSYMBOL_sliceop = 130,                  /* sliceop  */
  YYSYMBOL_testlist = 131,                 /* testlist  */
  YYSYMBOL_opt_testlist = 132,             /* opt_testlist  */
  YYSYMBOL_exprlist = 133,                 /* exprlist  */
  YYSYMBOL_opt_exprlist = 134              /* opt_exprlist  */
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251

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
       0,    24,    24,    25,    27,    27,    27,    30,    32,    33,
      35,    36,    38,    39,    40,    41,    44,    46,    47,    48,
      50,    51,    53,    54,    57,    59,    61,    62,    65,    65,
      65,    65,    65,    67,    69,    70,    72,    73,    76,    79,
      83,    85,    86,    88,    90,    91,    93,    95,    96,    98,
      99,   104,   106,   107,   109,   110,   112,   114,   115,   117,
     118,   120,   121,   123,   124,   126,   127,   129,   130,   132,
     134,   138,   138,   139,   141,   141,   143,   145,   146,   148,
     150,   152,   153,   155,   157,   158,   160,   161,   163,   165,
     166,   168,   170,   171,   173,   175,   176,   178,   180,   181,
     183,   185,   186,   188,   190,   191,   193,   195,   196,   198,
     199,   201,   202,   204,   206,   207,   209,   211,   212,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   225,
     226,   228,   229,   231,   232,   234,   235,   236,   237,   239,
     240,   242,   243,   245,   246,   249,   250,   253,   256,   258,
     259,   263,   265,   266
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
  "$accept", "module", "stmt", "simple_stmt", "opt_semicolon", "more_expr",
  "small_stmt", "expr_stmt", "right_assign", "Assign_stmt", "annassign",
  "break_stmt", "continue_stmt", "return_stmt", "compound_stmt", "if_stmt",
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
  "opt_sliceop", "sliceop", "testlist", "opt_testlist", "exprlist",
  "opt_exprlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-185)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-144)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,  -185,   233,   210,   210,  -185,    -7,  -185,  -185,   210,
    -185,   210,  -185,  -185,  -185,    -2,   210,   210,  -185,  -185,
    -185,  -185,  -185,    28,   114,  -185,    12,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,     8,    26,     5,
      23,  -185,    44,    20,    27,    22,    24,    30,    65,   233,
    -185,    31,     0,    21,    46,    45,    55,    57,    58,    11,
      56,  -185,    53,    60,  -185,  -185,  -185,  -185,   183,    66,
     210,    59,   210,  -185,   210,  -185,   210,  -185,   233,  -185,
     233,  -185,   233,  -185,   233,  -185,   233,  -185,   233,  -185,
     233,  -185,  -185,   233,  -185,   210,   210,    62,  -185,     0,
     210,   210,   210,  -185,  -185,  -185,   233,    59,   210,    17,
      17,   210,    70,   233,   210,  -185,    59,  -185,  -185,    71,
      74,    12,  -185,  -185,     8,  -185,  -185,    72,     5,    23,
      44,    20,    27,    22,    24,    30,    65,  -185,    76,  -185,
      77,    15,    82,    78,    79,    86,  -185,  -185,   100,  -185,
     101,    46,  -185,    90,    75,  -185,   102,   104,    91,    17,
      87,    95,  -185,   106,    98,  -185,   103,   210,   112,  -185,
    -185,   210,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,   210,    59,   210,  -185,  -185,  -185,   210,    59,
     210,  -185,   210,  -185,    17,   114,   116,  -185,   210,   102,
    -185,  -185,   210,  -185,  -185,  -185,    71,  -185,  -185,    17,
    -185,    77,  -185,  -185,    79,  -185,  -185,   117,  -185,   102,
     114,    18,    17,   118,  -185,    51,   103,  -185,  -185,  -185,
     210,  -185,  -185,  -185,  -185,  -185,  -185,  -185,    17,   210,
    -185,  -185,  -185,  -185,  -185,  -185,   104,    51,  -185,  -185,
    -185
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,   123,     0,     0,     0,    24,     0,    25,   128,   130,
     121,   130,   125,   126,   127,     0,     0,    26,     4,   112,
     111,   122,   124,     0,     3,     5,    11,    12,    13,    14,
      15,     6,    28,    29,    30,    31,    32,   149,    77,    81,
      84,    87,    90,    92,    95,    98,   101,   104,   107,     0,
     110,   115,   118,    21,   152,     0,     0,     0,    52,   133,
       0,   129,     0,     0,    86,    27,     1,     2,     0,     9,
       0,    57,     0,    76,     0,    80,     0,    83,     0,    88,
       0,    91,     0,    94,     0,    97,     0,   100,     0,   103,
       0,   106,   109,     0,   113,    54,   144,     0,   116,   118,
       0,     0,     0,    16,    19,    17,     0,    57,     0,     0,
       0,    54,     0,     0,     0,   131,    57,   119,   120,    44,
      41,    11,     8,     7,   149,    58,   148,     0,    81,    84,
      90,    92,    95,    98,   101,   104,   107,   114,     0,    55,
      59,    63,   141,     0,   140,     0,   137,   117,    21,    18,
      23,   152,   151,     0,     0,    71,    36,    34,     0,     0,
       0,   133,   132,    50,     0,    45,    48,     0,     0,    10,
     150,     0,    82,    85,    89,    93,    96,    99,   102,   105,
     108,   135,     0,    57,     0,    61,    64,   136,   144,    57,
     144,    20,     0,   153,     0,    75,     0,    38,     0,    36,
      53,    51,     0,   134,    49,    43,     0,    46,    42,     0,
      78,    59,    56,    62,   140,   138,   143,   146,    22,    36,
      75,     0,     0,     0,    33,    67,    48,    40,    60,   139,
     144,   142,   145,    39,    74,    73,    72,    37,     0,     0,
      68,    69,    65,    66,    47,   147,    34,    67,    79,    35,
      70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,   120,  -182,     2,  -185,    19,    81,  -185,  -185,     3,
     -13,  -185,  -185,  -185,  -185,  -185,   -94,  -184,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,   -73,   -50,  -185,  -185,    47,
    -185,  -102,   -54,   -21,  -185,  -185,   -85,   -47,  -185,  -106,
     -57,    -3,  -185,  -185,   -69,    37,    92,    38,    -6,  -185,
      39,     7,    40,    93,    42,    94,    49,    88,    41,    97,
      43,    89,    48,   -38,  -185,  -185,  -185,  -185,   105,  -185,
     169,  -185,    25,  -185,  -185,   -26,     4,  -174,  -185,  -185,
     -10,    67,    80,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,   155,   123,    69,    26,    27,   103,   104,
     105,    28,    29,    30,    31,    32,   199,   197,    33,    34,
      35,   168,   120,   164,   165,   207,   166,    36,   112,   138,
     139,   126,   183,   140,   185,   240,   241,   242,   243,   156,
     221,    37,    73,   247,    38,    75,    39,    77,    40,    41,
      79,    42,    81,    43,    83,    44,    85,    45,    87,    46,
      89,    47,    91,    48,    49,    50,    94,    51,    98,    52,
      60,    61,   116,    99,   143,   189,   144,   145,   231,   232,
      53,    71,    55,   107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    57,    25,   127,   157,   152,    59,    65,    59,    54,
      64,    92,   115,   220,   162,   224,   217,    58,   235,   113,
      95,   184,    63,   113,     1,    96,    25,   100,    66,    68,
       5,    70,     7,     8,   114,   233,    72,     9,   220,   101,
     102,    10,    11,    74,    12,    13,    14,    97,    78,    16,
      17,   154,   136,   201,   236,   137,   245,    19,    20,   113,
      76,   239,    21,    22,    80,    84,    82,   124,    90,   106,
     129,    88,    86,    93,   109,   108,   110,   117,   111,   118,
     119,   212,   125,   122,   171,   130,   146,   215,   219,   159,
     148,   149,   141,   142,   186,   163,   167,   181,   153,   150,
     182,  -143,   188,   227,   187,   190,   100,   192,   141,   194,
     195,   161,   200,   151,   196,   198,   237,   202,   114,   205,
      54,     1,     2,     3,     4,   102,   206,     5,     6,     7,
       8,   209,   246,   225,     9,   222,   230,   238,    10,    11,
     169,    12,    13,    14,    67,    15,    16,    17,    18,   121,
     204,   191,   249,   244,    19,    20,   226,   228,   158,    21,
      22,   211,   250,   234,   208,   172,   128,   173,   210,   174,
     248,   175,   133,   131,   176,   178,   132,   135,   179,   141,
      62,   213,   177,   134,   180,   142,   203,   216,   229,   218,
       1,   170,   214,   160,     0,   223,     5,    25,     7,     8,
       0,   193,     0,     9,   147,     0,     0,    10,    11,     0,
      12,    13,    14,     0,     0,    16,    17,     1,     0,     0,
       0,     0,    25,    19,    20,     0,     8,   216,    21,    22,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
       1,     0,    16,     0,     0,     0,     0,     0,     0,     8,
      19,    20,     0,     9,     0,    21,    22,    10,    11,     0,
      12,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,    72,   110,   107,     9,    17,    11,     2,
      16,    49,    59,   195,   116,   199,   190,    24,     0,     8,
      20,     6,    24,     8,     7,    25,    24,     6,     0,    17,
      13,    23,    15,    16,    23,   219,    10,    20,   220,    18,
      19,    24,    25,    38,    27,    28,    29,    47,     4,    32,
      33,    34,    90,   159,    36,    93,   230,    40,    41,     8,
      37,    10,    45,    46,    44,    43,    39,    70,     3,    23,
      76,    41,    48,    42,    19,    30,    19,    21,    20,    26,
      20,   183,    23,    17,    12,    78,    24,   189,   194,    19,
     100,   101,    95,    96,   141,    24,    22,    21,   108,   102,
      23,    19,    23,   209,    26,    19,     6,     6,   111,    19,
      35,   114,    21,   106,    12,    11,   222,    30,    23,    21,
     113,     7,     8,     9,    10,    19,    23,    13,    14,    15,
      16,    19,   238,   202,    20,    19,    19,    19,    24,    25,
     121,    27,    28,    29,    24,    31,    32,    33,    34,    68,
     163,   148,   246,   226,    40,    41,   206,   211,   111,    45,
      46,   182,   247,   220,   167,   128,    74,   129,   171,   130,
     239,   131,    84,    80,   132,   134,    82,    88,   135,   182,
      11,   184,   133,    86,   136,   188,   161,   190,   214,   192,
       7,   124,   188,   113,    -1,   198,    13,   195,    15,    16,
      -1,   151,    -1,    20,    99,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    33,     7,    -1,    -1,
      -1,    -1,   220,    40,    41,    -1,    16,   230,    45,    46,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
       7,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      40,    41,    -1,    20,    -1,    45,    46,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    45,    46,    52,    53,    54,    57,    58,    62,    63,
      64,    65,    66,    69,    70,    71,    78,    92,    95,    97,
      99,   100,   102,   104,   106,   108,   110,   112,   114,   115,
     116,   118,   120,   131,   102,   133,    92,    92,    24,    92,
     121,   122,   121,    24,    99,   131,     0,    52,    17,    56,
      23,   132,    10,    93,    38,    96,    37,    98,     4,   101,
      44,   103,    39,   105,    43,   107,    48,   109,    41,   111,
       3,   113,   114,    42,   117,    20,    25,    47,   119,   124,
       6,    18,    19,    59,    60,    61,    23,   134,    30,    19,
      19,    20,    79,     8,    23,    88,   123,    21,    26,    20,
      73,    57,    17,    55,    92,    23,    82,    95,    97,    99,
     102,   104,   106,   108,   110,   112,   114,   114,    80,    81,
      84,    92,    92,   125,   127,   128,    24,   119,   131,   131,
      92,   102,    82,   131,    34,    54,    90,    90,    80,    19,
     133,    92,    82,    24,    74,    75,    77,    22,    72,    56,
     132,    12,    96,    98,   101,   103,   105,   107,   109,   111,
     113,    21,    23,    83,     6,    85,    88,    26,    23,   126,
      19,    60,     6,   134,    19,    35,    12,    68,    11,    67,
      21,    90,    30,   123,    61,    21,    23,    76,    92,    19,
      92,    84,    82,    92,   127,    82,    92,   128,    92,    90,
      53,    91,    19,    92,    68,    95,    77,    90,    83,   126,
      19,   129,   130,    68,    91,     0,    36,    90,    19,    10,
      86,    87,    88,    89,    76,   128,    90,    94,    95,    67,
      87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    58,    59,    59,    59,
      60,    60,    61,    61,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    66,    67,    67,    68,    68,    69,    70,
      71,    72,    72,    73,    74,    74,    75,    76,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    90,    90,    90,    91,    91,    92,    93,    93,    94,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   101,
     101,   102,   103,   103,   104,   105,   105,   106,   107,   107,
     108,   109,   109,   110,   111,   111,   112,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   124,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   131,   132,
     132,   133,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     3,     1,     0,
       3,     0,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     0,     4,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     6,     0,     5,     0,     3,     5,     7,
       6,     0,     2,     3,     0,     1,     2,     3,     0,     2,
       1,     5,     0,     3,     0,     1,     3,     0,     1,     0,
       3,     2,     3,     0,     1,     1,     1,     0,     1,     5,
       3,     1,     4,     4,     2,     0,     2,     0,     4,     1,
       2,     0,     3,     2,     0,     3,     2,     1,     2,     3,
       0,     2,     0,     3,     2,     0,     3,     2,     0,     3,
       2,     0,     3,     2,     0,     3,     2,     0,     3,     2,
       1,     1,     1,     2,     2,     0,     2,     2,     0,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     3,     0,     3,     3,     3,     2,     3,     3,
       0,     1,     4,     1,     0,     1,     0,     2,     3,     0,
       3,     3,     0,     3
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
#line 24 "parser.y"
                     {fprintf(yyout,"stmt;\n module -- stmt;\n");}
#line 1412 "parser.tab.c"
    break;

  case 3: /* module: %empty  */
#line 25 "parser.y"
             {fprintf(yyout,"module;\n");}
#line 1418 "parser.tab.c"
    break;


#line 1422 "parser.tab.c"

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

#line 269 "parser.y"


void yyerror(const char *s){
   cout<<yytext<<" f u\n";
   return ;
}


int main ( int argc, char *argv[]){
     
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   fprintf(yyout,"graph ast {\n");
   yyparse();
   fprintf(yyout,"}");
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}
