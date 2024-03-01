/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ARITHMETIC_OPERATOR = 258,
     RELATIONAL_OPERATOR = 259,
     LOGICAL_OPERATOR = 260,
     BITWISE_OPERATOR = 261,
     ASSIGNMENT_OPERATOR = 262,
     DATA_TYPE = 263,
     FOR = 264,
     WHILE = 265,
     IF = 266,
     ELIF = 267,
     ELSE = 268,
     BREAK = 269,
     CLASS = 270,
     CONTINUE = 271,
     LIST = 272,
     SEMICOLON = 273,
     AUGASSIGNMENT_OPERATOR = 274,
     COLON = 275,
     LEFT_BRACKET = 276,
     RIGHT_BRACKET = 277,
     RETURN_ARROW = 278,
     COMMA = 279,
     NAME = 280,
     LEFT_SQUARE_BRACKET = 281,
     RIGHT_SQUARE_BRACKET = 282,
     NONE = 283,
     TRUE = 284,
     FALSE = 285,
     IN = 286,
     DEF = 287,
     NOT = 288,
     RETURN = 289,
     NEWLINE = 290,
     INDENT = 291,
     DEDENT = 292,
     AND = 293,
     OR = 294,
     XOR = 295,
     BIT_NOT = 296,
     ADD_SUB = 297,
     POWER = 298,
     NUMBER = 299,
     STRING = 300,
     DOT = 301,
     SHIFT = 302,
     LEFT_CURLY_BRACKET = 303,
     RIGHT_CURLY_BRACKET = 304
   };
#endif
/* Tokens.  */
#define ARITHMETIC_OPERATOR 258
#define RELATIONAL_OPERATOR 259
#define LOGICAL_OPERATOR 260
#define BITWISE_OPERATOR 261
#define ASSIGNMENT_OPERATOR 262
#define DATA_TYPE 263
#define FOR 264
#define WHILE 265
#define IF 266
#define ELIF 267
#define ELSE 268
#define BREAK 269
#define CLASS 270
#define CONTINUE 271
#define LIST 272
#define SEMICOLON 273
#define AUGASSIGNMENT_OPERATOR 274
#define COLON 275
#define LEFT_BRACKET 276
#define RIGHT_BRACKET 277
#define RETURN_ARROW 278
#define COMMA 279
#define NAME 280
#define LEFT_SQUARE_BRACKET 281
#define RIGHT_SQUARE_BRACKET 282
#define NONE 283
#define TRUE 284
#define FALSE 285
#define IN 286
#define DEF 287
#define NOT 288
#define RETURN 289
#define NEWLINE 290
#define INDENT 291
#define DEDENT 292
#define AND 293
#define OR 294
#define XOR 295
#define BIT_NOT 296
#define ADD_SUB 297
#define POWER 298
#define NUMBER 299
#define STRING 300
#define DOT 301
#define SHIFT 302
#define LEFT_CURLY_BRACKET 303
#define RIGHT_CURLY_BRACKET 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

