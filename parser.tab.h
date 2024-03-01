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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

