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
extern char * lexeme;
extern FILE* yyin;  
extern FILE* yyout;
extern int yychar;

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

vector<string>code;

map<string,int>table;
extern stack<string>current_attributes;

void pop_functional_attributes(){
    while(current_attributes.top()!="INDENT"){
        cout<<"pop "<<current_attributes.top()<<endl;
        table.erase(current_attributes.top());
        current_attributes.pop();
    }
    cout<<"pop "<<current_attributes.top()<<endl;
    current_attributes.pop();
}

string convert( string in){
    string out = in;
    return out;
}


#line 141 "parser.tab.c"

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
  YYSYMBOL_INVALID = 54,                   /* INVALID  */
  YYSYMBOL_low = 55,                       /* low  */
  YYSYMBOL_low1 = 56,                      /* low1  */
  YYSYMBOL_low2 = 57,                      /* low2  */
  YYSYMBOL_low3 = 58,                      /* low3  */
  YYSYMBOL_low4 = 59,                      /* low4  */
  YYSYMBOL_low5 = 60,                      /* low5  */
  YYSYMBOL_low6 = 61,                      /* low6  */
  YYSYMBOL_high = 62,                      /* high  */
  YYSYMBOL_high1 = 63,                     /* high1  */
  YYSYMBOL_SHIFT = 64,                     /* SHIFT  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_module = 66,                    /* module  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_simple_stmt = 68,               /* simple_stmt  */
  YYSYMBOL_more_expr = 69,                 /* more_expr  */
  YYSYMBOL_small_stmt = 70,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 71,                 /* expr_stmt  */
  YYSYMBOL_name = 72,                      /* name  */
  YYSYMBOL_Assign_stmt = 73,               /* Assign_stmt  */
  YYSYMBOL_annassign = 74,                 /* annassign  */
  YYSYMBOL_param_list = 75,                /* param_list  */
  YYSYMBOL_break_stmt = 76,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 77,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 78,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 79,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 80,                   /* if_stmt  */
  YYSYMBOL_elif_statements = 81,           /* elif_statements  */
  YYSYMBOL_else_statement = 82,            /* else_statement  */
  YYSYMBOL_while_stmt = 83,                /* while_stmt  */
  YYSYMBOL_for_stmt = 84,                  /* for_stmt  */
  YYSYMBOL_funcdef = 85,                   /* funcdef  */
  YYSYMBOL_parameters = 86,                /* parameters  */
  YYSYMBOL_typedargslist = 87,             /* typedargslist  */
  YYSYMBOL_full_tfpdef = 88,               /* full_tfpdef  */
  YYSYMBOL_classdef = 89,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 90,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 91,               /* opt_arglist  */
  YYSYMBOL_arglist = 92,                   /* arglist  */
  YYSYMBOL_argument = 93,                  /* argument  */
  YYSYMBOL_comp_iter = 94,                 /* comp_iter  */
  YYSYMBOL_comp_for = 95,                  /* comp_for  */
  YYSYMBOL_comp_if = 96,                   /* comp_if  */
  YYSYMBOL_suite = 97,                     /* suite  */
  YYSYMBOL_stmt_list = 98,                 /* stmt_list  */
  YYSYMBOL_test = 99,                      /* test  */
  YYSYMBOL_or_test = 100,                  /* or_test  */
  YYSYMBOL_and_test = 101,                 /* and_test  */
  YYSYMBOL_not_test = 102,                 /* not_test  */
  YYSYMBOL_comparison = 103,               /* comparison  */
  YYSYMBOL_r_o = 104,                      /* r_o  */
  YYSYMBOL_expr = 105,                     /* expr  */
  YYSYMBOL_xor_expr = 106,                 /* xor_expr  */
  YYSYMBOL_and_expr = 107,                 /* and_expr  */
  YYSYMBOL_shift_expr = 108,               /* shift_expr  */
  YYSYMBOL_arith_expr = 109,               /* arith_expr  */
  YYSYMBOL_term = 110,                     /* term  */
  YYSYMBOL_a_o = 111,                      /* a_o  */
  YYSYMBOL_factor = 112,                   /* factor  */
  YYSYMBOL_power = 113,                    /* power  */
  YYSYMBOL_atom_expr = 114,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 115,              /* opt_trailer  */
  YYSYMBOL_atom = 116,                     /* atom  */
  YYSYMBOL_testlist_comp = 117,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 118,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 119,                  /* trailer  */
  YYSYMBOL_testlist = 120,                 /* testlist  */
  YYSYMBOL_exprlist = 121                  /* exprlist  */
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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   511

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   104,   108,   109,   110,   111,   114,   115,
     118,   119,   124,   125,   126,   127,   131,   137,   138,   140,
     143,   144,   147,   148,   152,   155,   158,   161,   162,   168,
     169,   170,   171,   172,   175,   176,   177,   178,   181,   182,
     185,   189,   190,   194,   195,   199,   200,   203,   204,   208,
     209,   213,   214,   220,   221,   225,   226,   230,   231,   235,
     236,   240,   241,   242,   247,   248,   252,   253,   257,   258,
     262,   263,   266,   269,   270,   273,   276,   277,   280,   281,
     284,   285,   287,   288,   290,   292,   293,   295,   296,   298,
     299,   301,   302,   303,   306,   307,   308,   310,   311,   313,
     316,   317,   318,   319,   322,   323,   326,   327,   330,   331,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   351,   352,   353,   356,   357,   362,   363,
     364,   365,   369,   370,   374,   375
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
  "RIGHT_CURLY_BRACKET", "INVALID", "low", "low1", "low2", "low3", "low4",
  "low5", "low6", "high", "high1", "SHIFT", "$accept", "module", "stmt",
  "simple_stmt", "more_expr", "small_stmt", "expr_stmt", "name",
  "Assign_stmt", "annassign", "param_list", "break_stmt", "continue_stmt",
  "return_stmt", "compound_stmt", "if_stmt", "elif_statements",
  "else_statement", "while_stmt", "for_stmt", "funcdef", "parameters",
  "typedargslist", "full_tfpdef", "classdef", "opt_class_arg",
  "opt_arglist", "arglist", "argument", "comp_iter", "comp_for", "comp_if",
  "suite", "stmt_list", "test", "or_test", "and_test", "not_test",
  "comparison", "r_o", "expr", "xor_expr", "and_expr", "shift_expr",
  "arith_expr", "term", "a_o", "factor", "power", "atom_expr",
  "opt_trailer", "atom", "testlist_comp", "opt_test_stmt", "trailer",
  "testlist", "exprlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     190,  -163,   460,   404,   404,  -163,    19,  -163,  -163,   292,
      23,   320,  -163,  -163,  -163,    19,   404,   404,  -163,   460,
     460,   460,  -163,  -163,  -163,   117,  -163,  -163,    50,  -163,
    -163,    35,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,    43,    39,  -163,    81,    47,    66,    84,
     -24,    60,   133,  -163,  -163,    97,    -2,    12,  -163,    47,
      38,   124,   128,  -163,    94,  -163,   145,   134,   131,  -163,
     130,   140,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   264,
     432,   404,  -163,   404,   404,  -163,   460,   460,   460,   460,
     460,   460,   460,   460,  -163,   460,   460,   348,   404,    19,
      -2,  -163,   404,   404,   460,   404,   227,   227,   227,   376,
     148,   460,  -163,  -163,   404,  -163,    59,    71,  -163,    12,
     163,  -163,   147,   165,    39,  -163,    47,    66,    84,   -24,
      60,    60,   133,   133,  -163,  -163,  -163,    75,  -163,    91,
     152,  -163,  -163,   147,  -163,    47,    40,   139,  -163,   167,
     107,  -163,  -163,   160,   159,   227,    49,  -163,  -163,   164,
     166,    89,  -163,   227,   404,   404,  -163,  -163,   404,   404,
    -163,  -163,   227,   190,   168,  -163,   404,   111,  -163,  -163,
     404,  -163,   404,   404,  -163,   162,  -163,   169,  -163,  -163,
    -163,   167,  -163,    24,   227,   171,   404,  -163,     7,  -163,
    -163,   227,  -163,  -163,  -163,  -163,  -163,   227,   172,   404,
    -163,  -163,  -163,  -163,  -163,   227,     7,  -163,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   116,     0,     0,     0,    25,     0,    26,   122,     0,
     114,     0,   119,   120,   121,     0,     0,    27,     4,     0,
       0,     0,   115,   117,   118,     0,     3,     5,     8,    11,
      12,     0,    18,    13,    14,    15,     6,    29,    30,    31,
      32,    33,   133,    75,    77,    79,    81,    83,    86,    88,
      90,    93,    96,    98,   103,   105,   107,     7,   114,   135,
       0,     0,     0,    19,     0,   111,   126,     0,   125,   112,
       0,     0,    80,    28,   102,   100,   101,     1,     2,     9,
       0,     0,    16,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
     106,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   110,   124,   113,     0,     0,    10,     0,
       0,    20,    21,    23,    76,    78,    82,    85,    87,    89,
      91,    92,    94,    95,    97,   104,   129,     0,    60,    61,
       0,   131,   108,    17,   132,   134,     0,     0,    70,    41,
      34,    54,    55,     0,    58,     0,     0,   127,    47,    52,
       0,     0,    50,     0,     0,     0,    22,   128,     0,     0,
      62,   130,     0,     0,     0,    42,     0,    36,    35,    56,
      57,    53,     0,     0,    48,     0,    45,     0,    24,    59,
      63,    43,    74,     0,     0,     0,     0,    37,    66,    51,
      49,     0,    44,    72,    71,    73,    40,     0,     0,     0,
      67,    64,    65,    46,    39,     0,    68,    38,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   -21,     3,  -163,   105,  -163,     4,   112,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -141,  -163,  -163,
    -163,  -163,  -163,     9,  -163,  -163,  -163,    92,  -106,   -14,
     -50,  -163,   -86,  -163,    -3,  -162,   125,   -11,  -163,  -163,
       5,   120,   121,   122,    44,    46,  -163,    -8,  -163,  -163,
    -163,  -163,   201,  -163,   113,     2,   109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,   148,    28,    29,    30,    31,    32,    82,
     166,    33,    34,    35,    36,    37,   177,   175,    38,    39,
      40,   117,   161,   162,    41,   110,   153,   137,   138,   210,
     211,   212,   149,   193,    42,    43,    44,    45,    46,    86,
      47,    48,    49,    50,    51,    52,    95,    53,    54,    55,
     100,    56,    67,    68,   101,   119,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    62,    57,    27,    78,    72,    66,    59,    66,   178,
      64,    74,    75,    76,    73,   111,   112,   209,    97,    71,
     198,   150,   151,    98,   203,    90,    91,    57,    27,   -19,
     102,     1,     2,     3,     4,   103,   197,     5,     6,     7,
       8,    80,   -19,    63,     9,    83,    99,   216,    10,    11,
     202,    12,    13,    14,    81,    15,    16,    17,    18,   172,
     204,   104,   189,   103,    19,    20,    21,    79,   105,   181,
      22,    23,   104,   125,   189,    24,    84,   186,   123,   182,
     158,    83,   122,   159,   120,    85,   191,   134,   135,   170,
     163,   126,    87,   164,   139,   140,   167,   169,   168,   111,
     144,    92,    93,   141,   143,    88,   139,   146,   206,   145,
     184,   157,   185,   108,   109,   213,    59,    77,   176,   174,
     160,   214,   196,   174,     1,     2,     3,     4,    89,   217,
       5,     6,     7,     8,   130,   131,    94,     9,   132,   133,
      96,    10,    11,   106,    12,    13,    14,   107,    15,    16,
      17,    18,   192,   111,   114,   113,   115,    19,    20,    21,
     116,   187,   188,    22,    23,   139,   190,   155,    24,    80,
     103,   165,   205,   195,   173,    57,    27,   139,   171,   174,
     199,   179,   180,   -19,   118,   183,   159,   194,   201,   160,
     207,   215,   121,   208,   200,    57,    27,     1,     2,     3,
       4,   154,   218,     5,     6,     7,     8,   127,   124,   128,
       9,   129,    70,   142,    10,    11,     0,    12,    13,    14,
     156,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     1,     0,    22,    23,     0,     0,
       5,    24,     7,     8,     0,     0,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     0,     0,    16,
      17,   147,     0,     0,     0,     0,     0,    19,    20,    21,
       0,     1,     0,    22,    23,     0,     0,     5,    24,     7,
       8,     0,     0,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,     0,     0,    16,    17,     0,     1,
       0,     0,     0,     0,    19,    20,    21,     0,     8,     0,
      22,    23,     9,    65,     0,    24,    58,    11,     0,    12,
      13,    14,     0,     0,    16,     0,     0,     1,     0,     0,
       0,     0,    19,    20,    21,     0,     8,     0,    22,    23,
       9,     0,     0,    24,    58,    11,    69,    12,    13,    14,
       0,     0,    16,     0,     0,     1,     0,     0,     0,     0,
      19,    20,    21,     0,     8,     0,    22,    23,     9,   136,
       0,    24,    58,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     1,     0,     0,     0,     0,    19,    20,
      21,     0,     8,     0,    22,    23,     9,   152,     0,    24,
      58,    11,     0,    12,    13,    14,     0,     0,    16,     0,
       0,     1,     0,     0,     0,     0,    19,    20,    21,     0,
       8,     0,    22,    23,     9,     0,     0,    24,    58,    11,
       0,    12,    13,    14,     0,     0,    16,     0,     0,     1,
       0,     0,     0,     0,    19,    20,    21,     0,     8,     0,
      22,    23,     9,     0,     0,    24,    10,    11,     0,    12,
      13,    14,     0,     0,    16,     0,     0,     1,     0,     0,
       0,     0,    19,    20,    21,     0,     8,     0,    22,    23,
       9,     0,     0,    24,    58,    11,     0,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     0,     0,    22,    23,     0,     0,
       0,    24
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,     0,    25,    16,     9,     2,    11,   150,
       6,    19,    20,    21,    17,     8,    66,    10,    20,    15,
     182,   107,   108,    25,     0,    49,    50,    25,    25,     6,
      18,     7,     8,     9,    10,    23,   177,    13,    14,    15,
      16,     6,    19,    24,    20,    38,    48,   209,    24,    25,
     191,    27,    28,    29,    19,    31,    32,    33,    34,    19,
      36,    23,   168,    23,    40,    41,    42,    17,    30,   155,
      46,    47,    23,    84,   180,    51,    37,   163,    81,    30,
      21,    38,    80,    24,    80,     4,   172,    95,    96,   139,
      19,    86,    45,    22,    97,    98,    21,     6,    23,     8,
     103,    41,    42,    99,   102,    39,   109,   105,   194,   104,
      21,   114,    23,    19,    20,   201,   111,     0,    11,    12,
     116,   207,    11,    12,     7,     8,     9,    10,    44,   215,
      13,    14,    15,    16,    90,    91,     3,    20,    92,    93,
      43,    24,    25,    19,    27,    28,    29,    19,    31,    32,
      33,    34,   173,     8,    23,    21,    26,    40,    41,    42,
      20,   164,   165,    46,    47,   168,   169,    19,    51,     6,
      23,     6,   193,   176,    35,   173,   173,   180,    26,    12,
     183,    21,    23,    19,    79,    19,    24,    19,    19,   185,
      19,    19,    80,   196,   185,   193,   193,     7,     8,     9,
      10,   109,   216,    13,    14,    15,    16,    87,    83,    88,
      20,    89,    11,   100,    24,    25,    -1,    27,    28,    29,
     111,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,     7,    -1,    46,    47,    -1,    -1,
      13,    51,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,     7,    -1,    46,    47,    -1,    -1,    13,    51,    15,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    -1,     7,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    16,    -1,
      46,    47,    20,    21,    -1,    51,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,    47,
      20,    -1,    -1,    51,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    16,    -1,    46,    47,    20,    21,
      -1,    51,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    16,    -1,    46,    47,    20,    21,    -1,    51,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      16,    -1,    46,    47,    20,    -1,    -1,    51,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    16,    -1,
      46,    47,    20,    -1,    -1,    51,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,    47,
      20,    -1,    -1,    51,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    51,    66,    67,    68,    69,    70,
      71,    72,    73,    76,    77,    78,    79,    80,    83,    84,
      85,    89,    99,   100,   101,   102,   103,   105,   106,   107,
     108,   109,   110,   112,   113,   114,   116,   120,    24,   105,
     121,    99,    99,    24,    72,    21,    99,   117,   118,    26,
     117,    72,   102,    99,   112,   112,   112,     0,    67,    17,
       6,    19,    74,    38,    37,     4,   104,    45,    39,    44,
      49,    50,    41,    42,     3,   111,    43,    20,    25,    48,
     115,   119,    18,    23,    23,    30,    19,    19,    19,    20,
      90,     8,    95,    21,    23,    26,    20,    86,    70,   120,
      72,    73,   120,    99,   101,   102,   105,   106,   107,   108,
     109,   109,   110,   110,   112,   112,    21,    92,    93,    99,
      99,    72,   119,   120,    99,   105,   120,    34,    68,    97,
      97,    97,    21,    91,    92,    19,   121,    99,    21,    24,
      72,    87,    88,    19,    22,     6,    75,    21,    23,     6,
      95,    26,    19,    35,    12,    82,    11,    81,    82,    21,
      23,    97,    30,    19,    21,    23,    97,    99,    99,    93,
      99,    97,    67,    98,    19,    99,    11,    82,   100,    99,
      88,    19,    82,     0,    36,    67,    97,    19,    99,    10,
      94,    95,    96,    97,    97,    19,   100,    97,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    81,    81,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   109,   109,   109,   110,   110,   111,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   120,   120,   121,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       3,     3,     3,     2,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     5,     4,
       3,     4,     5,     6,     7,     5,     7,     2,     3,     3,
       1,     3,     1,     5,     4,     2,     3,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     4,     5,     2,     3,
       1,     4,     4,     2,     1,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       2,     2,     2,     1,     3,     1,     2,     1,     2,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     3,     3,     2,
       3,     2,     3,     1,     3,     1
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
  case 16: /* expr_stmt: name annassign  */
