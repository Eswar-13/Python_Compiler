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
stack<int> curr_for;
int curr_break=0;

string integerToOperator(int value) {
    // Map each integer value to its corresponding operator string
    if (value == 0) {
        return  "+";
    } else if (value == 1) {
        return  "-";
    } else if (value == 2) {
        return  "*";
    } else if (value == 3) {
        return  "/";
    } else if (value == 4) {
        return  "//";
    } else if (value == 5) {
        return  "%";
    } else if (value == 6) {
        return  "**";
    } else if (value == 7) {
        return  "&";
    } else if (value == 8) {
        return  "|";
    } else if (value == 9) {
        return  "^";
    } else if (value == 10) {
        return  "<<";
    } else if (value == 11) {
        return  ">>";
    } else {
        return ""; // Return empty string for invalid integer values
    }
}
class content{
    public:
        int type;
        int list_type;
        int list_number;
        int funct_return_type;
        int size=8;
        string parent_class="None";
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
int check_type(int type1, int type2){
    if(type1>10&&type2>10){
        if(type1==type2)return type1;
        string parent="";
        while(type1!=type2&&parent!="None"){
            parent=table["global"][type_to_class[type2]].parent_class;
            if(parent!="None")type2=classes_type[parent];
            if(type1==type2)return type1;
        }
        yyerror("type");return 0;
    }
    if(type1==type2)return type1;
    else if(type1==1&&type2==3||type1==3&&type2==1)return type1;
    else if(type1==1&&type2==2||type1==2&&type2==1)return type2;
    else {
        yyerror("type");
        return 0;
    }
}
char* convert_to_string(int list_type,int type){
    if(type==1)return (char*)"int";
    if(type==2)return (char*)"float";
    if(type==3)return (char*)"bool";
    if(type==4)return (char*)"str";
    if(type==5)return (char*)"class";
    if(type==6)return (char*)"Function";
    if(type==7){string c="list("+(string)convert_to_string(0,list_type)+")";char* a=new char[c.size() + 1]; strcpy(a, c.c_str());return a;}
    if(type>10){string c=type_to_class[type];char* a=new char[c.size() + 1]; strcpy(a, c.c_str());return a;}
    return (char*)"None";
}
void update_table(string key,int type,int line_number){
    //cout<<curr_func<<" "<<key<<endl;
    table[curr_func][key]=content(type,line_number);
    current_attributes.push(key);
}
bool check(string s){
    // cout<<s<<" "<<curr_func<<endl;
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
void add_class(string target,string input){
    for(auto it:table[input]){
        table[target][it.first]=it.second;
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

#line 302 "parser.tab.c"

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
  YYSYMBOL_111_9 = 111,                    /* $@9  */
  YYSYMBOL_112_10 = 112,                   /* $@10  */
  YYSYMBOL_class_name = 113,               /* class_name  */
  YYSYMBOL_opt_class_arg = 114,            /* opt_class_arg  */
  YYSYMBOL_arglist = 115,                  /* arglist  */
  YYSYMBOL_argument = 116,                 /* argument  */
  YYSYMBOL_suite = 117,                    /* suite  */
  YYSYMBOL_stmt_list = 118,                /* stmt_list  */
  YYSYMBOL_test = 119,                     /* test  */
  YYSYMBOL_or_test = 120,                  /* or_test  */
  YYSYMBOL_and_test = 121,                 /* and_test  */
  YYSYMBOL_not_test = 122,                 /* not_test  */
  YYSYMBOL_comparison = 123,               /* comparison  */
  YYSYMBOL_r_o = 124,                      /* r_o  */
  YYSYMBOL_expr = 125,                     /* expr  */
  YYSYMBOL_xor_expr = 126,                 /* xor_expr  */
  YYSYMBOL_and_expr = 127,                 /* and_expr  */
  YYSYMBOL_shift_expr = 128,               /* shift_expr  */
  YYSYMBOL_arith_expr = 129,               /* arith_expr  */
  YYSYMBOL_term = 130,                     /* term  */
  YYSYMBOL_a_o = 131,                      /* a_o  */
  YYSYMBOL_factor = 132,                   /* factor  */
  YYSYMBOL_power = 133,                    /* power  */
  YYSYMBOL_atom_expr = 134,                /* atom_expr  */
  YYSYMBOL_opt_trailer = 135,              /* opt_trailer  */
  YYSYMBOL_atom = 136,                     /* atom  */
  YYSYMBOL_trailer = 137,                  /* trailer  */
  YYSYMBOL_testlist = 138                  /* testlist  */
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
#define YYLAST   708

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
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
       0,   269,   269,   270,   274,   275,   276,   277,   280,   281,
     285,   286,   290,   291,   292,   293,   297,   306,   312,   316,
     323,   324,   326,   330,   338,   340,   341,   342,   343,   346,
     349,   353,   357,   363,   368,   369,   370,   371,   372,   376,
     377,   378,   379,   383,   383,   386,   387,   391,   391,   394,
     398,   399,   403,   403,   403,   406,   407,   411,   411,   414,
     415,   419,   419,   451,   451,   451,   484,   486,   487,   491,
     492,   496,   497,   498,   503,   503,   516,   516,   528,   531,
     532,   536,   537,   541,   542,   543,   547,   548,   549,   552,
     553,   556,   559,   560,   563,   564,   567,   568,   571,   572,
     575,   578,   579,   582,   583,   586,   587,   590,   591,   592,
     596,   597,   598,   601,   602,   604,   608,   609,   610,   611,
     615,   616,   620,   711,   713,   723,   735,   754,   755,   759,
     760,   761,   762,   773,   774,   775,   776,   777,   778,   779,
     780,   781,   782,   787,   788,   789,   790,   794,   795
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
  "typedargslist", "full_tfpdef", "classdef", "$@9", "$@10", "class_name",
  "opt_class_arg", "arglist", "argument", "suite", "stmt_list", "test",
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

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     275,  -169,    16,  -169,   575,  -169,    16,  -169,  -169,   413,
      39,   450,  -169,  -169,  -169,    16,   575,   575,  -169,   649,
     649,   649,  -169,  -169,  -169,  -169,     7,    45,    49,   222,
    -169,  -169,    64,  -169,  -169,  -169,    65,  -169,  -169,  -169,
    -169,  -169,  -169,    27,  -169,    73,  -169,    73,  -169,  -169,
      17,    50,    52,  -169,    86,    48,    57,    53,    23,    34,
      96,  -169,  -169,    59,    11,    77,  -169,    71,   575,  -169,
      11,  -169,  -169,    58,  -169,  -169,     5,  -169,    24,  -169,
      83,  -169,  -169,  -169,  -169,  -169,   494,   575,    16,    11,
    -169,   575,   612,  -169,  -169,   369,    18,  -169,   575,    85,
      27,  -169,  -169,  -169,  -169,   575,   575,   575,   575,  -169,
     649,   649,   649,   649,   649,   649,   649,   649,  -169,   649,
     649,    16,    11,   575,    51,  -169,    88,  -169,   538,    90,
    -169,  -169,    -2,    29,  -169,    11,    32,  -169,   104,    89,
      92,  -169,    91,    36,  -169,    17,  -169,  -169,  -169,  -169,
     110,  -169,   322,  -169,  -169,  -169,  -169,    52,  -169,    48,
      57,    53,    23,    34,    34,    96,    96,  -169,  -169,  -169,
    -169,    97,  -169,    99,   322,   322,  -169,    98,  -169,  -169,
      39,  -169,   101,    40,  -169,  -169,    18,  -169,   612,   575,
    -169,  -169,  -169,   575,  -169,   102,    87,  -169,  -169,   575,
     105,   322,  -169,  -169,  -169,   322,    18,  -169,    -4,   322,
    -169,  -169,  -169,  -169,   322,   275,    43,   322,  -169,  -169,
    -169,  -169,  -169,   106,  -169,  -169,   126,  -169,   575,  -169,
    -169,  -169,  -169,  -169,   108,   322,  -169,  -169
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
       0,    43,    78,     0,   130,   148,     0,   131,     0,    66,
       0,    96,    32,   118,   116,   117,     0,     0,     0,   124,
     128,     0,     0,     1,     2,     9,     0,    16,     0,     0,
      42,    46,    40,    51,    56,     0,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,   122,     0,     0,    53,     0,    76,     0,     0,
     129,   132,     0,     0,   144,    85,     0,    82,    83,     0,
     146,   127,     0,     0,    10,     0,    25,    26,    28,    27,
      24,    47,     0,    45,    41,    19,    17,    92,    94,    98,
     101,   103,   105,   107,   108,   110,   111,   113,   120,   146,
     147,     0,    57,     0,     0,     0,    79,     0,    74,    67,
      72,    73,     0,     0,    70,    61,     0,   143,     0,     0,
     145,   125,   126,     0,    23,     0,     0,    86,    49,     0,
       0,     0,    44,    77,    80,     0,     0,    68,     0,     0,
      63,    81,    84,    29,     0,     0,     0,     0,    54,    75,
      71,    69,    62,     0,    48,    90,     0,    60,     0,    58,
      64,    88,    87,    89,     0,     0,    59,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   -24,     1,  -169,    35,  -169,  -169,  -169,     6,
    -169,  -162,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,    31,  -169,   -29,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   -76,
    -169,  -169,  -169,  -169,  -169,    55,  -126,  -168,  -169,     0,
    -169,    30,   -13,  -169,  -169,    33,    37,    44,    56,   -35,
     -34,  -169,    -6,  -169,  -169,    80,  -169,   -79,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    29,    30,   197,    32,    33,    34,    35,    36,    37,
      97,   150,   194,    38,    39,    40,    41,    42,    43,   126,
     100,   101,   195,   102,    44,    45,    68,   173,    46,    47,
     200,   172,    48,   209,   223,   235,    80,   133,   183,   184,
      49,   205,   175,    73,   129,   136,   137,   198,   226,   145,
      51,    52,    53,    54,   110,    55,    56,    57,    58,    59,
      60,   119,    61,    62,    63,    89,    64,    90,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    31,   177,    81,    71,    94,   202,   203,    67,    75,
     141,    75,    72,    83,    84,    85,   103,    82,   104,   179,
     180,    79,   180,   105,   210,   146,   130,    86,   123,    50,
      31,    86,    87,   218,   147,   106,    87,   219,    98,    99,
      66,   222,   148,   141,   220,   149,   224,   123,   185,   229,
     131,   186,   181,   187,   181,   188,    88,   192,   -22,   188,
     121,   207,   211,   208,   227,    91,   228,   237,   125,    92,
      76,   154,    78,   114,   115,   116,   117,   127,   128,   163,
     164,    95,   165,   166,    96,    99,   138,   139,   107,   108,
     109,   142,   138,   111,   140,   158,   112,   113,   151,   118,
     123,   124,   120,   132,   152,   155,   156,   174,   171,   178,
     189,   -20,   191,   167,   168,   190,   193,   199,   201,   204,
     206,   214,   215,   170,   217,   230,   231,   169,   138,   236,
     144,   153,   221,     1,     2,     3,     4,   157,   182,     5,
       6,     7,     8,   159,   122,     0,     9,   143,   160,     0,
      10,    11,     0,    12,    13,    14,   161,    15,    16,    17,
      18,     0,   232,     0,     0,     0,    19,    20,    21,   162,
       0,     0,    22,    23,    24,     0,     0,     0,    25,     0,
       0,     0,    26,     0,    27,    28,     0,     0,   138,   212,
       0,   225,     0,   213,     0,     0,     0,     0,     0,   216,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,    50,    31,     0,     0,     0,
       0,     0,    93,     0,     0,     0,    50,    31,   234,     1,
       2,     3,     4,     0,     0,     5,     6,     7,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,     0,    15,    16,    17,    18,     0,     0,     0,
       0,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,    25,     0,     0,     0,    26,     0,
      27,    28,     1,     2,     3,     4,     0,     0,     5,     6,
       7,     8,     0,     0,     0,     9,     0,     0,     0,    10,
      11,     0,    12,    13,    14,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    19,    20,    21,     0,     0,
       0,    22,    23,    24,     0,     0,     0,    25,     0,     1,
       0,    26,     0,    27,    28,     5,     0,     7,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,     0,     0,    16,    17,   196,     0,     0,     0,
       0,     0,    19,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,    25,     0,     1,     0,    26,     0,
      27,    28,     5,     0,     7,     8,     0,     0,     0,     9,
       0,     0,     0,    10,    11,     0,    12,    13,    14,     0,
       0,    16,    17,     0,     0,     0,     0,     0,     0,    19,
      20,    21,     0,     0,     0,    22,    23,    24,     0,     0,
       1,    25,     0,     0,     0,    26,     0,    27,    28,     8,
       0,     0,     0,     9,    74,     0,     0,    69,    11,     0,
      12,    13,    14,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     1,     0,    22,
      23,    24,     0,     0,     0,    25,     8,     0,     0,    70,
       9,    27,    28,     0,    69,    11,    77,    12,    13,    14,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      19,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     1,    25,     0,     0,     0,    70,     0,    27,    28,
       8,     0,     0,     0,     9,   134,     0,     0,    69,    11,
       0,    12,    13,    14,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,    19,    20,    21,     0,     0,     0,
      22,    23,    24,     0,     0,     1,    25,     0,     0,     0,
     135,     0,    27,    28,     8,     0,     0,     0,     9,   176,
       0,     0,    69,    11,     0,    12,    13,    14,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      21,     0,     1,     0,    22,    23,    24,     0,     0,     0,
      25,     8,     0,     0,   135,     9,    27,    28,     0,    69,
      11,     0,    12,    13,    14,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,     0,     1,
       0,    22,    23,    24,     0,     0,     0,    25,     8,     0,
       0,    70,     9,    27,    28,     0,    69,    11,     0,    12,
      13,    14,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,    19,    20,    21,     0,     1,     0,    22,    23,
      24,     0,     0,     0,    25,     8,     0,     0,   135,     9,
      27,    28,     0,    69,    11,     0,    12,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,     0,     0,     0,    22,    23,    24,     0,     0,
       0,    25,     0,     0,     0,    70,     0,    27,    28
};

static const yytype_int16 yycheck[] =
{
       0,     0,   128,    16,     4,    29,   174,   175,     2,     9,
      89,    11,     6,    19,    20,    21,    45,    17,    47,    21,
      24,    15,    24,     6,   186,     7,    21,    20,    23,    29,
      29,    20,    25,   201,    16,    18,    25,   205,    11,    12,
      24,   209,    24,   122,   206,    27,   214,    23,    19,   217,
      26,    22,    56,    21,    56,    23,    49,    21,    19,    23,
      49,    21,   188,    23,    21,    20,    23,   235,    68,    20,
       9,   100,    11,    50,    51,    41,    42,    19,    20,   114,
     115,    17,   116,   117,    19,    12,    86,    87,    38,    37,
       4,    91,    92,    45,    88,   108,    39,    44,    98,     3,
      23,    30,    43,    20,    19,   105,   106,    19,    57,    19,
       6,    19,    21,   119,   120,    26,     6,    20,    19,    21,
      19,    19,    35,   123,    19,    19,     0,   121,   128,    21,
      95,   100,   208,     7,     8,     9,    10,   107,   132,    13,
      14,    15,    16,   110,    64,    -1,    20,    92,   111,    -1,
      24,    25,    -1,    27,    28,    29,   112,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    40,    41,    42,   113,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    -1,   188,   189,
      -1,   215,    -1,   193,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   215,   215,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,   226,   226,   228,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    52,    -1,    -1,    -1,    56,    -1,
      58,    59,     7,     8,     9,    10,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    52,    -1,     7,
      -1,    56,    -1,    58,    59,    13,    -1,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    52,    -1,     7,    -1,    56,    -1,
      58,    59,    13,    -1,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
       7,    52,    -1,    -1,    -1,    56,    -1,    58,    59,    16,
      -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,     7,    -1,    46,
      47,    48,    -1,    -1,    -1,    52,    16,    -1,    -1,    56,
      20,    58,    59,    -1,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,     7,    52,    -1,    -1,    -1,    56,    -1,    58,    59,
      16,    -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,     7,    52,    -1,    -1,    -1,
      56,    -1,    58,    59,    16,    -1,    -1,    -1,    20,    21,
      -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,     7,    -1,    46,    47,    48,    -1,    -1,    -1,
      52,    16,    -1,    -1,    56,    20,    58,    59,    -1,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,     7,
      -1,    46,    47,    48,    -1,    -1,    -1,    52,    16,    -1,
      -1,    56,    20,    58,    59,    -1,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,     7,    -1,    46,    47,
      48,    -1,    -1,    -1,    52,    16,    -1,    -1,    56,    20,
      58,    59,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59
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
     119,   120,   121,   122,   123,   125,   126,   127,   128,   129,
     130,   132,   133,   134,   136,   138,    24,    79,    96,    24,
      56,   119,    79,   113,    21,   119,   138,    26,   138,    79,
     106,   122,   119,   132,   132,   132,    20,    25,    49,   135,
     137,    20,    20,     0,    72,    17,    19,    80,    11,    12,
      90,    91,    93,    93,    93,     6,    18,    38,    37,     4,
     124,    45,    39,    44,    50,    51,    41,    42,     3,   131,
      43,    49,   135,    23,    30,   119,    89,    19,    20,   114,
      21,    26,    20,   107,    21,    56,   115,   116,   119,   119,
      79,   137,   119,   115,    75,   119,     7,    16,    24,    27,
      81,   119,    19,    91,    93,   119,   119,   121,   122,   125,
     126,   127,   128,   129,   129,   130,   130,   132,   132,    79,
     119,    57,   101,    97,    19,   112,    21,   116,    19,    21,
      24,    56,    79,   108,   109,    19,    22,    21,    23,     6,
      26,    21,    21,     6,    82,    92,    34,    73,   117,    20,
     100,    19,   117,   117,    21,   111,    19,    21,    23,   103,
      81,   116,   119,   119,    19,    35,   119,    19,   117,   117,
      81,   109,   117,   104,   117,    72,   118,    21,    23,   117,
      19,     0,    36,    72,   119,   105,    21,   117
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
     108,   109,   109,   109,   111,   110,   112,   110,   113,   114,
     114,   115,   115,   116,   116,   116,   117,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     129,   129,   129,   130,   130,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   137,   137,   138,   138
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
       1,     3,     1,     1,     0,     6,     0,     5,     1,     2,
       3,     3,     1,     1,     3,     1,     1,     4,     4,     2,
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
#line 297 "parser.y"
                    {string c=convert((yyvsp[-1].attributes).lexeme); c=c+" = "+convert((yyvsp[0].attributes).reg); code.push_back(c); 
                    update_table((yyvsp[-1].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-1].attributes).line);
                    if((yyvsp[0].attributes).type==7){
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_type=(yyvsp[0].attributes).list_type;
                        table[curr_func][(yyvsp[-1].attributes).lexeme].list_number=(yyvsp[0].attributes).count;
                        table[curr_func][(yyvsp[-1].attributes).lexeme].size=((yyvsp[0].attributes).count)*8;
                    }
                    if((yyvsp[-1].attributes).type==1)table[curr_class][(yyvsp[-1].attributes).lexeme]=table[curr_func][(yyvsp[-1].attributes).lexeme];
                }
#line 1713 "parser.tab.c"
    break;

  case 17: /* expr_stmt: test AUGASSIGNMENT_OPERATOR test  */
#line 306 "parser.y"
                                  {
    if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;
    string c=convert((yyvsp[-2].attributes).lexeme)+ " = "+convert((yyvsp[-2].attributes).reg);
    c=c+" "+integerToOperator((yyvsp[-1].attributes).top)+" "+convert((yyvsp[0].attributes).reg);
    code.push_back(c);
    }
#line 1724 "parser.tab.c"
    break;

  case 19: /* Assign_stmt: test ASSIGNMENT_OPERATOR test  */
#line 316 "parser.y"
                              {string c=convert((yyvsp[-2].attributes).lexeme); c=c+" = "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=(yyvsp[-2].attributes).type;
                                    if((yyvsp[-2].attributes).type==7){
                                        if(!check_type((yyvsp[-2].attributes).list_type,(yyvsp[0].attributes).list_type))return 0;

                                    }
                                }
#line 1735 "parser.tab.c"
    break;

  case 20: /* dec_name: SELF DOT name  */
#line 323 "parser.y"
                                  {(yyval.attributes).type=1;(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;string c = "self.";c=c+convert((yyvsp[0].attributes).lexeme);(yyval.attributes).lexeme=new char[c.size()]; strcpy((yyval.attributes).lexeme, c.c_str());(yyval.attributes).line=(yyvsp[0].attributes).line;if(!is_self){yyerror("type");return 0;}}
#line 1741 "parser.tab.c"
    break;

  case 21: /* dec_name: name  */
#line 324 "parser.y"
      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).line=(yyvsp[0].attributes).line;}
#line 1747 "parser.tab.c"
    break;

  case 22: /* name: NAME  */
#line 326 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size()]; strcpy((yyval.attributes).reg, c.c_str()); (yyval.attributes).line=yylineno;}
#line 1753 "parser.tab.c"
    break;

  case 23: /* annassign: COLON data_type param_list  */
#line 330 "parser.y"
                                     {  (yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).type=(yyvsp[-1].attributes).type;if(!check_type((yyvsp[-1].attributes).type,(yyvsp[0].attributes).type))return 0;
                                        if((yyvsp[-1].attributes).type==7){
                                            int list_type=typelist((yyvsp[-1].attributes).lexeme);
                                            (yyval.attributes).list_type=list_type;
                                            if(!check_type(list_type,(yyvsp[0].attributes).list_type))return 0;
                                            (yyval.attributes).count=(yyvsp[0].attributes).count;
                                        }
                                    }
#line 1766 "parser.tab.c"
    break;

  case 24: /* annassign: COLON data_type  */
#line 338 "parser.y"
                            {(yyval.attributes).type=(yyvsp[0].attributes).type;if((yyvsp[0].attributes).type==8)(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1772 "parser.tab.c"
    break;

  case 25: /* data_type: DATA_TYPE  */
#line 340 "parser.y"
                     {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);}
#line 1778 "parser.tab.c"
    break;

  case 26: /* data_type: LIST  */
#line 341 "parser.y"
      {(yyval.attributes).type=7;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 1784 "parser.tab.c"
    break;

  case 27: /* data_type: NONE  */
#line 342 "parser.y"
      {(yyval.attributes).type=0;}
#line 1790 "parser.tab.c"
    break;

  case 28: /* data_type: NAME  */
#line 343 "parser.y"
      {if(check((yyvsp[0].attributes).lexeme)&&get_type((yyvsp[0].attributes).lexeme)!=5)return 0;(yyval.attributes).type=classes_type[(yyvsp[0].attributes).lexeme]; }
#line 1796 "parser.tab.c"
    break;

  case 29: /* param_list: ASSIGNMENT_OPERATOR test  */
#line 346 "parser.y"
                          {(yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).list_type=(yyvsp[0].attributes).list_type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 1802 "parser.tab.c"
    break;

  case 30: /* break_stmt: BREAK  */
#line 349 "parser.y"
       {code.push_back("jump line "); curr_break++;}
#line 1808 "parser.tab.c"
    break;

  case 31: /* continue_stmt: CONTINUE  */
#line 353 "parser.y"
          {code.push_back("jump line "+to_string(curr_for.top()));}
#line 1814 "parser.tab.c"
    break;

  case 32: /* return_stmt: RETURN test  */
#line 357 "parser.y"
                        {
    if(!check_type(current_func_type,(yyvsp[0].attributes).type))return 0;is_return=1;
    string c="push "+convert((yyvsp[0].attributes).reg);
    code.push_back(c);
    code.push_back("return");
}
#line 1825 "parser.tab.c"
    break;

  case 33: /* return_stmt: RETURN  */
#line 363 "parser.y"
                    {if(current_func_type!=0||current_func_type==-1){yyerror("type");return 0;}}
#line 1831 "parser.tab.c"
    break;

  case 39: /* if_stmt: if_test  */
#line 376 "parser.y"
         {fill(code.size()+1,1);}
#line 1837 "parser.tab.c"
    break;

  case 40: /* if_stmt: if_test else_statement  */
#line 377 "parser.y"
                          {fill(code.size()+1,1);}
#line 1843 "parser.tab.c"
    break;

  case 41: /* if_stmt: if_test elif_statements else_statement  */
#line 378 "parser.y"
                                         {fill(code.size()+1,(yyvsp[-1].attributes).jump+1);}
#line 1849 "parser.tab.c"
    break;

  case 42: /* if_stmt: if_test elif_statements  */
#line 379 "parser.y"
                          {fill(code.size()+1,(yyvsp[0].attributes).jump+1);}
#line 1855 "parser.tab.c"
    break;

  case 43: /* $@1: %empty  */
#line 383 "parser.y"
        {if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=3){yyerror("type");return 0;}(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1861 "parser.tab.c"
    break;

  case 44: /* if_test: IF test $@1 COLON suite  */
#line 383 "parser.y"
                                                                                                                                                                                                                                          {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1867 "parser.tab.c"
    break;

  case 45: /* elif_statements: elif_statements elif_test  */
#line 386 "parser.y"
                          {(yyval.attributes).jump=(yyvsp[-1].attributes).jump+1;}
#line 1873 "parser.tab.c"
    break;

  case 46: /* elif_statements: elif_test  */
#line 387 "parser.y"
            {(yyval.attributes).jump=1;}
#line 1879 "parser.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 391 "parser.y"
          {if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=3){yyerror("type");return 0;}(yyvsp[-1].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1885 "parser.tab.c"
    break;

  case 48: /* elif_test: ELIF test $@2 COLON suite  */
#line 391 "parser.y"
                                                                                                                                                                                                                                            {string c=code[(yyvsp[-4].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-4].attributes).jump]=c; c="jump line "; code.push_back(c);}
#line 1891 "parser.tab.c"
    break;

  case 52: /* $@3: %empty  */
#line 403 "parser.y"
     {(yyvsp[0].attributes).jump=code.size()+1;}
#line 1897 "parser.tab.c"
    break;

  case 53: /* $@4: %empty  */
#line 403 "parser.y"
                                    {if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=3){yyerror("type");return 0;}(yyvsp[0].attributes).jump=code.size()+1; string c="if "+convert((yyvsp[0].attributes).reg)+" jump line "+to_string(code.size()+3); code.push_back(c); c.clear(); c="jump line "; code.push_back(c);}
#line 1903 "parser.tab.c"
    break;

  case 54: /* while_test: WHILE $@3 test $@4 COLON suite  */
#line 403 "parser.y"
                                                                                                                                                                                                                                                                      {fill(code.size()+2,curr_break); curr_break=0; string c=code[(yyvsp[-3].attributes).jump]; c=c+to_string(code.size()+2); code[(yyvsp[-3].attributes).jump]=c; c="jump line "+to_string((yyvsp[-5].attributes).jump); code.push_back(c);}
#line 1909 "parser.tab.c"
    break;

  case 57: /* $@5: %empty  */
#line 411 "parser.y"
                 {string c=convert((yyvsp[-2].attributes).lexeme); c=c+" = "+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyvsp[-3].attributes).jump=code.size()+1; c="#r"+to_string(node); node++; c=c+" = "+convert((yyvsp[-2].attributes).lexeme); code.push_back(c); c="#r"+to_string(node-1); c=c+" = "+c+" < "+convert((yyvsp[0].attributes).reg); code.push_back(c); c="if r"+to_string(node-1)+" jump line "+to_string(code.size()+3); code.push_back(c); c="jump line "; code.push_back(c);}
#line 1915 "parser.tab.c"
    break;

  case 58: /* for_test: FOR name IN range $@5 COLON suite  */
#line 411 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                             {fill(code.size()+2,curr_break); curr_break=0;  fill(code.size()+2,1); string c="jump line "+to_string((yyvsp[-6].attributes).jump); code.push_back(c);}
#line 1921 "parser.tab.c"
    break;

  case 59: /* range: RANGE LEFT_BRACKET test COMMA test RIGHT_BRACKET  */
#line 414 "parser.y"
                                                 {(yyval.attributes).lexeme=(yyvsp[-3].attributes).reg; (yyval.attributes).reg=(yyvsp[-1].attributes).reg;  if((yyvsp[-3].attributes).type!=1||(yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}}
#line 1927 "parser.tab.c"
    break;

  case 60: /* range: RANGE LEFT_BRACKET test RIGHT_BRACKET  */
#line 415 "parser.y"
                                        {string c="0"; (yyval.attributes).lexeme=new char[c.size()+1]; strcpy((yyval.attributes).lexeme, c.c_str()); (yyval.attributes).reg=(yyvsp[-1].attributes).reg;  if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}}
#line 1933 "parser.tab.c"
    break;

  case 61: /* $@6: %empty  */
#line 419 "parser.y"
                               {
                                current_func_type=0; 
                                string c=""; code.push_back(c); c=convert((yyvsp[-2].attributes).lexeme);
                                c=c+" :"; code.push_back(c); 
                                code.push_back("funcbegin");
                                for(auto x : (yyvsp[-1].attributes).other->lexemes){
                                    c=x+" = popparameter";
                                    code.push_back(c);
                                }
                                (yyvsp[-3].attributes).jump=code.size();
                                (yyvsp[0].attributes).jump=node-1;
                                string temp=curr_func;
                                if(curr_class=="None")curr_func="global";
                                else curr_func=curr_class;
                                update_table((yyvsp[-2].attributes).lexeme,6,(yyvsp[-2].attributes).line);
                                        
                                table[curr_func][(yyvsp[-2].attributes).lexeme].func_parameter=((yyvsp[-1].attributes).other)->types;
                                table[curr_func][(yyvsp[-2].attributes).lexeme].funct_return_type=0;
                                curr_func=temp;
                                }
#line 1958 "parser.tab.c"
    break;

  case 62: /* funcdef: DEF func_name parameters COLON $@6 suite  */
#line 439 "parser.y"
                                     {
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        copy_content((yyvsp[-4].attributes).lexeme);
                                        curr_func="global";
                                        current_func_type=-1;
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        c="funcend"; code.push_back(c);
                                        c=""; code.push_back(c);
                                    }
#line 1975 "parser.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 451 "parser.y"
                                                 {current_func_type=(yyvsp[0].attributes).type;  }
#line 1981 "parser.tab.c"
    break;

  case 64: /* $@8: %empty  */
#line 451 "parser.y"
                                                                                     {
                                string c=""; code.push_back(c); c=convert((yyvsp[-5].attributes).lexeme);
                                c=c+" :"; code.push_back(c); 
                                code.push_back("funcbegin");
                                for(auto x : (yyvsp[-4].attributes).other->lexemes){
                                    
                                    c=x+" = popparameter";
                                    code.push_back(c);
                                }
                                (yyvsp[-6].attributes).jump=code.size();
                                (yyvsp[-3].attributes).jump=node-1;
                                string temp=curr_func;
                                if(curr_class=="None")curr_func="global";
                                else curr_func=curr_class;
                                update_table((yyvsp[-5].attributes).lexeme,6,(yyvsp[-5].attributes).line);
                                table[curr_func][(yyvsp[-5].attributes).lexeme].func_parameter=((yyvsp[-4].attributes).other)->types;
                                table[curr_func][(yyvsp[-5].attributes).lexeme].funct_return_type=current_func_type;
                                curr_func=temp;
                                }
#line 2005 "parser.tab.c"
    break;

  case 65: /* funcdef: DEF func_name parameters RETURN_ARROW data_type $@7 COLON $@8 suite  */
#line 470 "parser.y"
                                      {
                                        if(curr_class=="None")curr_func="global";
                                        else curr_func=curr_class;
                                        copy_content((yyvsp[-7].attributes).lexeme);
                                        curr_func="global";
                                        current_func_type=-1;
                                        if(!is_return && (yyvsp[-4].attributes).type){yyerror("type");return 0;}
                                        is_return=0;
                                        is_self=0;
                                        string c;
                                        c="funcend"; code.push_back(c);
                                        c=""; code.push_back(c);
                                    }
#line 2023 "parser.tab.c"
    break;

  case 66: /* func_name: name  */
#line 484 "parser.y"
              {curr_func=(yyvsp[0].attributes).lexeme;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2029 "parser.tab.c"
    break;

  case 67: /* parameters: LEFT_BRACKET RIGHT_BRACKET  */
#line 486 "parser.y"
                                         {(yyval.attributes).other=new other;}
#line 2035 "parser.tab.c"
    break;

  case 68: /* parameters: LEFT_BRACKET typedargslist RIGHT_BRACKET  */
#line 487 "parser.y"
                                            {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 2041 "parser.tab.c"
    break;

  case 69: /* typedargslist: typedargslist COMMA full_tfpdef  */
#line 491 "parser.y"
                                {(yyval.attributes).other=(yyvsp[-2].attributes).other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme);}
#line 2047 "parser.tab.c"
    break;

  case 70: /* typedargslist: full_tfpdef  */
#line 492 "parser.y"
              {(yyval.attributes).other=new other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme);}
#line 2053 "parser.tab.c"
    break;

  case 71: /* full_tfpdef: name COLON data_type  */
#line 496 "parser.y"
                                {(yyval.attributes).lexeme=strdup((yyvsp[-2].attributes).lexeme); update_table((yyvsp[-2].attributes).lexeme,(yyvsp[0].attributes).type,(yyvsp[-2].attributes).line);(yyval.attributes).type=(yyvsp[0].attributes).type;if((yyval.attributes).type==7)table[curr_func][(yyvsp[-2].attributes).lexeme].list_type=typelist((yyvsp[0].attributes).lexeme);}
#line 2059 "parser.tab.c"
    break;

  case 72: /* full_tfpdef: NAME  */
#line 497 "parser.y"
                  {(yyval.attributes).lexeme=strdup((yyvsp[0].attributes).lexeme);}
#line 2065 "parser.tab.c"
    break;

  case 73: /* full_tfpdef: SELF  */
#line 498 "parser.y"
      {(yyval.attributes).type=0;is_self=1;}
#line 2071 "parser.tab.c"
    break;

  case 74: /* $@9: %empty  */
#line 503 "parser.y"
                                    {
                                    string c=""; code.push_back(c);
                                    c=convert((yyvsp[-2].attributes).lexeme);
                                    c=c+" :"; code.push_back(c);
                                    c="Parent : "+convert((yyvsp[-1].attributes).lexeme);
                                    code.push_back(c);
                                    code.push_back("classbegin");
                                }
#line 2084 "parser.tab.c"
    break;

  case 75: /* classdef: CLASS class_name opt_class_arg COLON $@9 suite  */
#line 511 "parser.y"
                                       {
                                update_table((yyvsp[-4].attributes).lexeme,5,(yyvsp[-4].attributes).line);curr_class="None";table["global"][(yyvsp[-4].attributes).lexeme].parent_class=(yyvsp[-3].attributes).lexeme;
                                string c="classend"; code.push_back(c);
                                c=""; code.push_back(c);
                                }
#line 2094 "parser.tab.c"
    break;

  case 76: /* $@10: %empty  */
#line 516 "parser.y"
                        {
                        string c=""; code.push_back(c);
                        c=convert((yyvsp[-1].attributes).lexeme);
                        c=c+" :"; code.push_back(c);
                        code.push_back("classbegin");
}
#line 2105 "parser.tab.c"
    break;

  case 77: /* classdef: CLASS class_name COLON $@10 suite  */
#line 522 "parser.y"
                          {
                            update_table((yyvsp[-3].attributes).lexeme,5,(yyvsp[-3].attributes).line);curr_class="None";
                            string c="classend"; code.push_back(c);
                                c=""; code.push_back(c);
                                }
#line 2115 "parser.tab.c"
    break;

  case 78: /* class_name: name  */
#line 528 "parser.y"
               {curr_class=(yyvsp[0].attributes).lexeme;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;update_class_type(curr_class);}
#line 2121 "parser.tab.c"
    break;

  case 79: /* opt_class_arg: LEFT_BRACKET RIGHT_BRACKET  */
#line 531 "parser.y"
                            {(yyval.attributes).lexeme=(char*)"None";}
#line 2127 "parser.tab.c"
    break;

  case 80: /* opt_class_arg: LEFT_BRACKET argument RIGHT_BRACKET  */
#line 532 "parser.y"
                                      {add_class(curr_class,(yyvsp[-1].attributes).lexeme);(yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;(yyval.attributes).other =(yyvsp[-1].attributes).other;}
#line 2133 "parser.tab.c"
    break;

  case 81: /* arglist: arglist COMMA argument  */
#line 536 "parser.y"
                                  {(yyval.attributes).other=(yyvsp[-2].attributes).other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type);if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2139 "parser.tab.c"
    break;

  case 82: /* arglist: argument  */
#line 537 "parser.y"
                      {(yyval.attributes).other=new other;if((yyvsp[0].attributes).type)(((yyval.attributes).other)->types).push_back((yyvsp[0].attributes).type); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->lexemes).push_back((yyvsp[0].attributes).lexeme); if((yyvsp[0].attributes).type)(((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2145 "parser.tab.c"
    break;

  case 83: /* argument: test  */
#line 541 "parser.y"
       {(yyval.attributes).type=(yyvsp[0].attributes).type; (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; (yyval.attributes).reg=(yyvsp[0].attributes).reg;}
#line 2151 "parser.tab.c"
    break;

  case 84: /* argument: test ASSIGNMENT_OPERATOR test  */
#line 542 "parser.y"
                                {if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;}
#line 2157 "parser.tab.c"
    break;

  case 85: /* argument: SELF  */
#line 543 "parser.y"
       {(yyval.attributes).type=0; string c="self"; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str());}
#line 2163 "parser.tab.c"
    break;

  case 91: /* test: or_test  */
#line 556 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2169 "parser.tab.c"
    break;

  case 92: /* or_test: or_test OR and_test  */
#line 559 "parser.y"
                                        {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+c+" or "+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2175 "parser.tab.c"
    break;

  case 93: /* or_test: and_test  */
#line 560 "parser.y"
                    {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2181 "parser.tab.c"
    break;

  case 94: /* and_test: and_test AND not_test  */
#line 563 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+c+" and "+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2187 "parser.tab.c"
    break;

  case 95: /* and_test: not_test  */
#line 564 "parser.y"
          {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2193 "parser.tab.c"
    break;

  case 96: /* not_test: NOT not_test  */
#line 567 "parser.y"
                        {string c=convert((yyvsp[0].attributes).reg); c=c+" = not "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if(!((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3)){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2199 "parser.tab.c"
    break;

  case 97: /* not_test: comparison  */
#line 568 "parser.y"
             {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2205 "parser.tab.c"
    break;

  case 98: /* comparison: comparison r_o expr  */
#line 571 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+c+" "+convert((yyvsp[-1].attributes).reg)+" "+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type))return 0;(yyval.attributes).type=3;}
#line 2211 "parser.tab.c"
    break;

  case 99: /* comparison: expr  */
#line 572 "parser.y"
                 {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2217 "parser.tab.c"
    break;

  case 100: /* r_o: RELATIONAL_OPERATOR  */
#line 575 "parser.y"
                         {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); }
#line 2223 "parser.tab.c"
    break;

  case 101: /* expr: expr BIT_OR xor_expr  */
#line 578 "parser.y"
                                         {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" | "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2229 "parser.tab.c"
    break;

  case 102: /* expr: xor_expr  */
#line 579 "parser.y"
                       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2235 "parser.tab.c"
    break;

  case 103: /* xor_expr: xor_expr XOR and_expr  */
#line 582 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" ^ "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2241 "parser.tab.c"
    break;

  case 104: /* xor_expr: and_expr  */
#line 583 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2247 "parser.tab.c"
    break;

  case 105: /* and_expr: and_expr BIT_AND shift_expr  */
#line 586 "parser.y"
                                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" & "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2253 "parser.tab.c"
    break;

  case 106: /* and_expr: shift_expr  */
#line 587 "parser.y"
                           {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2259 "parser.tab.c"
    break;

  case 107: /* shift_expr: shift_expr L_SHIFT arith_expr  */
#line 590 "parser.y"
                                                      {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" << "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2265 "parser.tab.c"
    break;

  case 108: /* shift_expr: shift_expr R_SHIFT arith_expr  */
#line 591 "parser.y"
                                            {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" >> "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;if(!(((yyvsp[-2].attributes).type==1||(yyvsp[-2].attributes).type==3)&&((yyvsp[0].attributes).type==1||(yyvsp[0].attributes).type==3))){yyerror("type");return 0;}(yyval.attributes).type=3;}
#line 2271 "parser.tab.c"
    break;

  case 109: /* shift_expr: arith_expr  */
#line 592 "parser.y"
                         {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2277 "parser.tab.c"
    break;

  case 110: /* arith_expr: arith_expr ADD term  */
#line 596 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" + "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(!type){return 0;}(yyval.attributes).type=type;}
#line 2283 "parser.tab.c"
    break;

  case 111: /* arith_expr: arith_expr SUB term  */
#line 597 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+convert((yyvsp[-2].attributes).reg)+" - "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>3)yyerror("type");if(type<1||type>3)return 0;(yyval.attributes).type=type;}
#line 2289 "parser.tab.c"
    break;

  case 112: /* arith_expr: term  */
#line 598 "parser.y"
                  {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2295 "parser.tab.c"
    break;

  case 113: /* term: term a_o factor  */
#line 601 "parser.y"
                                   {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+c+" "+convert((yyvsp[-1].attributes).reg)+" "+convert((yyvsp[0].attributes).reg); code.push_back(c); (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;if((yyvsp[-1].attributes).lexeme!="//"){(yyval.attributes).type=type;}else (yyval.attributes).type=1;  }
#line 2301 "parser.tab.c"
    break;

  case 114: /* term: factor  */
#line 602 "parser.y"
                   {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2307 "parser.tab.c"
    break;

  case 115: /* a_o: ARITHMETIC_OPERATOR  */
#line 604 "parser.y"
                          {string c=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; }
#line 2313 "parser.tab.c"
    break;

  case 116: /* factor: ADD factor  */
#line 608 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+" = + "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2319 "parser.tab.c"
    break;

  case 117: /* factor: SUB factor  */
#line 609 "parser.y"
            {string c=convert((yyvsp[0].attributes).reg); c=c+" = - "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type!=1&&(yyvsp[0].attributes).type!=2){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2325 "parser.tab.c"
    break;

  case 118: /* factor: BIT_NOT factor  */
#line 610 "parser.y"
                {string c=convert((yyvsp[0].attributes).reg); c=c+" = ~ "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[0].attributes).reg;if((yyvsp[0].attributes).type<1||(yyvsp[0].attributes).type>3){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[0].attributes).type;}
#line 2331 "parser.tab.c"
    break;

  case 119: /* factor: power  */
#line 611 "parser.y"
       {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2337 "parser.tab.c"
    break;

  case 120: /* power: atom_expr POWER factor  */
#line 615 "parser.y"
                                  {string c=convert((yyvsp[-2].attributes).reg); c=c+" = "+c+" ** "+convert((yyvsp[0].attributes).reg); code.push_back(c);  (yyval.attributes).reg=(yyvsp[-2].attributes).reg;int type=check_type((yyvsp[-2].attributes).type,(yyvsp[0].attributes).type);if(type>2)yyerror("type");if(type<1||type>2)return 0;(yyval.attributes).type=type;}
#line 2343 "parser.tab.c"
    break;

  case 121: /* power: atom_expr  */
#line 616 "parser.y"
                      {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2349 "parser.tab.c"
    break;

  case 122: /* atom_expr: atom opt_trailer  */
#line 620 "parser.y"
                            { 
                              if(get_type((yyvsp[-1].attributes).lexeme)==7){
                                string c=convert((yyvsp[-1].attributes).lexeme); c+=convert((yyvsp[0].attributes).lexeme); (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); c="#r"+to_string(node); node++;
                                (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());  c=c+" = "+convert((yyvsp[-1].attributes).lexeme)+convert((yyvsp[0].attributes).lexeme); code.push_back(c); 
                                if((yyvsp[0].attributes).list_type!=1){yyerror("type");return 0;}
                                (yyval.attributes).type=get_listtype((yyvsp[-1].attributes).lexeme);
                              }
                              else{
                                if((yyvsp[0].attributes).list_type==1){yyerror("type");return 0;}
                                if((yyvsp[-1].attributes).type==6){
                                    if(!match_vector(get_func_parameter((yyvsp[-1].attributes).lexeme),(yyvsp[0].attributes).other->types)){return 0;}
                                    int i=0;
                                    for(auto x: (yyvsp[0].attributes).other->regs){
                                        i++;
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                    code.push_back("stackpointer +xxx"); 
                                    string c= "call ";
                                    c=c+convert((yyvsp[-1].attributes).lexeme)+" , "+to_string(i);
                                    code.push_back(c);
                                    code.push_back("stackpointer -xxx"); 
                                    (yyval.attributes).type=get_funct_type((yyvsp[-1].attributes).lexeme);
                                    if((yyval.attributes).type){
                                    c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());
                                    c=c+" = popparameter"; code.push_back(c);
                                    }
                                }
                                if((yyvsp[-1].attributes).type==5){
                                    if(!(yyvsp[0].attributes).dot){
                                        (yyval.attributes).type=classes_type[(yyvsp[-1].attributes).lexeme];
                                        if(!match_vector(table[(yyvsp[-1].attributes).lexeme]["__init__"].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                        int i=0;
                                        for(auto x: (yyvsp[0].attributes).other->regs){
                                            i++;
                                            string c="param ";
                                            c=c+x;
                                            code.push_back(c);
                                        }
                                        code.push_back("stackpointer +xxx"); 
                                        string c= "call ";
                                        c=c+convert((yyvsp[-1].attributes).lexeme)+".__init__ , "+to_string(i);
                                        code.push_back(c);
                                        code.push_back("stackpointer -xxx"); 
                                        c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());
                                        c=c+" = popparameter"; code.push_back(c);
                                    }else{
                                        (yyval.attributes).type=table[(yyvsp[-1].attributes).lexeme][(yyvsp[0].attributes).lexeme].type;
                                        if((yyval.attributes).type==6&&!match_vector(table[(yyvsp[-1].attributes).lexeme][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                        int i=0;
                                        for(auto x: (yyvsp[0].attributes).other->regs){
                                            i++;
                                            string c="param ";
                                            c=c+x;
                                            code.push_back(c);
                                        }
                                        code.push_back("stackpointer +xxx"); 
                                        string c= "call ";
                                        c=c+convert((yyvsp[-1].attributes).lexeme)+"."+convert((yyvsp[0].attributes).lexeme)+" , "+to_string(i);
                                        code.push_back(c);
                                        code.push_back("stackpointer -xxx"); 
                                        if((yyval.attributes).type){c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());
                                        c=c+" = popparameter"; code.push_back(c);
                                        }
                                    }

                                }
                                if((yyvsp[-1].attributes).type>10){
                                    if((yyvsp[0].attributes).dot){
                                        (yyval.attributes).type=table[type_to_class[(yyvsp[-1].attributes).type]][(yyvsp[0].attributes).lexeme].type;
                                        if((yyval.attributes).type==6&&!match_vector(table[type_to_class[(yyvsp[-1].attributes).type]][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                                        int i=0;
                                        for(auto x: (yyvsp[0].attributes).other->regs){
                                            i++;
                                            string c="param ";
                                            c=c+x;
                                            code.push_back(c);
                                        }
                                        code.push_back("stackpointer +xxx"); 
                                        string c= "call ";
                                        c=c+convert((yyvsp[-1].attributes).lexeme)+"."+convert((yyvsp[0].attributes).lexeme)+" , "+to_string(i);
                                        code.push_back(c);
                                        code.push_back("stackpointer -xxx"); 
                                        if((yyval.attributes).type){c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str());
                                        c=c+" = popparameter"; code.push_back(c);
                                        }
                                    }
                                }
                              }
                            }
#line 2445 "parser.tab.c"
    break;

  case 123: /* atom_expr: atom  */
#line 711 "parser.y"
                {(yyval.attributes).reg=(yyvsp[0].attributes).reg;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).count=(yyvsp[0].attributes).count;}
#line 2451 "parser.tab.c"
    break;

  case 124: /* atom_expr: SELF opt_trailer  */
#line 713 "parser.y"
                           {
                            if((yyvsp[0].attributes).dot){
                                string c = "self.";c=c+convert((yyvsp[0].attributes).lexeme);(yyvsp[0].attributes).lexeme=new char[c.size()]; strcpy((yyvsp[0].attributes).lexeme, c.c_str());
                                (yyval.attributes).type=table[curr_class][(yyvsp[0].attributes).lexeme].type;
                                if((yyval.attributes).type==6&&!match_vector(table[curr_class][(yyvsp[0].attributes).lexeme].func_parameter,(yyvsp[0].attributes).other->types)){return 0;}
                            }
                            if(!is_self){yyerror("type");return 0;}
                            (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;
                            (yyval.attributes).reg=(yyvsp[0].attributes).reg;
                        }
#line 2466 "parser.tab.c"
    break;

  case 125: /* atom_expr: LEN LEFT_BRACKET test RIGHT_BRACKET  */
#line 723 "parser.y"
                                     {
                                if((yyvsp[-1].attributes).type!=7){yyerror("type");return 0;}
                                (yyval.attributes).type=1;
                                string c="param ";
                                c=c+convert((yyvsp[-1].attributes).reg);
                                code.push_back(c);
                                code.push_back("stackpointer +xxx"); 
                                c= "call len , 1";
                                code.push_back(c);
                                code.push_back("stackpointer -xxx"); 
                                c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+"=popparameter"; code.push_back(c);
                            }
#line 2483 "parser.tab.c"
    break;

  case 126: /* atom_expr: PRINT LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 735 "parser.y"
                                         {
                                int i=0;
                                for(auto x: (yyvsp[-1].attributes).other->regs){
                                        i++;
                                        string c="param ";
                                        c=c+x;
                                        code.push_back(c);
                                    }
                                code.push_back("stackpointer +xxx"); 
                                string c= "call print , "+to_string(i);
                                code.push_back(c);
                                code.push_back("stackpointer -xxx"); 
                                (yyval.attributes).type=0;
                                (yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;
                                (yyval.attributes).reg=(yyval.attributes).lexeme;
                            }
#line 2504 "parser.tab.c"
    break;

  case 127: /* opt_trailer: opt_trailer trailer  */
#line 754 "parser.y"
                    {(yyval.attributes).lexeme=(yyvsp[-1].attributes).lexeme;(yyval.attributes).other=(yyvsp[0].attributes).other;(yyval.attributes).list_type=5;(yyval.attributes).dot=(yyvsp[-1].attributes).dot+(yyvsp[0].attributes).dot;}
#line 2510 "parser.tab.c"
    break;

  case 128: /* opt_trailer: trailer  */
#line 755 "parser.y"
           {(yyval.attributes).type=(yyvsp[0].attributes).type;(yyval.attributes).list_type=(yyvsp[0].attributes).list_type;(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).other=(yyvsp[0].attributes).other;(yyval.attributes).dot=(yyvsp[0].attributes).dot;}
#line 2516 "parser.tab.c"
    break;

  case 129: /* atom: LEFT_BRACKET testlist RIGHT_BRACKET  */
#line 759 "parser.y"
                                    {(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;(yyval.attributes).reg=(yyvsp[-1].attributes).reg;}
#line 2522 "parser.tab.c"
    break;

  case 132: /* atom: LEFT_SQUARE_BRACKET testlist RIGHT_SQUARE_BRACKET  */
#line 762 "parser.y"
                                                   {
    string c="#r"+to_string(node); node++; c=c+" = "+to_string(((yyvsp[-1].attributes).count+1)*8); code.push_back(c); code.push_back("stackpointer + 8"); code.push_back("param #r"+to_string(node-1)); code.push_back("call mem_alloc , 1"); code.push_back("stackpointer - 8");
    c="#r"+to_string(node); node++; code.push_back(c+"=popparameter"); (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); (yyval.attributes).type=7;(yyval.attributes).list_type=(yyvsp[-1].attributes).type;(yyval.attributes).count=(yyvsp[-1].attributes).count;
    c="#r"+to_string(node); node++; 
    code.push_back(c+" = "+convert((yyval.attributes).reg));
    code.push_back("* ( "+c+" ) = r"+to_string(node-3));
    for(auto x:(yyvsp[-1].attributes).other->regs){
       code.push_back(c+" = "+c+" + 8");
       code.push_back("* ( "+c+" ) = "+x);
    }
    }
#line 2538 "parser.tab.c"
    break;

  case 133: /* atom: NAME  */
#line 773 "parser.y"
        {string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c);  (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;if(check((yyvsp[0].attributes).lexeme))return 0; (yyval.attributes).type=get_type((yyvsp[0].attributes).lexeme);if((yyval.attributes).type==7)(yyval.attributes).list_type=get_listtype((yyvsp[0].attributes).lexeme);}
#line 2544 "parser.tab.c"
    break;

  case 134: /* atom: INT  */
#line 774 "parser.y"
      {string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=1;}
#line 2550 "parser.tab.c"
    break;

  case 135: /* atom: FLOAT  */
#line 775 "parser.y"
        {string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=2;}
#line 2556 "parser.tab.c"
    break;

  case 136: /* atom: DATA_TYPE  */
#line 776 "parser.y"
            {(yyval.attributes).type=typedetector((yyvsp[0].attributes).lexeme);(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2562 "parser.tab.c"
    break;

  case 137: /* atom: STRING  */
#line 777 "parser.y"
          {(yyval.attributes).type=4;string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2568 "parser.tab.c"
    break;

  case 138: /* atom: STRING_1  */
#line 778 "parser.y"
           {(yyval.attributes).type=4;string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;}
#line 2574 "parser.tab.c"
    break;

  case 139: /* atom: NONE  */
#line 779 "parser.y"
            {(yyval.attributes).type=0;}
#line 2580 "parser.tab.c"
    break;

  case 140: /* atom: TRUE  */
#line 780 "parser.y"
      {string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2586 "parser.tab.c"
    break;

  case 141: /* atom: FALSE  */
#line 781 "parser.y"
       {string c="#r"+to_string(node); node++; (yyval.attributes).reg=new char[c.size() + 1]; strcpy((yyval.attributes).reg, c.c_str()); c=c+" = ";  c=c+convert((yyvsp[0].attributes).lexeme); code.push_back(c); (yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme;(yyval.attributes).type=3;}
#line 2592 "parser.tab.c"
    break;

  case 142: /* atom: LIST  */
#line 782 "parser.y"
      {(yyval.attributes).type=7;}
#line 2598 "parser.tab.c"
    break;

  case 143: /* trailer: LEFT_BRACKET arglist RIGHT_BRACKET  */
#line 787 "parser.y"
                                     {(yyval.attributes).other=(yyvsp[-1].attributes).other;}
#line 2604 "parser.tab.c"
    break;

  case 144: /* trailer: LEFT_BRACKET RIGHT_BRACKET  */
#line 788 "parser.y"
                              {(yyval.attributes).other=new other;}
#line 2610 "parser.tab.c"
    break;

  case 145: /* trailer: LEFT_SQUARE_BRACKET test RIGHT_SQUARE_BRACKET  */
#line 789 "parser.y"
                                                 {string c="[ "; c+=convert((yyvsp[-1].attributes).reg); c+=" ]"; (yyval.attributes).lexeme=new char[c.size() + 1]; strcpy((yyval.attributes).lexeme, c.c_str()); if((yyvsp[-1].attributes).type!=1){yyerror("type");return 0;}(yyval.attributes).type=(yyvsp[-1].attributes).type;(yyval.attributes).list_type=1;}
#line 2616 "parser.tab.c"
    break;

  case 146: /* trailer: DOT name  */
#line 790 "parser.y"
           {(yyval.attributes).lexeme=(yyvsp[0].attributes).lexeme; (yyval.attributes).reg=(yyvsp[0].attributes).reg; (yyval.attributes).dot=1;}
#line 2622 "parser.tab.c"
    break;

  case 147: /* testlist: testlist COMMA test  */
#line 794 "parser.y"
                    {(yyval.attributes).type=(yyvsp[-2].attributes).type; (yyval.attributes).count=(yyvsp[-2].attributes).count+1; (yyval.attributes).other=(yyvsp[-2].attributes).other; (((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2628 "parser.tab.c"
    break;

  case 148: /* testlist: test  */
#line 795 "parser.y"
       {(yyval.attributes).type=(yyvsp[0].attributes).type; (yyval.attributes).count=1; (yyval.attributes).other=new other; (((yyval.attributes).other)->regs).push_back((yyvsp[0].attributes).reg);}
#line 2634 "parser.tab.c"
    break;


#line 2638 "parser.tab.c"

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

#line 799 "parser.y"


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
   
   int flag = 0;
   if(argc == 5)  flag=1;
   if(flag){ 
   yyin = fopen(argv[2], "r");
   yyout = fopen(argv[4], "w");
   yydebug=0;
   yyparse();
   for(auto x:code){
    fprintf(yyout,"%s\n",x.data());
   }
   FILE *fpt1;
   FILE *fpt2;
   string c;
   char * path;
   int i=0;
   for(auto x: table){
        c=x.first+to_string(i)+".csv";
        path=new char[c.size() + 1]; 
        strcpy(path, c.c_str());
        fpt1 = fopen(path, "w+");
        fprintf(fpt1, "lexeme, token, line_number, type\n");
        for(auto y: x.second){
            char * t1=new char[y.first.size() + 1]; strcpy(t1, y.first.c_str());
            fprintf(fpt1, "%s, IDENTIFIER, %d, %s, %d\n",t1,y.second.line_number,convert_to_string(y.second.list_type,y.second.type),y.second.size);
            if(y.second.type==6){
                i++;
                c=x.first+"."+y.first+to_string(i)+".csv";
                path=new char[c.size() + 1]; 
                strcpy(path, c.c_str());
                fpt2 = fopen(path, "w+");
                fprintf(fpt2, "lexeme, token, line_number, type\n");
                for(auto it:y.second.func_content){
                    char * t2=new char[it.first.size() + 1]; strcpy(t2, it.first.c_str());
                    fprintf(fpt2, "%s, IDENTIFIER, %d, %s\n",t2,it.second.line_number,convert_to_string(it.second.list_type,it.second.type));
                }
            }
        }
        i++;
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
