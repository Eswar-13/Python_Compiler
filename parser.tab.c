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
map<string,int>m;
int node=0;

char* integerToOperator(int value) {
    // Map each integer value to its corresponding operator string
    if (value == 0) {
        return (char *) "+=";
    } else if (value == 1) {
        return (char *) "-=";
    } else if (value == 2) {
        return (char *) "*=";
    } else if (value == 3) {
        return (char *) "/=";
    } else if (value == 4) {
        return (char *) "//=";
    } else if (value == 5) {
        return (char *) "%=";
    } else if (value == 6) {
        return (char *) "**=";
    } else if (value == 7) {
        return (char *) "&=";
    } else if (value == 8) {
        return (char *) "|=";
    } else if (value == 9) {
        return (char *) "^=";
    } else if (value == 10) {
        return (char *) "<<=";
    } else if (value == 11) {
        return (char *) ">>=";
    } else {
        return (char *)""; // Return empty string for invalid integer values
    }
}
char * addBackslashBeforeQuotes(string inputString) {
    string modifiedString;
    for (char ch : inputString) {
        if (ch == '"') {
            modifiedString += '\\'; // Add backslash before double quote
        }
        modifiedString += ch;
    }
    const char* str=modifiedString.c_str();
    return (char *)str;
}

#line 132 "parser.tab.c"

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
  YYSYMBOL_L_SHIFT = 49,                   /* L_SHIFT  */
  YYSYMBOL_R_SHIFT = 50,                   /* R_SHIFT  */
  YYSYMBOL_STRING_1 = 51,                  /* STRING_1  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 52,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 53,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_low = 54,                       /* low  */
  YYSYMBOL_low1 = 55,                      /* low1  */
  YYSYMBOL_low2 = 56,                      /* low2  */
  YYSYMBOL_low3 = 57,                      /* low3  */
  YYSYMBOL_low4 = 58,                      /* low4  */
  YYSYMBOL_low5 = 59,                      /* low5  */
  YYSYMBOL_low6 = 60,                      /* low6  */
  YYSYMBOL_high = 61,                      /* high  */
  YYSYMBOL_high1 = 62,                     /* high1  */
  YYSYMBOL_SHIFT = 63,                     /* SHIFT  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_module = 65,                    /* module  */
  YYSYMBOL_stmt = 66,                      /* stmt  */
  YYSYMBOL_simple_stmt = 67,               /* simple_stmt  */
  YYSYMBOL_more_expr = 68,                 /* more_expr  */
  YYSYMBOL_small_stmt = 69,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 70,                 /* expr_stmt  */
  YYSYMBOL_Assign_stmt = 71,               /* Assign_stmt  */
  YYSYMBOL_annassign = 72,                 /* annassign  */
  YYSYMBOL_param_list = 73,                /* param_list  */
  YYSYMBOL_break_stmt = 74,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 75,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 76,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 77,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 78,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 79,           /* elif_statements  */
  YYSYMBOL_else_statement = 80,            /* else_statement  */
  YYSYMBOL_while_stmt = 81,                /* while_stmt  */
  YYSYMBOL_for_stmt = 82,                  /* for_stmt  */
  YYSYMBOL_funcdef = 83,                   /* funcdef  */
  YYSYMBOL_parameters = 84,                /* parameters  */
  YYSYMBOL_typedargslist = 85,             /* typedargslist  */
  YYSYMBOL_full_tfpdef = 86,               /* full_tfpdef  */
  YYSYMBOL_name = 87,                      /* name  */
  YYSYMBOL_classdef = 88,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 89,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 90,               /* opt_arglist  */
  YYSYMBOL_arglist = 91,                   /* arglist  */
  YYSYMBOL_argument = 92,                  /* argument  */
  YYSYMBOL_comp_iter = 93,                 /* comp_iter  */
  YYSYMBOL_comp_for = 94,                  /* comp_for  */
  YYSYMBOL_comp_if = 95,                   /* comp_if  */
  YYSYMBOL_suite = 96,                     /* suite  */
  YYSYMBOL_stmt_list = 97,                 /* stmt_list  */
  YYSYMBOL_test = 98,                      /* test  */
  YYSYMBOL_or_test = 99,                   /* or_test  */
  YYSYMBOL_and_test = 100,                 /* and_test  */
  YYSYMBOL_not_test = 101,                 /* not_test  */
  YYSYMBOL_comparison = 102,               /* comparison  */
  YYSYMBOL_r_o = 103,                      /* r_o  */
  YYSYMBOL_expr = 104,                     /* expr  */
  YYSYMBOL_xor_expr = 105,                 /* xor_expr  */
  YYSYMBOL_and_expr = 106,                 /* and_expr  */
  YYSYMBOL_shift_expr = 107,               /* shift_expr  */
  YYSYMBOL_arith_expr = 108,               /* arith_expr  */
  YYSYMBOL_term = 109,                     /* term  */
  YYSYMBOL_a_o = 110,                      /* a_o  */
  YYSYMBOL_factor = 111,                   /* factor  */
  YYSYMBOL_power = 112,                    /* power  */
  YYSYMBOL_atom_expr = 113,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 114,              /* opt_trailer  */
  YYSYMBOL_atom = 115,                     /* atom  */
  YYSYMBOL_testlist_comp = 116,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 117,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 118,                  /* trailer  */
  YYSYMBOL_testlist = 119,                 /* testlist  */
  YYSYMBOL_exprlist = 120                  /* exprlist  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    94,    98,    99,   100,   101,   104,   105,
     108,   109,   113,   114,   115,   116,   120,   121,   122,   125,
     126,   129,   130,   134,   137,   140,   143,   144,   150,   151,
     152,   153,   154,   157,   158,   159,   160,   163,   164,   167,
     171,   172,   176,   177,   181,   182,   185,   186,   190,   191,
     195,   196,   198,   202,   203,   207,   208,   212,   213,   218,
     219,   223,   224,   225,   229,   230,   234,   235,   239,   240,
     244,   245,   246,   249,   250,   253,   254,   257,   258,   261,
     262,   265,   266,   268,   269,   271,   273,   274,   276,   277,
     279,   280,   282,   283,   284,   287,   288,   289,   291,   292,
     293,   296,   297,   298,   299,   302,   303,   306,   307,   310,
     311,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   330,   331,   332,   335,   336,   341,
     342,   343,   344,   348,   349,   353,   354
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
  "STRING", "DOT", "L_SHIFT", "R_SHIFT", "STRING_1", "LEFT_CURLY_BRACKET",
  "RIGHT_CURLY_BRACKET", "low", "low1", "low2", "low3", "low4", "low5",
  "low6", "high", "high1", "SHIFT", "$accept", "module", "stmt",
  "simple_stmt", "more_expr", "small_stmt", "expr_stmt", "Assign_stmt",
  "annassign", "param_list", "break_stmt", "continue_stmt", "return_stmt",
  "compound_stmt", "if_stmt", "elif_statements", "else_statement",
  "while_stmt", "for_stmt", "funcdef", "parameters", "typedargslist",
  "full_tfpdef", "name", "classdef", "opt_class_arg", "opt_arglist",
  "arglist", "argument", "comp_iter", "comp_for", "comp_if", "suite",
  "stmt_list", "test", "or_test", "and_test", "not_test", "comparison",
  "r_o", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "a_o", "factor", "power", "atom_expr", "opt_trailer", "atom",
  "testlist_comp", "opt_test_stmt", "trailer", "testlist", "exprlist", YY_NULLPTR
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

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,  -149,   451,   423,   423,  -149,   -11,  -149,  -149,   101,
    -149,   339,  -149,  -149,  -149,    -5,   423,   423,  -149,   451,
     451,   451,  -149,  -149,  -149,   237,  -149,  -149,     8,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,     7,    11,  -149,    30,    16,    31,    43,    52,    74,
      78,  -149,  -149,    50,    32,   113,    16,    -7,    21,    84,
     104,  -149,    89,    92,    87,  -149,   111,    98,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,   311,   423,   423,   423,  -149,
     451,   451,   451,   451,   451,   451,   451,   451,  -149,   451,
     451,   367,   423,   103,    32,  -149,   423,   423,   423,   423,
     138,  -149,   451,   423,   274,   274,   274,   395,   127,   451,
    -149,  -149,   423,  -149,    54,    60,  -149,   113,    27,    11,
    -149,    16,    43,    43,    52,    74,    74,    78,    78,  -149,
    -149,  -149,    63,  -149,    18,   125,  -149,  -149,  -149,   130,
     130,   149,  -149,   423,    16,    53,   124,  -149,   146,   123,
    -149,  -149,   141,   145,   274,    37,  -149,  -149,   150,    71,
    -149,   151,   274,   423,   423,  -149,   423,   423,  -149,  -149,
     423,  -149,   130,   274,    22,   152,  -149,   423,   128,  -149,
    -149,   423,  -149,   423,  -149,   148,  -149,  -149,   154,  -149,
    -149,  -149,  -149,   146,  -149,   192,   274,   160,   423,  -149,
      33,  -149,   274,  -149,  -149,  -149,  -149,  -149,   274,   161,
     423,  -149,  -149,  -149,  -149,  -149,   274,    33,  -149,  -149
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   117,     0,     0,     0,    24,     0,    25,   123,     0,
     115,     0,   120,   121,   122,     0,     0,    26,     4,     0,
       0,     0,   116,   118,   119,     0,     3,     5,     8,    11,
      12,    13,    14,    15,     6,    28,    29,    30,    31,    32,
     134,    76,    78,    80,    82,    84,    87,    89,    91,    94,
      97,    99,   104,   106,   108,     7,   136,     0,     0,     0,
       0,   112,   127,     0,   126,   113,     0,     0,    81,    27,
     103,   101,   102,     1,     2,     9,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   107,   110,     0,     0,     0,     0,
      18,    16,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   111,   125,   114,     0,     0,    10,     0,     0,    77,
      79,    83,    86,    88,    90,    92,    93,    95,    96,    98,
     105,   130,     0,    60,    61,     0,    52,   132,   109,    20,
      17,    22,   133,     0,   135,     0,     0,    70,    40,    33,
      54,    55,     0,    58,     0,     0,   128,    46,    51,     0,
      49,     0,     0,     0,     0,   129,     0,     0,    62,   131,
       0,    21,    19,     0,     0,     0,    41,     0,    35,    34,
      56,    57,    53,     0,    47,     0,    50,    44,     0,    75,
      59,    63,    23,    42,    74,     0,     0,     0,     0,    36,
      66,    48,     0,    43,    72,    71,    73,    39,     0,     0,
       0,    67,    64,    65,    45,    38,     0,    68,    37,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   -20,     3,  -149,   106,  -149,  -149,    23,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -134,  -149,  -149,  -149,
    -149,  -149,    -2,    93,  -149,  -149,  -149,    75,  -148,   -32,
     -51,  -149,   -96,  -149,    -3,   -72,   110,    -4,  -149,  -149,
       5,  -149,    68,   105,    72,    79,  -149,     1,  -149,  -149,
    -149,  -149,   178,  -149,    96,     2,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,   147,    28,    29,    30,   100,   101,   171,
      31,    32,    33,    34,    35,   178,   176,    36,    37,    38,
     115,   159,   160,   161,    39,   108,   152,   132,   133,   211,
     212,   213,   148,   195,    40,    41,    42,    43,    44,    80,
      45,    46,    47,    48,    49,    50,    89,    51,    52,    53,
      94,    54,    63,    64,    95,   117,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    59,    55,    27,   118,    74,    62,    56,    62,   149,
     150,   110,    68,    60,    69,   179,   102,    76,   190,    67,
      70,    71,    72,   103,   167,    75,   109,    55,    27,     1,
       2,     3,     4,   190,    79,     5,     6,     7,     8,   164,
     104,   109,     9,   210,   199,    77,    10,    11,    78,    12,
      13,    14,    91,    15,    16,    17,    18,    92,   182,   203,
     102,    81,    19,    20,    21,    77,   187,   183,    22,    23,
      82,    77,   173,    24,   120,   157,    99,   193,   158,   162,
      93,    88,   163,   168,   165,   121,   166,    83,   134,   135,
     129,   130,   184,    90,   185,   141,   142,   109,   139,   140,
     207,    84,    85,   105,   134,   145,   214,   144,     1,   156,
     112,   200,   215,   111,    56,    86,    87,     8,   114,    96,
     218,     9,    61,   106,   107,    10,    11,   136,    12,    13,
      14,    97,    98,    16,   177,   175,    99,   113,   217,   198,
     175,    19,    20,    21,   143,   172,   154,    22,    23,   122,
     123,   169,    24,    99,   194,   170,   125,   126,   175,   174,
     188,   189,   180,   134,   191,   127,   128,   192,   181,   -52,
      98,   196,   158,   202,   197,   206,    55,    27,   134,   208,
     216,   116,   153,   201,   186,   219,   137,   119,   124,    66,
     138,   155,   204,     0,     0,   209,     0,    55,    27,     1,
       2,     3,     4,     0,     0,     5,     6,     7,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,     0,    15,    16,    17,    18,     0,   205,     0,
       0,     0,    19,    20,    21,     0,     0,    73,    22,    23,
       0,     0,     0,    24,     1,     2,     3,     4,     0,     0,
       5,     6,     7,     8,     0,     0,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     0,    15,    16,
      17,    18,     0,     0,     0,     0,     0,    19,    20,    21,
       0,     1,     0,    22,    23,     0,     0,     5,    24,     7,
       8,     0,     0,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,     0,     0,    16,    17,   146,     0,
       0,     0,     0,     0,    19,    20,    21,     0,     1,     0,
      22,    23,     0,     0,     5,    24,     7,     8,     0,     0,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,     0,     0,    16,    17,     0,     1,     0,     0,     0,
       0,    19,    20,    21,     0,     8,     0,    22,    23,     9,
       0,     0,    24,    10,    11,    65,    12,    13,    14,     0,
       0,    16,     0,     0,     1,     0,     0,     0,     0,    19,
      20,    21,     0,     8,     0,    22,    23,     9,   131,     0,
      24,    10,    11,     0,    12,    13,    14,     0,     0,    16,
       0,     0,     1,     0,     0,     0,     0,    19,    20,    21,
       0,     8,     0,    22,    23,     9,   151,     0,    24,    10,
      11,     0,    12,    13,    14,     0,     0,    16,     0,     0,
       1,     0,     0,     0,     0,    19,    20,    21,     0,     8,
       0,    22,    23,     9,     0,     0,    24,    10,    11,     0,
      12,    13,    14,     0,     0,    16,     0,     0,     1,     0,
       0,     0,     0,    19,    20,    21,     0,     8,     0,    22,
      23,     9,     0,     0,    24,    10,    11,     0,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,     0,     0,     0,    22,    23,     0,
       0,     0,    24
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    76,    25,     9,     2,    11,   105,
     106,    62,    16,    24,    17,   149,    23,    10,   166,    24,
      19,    20,    21,    30,     6,    17,     8,    25,    25,     7,
       8,     9,    10,   181,     4,    13,    14,    15,    16,    12,
      19,     8,    20,    10,   178,    38,    24,    25,    37,    27,
      28,    29,    20,    31,    32,    33,    34,    25,   154,   193,
      23,    45,    40,    41,    42,    38,   162,    30,    46,    47,
      39,    38,    19,    51,    78,    21,    23,   173,    24,    19,
      48,     3,    22,   134,    21,    80,    23,    44,    91,    92,
      89,    90,    21,    43,    23,    98,    99,     8,    96,    97,
     196,    49,    50,    19,   107,   103,   202,   102,     7,   112,
      23,   183,   208,    21,   109,    41,    42,    16,    20,     6,
     216,    20,    21,    19,    20,    24,    25,    24,    27,    28,
      29,    18,    19,    32,    11,    12,    23,    26,   210,    11,
      12,    40,    41,    42,     6,   143,    19,    46,    47,    81,
      82,    26,    51,    23,   174,     6,    84,    85,    12,    35,
     163,   164,    21,   166,   167,    86,    87,   170,    23,    19,
      19,    19,    24,    19,   177,   195,   174,   174,   181,    19,
      19,    75,   107,   185,   161,   217,    93,    77,    83,    11,
      94,   109,     0,    -1,    -1,   198,    -1,   195,   195,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,     0,    46,    47,
      -1,    -1,    -1,    51,     7,     8,     9,    10,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,     7,    -1,    46,    47,    -1,    -1,    13,    51,    15,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,     7,    -1,
      46,    47,    -1,    -1,    13,    51,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    33,    -1,     7,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    16,    -1,    46,    47,    20,
      -1,    -1,    51,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    16,    -1,    46,    47,    20,    21,    -1,
      51,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    16,    -1,    46,    47,    20,    21,    -1,    51,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    16,
      -1,    46,    47,    20,    -1,    -1,    51,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,
      47,    20,    -1,    -1,    51,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    51,    65,    66,    67,    68,    69,
      70,    74,    75,    76,    77,    78,    81,    82,    83,    88,
      98,    99,   100,   101,   102,   104,   105,   106,   107,   108,
     109,   111,   112,   113,   115,   119,   104,   120,    98,    98,
      24,    21,    98,   116,   117,    26,   116,    24,   101,    98,
     111,   111,   111,     0,    66,    17,    10,    38,    37,     4,
     103,    45,    39,    44,    49,    50,    41,    42,     3,   110,
      43,    20,    25,    48,   114,   118,     6,    18,    19,    23,
      71,    72,    23,    30,    19,    19,    19,    20,    89,     8,
      94,    21,    23,    26,    20,    84,    69,   119,    99,   100,
     101,   104,   106,   106,   107,   108,   108,   109,   109,   111,
     111,    21,    91,    92,    98,    98,    24,    87,   118,   119,
     119,    98,    98,     6,   104,   119,    34,    67,    96,    96,
      96,    21,    90,    91,    19,   120,    98,    21,    24,    85,
      86,    87,    19,    22,    12,    21,    23,     6,    94,    26,
       6,    73,   119,    19,    35,    12,    80,    11,    79,    80,
      21,    23,    96,    30,    21,    23,    72,    96,    98,    98,
      92,    98,    98,    96,    66,    97,    19,    98,    11,    80,
      99,    86,    19,    80,     0,    36,    66,    96,    19,    98,
      10,    93,    94,    95,    96,    96,    19,    99,    96,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    73,    74,    75,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   107,   108,   108,   108,   109,   109,
     110,   111,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     2,     3,
       2,     3,     2,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     5,     5,     6,     5,     4,     3,
       4,     5,     6,     7,     5,     7,     2,     3,     3,     1,
       2,     1,     1,     5,     4,     2,     3,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     4,     5,     2,     3,
       1,     4,     4,     2,     1,     5,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     2,     2,     2,     1,     3,     1,     2,     1,     2,
       1,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     3,     3,
       2,     3,     2,     3,     1,     3,     1
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
  case 2: /* module: module stmt  */
