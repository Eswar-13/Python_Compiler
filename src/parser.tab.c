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
class content{
    public:
        int type;
        content(){}
        content(int type) : type(type) {}
};
int typedetector(string s){
    if(s=="int")return 1;
    if(s=="float")return 2;
    if(s=="bool")return 3;
    if(s=="str")return 4;
    if(s=="class")return 5;
    return 0;
}
int typelist(string s){
    int a=0;
    string t="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='[')a=1;
        else if(s[i]==']')a=0;
        else if(a&&s[i]!=' ')t+=s[i];
    }
    return typedetector(t);
}
int check_type(int type1, int type2){
    if(type1==type2)return type1;
    else if(type1==1&&type2==3||type1==3&&type2==1)return type1;
    else if(type1==1&&type2==2||type1==2&&type2==1)return type2;
    else {
        yyerror("type");
        return 0;
    }
}
vector<string>code;

map<string,content>table;
extern stack<string>current_attributes;
int current_func_type;
bool check(string s){
    if(table.find(s)==table.end()){yyerror("dec");return 1;}
    else return 0;
}
void update_table(string key,int type){
    table[key]=content(type);
    current_attributes.push(key);
    cout<<"push "<<key<<endl;
}
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

#line 193 "parser.tab.c"

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
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_FLOAT = 47,                     /* FLOAT  */
  YYSYMBOL_STRING = 48,                    /* STRING  */
  YYSYMBOL_DOT = 49,                       /* DOT  */
  YYSYMBOL_L_SHIFT = 50,                   /* L_SHIFT  */
  YYSYMBOL_R_SHIFT = 51,                   /* R_SHIFT  */
  YYSYMBOL_STRING_1 = 52,                  /* STRING_1  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 53,        /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 54,       /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_INVALID = 55,                   /* INVALID  */
  YYSYMBOL_low = 56,                       /* low  */
  YYSYMBOL_low1 = 57,                      /* low1  */
  YYSYMBOL_low2 = 58,                      /* low2  */
  YYSYMBOL_low3 = 59,                      /* low3  */
  YYSYMBOL_low4 = 60,                      /* low4  */
  YYSYMBOL_low5 = 61,                      /* low5  */
  YYSYMBOL_low6 = 62,                      /* low6  */
  YYSYMBOL_high = 63,                      /* high  */
  YYSYMBOL_high1 = 64,                     /* high1  */
  YYSYMBOL_SHIFT = 65,                     /* SHIFT  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_module = 67,                    /* module  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_simple_stmt = 69,               /* simple_stmt  */
  YYSYMBOL_more_expr = 70,                 /* more_expr  */
  YYSYMBOL_small_stmt = 71,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 72,                 /* expr_stmt  */
  YYSYMBOL_Assign_stmt = 73,               /* Assign_stmt  */
  YYSYMBOL_name = 74,                      /* name  */
  YYSYMBOL_annassign = 75,                 /* annassign  */
  YYSYMBOL_data_type = 76,                 /* data_type  */
  YYSYMBOL_param_list = 77,                /* param_list  */
  YYSYMBOL_break_stmt = 78,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 79,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 80,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 81,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 82,                   /* if_stmt  */
  YYSYMBOL_if_test = 83,                   /* if_test  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_elif_statements = 85,           /* elif_statements  */
  YYSYMBOL_elif_test = 86,                 /* elif_test  */
  YYSYMBOL_87_2 = 87,                      /* $@2  */
  YYSYMBOL_else_statement = 88,            /* else_statement  */
  YYSYMBOL_while_stmt = 89,                /* while_stmt  */
  YYSYMBOL_while_test = 90,                /* while_test  */
  YYSYMBOL_91_3 = 91,                      /* $@3  */
  YYSYMBOL_92_4 = 92,                      /* $@4  */
  YYSYMBOL_for_stmt = 93,                  /* for_stmt  */
  YYSYMBOL_funcdef = 94,                   /* funcdef  */
  YYSYMBOL_95_5 = 95,                      /* $@5  */
  YYSYMBOL_parameters = 96,                /* parameters  */
  YYSYMBOL_typedargslist = 97,             /* typedargslist  */
  YYSYMBOL_full_tfpdef = 98,               /* full_tfpdef  */
  YYSYMBOL_classdef = 99,                  /* classdef  */
  YYSYMBOL_opt_class_arg = 100,            /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 101,              /* opt_arglist  */
  YYSYMBOL_arglist = 102,                  /* arglist  */
  YYSYMBOL_argument = 103,                 /* argument  */
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
  YYSYMBOL_trailer = 124,                  /* trailer  */
  YYSYMBOL_testlist = 125                  /* testlist  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   157,   161,   162,   163,   164,   167,   168,
     172,   173,   177,   178,   179,   180,   184,   185,   186,   190,
     191,   194,   198,   199,   201,   202,   205,   208,   212,   216,
     217,   222,   223,   224,   225,   226,   230,   231,   232,   233,
     237,   237,   240,   241,   245,   245,   248,   252,   253,   257,
     257,   257,   260,   261,   265,   266,   266,   269,   270,   274,
     275,   279,   280,   284,   285,   289,   290,   294,   295,   299,
     300,   304,   305,   311,   312,   315,   318,   319,   322,   325,
     326,   329,   330,   333,   334,   337,   338,   341,   344,   345,
     348,   349,   352,   353,   356,   357,   358,   362,   363,   364,
     367,   368,   370,   374,   375,   376,   377,   381,   382,   386,
     387,   391,   392,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   414,   415,   416,
     417,   421,   422
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
  "XOR", "BIT_NOT", "ADD", "SUB", "POWER", "BIT_AND", "BIT_OR", "INT",
  "FLOAT", "STRING", "DOT", "L_SHIFT", "R_SHIFT", "STRING_1",
  "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", "INVALID", "low", "low1",
  "low2", "low3", "low4", "low5", "low6", "high", "high1", "SHIFT",
  "$accept", "module", "stmt", "simple_stmt", "more_expr", "small_stmt",
  "expr_stmt", "Assign_stmt", "name", "annassign", "data_type",
  "param_list", "break_stmt", "continue_stmt", "return_stmt",
  "compound_stmt", "if_stmt", "if_test", "$@1", "elif_statements",
  "elif_test", "$@2", "else_statement", "while_stmt", "while_test", "$@3",
  "$@4", "for_stmt", "funcdef", "$@5", "parameters", "typedargslist",
  "full_tfpdef", "classdef", "opt_class_arg", "opt_arglist", "arglist",
  "argument", "suite", "stmt_list", "test", "or_test", "and_test",
  "not_test", "comparison", "r_o", "expr", "xor_expr", "and_expr",
  "shift_expr", "arith_expr", "term", "a_o", "factor", "power",
  "atom_expr", "opt_trailer", "atom", "trailer", "testlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     225,  -160,    27,  -160,   446,  -160,    12,  -160,  -160,   330,
      22,   359,  -160,  -160,  -160,    12,   446,   446,  -160,    27,
      27,    27,  -160,  -160,  -160,  -160,   179,  -160,  -160,    21,
    -160,  -160,  -160,    31,  -160,  -160,  -160,  -160,  -160,    19,
    -160,    33,  -160,  -160,  -160,    15,    42,    20,  -160,    49,
      48,    46,    17,    26,    40,    62,  -160,  -160,    35,   -10,
      73,  -160,   -17,   446,  -160,  -160,    68,  -160,  -160,    23,
    -160,     6,    77,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     301,     7,  -160,   446,    80,    19,  -160,  -160,  -160,   446,
     446,   446,   446,  -160,    27,    27,    27,    27,    27,    27,
      27,    27,  -160,    27,    27,   388,   446,    12,   -10,  -160,
     446,   446,  -160,    81,   263,   417,    82,  -160,  -160,    16,
       3,  -160,    15,  -160,  -160,   101,  -160,   263,  -160,  -160,
    -160,   102,  -160,    20,  -160,    48,    46,    17,    26,    40,
      40,    62,    62,  -160,  -160,  -160,    39,  -160,   103,    86,
    -160,  -160,  -160,    95,    98,   263,    83,  -160,  -160,  -160,
     104,    96,   263,  -160,    22,   105,    43,  -160,   263,     7,
     446,  -160,   111,  -160,  -160,   446,   446,  -160,   263,   263,
    -160,   225,  -160,   446,  -160,   446,  -160,   107,  -160,  -160,
    -160,   263,  -160,  -160,    33,  -160,  -160,   113,  -160,  -160,
     115,  -160,  -160,  -160,  -160,  -160,   263,  -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   120,     0,    49,     0,    27,     0,    28,   126,     0,
     117,     0,   123,   124,   125,     0,     0,    30,     4,     0,
       0,     0,   118,   119,   121,   122,     0,     3,     5,     8,
      11,    12,    18,     0,    13,    14,    15,     6,    31,    36,
      32,    47,    33,    34,    35,   132,    78,    80,    82,    84,
      86,    89,    91,    93,    96,    99,   101,   106,   108,   110,
       7,   117,     0,     0,    40,    21,     0,   114,   132,     0,
     115,     0,     0,    83,    29,   105,   103,   104,     1,     2,
       9,     0,    16,     0,     0,    39,    43,    37,    48,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,   109,   112,
       0,     0,    50,     0,     0,     0,     0,   113,   116,     0,
       0,    10,     0,    24,    25,    23,    44,     0,    42,    38,
      19,    20,    17,    79,    81,    85,    88,    90,    92,    94,
      95,    97,    98,   100,   107,   128,     0,    70,    71,     0,
     130,   111,   131,     0,     0,     0,     0,    73,    64,    65,
       0,    68,     0,    57,    62,     0,     0,    60,     0,     0,
       0,    22,     0,    46,   127,     0,     0,   129,     0,     0,
      41,     0,    66,    67,    63,     0,    58,     0,    54,    55,
      26,     0,    69,    72,    52,    51,    77,     0,    61,    59,
       0,    45,    53,    75,    74,    76,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   -24,     1,  -160,    52,  -160,    47,    -3,  -160,
     -34,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
      54,  -160,   -36,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,   -44,  -160,  -160,  -160,    36,  -159,  -120,  -160,
       0,  -160,    57,    -8,  -160,  -160,     4,    55,    56,    59,
      -7,    -6,  -160,    -1,  -160,  -160,  -160,  -160,    58,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,   157,    29,    30,    31,    32,    33,    82,
     125,   171,    34,    35,    36,    37,    38,    39,   113,    85,
      86,   172,    87,    40,    41,    63,   154,    42,    43,   200,
     120,   166,   167,    44,   116,   160,   146,   147,   158,   197,
     122,    46,    47,    48,    49,    94,    50,    51,    52,    53,
      54,    55,   103,    56,    57,    58,   108,    59,   109,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    28,    79,    66,    64,    88,    62,   173,    73,    68,
     105,    68,    72,   111,   123,   106,   192,    74,    75,    76,
      77,    89,   168,   124,   192,   169,    45,    28,    95,   110,
      83,    84,   118,    90,     1,   180,    65,   163,    80,   107,
     164,   -21,   184,     8,   117,    84,   110,     9,   188,   129,
      81,    61,    11,    93,    12,    13,    14,    92,   194,   195,
     174,    97,   175,   112,   186,   102,   187,    19,    20,    21,
      69,   201,    71,    22,    23,    24,    98,    99,   104,    25,
      91,   100,   101,   126,   134,    96,   207,   114,   115,   131,
     132,   139,   140,    95,   141,   142,   110,   119,   135,   127,
     155,   162,   143,   144,   150,   148,   149,   170,    89,   176,
     152,   153,   177,   203,   178,   148,   165,   179,   181,   183,
       1,     2,     3,     4,   185,   182,     5,     6,     7,     8,
     191,   164,   121,     9,   206,   189,   130,    10,    11,   128,
      12,    13,    14,   199,    15,    16,    17,    18,   133,   204,
     136,   161,   137,    19,    20,    21,   138,   196,   202,    22,
      23,    24,     0,     0,     0,    25,   151,     0,     0,     0,
     190,     0,     0,   205,     0,   148,   193,     0,     0,    78,
       0,    45,    28,   148,   165,   198,     1,     2,     3,     4,
       0,     0,     5,     6,     7,     8,     0,    45,    28,     9,
       0,     0,     0,    10,    11,     0,    12,    13,    14,     0,
      15,    16,    17,    18,     0,     0,     0,     0,     0,    19,
      20,    21,     0,     0,     0,    22,    23,    24,     0,     0,
       0,    25,     1,     2,     3,     4,     0,     0,     5,     6,
       7,     8,     0,     0,     0,     9,     0,     0,     0,    10,
      11,     0,    12,    13,    14,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    19,    20,    21,     0,     0,
       1,    22,    23,    24,     0,     0,     5,    25,     7,     8,
       0,     0,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,     0,     0,    16,    17,   156,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,     1,    22,
      23,    24,     0,     0,     5,    25,     7,     8,     0,     0,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,     0,     0,    16,    17,     0,     0,     1,     0,     0,
       0,    19,    20,    21,     0,     0,     8,    22,    23,    24,
       9,    67,     0,    25,    61,    11,     0,    12,    13,    14,
       0,     0,    16,     0,     0,     0,     1,     0,     0,     0,
      19,    20,    21,     0,     0,     8,    22,    23,    24,     9,
       0,     0,    25,    61,    11,    70,    12,    13,    14,     0,
       0,    16,     0,     0,     0,     1,     0,     0,     0,    19,
      20,    21,     0,     0,     8,    22,    23,    24,     9,   145,
       0,    25,    61,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     0,     1,     0,     0,     0,    19,    20,
      21,     0,     0,     8,    22,    23,    24,     9,   159,     0,
      25,    61,    11,     0,    12,    13,    14,     0,     0,    16,
       0,     0,     0,     1,     0,     0,     0,    19,    20,    21,
       0,     0,     8,    22,    23,    24,     9,     0,     0,    25,
      61,    11,     0,    12,    13,    14,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     0,    22,    23,    24,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
       0,     0,    26,     6,     4,    41,     2,   127,    16,     9,
      20,    11,    15,    30,     7,    25,   175,    17,    19,    20,
      21,     6,    19,    16,   183,    22,    26,    26,    45,    23,
      11,    12,    26,    18,     7,   155,    24,    21,    17,    49,
      24,    19,   162,    16,    21,    12,    23,    20,   168,    85,
      19,    24,    25,     4,    27,    28,    29,    37,   178,   179,
      21,    44,    23,    63,    21,     3,    23,    40,    41,    42,
       9,   191,    11,    46,    47,    48,    50,    51,    43,    52,
      38,    41,    42,    83,    92,    39,   206,    19,    20,    89,
      90,    98,    99,    45,   100,   101,    23,    20,    94,    19,
      19,    19,   103,   104,   107,   105,   106,     6,     6,     6,
     110,   111,    26,     0,    19,   115,   119,    19,    35,    23,
       7,     8,     9,    10,    19,    21,    13,    14,    15,    16,
      19,    24,    80,    20,    19,   169,    89,    24,    25,    85,
      27,    28,    29,   187,    31,    32,    33,    34,    91,    36,
      95,   115,    96,    40,    41,    42,    97,   181,   194,    46,
      47,    48,    -1,    -1,    -1,    52,   108,    -1,    -1,    -1,
     170,    -1,    -1,   197,    -1,   175,   176,    -1,    -1,     0,
      -1,   181,   181,   183,   187,   185,     7,     8,     9,    10,
      -1,    -1,    13,    14,    15,    16,    -1,   197,   197,    20,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    52,     7,     8,     9,    10,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
       7,    46,    47,    48,    -1,    -1,    13,    52,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,     7,    46,
      47,    48,    -1,    -1,    13,    52,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    33,    -1,    -1,     7,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    16,    46,    47,    48,
      20,    21,    -1,    52,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    16,    46,    47,    48,    20,
      -1,    -1,    52,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,     7,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    16,    46,    47,    48,    20,    21,
      -1,    52,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,     7,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    16,    46,    47,    48,    20,    21,    -1,
      52,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,     7,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    16,    46,    47,    48,    20,    -1,    -1,    52,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    48,    52,    67,    68,    69,    70,
      71,    72,    73,    74,    78,    79,    80,    81,    82,    83,
      89,    90,    93,    94,    99,   106,   107,   108,   109,   110,
     112,   113,   114,   115,   116,   117,   119,   120,   121,   123,
     125,    24,   112,    91,   106,    24,    74,    21,   106,   125,
      26,   125,    74,   109,   106,   119,   119,   119,     0,    68,
      17,    19,    75,    11,    12,    85,    86,    88,    88,     6,
      18,    38,    37,     4,   111,    45,    39,    44,    50,    51,
      41,    42,     3,   118,    43,    20,    25,    49,   122,   124,
      23,    30,   106,    84,    19,    20,   100,    21,    26,    20,
      96,    71,   106,     7,    16,    76,   106,    19,    86,    88,
      73,   106,   106,   108,   109,   112,   113,   114,   115,   116,
     116,   117,   117,   119,   119,    21,   102,   103,   106,   106,
      74,   124,   106,   106,    92,    19,    34,    69,   104,    21,
     101,   102,    19,    21,    24,    74,    97,    98,    19,    22,
       6,    77,    87,   104,    21,    23,     6,    26,    19,    19,
     104,    35,    21,    23,   104,    19,    21,    23,   104,    76,
     106,    19,   103,   106,   104,   104,    68,   105,   106,    98,
      95,   104,    88,     0,    36,    68,    19,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    74,    75,    75,    76,    76,    77,    78,    79,    80,
      80,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      84,    83,    85,    85,    87,    86,    88,    89,    89,    91,
      92,    90,    93,    93,    94,    95,    94,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   105,   105,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       3,     1,     3,     2,     1,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       0,     5,     2,     1,     0,     5,     3,     1,     2,     0,
       0,     6,     6,     7,     5,     0,     8,     2,     3,     3,
       1,     3,     1,     5,     4,     2,     3,     2,     1,     3,
       1,     1,     3,     1,     4,     4,     2,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     2,     2,     2,     1,     3,     1,     2,
       1,     2,     1,     3,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       2,     3,     1
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
#line 184 "parser.y"
                {string c=convert((yyvsp[-1].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c); update_table((yyvsp[-1].attributes).lexeme,(yyvsp[0].attributes).type);}
#line 1525 "parser.tab.c"
    break;

  case 17: /* expr_stmt: test AUGASSIGNMENT_OPERATOR test  */
