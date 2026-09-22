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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONST = 258,                   /* CONST  */
    TYPE = 259,                    /* TYPE  */
    IF = 260,                      /* IF  */
    DO = 261,                      /* DO  */
    NAME = 262,                    /* NAME  */
    UNAME = 263,                   /* UNAME  */
    PNAME = 264,                   /* PNAME  */
    INAME = 265,                   /* INAME  */
    STRING = 266,                  /* STRING  */
    ASSERT = 267,                  /* ASSERT  */
    PRINT = 268,                   /* PRINT  */
    PRINTM = 269,                  /* PRINTM  */
    C_CODE = 270,                  /* C_CODE  */
    C_DECL = 271,                  /* C_DECL  */
    C_EXPR = 272,                  /* C_EXPR  */
    C_STATE = 273,                 /* C_STATE  */
    C_TRACK = 274,                 /* C_TRACK  */
    RUN = 275,                     /* RUN  */
    LEN = 276,                     /* LEN  */
    ENABLED = 277,                 /* ENABLED  */
    EVAL = 278,                    /* EVAL  */
    PC_VAL = 279,                  /* PC_VAL  */
    TYPEDEF = 280,                 /* TYPEDEF  */
    MTYPE = 281,                   /* MTYPE  */
    INLINE = 282,                  /* INLINE  */
    LABEL = 283,                   /* LABEL  */
    OF = 284,                      /* OF  */
    GOTO = 285,                    /* GOTO  */
    BREAK = 286,                   /* BREAK  */
    ELSE = 287,                    /* ELSE  */
    SEMI = 288,                    /* SEMI  */
    FI = 289,                      /* FI  */
    OD = 290,                      /* OD  */
    SEP = 291,                     /* SEP  */
    ATOMIC = 292,                  /* ATOMIC  */
    NON_ATOMIC = 293,              /* NON_ATOMIC  */
    D_STEP = 294,                  /* D_STEP  */
    UNLESS = 295,                  /* UNLESS  */
    TIMEOUT = 296,                 /* TIMEOUT  */
    NONPROGRESS = 297,             /* NONPROGRESS  */
    ACTIVE = 298,                  /* ACTIVE  */
    PROCTYPE = 299,                /* PROCTYPE  */
    D_PROCTYPE = 300,              /* D_PROCTYPE  */
    HIDDEN = 301,                  /* HIDDEN  */
    SHOW = 302,                    /* SHOW  */
    ISLOCAL = 303,                 /* ISLOCAL  */
    PRIORITY = 304,                /* PRIORITY  */
    PROVIDED = 305,                /* PROVIDED  */
    FULL = 306,                    /* FULL  */
    EMPTY = 307,                   /* EMPTY  */
    NFULL = 308,                   /* NFULL  */
    NEMPTY = 309,                  /* NEMPTY  */
    XU = 310,                      /* XU  */
    CLAIM = 311,                   /* CLAIM  */
    TRACE = 312,                   /* TRACE  */
    INIT = 313,                    /* INIT  */
    WHILE = 314,                   /* WHILE  */
    WHEN = 315,                    /* WHEN  */
    WAIT = 316,                    /* WAIT  */
    RESET = 317,                   /* RESET  */
    THEN = 318,                    /* THEN  */
    SPEC = 319,                    /* SPEC  */
    EVENTUALLY = 320,              /* EVENTUALLY  */
    ALWAYS = 321,                  /* ALWAYS  */
    GLOBALLY = 322,                /* GLOBALLY  */
    FINALLY = 323,                 /* FINALLY  */
    CHECK = 324,                   /* CHECK  */
    WITHIN = 325,                  /* WITHIN  */
    MINIMIZE = 326,                /* MINIMIZE  */
    TIME = 327,                    /* TIME  */
    COST = 328,                    /* COST  */
    QUALITY = 329,                 /* QUALITY  */
    ASGN = 330,                    /* ASGN  */
    SND = 331,                     /* SND  */
    O_SND = 332,                   /* O_SND  */
    RCV = 333,                     /* RCV  */
    R_RCV = 334,                   /* R_RCV  */
    OR = 335,                      /* OR  */
    AND = 336,                     /* AND  */
    EQ = 337,                      /* EQ  */
    NE = 338,                      /* NE  */
    GT = 339,                      /* GT  */
    LT = 340,                      /* LT  */
    GE = 341,                      /* GE  */
    LE = 342,                      /* LE  */
    LSHIFT = 343,                  /* LSHIFT  */
    RSHIFT = 344,                  /* RSHIFT  */
    INCR = 345,                    /* INCR  */
    DECR = 346,                    /* DECR  */
    UMIN = 347,                    /* UMIN  */
    NEG = 348,                     /* NEG  */
    COUNT = 349,                   /* COUNT  */
    CONTEXT = 350,                 /* CONTEXT  */
    DOT = 351                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define SND 331
#define O_SND 332
#define RCV 333
#define R_RCV 334
#define OR 335
#define AND 336
#define EQ 337
#define NE 338
#define GT 339
#define LT 340
#define GE 341
#define LE 342
#define LSHIFT 343
#define RSHIFT 344
#define INCR 345
#define DECR 346
#define UMIN 347
#define NEG 348
#define COUNT 349
#define CONTEXT 350
#define DOT 351

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "promela.y"
 
	int       				iVal;
	char*    				sVal;
	tDataTuple				pDataVal;
	ptExpNode				pExpVal;
	ptSymTabNode			pSymTabNodeVal;
	struct fsm_*			pFsmVal;
	struct list_ *			pList;
    struct _costFormula *    pCostFormula;

#line 270 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
