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
     CONST = 258,
     TYPE = 259,
     IF = 260,
     DO = 261,
     NAME = 262,
     UNAME = 263,
     PNAME = 264,
     INAME = 265,
     STRING = 266,
     ASSERT = 267,
     PRINT = 268,
     PRINTM = 269,
     C_CODE = 270,
     C_DECL = 271,
     C_EXPR = 272,
     C_STATE = 273,
     C_TRACK = 274,
     RUN = 275,
     LEN = 276,
     ENABLED = 277,
     EVAL = 278,
     PC_VAL = 279,
     TYPEDEF = 280,
     MTYPE = 281,
     INLINE = 282,
     LABEL = 283,
     OF = 284,
     GOTO = 285,
     BREAK = 286,
     ELSE = 287,
     SEMI = 288,
     FI = 289,
     OD = 290,
     SEP = 291,
     ATOMIC = 292,
     NON_ATOMIC = 293,
     D_STEP = 294,
     UNLESS = 295,
     TIMEOUT = 296,
     NONPROGRESS = 297,
     ACTIVE = 298,
     PROCTYPE = 299,
     D_PROCTYPE = 300,
     HIDDEN = 301,
     SHOW = 302,
     ISLOCAL = 303,
     PRIORITY = 304,
     PROVIDED = 305,
     FULL = 306,
     EMPTY = 307,
     NFULL = 308,
     NEMPTY = 309,
     XU = 310,
     CLAIM = 311,
     TRACE = 312,
     INIT = 313,
     WHILE = 314,
     WHEN = 315,
     WAIT = 316,
     RESET = 317,
     THEN = 318,
     SPEC = 319,
     EVENTUALLY = 320,
     ALWAYS = 321,
     GLOBALLY = 322,
     FINALLY = 323,
     CHECK = 324,
     WITHIN = 325,
     MINIMIZE = 326,
     TIME = 327,
     COST = 328,
     QUALITY = 329,
     ASGN = 330,
     R_RCV = 331,
     RCV = 332,
     O_SND = 333,
     SND = 334,
     OR = 335,
     AND = 336,
     NE = 337,
     EQ = 338,
     LE = 339,
     GE = 340,
     LT = 341,
     GT = 342,
     RSHIFT = 343,
     LSHIFT = 344,
     DECR = 345,
     INCR = 346,
     CONTEXT = 347,
     COUNT = 348,
     NEG = 349,
     UMIN = 350,
     DOT = 351
   };
#endif
/* Tokens.  */
#define CONST 258
#define TYPE 259
#define IF 260
#define DO 261
#define NAME 262
#define UNAME 263
#define PNAME 264
#define INAME 265
#define STRING 266
#define ASSERT 267
#define PRINT 268
#define PRINTM 269
#define C_CODE 270
#define C_DECL 271
#define C_EXPR 272
#define C_STATE 273
#define C_TRACK 274
#define RUN 275
#define LEN 276
#define ENABLED 277
#define EVAL 278
#define PC_VAL 279
#define TYPEDEF 280
#define MTYPE 281
#define INLINE 282
#define LABEL 283
#define OF 284
#define GOTO 285
#define BREAK 286
#define ELSE 287
#define SEMI 288
#define FI 289
#define OD 290
#define SEP 291
#define ATOMIC 292
#define NON_ATOMIC 293
#define D_STEP 294
#define UNLESS 295
#define TIMEOUT 296
#define NONPROGRESS 297
#define ACTIVE 298
#define PROCTYPE 299
#define D_PROCTYPE 300
#define HIDDEN 301
#define SHOW 302
#define ISLOCAL 303
#define PRIORITY 304
#define PROVIDED 305
#define FULL 306
#define EMPTY 307
#define NFULL 308
#define NEMPTY 309
#define XU 310
#define CLAIM 311
#define TRACE 312
#define INIT 313
#define WHILE 314
#define WHEN 315
#define WAIT 316
#define RESET 317
#define THEN 318
#define SPEC 319
#define EVENTUALLY 320
#define ALWAYS 321
#define GLOBALLY 322
#define FINALLY 323
#define CHECK 324
#define WITHIN 325
#define MINIMIZE 326
#define TIME 327
#define COST 328
#define QUALITY 329
#define ASGN 330
#define R_RCV 331
#define RCV 332
#define O_SND 333
#define SND 334
#define OR 335
#define AND 336
#define NE 337
#define EQ 338
#define LE 339
#define GE 340
#define LT 341
#define GT 342
#define RSHIFT 343
#define LSHIFT 344
#define DECR 345
#define INCR 346
#define CONTEXT 347
#define COUNT 348
#define NEG 349
#define UMIN 350
#define DOT 351




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "promela.y"
{ 
	int       				iVal;
	char*    				sVal;
	tDataTuple				pDataVal;
	ptExpNode				pExpVal;
	ptSymTabNode			pSymTabNodeVal;
	struct fsm_*			pFsmVal;
	struct list_ *			pList;
    struct _costFormula *    pCostFormula;
}
/* Line 1529 of yacc.c.  */
#line 252 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



