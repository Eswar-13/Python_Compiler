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
        int list_type;
        int list_number;
        int funct_return_type;
        vector<int>func_parameter;
        int line_number;
        content(){}
        content(int type_num,int line) {
            type=type_num;
            line_number=line;
        }
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
        else if(s[i]==']')break;
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

map<string,map<string,content>>table;
string curr_func="global";

extern stack<string>current_attributes;
int current_func_type;
bool check(string s){
    if(table[curr_func].find(s)==table[curr_func].end() && table["global"].find(s)==table["global"].end()){yyerror("dec");return 0;}
    else return 0;
}
void update_table(string key,int type,int line_number){
    table[curr_func][key]=content(type,line_number);
    current_attributes.push(key);
}
int get_type(string key){
    if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].type;
    return table[curr_func][key].type;
}
int get_listtype(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return 0;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].list_type;
    return table[curr_func][key].list_type;
}
int get_listnumber(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return -1;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].list_number;
    return table[curr_func][key].list_number;
}
int get_funct_type(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return -1;}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].funct_return_type;
    return table[curr_func][key].funct_return_type;
}
vector<int> get_func_parameter(string key){
    if (table["global"].find(key)==table["global"].end()&&(table[curr_func].find(key)==table[curr_func].end())){return {};}
    else if(table[curr_func].find(key)==table[curr_func].end()) return table["global"][key].func_parameter;
    return table[curr_func][key].func_parameter;
}
int match_vector(vector<int>a,vector<int>b){
    if(a.size()!=b.size()){yyerror("type");return 0;}
    for(int i=0;i<a.size();i++){
        if(!check_type(a[i],b[i]))return 0;
    }
    return 1;
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
struct other{
    vector<int>types;
};


#line 228 "parser.tab.c"

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
  YYSYMBOL_func_name = 96,                 /* func_name  */
  YYSYMBOL_parameters = 97,                /* parameters  */
  YYSYMBOL_typedargslist = 98,             /* typedargslist  */
  YYSYMBOL_full_tfpdef = 99,               /* full_tfpdef  */
  YYSYMBOL_classdef = 100,                 /* classdef  */
  YYSYMBOL_opt_class_arg = 101,            /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 102,              /* opt_arglist  */
  YYSYMBOL_arglist = 103,                  /* arglist  */
  YYSYMBOL_argument = 104,                 /* argument  */
  YYSYMBOL_suite = 105,                    /* suite  */
  YYSYMBOL_stmt_list = 106,                /* stmt_list  */
  YYSYMBOL_test = 107,                     /* test  */
  YYSYMBOL_or_test = 108,                  /* or_test  */
  YYSYMBOL_and_test = 109,                 /* and_test  */
  YYSYMBOL_not_test = 110,                 /* not_test  */
  YYSYMBOL_comparison = 111,               /* comparison  */
  YYSYMBOL_r_o = 112,                      /* r_o  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_xor_expr = 114,                 /* xor_expr  */
  YYSYMBOL_and_expr = 115,                 /* and_expr  */
  YYSYMBOL_shift_expr = 116,               /* shift_expr  */
  YYSYMBOL_arith_expr = 117,               /* arith_expr  */
  YYSYMBOL_term = 118,                     /* term  */
  YYSYMBOL_a_o = 119,                      /* a_o  */
  YYSYMBOL_factor = 120,                   /* factor  */
  YYSYMBOL_power = 121,                    /* power  */
  YYSYMBOL_atom_expr = 122,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 123,              /* opt_trailer  */
  YYSYMBOL_atom = 124,                     /* atom  */
  YYSYMBOL_trailer = 125,                  /* trailer  */
  YYSYMBOL_testlist = 126                  /* testlist  */
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
#define YYLAST   528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

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
       0,   194,   194,   195,   199,   200,   201,   202,   205,   206,
     210,   211,   215,   216,   217,   218,   222,   228,   229,   233,
     244,   248,   258,   260,   261,   262,   265,   268,   272,   276,
     277,   282,   283,   284,   285,   286,   290,   291,   292,   293,
     297,   297,   300,   301,   305,   305,   308,   312,   313,   317,
     317,   317,   320,   321,   325,   331,   331,   338,   340,   341,
     345,   346,   350,   351,   355,   356,   360,   361,   365,   366,
     370,   371,   375,   376,   382,   383,   384,   387,   388,   391,
     394,   395,   398,   399,   402,   403,   406,   407,   410,   413,
     414,   417,   418,   421,   422,   425,   426,   427,   431,   432,
     433,   436,   437,   439,   443,   444,   445,   446,   450,   451,
     455,   467,   471,   472,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   494,   495,
     496,   497,   501,   502
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
  "$@4", "for_stmt", "funcdef", "$@5", "func_name", "parameters",
  "typedargslist", "full_tfpdef", "classdef", "opt_class_arg",
  "opt_arglist", "arglist", "argument", "suite", "stmt_list", "test",
  "or_test", "and_test", "not_test", "comparison", "r_o", "expr",
  "xor_expr", "and_expr", "shift_expr", "arith_expr", "term", "a_o",
  "factor", "power", "atom_expr", "opt_trailer", "atom", "trailer",
  "testlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,  -157,   476,  -157,   447,  -157,    24,  -157,  -157,   331,
      35,   360,  -157,  -157,  -157,    24,   447,   447,  -157,   476,
     476,   476,  -157,  -157,  -157,  -157,   180,  -157,  -157,    42,
    -157,  -157,  -157,    43,  -157,  -157,  -157,  -157,  -157,    41,
    -157,    11,  -157,  -157,  -157,    15,    30,    32,  -157,    69,
      29,    36,    33,     5,    19,    73,  -157,  -157,    37,   -12,
      55,  -157,   -14,   447,  -157,  -157,    45,  -157,  -157,    17,
    -157,     6,  -157,    59,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,   302,     8,  -157,   447,    62,    41,  -157,  -157,  -157,
     447,   447,   447,   447,  -157,   476,   476,   476,   476,   476,
     476,   476,   476,  -157,   476,   476,   389,   447,    24,   -12,
    -157,   447,   447,  -157,    63,   264,   418,    64,  -157,  -157,
      18,     3,  -157,    15,  -157,  -157,  -157,    80,  -157,   264,
    -157,  -157,  -157,  -157,    32,  -157,    29,    36,    33,     5,
      19,    19,    73,    73,  -157,  -157,  -157,    22,  -157,    82,
      66,  -157,  -157,  -157,    70,    74,   264,    60,  -157,  -157,
    -157,    75,    71,   264,  -157,    35,    78,    23,  -157,   264,
       8,   447,  -157,    79,  -157,  -157,   447,   447,  -157,   264,
     264,  -157,   226,  -157,   447,  -157,     8,  -157,    76,  -157,
    -157,  -157,   264,  -157,  -157,    11,  -157,  -157,   114,  -157,
    -157,    83,  -157,  -157,  -157,  -157,  -157,   264,  -157
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   121,     0,    49,     0,    27,     0,    28,   127,     0,
     118,     0,   124,   125,   126,     0,     0,    30,     4,     0,
       0,     0,   119,   120,   122,   123,     0,     3,     5,     8,
      11,    12,    18,     0,    13,    14,    15,     6,    31,    36,
      32,    47,    33,    34,    35,   133,    79,    81,    83,    85,
      87,    90,    92,    94,    97,   100,   102,   107,   109,   111,
       7,   118,     0,     0,    40,    20,     0,   115,   133,     0,
     116,     0,    57,     0,    84,    29,   106,   104,   105,     1,
       2,     9,     0,    16,     0,     0,    39,    43,    37,    48,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,   110,
     113,     0,     0,    50,     0,     0,     0,     0,   114,   117,
       0,     0,    10,     0,    23,    24,    25,    22,    44,     0,
      42,    38,    19,    17,    80,    82,    86,    89,    91,    93,
      95,    96,    98,    99,   101,   108,   129,     0,    71,    72,
       0,   131,   112,   132,     0,     0,     0,     0,    74,    65,
      66,     0,    69,     0,    58,    63,     0,     0,    61,     0,
       0,     0,    21,     0,    46,   128,     0,     0,   130,     0,
       0,    41,     0,    67,    68,    64,     0,    59,     0,    54,
      55,    26,     0,    70,    73,    52,    51,    78,     0,    62,
      60,     0,    45,    53,    76,    75,    77,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   -24,     1,  -157,    20,  -157,  -157,    -3,  -157,
    -156,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
      27,  -157,   -36,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,   -80,  -157,  -157,  -157,    -7,  -148,  -122,
    -157,     0,  -157,    26,    -6,  -157,  -157,     4,    14,    28,
      21,   -33,   -30,  -157,    -1,  -157,  -157,  -157,  -157,    31,
      40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,   158,    29,    30,    31,    32,    33,    83,
     127,   172,    34,    35,    36,    37,    38,    39,   114,    86,
      87,   173,    88,    40,    41,    63,   155,    42,    43,   201,
      73,   121,   167,   168,    44,   117,   161,   147,   148,   159,
     198,   123,    46,    47,    48,    49,    95,    50,    51,    52,
      53,    54,    55,   104,    56,    57,    58,   109,    59,   110,
      60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    28,    80,    66,    64,    89,    62,   174,   106,    68,
      74,    68,    72,   107,   190,   124,   112,    75,    76,    77,
      78,    90,   169,    85,   125,   170,    45,    28,   193,   111,
     199,    96,   119,    91,   181,   126,   193,   108,   118,   164,
     111,   185,   165,   175,   187,   176,   188,   189,    65,    69,
     131,    71,    84,    85,   -20,    99,   100,   195,   196,    81,
     101,   102,    82,   113,   115,   116,   140,   141,    92,    93,
     202,   142,   143,    94,    96,    97,   103,    98,   111,   120,
     105,   129,   156,   163,   128,   208,   171,   135,   177,   179,
     132,   133,   178,   180,   184,   182,   183,   186,   192,   136,
     165,   122,   207,   144,   145,   151,   149,   150,   200,   162,
     137,   153,   154,   130,   204,     0,   149,   166,   134,   139,
       0,     1,     2,     3,     4,   138,     0,     5,     6,     7,
       8,     0,     0,     0,     9,     0,     0,     0,    10,    11,
     152,    12,    13,    14,     0,    15,    16,    17,    18,     0,
     205,     0,     0,     0,    19,    20,    21,     0,   197,   203,
      22,    23,    24,     0,     0,     0,    25,     0,     0,     0,
       0,   191,     0,     0,   206,     0,   149,   194,     0,     0,
      79,     0,    45,    28,   149,   166,     0,     1,     2,     3,
       4,     0,     0,     5,     6,     7,     8,     0,    45,    28,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
       0,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     0,    25,     1,     2,     3,     4,     0,     0,     5,
       6,     7,     8,     0,     0,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     1,    22,    23,    24,     0,     0,     5,    25,     7,
       8,     0,     0,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,     0,     0,    16,    17,   157,     0,
       0,     0,     0,     0,    19,    20,    21,     0,     0,     1,
      22,    23,    24,     0,     0,     5,    25,     7,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,     0,     0,    16,    17,     0,     0,     1,     0,
       0,     0,    19,    20,    21,     0,     0,     8,    22,    23,
      24,     9,    67,     0,    25,    61,    11,     0,    12,    13,
      14,     0,     0,    16,     0,     0,     0,     1,     0,     0,
       0,    19,    20,    21,     0,     0,     8,    22,    23,    24,
       9,     0,     0,    25,    61,    11,    70,    12,    13,    14,
       0,     0,    16,     0,     0,     0,     1,     0,     0,     0,
      19,    20,    21,     0,     0,     8,    22,    23,    24,     9,
     146,     0,    25,    61,    11,     0,    12,    13,    14,     0,
       0,    16,     0,     0,     0,     1,     0,     0,     0,    19,
      20,    21,     0,     0,     8,    22,    23,    24,     9,   160,
       0,    25,    61,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     0,     1,     0,     0,     0,    19,    20,
      21,     0,     0,     8,    22,    23,    24,     9,     0,     0,
      25,    61,    11,     0,    12,    13,    14,     0,     0,    16,
       0,     0,     0,     1,     0,     0,     0,    19,    20,    21,
       0,     0,     8,    22,    23,    24,     9,     0,     0,    25,
      61,    11,     0,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     0,    22,    23,    24,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
       0,     0,    26,     6,     4,    41,     2,   129,    20,     9,
      16,    11,    15,    25,   170,     7,    30,    17,    19,    20,
      21,     6,    19,    12,    16,    22,    26,    26,   176,    23,
     186,    45,    26,    18,   156,    27,   184,    49,    21,    21,
      23,   163,    24,    21,    21,    23,    23,   169,    24,     9,
      86,    11,    11,    12,    19,    50,    51,   179,   180,    17,
      41,    42,    19,    63,    19,    20,    99,   100,    38,    37,
     192,   101,   102,     4,    45,    39,     3,    44,    23,    20,
      43,    19,    19,    19,    84,   207,     6,    93,     6,    19,
      90,    91,    26,    19,    23,    35,    21,    19,    19,    95,
      24,    81,    19,   104,   105,   108,   106,   107,   188,   116,
      96,   111,   112,    86,     0,    -1,   116,   120,    92,    98,
      -1,     7,     8,     9,    10,    97,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
     109,    27,    28,    29,    -1,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,   182,   195,
      46,    47,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,   171,    -1,    -1,   198,    -1,   176,   177,    -1,    -1,
       0,    -1,   182,   182,   184,   188,    -1,     7,     8,     9,
      10,    -1,    -1,    13,    14,    15,    16,    -1,   198,   198,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    52,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,     7,    46,    47,    48,    -1,    -1,    13,    52,    15,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,     7,
      46,    47,    48,    -1,    -1,    13,    52,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,     7,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    16,    46,    47,
      48,    20,    21,    -1,    52,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,     7,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    16,    46,    47,    48,
      20,    -1,    -1,    52,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    16,    46,    47,    48,    20,
      21,    -1,    52,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,     7,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    16,    46,    47,    48,    20,    21,
      -1,    52,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,     7,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    16,    46,    47,    48,    20,    -1,    -1,
      52,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,     7,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    16,    46,    47,    48,    20,    -1,    -1,    52,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
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
      89,    90,    93,    94,   100,   107,   108,   109,   110,   111,
     113,   114,   115,   116,   117,   118,   120,   121,   122,   124,
     126,    24,   113,    91,   107,    24,    74,    21,   107,   126,
      26,   126,    74,    96,   110,   107,   120,   120,   120,     0,
      68,    17,    19,    75,    11,    12,    85,    86,    88,    88,
       6,    18,    38,    37,     4,   112,    45,    39,    44,    50,
      51,    41,    42,     3,   119,    43,    20,    25,    49,   123,
     125,    23,    30,   107,    84,    19,    20,   101,    21,    26,
      20,    97,    71,   107,     7,    16,    27,    76,   107,    19,
      86,    88,   107,   107,   109,   110,   113,   114,   115,   116,
     117,   117,   118,   118,   120,   120,    21,   103,   104,   107,
     107,    74,   125,   107,   107,    92,    19,    34,    69,   105,
      21,   102,   103,    19,    21,    24,    74,    98,    99,    19,
      22,     6,    77,    87,   105,    21,    23,     6,    26,    19,
      19,   105,    35,    21,    23,   105,    19,    21,    23,   105,
      76,   107,    19,   104,   107,   105,   105,    68,   106,    76,
      99,    95,   105,    88,     0,    36,    68,    19,   105
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    73,
      74,    75,    75,    76,    76,    76,    77,    78,    79,    80,
      80,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      84,    83,    85,    85,    87,    86,    88,    89,    89,    91,
      92,    90,    93,    93,    94,    95,    94,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   117,   117,
     117,   118,   118,   119,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   126,   126
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       1,     3,     2,     1,     1,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       0,     5,     2,     1,     0,     5,     3,     1,     2,     0,
       0,     6,     6,     7,     5,     0,     8,     1,     2,     3,
       3,     1,     3,     1,     5,     4,     2,     3,     2,     1,
       3,     1,     1,     3,     1,     4,     4,     2,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     2,     2,     2,     1,     3,     1,
       2,     1,     2,     1,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     2,     3,     1
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
#line 222 "parser.y"
                {string c=convert((yyvsp[-1].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c); update_table((yyvsp[-1].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-1].attributes).line);
                    if((yyvsp[0].attributes).type==7){
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_type=(yyvsp[0].attributes).list_type;
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_number=(yyvsp[0].attributes).count;
                    }
                }
#line 1575 "parser.tab.c"
    break;

  case 17: /* expr_stmt: test AUGASSIGNMENT_OPERATOR test  */
#line 228 "parser.y"
                                  {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1581 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: test ASSIGNMENT_OPERATOR test  */
#line 233 "parser.y"
                              {string c=convert((yyvsp[-2].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;
                                    if((yyvsp[-2].attributes).type==7){
                                        int list_type=get_listtype((yyvsp[-2].attributes).lexeme);
                                        if(!check_type(list_type,(yyvsp[0].attributes).type))return 0;
                                        if(get_listnumber((yyvsp[-2].attributes).lexeme)!=(yyvsp[0].attributes).count){yyerror("type");return 0;}
                                    }else{
                                        if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=(yyvsp[-2].attributes).type;
                                    }
                                }
#line 1595 "parser.tab.c"
    break;

  case 20: /* name: NAME  */
#line 244 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size()]; strcpy((yyval.attributes).reg, c.c_str()); (yyval.attributes).line=yylineno;}
#line 1601 "parser.tab.c"
    break;

  case 21: /* annassign: COLON data_type param_list  */
#line 248 "parser.y"
                                     {  (yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).type=(yyvsp[-1].attributes).type;
                                        if((yyvsp[-1].attributes).type==7){
                                            int list_type=typelist((yyvsp[-1].attributes).lexeme);
                                            if(!check_type(list_type,(yyvsp[0].attributes).type))return 0;
                                            (yyval.attributes).list_type=list_type;
                                            (yyval.attributes).count=(yyvsp[0].attributes).count;
                                        }else{
                                            if(!check_type((yyvsp[-1].attributes).type,(yyvsp[0].attributes).type))return 0;
                                        }
                                    }
#line 1616 "parser.tab.c"
    break;

  case 22: /* annassign: COLON data_type  */
#line 258 "parser.y"
                            {(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1622 "parser.tab.c"
    break;

  case 23: /* data_type: DATA_TYPE  */
#line 260 "parser.y"
                     {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);}
#line 1628 "parser.tab.c"
    break;

  case 24: /* data_type: LIST  */
#line 261 "parser.y"
      {(yyval.attributes).type=7;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1634 "parser.tab.c"
    break;

  case 25: /* data_type: NONE  */
#line 262 "parser.y"
      {(yyval.attributes).type=0;}
#line 1640 "parser.tab.c"
    break;

  case 26: /* param_list: ASSIGNMENT_OPERATOR test  */
#line 265 "parser.y"
                          {(yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1646 "parser.tab.c"
    break;

  case 29: /* return_stmt: RETURN test  */
#line 276 "parser.y"
                        {if(!check_type(current_func_type,(yyvsp[0].attributes).type))return 0;}
#line 1652 "parser.tab.c"
    break;

  case 36: /* if_stmt: if_test  */
#line 290 "parser.y"
         {fill(code.size()+1,1);}
#line 1658 "parser.tab.c"
    break;

  case 37: /* if_stmt: if_test else_statement  */
#line 291 "parser.y"
                          {fill(code.size()+1,1);}
#line 1664 "parser.tab.c"
    break;

  case 38: /* if_stmt: if_test elif_statements else_statement  */
#line 292 "parser.y"
                                         {fill(code.size()+1,(yyvsp[-1].attributes).jump+1);}
#line 1670 "parser.tab.c"
    break;

  case 39: /* if_stmt: if_test elif_statements  */
#line 293 "parser.y"
                          {fill(code.size()+1,(yyvsp[0].attributes).jump+1);}
#line 1676 "parser.tab.c"
    break;

  case 40: /* $@1: %empty  */
#line 297 "parser.y"
        {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1682 "parser.tab.c"
    break;

  case 41: /* if_test: IF test $@1 COLON suite  */
#line 297 "parser.y"
                                                                                                                                                                                     {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1688 "parser.tab.c"
    break;

  case 42: /* elif_statements: elif_statements elif_test  */
#line 300 "parser.y"
                          {(yyval.attributes).jump=(yyvsp[-1].attributes).jump+1;}
#line 1694 "parser.tab.c"
    break;

  case 43: /* elif_statements: elif_test  */
#line 301 "parser.y"
            {(yyval.attributes).jump=1;}
#line 1700 "parser.tab.c"
    break;

  case 44: /* $@2: %empty  */
#line 305 "parser.y"
          {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1706 "parser.tab.c"
    break;

  case 45: /* elif_test: ELIF test $@2 COLON suite  */
#line 305 "parser.y"
                                                                                                                                                                                       {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1712 "parser.tab.c"
    break;

  case 49: /* $@3: %empty  */
#line 317 "parser.y"
     {(yyvsp[0].attributes).jump=code.size()+1;}
#line 1718 "parser.tab.c"
    break;

  case 50: /* $@4: %empty  */
#line 317 "parser.y"
                                    {(yyvsp[0].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1724 "parser.tab.c"
    break;

  case 51: /* while_test: WHILE $@3 test $@4 COLON suite  */
#line 317 "parser.y"
                                                                                                                                                                                                                 {string c=code[(yyvsp[-3].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-3].attributes).jump]=c; c="jump line "+to_string((yyvsp[-5].attributes).jump); code.push_back(c);}
#line 1730 "parser.tab.c"
    break;

  case 54: /* funcdef: DEF func_name parameters COLON suite  */
#line 325 "parser.y"
                                    {
                                        curr_func="global";
                                        update_table((yyvsp[-3].attributes).lexeme,6,(yyvsp[-3].attributes).line);
                                        table[curr_func][(yyvsp[-3].attributes).lexeme].func_parameter=((yyvsp[-2].attributes).other)->types;
                                        table[curr_func][(yyvsp[-3].attributes).lexeme].funct_return_type=0;
                                    }
#line 1741 "parser.tab.c"
    break;

  case 55: /* $@5: %empty  */
#line 331 "parser.y"
                                                 {current_func_type=(yyvsp[0].attributes).type;}
#line 1747 "parser.tab.c"
    break;

  case 56: /* funcdef: DEF func_name parameters RETURN_ARROW data_type $@5 COLON suite  */
#line 331 "parser.y"
                                                                                         {
                                                                                            curr_func="global";
                                                                                            update_table((yyvsp[-6].attributes).lexeme,6,(yyvsp[-6].attributes).line);
                                                                                            table[curr_func][(yyvsp[-6].attributes).lexeme].func_parameter=((yyvsp[-5].attributes).other)->types;
                                                                                            table[curr_func][(yyvsp[-6].attributes).lexeme].funct_return_type=(yyvsp[-3].attributes).type;
                                                                                        }
#line 1758 "parser.tab.c"
    break;

  case 57: /* func_name: name  */
#line 338 "parser.y"
              {curr_func=(yyvsp[0].attributes).lexeme;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1764 "parser.tab.c"
    break;

  case 58: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 340 "parser.y"
                                         {(yyval.attributes).other=new other;}
#line 1770 "parser.tab.c"
    break;

  case 59: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 341 "parser.y"
                                            {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 1776 "parser.tab.c"
    break;

  case 60: /* typedargslist: typedargslist COMMA full_tfpdef  */
#line 345 "parser.y"
                                {(yyval.attributes).other=(yyvsp[-2].attributes).other;(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);}
#line 1782 "parser.tab.c"
    break;

  case 61: /* typedargslist: full_tfpdef  */
#line 346 "parser.y"
              {(yyval.attributes).other=new other;(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);}
#line 1788 "parser.tab.c"
    break;

  case 62: /* full_tfpdef: name COLON data_type  */
#line 350 "parser.y"
                                {update_table((yyvsp[-2].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-2].attributes).line);(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1794 "parser.tab.c"
    break;

  case 64: /* classdef: CLASS name opt_class_arg COLON suite  */
#line 355 "parser.y"
                                       {update_table((yyvsp[-4].attributes).lexeme,5,(yyvsp[-3].attributes).line);}
#line 1800 "parser.tab.c"
    break;

  case 65: /* classdef: CLASS name COLON suite  */
#line 356 "parser.y"
                          {update_table((yyvsp[-3].attributes).lexeme,5,(yyvsp[-2].attributes).line);}
#line 1806 "parser.tab.c"
    break;

  case 70: /* arglist: arglist COMMA argument  */
#line 370 "parser.y"
                                  {(yyval.attributes).other=(yyvsp[-2].attributes).other;(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);}
#line 1812 "parser.tab.c"
    break;

  case 71: /* arglist: argument  */
#line 371 "parser.y"
                      {(yyval.attributes).other=new other;(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);}
#line 1818 "parser.tab.c"
    break;

  case 72: /* argument: test  */
#line 375 "parser.y"
       {(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1824 "parser.tab.c"
    break;

  case 73: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 376 "parser.y"
                                {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1830 "parser.tab.c"
    break;

  case 79: /* test: or_test  */
#line 391 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1836 "parser.tab.c"
    break;

  case 80: /* or_test: or_test OR and_test  */
#line 394 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"or"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1842 "parser.tab.c"
    break;

  case 81: /* or_test: and_test  */
#line 395 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1848 "parser.tab.c"
    break;

  case 82: /* and_test: and_test AND not_test  */
#line 398 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"and"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1854 "parser.tab.c"
    break;

  case 83: /* and_test: not_test  */
#line 399 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1860 "parser.tab.c"
    break;

  case 84: /* not_test: NOT not_test  */
#line 402 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+"=""not"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!((yyvsp[-1].attributes).type==1||(yyvsp[-1].attributes).type==3)){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1866 "parser.tab.c"
    break;

  case 85: /* not_test: comparison  */
#line 403 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1872 "parser.tab.c"
    break;

  case 86: /* comparison: comparison r_o expr  */
#line 406 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=3;}
#line 1878 "parser.tab.c"
    break;

  case 87: /* comparison: expr  */
#line 407 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1884 "parser.tab.c"
    break;

  case 88: /* r_o: RELATIONAL_OPERATOR  */
#line 410 "parser.y"
                         {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 1890 "parser.tab.c"
    break;

  case 89: /* expr: expr BIT_OR xor_expr  */
#line 413 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"|"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1896 "parser.tab.c"
    break;

  case 90: /* expr: xor_expr  */
#line 414 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1902 "parser.tab.c"
    break;

  case 91: /* xor_expr: xor_expr XOR and_expr  */
#line 417 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"^"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1908 "parser.tab.c"
    break;

  case 92: /* xor_expr: and_expr  */
#line 418 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1914 "parser.tab.c"
    break;

  case 93: /* and_expr: and_expr BIT_AND shift_expr  */
#line 421 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"&"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1920 "parser.tab.c"
    break;

  case 94: /* and_expr: shift_expr  */
#line 422 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1926 "parser.tab.c"
    break;

  case 95: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 425 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"<<"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1932 "parser.tab.c"
    break;

  case 96: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 426 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+">>"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 1938 "parser.tab.c"
    break;

  case 97: /* shift_expr: arith_expr  */
#line 427 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1944 "parser.tab.c"
    break;

  case 98: /* arith_expr: arith_expr ADD term  */
#line 431 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 1950 "parser.tab.c"
    break;

  case 99: /* arith_expr: arith_expr SUB term  */
#line 432 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>3)yyerror("type");if(type<1||type>3)return 0;(yyval.attributes).type=type;}
#line 1956 "parser.tab.c"
    break;

  case 100: /* arith_expr: term  */
#line 433 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1962 "parser.tab.c"
    break;

  case 101: /* term: term a_o factor  */
#line 436 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if((yyvsp[-1].attributes).lexeme!="//"){(yyval.attributes).type=type;}else (yyval.attributes).type=1;  }
#line 1968 "parser.tab.c"
    break;

  case 102: /* term: factor  */
#line 437 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1974 "parser.tab.c"
    break;

  case 103: /* a_o: ARITHMETIC_OPERATOR  */
#line 439 "parser.y"
                          {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; }
#line 1980 "parser.tab.c"
    break;

  case 104: /* factor: ADD factor  */
#line 443 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1986 "parser.tab.c"
    break;

  case 105: /* factor: SUB factor  */
#line 444 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1992 "parser.tab.c"
    break;

  case 106: /* factor: BIT_NOT factor  */
#line 445 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+"=""~"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type<1||(yyvsp[0].attributes).type>3){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 1998 "parser.tab.c"
    break;

  case 107: /* factor: power  */
#line 446 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2004 "parser.tab.c"
    break;

  case 108: /* power: atom_expr POWER factor  */
#line 450 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"**"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;(yyval.attributes).type=type;}
#line 2010 "parser.tab.c"
    break;

  case 109: /* power: atom_expr  */
#line 451 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2016 "parser.tab.c"
    break;

  case 110: /* atom_expr: atom opt_trailer  */
#line 455 "parser.y"
                            {string c=convert((yyvsp[-1].attributes).lexeme); c+=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());  c=c+"="+convert((yyvsp[-1].attributes).lexeme)+convert((yyvsp[0].attributes).lexeme); code.push_back(c); 
                              if(get_type((yyvsp[-1].attributes).lexeme)==7){
                                if((yyvsp[0].attributes).list_type!=1){yyerror("type");return 0;}
                                (yyval.attributes).type=get_listtype((yyvsp[-1].attributes).lexeme);
                              }else if((yyvsp[-1].attributes).type==6){
                                if(!match_vector(get_func_parameter((yyvsp[-1].attributes).lexeme),(yyvsp[0].attributes).other->types)){return 0;}
                                (yyval.attributes).type=get_funct_type((yyvsp[-1].attributes).lexeme);
                              }
                              else{
                                if((yyvsp[0].attributes).list_type==1){yyerror("type");return 0;}
                              }
                            }
#line 2033 "parser.tab.c"
    break;

  case 111: /* atom_expr: atom  */
#line 467 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2039 "parser.tab.c"
    break;

  case 112: /* opt_trailer: opt_trailer trailer  */
#line 471 "parser.y"
                    {int type=check_type((yyvsp[-1].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 2045 "parser.tab.c"
    break;

  case 113: /* opt_trailer: trailer  */
#line 472 "parser.y"
           {(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).list_type=(yyvsp[0].attributes).list_type;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).other=(yyvsp[0].attributes).other;}
#line 2051 "parser.tab.c"
    break;

  case 114: /* atom: LEFT_BRACKET testlist RIGHT_BRACKET  */
#line 476 "parser.y"
                                    {(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;}
#line 2057 "parser.tab.c"
    break;

  case 117: /* atom: LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET  */
#line 479 "parser.y"
                                                   {string c="["; c+=convert((yyvsp[-1].attributes).lexeme); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyval.attributes).lexeme); code.push_back(c); (yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;}
#line 2063 "parser.tab.c"
    break;

  case 118: /* atom: NAME  */
#line 480 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;if(check((yyvsp[0].attributes).lexeme))return 0; (yyval.attributes).type=get_type((yyvsp[0].attributes).lexeme);}
#line 2069 "parser.tab.c"
    break;

  case 119: /* atom: INT  */
#line 481 "parser.y"
      {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=1;}
#line 2075 "parser.tab.c"
    break;

  case 120: /* atom: FLOAT  */
#line 482 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=2;}
#line 2081 "parser.tab.c"
    break;

  case 121: /* atom: DATA_TYPE  */
#line 483 "parser.y"
            {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2087 "parser.tab.c"
    break;

  case 122: /* atom: STRING  */
#line 484 "parser.y"
          {(yyval.attributes).type=4;(yyval.attributes).reg=(yyvsp[0].attributes).lexeme;}
#line 2093 "parser.tab.c"
    break;

  case 123: /* atom: STRING_1  */
#line 485 "parser.y"
           {(yyval.attributes).type=4;}
#line 2099 "parser.tab.c"
    break;

  case 124: /* atom: NONE  */
#line 486 "parser.y"
            {(yyval.attributes).type=0;}
#line 2105 "parser.tab.c"
    break;

  case 125: /* atom: TRUE  */
#line 487 "parser.y"
      {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2111 "parser.tab.c"
    break;

  case 126: /* atom: FALSE  */
#line 488 "parser.y"
       {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2117 "parser.tab.c"
    break;

  case 127: /* atom: LIST  */
#line 489 "parser.y"
      {(yyval.attributes).type=7;}
#line 2123 "parser.tab.c"
    break;

  case 128: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 494 "parser.y"
                                     {string c="["; c+=convert((yyvsp[-1].attributes).reg); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); (yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 2129 "parser.tab.c"
    break;

  case 129: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 495 "parser.y"
                              {(yyval.attributes).other=new other;}
#line 2135 "parser.tab.c"
    break;

  case 130: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 496 "parser.y"
                                                 {string c="["; c+=convert((yyvsp[-1].attributes).reg); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).list_type=1;}
#line 2141 "parser.tab.c"
    break;

  case 132: /* testlist: testlist COMMA test  */
#line 501 "parser.y"
                    {string c=convert((yyvsp[-2].attributes).lexeme); c=c+","+convert((yyvsp[0].attributes).reg); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;(yyval.attributes).count=(yyvsp[-2].attributes).count+1;(yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 2147 "parser.tab.c"
    break;

  case 133: /* testlist: test  */
#line 502 "parser.y"
       {(yyval.attributes).lexeme=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=1;(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 2153 "parser.tab.c"
    break;


#line 2157 "parser.tab.c"

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

#line 506 "parser.y"


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
   for(auto x: table){
    cout<<x.first<<'\n';
    for(auto y: x.second){
        cout<<y.first<<' '<<y.second.line_number<<'\n';
    }
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