#line 131 "parser.y"
                {
                    table[(yyvsp[-1].attributes).lexeme]=node;
                    current_attributes.push((yyvsp[-1].attributes).lexeme);
                    cout<<"push "<<(yyvsp[-1].attributes).lexeme<<endl;
                    node++;
                }
#line 1480 "parser.tab.c"
    break;

  case 19: /* name: NAME  */
#line 140 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; (yyval.attributes).reg=(yyvsp[0].attributes).lexeme; }
#line 1486 "parser.tab.c"
    break;

  case 20: /* Assign_stmt: name ASSIGNMENT_OPERATOR Assign_stmt  */
#line 143 "parser.y"
                                     {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1492 "parser.tab.c"
    break;

  case 21: /* Assign_stmt: name ASSIGNMENT_OPERATOR testlist  */
#line 144 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1498 "parser.tab.c"
    break;

  case 71: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 263 "parser.y"
                                    {
                                        pop_functional_attributes();
                                    }
#line 1506 "parser.tab.c"
    break;

  case 72: /* suite: NEWLINE INDENT stmt_list $end  */
#line 266 "parser.y"
                                 {pop_functional_attributes();}
#line 1512 "parser.tab.c"
    break;

  case 75: /* test: or_test  */
#line 273 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1518 "parser.tab.c"
    break;

  case 76: /* or_test: or_test OR and_test  */
#line 276 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"or"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1524 "parser.tab.c"
    break;

  case 77: /* or_test: and_test  */
#line 277 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1530 "parser.tab.c"
    break;

  case 78: /* and_test: and_test AND not_test  */
#line 280 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"and"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1536 "parser.tab.c"
    break;

  case 79: /* and_test: not_test  */
#line 281 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1542 "parser.tab.c"
    break;

  case 80: /* not_test: NOT not_test  */
#line 284 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+"=""not"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1548 "parser.tab.c"
    break;

  case 81: /* not_test: comparison  */
#line 285 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1554 "parser.tab.c"
    break;

  case 82: /* comparison: comparison r_o expr  */
#line 287 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1560 "parser.tab.c"
    break;

  case 83: /* comparison: expr  */
#line 288 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1566 "parser.tab.c"
    break;

  case 84: /* r_o: RELATIONAL_OPERATOR  */
#line 290 "parser.y"
                         {string c=convert(lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1572 "parser.tab.c"
    break;

  case 85: /* expr: expr BIT_OR xor_expr  */
#line 292 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"|"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1578 "parser.tab.c"
    break;

  case 86: /* expr: xor_expr  */
#line 293 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1584 "parser.tab.c"
    break;

  case 87: /* xor_expr: xor_expr XOR and_expr  */
#line 295 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"^"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1590 "parser.tab.c"
    break;

  case 88: /* xor_expr: and_expr  */
#line 296 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1596 "parser.tab.c"
    break;

  case 89: /* and_expr: and_expr BIT_AND shift_expr  */
#line 298 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"&"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1602 "parser.tab.c"
    break;

  case 90: /* and_expr: shift_expr  */
#line 299 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1608 "parser.tab.c"
    break;

  case 91: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 301 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"<<"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1614 "parser.tab.c"
    break;

  case 92: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 302 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+">>"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1620 "parser.tab.c"
    break;

  case 93: /* shift_expr: arith_expr  */
#line 303 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1626 "parser.tab.c"
    break;

  case 94: /* arith_expr: arith_expr ADD term  */
#line 306 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1632 "parser.tab.c"
    break;

  case 95: /* arith_expr: arith_expr SUB term  */
#line 307 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1638 "parser.tab.c"
    break;

  case 96: /* arith_expr: term  */
#line 308 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1644 "parser.tab.c"
    break;

  case 97: /* term: term a_o factor  */
#line 310 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1650 "parser.tab.c"
    break;

  case 98: /* term: factor  */
#line 311 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1656 "parser.tab.c"
    break;

  case 99: /* a_o: ARITHMETIC_OPERATOR  */
#line 313 "parser.y"
                          {string c=convert(lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1662 "parser.tab.c"
    break;

  case 100: /* factor: ADD factor  */
#line 316 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1668 "parser.tab.c"
    break;

  case 101: /* factor: SUB factor  */
#line 317 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1674 "parser.tab.c"
    break;

  case 102: /* factor: BIT_NOT factor  */
#line 318 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+"=""~"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1680 "parser.tab.c"
    break;

  case 103: /* factor: power  */
#line 319 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1686 "parser.tab.c"
    break;

  case 104: /* power: atom_expr POWER factor  */
#line 322 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"**"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1692 "parser.tab.c"
    break;

  case 105: /* power: atom_expr  */
#line 323 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1698 "parser.tab.c"
    break;

  case 107: /* atom_expr: atom  */
#line 327 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1704 "parser.tab.c"
    break;

  case 114: /* atom: NAME  */
#line 338 "parser.y"
        {string c="r"+to_string(node); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert(lexeme); code.push_back(c);  node++;}
#line 1710 "parser.tab.c"
    break;

  case 115: /* atom: NUMBER  */
#line 339 "parser.y"
          {string c="r"+to_string(node); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert(lexeme); code.push_back(c);  node++;}
#line 1716 "parser.tab.c"
    break;


#line 1720 "parser.tab.c"

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

#line 378 "parser.y"


const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   cout<<"Error in Line no "<<yylineno<<endl;
   cout<< "The Last Lexeme is "<<lexeme<<endl;
   cout<< "The Last Token is "<<token_name(yychar)<<endl;
   return ;
}

int main ( int argc, char *argv[]){
   
   if(argc==5){ 
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   yydebug=0;
   yyparse();
   for(auto x:code){
    fprintf(yyout,"%s\n",x.data());
   }
   fclose(yyin);
   fclose(yyout);
   }else if(argc==2){
     cout<<" Use ./ast -input input_file -output output_file for proper execution\n";
   }else{
     cout<<" Use ./ast -help\n";
   }
   
   return 0;
}
