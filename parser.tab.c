/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ARITHMETIC_OPERATOR = 258,
     RELATIONAL_OPERATOR = 259,
     BITWISE_OPERATOR = 260,
     ASSIGNMENT_OPERATOR = 261,
     DATA_TYPE = 262,
     FOR = 263,
     WHILE = 264,
     IF = 265,
     ELIF = 266,
     ELSE = 267,
     BREAK = 268,
     CLASS = 269,
     CONTINUE = 270,
     LIST = 271,
     SEMICOLON = 272,
     AUGASSIGNMENT_OPERATOR = 273,
     COLON = 274,
     LEFT_BRACKET = 275,
     RIGHT_BRACKET = 276,
     RETURN_ARROW = 277,
     COMMA = 278,
     NAME = 279,
     LEFT_SQUARE_BRACKET = 280,
     RIGHT_SQUARE_BRACKET = 281,
     NONE = 282,
     TRUE = 283,
     FALSE = 284,
     IN = 285,
     DEF = 286,
     NOT = 287,
     RETURN = 288,
     NEWLINE = 289,
     INDENT = 290,
     DEDENT = 291,
     AND = 292,
     OR = 293,
     XOR = 294,
     BIT_NOT = 295,
     ADD_SUB = 296,
     POWER = 297,
     BIT_AND = 298,
     BIT_OR = 299,
     NUMBER = 300,
     STRING = 301,
     DOT = 302,
     SHIFT = 303,
     LEFT_CURLY_BRACKET = 304,
     RIGHT_CURLY_BRACKET = 305
   };
#endif
/* Tokens.  */
#define ARITHMETIC_OPERATOR 258
#define RELATIONAL_OPERATOR 259
#define BITWISE_OPERATOR 260
#define ASSIGNMENT_OPERATOR 261
#define DATA_TYPE 262
#define FOR 263
#define WHILE 264
#define IF 265
#define ELIF 266
#define ELSE 267
#define BREAK 268
#define CLASS 269
#define CONTINUE 270
#define LIST 271
#define SEMICOLON 272
#define AUGASSIGNMENT_OPERATOR 273
#define COLON 274
#define LEFT_BRACKET 275
#define RIGHT_BRACKET 276
#define RETURN_ARROW 277
#define COMMA 278
#define NAME 279
#define LEFT_SQUARE_BRACKET 280
#define RIGHT_SQUARE_BRACKET 281
#define NONE 282
#define TRUE 283
#define FALSE 284
#define IN 285
#define DEF 286
#define NOT 287
#define RETURN 288
#define NEWLINE 289
#define INDENT 290
#define DEDENT 291
#define AND 292
#define OR 293
#define XOR 294
#define BIT_NOT 295
#define ADD_SUB 296
#define POWER 297
#define BIT_AND 298
#define BIT_OR 299
#define NUMBER 300
#define STRING 301
#define DOT 302
#define SHIFT 303
#define LEFT_CURLY_BRACKET 304
#define RIGHT_CURLY_BRACKET 305




