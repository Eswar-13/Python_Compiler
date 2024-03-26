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
extern FILE* yyin;  
extern FILE* yyout;
extern int yychar;
extern char * yytext;

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
    //cout<<"pop "<<current_attributes.top()<<endl;
    current_attributes.pop();
}

string convert( string in){
    string out = in;
    return out;
}

void fill(int l,int c){
    int t=code.size()-1;
    while(c){
       if(code[t].compare("jump line ")==0){
        code[t]=code[t]+to_string(l);
        c--;
       }else t--;
    }
    return ;
}

#line 152 "parser.tab.c"

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
  YYSYMBOL_Assign_stmt = 72,               /* Assign_stmt  */
  YYSYMBOL_name = 73,                      /* name  */
  YYSYMBOL_annassign = 74,                 /* annassign  */
  YYSYMBOL_param_list = 75,                /* param_list  */
  YYSYMBOL_break_stmt = 76,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 77,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 78,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 79,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 80,                   /* if_stmt  */
  YYSYMBOL_if_test = 81,                   /* if_test  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_elif_statements = 83,           /* elif_statements  */
  YYSYMBOL_elif_test = 84,                 /* elif_test  */
  YYSYMBOL_85_2 = 85,                      /* $@2  */
  YYSYMBOL_else_statement = 86,            /* else_statement  */
  YYSYMBOL_while_stmt = 87,                /* while_stmt  */
  YYSYMBOL_while_test = 88,                /* while_test  */
  YYSYMBOL_89_3 = 89,                      /* $@3  */
  YYSYMBOL_90_4 = 90,                      /* $@4  */
  YYSYMBOL_for_stmt = 91,                  /* for_stmt  */
  YYSYMBOL_funcdef = 92,                   /* funcdef  */
  YYSYMBOL_parameters = 93,                /* parameters  */
  YYSYMBOL_typedargslist = 94,             /* typedargslist  */
  YYSYMBOL_full_tfpdef = 95,               /* full_tfpdef  */
  YYSYMBOL_classdef = 96,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 97,             /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 98,               /* opt_arglist  */
  YYSYMBOL_arglist = 99,                   /* arglist  */
  YYSYMBOL_argument = 100,                 /* argument  */
  YYSYMBOL_comp_iter = 101,                /* comp_iter  */
  YYSYMBOL_comp_for = 102,                 /* comp_for  */
  YYSYMBOL_comp_if = 103,                  /* comp_if  */
  YYSYMBOL_suite = 104,                    /* suite  */
  YYSYMBOL_stmt_list = 105,                /* stmt_list  */
  YYSYMBOL_test = 106,                     /* test  */
  YYSYMBOL_or_test = 107,                  /* or_test  */
  YYSYMBOL_and_test = 108,                 /* and_test  */
  YYSYMBOL_not_test = 109,                 /* not_test  */
  YYSYMBOL_comparison = 110,               /* comparison  */
  YYSYMBOL_r_o = 111,                      /* r_o  */
  YYSYMBOL_expr = 112,                     /* expr  */
  YYSYMBOL_xor_expr = 113,                 /* xor_expr  */
  YYSYMBOL_and_expr = 114,                 /* and_expr  */
  YYSYMBOL_shift_expr = 115,               /* shift_expr  */
  YYSYMBOL_arith_expr = 116,               /* arith_expr  */
  YYSYMBOL_term = 117,                     /* term  */
  YYSYMBOL_a_o = 118,                      /* a_o  */
  YYSYMBOL_factor = 119,                   /* factor  */
  YYSYMBOL_power = 120,                    /* power  */
  YYSYMBOL_atom_expr = 121,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 122,              /* opt_trailer  */
  YYSYMBOL_atom = 123,                     /* atom  */
  YYSYMBOL_testlist_comp = 124,            /* testlist_comp  */
  YYSYMBOL_opt_test_stmt = 125,            /* opt_test_stmt  */
  YYSYMBOL_trailer = 126,                  /* trailer  */
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
#define YYFINAL  79
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   567

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

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
       0,   115,   115,   116,   120,   121,   122,   123,   126,   127,
     131,   132,   136,   137,   138,   139,   143,   149,   150,   154,
     155,   158,   162,   163,   167,   170,   174,   178,   179,   183,
     184,   185,   186,   187,   191,   192,   193,   194,   198,   198,
     201,   202,   206,   206,   209,   213,   214,   218,   218,   218,
     221,   222,   226,   227,   230,   231,   235,   236,   240,   241,
     245,   246,   250,   251,   255,   256,   260,   261,   265,   266,
     267,   271,   272,   276,   277,   281,   282,   286,   287,   290,
     293,   294,   297,   300,   301,   304,   305,   308,   309,   312,
     313,   316,   319,   320,   323,   324,   327,   328,   331,   332,
     333,   337,   338,   339,   342,   343,   345,   349,   350,   351,
     352,   356,   357,   361,   362,   366,   367,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     387,   388,   389,   392,   393,   397,   398,   399,   400,   404,
     405,   409,   410
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
  "simple_stmt", "more_expr", "small_stmt", "expr_stmt", "Assign_stmt",
  "name", "annassign", "param_list", "break_stmt", "continue_stmt",
  "return_stmt", "compound_stmt", "if_stmt", "if_test", "$@1",
  "elif_statements", "elif_test", "$@2", "else_statement", "while_stmt",
  "while_test", "$@3", "$@4", "for_stmt", "funcdef", "parameters",
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