#line 93 "parser.y"
                               { if((yyvsp[0].attributes).top!=-1)fprintf(yyout,"module--%d;\n",(yyvsp[0].attributes).top);}
#line 1462 "parser.tab.c"
    break;

  case 3: /* module: stmt  */
#line 94 "parser.y"
      { if((yyvsp[0].attributes).top!=-1)fprintf(yyout,"module--%d;\n",(yyvsp[0].attributes).top);}
#line 1468 "parser.tab.c"
    break;

  case 4: /* stmt: NEWLINE  */
#line 98 "parser.y"
        {(yyval.attributes).top=-1;}
#line 1474 "parser.tab.c"
    break;

  case 5: /* stmt: simple_stmt  */
#line 99 "parser.y"
              {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1480 "parser.tab.c"
    break;

  case 6: /* stmt: compound_stmt  */
#line 100 "parser.y"
                {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1486 "parser.tab.c"
    break;

  case 7: /* stmt: testlist  */
#line 101 "parser.y"
           {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1492 "parser.tab.c"
    break;

  case 8: /* simple_stmt: more_expr  */
#line 104 "parser.y"
                                 {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1498 "parser.tab.c"
    break;

  case 9: /* simple_stmt: more_expr SEMICOLON  */
#line 105 "parser.y"
                                 {fprintf(yyout,"%d--%d; %d[label=\" DELIMITER(;)\"];\n",(yyvsp[-1].attributes).top,node,node); node++; (yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 1504 "parser.tab.c"
    break;

  case 10: /* more_expr: more_expr SEMICOLON small_stmt  */
#line 108 "parser.y"
                               {fprintf(yyout,"%d--%d; %d[label=\" DELIMITER(;)\"];\n",(yyvsp[-2].attributes).top,node,node); node++; (yyval.attributes).top=(yyvsp[-2].attributes).top; fprintf(yyout,"%d--%d;\n",(yyvsp[-2].attributes).top,(yyvsp[0].attributes).top);}
#line 1510 "parser.tab.c"
    break;

  case 11: /* more_expr: small_stmt  */
#line 109 "parser.y"
            {fprintf(yyout,"%d--%d; %d[label=\" Stmt List\"];\n",node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1516 "parser.tab.c"
    break;

  case 12: /* small_stmt: expr_stmt  */
#line 113 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1522 "parser.tab.c"
    break;

  case 13: /* small_stmt: break_stmt  */
#line 114 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1528 "parser.tab.c"
    break;

  case 14: /* small_stmt: continue_stmt  */
#line 115 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1534 "parser.tab.c"
    break;

  case 15: /* small_stmt: return_stmt  */
#line 116 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1540 "parser.tab.c"
    break;

  case 16: /* expr_stmt: testlist annassign  */
#line 120 "parser.y"
                   {fprintf(yyout,"%d--%d;\n",(yyvsp[0].attributes).top,(yyvsp[-1].attributes).top); (yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1546 "parser.tab.c"
    break;

  case 17: /* expr_stmt: testlist AUGASSIGNMENT_OPERATOR testlist  */
#line 121 "parser.y"
                                          {fprintf(yyout,"%d--%d; %d--%d; %d[label=\"Operator (%s)\"];\n",node,(yyvsp[-2].attributes).top,node,(yyvsp[0].attributes).top,node,integerToOperator((yyvsp[-1].attributes).top)); node++; (yyvsp[-2].attributes).top=node-1;  fprintf(yyout,"%d--%d; %d[label=\" Expr\"];\n",node,node-1,node); node++; (yyval.attributes).top=node-1; }
#line 1552 "parser.tab.c"
    break;

  case 18: /* expr_stmt: testlist Assign_stmt  */
#line 122 "parser.y"
                        { fprintf(yyout,"%d--%d;\n",(yyvsp[0].attributes).low,(yyvsp[-1].attributes).top); fprintf(yyout,"%d--%d; %d[label=\" Expr\"];\n",node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1558 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: Assign_stmt ASSIGNMENT_OPERATOR testlist  */
#line 125 "parser.y"
                                          {fprintf(yyout,"%d--%d; %d--%d;%d[label=\"Operator (=)\"];\n",node,(yyvsp[0].attributes).top,node,(yyvsp[-2].attributes).top,node); node++; (yyval.attributes).top=node-1; (yyval.attributes).low=(yyvsp[-2].attributes).low;}
#line 1564 "parser.tab.c"
    break;

  case 20: /* Assign_stmt: ASSIGNMENT_OPERATOR testlist  */
#line 126 "parser.y"
                                 {fprintf(yyout,"%d--%d; %d[label=\"Operator (=)\"];\n",node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1; (yyval.attributes).low=node-1;}
#line 1570 "parser.tab.c"
    break;

  case 21: /* annassign: COLON test param_list  */
#line 129 "parser.y"
                                  {fprintf(yyout,"%d[label=\" COLON\"];\n",node); node++;  fprintf(yyout,"%d--%d; %d--%d;  %d--%d; %d[label=\" Annassign\"];\n",node,(yyvsp[-1].attributes).top,node,(yyvsp[0].attributes).top,node,node-1,node); node++; (yyval.attributes).top=node-1;  }
#line 1576 "parser.tab.c"
    break;

  case 22: /* annassign: COLON test  */
#line 130 "parser.y"
                         {fprintf(yyout,"%d[label=\" COLON\"];\n",node); node++; (yyval.attributes).top=node-1; fprintf(yyout,"%d--%d; %d--%d; %d[label=\" Annassign\"];\n",node,(yyvsp[0].attributes).top,node,node-1,node); node++; (yyval.attributes).top=node-1;}
#line 1582 "parser.tab.c"
    break;

  case 23: /* param_list: ASSIGNMENT_OPERATOR test  */
#line 134 "parser.y"
                          {fprintf(yyout,"%d[label=\" Operator (=)\"];\n",node); node++; fprintf(yyout,"%d--%d; %d--%d; %d[label=\" param_list \"];\n",node,node-1,node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1588 "parser.tab.c"
    break;

  case 24: /* break_stmt: BREAK  */
#line 137 "parser.y"
       {fprintf(yyout,"%d[label=\" KEYWORD(break) \"];\n",node); node++; (yyval.attributes).top=node-1;}
#line 1594 "parser.tab.c"
    break;

  case 25: /* continue_stmt: CONTINUE  */
#line 140 "parser.y"
            {fprintf(yyout,"%d[label=\" KEYWORD(continue) \"];\n",node); node++; (yyval.attributes).top=node-1;}
#line 1600 "parser.tab.c"
    break;

  case 26: /* return_stmt: RETURN  */
#line 143 "parser.y"
                   {fprintf(yyout,"%d[label=\" KEYWORD(return) \"];\n",node); node++; fprintf(yyout,"%d--%d;%d[label=\" return_stmt \"];\n",node,node-1,node); node++; (yyval.attributes).top=node-1;}
#line 1606 "parser.tab.c"
    break;

  case 27: /* return_stmt: RETURN test  */
#line 144 "parser.y"
                           {fprintf(yyout,"%d[label=\" KEYWORD(return) \"];\n",node); node++;  fprintf(yyout,"%d--%d;%d--%d;%d[label=\" return_stmt \"];\n",node,node-1,node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1612 "parser.tab.c"
    break;

  case 28: /* compound_stmt: if_stmt  */
#line 150 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1618 "parser.tab.c"
    break;

  case 29: /* compound_stmt: while_stmt  */
#line 151 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1624 "parser.tab.c"
    break;

  case 30: /* compound_stmt: for_stmt  */
#line 152 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1630 "parser.tab.c"
    break;

  case 31: /* compound_stmt: funcdef  */
#line 153 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1636 "parser.tab.c"
    break;

  case 32: /* compound_stmt: classdef  */
#line 154 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1642 "parser.tab.c"
    break;

  case 33: /* if_stmt: IF test COLON suite  */
#line 157 "parser.y"
                           { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1648 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF test COLON suite else_statement  */
#line 158 "parser.y"
                                       { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-3].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1654 "parser.tab.c"
    break;

  case 35: /* if_stmt: IF test COLON suite elif_statements  */
#line 159 "parser.y"
                                       { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-3].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1660 "parser.tab.c"
    break;

  case 36: /* if_stmt: IF test COLON suite elif_statements else_statement  */
#line 160 "parser.y"
                                                      { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"if_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-4].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1666 "parser.tab.c"
    break;

  case 37: /* elif_statements: elif_statements ELIF test COLON suite  */
#line 163 "parser.y"
                                       {fprintf(yyout,"%d--%d;\n",node,(yyvsp[-4].attributes).top); fprintf(yyout,"%d--%d;%d[label=\"Keyword(elif)\"];%d[label=\"elif_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1672 "parser.tab.c"
    break;

  case 38: /* elif_statements: ELIF test COLON suite  */
#line 164 "parser.y"
                                      {fprintf(yyout,"%d--%d;%d[label=\"Keyword(elif)\"];%d[label=\"elif_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1678 "parser.tab.c"
    break;

  case 39: /* else_statement: ELSE COLON suite  */
#line 167 "parser.y"
                        {fprintf(yyout,"%d--%d;%d[label=\"Keyword(else)\"];%d[label=\"else_statement\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1684 "parser.tab.c"
    break;

  case 40: /* while_stmt: WHILE test COLON suite  */
#line 171 "parser.y"
                                    {fprintf(yyout,"%d--%d;%d[label=\"Keyword(while)\"];%d[label=\"while_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1690 "parser.tab.c"
    break;

  case 41: /* while_stmt: WHILE test COLON suite else_statement  */
#line 172 "parser.y"
                                                    { fprintf(yyout,"%d--%d;%d[label=\"Keyword(while)\"];%d[label=\"while_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-3].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1696 "parser.tab.c"
    break;

  case 42: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 176 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"for_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-4].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+4;(yyval.attributes).top=node-4;}
#line 1702 "parser.tab.c"
    break;

  case 43: /* for_stmt: FOR exprlist IN testlist COLON suite else_statement  */
#line 177 "parser.y"
                                                                     {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"for_statement\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-5].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-3].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+4;(yyval.attributes).top=node-4;}
#line 1708 "parser.tab.c"
    break;

  case 44: /* funcdef: DEF NAME parameters COLON suite  */
#line 181 "parser.y"
                                     {fprintf(yyout,"%d--%d;%d[label=\"Keyword(def)\"];%d[label=\"funcdef\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"NAME\"];\n",node,node+2,node+2); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+4;(yyval.attributes).top=node-4;}
#line 1714 "parser.tab.c"
    break;

  case 45: /* funcdef: DEF NAME parameters RETURN_ARROW test COLON suite  */
#line 182 "parser.y"
                                                      {fprintf(yyout,"%d--%d;%d[label=\"DEF\"];%d[label=\"funcdef\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"NAME\"];\n",node,node+2,node+2); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-4].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"RETURN_ARROW\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+4,node+4);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+5;(yyval.attributes).top=node-5;}
#line 1720 "parser.tab.c"
    break;

  case 46: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 185 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(()\"];%d[label=\"parameters\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER())\"];\n",node,node+2,node+2);node=node+3;(yyval.attributes).top=node-3;}
#line 1726 "parser.tab.c"
    break;

  case 47: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 186 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(()\"];%d[label=\"parameters\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER())\"];\n",node,node+2,node+2);node=node+3;(yyval.attributes).top=node-3;}
#line 1732 "parser.tab.c"
    break;

  case 48: /* typedargslist: typedargslist COMMA full_tfpdef  */
#line 190 "parser.y"
                                { fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];%d[label=\"typedargslist\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 1738 "parser.tab.c"
    break;

  case 49: /* typedargslist: full_tfpdef  */
#line 191 "parser.y"
              {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1744 "parser.tab.c"
    break;

  case 50: /* full_tfpdef: name annassign  */
#line 195 "parser.y"
                           {fprintf(yyout,"%d--%d;\n",(yyvsp[0].attributes).top,(yyvsp[-1].attributes).top); (yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1750 "parser.tab.c"
    break;

  case 51: /* full_tfpdef: NAME  */
#line 196 "parser.y"
                    {fprintf(yyout,"%d[label=\"NAME( %s )\"];\n",node,yytext);node++;}
#line 1756 "parser.tab.c"
    break;

  case 52: /* name: NAME  */
#line 198 "parser.y"
           {fprintf(yyout,"%d[label=\"NAME( %s )\"];\n",node,yytext);node++;}
#line 1762 "parser.tab.c"
    break;

  case 53: /* classdef: CLASS NAME opt_class_arg COLON suite  */
#line 202 "parser.y"
                                        {fprintf(yyout,"%d--%d;%d[label=\"Keyword(class)\"];%d[label=\"class_def\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"NAME\"];\n",node,node+2,node+2); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+4;(yyval.attributes).top=node-4;}
#line 1768 "parser.tab.c"
    break;

  case 54: /* classdef: CLASS NAME COLON suite  */
#line 203 "parser.y"
                             {fprintf(yyout,"%d--%d;%d[label=\"Keyword(class)\"];%d[label=\"class_def\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"NAME\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;%d[label=\"COLON\"];\n",node,node+3,node+3);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+4;(yyval.attributes).top=node-4;}
#line 1774 "parser.tab.c"
    break;

  case 55: /* opt_class_arg: LEFT_BRACKET RIGHT_BRACKET  */
#line 207 "parser.y"
                              {fprintf(yyout,"%d--%d;%d[label=\"DELIMITER({)\"];%d[label=\"opt_class_arg\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(})\"];\n",node,node+2,node+2);node=node+3;(yyval.attributes).top=node-3;}
#line 1780 "parser.tab.c"
    break;

  case 56: /* opt_class_arg: LEFT_BRACKET opt_arglist RIGHT_BRACKET  */
#line 208 "parser.y"
                                            {fprintf(yyout,"%d--%d;%d[label=\"DELIMITER({)\"];%d[label=\"opt_class_arg\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(})\"];\n",node,node+2,node+2);node=node+3;(yyval.attributes).top=node-3;}
#line 1786 "parser.tab.c"
    break;

  case 57: /* opt_arglist: arglist COMMA  */
#line 212 "parser.y"
                              {fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(,)\"];%d[label=\"opt_arglist\"];\n",node,node+1,node+1,node);node=node+2;(yyval.attributes).top=node-2;}
#line 1792 "parser.tab.c"
    break;

  case 58: /* opt_arglist: arglist  */
#line 213 "parser.y"
                              {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1798 "parser.tab.c"
    break;

  case 59: /* arglist: arglist COMMA argument  */
#line 218 "parser.y"
                                    {fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"DELIMITER(,)\"];%d[label=\"arglist\"];\n",node,node+1,node+1,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 1804 "parser.tab.c"
    break;

  case 60: /* arglist: argument  */
#line 219 "parser.y"
                                     {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1810 "parser.tab.c"
    break;

  case 61: /* argument: test  */
#line 223 "parser.y"
              {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1816 "parser.tab.c"
    break;

  case 62: /* argument: test comp_for  */
#line 224 "parser.y"
                       {fprintf(yyout,"%d--%d;%d[label=\"argument\"];\n",node,(yyvsp[-1].attributes).top,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+1;(yyval.attributes).top=node-1;}
#line 1822 "parser.tab.c"
    break;

  case 63: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 225 "parser.y"
                                  {fprintf(yyout,"%d--%d;%d[label=\"Operator(=)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1828 "parser.tab.c"
    break;

  case 64: /* comp_iter: comp_for  */
#line 229 "parser.y"
             {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1834 "parser.tab.c"
    break;

  case 65: /* comp_iter: comp_if  */
#line 230 "parser.y"
             {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1840 "parser.tab.c"
    break;

  case 66: /* comp_for: FOR exprlist IN or_test  */
#line 234 "parser.y"
                             {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"comp_for\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1846 "parser.tab.c"
    break;

  case 67: /* comp_for: FOR exprlist IN or_test comp_iter  */
#line 235 "parser.y"
                                      {fprintf(yyout,"%d--%d;%d[label=\"Keyword(for)\"];%d[label=\"comp_for\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-3].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Keyword(in)\"];\n",node,node+2,node+2);fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+3;(yyval.attributes).top=node-3;}
#line 1852 "parser.tab.c"
    break;

  case 68: /* comp_if: IF or_test  */
#line 239 "parser.y"
                     { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"comp_if\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 1858 "parser.tab.c"
    break;

  case 69: /* comp_if: IF or_test comp_iter  */
#line 240 "parser.y"
                          { fprintf(yyout,"%d--%d;%d[label=\"Keyword(if)\"];%d[label=\"comp_if\"];\n",node,node+1,node+1,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[-1].attributes).top); fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 1864 "parser.tab.c"
    break;

  case 70: /* suite: simple_stmt  */
#line 244 "parser.y"
            {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1870 "parser.tab.c"
    break;

  case 71: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 245 "parser.y"
                                  {(yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 1876 "parser.tab.c"
    break;

  case 72: /* suite: NEWLINE INDENT stmt_list $end  */
#line 246 "parser.y"
                                 {(yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 1882 "parser.tab.c"
    break;

  case 73: /* stmt_list: stmt_list stmt  */
#line 249 "parser.y"
                {if((yyvsp[0].attributes).top!=-1) fprintf(yyout,"%d--%d;\n",(yyvsp[-1].attributes).top,(yyvsp[0].attributes).top); (yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 1888 "parser.tab.c"
    break;

  case 74: /* stmt_list: stmt  */
#line 250 "parser.y"
       {fprintf(yyout,"%d--%d; %d[label=\" Suite\"];\n",node,(yyvsp[0].attributes).top,node); node++; (yyval.attributes).top=node-1;}
#line 1894 "parser.tab.c"
    break;

  case 75: /* test: or_test IF or_test ELSE test  */
#line 253 "parser.y"
                                                   {fprintf(yyout,"%d--%d;\n",node+2,(yyvsp[-4].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"test\"];%d[label=\"Keyword(if)\"];\n",node+2,node,node+2,node);fprintf(yyout,"%d--%d;\n",node+2,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"test\"];%d[label=\"Keyword(else)\"];\n",node+2,node+1,node+2,node+1);fprintf(yyout,"%d--%d;\n",node+2,(yyvsp[0].attributes).top);node+=3; (yyval.attributes).top=node-1;}
#line 1900 "parser.tab.c"
    break;

  case 76: /* test: or_test  */
#line 254 "parser.y"
                       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1906 "parser.tab.c"
    break;

  case 77: /* or_test: or_test OR and_test  */
#line 257 "parser.y"
                                          {fprintf(yyout,"%d--%d;%d[label=\"Keyword(or)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1912 "parser.tab.c"
    break;

  case 78: /* or_test: and_test  */
#line 258 "parser.y"
                          {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1918 "parser.tab.c"
    break;

  case 79: /* and_test: and_test AND not_test  */
#line 261 "parser.y"
                                          {fprintf(yyout,"%d--%d;%d[label=\"Keyword(and)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1924 "parser.tab.c"
    break;

  case 80: /* and_test: not_test  */
#line 262 "parser.y"
                       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1930 "parser.tab.c"
    break;

  case 81: /* not_test: NOT not_test  */
#line 265 "parser.y"
                              {fprintf(yyout,"%d--%d;%d[label=\"Keyword(not)\"];\n",node,(yyvsp[0].attributes).top,node);node+=1; (yyval.attributes).top=node-1;}
#line 1936 "parser.tab.c"
    break;

  case 82: /* not_test: comparison  */
#line 266 "parser.y"
               {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1942 "parser.tab.c"
    break;

  case 83: /* comparison: comparison r_o expr  */
#line 268 "parser.y"
                                               {fprintf(yyout,"%d--%d;\n",(yyvsp[-1].attributes).top,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;\n",(yyvsp[-1].attributes).top,(yyvsp[0].attributes).top); (yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 1948 "parser.tab.c"
    break;

  case 84: /* comparison: expr  */
#line 269 "parser.y"
                    {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1954 "parser.tab.c"
    break;

  case 85: /* r_o: RELATIONAL_OPERATOR  */
#line 271 "parser.y"
                           {fprintf(yyout,"%d[label=\"Operator( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 1960 "parser.tab.c"
    break;

  case 86: /* expr: expr BIT_OR and_expr  */
#line 273 "parser.y"
                                          {fprintf(yyout,"%d--%d;%d[label=\"Operator(|)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1966 "parser.tab.c"
    break;

  case 87: /* expr: xor_expr  */
#line 274 "parser.y"
                           {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1972 "parser.tab.c"
    break;

  case 88: /* xor_expr: xor_expr XOR and_expr  */
#line 276 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"Operator(^)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1978 "parser.tab.c"
    break;

  case 89: /* xor_expr: and_expr  */
#line 277 "parser.y"
                            {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1984 "parser.tab.c"
    break;

  case 90: /* and_expr: and_expr BIT_AND shift_expr  */
#line 279 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Operator(&)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 1990 "parser.tab.c"
    break;

  case 91: /* and_expr: shift_expr  */
#line 280 "parser.y"
                          {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 1996 "parser.tab.c"
    break;

  case 92: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 282 "parser.y"
                                                        {fprintf(yyout,"%d--%d;%d[label=\"Operator(<<)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2002 "parser.tab.c"
    break;

  case 93: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 283 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"Operator(>>)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2008 "parser.tab.c"
    break;

  case 94: /* shift_expr: arith_expr  */
#line 284 "parser.y"
                         {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2014 "parser.tab.c"
    break;

  case 95: /* arith_expr: arith_expr ADD term  */
#line 287 "parser.y"
                                      {fprintf(yyout,"%d--%d;%d[label=\"Operator(+)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2020 "parser.tab.c"
    break;

  case 96: /* arith_expr: arith_expr SUB term  */
#line 288 "parser.y"
                                       {fprintf(yyout,"%d--%d;%d[label=\"Operator(-)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2026 "parser.tab.c"
    break;

  case 97: /* arith_expr: term  */
#line 289 "parser.y"
                 {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2032 "parser.tab.c"
    break;

  case 98: /* term: term a_o factor  */
#line 291 "parser.y"
                                      {fprintf(yyout,"%d--%d;\n",(yyvsp[-1].attributes).top,(yyvsp[-2].attributes).top);fprintf(yyout,"%d--%d;\n",(yyvsp[-1].attributes).top,(yyvsp[0].attributes).top); (yyval.attributes).top=(yyvsp[-1].attributes).top;}
#line 2038 "parser.tab.c"
    break;

  case 99: /* term: factor  */
#line 292 "parser.y"
                   {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2044 "parser.tab.c"
    break;

  case 100: /* a_o: ARITHMETIC_OPERATOR  */
#line 293 "parser.y"
                           {fprintf(yyout,"%d[label=\"Operator( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2050 "parser.tab.c"
    break;

  case 101: /* factor: ADD factor  */
#line 296 "parser.y"
            {fprintf(yyout,"%d--%d;%d[label=\"Operator(+)\"];\n",node,(yyvsp[0].attributes).top,node);node+=1; (yyval.attributes).top=node-1;}
#line 2056 "parser.tab.c"
    break;

  case 102: /* factor: SUB factor  */
#line 297 "parser.y"
            {fprintf(yyout,"%d--%d;%d[label=\"Operator(-)\"];\n",node,(yyvsp[0].attributes).top,node);node+=1; (yyval.attributes).top=node-1;}
#line 2062 "parser.tab.c"
    break;

  case 103: /* factor: BIT_NOT factor  */
#line 298 "parser.y"
               {fprintf(yyout,"%d--%d;%d[label=\"Operator(~)\"];\n",node,(yyvsp[0].attributes).top,node);node+=1; (yyval.attributes).top=node-1;}
#line 2068 "parser.tab.c"
    break;

  case 104: /* factor: power  */
#line 299 "parser.y"
       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2074 "parser.tab.c"
    break;

  case 105: /* power: atom_expr POWER factor  */
#line 302 "parser.y"
                                   {fprintf(yyout,"%d--%d;%d[label=\"Operator(**)\"];\n",node,(yyvsp[-2].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2080 "parser.tab.c"
    break;

  case 106: /* power: atom_expr  */
#line 303 "parser.y"
                      {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2086 "parser.tab.c"
    break;

  case 107: /* atom_expr: atom opt_trailer  */
#line 306 "parser.y"
                            {fprintf(yyout,"%d--%d;%d[label=\"atom_expr\"];\n",node,(yyvsp[-1].attributes).top,node);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node+=1; (yyval.attributes).top=node-1;}
#line 2092 "parser.tab.c"
    break;

  case 108: /* atom_expr: atom  */
#line 307 "parser.y"
                {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2098 "parser.tab.c"
    break;

  case 109: /* opt_trailer: opt_trailer trailer  */
#line 310 "parser.y"
                    {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2104 "parser.tab.c"
    break;

  case 110: /* opt_trailer: trailer  */
#line 311 "parser.y"
            {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2110 "parser.tab.c"
    break;

  case 111: /* atom: LEFT_BRACKET testlist_comp RIGHT_BRACKET  */
#line 314 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2116 "parser.tab.c"
    break;

  case 112: /* atom: LEFT_BRACKET RIGHT_BRACKET  */
#line 315 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2122 "parser.tab.c"
    break;

  case 113: /* atom: LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET  */
#line 316 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2128 "parser.tab.c"
    break;

  case 114: /* atom: LEFT_SQUARE_BRACKET testlist_comp RIGHT_SQUARE_BRACKET  */
#line 317 "parser.y"
                                                            {fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"atom\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2134 "parser.tab.c"
    break;

  case 115: /* atom: NAME  */
#line 318 "parser.y"
            {fprintf(yyout,"%d[label=\"Name( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2140 "parser.tab.c"
    break;

  case 116: /* atom: NUMBER  */
#line 319 "parser.y"
            {fprintf(yyout,"%d[label=\"Number( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2146 "parser.tab.c"
    break;

  case 117: /* atom: DATA_TYPE  */
#line 320 "parser.y"
            {fprintf(yyout,"%d[label=\"Data Type( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2152 "parser.tab.c"
    break;

  case 118: /* atom: STRING  */
#line 321 "parser.y"
        {fprintf(yyout,"%d[label=\"String( %s )\"];\n",node,addBackslashBeforeQuotes(yytext));node++; (yyval.attributes).top=node-1;}
#line 2158 "parser.tab.c"
    break;

  case 119: /* atom: STRING_1  */
#line 322 "parser.y"
          {fprintf(yyout,"%d[label=\"String( %s )\"];\n",node,yytext);node++; (yyval.attributes).top=node-1;}
#line 2164 "parser.tab.c"
    break;

  case 120: /* atom: NONE  */
#line 323 "parser.y"
      {fprintf(yyout,"%d[label=\"Keyword(None)\"];\n",node);node++; (yyval.attributes).top=node-1;}
#line 2170 "parser.tab.c"
    break;

  case 121: /* atom: TRUE  */
#line 324 "parser.y"
      {fprintf(yyout,"%d[label=\"Keyword(True)\"];\n",node);node++; (yyval.attributes).top=node-1;}
#line 2176 "parser.tab.c"
    break;

  case 122: /* atom: FALSE  */
#line 325 "parser.y"
       {fprintf(yyout,"%d[label=\"Keyword(False)\"];\n",node);node++; (yyval.attributes).top=node-1;}
#line 2182 "parser.tab.c"
    break;

  case 123: /* atom: LIST  */
#line 326 "parser.y"
      {fprintf(yyout,"%d[label=\"List \"];\n",node);node++; (yyval.attributes).top=node-1;}
#line 2188 "parser.tab.c"
    break;

  case 124: /* testlist_comp: test comp_for  */
#line 330 "parser.y"
              {fprintf(yyout,"%d--%d;%d[label=\"testlist_comp\"];\n",node,(yyvsp[-1].attributes).top,node); fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+1;(yyval.attributes).top=node-1;}
#line 2194 "parser.tab.c"
    break;

  case 125: /* testlist_comp: opt_test_stmt COMMA  */
#line 331 "parser.y"
                       {fprintf(yyout,"%d--%d;%d[label=\"testlist_comp\"];\n",node,(yyvsp[-1].attributes).top,node); fprintf(yyout,"%d--%d;%d[label=\"Delimiter(,)\"];\n",node,node+1,node+1);node=node+2;(yyval.attributes).top=node-2;}
#line 2200 "parser.tab.c"
    break;

  case 126: /* testlist_comp: opt_test_stmt  */
#line 332 "parser.y"
                {(yyval.attributes).top = (yyvsp[0].attributes).top;}
#line 2206 "parser.tab.c"
    break;

  case 127: /* opt_test_stmt: test  */
#line 335 "parser.y"
                    {(yyval.attributes).top = (yyvsp[0].attributes).top;}
#line 2212 "parser.tab.c"
    break;

  case 128: /* opt_test_stmt: opt_test_stmt COMMA test  */
#line 336 "parser.y"
                           {fprintf(yyout,"%d--%d;%d[label=\"opt_test_stmt\"];\n",node,(yyvsp[-2].attributes).top,node); fprintf(yyout,"%d--%d;%d[label=\"Delimiter(,)\"];\n",node,node+1,node+1);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 2218 "parser.tab.c"
    break;

  case 129: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 341 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2224 "parser.tab.c"
    break;

  case 130: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 342 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"Delimiter(()\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;%d[label=\"Delimiter())\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2230 "parser.tab.c"
    break;

  case 131: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 343 "parser.y"
                                                   {fprintf(yyout,"%d--%d;%d[label=\"Delimiter([)\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,(yyvsp[-1].attributes).top);fprintf(yyout,"%d--%d;%d[label=\"Delimiter(])\"];\n",node+1,node+2,node+2);node+=3; (yyval.attributes).top=node-2;}
#line 2236 "parser.tab.c"
    break;

  case 132: /* trailer: DOT name  */
#line 344 "parser.y"
                                             {fprintf(yyout,"%d--%d;%d[label=\"Delimiter(.)\"];%d[label=\"trailer\"];\n",node+1,node,node,node+1);fprintf(yyout,"%d--%d;\n",node+1,(yyvsp[0].attributes).top);node+=2; (yyval.attributes).top=node-1;}
#line 2242 "parser.tab.c"
    break;

  case 133: /* testlist: testlist COMMA test  */
#line 348 "parser.y"
                    {fprintf(yyout,"%d--%d;%d[label=\"testlist\"];\n",node,(yyvsp[-2].attributes).top,node); fprintf(yyout,"%d--%d;%d[label=\"Delimiter(,)\"];\n",node,node+1,node+1);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 2248 "parser.tab.c"
    break;

  case 134: /* testlist: test  */
#line 349 "parser.y"
       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2254 "parser.tab.c"
    break;

  case 135: /* exprlist: exprlist COMMA expr  */
#line 353 "parser.y"
                    {fprintf(yyout,"%d--%d;%d[label=\"exprlist\"];\n",node,(yyvsp[-2].attributes).top,node); fprintf(yyout,"%d--%d;%d[label=\"Delimiter(,)\"];\n",node,node+1,node+1);fprintf(yyout,"%d--%d;\n",node,(yyvsp[0].attributes).top);node=node+2;(yyval.attributes).top=node-2;}
#line 2260 "parser.tab.c"
    break;

  case 136: /* exprlist: expr  */
#line 354 "parser.y"
       {(yyval.attributes).top=(yyvsp[0].attributes).top;}
#line 2266 "parser.tab.c"
    break;


#line 2270 "parser.tab.c"

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

#line 357 "parser.y"

const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   cout<<"Error in Line no "<<yylineno<<endl;
   cout<< "The Last Lexeme is "<<yytext<<endl;
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