/* Copy the first part of user declarations.  */
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    16,    21,
      24,    26,    27,    31,    32,    34,    36,    38,    40,    43,
      45,    48,    50,    54,    55,    60,    63,    65,    67,    69,
      72,    74,    76,    78,    80,    82,    89,    90,    96,    97,
     101,   107,   115,   122,   123,   126,   130,   131,   133,   136,
     140,   141,   144,   146,   152,   153,   157,   158,   160,   164,
     165,   167,   168,   172,   175,   179,   180,   182,   184,   186,
     187,   189,   195,   199,   201,   206,   209,   210,   213,   214,
     219,   221,   224,   225,   229,   232,   233,   237,   240,   242,
     245,   249,   250,   253,   254,   258,   261,   262,   266,   269,
     270,   274,   277,   278,   282,   285,   286,   290,   293,   294,
     298,   301,   303,   305,   307,   310,   313,   314,   317,   320,
     321,   325,   329,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   348,   351,   355,   356,   360,   364,   368,   371,
     375,   379,   380,   382,   387,   389,   390,   392,   393,   396,
     400,   401,   405,   409,   410
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    34,    -1,    55,    -1,    66,
      34,    -1,    55,    -1,    66,    -1,    58,    57,    56,    34,
      -1,    58,    57,    -1,    17,    -1,    -1,    17,    58,    57,
      -1,    -1,    59,    -1,    63,    -1,    64,    -1,    65,    -1,
     132,    60,    -1,    62,    -1,    18,   132,    -1,    61,    -1,
       6,   132,    61,    -1,    -1,    19,    93,     6,    93,    -1,
      19,    93,    -1,    13,    -1,    15,    -1,    33,    -1,    33,
     132,    -1,    67,    -1,    70,    -1,    71,    -1,    72,    -1,
      79,    -1,    10,    93,    19,    91,    68,    69,    -1,    -1,
      11,    93,    19,    91,    68,    -1,    -1,    12,    19,    91,
      -1,     9,    93,    19,    91,    69,    -1,     8,   134,    30,
     132,    19,    91,    69,    -1,    31,    24,    74,    73,    19,
      91,    -1,    -1,    22,    93,    -1,    20,    75,    21,    -1,
      -1,    76,    -1,    78,    77,    -1,    23,    78,    77,    -1,
      -1,    24,    62,    -1,    24,    -1,    14,    24,    80,    19,
      91,    -1,    -1,    20,    81,    21,    -1,    -1,    82,    -1,
      85,    84,    83,    -1,    -1,    23,    -1,    -1,    23,    85,
      84,    -1,    93,    86,    -1,    93,     6,    93,    -1,    -1,
      89,    -1,    89,    -1,    90,    -1,    -1,    87,    -1,     8,
     134,    30,    96,    88,    -1,    10,    95,    88,    -1,    55,
      -1,    34,    35,    92,    36,    -1,    54,    92,    -1,    -1,
      96,    94,    -1,    -1,    10,    96,    12,    93,    -1,    96,
      -1,    98,    97,    -1,    -1,    38,    98,    97,    -1,   100,
      99,    -1,    -1,    37,   100,    99,    -1,    32,   100,    -1,
     101,    -1,   103,   102,    -1,     4,   103,   102,    -1,    -1,
     105,   104,    -1,    -1,    44,   105,   104,    -1,   107,   106,
      -1,    -1,    39,   107,   106,    -1,   109,   108,    -1,    -1,
      43,   109,   108,    -1,   111,   110,    -1,    -1,    48,   111,
     110,    -1,   113,   112,    -1,    -1,    41,   113,   112,    -1,
     115,   114,    -1,    -1,     3,   115,   114,    -1,   116,   115,
      -1,   117,    -1,    41,    -1,    40,    -1,   119,   118,    -1,
      42,   115,    -1,    -1,   121,   120,    -1,   125,   120,    -1,
      -1,    20,   122,    21,    -1,    25,   122,    26,    -1,    24,
      -1,    45,    -1,     7,    -1,    46,    -1,    27,    -1,    28,
      -1,    29,    -1,    16,    -1,   123,    -1,    -1,    93,    89,
      -1,    93,   124,    83,    -1,    -1,    23,    93,   124,    -1,
      20,    81,    21,    -1,    25,   126,    26,    -1,    47,    24,
      -1,   128,   127,    83,    -1,    23,   128,   127,    -1,    -1,
      93,    -1,   129,    19,   129,   130,    -1,    93,    -1,    -1,
     131,    -1,    -1,    19,   129,    -1,    93,   133,    83,    -1,
      -1,    23,    93,   133,    -1,   103,   135,    83,    -1,    -1,
      23,   103,   135,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    24,    24,    26,    26,    26,    28,    29,    31,    32,
      34,    35,    37,    38,    40,    41,    42,    43,    46,    48,
      49,    50,    52,    53,    55,    56,    59,    61,    63,    64,
      67,    67,    67,    67,    67,    69,    71,    72,    74,    75,
      78,    81,    85,    87,    88,    90,    92,    93,    95,    97,
      98,   100,   101,   106,   108,   109,   111,   112,   114,   116,
     117,   119,   120,   122,   123,   125,   126,   128,   129,   131,
     132,   134,   136,   140,   140,   141,   141,   143,   145,   146,
     148,   150,   152,   153,   155,   157,   158,   160,   161,   163,
     165,   166,   168,   170,   171,   173,   175,   176,   178,   180,
     181,   183,   185,   186,   188,   190,   191,   193,   195,   196,
     198,   199,   201,   202,   204,   206,   207,   209,   211,   212,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     225,   226,   228,   229,   231,   232,   234,   235,   236,   237,
     239,   240,   242,   243,   245,   246,   249,   250,   253,   256,
     258,   259,   263,   265,   266
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARITHMETIC_OPERATOR",
  "RELATIONAL_OPERATOR", "BITWISE_OPERATOR", "ASSIGNMENT_OPERATOR",
  "DATA_TYPE", "FOR", "WHILE", "IF", "ELIF", "ELSE", "BREAK", "CLASS",
  "CONTINUE", "LIST", "SEMICOLON", "AUGASSIGNMENT_OPERATOR", "COLON",
  "LEFT_BRACKET", "RIGHT_BRACKET", "RETURN_ARROW", "COMMA", "NAME",
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "NONE", "TRUE", "FALSE",
  "IN", "DEF", "NOT", "RETURN", "NEWLINE", "INDENT", "DEDENT", "AND", "OR",
  "XOR", "BIT_NOT", "ADD_SUB", "POWER", "BIT_AND", "BIT_OR", "NUMBER",
  "STRING", "DOT", "SHIFT", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET",
  "$accept", "module", "single_input", "stmt", "simple_stmt",
  "opt_semicolon", "more_expr", "small_stmt", "expr_stmt", "right_assign",
  "Assign_stmt", "annassign", "break_stmt", "continue_stmt", "return_stmt",
  "compound_stmt", "if_stmt", "elif_statements", "else_statement_opt",
  "while_stmt", "for_stmt", "funcdef", "return_arrow_opt", "parameters",
  "typedargslist_opt", "typedargslist", "tfpdef_list", "full_tfpdef",
  "classdef", "opt_class_arg", "opt_arglist", "arglist", "opt_comma",
  "comma_arg_star", "argument", "opt_comp_for", "comp_iter",
  "opt_comp_iter", "comp_for", "comp_if", "suite", "stmt_list", "test",
  "opt_if_or_test_else_test", "test_nocond", "or_test", "or_and_test_star",
  "and_test", "and_not_test_star", "not_test", "comparison", "opt_expr",
  "expr", "opt_xor", "xor_expr", "opt_and", "and_expr", "opt_shift",
  "shift_expr", "opt_arith", "arith_expr", "opt_term", "term",
  "opt_factor", "factor", "oper", "power", "opt_atom", "atom_expr",
  "opt_trailer", "atom", "opt_testlist_comp", "testlist_comp",
  "opt_test_stmt", "trailer", "subscriptlist", "opt_subscript",
  "subscript", "opt_test_sub", "opt_sliceop", "sliceop", "testlist",
  "opt_testlist", "exprlist", "opt_exprlist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    60,
      60,    60,    61,    61,    62,    62,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    67,    68,    68,    69,    69,
      70,    71,    72,    73,    73,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    91,    91,    92,    92,    93,    94,    94,
      95,    96,    97,    97,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   104,   104,   105,   106,   106,   107,   108,
     108,   109,   110,   110,   111,   112,   112,   113,   114,   114,
     115,   115,   116,   116,   117,   118,   118,   119,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   132,
     133,   133,   134,   135,   135
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     4,     2,
       1,     0,     3,     0,     1,     1,     1,     1,     2,     1,
       2,     1,     3,     0,     4,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     6,     0,     5,     0,     3,
       5,     7,     6,     0,     2,     3,     0,     1,     2,     3,
       0,     2,     1,     5,     0,     3,     0,     1,     3,     0,
       1,     0,     3,     2,     3,     0,     1,     1,     1,     0,
       1,     5,     3,     1,     4,     2,     0,     2,     0,     4,
       1,     2,     0,     3,     2,     0,     3,     2,     1,     2,
       3,     0,     2,     0,     3,     2,     0,     3,     2,     0,
       3,     2,     0,     3,     2,     0,     3,     2,     0,     3,
       2,     1,     1,     1,     2,     2,     0,     2,     2,     0,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     3,     0,     3,     3,     3,     2,     3,
       3,     0,     1,     4,     1,     0,     1,     0,     2,     3,
       0,     3,     3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   124,     0,     0,     0,    26,     0,    27,   129,   131,
     122,   131,   126,   127,   128,     0,     0,    28,     3,   113,
     112,   123,   125,     0,     2,     4,    13,    14,    15,    16,
      17,     0,    30,    31,    32,    33,    34,   150,    78,    82,
      85,    88,    91,    93,    96,    99,   102,   105,   108,     0,
     111,   116,   119,    23,   153,     0,     0,     0,    54,   134,
       0,   130,     0,     0,    87,    29,     1,     0,     9,     5,
       0,    59,     0,    77,     0,    81,     0,    84,     0,    89,
       0,    92,     0,    95,     0,    98,     0,   101,     0,   104,
       0,   107,   110,     0,   114,    56,   145,     0,   117,   119,
       0,     0,     0,    18,    21,    19,     0,    59,     0,     0,
       0,    56,     0,     0,     0,   132,    59,   120,   121,    46,
      43,    13,    10,     0,   150,    60,   149,     0,    82,    85,
      91,    93,    96,    99,   102,   105,   108,   115,     0,    57,
      61,    65,   142,     0,   141,     0,   138,   118,    23,    20,
      25,   153,   152,     0,     0,    73,    38,    36,     0,     0,
       0,   134,   133,    52,     0,    47,    50,     0,     0,    12,
       8,   151,     0,    83,    86,    90,    94,    97,   100,   103,
     106,   109,   136,     0,    59,     0,    63,    66,   137,   145,
      59,   145,    22,     0,   154,     0,    76,     0,    40,     0,
      38,    55,    53,     0,   135,    51,    45,     0,    48,    44,
       0,    79,    61,    58,    64,   141,   139,   144,   147,    24,
      38,    76,     6,     7,     0,     0,     0,    35,    69,    50,
      42,    62,   140,   145,   143,   146,    41,    75,    74,    39,
       0,     0,    70,    71,    67,    68,    49,   148,    36,    69,
      80,    37,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,   221,   155,   123,    68,    26,    27,   103,
     104,   105,    28,    29,    30,   223,    32,   200,   198,    33,
      34,    35,   168,   120,   164,   165,   208,   166,    36,   112,
     138,   139,   126,   184,   140,   186,   242,   243,   244,   245,
     156,   224,    37,    73,   249,    38,    75,    39,    77,    40,
      41,    79,    42,    81,    43,    83,    44,    85,    45,    87,
      46,    89,    47,    91,    48,    49,    50,    94,    51,    98,
      52,    60,    61,   116,    99,   143,   190,   144,   145,   234,
     235,    53,    71,    55,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -185
