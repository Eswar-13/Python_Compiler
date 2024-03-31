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
        string class_type;
        map<string,content>func_content;
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
string curr_class="None";
int total_class_type=11;
map<string,int>classes_type;
map<int,string>type_to_class;
void update_class_type(string key){
    classes_type[key]=total_class_type;
    type_to_class[total_class_type]=key;
    total_class_type++;
}
extern stack<string>current_attributes;
int current_func_type=-1;
int is_return=0;
int is_self=0;
void update_table(string key,int type,int line_number){
    table[curr_func][key]=content(type,line_number);
    current_attributes.push(key);
}
bool check(string s){
    if(s=="__name__"){update_table(s,4,0);return 0;}
    if(table[curr_func].find(s)==table[curr_func].end() && table["global"].find(s)==table["global"].end()){yyerror("dec");return 1;}
    else return 0;
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
void add_classes(string target,vector<string>input){
    for(int i=0;i<input.size();i++){
        for(auto it:table[input[i]]){
            table[target][it.first]=it.second;
        }
    }
}
void copy_content(string key){
    for(auto it:table[key]){
        table[curr_func][key].func_content[it.first]=it.second;
    }
    table.erase(key);
}

void find_and_replace(string a,string b,int l,int r){
    for(int i=l;i<r;i++){
        string s=code[i];
        size_t pos = 0;
        while ((pos = s.find(a, pos)) != string::npos) {
            s.replace(pos, a.length(), b);
            pos += b.length();
        }
        code[i]=s;
    }
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
    vector<string>lexemes;
    vector<string>regs;
};
// types
// 0:None
// 1:int
// 2:float
// 3:bool
// 4:str
// 5:class
// 6:function
// 7:list
// 8:class as data_type

#line 275 "parser.tab.c"

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
  YYSYMBOL_SELF = 56,                      /* SELF  */
  YYSYMBOL_RANGE = 57,                     /* RANGE  */
  YYSYMBOL_LEN = 58,                       /* LEN  */
  YYSYMBOL_PRINT = 59,                     /* PRINT  */
  YYSYMBOL_low = 60,                       /* low  */
  YYSYMBOL_low1 = 61,                      /* low1  */
  YYSYMBOL_low2 = 62,                      /* low2  */
  YYSYMBOL_low3 = 63,                      /* low3  */
  YYSYMBOL_low4 = 64,                      /* low4  */
  YYSYMBOL_low5 = 65,                      /* low5  */
  YYSYMBOL_low6 = 66,                      /* low6  */
  YYSYMBOL_high = 67,                      /* high  */
  YYSYMBOL_high1 = 68,                     /* high1  */
  YYSYMBOL_SHIFT = 69,                     /* SHIFT  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_module = 71,                    /* module  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_simple_stmt = 73,               /* simple_stmt  */
  YYSYMBOL_more_expr = 74,                 /* more_expr  */
  YYSYMBOL_small_stmt = 75,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 76,                 /* expr_stmt  */
  YYSYMBOL_Assign_stmt = 77,               /* Assign_stmt  */
  YYSYMBOL_dec_name = 78,                  /* dec_name  */
  YYSYMBOL_name = 79,                      /* name  */
  YYSYMBOL_annassign = 80,                 /* annassign  */
  YYSYMBOL_data_type = 81,                 /* data_type  */
  YYSYMBOL_param_list = 82,                /* param_list  */
  YYSYMBOL_break_stmt = 83,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 84,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 85,               /* return_stmt  */
  YYSYMBOL_compound_stmt = 86,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_if_test = 88,                   /* if_test  */
  YYSYMBOL_89_1 = 89,                      /* $@1  */
  YYSYMBOL_elif_statements = 90,           /* elif_statements  */
  YYSYMBOL_elif_test = 91,                 /* elif_test  */
  YYSYMBOL_92_2 = 92,                      /* $@2  */
  YYSYMBOL_else_statement = 93,            /* else_statement  */
  YYSYMBOL_while_stmt = 94,                /* while_stmt  */
  YYSYMBOL_while_test = 95,                /* while_test  */
  YYSYMBOL_96_3 = 96,                      /* $@3  */
  YYSYMBOL_97_4 = 97,                      /* $@4  */
  YYSYMBOL_for_stmt = 98,                  /* for_stmt  */
  YYSYMBOL_for_test = 99,                  /* for_test  */
  YYSYMBOL_100_5 = 100,                    /* $@5  */
  YYSYMBOL_range = 101,                    /* range  */
  YYSYMBOL_funcdef = 102,                  /* funcdef  */
  YYSYMBOL_103_6 = 103,                    /* $@6  */
  YYSYMBOL_104_7 = 104,                    /* $@7  */
  YYSYMBOL_105_8 = 105,                    /* $@8  */
  YYSYMBOL_func_name = 106,                /* func_name  */
  YYSYMBOL_parameters = 107,               /* parameters  */
  YYSYMBOL_typedargslist = 108,            /* typedargslist  */
  YYSYMBOL_full_tfpdef = 109,              /* full_tfpdef  */
  YYSYMBOL_classdef = 110,                 /* classdef  */
  YYSYMBOL_class_name = 111,               /* class_name  */
  YYSYMBOL_opt_class_arg = 112,            /* opt_class_arg  */
  YYSYMBOL_opt_arglist = 113,              /* opt_arglist  */
  YYSYMBOL_arglist = 114,                  /* arglist  */
  YYSYMBOL_argument = 115,                 /* argument  */
  YYSYMBOL_suite = 116,                    /* suite  */
  YYSYMBOL_stmt_list = 117,                /* stmt_list  */
  YYSYMBOL_test = 118,                     /* test  */
  YYSYMBOL_or_test = 119,                  /* or_test  */
  YYSYMBOL_and_test = 120,                 /* and_test  */
  YYSYMBOL_not_test = 121,                 /* not_test  */
  YYSYMBOL_comparison = 122,               /* comparison  */
  YYSYMBOL_r_o = 123,                      /* r_o  */
  YYSYMBOL_expr = 124,                     /* expr  */
  YYSYMBOL_xor_expr = 125,                 /* xor_expr  */
  YYSYMBOL_and_expr = 126,                 /* and_expr  */
  YYSYMBOL_shift_expr = 127,               /* shift_expr  */
  YYSYMBOL_arith_expr = 128,               /* arith_expr  */
  YYSYMBOL_term = 129,                     /* term  */
  YYSYMBOL_a_o = 130,                      /* a_o  */
  YYSYMBOL_factor = 131,                   /* factor  */
  YYSYMBOL_power = 132,                    /* power  */
  YYSYMBOL_atom_expr = 133,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 134,              /* opt_trailer  */
  YYSYMBOL_atom = 135,                     /* atom  */
  YYSYMBOL_trailer = 136,                  /* trailer  */
  YYSYMBOL_testlist = 137                  /* testlist  */
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
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   696

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   243,   247,   248,   249,   250,   253,   254,
     258,   259,   263,   264,   265,   266,   270,   278,   279,   283,
     293,   294,   296,   300,   310,   312,   313,   314,   315,   318,
     321,   325,   329,   330,   335,   336,   337,   338,   339,   343,
     344,   345,   346,   350,   350,   353,   354,   358,   358,   361,
     365,   366,   370,   370,   370,   373,   374,   378,   378,   381,
     382,   386,   386,   418,   418,   418,   451,   453,   454,   458,
     459,   463,   464,   465,   470,   471,   473,   476,   477,   481,
     482,   486,   487,   491,   492,   493,   499,   500,   501,   504,
     505,   508,   511,   512,   515,   516,   519,   520,   523,   524,
     527,   530,   531,   534,   535,   538,   539,   542,   543,   544,
     548,   549,   550,   553,   554,   556,   560,   561,   562,   563,
     567,   568,   572,   615,   617,   623,   629,   644,   645,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   667,   668,   669,   670,   674,   675
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
  "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", "INVALID", "SELF", "RANGE",
  "LEN", "PRINT", "low", "low1", "low2", "low3", "low4", "low5", "low6",
  "high", "high1", "SHIFT", "$accept", "module", "stmt", "simple_stmt",
  "more_expr", "small_stmt", "expr_stmt", "Assign_stmt", "dec_name",
  "name", "annassign", "data_type", "param_list", "break_stmt",
  "continue_stmt", "return_stmt", "compound_stmt", "if_stmt", "if_test",
  "$@1", "elif_statements", "elif_test", "$@2", "else_statement",
  "while_stmt", "while_test", "$@3", "$@4", "for_stmt", "for_test", "$@5",
  "range", "funcdef", "$@6", "$@7", "$@8", "func_name", "parameters",
  "typedargslist", "full_tfpdef", "classdef", "class_name",
  "opt_class_arg", "opt_arglist", "arglist", "argument", "suite",
  "stmt_list", "test", "or_test", "and_test", "not_test", "comparison",
  "r_o", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "a_o", "factor", "power", "atom_expr", "opt_trailer", "atom",
  "trailer", "testlist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     263,  -182,     7,  -182,   563,  -182,     7,  -182,  -182,   401,
      26,   438,  -182,  -182,  -182,     7,   563,   563,  -182,   637,
     637,   637,  -182,  -182,  -182,  -182,    -2,    50,    62,   210,
    -182,  -182,    57,  -182,  -182,  -182,    66,  -182,  -182,  -182,
    -182,  -182,  -182,    55,  -182,    77,  -182,    77,  -182,  -182,
      30,    52,    56,  -182,    92,    58,    60,    53,    22,    35,
      97,  -182,  -182,    61,     8,    78,  -182,    72,   563,  -182,
       8,  -182,  -182,    59,  -182,  -182,    16,  -182,    12,  -182,
      87,  -182,  -182,  -182,  -182,  -182,   482,   563,     7,     8,
    -182,   563,   600,  -182,  -182,   357,    25,  -182,   563,    89,
      55,  -182,  -182,  -182,  -182,   563,   563,   563,   563,  -182,
     637,   637,   637,   637,   637,   637,   637,   637,  -182,   637,
     637,     7,     8,   563,    63,  -182,    90,   310,   526,    91,
    -182,  -182,    -5,    31,  -182,     8,    23,  -182,   105,    86,
      96,  -182,    95,    33,  -182,    30,  -182,  -182,  -182,  -182,
     111,  -182,   310,  -182,  -182,  -182,  -182,    56,  -182,    58,
      60,    53,    22,    35,    35,    97,    97,  -182,  -182,  -182,
    -182,    98,  -182,   100,   310,    94,  -182,  -182,  -182,   101,
     102,   310,  -182,    26,  -182,   112,    38,  -182,  -182,    25,
    -182,   600,   563,  -182,  -182,  -182,   563,  -182,   113,  -182,
     563,   118,   310,  -182,   263,  -182,   600,  -182,    25,  -182,
       2,   310,  -182,  -182,  -182,  -182,   310,    39,   310,  -182,
    -182,   126,  -182,  -182,  -182,   124,  -182,  -182,   563,  -182,
    -182,  -182,  -182,  -182,   103,   310,  -182,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,     0,    52,     0,    30,     0,    31,   142,     0,
     133,     0,   139,   140,   141,     0,     0,    33,     4,     0,
       0,     0,   134,   135,   137,   138,     0,     0,     0,     0,
       3,     5,     8,    11,    12,    18,     0,    21,    13,    14,
      15,     6,    34,    39,    35,    50,    36,    55,    37,    38,
     148,    91,    93,    95,    97,    99,   102,   104,   106,   109,
     112,   114,   119,   121,   123,     7,    22,     0,     0,   133,
       0,    43,    76,     0,   130,   148,     0,   131,     0,    66,
       0,    96,    32,   118,   116,   117,     0,     0,     0,   124,
     128,     0,     0,     1,     2,     9,     0,    16,     0,     0,
      42,    46,    40,    51,    56,     0,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,   122,     0,     0,    53,     0,     0,     0,     0,
     129,   132,     0,     0,   144,    85,     0,    82,    83,     0,
     146,   127,     0,     0,    10,     0,    25,    26,    28,    27,
      24,    47,     0,    45,    41,    19,    17,    92,    94,    98,
     101,   103,   105,   107,   108,   110,   111,   113,   120,   146,
     147,     0,    57,     0,     0,     0,    86,    75,    77,     0,
      80,     0,    67,    72,    73,     0,     0,    70,    61,     0,
     143,     0,     0,   145,   125,   126,     0,    23,     0,    49,
       0,     0,     0,    44,     0,    78,    79,    74,     0,    68,
       0,     0,    63,    81,    84,    29,     0,     0,     0,    54,
      90,     0,    71,    69,    62,     0,    48,    60,     0,    58,
      88,    87,    89,    64,     0,     0,    59,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,   -27,     1,  -182,    49,  -182,  -182,  -182,     6,
    -182,  -165,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,    21,  -182,   -25,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,   -80,
    -182,  -182,  -182,  -182,   -86,  -181,  -147,  -182,     0,  -182,
      40,   -13,  -182,  -182,    42,    34,    36,    43,   -34,   -33,
    -182,    -6,  -182,  -182,    85,  -182,   -82,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    29,    30,   176,    32,    33,    34,    35,    36,    37,
      97,   150,   197,    38,    39,    40,    41,    42,    43,   126,
     100,   101,   198,   102,    44,    45,    68,   173,    46,    47,
     201,   172,    48,   211,   225,   235,    80,   133,   186,   187,
      49,    73,   129,   179,   136,   137,   177,   221,   145,    51,
      52,    53,    54,   110,    55,    56,    57,    58,    59,    60,
     119,    61,    62,    63,    89,    64,    90,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    31,    94,    81,    71,   199,   143,   141,    67,    75,
     213,    75,    72,    83,    84,    85,   182,    82,    86,   183,
     103,    79,   104,    87,   212,   213,   183,   203,    86,    50,
      31,    66,   146,    87,   207,   123,   105,   130,   131,   123,
     141,   147,   180,   222,   190,   -22,   191,    88,   106,   148,
     188,   184,   149,   189,   195,   219,   191,   121,   184,   209,
     227,   210,   228,    76,   224,    78,    98,    99,   125,   226,
      91,   229,   114,   115,    95,   154,   116,   117,   127,   128,
     163,   164,    92,   165,   166,    96,   138,   139,   237,    99,
     107,   142,   138,   108,   140,   158,   109,   113,   151,   112,
     118,   123,   124,   111,   120,   155,   156,   132,   152,   174,
     181,   192,   193,   167,   168,   -20,   194,   196,   200,   202,
     171,   153,   205,   170,   236,   206,   230,   169,   138,   204,
     223,   208,   216,     1,     2,     3,     4,   218,   185,     5,
       6,     7,     8,   233,   144,   160,     9,   157,   161,   122,
      10,    11,   159,    12,    13,    14,   162,    15,    16,    17,
      18,     0,   231,     0,     0,     0,    19,    20,    21,     0,
       0,     0,    22,    23,    24,     0,     0,   220,    25,     0,
       0,     0,    26,     0,    27,    28,     0,     0,     0,     0,
       0,   138,   214,     0,   232,     0,   215,     0,     0,     0,
     217,     0,     0,     0,    50,    31,   138,     0,     0,     0,
      93,     0,     0,     0,     0,     0,   185,     1,     2,     3,
       4,    50,    31,     5,     6,     7,     8,     0,   234,     0,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
       0,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     0,    25,     0,     0,     0,    26,     0,    27,    28,
       1,     2,     3,     4,     0,     0,     5,     6,     7,     8,
       0,     0,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,     0,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,     0,    22,
      23,    24,     0,     0,     0,    25,     0,     1,     0,    26,
       0,    27,    28,     5,     0,     7,     8,     0,     0,     0,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
       0,     0,    16,    17,   175,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     0,    25,     0,     1,     0,    26,     0,    27,    28,
       5,     0,     7,     8,     0,     0,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,    19,    20,    21,
       0,     0,     0,    22,    23,    24,     0,     0,     1,    25,
       0,     0,     0,    26,     0,    27,    28,     8,     0,     0,
       0,     9,    74,     0,     0,    69,    11,     0,    12,    13,
      14,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,     0,     1,     0,    22,    23,    24,
       0,     0,     0,    25,     8,     0,     0,    70,     9,    27,
      28,     0,    69,    11,    77,    12,    13,    14,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      21,     0,     0,     0,    22,    23,    24,     0,     0,     1,
      25,     0,     0,     0,    70,     0,    27,    28,     8,     0,
       0,     0,     9,   134,     0,     0,    69,    11,     0,    12,
      13,    14,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     1,    25,     0,     0,     0,   135,     0,
      27,    28,     8,     0,     0,     0,     9,   178,     0,     0,
      69,    11,     0,    12,    13,    14,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       1,     0,    22,    23,    24,     0,     0,     0,    25,     8,
       0,     0,   135,     9,    27,    28,     0,    69,    11,     0,
      12,    13,    14,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     1,     0,    22,
      23,    24,     0,     0,     0,    25,     8,     0,     0,    70,
       9,    27,    28,     0,    69,    11,     0,    12,    13,    14,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     1,     0,    22,    23,    24,     0,
       0,     0,    25,     8,     0,     0,   135,     9,    27,    28,
       0,    69,    11,     0,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,    21,
       0,     0,     0,    22,    23,    24,     0,     0,     0,    25,
       0,     0,     0,    70,     0,    27,    28
};

