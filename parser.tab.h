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
    LOGICAL_OPERATOR = 260,        /* LOGICAL_OPERATOR  */
    BITWISE_OPERATOR = 261,        /* BITWISE_OPERATOR  */
    ASSIGNMENT_OPERATOR = 262,     /* ASSIGNMENT_OPERATOR  */
    DATA_TYPE = 263,               /* DATA_TYPE  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    IF = 266,                      /* IF  */
    ELIF = 267,                    /* ELIF  */
    ELSE = 268,                    /* ELSE  */
    BREAK = 269,                   /* BREAK  */
    CLASS = 270,                   /* CLASS  */
    CONTINUE = 271,                /* CONTINUE  */
    LIST = 272,                    /* LIST  */
    SEMICOLON = 273,               /* SEMICOLON  */
    AUGASSIGNMENT_OPERATOR = 274,  /* AUGASSIGNMENT_OPERATOR  */
    COLON = 275,                   /* COLON  */
    LEFT_BRACKET = 276,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 277,           /* RIGHT_BRACKET  */
    RETURN_ARROW = 278,            /* RETURN_ARROW  */
    COMMA = 279,                   /* COMMA  */
    NAME = 280,                    /* NAME  */
    LEFT_SQUARE_BRACKET = 281,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 282,    /* RIGHT_SQUARE_BRACKET  */
    NONE = 283,                    /* NONE  */
    TRUE = 284,                    /* TRUE  */
    FALSE = 285,                   /* FALSE  */
    IN = 286,                      /* IN  */
    DEF = 287,                     /* DEF  */
    NOT = 288,                     /* NOT  */
    RETURN = 289,                  /* RETURN  */
    NEWLINE = 290,                 /* NEWLINE  */
    INDENT = 291,                  /* INDENT  */
    DEDENT = 292,                  /* DEDENT  */
    AND = 293,                     /* AND  */
    OR = 294,                      /* OR  */
    XOR = 295,                     /* XOR  */
    BIT_NOT = 296,                 /* BIT_NOT  */
    ADD_SUB = 297,                 /* ADD_SUB  */
    POWER = 298,                   /* POWER  */
    NUMBER = 299,                  /* NUMBER  */
    STRING = 300,                  /* STRING  */
    DOT = 301,                     /* DOT  */
    SHIFT = 302,                   /* SHIFT  */
    LEFT_CURLY_BRACKET = 303,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 304      /* RIGHT_CURLY_BRACKET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
