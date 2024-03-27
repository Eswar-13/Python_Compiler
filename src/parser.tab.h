/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ARITHMETIC_OPERATOR = 258,     /* ARITHMETIC_OPERATOR  */
    RELATIONAL_OPERATOR = 259,     /* RELATIONAL_OPERATOR  */
    BITWISE_OPERATOR = 260,        /* BITWISE_OPERATOR  */
    ASSIGNMENT_OPERATOR = 261,     /* ASSIGNMENT_OPERATOR  */
    DATA_TYPE = 262,               /* DATA_TYPE  */
    FOR = 263,                     /* FOR  */
    WHILE = 264,                   /* WHILE  */
    IF = 265,                      /* IF  */
    ELIF = 266,                    /* ELIF  */
    ELSE = 267,                    /* ELSE  */
    BREAK = 268,                   /* BREAK  */
    CLASS = 269,                   /* CLASS  */
    CONTINUE = 270,                /* CONTINUE  */
    LIST = 271,                    /* LIST  */
    SEMICOLON = 272,               /* SEMICOLON  */
    AUGASSIGNMENT_OPERATOR = 273,  /* AUGASSIGNMENT_OPERATOR  */
    COLON = 274,                   /* COLON  */
    LEFT_BRACKET = 275,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 276,           /* RIGHT_BRACKET  */
    RETURN_ARROW = 277,            /* RETURN_ARROW  */
    COMMA = 278,                   /* COMMA  */
    NAME = 279,                    /* NAME  */
    LEFT_SQUARE_BRACKET = 280,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 281,    /* RIGHT_SQUARE_BRACKET  */
    NONE = 282,                    /* NONE  */
    TRUE = 283,                    /* TRUE  */
    FALSE = 284,                   /* FALSE  */
    IN = 285,                      /* IN  */
    DEF = 286,                     /* DEF  */
    NOT = 287,                     /* NOT  */
    RETURN = 288,                  /* RETURN  */
    NEWLINE = 289,                 /* NEWLINE  */
    INDENT = 290,                  /* INDENT  */
    DEDENT = 291,                  /* DEDENT  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    XOR = 294,                     /* XOR  */
    BIT_NOT = 295,                 /* BIT_NOT  */
    ADD = 296,                     /* ADD  */
    SUB = 297,                     /* SUB  */
    POWER = 298,                   /* POWER  */
    BIT_AND = 299,                 /* BIT_AND  */
    BIT_OR = 300,                  /* BIT_OR  */
    INT = 301,                     /* INT  */
    FLOAT = 302,                   /* FLOAT  */
    STRING = 303,                  /* STRING  */
    DOT = 304,                     /* DOT  */
    L_SHIFT = 305,                 /* L_SHIFT  */
    R_SHIFT = 306,                 /* R_SHIFT  */
    STRING_1 = 307,                /* STRING_1  */
    LEFT_CURLY_BRACKET = 308,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 309,     /* RIGHT_CURLY_BRACKET  */
    INVALID = 310,                 /* INVALID  */
    low = 311,                     /* low  */
    low1 = 312,                    /* low1  */
    low2 = 313,                    /* low2  */
    low3 = 314,                    /* low3  */
    low4 = 315,                    /* low4  */
    low5 = 316,                    /* low5  */
    low6 = 317,                    /* low6  */
    high = 318,                    /* high  */
    high1 = 319,                   /* high1  */
    SHIFT = 320                    /* SHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 123 "parser.y"

   struct{
     int top;
     char * reg;
     int type;
     int jump;
     char* lexeme;
   }attributes;

#line 139 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