static const yytype_int16 yycheck[] =
{
       0,     0,    29,    16,     4,   152,    92,    89,     2,     9,
     191,    11,     6,    19,    20,    21,    21,    17,    20,    24,
      45,    15,    47,    25,   189,   206,    24,   174,    20,    29,
      29,    24,     7,    25,   181,    23,     6,    21,    26,    23,
     122,    16,   128,   208,    21,    19,    23,    49,    18,    24,
      19,    56,    27,    22,    21,   202,    23,    49,    56,    21,
      21,    23,    23,     9,   211,    11,    11,    12,    68,   216,
      20,   218,    50,    51,    17,   100,    41,    42,    19,    20,
     114,   115,    20,   116,   117,    19,    86,    87,   235,    12,
      38,    91,    92,    37,    88,   108,     4,    44,    98,    39,
       3,    23,    30,    45,    43,   105,   106,    20,    19,    19,
      19,     6,    26,   119,   120,    19,    21,     6,    20,    19,
      57,   100,    21,   123,    21,    23,     0,   121,   128,    35,
     210,    19,    19,     7,     8,     9,    10,    19,   132,    13,
      14,    15,    16,    19,    95,   111,    20,   107,   112,    64,
      24,    25,   110,    27,    28,    29,   113,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,   204,    52,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,   191,   192,    -1,   221,    -1,   196,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,   204,   206,    -1,    -1,    -1,
       0,    -1,    -1,    -1,    -1,    -1,   210,     7,     8,     9,
      10,   221,   221,    13,    14,    15,    16,    -1,   228,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59,
       7,     8,     9,    10,    -1,    -1,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,     7,    -1,    56,
      -1,    58,    59,    13,    -1,    15,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    52,    -1,     7,    -1,    56,    -1,    58,    59,
      13,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,     7,    52,
      -1,    -1,    -1,    56,    -1,    58,    59,    16,    -1,    -1,
      -1,    20,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,     7,    -1,    46,    47,    48,
      -1,    -1,    -1,    52,    16,    -1,    -1,    56,    20,    58,
      59,    -1,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,     7,
      52,    -1,    -1,    -1,    56,    -1,    58,    59,    16,    -1,
      -1,    -1,    20,    21,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,     7,    52,    -1,    -1,    -1,    56,    -1,
      58,    59,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
       7,    -1,    46,    47,    48,    -1,    -1,    -1,    52,    16,
      -1,    -1,    56,    20,    58,    59,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,     7,    -1,    46,
      47,    48,    -1,    -1,    -1,    52,    16,    -1,    -1,    56,
      20,    58,    59,    -1,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,     7,    -1,    46,    47,    48,    -1,
      -1,    -1,    52,    16,    -1,    -1,    56,    20,    58,    59,
      -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    42,    46,    47,    48,    52,    56,    58,    59,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    83,    84,
      85,    86,    87,    88,    94,    95,    98,    99,   102,   110,
     118,   119,   120,   121,   122,   124,   125,   126,   127,   128,
     129,   131,   132,   133,   135,   137,    24,    79,    96,    24,
      56,   118,    79,   111,    21,   118,   137,    26,   137,    79,
     106,   121,   118,   131,   131,   131,    20,    25,    49,   134,
     136,    20,    20,     0,    72,    17,    19,    80,    11,    12,
      90,    91,    93,    93,    93,     6,    18,    38,    37,     4,
     123,    45,    39,    44,    50,    51,    41,    42,     3,   130,
      43,    49,   134,    23,    30,   118,    89,    19,    20,   112,
      21,    26,    20,   107,    21,    56,   114,   115,   118,   118,
      79,   136,   118,   114,    75,   118,     7,    16,    24,    27,
      81,   118,    19,    91,    93,   118,   118,   120,   121,   124,
     125,   126,   127,   128,   128,   129,   129,   131,   131,    79,
     118,    57,   101,    97,    19,    34,    73,   116,    21,   113,
     114,    19,    21,    24,    56,    79,   108,   109,    19,    22,
      21,    23,     6,    26,    21,    21,     6,    82,    92,   116,
      20,   100,    19,   116,    35,    21,    23,   116,    19,    21,
      23,   103,    81,   115,   118,   118,    19,   118,    19,   116,
      72,   117,    81,   109,   116,   104,   116,    21,    23,   116,
       0,    36,    72,    19,   118,   105,    21,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      78,    78,    79,    80,    80,    81,    81,    81,    81,    82,
      83,    84,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    89,    88,    90,    90,    92,    91,    93,
      94,    94,    96,    97,    95,    98,    98,   100,    99,   101,
     101,   103,   102,   104,   105,   102,   106,   107,   107,   108,
     108,   109,   109,   109,   110,   110,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   116,   116,   116,   117,
     117,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     128,   128,   128,   129,   129,   130,   131,   131,   131,   131,
     132,   132,   133,   133,   133,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   137,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       3,     1,     1,     3,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     0,     5,     2,     1,     0,     5,     3,
       1,     2,     0,     0,     6,     1,     2,     0,     7,     6,
       4,     0,     6,     0,     0,     9,     1,     2,     3,     3,
       1,     3,     1,     1,     5,     4,     1,     2,     3,     2,
       1,     3,     1,     1,     3,     1,     1,     4,     4,     2,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     2,     2,     2,     1,
       3,     1,     2,     1,     2,     4,     4,     2,     1,     3,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     2,     3,     1
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
  case 16: /* expr_stmt: dec_name annassign  */
#line 270 "parser.y"
                    {string c=convert((yyvsp[-1].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c); 
                    update_table((yyvsp[-1].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-1].attributes).line);
                    if((yyvsp[0].attributes).type==7){
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_type=(yyvsp[0].attributes).list_type;
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_number=(yyvsp[0].attributes).count;
                    }
                    if((yyvsp[-1].attributes).type==1)table[curr_class][(yyvsp[-1].attributes).lexeme]=table[curr_func][(yyvsp[-1].attributes).lexeme];
                }
#line 1682 "parser.tab.c"
    break;

  case 17: /* expr_stmt: test AUGASSIGNMENT_OPERATOR test  */
#line 278 "parser.y"
                                  {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 1688 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: test ASSIGNMENT_OPERATOR test  */
#line 283 "parser.y"
                              {string c=convert((yyvsp[-2].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;
                                    if((yyvsp[-2].attributes).type==7){
                                        int list_type=get_listtype((yyvsp[-2].attributes).lexeme);
                                        if(!check_type(list_type,(yyvsp[0].attributes).type))return 0;
                                        if(get_listnumber((yyvsp[-2].attributes).lexeme)!=(yyvsp[0].attributes).count){yyerror("type");return 0;}
                                    }else{
                                        if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=(yyvsp[-2].attributes).type;
                                    }
                                }
#line 1702 "parser.tab.c"
    break;

  case 20: /* dec_name: SELF DOT name  */
#line 293 "parser.y"
                                  {(yyval.attributes).type=1;(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).line=(yyvsp[0].attributes).line;if(!is_self){yyerror("type");return 0;}}
#line 1708 "parser.tab.c"
    break;

  case 21: /* dec_name: name  */
#line 294 "parser.y"
      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).line=(yyvsp[0].attributes).line;}
#line 1714 "parser.tab.c"
    break;

  case 22: /* name: NAME  */
#line 296 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size()]; strcpy((yyval.attributes).reg, c.c_str()); (yyval.attributes).line=yylineno;}
#line 1720 "parser.tab.c"
    break;

  case 23: /* annassign: COLON data_type param_list  */
#line 300 "parser.y"
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
#line 1735 "parser.tab.c"
    break;

  case 24: /* annassign: COLON data_type  */
#line 310 "parser.y"
                            {(yyval.attributes).type=(yyvsp[0].attributes).type;if((yyvsp[0].attributes).type==8)(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1741 "parser.tab.c"
    break;

  case 25: /* data_type: DATA_TYPE  */
#line 312 "parser.y"
                     {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);}
#line 1747 "parser.tab.c"
    break;

  case 26: /* data_type: LIST  */
#line 313 "parser.y"
      {(yyval.attributes).type=7;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1753 "parser.tab.c"
    break;

  case 27: /* data_type: NONE  */
#line 314 "parser.y"
      {(yyval.attributes).type=0;}
#line 1759 "parser.tab.c"
    break;

  case 28: /* data_type: NAME  */
#line 315 "parser.y"
      {if(check((yyvsp[0].attributes).lexeme)&&get_type((yyvsp[0].attributes).lexeme)!=5)return 0;(yyval.attributes).type=classes_type[(yyvsp[0].attributes).lexeme]; }
#line 1765 "parser.tab.c"
    break;

  case 29: /* param_list: ASSIGNMENT_OPERATOR test  */
#line 318 "parser.y"
                          {(yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1771 "parser.tab.c"
    break;

  case 32: /* return_stmt: RETURN test  */
#line 329 "parser.y"
                        {if(!check_type(current_func_type,(yyvsp[0].attributes).type))return 0;is_return=1;}
#line 1777 "parser.tab.c"
    break;

  case 33: /* return_stmt: RETURN  */
#line 330 "parser.y"
                    {if(current_func_type!=0||current_func_type==-1){yyerror("type");return 0;}}
#line 1783 "parser.tab.c"
    break;

  case 39: /* if_stmt: if_test  */
#line 343 "parser.y"
         {fill(code.size()+1,1);}
#line 1789 "parser.tab.c"
    break;

  case 40: /* if_stmt: if_test else_statement  */
#line 344 "parser.y"
                          {fill(code.size()+1,1);}
#line 1795 "parser.tab.c"
    break;

  case 41: /* if_stmt: if_test elif_statements else_statement  */
#line 345 "parser.y"
                                         {fill(code.size()+1,(yyvsp[-1].attributes).jump+1);}
#line 1801 "parser.tab.c"
    break;

  case 42: /* if_stmt: if_test elif_statements  */
#line 346 "parser.y"
                          {fill(code.size()+1,(yyvsp[0].attributes).jump+1);}
#line 1807 "parser.tab.c"
    break;

  case 43: /* $@1: %empty  */
#line 350 "parser.y"
        {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1813 "parser.tab.c"
    break;

  case 44: /* if_test: IF test $@1 COLON suite  */
#line 350 "parser.y"
                                                                                                                                                                                     {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1819 "parser.tab.c"
    break;

  case 45: /* elif_statements: elif_statements elif_test  */
#line 353 "parser.y"
                          {(yyval.attributes).jump=(yyvsp[-1].attributes).jump+1;}
#line 1825 "parser.tab.c"
    break;

  case 46: /* elif_statements: elif_test  */
#line 354 "parser.y"
            {(yyval.attributes).jump=1;}
#line 1831 "parser.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 358 "parser.y"
          {(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1837 "parser.tab.c"
    break;

  case 48: /* elif_test: ELIF test $@2 COLON suite  */
#line 358 "parser.y"
                                                                                                                                                                                       {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1843 "parser.tab.c"
    break;

  case 52: /* $@3: %empty  */
#line 370 "parser.y"
     {(yyvsp[0].attributes).jump=code.size()+1;}
#line 1849 "parser.tab.c"
    break;

  case 53: /* $@4: %empty  */
#line 370 "parser.y"
                                    {(yyvsp[0].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1855 "parser.tab.c"
    break;

  case 54: /* while_test: WHILE $@3 test $@4 COLON suite  */
#line 370 "parser.y"
                                                                                                                                                                                                                 {string c=code[(yyvsp[-3].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-3].attributes).jump]=c; c="jump line "+to_string((yyvsp[-5].attributes).jump); code.push_back(c);}
#line 1861 "parser.tab.c"
    break;

  case 57: /* $@5: %empty  */
#line 378 "parser.y"
                 {string c=convert((yyvsp[-2].attributes).lexeme); c=c+"="+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyvsp[-3].attributes).jump=code.size()+1; c="r"+to_string(node); node++; c=c+"="+convert((yyvsp[-2].attributes).lexeme); code.push_back(c); c="r"+to_string(node-1); c=c+"="+c+"<"+convert((yyvsp[0].attributes).reg); code.push_back(c); c="if r"+to_string(node-1)+" jump line "+to_string(code.size()+3); code.push_back(c); c="jump line "; code.push_back(c);}
#line 1867 "parser.tab.c"
    break;

  case 58: /* for_test: FOR name IN range $@5 COLON suite  */
#line 378 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                   { fill(code.size()+2,1); string c="jump line "+to_string((yyvsp[-6].attributes).jump); code.push_back(c);}
#line 1873 "parser.tab.c"
    break;

  case 59: /* range: RANGE LEFT_BRACKET test COMMA test RIGHT_BRACKET  */
#line 381 "parser.y"
                                                 {(yyval.attributes).lexeme=(yyvsp[-3].attributes).reg; (yyval.attributes).reg=(yyvsp[-1].attributes).reg;  if((yyvsp[-3].attributes).type!=1||(yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}}
#line 1879 "parser.tab.c"
    break;

  case 60: /* range: RANGE LEFT_BRACKET test RIGHT_BRACKET  */
#line 382 "parser.y"
                                        {string c="0"; (yyval.attributes).lexeme=new char[c.size()+1]; strcpy((yyval.attributes).lexeme, c.c_str()); (yyval.attributes).reg=(yyvsp[-1].attributes).reg;  if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}}
#line 1885 "parser.tab.c"
    break;

  case 61: /* $@6: %empty  */
#line 386 "parser.y"
                               {
                                current_func_type=0; 
                                string c=""; code.push_back(c); c=convert((yyvsp[-2].attributes).lexeme);
                                c=c+" :"; code.push_back(c); 
                                for(auto x : (yyvsp[-1].attributes).other->types){
                                    c="r"+to_string(node); node++;
                                    c=c+"=popparameter";
                                    code.push_back(c);
                                }
                                (yyvsp[-3].attributes).jump=code.size();
                                (yyvsp[0].attributes).jump=node-1;
                                }
#line 1902 "parser.tab.c"
    break;

  case 62: /* funcdef: DEF func_name parameters COLON $@6 suite  */
#line 398 "parser.y"
                                     {
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        update_table((yyvsp[-4].attributes).lexeme,6,(yyvsp[-4].attributes).line);
                                        copy_content((yyvsp[-4].attributes).lexeme);
                                        table[curr_func][(yyvsp[-4].attributes).lexeme].func_parameter=((yyvsp[-3].attributes).other)->types;
                                        table[curr_func][(yyvsp[-4].attributes).lexeme].funct_return_type=0;
                                        curr_func="global";
                                        current_func_type=-1;
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        int i=0;
                                        for(auto x : (yyvsp[-3].attributes).other->lexemes){
                                            c="r"+to_string((yyvsp[-2].attributes).jump-i); 
                                            find_and_replace(x,c,(yyvsp[-5].attributes).jump,code.size());
                                            i++;
                                        }
                                        c=""; code.push_back(c);
                                    }
#line 1927 "parser.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 418 "parser.y"
                                                 {current_func_type=(yyvsp[0].attributes).type;  }
#line 1933 "parser.tab.c"
    break;

  case 64: /* $@8: %empty  */
#line 418 "parser.y"
                                                                                     {
                                string c=""; code.push_back(c); c=convert((yyvsp[-5].attributes).lexeme);
                                c=c+" :"; code.push_back(c); 
                                for(auto x : (yyvsp[-4].attributes).other->types){
                                    c="r"+to_string(node); node++;
                                    c=c+"=popparameter";
                                    code.push_back(c);
                                }
                                (yyvsp[-6].attributes).jump=code.size();
                                (yyvsp[-3].attributes).jump=node-1;
                                }
#line 1949 "parser.tab.c"
    break;

  case 65: /* funcdef: DEF func_name parameters RETURN_ARROW data_type $@7 COLON $@8 suite  */
#line 429 "parser.y"
                                      {
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        update_table((yyvsp[-7].attributes).lexeme,6,(yyvsp[-7].attributes).line);
                                        copy_content((yyvsp[-7].attributes).lexeme);
                                        table[curr_func][(yyvsp[-7].attributes).lexeme].func_parameter=((yyvsp[-6].attributes).other)->types;
                                        table[curr_func][(yyvsp[-7].attributes).lexeme].funct_return_type=(yyvsp[-4].attributes).type;
                                        curr_func="global";
                                        current_func_type=-1;
                                        if(!is_return && (yyvsp[-4].attributes).type){yyerror("type");return 0;}
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        int i=0;
                                        for(auto x : (yyvsp[-6].attributes).other->lexemes){
                                            c="r"+to_string((yyvsp[-5].attributes).jump-i); 
                                            find_and_replace(x,c,(yyvsp[-8].attributes).jump,code.size());
                                            i++;
                                        }
                                        c=""; code.push_back(c);
                                    }
#line 1975 "parser.tab.c"
    break;

  case 66: /* func_name: name  */
#line 451 "parser.y"
              {curr_func=(yyvsp[0].attributes).lexeme;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1981 "parser.tab.c"
    break;

  case 67: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 453 "parser.y"
                                         {(yyval.attributes).other=new other;}
#line 1987 "parser.tab.c"
    break;

  case 68: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 454 "parser.y"
                                            {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 1993 "parser.tab.c"
    break;

  case 69: /* typedargslist: typedargslist COMMA full_tfpdef  */
#line 458 "parser.y"
                                {(yyval.attributes).other=(yyvsp[-2].attributes).other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme);}
#line 1999 "parser.tab.c"
    break;

  case 70: /* typedargslist: full_tfpdef  */
#line 459 "parser.y"
              {(yyval.attributes).other=new other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme);}
#line 2005 "parser.tab.c"
    break;

  case 71: /* full_tfpdef: name COLON data_type  */
#line 463 "parser.y"
                                {(yyval.attributes).lexeme=strdup((yyvsp[-2].attributes).lexeme); update_table((yyvsp[-2].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-2].attributes).line);(yyval.attributes).type=(yyvsp[0].attributes).type;if((yyval.attributes).type==7)table[curr_func][(yyvsp[-2].attributes).lexeme].list_type=typelist((yyvsp[0].attributes).lexeme);}
#line 2011 "parser.tab.c"
    break;

  case 72: /* full_tfpdef: NAME  */
#line 464 "parser.y"
                  {(yyval.attributes).lexeme=strdup((yyvsp[0].attributes).lexeme);}
#line 2017 "parser.tab.c"
    break;

  case 73: /* full_tfpdef: SELF  */
#line 465 "parser.y"
      {(yyval.attributes).type=0;is_self=1;}
#line 2023 "parser.tab.c"
    break;

  case 74: /* classdef: CLASS class_name opt_class_arg COLON suite  */
#line 470 "parser.y"
                                             {update_table((yyvsp[-3].attributes).lexeme,5,(yyvsp[-3].attributes).line);curr_class="None";}
#line 2029 "parser.tab.c"
    break;

  case 75: /* classdef: CLASS class_name COLON suite  */
#line 471 "parser.y"
                                {update_table((yyvsp[-2].attributes).lexeme,5,(yyvsp[-2].attributes).line);curr_class="None";}
#line 2035 "parser.tab.c"
    break;

  case 76: /* class_name: name  */
#line 473 "parser.y"
               {curr_class=(yyvsp[0].attributes).lexeme;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;update_class_type(curr_class);}
#line 2041 "parser.tab.c"
    break;

  case 78: /* opt_class_arg: LEFT_BRACKET opt_arglist RIGHT_BRACKET  */
#line 477 "parser.y"
                                         {add_classes(curr_class,((yyvsp[-1].attributes).other)->lexemes);}
#line 2047 "parser.tab.c"
    break;

  case 79: /* opt_arglist: arglist COMMA  */
#line 481 "parser.y"
                           {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 2053 "parser.tab.c"
    break;

  case 80: /* opt_arglist: arglist  */
#line 482 "parser.y"
                     {(yyval.attributes).other=(yyvsp[0].attributes).other;}
#line 2059 "parser.tab.c"
    break;

  case 81: /* arglist: arglist COMMA argument  */
#line 486 "parser.y"
                                  {(yyval.attributes).other=(yyvsp[-2].attributes).other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2065 "parser.tab.c"
    break;

  case 82: /* arglist: argument  */
#line 487 "parser.y"
                      {(yyval.attributes).other=new other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2071 "parser.tab.c"
    break;

  case 83: /* argument: test  */
#line 491 "parser.y"
       {(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 2077 "parser.tab.c"
    break;

  case 84: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 492 "parser.y"
                                {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 2083 "parser.tab.c"
    break;

  case 85: /* argument: SELF  */
#line 493 "parser.y"
       {(yyval.attributes).type=0;(yyval.attributes).reg=(char*)"self";}
#line 2089 "parser.tab.c"
    break;

  case 91: /* test: or_test  */
#line 508 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2095 "parser.tab.c"
    break;

  case 92: /* or_test: or_test OR and_test  */
#line 511 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"or"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2101 "parser.tab.c"
    break;

  case 93: /* or_test: and_test  */
#line 512 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2107 "parser.tab.c"
    break;

  case 94: /* and_test: and_test AND not_test  */
#line 515 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"and"+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2113 "parser.tab.c"
    break;

  case 95: /* and_test: not_test  */
#line 516 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2119 "parser.tab.c"
    break;

  case 96: /* not_test: NOT not_test  */
#line 519 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+"=""not"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3)){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2125 "parser.tab.c"
    break;

  case 97: /* not_test: comparison  */
#line 520 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2131 "parser.tab.c"
    break;

  case 98: /* comparison: comparison r_o expr  */
#line 523 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=3;}
#line 2137 "parser.tab.c"
    break;

  case 99: /* comparison: expr  */
#line 524 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2143 "parser.tab.c"
    break;

  case 100: /* r_o: RELATIONAL_OPERATOR  */
#line 527 "parser.y"
                         {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 2149 "parser.tab.c"
    break;

  case 101: /* expr: expr BIT_OR xor_expr  */
#line 530 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"|"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2155 "parser.tab.c"
    break;

  case 102: /* expr: xor_expr  */
#line 531 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2161 "parser.tab.c"
    break;

  case 103: /* xor_expr: xor_expr XOR and_expr  */
#line 534 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"^"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2167 "parser.tab.c"
    break;

  case 104: /* xor_expr: and_expr  */
#line 535 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2173 "parser.tab.c"
    break;

  case 105: /* and_expr: and_expr BIT_AND shift_expr  */
#line 538 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"&"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2179 "parser.tab.c"
    break;

  case 106: /* and_expr: shift_expr  */
#line 539 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2185 "parser.tab.c"
    break;

  case 107: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 542 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"<<"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2191 "parser.tab.c"
    break;

  case 108: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 543 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+">>"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2197 "parser.tab.c"
    break;

  case 109: /* shift_expr: arith_expr  */
#line 544 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2203 "parser.tab.c"
    break;

  case 110: /* arith_expr: arith_expr ADD term  */
#line 548 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 2209 "parser.tab.c"
    break;

  case 111: /* arith_expr: arith_expr SUB term  */
#line 549 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+convert((yyvsp[-2].attributes).reg)+"-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>3)yyerror("type");if(type<1||type>3)return 0;(yyval.attributes).type=type;}
#line 2215 "parser.tab.c"
    break;

  case 112: /* arith_expr: term  */
#line 550 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2221 "parser.tab.c"
    break;

  case 113: /* term: term a_o factor  */
#line 553 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+convert((yyvsp[-1].attributes).reg)+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if((yyvsp[-1].attributes).lexeme!="//"){(yyval.attributes).type=type;}else (yyval.attributes).type=1;  }
#line 2227 "parser.tab.c"
    break;

  case 114: /* term: factor  */
#line 554 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2233 "parser.tab.c"
    break;

  case 115: /* a_o: ARITHMETIC_OPERATOR  */
#line 556 "parser.y"
                          {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; }
#line 2239 "parser.tab.c"
    break;

  case 116: /* factor: ADD factor  */
#line 560 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""+"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2245 "parser.tab.c"
    break;

  case 117: /* factor: SUB factor  */
#line 561 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+"=""-"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2251 "parser.tab.c"
    break;

  case 118: /* factor: BIT_NOT factor  */
#line 562 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+"=""~"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type<1||(yyvsp[0].attributes).type>3){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2257 "parser.tab.c"
    break;

  case 119: /* factor: power  */
#line 563 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2263 "parser.tab.c"
    break;

  case 120: /* power: atom_expr POWER factor  */
#line 567 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+"="+c+"**"+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;(yyval.attributes).type=type;}
#line 2269 "parser.tab.c"
    break;

  case 121: /* power: atom_expr  */
#line 568 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2275 "parser.tab.c"
    break;

  case 122: /* atom_expr: atom opt_trailer  */
#line 572 "parser.y"
                            { 
                              if(get_type((yyvsp[-1].attributes).lexeme)==7){
                                string c=convert((yyvsp[-1].attributes).lexeme); c+=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="r"+to_string(node); node++;
                                (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());  c=c+"="+convert((yyvsp[-1].attributes).lexeme)+convert((yyvsp[0].attributes).lexeme); code.push_back(c); 
                                if((yyvsp[0].attributes).list_type!=1){yyerror("type");return 0;}
                                (yyval.attributes).type=get_listtype((yyvsp[-1].attributes).lexeme);
                              }
                              else{
                                if((yyvsp[0].attributes).list_type==1){yyerror("type");return 0;}
                                if((yyvsp[-1].attributes).type==6){
                                    if(!match_vector(get_func_parameter((yyvsp[-1].attributes).lexeme),(yyvsp[0].attributes).other->types)){return 0;}
                                    for(auto x: (yyvsp[0].attributes).other->regs){
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                    string c= "call ";
                                    c=c+convert((yyvsp[-1].attributes).lexeme)+",1";
                                    code.push_back(c);
                                    (yyval.attributes).type=get_funct_type((yyvsp[-1].attributes).lexeme);
                                    if((yyval.attributes).type){c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());
                                    c=c+"=popparameter"; code.push_back(c);
                                    }
                                }
                                if((yyvsp[-1].attributes).type==5){
                                    if(!(yyvsp[0].attributes).dot){
                                        (yyval.attributes).type=classes_type[(yyvsp[-1].attributes).lexeme];
                                        if(!match_vector(table[(yyvsp[-1].attributes).lexeme]["__init__"].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                    }else{
                                        (yyval.attributes).type=table[(yyvsp[-1].attributes).lexeme][(yyvsp[0].attributes).lexeme].type;
                                        cout<<(yyval.attributes).type<<" "<<(yyvsp[-1].attributes).lexeme<<endl;
                                        if((yyval.attributes).type==6&&!match_vector(table[(yyvsp[-1].attributes).lexeme][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                    }

                                }
                                if((yyvsp[-1].attributes).type>10){
                                    if((yyvsp[0].attributes).dot){
                                        (yyval.attributes).type=table[type_to_class[(yyvsp[-1].attributes).type]][(yyvsp[0].attributes).lexeme].type;
                                        if((yyval.attributes).type==6&&!match_vector(table[type_to_class[(yyvsp[-1].attributes).type]][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                    }
                                }
                              }
                            }
#line 2323 "parser.tab.c"
    break;

  case 123: /* atom_expr: atom  */
#line 615 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2329 "parser.tab.c"
    break;

  case 124: /* atom_expr: SELF opt_trailer  */
#line 617 "parser.y"
                           {if((yyvsp[0].attributes).dot){
                                (yyval.attributes).type=table[curr_class][(yyvsp[0].attributes).lexeme].type;
                                if((yyval.attributes).type==6&&!match_vector(table[curr_class][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                            }
                            if(!is_self){yyerror("type");return 0;}
                }
#line 2340 "parser.tab.c"
    break;

  case 125: /* atom_expr: LEN LEFT_BRACKET test RIGHT_BRACKET  */
#line 623 "parser.y"
                                     {
                                if((yyvsp[-1].attributes).type!=7){yyerror("type");return 0;}
                                (yyval.attributes).type=1;
                                (yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;
                                (yyval.attributes).reg=(yyval.attributes).lexeme;
                            }
#line 2351 "parser.tab.c"
    break;

  case 126: /* atom_expr: PRINT LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 629 "parser.y"
                                         {
                                for(auto x: (yyvsp[-1].attributes).other->regs){
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                string c= "call print,1";
                                code.push_back(c);
                                (yyval.attributes).type=0;
                                (yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;
                                (yyval.attributes).reg=(yyval.attributes).lexeme;
                            }
#line 2368 "parser.tab.c"
    break;

  case 127: /* opt_trailer: opt_trailer trailer  */
#line 644 "parser.y"
                    {(yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;(yyval.attributes).other=(yyvsp[0].attributes).other;(yyval.attributes).list_type=5;(yyval.attributes).dot=(yyvsp[-1].attributes).dot+(yyvsp[0].attributes).dot;}
#line 2374 "parser.tab.c"
    break;

  case 128: /* opt_trailer: trailer  */
#line 645 "parser.y"
           {(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).list_type=(yyvsp[0].attributes).list_type;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).other=(yyvsp[0].attributes).other;(yyval.attributes).dot=(yyvsp[0].attributes).dot;}
#line 2380 "parser.tab.c"
    break;

  case 129: /* atom: LEFT_BRACKET testlist RIGHT_BRACKET  */
#line 649 "parser.y"
                                    {(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;(yyval.attributes).reg=(yyvsp[-1].attributes).reg;}
#line 2386 "parser.tab.c"
    break;

  case 132: /* atom: LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET  */
#line 652 "parser.y"
                                                   {string c="["; c+=convert((yyvsp[-1].attributes).lexeme); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyval.attributes).lexeme); code.push_back(c); (yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;}
#line 2392 "parser.tab.c"
    break;

  case 133: /* atom: NAME  */
#line 653 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;if(check((yyvsp[0].attributes).lexeme))return 0; (yyval.attributes).type=get_type((yyvsp[0].attributes).lexeme);}
#line 2398 "parser.tab.c"
    break;

  case 134: /* atom: INT  */
#line 654 "parser.y"
      {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=1;}
#line 2404 "parser.tab.c"
    break;

  case 135: /* atom: FLOAT  */
#line 655 "parser.y"
        {string c="r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=2;}
#line 2410 "parser.tab.c"
    break;

  case 136: /* atom: DATA_TYPE  */
#line 656 "parser.y"
            {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2416 "parser.tab.c"
    break;

  case 137: /* atom: STRING  */
#line 657 "parser.y"
          {(yyval.attributes).type=4;(yyval.attributes).reg=(yyvsp[0].attributes).lexeme;}
#line 2422 "parser.tab.c"
    break;

  case 138: /* atom: STRING_1  */
#line 658 "parser.y"
           {(yyval.attributes).type=4;}
#line 2428 "parser.tab.c"
    break;

  case 139: /* atom: NONE  */
#line 659 "parser.y"
            {(yyval.attributes).type=0;}
#line 2434 "parser.tab.c"
    break;

  case 140: /* atom: TRUE  */
#line 660 "parser.y"
      {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2440 "parser.tab.c"
    break;

  case 141: /* atom: FALSE  */
#line 661 "parser.y"
       {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2446 "parser.tab.c"
    break;

  case 142: /* atom: LIST  */
#line 662 "parser.y"
      {(yyval.attributes).type=7;}
#line 2452 "parser.tab.c"
    break;

  case 143: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 667 "parser.y"
                                     {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 2458 "parser.tab.c"
    break;

  case 144: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 668 "parser.y"
                              {(yyval.attributes).other=new other;}
#line 2464 "parser.tab.c"
    break;

  case 145: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 669 "parser.y"
                                                 {string c="["; c+=convert((yyvsp[-1].attributes).reg); c+="]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).list_type=1;}
#line 2470 "parser.tab.c"
    break;

  case 146: /* trailer: DOT name  */
#line 670 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).dot=1;}
#line 2476 "parser.tab.c"
    break;

  case 147: /* testlist: testlist COMMA test  */
#line 674 "parser.y"
                    {string c=convert((yyvsp[-2].attributes).lexeme); c=c+","+convert((yyvsp[0].attributes).reg); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); (yyval.attributes).type=(yyvsp[-2].attributes).type;(yyval.attributes).count=(yyvsp[-2].attributes).count+1;(yyval.attributes).reg=(yyvsp[-2].attributes).reg;}
#line 2482 "parser.tab.c"
    break;

  case 148: /* testlist: test  */
#line 675 "parser.y"
       {(yyval.attributes).lexeme=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=1;(yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 2488 "parser.tab.c"
    break;


#line 2492 "parser.tab.c"

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

#line 679 "parser.y"


const char* token_name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}

void yyerror(const char *s){
   cout<<endl;
   if(s=="dec"){cout<<"declaration error"<<endl;}
   if(s=="type"){cout<<"Type error"<<endl;}
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
        cout<<" "<<y.first<<' '<<y.second.line_number<<'\n';
        if(y.second.type==6){
            for(auto it:y.second.func_content){
                cout<<"  "<<it.first<<' '<<it.second.line_number<<'\n';
            }
        }
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