#define YYPACT_NINF (-184)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     246,  -184,   516,  -184,   460,  -184,   -13,  -184,  -184,   348,
      13,   376,  -184,  -184,  -184,   -13,   460,   460,  -184,   516,
     516,   516,  -184,  -184,  -184,   201,  -184,  -184,    14,  -184,
    -184,  -184,    21,  -184,  -184,  -184,  -184,  -184,    43,  -184,
      32,  -184,  -184,  -184,  -184,   -21,    26,  -184,    44,    33,
      36,    25,    18,    30,    62,  -184,  -184,    42,   -12,    24,
    -184,    33,     5,   460,  -184,  -184,    54,  -184,    71,    66,
      67,  -184,    68,    72,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,   320,   488,   460,  -184,   460,    74,    43,  -184,  -184,
    -184,   460,   460,  -184,   516,   516,   516,   516,   516,   516,
     516,   516,  -184,   516,   516,   404,   460,   -13,   -12,  -184,
     460,   460,   516,   460,  -184,    76,   283,   432,    77,   516,
    -184,  -184,   460,  -184,    28,    31,  -184,    24,  -184,    91,
      75,    93,  -184,   283,  -184,  -184,    26,  -184,    33,    36,
      25,    18,    30,    30,    62,    62,  -184,  -184,  -184,    37,
    -184,    53,    78,  -184,  -184,    75,  -184,    33,    20,    81,
     283,    80,  -184,  -184,  -184,    82,    79,   283,    11,  -184,
    -184,    88,    92,    41,  -184,   283,   460,   460,  -184,    98,
    -184,  -184,   460,   460,  -184,  -184,   283,   283,  -184,   246,
    -184,   460,  -184,   460,   460,  -184,    94,  -184,   102,  -184,
     283,  -184,  -184,    32,  -184,  -184,   122,     8,  -184,  -184,
     283,  -184,  -184,  -184,  -184,  -184,   460,  -184,  -184,  -184,
    -184,     8,  -184
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   123,     0,    47,     0,    25,     0,    26,   129,     0,
     121,     0,   126,   127,   128,     0,     0,    27,     4,     0,
       0,     0,   122,   124,   125,     0,     3,     5,     8,    11,
      12,    18,     0,    13,    14,    15,     6,    29,    34,    30,
      45,    31,    32,    33,   140,    82,    84,    86,    88,    90,
      93,    95,    97,   100,   103,   105,   110,   112,   114,     7,
     121,   142,     0,     0,    38,    21,     0,   118,   133,     0,
     132,   119,     0,     0,    87,    28,   109,   107,   108,     1,
       2,     9,     0,     0,    16,     0,     0,    37,    41,    35,
      46,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,   113,   116,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
     130,   117,   131,   120,     0,     0,    10,     0,    19,     0,
      20,    23,    42,     0,    40,    36,    83,    85,    89,    92,
      94,    96,    98,    99,   101,   102,   104,   111,   136,     0,
      67,    68,     0,   138,   115,    17,   139,   141,     0,     0,
       0,     0,    77,    61,    62,     0,    65,     0,     0,   134,
      54,    59,     0,     0,    57,     0,     0,     0,    22,     0,
      44,   135,     0,     0,    69,   137,     0,     0,    39,     0,
      63,    64,    60,     0,     0,    55,     0,    52,     0,    24,
       0,    66,    70,    50,    49,    81,     0,    73,    58,    56,
       0,    43,    51,    79,    78,    80,     0,    74,    71,    72,
      53,    75,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,   -23,     1,  -184,    46,  -184,    52,     9,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,    56,
    -184,   -36,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
     -84,  -184,  -184,  -184,     6,  -153,   -97,   -62,  -184,  -130,
    -184,     3,  -183,    48,   -11,  -184,  -184,     7,    45,    49,
      47,   -22,   -17,  -184,     2,  -184,  -184,  -184,  -184,   117,
    -184,    40,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,   162,    28,    29,    30,    31,    32,    84,
     178,    33,    34,    35,    36,    37,    38,   115,    87,    88,
     179,    89,    39,    40,    63,   159,    41,    42,   125,   173,
     174,    43,   118,   165,   149,   150,   217,   218,   219,   163,
     206,    44,    45,    46,    47,    48,    94,    49,    50,    51,
      52,    53,    54,   103,    55,    56,    57,   108,    58,    69,
      70,   109,   127,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    27,    80,   180,    90,    74,   120,    64,   105,    61,
     207,    65,    68,   106,    68,    66,   119,    91,   216,   -21,
      75,    76,    77,    78,    73,    59,    27,    82,   112,   201,
     188,    81,   -21,   221,   112,   113,   107,   192,   201,   186,
      83,   193,   110,   111,    86,   197,    91,   111,    93,   170,
     175,   135,   171,   176,    85,    86,   203,   204,   181,   183,
     182,   119,   195,    92,   196,   102,   114,    98,    99,    97,
     211,   100,   101,   116,   117,    96,   142,   143,    95,   119,
     220,   137,   130,   144,   145,   104,   131,   121,   132,   184,
     122,   129,   124,   133,   123,   160,   167,    82,   111,   177,
     187,   138,   191,   190,   185,   146,   147,   -21,   151,   152,
     155,   194,   209,   158,   156,   189,   153,   200,   171,   157,
     151,   210,   213,   166,   222,   169,    61,   126,    72,     1,
       2,     3,     4,   172,   128,     5,     6,     7,     8,   136,
     139,   168,     9,   134,   141,   140,    10,    11,   154,    12,
      13,    14,     0,    15,    16,    17,    18,     0,   214,     0,
       0,     0,    19,    20,    21,     0,   205,   212,    22,    23,
       0,     0,     0,    24,     0,     0,     0,     0,     0,   198,
     199,     0,     0,   215,     0,   151,   202,     0,     0,    59,
      27,     0,     0,     0,   151,     0,     0,   208,     0,     0,
       0,    79,     0,     0,     0,   172,    59,    27,     1,     2,
       3,     4,     0,     0,     5,     6,     7,     8,     0,     0,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,     0,    15,    16,    17,    18,     0,     0,     0,     0,
       0,    19,    20,    21,     0,     0,     0,    22,    23,     0,
       0,     0,    24,     1,     2,     3,     4,     0,     0,     5,
       6,     7,     8,     0,     0,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       1,     0,    22,    23,     0,     0,     5,    24,     7,     8,
       0,     0,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,     0,     0,    16,    17,   161,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     1,     0,    22,
      23,     0,     0,     5,    24,     7,     8,     0,     0,     0,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
       0,     0,    16,    17,     0,     1,     0,     0,     0,     0,
      19,    20,    21,     0,     8,     0,    22,    23,     9,    67,
       0,    24,    60,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     1,     0,     0,     0,     0,    19,    20,
      21,     0,     8,     0,    22,    23,     9,     0,     0,    24,
      60,    11,    71,    12,    13,    14,     0,     0,    16,     0,
       0,     1,     0,     0,     0,     0,    19,    20,    21,     0,
       8,     0,    22,    23,     9,   148,     0,    24,    60,    11,
       0,    12,    13,    14,     0,     0,    16,     0,     0,     1,
       0,     0,     0,     0,    19,    20,    21,     0,     8,     0,
      22,    23,     9,   164,     0,    24,    60,    11,     0,    12,
      13,    14,     0,     0,    16,     0,     0,     1,     0,     0,
       0,     0,    19,    20,    21,     0,     8,     0,    22,    23,
       9,     0,     0,    24,    60,    11,     0,    12,    13,    14,
       0,     0,    16,     0,     0,     1,     0,     0,     0,     0,
      19,    20,    21,     0,     8,     0,    22,    23,     9,     0,
       0,    24,    10,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     1,     0,     0,     0,     0,    19,    20,
      21,     0,     8,     0,    22,    23,     9,     0,     0,    24,
      60,    11,     0,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     0,    22,    23,     0,     0,     0,    24
};