static const yytype_int16 yypact[] =
{
     116,  -185,   255,   232,   232,  -185,   -11,  -185,  -185,   232,
    -185,   232,  -185,  -185,  -185,    -6,   232,   232,  -185,  -185,
    -185,  -185,  -185,    29,  -185,  -185,    20,  -185,  -185,  -185,
    -185,    -4,  -185,  -185,  -185,  -185,  -185,    17,    31,     6,
      16,  -185,    52,    21,    23,    25,    22,    30,    63,   255,
    -185,    32,    -8,    42,    49,    43,    56,    57,    58,    12,
      59,  -185,    51,    61,  -185,  -185,  -185,   209,    62,  -185,
     232,    60,   232,  -185,   232,  -185,   232,  -185,   255,  -185,
     255,  -185,   255,  -185,   255,  -185,   255,  -185,   255,  -185,
     255,  -185,  -185,   255,  -185,   232,   232,    70,  -185,    -8,
     232,   232,   232,  -185,  -185,  -185,   255,    60,   232,   186,
     186,   232,    65,   255,   232,  -185,    60,  -185,  -185,    72,
      76,    20,  -185,    48,    17,  -185,  -185,    73,     6,    16,
      52,    21,    23,    25,    22,    30,    63,  -185,    79,  -185,
      78,    13,    83,    77,    81,    87,  -185,  -185,   101,  -185,
     103,    49,  -185,    91,    80,  -185,   100,   102,    95,   186,
      88,    94,  -185,   108,    98,  -185,    99,   232,   109,  -185,
    -185,  -185,   232,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,   232,    60,   232,  -185,  -185,  -185,   232,
      60,   232,  -185,   232,  -185,   186,    18,   114,  -185,   232,
     100,  -185,  -185,   232,  -185,  -185,  -185,    72,  -185,  -185,
     186,  -185,    78,  -185,  -185,    81,  -185,  -185,   118,  -185,
     100,    18,  -185,  -185,   106,   186,   119,  -185,    14,    99,
    -185,  -185,  -185,   232,  -185,  -185,  -185,  -185,  -185,  -185,
     186,   232,  -185,  -185,  -185,  -185,  -185,  -185,   102,    14,
    -185,  -185,  -185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,  -185,     2,  -185,    33,    84,  -185,  -185,
      -9,   -17,  -185,  -185,  -185,   152,  -185,   -95,  -184,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,   -74,   -49,  -185,  -185,
      54,  -185,   -93,   -53,   -23,  -185,  -185,   -86,   -52,  -185,
    -105,   -55,    -3,  -185,  -185,   -69,    39,    96,    44,    -7,
    -185,    38,     8,    40,    97,    46,    92,    50,   105,    41,
      90,    68,    93,    55,   -38,  -185,  -185,  -185,  -185,    85,
    -185,   168,  -185,    24,  -185,  -185,   -28,     3,  -176,  -185,
    -185,   -13,    71,   104,    53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -145
static const yytype_int16 yytable[] =
{
      56,    57,    25,   127,    65,   157,    59,   115,    59,    64,
      54,    92,    95,    58,   152,   218,   227,    96,    63,   185,
     113,   113,   113,   162,   241,     1,     2,     3,     4,    66,
      69,     5,     6,     7,     8,   114,   236,    67,     9,    97,
      70,    72,    10,    11,    74,    12,    13,    14,   100,    15,
      16,    17,   136,    76,   202,   137,    78,   247,    19,    20,
     101,   102,    82,    21,    22,    80,    90,   124,    84,   129,
      86,    88,   106,   108,    93,   109,   110,   118,   111,   122,
     117,   119,   170,   125,   159,   172,   130,   148,   149,   187,
     220,   213,   141,   142,   146,   153,   163,   216,   167,   150,
     182,   183,  -144,   188,   189,   230,   191,   100,   141,   193,
     195,   161,   197,   199,   151,   196,   201,   114,   203,   206,
     239,    54,   207,     1,     2,     3,     4,   102,   210,     5,
       6,     7,     8,   225,   228,   248,     9,   233,   240,   192,
      10,    11,   238,    12,    13,    14,   205,    15,    16,    17,
      18,   121,    31,   251,   169,   246,    19,    20,   229,   231,
     212,    21,    22,   252,   209,   158,   237,   173,   175,   211,
     128,   176,   250,   174,   132,   179,   134,   131,   177,    62,
     141,   135,   214,   178,   147,   204,   142,   232,   217,   133,
     219,   181,   215,     1,     0,   171,   226,     0,   222,     5,
       0,     7,     8,   180,   194,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,     1,   160,    16,    17,
     154,     0,     5,   222,     7,     8,    19,    20,     0,     9,
     217,    21,    22,    10,    11,     0,    12,    13,    14,     1,
       0,    16,    17,     0,     0,     0,     0,     0,     8,    19,
      20,     0,     9,     0,    21,    22,    10,    11,     0,    12,
      13,    14,     1,     0,    16,     0,     0,     0,     0,     0,
       0,     8,    19,    20,     0,     9,     0,    21,    22,    10,
      11,     0,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
      21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     4,     0,    72,    17,   110,     9,    59,    11,    16,
       2,    49,    20,    24,   107,   191,   200,    25,    24,     6,
       8,     8,     8,   116,    10,     7,     8,     9,    10,     0,
      34,    13,    14,    15,    16,    23,   220,    17,    20,    47,
      23,    10,    24,    25,    38,    27,    28,    29,     6,    31,
      32,    33,    90,    37,   159,    93,     4,   233,    40,    41,
      18,    19,    39,    45,    46,    44,     3,    70,    43,    76,
      48,    41,    23,    30,    42,    19,    19,    26,    20,    17,
      21,    20,    34,    23,    19,    12,    78,   100,   101,   141,
     195,   184,    95,    96,    24,   108,    24,   190,    22,   102,
      21,    23,    19,    26,    23,   210,    19,     6,   111,     6,
      19,   114,    12,    11,   106,    35,    21,    23,    30,    21,
     225,   113,    23,     7,     8,     9,    10,    19,    19,    13,
      14,    15,    16,    19,   203,   240,    20,    19,    19,   148,
      24,    25,    36,    27,    28,    29,   163,    31,    32,    33,
      34,    67,     0,   248,   121,   229,    40,    41,   207,   212,
     183,    45,    46,   249,   167,   111,   221,   128,   130,   172,
      74,   131,   241,   129,    82,   134,    86,    80,   132,    11,
     183,    88,   185,   133,    99,   161,   189,   215,   191,    84,
     193,   136,   189,     7,    -1,   124,   199,    -1,   196,    13,
      -1,    15,    16,   135,   151,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    29,     7,   113,    32,    33,
      34,    -1,    13,   221,    15,    16,    40,    41,    -1,    20,
     233,    45,    46,    24,    25,    -1,    27,    28,    29,     7,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    16,    40,
      41,    -1,    20,    -1,    45,    46,    24,    25,    -1,    27,
      28,    29,     7,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    40,    41,    -1,    20,    -1,    45,    46,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    13,    14,    15,    16,    20,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    40,
      41,    45,    46,    52,    53,    55,    58,    59,    63,    64,
      65,    66,    67,    70,    71,    72,    79,    93,    96,    98,
     100,   101,   103,   105,   107,   109,   111,   113,   115,   116,
     117,   119,   121,   132,   103,   134,    93,    93,    24,    93,
     122,   123,   122,    24,   100,   132,     0,    17,    57,    34,
      23,   133,    10,    94,    38,    97,    37,    99,     4,   102,
      44,   104,    39,   106,    43,   108,    48,   110,    41,   112,
       3,   114,   115,    42,   118,    20,    25,    47,   120,   125,
       6,    18,    19,    60,    61,    62,    23,   135,    30,    19,
      19,    20,    80,     8,    23,    89,   124,    21,    26,    20,
      74,    58,    17,    56,    93,    23,    83,    96,    98,   100,
     103,   105,   107,   109,   111,   113,   115,   115,    81,    82,
      85,    93,    93,   126,   128,   129,    24,   120,   132,   132,
      93,   103,    83,   132,    34,    55,    91,    91,    81,    19,
     134,    93,    83,    24,    75,    76,    78,    22,    73,    57,
      34,   133,    12,    97,    99,   102,   104,   106,   108,   110,
     112,   114,    21,    23,    84,     6,    86,    89,    26,    23,
     127,    19,    61,     6,   135,    19,    35,    12,    69,    11,
      68,    21,    91,    30,   124,    62,    21,    23,    77,    93,
      19,    93,    85,    83,    93,   128,    83,    93,   129,    93,
      91,    54,    55,    66,    92,    19,    93,    69,    96,    78,
      91,    84,   127,    19,   130,   131,    69,    92,    36,    91,
      19,    10,    87,    88,    89,    90,    77,   129,    91,    95,
      96,    68,    88
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 1686 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 269 "parser.y"


void yyerror(const char *s){
   cout<<"f u\n";
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