#line 185 "parser.y"
                                  {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1531 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: test ASSIGNMENT_OPERATOR Assign_stmt  */
#line 190 "parser.y"
                                     {string c=convert((yyvsp[-2].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=(yyvsp[-2].attributes).type;}
#line 1537 "parser.tab.c"
    break;

  case 20: /* Assign_stmt: test ASSIGNMENT_OPERATOR test  */
#line 191 "parser.y"
                               {string c=convert((yyvsp[-2].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=(yyvsp[-2].attributes).type;}
#line 1543 "parser.tab.c"
    break;

  case 21: /* name: NAME  */
#line 194 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size()]; strcpy((yyval.attributes).reg, c.c_str());}
#line 1549 "parser.tab.c"
    break;

  case 22: /* annassign: COLON data_type param_list  */
#line 198 "parser.y"
                                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[-1].attributes).type;if(!check_type((yyvsp[-1].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1555 "parser.tab.c"
    break;

  case 23: /* annassign: COLON data_type  */
#line 199 "parser.y"
                            {(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1561 "parser.tab.c"
    break;

  case 24: /* data_type: DATA_TYPE  */
#line 201 "parser.y"
                     {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);}
#line 1567 "parser.tab.c"
    break;

  case 25: /* data_type: LIST  */
#line 202 "parser.y"
      {(yyval.attributes).type=typelist((yyvsp[0].attributes).lexeme);}
#line 1573 "parser.tab.c"
    break;

  case 26: /* param_list: ASSIGNMENT_OPERATOR test  */
#line 205 "parser.y"
                          {(yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1579 "parser.tab.c"
    break;

  case 29: /* return_stmt: RETURN test  */
#line 216 "parser.y"
                        {if(!check_type(current_func_type,(yyvsp[0].attributes).type))return 0;}
#line 1585 "parser.tab.c"
    break;

  case 36: /* if_stmt: if_test  */
#line 230 "parser.y"
         {fill(code.size()+1,1);}
#line 1591 "parser.tab.c"
    break;

  case 37: /* if_stmt: if_test else_statement  */
#line 231 "parser.y"
                          {fill(code.size()+1,1);}
#line 1597 "parser.tab.c"
    break;

  case 38: /* if_stmt: if_test elif_statements else_statement  */
#line 232 "parser.y"
                                         {fill(code.size()+1,(yyvsp[-1].attributes).jump+1);}
#line 1603 "parser.tab.c"
    break;

  case 39: /* if_stmt: if_test elif_statements  */
#line 233 "parser.y"
                          {fill(code.size()+1,(yyvsp[0].attributes).jump+1);}
#line 1609 "parser.tab.c"
    break;

  case 40: /* $@1: %empty  */
#line 237 "parser.y"
        {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1615 "parser.tab.c"
    break;

  case 41: /* if_test: IF test $@1 COLON suite  */
#line 237 "parser.y"
                                                                                                                                                                                     {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1621 "parser.tab.c"
    break;

  case 42: /* elif_statements: elif_statements elif_test  */
#line 240 "parser.y"
                          {(yyval.attributes).jump=(yyvsp[-1].attributes).jump+1;}
#line 1627 "parser.tab.c"
    break;

  case 43: /* elif_statements: elif_test  */
#line 241 "parser.y"
            {(yyval.attributes).jump=1;}
#line 1633 "parser.tab.c"
    break;

  case 44: /* $@2: %empty  */
#line 245 "parser.y"
          {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1639 "parser.tab.c"
    break;

  case 45: /* elif_test: ELIF test $@2 COLON suite  */
#line 245 "parser.y"
                                                                                                                                                                                       {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1645 "parser.tab.c"
    break;

  case 49: /* $@3: %empty  */
#line 257 "parser.y"
     {(yyvsp[0].attributes).jump=code.size()+1;}
#line 1651 "parser.tab.c"
    break;

  case 50: /* $@4: %empty  */
#line 257 "parser.y"
                                    {(yyvsp[0].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1657 "parser.tab.c"
    break;

  case 51: /* while_test: WHILE $@3 test $@4 COLON suite  */
#line 257 "parser.y"
                                                                                                                                                                                                                 {string c=code[(yyvsp[-3].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-3].attributes).jump]=c; c="jump line "+to_string((yyvsp[-5].attributes).jump); code.push_back(c);}
#line 1663 "parser.tab.c"
    break;

  case 54: /* funcdef: DEF name parameters COLON suite  */
#line 265 "parser.y"
                                 {update_table((yyvsp[-3].attributes).lexeme,6);}
#line 1669 "parser.tab.c"
    break;

  case 55: /* $@5: %empty  */
#line 266 "parser.y"
                                            {current_func_type=(yyvsp[0].attributes).type;}
#line 1675 "parser.tab.c"
    break;

  case 56: /* funcdef: DEF name parameters RETURN_ARROW data_type $@5 COLON suite  */
#line 266 "parser.y"
                                                                                      {update_table((yyvsp[-6].attributes).lexeme,6);}
#line 1681 "parser.tab.c"
    break;

  case 61: /* full_tfpdef: name COLON test  */
#line 279 "parser.y"
                           {update_table((yyvsp[-2].attributes).lexeme,(yyvsp[0].attributes).type);}
#line 1687 "parser.tab.c"
    break;

  case 63: /* classdef: CLASS name opt_class_arg COLON suite  */
#line 284 "parser.y"
                                       {update_table((yyvsp[-4].attributes).lexeme,5);}
#line 1693 "parser.tab.c"
    break;

  case 64: /* classdef: CLASS name COLON suite  */
#line 285 "parser.y"
                          {update_table((yyvsp[-3].attributes).lexeme,5);}
#line 1699 "parser.tab.c"
    break;

  case 72: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 305 "parser.y"
                                {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1705 "parser.tab.c"
    break;

  case 74: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 312 "parser.y"
                                    {
                                        pop_functional_attributes();
                                    }
#line 1713 "parser.tab.c"
    break;

  case 75: /* suite: NEWLINE INDENT stmt_list $end  */
#line 315 "parser.y"
                                 {pop_functional_attributes();}
#line 1719 "parser.tab.c"
    break;

  case 78: /* test: or_test  */
#line 322 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1725 "parser.tab.c"
    break;

  case 79: /* or_test: or_test OR and_test  */
#line 325 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"or"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1731 "parser.tab.c"
    break;

  case 80: /* or_test: and_test  */
#line 326 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1737 "parser.tab.c"
    break;

  case 81: /* and_test: and_test AND not_test  */
#line 329 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"and"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1743 "parser.tab.c"
    break;

  case 82: /* and_test: not_test  */
#line 330 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1749 "parser.tab.c"
    break;

  case 83: /* not_test: NOT not_test  */
#line 333 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+"=""not"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!((yyvsp[-1].attributes).type==1||(yyvsp[-1].attributes).type==3)){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1755 "parser.tab.c"
    break;

  case 84: /* not_test: comparison  */
#line 334 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1761 "parser.tab.c"
    break;

  case 85: /* comparison: comparison r_o expr  */
#line 337 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=3;}
#line 1767 "parser.tab.c"
    break;

  case 86: /* comparison: expr  */
#line 338 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1773 "parser.tab.c"
    break;

  case 87: /* r_o: RELATIONAL_OPERATOR  */
#line 341 "parser.y"
                         {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1779 "parser.tab.c"
    break;

  case 88: /* expr: expr BIT_OR xor_expr  */
#line 344 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"|"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1785 "parser.tab.c"
    break;

  case 89: /* expr: xor_expr  */
#line 345 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1791 "parser.tab.c"
    break;

  case 90: /* xor_expr: xor_expr XOR and_expr  */
#line 348 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"^"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1797 "parser.tab.c"
    break;

  case 91: /* xor_expr: and_expr  */
#line 349 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1803 "parser.tab.c"
    break;

  case 92: /* and_expr: and_expr BIT_AND shift_expr  */
#line 352 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"&"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1809 "parser.tab.c"
    break;

  case 93: /* and_expr: shift_expr  */
#line 353 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1815 "parser.tab.c"
    break;

  case 94: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 356 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"<<"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1821 "parser.tab.c"
    break;

  case 95: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 357 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+">>"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1827 "parser.tab.c"
    break;

  case 96: /* shift_expr: arith_expr  */
#line 358 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1833 "parser.tab.c"
    break;

  case 97: /* arith_expr: arith_expr ADD term  */
#line 362 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 1839 "parser.tab.c"
    break;

  case 98: /* arith_expr: arith_expr SUB term  */
#line 363 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>3)yyerror("type");if(type<1||type>3)return 0;(yyval.attributes).type=type;}
#line 1845 "parser.tab.c"
    break;

  case 99: /* arith_expr: term  */
#line 364 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1851 "parser.tab.c"
    break;

  case 100: /* term: term a_o factor  */
#line 367 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if((yyvsp[-1].attributes).lexeme!="//"){(yyval.attributes).type=type;}else (yyval.attributes).type=1;  }
#line 1857 "parser.tab.c"
    break;

  case 101: /* term: factor  */
#line 368 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1863 "parser.tab.c"
    break;

  case 102: /* a_o: ARITHMETIC_OPERATOR  */
#line 370 "parser.y"
                          {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; }
#line 1869 "parser.tab.c"
    break;

  case 103: /* factor: ADD factor  */
#line 374 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1875 "parser.tab.c"
    break;

  case 104: /* factor: SUB factor  */
#line 375 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1881 "parser.tab.c"
    break;

  case 105: /* factor: BIT_NOT factor  */
#line 376 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+"=""~"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type<1||(yyvsp[0].attributes).type>3){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1887 "parser.tab.c"
    break;

  case 106: /* factor: power  */
#line 377 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1893 "parser.tab.c"
    break;

  case 107: /* power: atom_expr POWER factor  */
#line 381 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"**"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;(yyval.attributes).type=type;}
#line 1899 "parser.tab.c"
    break;

  case 108: /* power: atom_expr  */
#line 382 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1905 "parser.tab.c"
    break;

  case 109: /* atom_expr: atom opt_trailer  */
#line 386 "parser.y"
                            {string c=convert((yyvsp[-1].attributes).lexeme); c+=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());  c=c+"="+convert((yyvsp[-1].attributes).lexeme)+convert((yyvsp[0].attributes).lexeme); code.push_back(c); }
#line 1911 "parser.tab.c"
    break;

  case 110: /* atom_expr: atom  */
#line 387 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1917 "parser.tab.c"
    break;

  case 111: /* opt_trailer: opt_trailer trailer  */
#line 391 "parser.y"
                    {int type=check_type((yyvsp[-1].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 1923 "parser.tab.c"
    break;

  case 112: /* opt_trailer: trailer  */
#line 392 "parser.y"
           {(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1929 "parser.tab.c"
    break;

  case 113: /* atom: LEFT_BRACKET testlist RIGHT_BRACKET  */
#line 396 "parser.y"
                                    {(yyval.attributes).type=(yyvsp[-1].attributes).type;}
#line 1935 "parser.tab.c"
    break;

  case 116: /* atom: LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET  */
#line 399 "parser.y"
                                                   {(yyval.attributes).type=(yyvsp[-1].attributes).type;}
#line 1941 "parser.tab.c"
    break;

  case 117: /* atom: NAME  */
#line 400 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;if(check((yyvsp[0].attributes).lexeme))return 0;(yyval.attributes).type=table[(yyvsp[0].attributes).lexeme].type;}
#line 1947 "parser.tab.c"
    break;

  case 118: /* atom: INT  */
#line 401 "parser.y"
      {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=1;}
#line 1953 "parser.tab.c"
    break;

  case 119: /* atom: FLOAT  */
#line 402 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=2;}
#line 1959 "parser.tab.c"
    break;

  case 120: /* atom: DATA_TYPE  */
#line 403 "parser.y"
            {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1965 "parser.tab.c"
    break;

  case 121: /* atom: STRING  */
#line 404 "parser.y"
          {(yyval.attributes).type=4;}
#line 1971 "parser.tab.c"
    break;

  case 122: /* atom: STRING_1  */
#line 405 "parser.y"
           {(yyval.attributes).type=4;}
#line 1977 "parser.tab.c"
    break;

  case 123: /* atom: NONE  */
#line 406 "parser.y"
            {(yyval.attributes).type=0;}
#line 1983 "parser.tab.c"
    break;

  case 124: /* atom: TRUE  */
#line 407 "parser.y"
      {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 1989 "parser.tab.c"
    break;

  case 125: /* atom: FALSE  */
#line 408 "parser.y"
       {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 1995 "parser.tab.c"
    break;

  case 126: /* atom: LIST  */
#line 409 "parser.y"
      {(yyval.attributes).type=7;}
#line 2001 "parser.tab.c"
    break;

  case 129: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 416 "parser.y"
                                                 {string c="["; c+=convert((yyvsp[-1].attributes).reg); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}}
#line 2007 "parser.tab.c"
    break;

  case 131: /* testlist: testlist COMMA test  */
#line 421 "parser.y"
                    {int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 2013 "parser.tab.c"
    break;

  case 132: /* testlist: test  */
#line 422 "parser.y"
       {(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2019 "parser.tab.c"
    break;


#line 2023 "parser.tab.c"

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

#line 426 "parser.y"


const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   if(s=="dec"){cout<<"declaration error"<<endl;return;}
   if(s=="type"){cout<<"Type error"<<endl;return;}
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