static const yytype_int16 yycheck[] =
{
       0,     0,    25,   133,    40,    16,    68,     4,    20,     2,
     193,    24,     9,    25,    11,     6,     8,    38,    10,     6,
      17,    19,    20,    21,    15,    25,    25,     6,    23,   182,
     160,    17,    19,   216,    23,    30,    48,   167,   191,    19,
      19,    30,    18,    23,    12,   175,    38,    23,     4,    21,
      19,    87,    24,    22,    11,    12,   186,   187,    21,     6,
      23,     8,    21,    37,    23,     3,    63,    49,    50,    44,
     200,    41,    42,    19,    20,    39,    98,    99,    45,     8,
     210,    92,    82,   100,   101,    43,    83,    21,    85,   151,
      23,    82,    20,    19,    26,    19,    19,     6,    23,     6,
      19,    94,    23,    21,    26,   103,   104,    19,   105,   106,
     110,    19,   196,   113,   111,    35,   107,    19,    24,   112,
     117,    19,     0,   117,   221,   122,   119,    81,    11,     7,
       8,     9,    10,   124,    82,    13,    14,    15,    16,    91,
      95,   119,    20,    87,    97,    96,    24,    25,   108,    27,
      28,    29,    -1,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,   189,   203,    46,    47,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,   176,
     177,    -1,    -1,   206,    -1,   182,   183,    -1,    -1,   189,
     189,    -1,    -1,    -1,   191,    -1,    -1,   194,    -1,    -1,
      -1,     0,    -1,    -1,    -1,   196,   206,   206,     7,     8,
       9,    10,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
       7,    -1,    46,    47,    -1,    -1,    13,    51,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,     7,    -1,    46,
      47,    -1,    -1,    13,    51,    15,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    33,    -1,     7,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    16,    -1,    46,    47,    20,    21,
      -1,    51,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    16,    -1,    46,    47,    20,    -1,    -1,    51,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      16,    -1,    46,    47,    20,    21,    -1,    51,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    16,    -1,
      46,    47,    20,    21,    -1,    51,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    16,    -1,    46,    47,
      20,    -1,    -1,    51,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    16,    -1,    46,    47,    20,    -1,
      -1,    51,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,     7,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    16,    -1,    46,    47,    20,    -1,    -1,    51,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    51,    66,    67,    68,    69,    70,
      71,    72,    73,    76,    77,    78,    79,    80,    81,    87,
      88,    91,    92,    96,   106,   107,   108,   109,   110,   112,
     113,   114,   115,   116,   117,   119,   120,   121,   123,   127,
      24,   112,   128,    89,   106,    24,    73,    21,   106,   124,
     125,    26,   124,    73,   109,   106,   119,   119,   119,     0,
      67,    17,     6,    19,    74,    11,    12,    83,    84,    86,
      86,    38,    37,     4,   111,    45,    39,    44,    49,    50,
      41,    42,     3,   118,    43,    20,    25,    48,   122,   126,
      18,    23,    23,    30,   106,    82,    19,    20,    97,     8,
     102,    21,    23,    26,    20,    93,    70,   127,    72,    73,
     127,   106,   106,    19,    84,    86,   108,   109,   112,   113,
     114,   115,   116,   116,   117,   117,   119,   119,    21,    99,
     100,   106,   106,    73,   126,   127,   106,   112,   127,    90,
      19,    34,    68,   104,    21,    98,    99,    19,   128,   106,
      21,    24,    73,    94,    95,    19,    22,     6,    75,    85,
     104,    21,    23,     6,   102,    26,    19,    19,   104,    35,
      21,    23,   104,    30,    19,    21,    23,   104,   106,   106,
      19,   100,   106,   104,   104,    67,   105,   107,   106,    95,
      19,   104,    86,     0,    36,    67,    10,   101,   102,   103,
     104,   107,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    82,    81,
      83,    83,    85,    84,    86,    87,    87,    89,    90,    88,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     105,   105,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   116,   117,   117,   118,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   126,   126,   127,
     127,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       3,     1,     3,     2,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     3,     2,     0,     5,
       2,     1,     0,     5,     3,     1,     2,     0,     0,     6,
       6,     7,     5,     7,     2,     3,     3,     1,     3,     1,
       5,     4,     2,     3,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     4,     5,     2,     3,     1,     4,     4,
       2,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     2,     2,     2,
       1,     3,     1,     2,     1,     2,     1,     3,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  case 16: /* expr_stmt: name annassign  */
#line 143 "parser.y"
                {
                    table[(yyvsp[-1].attributes).lexeme]=node;
                    current_attributes.push((yyvsp[-1].attributes).lexeme);
                    cout<<"push "<<(yyvsp[-1].attributes).lexeme<<endl;
                    node++;
                }
#line 1517 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: name ASSIGNMENT_OPERATOR Assign_stmt  */
#line 154 "parser.y"
                                     {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1523 "parser.tab.c"
    break;

  case 20: /* Assign_stmt: name ASSIGNMENT_OPERATOR testlist  */
#line 155 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1529 "parser.tab.c"
    break;

  case 21: /* name: NAME  */
#line 158 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size()]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1535 "parser.tab.c"
    break;

  case 34: /* if_stmt: if_test  */
#line 191 "parser.y"
         {fill(code.size()+1,1);}
#line 1541 "parser.tab.c"
    break;

  case 35: /* if_stmt: if_test else_statement  */
#line 192 "parser.y"
                          {fill(code.size()+1,1);}
#line 1547 "parser.tab.c"
    break;

  case 36: /* if_stmt: if_test elif_statements else_statement  */
#line 193 "parser.y"
                                         {fill(code.size()+1,(yyvsp[-1].attributes).jump+1);}
#line 1553 "parser.tab.c"
    break;

  case 37: /* if_stmt: if_test elif_statements  */
#line 194 "parser.y"
                          {fill(code.size()+1,(yyvsp[0].attributes).jump+1);}
#line 1559 "parser.tab.c"
    break;

  case 38: /* $@1: %empty  */
#line 198 "parser.y"
        {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1565 "parser.tab.c"
    break;

  case 39: /* if_test: IF test $@1 COLON suite  */
#line 198 "parser.y"
                                                                                                                                                                                     {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1571 "parser.tab.c"
    break;

  case 40: /* elif_statements: elif_statements elif_test  */
#line 201 "parser.y"
                          {(yyval.attributes).jump=(yyvsp[-1].attributes).jump+1;}
#line 1577 "parser.tab.c"
    break;

  case 41: /* elif_statements: elif_test  */
#line 202 "parser.y"
            {(yyval.attributes).jump=1;}
#line 1583 "parser.tab.c"
    break;

  case 42: /* $@2: %empty  */
#line 206 "parser.y"
          {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1589 "parser.tab.c"
    break;

  case 43: /* elif_test: ELIF test $@2 COLON suite  */
#line 206 "parser.y"
                                                                                                                                                                                       {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1595 "parser.tab.c"
    break;

  case 47: /* $@3: %empty  */
#line 218 "parser.y"
     {(yyvsp[0].attributes).jump=code.size()+1;}
#line 1601 "parser.tab.c"
    break;

  case 48: /* $@4: %empty  */
#line 218 "parser.y"
                                    {(yyvsp[0].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1607 "parser.tab.c"
    break;

  case 49: /* while_test: WHILE $@3 test $@4 COLON suite  */
#line 218 "parser.y"
                                                                                                                                                                                                                 {string c=code[(yyvsp[-3].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-3].attributes).jump]=c; c="jump line "+to_string((yyvsp[-5].attributes).jump); code.push_back(c);}
#line 1613 "parser.tab.c"
    break;

  case 78: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 287 "parser.y"
                                    {
                                        pop_functional_attributes();
                                    }
#line 1621 "parser.tab.c"
    break;

  case 79: /* suite: NEWLINE INDENT stmt_list $end  */
#line 290 "parser.y"
                                 {pop_functional_attributes();}
#line 1627 "parser.tab.c"
    break;

  case 82: /* test: or_test  */
#line 297 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1633 "parser.tab.c"
    break;

  case 83: /* or_test: or_test OR and_test  */
#line 300 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"or"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1639 "parser.tab.c"
    break;

  case 84: /* or_test: and_test  */
#line 301 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1645 "parser.tab.c"
    break;

  case 85: /* and_test: and_test AND not_test  */
#line 304 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"and"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1651 "parser.tab.c"
    break;

  case 86: /* and_test: not_test  */
#line 305 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1657 "parser.tab.c"
    break;

  case 87: /* not_test: NOT not_test  */
#line 308 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+"=""not"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1663 "parser.tab.c"
    break;

  case 88: /* not_test: comparison  */
#line 309 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1669 "parser.tab.c"
    break;

  case 89: /* comparison: comparison r_o expr  */
#line 312 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1675 "parser.tab.c"
    break;

  case 90: /* comparison: expr  */
#line 313 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1681 "parser.tab.c"
    break;

  case 91: /* r_o: RELATIONAL_OPERATOR  */
#line 316 "parser.y"
                         {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1687 "parser.tab.c"
    break;

  case 92: /* expr: expr BIT_OR xor_expr  */
#line 319 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"|"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1693 "parser.tab.c"
    break;

  case 93: /* expr: xor_expr  */
#line 320 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1699 "parser.tab.c"
    break;

  case 94: /* xor_expr: xor_expr XOR and_expr  */
#line 323 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"^"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1705 "parser.tab.c"
    break;

  case 95: /* xor_expr: and_expr  */
#line 324 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1711 "parser.tab.c"
    break;

  case 96: /* and_expr: and_expr BIT_AND shift_expr  */
#line 327 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"&"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1717 "parser.tab.c"
    break;

  case 97: /* and_expr: shift_expr  */
#line 328 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1723 "parser.tab.c"
    break;

  case 98: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 331 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"<<"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1729 "parser.tab.c"
    break;

  case 99: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 332 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+">>"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1735 "parser.tab.c"
    break;

  case 100: /* shift_expr: arith_expr  */
#line 333 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1741 "parser.tab.c"
    break;

  case 101: /* arith_expr: arith_expr ADD term  */
#line 337 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1747 "parser.tab.c"
    break;

  case 102: /* arith_expr: arith_expr SUB term  */
#line 338 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1753 "parser.tab.c"
    break;

  case 103: /* arith_expr: term  */
#line 339 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1759 "parser.tab.c"
    break;

  case 104: /* term: term a_o factor  */
#line 342 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1765 "parser.tab.c"
    break;

  case 105: /* term: factor  */
#line 343 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1771 "parser.tab.c"
    break;

  case 106: /* a_o: ARITHMETIC_OPERATOR  */
#line 345 "parser.y"
                          {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1777 "parser.tab.c"
    break;

  case 107: /* factor: ADD factor  */
#line 349 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1783 "parser.tab.c"
    break;

  case 108: /* factor: SUB factor  */
#line 350 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1789 "parser.tab.c"
    break;

  case 109: /* factor: BIT_NOT factor  */
#line 351 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+"=""~"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1795 "parser.tab.c"
    break;

  case 110: /* factor: power  */
#line 352 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1801 "parser.tab.c"
    break;

  case 111: /* power: atom_expr POWER factor  */
#line 356 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"**"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 1807 "parser.tab.c"
    break;

  case 112: /* power: atom_expr  */
#line 357 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1813 "parser.tab.c"
    break;

  case 114: /* atom_expr: atom  */
#line 362 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 1819 "parser.tab.c"
    break;

  case 121: /* atom: NAME  */
#line 375 "parser.y"
        {string c="r"+to_string(node); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  node++;}
#line 1825 "parser.tab.c"
    break;

  case 122: /* atom: NUMBER  */
#line 376 "parser.y"
          {string c="r"+to_string(node); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  node++;}
#line 1831 "parser.tab.c"
    break;


#line 1835 "parser.tab.c"

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

#line 413 "parser.y"


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
