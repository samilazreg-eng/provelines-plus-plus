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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "promela.y"


// This is based on the original Yacc grammar of SPIN (spin.y):

/* Copyright (c) 1989-2003 by Lucent Technologies, Bell Laboratories.     */
/* All Rights Reserved.  This software is for educational purposes only.  */
/* No guarantee whatsoever is expressed or implied by the distribution of */
/* this code.  Permission is given to distribute this code provided that  */
/* this introductory message is not removed and no monies are exchanged.  */
/* Software written by Gerard J. Holzmann.  For tool documentation see:   */
/*             http://spinroot.com/                                       */
/* Send all bug-reports and/or questions to: bugs@spinroot.com            */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "error.h"
#include "main.h"
#include "cnf.h"
#include "list.h"
#include "boolFct.h"
#include "symbols.h"
#include "costFormula.h"
#include "automata.h"

// extern - lex
extern int nbrLines;


#line 102 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 358 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_TYPE = 4,                       /* TYPE  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_NAME = 7,                       /* NAME  */
  YYSYMBOL_UNAME = 8,                      /* UNAME  */
  YYSYMBOL_PNAME = 9,                      /* PNAME  */
  YYSYMBOL_INAME = 10,                     /* INAME  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_ASSERT = 12,                    /* ASSERT  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_PRINTM = 14,                    /* PRINTM  */
  YYSYMBOL_C_CODE = 15,                    /* C_CODE  */
  YYSYMBOL_C_DECL = 16,                    /* C_DECL  */
  YYSYMBOL_C_EXPR = 17,                    /* C_EXPR  */
  YYSYMBOL_C_STATE = 18,                   /* C_STATE  */
  YYSYMBOL_C_TRACK = 19,                   /* C_TRACK  */
  YYSYMBOL_RUN = 20,                       /* RUN  */
  YYSYMBOL_LEN = 21,                       /* LEN  */
  YYSYMBOL_ENABLED = 22,                   /* ENABLED  */
  YYSYMBOL_EVAL = 23,                      /* EVAL  */
  YYSYMBOL_PC_VAL = 24,                    /* PC_VAL  */
  YYSYMBOL_TYPEDEF = 25,                   /* TYPEDEF  */
  YYSYMBOL_MTYPE = 26,                     /* MTYPE  */
  YYSYMBOL_INLINE = 27,                    /* INLINE  */
  YYSYMBOL_LABEL = 28,                     /* LABEL  */
  YYSYMBOL_OF = 29,                        /* OF  */
  YYSYMBOL_GOTO = 30,                      /* GOTO  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_SEMI = 33,                      /* SEMI  */
  YYSYMBOL_FI = 34,                        /* FI  */
  YYSYMBOL_OD = 35,                        /* OD  */
  YYSYMBOL_SEP = 36,                       /* SEP  */
  YYSYMBOL_ATOMIC = 37,                    /* ATOMIC  */
  YYSYMBOL_NON_ATOMIC = 38,                /* NON_ATOMIC  */
  YYSYMBOL_D_STEP = 39,                    /* D_STEP  */
  YYSYMBOL_UNLESS = 40,                    /* UNLESS  */
  YYSYMBOL_TIMEOUT = 41,                   /* TIMEOUT  */
  YYSYMBOL_NONPROGRESS = 42,               /* NONPROGRESS  */
  YYSYMBOL_ACTIVE = 43,                    /* ACTIVE  */
  YYSYMBOL_PROCTYPE = 44,                  /* PROCTYPE  */
  YYSYMBOL_D_PROCTYPE = 45,                /* D_PROCTYPE  */
  YYSYMBOL_HIDDEN = 46,                    /* HIDDEN  */
  YYSYMBOL_SHOW = 47,                      /* SHOW  */
  YYSYMBOL_ISLOCAL = 48,                   /* ISLOCAL  */
  YYSYMBOL_PRIORITY = 49,                  /* PRIORITY  */
  YYSYMBOL_PROVIDED = 50,                  /* PROVIDED  */
  YYSYMBOL_FULL = 51,                      /* FULL  */
  YYSYMBOL_EMPTY = 52,                     /* EMPTY  */
  YYSYMBOL_NFULL = 53,                     /* NFULL  */
  YYSYMBOL_NEMPTY = 54,                    /* NEMPTY  */
  YYSYMBOL_XU = 55,                        /* XU  */
  YYSYMBOL_CLAIM = 56,                     /* CLAIM  */
  YYSYMBOL_TRACE = 57,                     /* TRACE  */
  YYSYMBOL_INIT = 58,                      /* INIT  */
  YYSYMBOL_WHILE = 59,                     /* WHILE  */
  YYSYMBOL_WHEN = 60,                      /* WHEN  */
  YYSYMBOL_WAIT = 61,                      /* WAIT  */
  YYSYMBOL_RESET = 62,                     /* RESET  */
  YYSYMBOL_THEN = 63,                      /* THEN  */
  YYSYMBOL_SPEC = 64,                      /* SPEC  */
  YYSYMBOL_EVENTUALLY = 65,                /* EVENTUALLY  */
  YYSYMBOL_ALWAYS = 66,                    /* ALWAYS  */
  YYSYMBOL_GLOBALLY = 67,                  /* GLOBALLY  */
  YYSYMBOL_FINALLY = 68,                   /* FINALLY  */
  YYSYMBOL_CHECK = 69,                     /* CHECK  */
  YYSYMBOL_WITHIN = 70,                    /* WITHIN  */
  YYSYMBOL_MINIMIZE = 71,                  /* MINIMIZE  */
  YYSYMBOL_TIME = 72,                      /* TIME  */
  YYSYMBOL_COST = 73,                      /* COST  */
  YYSYMBOL_QUALITY = 74,                   /* QUALITY  */
  YYSYMBOL_ASGN = 75,                      /* ASGN  */
  YYSYMBOL_SND = 76,                       /* SND  */
  YYSYMBOL_O_SND = 77,                     /* O_SND  */
  YYSYMBOL_RCV = 78,                       /* RCV  */
  YYSYMBOL_R_RCV = 79,                     /* R_RCV  */
  YYSYMBOL_OR = 80,                        /* OR  */
  YYSYMBOL_AND = 81,                       /* AND  */
  YYSYMBOL_82_ = 82,                       /* '|'  */
  YYSYMBOL_83_ = 83,                       /* '^'  */
  YYSYMBOL_84_ = 84,                       /* '&'  */
  YYSYMBOL_EQ = 85,                        /* EQ  */
  YYSYMBOL_NE = 86,                        /* NE  */
  YYSYMBOL_GT = 87,                        /* GT  */
  YYSYMBOL_LT = 88,                        /* LT  */
  YYSYMBOL_GE = 89,                        /* GE  */
  YYSYMBOL_LE = 90,                        /* LE  */
  YYSYMBOL_LSHIFT = 91,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 92,                    /* RSHIFT  */
  YYSYMBOL_93_ = 93,                       /* '+'  */
  YYSYMBOL_94_ = 94,                       /* '-'  */
  YYSYMBOL_95_ = 95,                       /* '*'  */
  YYSYMBOL_96_ = 96,                       /* '/'  */
  YYSYMBOL_97_ = 97,                       /* '%'  */
  YYSYMBOL_INCR = 98,                      /* INCR  */
  YYSYMBOL_DECR = 99,                      /* DECR  */
  YYSYMBOL_100_ = 100,                     /* '~'  */
  YYSYMBOL_UMIN = 101,                     /* UMIN  */
  YYSYMBOL_NEG = 102,                      /* NEG  */
  YYSYMBOL_COUNT = 103,                    /* COUNT  */
  YYSYMBOL_CONTEXT = 104,                  /* CONTEXT  */
  YYSYMBOL_DOT = 105,                      /* DOT  */
  YYSYMBOL_106_ = 106,                     /* ','  */
  YYSYMBOL_107_ = 107,                     /* '('  */
  YYSYMBOL_108_ = 108,                     /* ')'  */
  YYSYMBOL_109_ = 109,                     /* '['  */
  YYSYMBOL_110_ = 110,                     /* ']'  */
  YYSYMBOL_111_ = 111,                     /* '.'  */
  YYSYMBOL_112_ = 112,                     /* '{'  */
  YYSYMBOL_113_ = 113,                     /* '}'  */
  YYSYMBOL_114_ = 114,                     /* ':'  */
  YYSYMBOL_115_ = 115,                     /* '@'  */
  YYSYMBOL_YYACCEPT = 116,                 /* $accept  */
  YYSYMBOL_start_parsing = 117,            /* start_parsing  */
  YYSYMBOL_cformula = 118,                 /* cformula  */
  YYSYMBOL_props = 119,                    /* props  */
  YYSYMBOL_prop = 120,                     /* prop  */
  YYSYMBOL_program = 121,                  /* program  */
  YYSYMBOL_units = 122,                    /* units  */
  YYSYMBOL_unit = 123,                     /* unit  */
  YYSYMBOL_proc = 124,                     /* proc  */
  YYSYMBOL_proctype = 125,                 /* proctype  */
  YYSYMBOL_inst = 126,                     /* inst  */
  YYSYMBOL_init = 127,                     /* init  */
  YYSYMBOL_claim = 128,                    /* claim  */
  YYSYMBOL_events = 129,                   /* events  */
  YYSYMBOL_utype = 130,                    /* utype  */
  YYSYMBOL_nm = 131,                       /* nm  */
  YYSYMBOL_ns = 132,                       /* ns  */
  YYSYMBOL_c_fcts = 133,                   /* c_fcts  */
  YYSYMBOL_cstate = 134,                   /* cstate  */
  YYSYMBOL_ccode = 135,                    /* ccode  */
  YYSYMBOL_cexpr = 136,                    /* cexpr  */
  YYSYMBOL_body = 137,                     /* body  */
  YYSYMBOL_sequence = 138,                 /* sequence  */
  YYSYMBOL_step = 139,                     /* step  */
  YYSYMBOL_timed_stmnt = 140,              /* timed_stmnt  */
  YYSYMBOL_nf_stmnt = 141,                 /* nf_stmnt  */
  YYSYMBOL_cost_stmnt = 142,               /* cost_stmnt  */
  YYSYMBOL_vis = 143,                      /* vis  */
  YYSYMBOL_asgn = 144,                     /* asgn  */
  YYSYMBOL_one_decl = 145,                 /* one_decl  */
  YYSYMBOL_decl_lst = 146,                 /* decl_lst  */
  YYSYMBOL_decl = 147,                     /* decl  */
  YYSYMBOL_vref_lst = 148,                 /* vref_lst  */
  YYSYMBOL_var_list = 149,                 /* var_list  */
  YYSYMBOL_ivar = 150,                     /* ivar  */
  YYSYMBOL_ch_init = 151,                  /* ch_init  */
  YYSYMBOL_vardcl = 152,                   /* vardcl  */
  YYSYMBOL_varref = 153,                   /* varref  */
  YYSYMBOL_pfld = 154,                     /* pfld  */
  YYSYMBOL_cmpnd = 155,                    /* cmpnd  */
  YYSYMBOL_sfld = 156,                     /* sfld  */
  YYSYMBOL_stmnt = 157,                    /* stmnt  */
  YYSYMBOL_Special = 158,                  /* Special  */
  YYSYMBOL_Stmnt = 159,                    /* Stmnt  */
  YYSYMBOL_options = 160,                  /* options  */
  YYSYMBOL_option = 161,                   /* option  */
  YYSYMBOL_OS = 162,                       /* OS  */
  YYSYMBOL_MS = 163,                       /* MS  */
  YYSYMBOL_aname = 164,                    /* aname  */
  YYSYMBOL_expr = 165,                     /* expr  */
  YYSYMBOL_Opt_priority = 166,             /* Opt_priority  */
  YYSYMBOL_full_expr = 167,                /* full_expr  */
  YYSYMBOL_Opt_enabler = 168,              /* Opt_enabler  */
  YYSYMBOL_Expr = 169,                     /* Expr  */
  YYSYMBOL_Probe = 170,                    /* Probe  */
  YYSYMBOL_basetype = 171,                 /* basetype  */
  YYSYMBOL_typ_list = 172,                 /* typ_list  */
  YYSYMBOL_args = 173,                     /* args  */
  YYSYMBOL_prargs = 174,                   /* prargs  */
  YYSYMBOL_margs = 175,                    /* margs  */
  YYSYMBOL_arg = 176,                      /* arg  */
  YYSYMBOL_rarg = 177,                     /* rarg  */
  YYSYMBOL_rargs = 178,                    /* rargs  */
  YYSYMBOL_nlst = 179                      /* nlst  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1626

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  116
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  476

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   351


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
       2,     2,     2,     2,     2,     2,     2,    97,    84,     2,
     107,   108,    95,    93,   106,    94,   111,    96,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   114,     2,
       2,     2,     2,     2,   115,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   109,     2,   110,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,    82,   113,   100,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    85,    86,    87,
      88,    89,    90,    91,    92,    98,    99,   101,   102,   103,
     104,   105
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   100,   101,   104,   105,   108,   109,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   157,   160,
     161,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     176,   186,   187,   190,   191,   192,   193,   202,   209,   217,
     225,   228,   258,   259,   262,   265,   266,   269,   270,   271,
     272,   275,   276,   279,   282,   285,   296,   309,   310,   311,
     312,   313,   314,   315,   318,   321,   322,   325,   326,   329,
     330,   331,   332,   335,   336,   342,   355,   368,   374,   375,
     379,   380,   383,   384,   387,   388,   391,   392,   400,   403,
     406,   407,   408,   411,   414,   415,   418,   419,   422,   423,
     426,   427,   430,   433,   434,   435,   436,   437,   438,   440,
     443,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   465,   466,
     469,   472,   473,   476,   477,   480,   481,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   511,
     512,   513,   514,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   532,   533,   536,
     537,   540,   541,   546,   547,   548,   549,   550,   551,   552,
     553,   555,   556,   557,   558,   561,   562,   566,   574,   586,
     587,   591,   592,   596,   597,   600,   601,   604,   605,   606,
     607,   611,   612,   613,   614,   617,   618,   619
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "TYPE", "IF",
  "DO", "NAME", "UNAME", "PNAME", "INAME", "STRING", "ASSERT", "PRINT",
  "PRINTM", "C_CODE", "C_DECL", "C_EXPR", "C_STATE", "C_TRACK", "RUN",
  "LEN", "ENABLED", "EVAL", "PC_VAL", "TYPEDEF", "MTYPE", "INLINE",
  "LABEL", "OF", "GOTO", "BREAK", "ELSE", "SEMI", "FI", "OD", "SEP",
  "ATOMIC", "NON_ATOMIC", "D_STEP", "UNLESS", "TIMEOUT", "NONPROGRESS",
  "ACTIVE", "PROCTYPE", "D_PROCTYPE", "HIDDEN", "SHOW", "ISLOCAL",
  "PRIORITY", "PROVIDED", "FULL", "EMPTY", "NFULL", "NEMPTY", "XU",
  "CLAIM", "TRACE", "INIT", "WHILE", "WHEN", "WAIT", "RESET", "THEN",
  "SPEC", "EVENTUALLY", "ALWAYS", "GLOBALLY", "FINALLY", "CHECK", "WITHIN",
  "MINIMIZE", "TIME", "COST", "QUALITY", "ASGN", "SND", "O_SND", "RCV",
  "R_RCV", "OR", "AND", "'|'", "'^'", "'&'", "EQ", "NE", "GT", "LT", "GE",
  "LE", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "INCR",
  "DECR", "'~'", "UMIN", "NEG", "COUNT", "CONTEXT", "DOT", "','", "'('",
  "')'", "'['", "']'", "'.'", "'{'", "'}'", "':'", "'@'", "$accept",
  "start_parsing", "cformula", "props", "prop", "program", "units", "unit",
  "proc", "proctype", "inst", "init", "claim", "events", "utype", "nm",
  "ns", "c_fcts", "cstate", "ccode", "cexpr", "body", "sequence", "step",
  "timed_stmnt", "nf_stmnt", "cost_stmnt", "vis", "asgn", "one_decl",
  "decl_lst", "decl", "vref_lst", "var_list", "ivar", "ch_init", "vardcl",
  "varref", "pfld", "cmpnd", "sfld", "stmnt", "Special", "Stmnt",
  "options", "option", "OS", "MS", "aname", "expr", "Opt_priority",
  "full_expr", "Opt_enabler", "Expr", "Probe", "basetype", "typ_list",
  "args", "prargs", "margs", "arg", "rarg", "rargs", "nlst", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-311)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     859,  -311,   -86,  -311,  -311,     8,    23,    38,    36,  -311,
     -29,  -311,  -311,  -311,   -28,   -28,    56,    40,    10,    15,
      90,    21,   629,  -311,  1072,  -311,  -311,   166,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,    74,  -311,  -311,    25,
    -311,   917,   103,   133,    59,  -311,  -311,    61,    14,   519,
    -311,  -311,   172,   -28,    15,   318,   175,   413,  -311,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,  -311,  -311,  -311,   198,
      17,   200,     7,  -311,  -311,    39,  -311,   165,   102,   105,
     114,  -311,  -311,   917,   917,   917,   149,   917,  -311,   150,
    1104,   246,   251,   109,   917,   153,   154,   160,   230,   230,
     -60,   162,   901,   163,   167,   265,  -311,  -311,   161,   164,
     170,   171,   174,   178,     7,   181,   186,   203,   901,   519,
    -311,   267,  -311,  -311,  -311,   196,  -311,   392,   263,  -311,
    -311,  1424,  -311,   159,  -311,  -311,  -311,   521,  -311,    25,
    -311,   629,   886,  1458,  1488,  1516,   763,   386,   386,   121,
     121,   121,   121,    66,    66,  -311,  -311,  -311,   197,   -21,
    -311,   194,  -311,   201,   233,  -311,  -311,   917,   175,   303,
    -311,  -311,    97,     7,   917,   917,  -311,  -311,  -311,   917,
     945,   202,   204,   917,   917,   917,   917,   917,   917,   917,
     917,   917,   917,   917,   917,   917,   917,   917,   917,   917,
     917,  -311,  -311,  -311,   279,   207,  1397,   209,  -311,  -311,
    -311,   917,   519,   281,   230,   286,   627,   917,  -311,   312,
      41,  -311,   519,   519,     7,     7,     7,     7,  -311,   218,
     917,   324,   329,   974,    71,   267,    22,   222,   411,   168,
     901,   917,   917,     6,    24,  -311,  -311,   735,   901,   901,
     901,   901,     9,  -311,    -6,   335,   336,   333,   200,   761,
    1135,  -311,  -311,   917,     7,   238,  1166,  1195,  1224,   917,
    -311,    76,    76,   602,  1085,  1473,  1502,  1529,   306,   306,
     490,   490,   490,   490,   261,   261,    70,    70,  -311,  -311,
    -311,   109,  -311,   917,  -311,  1253,   267,  -311,  -311,  -311,
      20,  -311,  -311,  -311,   241,   235,   242,   244,   267,   267,
     254,   255,   259,   260,     7,  1282,  -311,  -311,  -311,   256,
    -311,  -311,  -311,  -311,  -311,  1369,  -311,  -311,  -311,  -311,
     252,    76,   367,    76,  -311,   141,  -311,    76,  -311,  -311,
     731,   291,  1085,  -311,   731,   291,  1085,  -311,  -311,   283,
    -311,   271,   272,  -311,  -311,     3,  -311,   380,  -311,  1442,
     145,   280,   294,  -311,  -311,  -311,  -311,  1069,   297,   298,
    -311,  -311,   299,  -311,   735,   277,   917,   282,  -311,  -311,
     274,   300,  -311,  -311,  -311,  -311,  -311,   348,  -311,   917,
     917,   325,  -311,   307,    76,    76,   332,   419,    56,  -311,
    -311,  -311,  -311,   320,   175,   430,    56,   331,   917,  -311,
    -311,  -311,   147,  -311,  -311,  -311,  -311,  -311,   735,   337,
    1311,  -311,  -311,  -311,   338,  -311,   334,   389,   418,  -311,
    -311,  -311,   917,  1340,   -56,  -311,  -311,  -311,  -311,   376,
     344,   -28,   342,   347,  -311,   366,   901,  -311,   142,    56,
     457,   353,  -311,  -311,   371,   365,  -311,   382,  -311,   142,
    -311,   412,  -311,   399,   489,  -311
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      43,    27,   104,    61,    62,     0,     0,     0,     0,    39,
      44,    80,    81,    82,     0,     0,   187,     0,     0,     0,
       0,     3,     7,     2,    43,    29,    31,     0,    32,    33,
      34,    36,    38,    37,    56,    55,     0,    35,    26,   108,
     103,     0,     0,     0,     0,    52,    53,     0,     0,    79,
      49,    50,     0,     0,     0,    43,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    41,    42,     0,
      83,     0,     0,   106,   179,     0,    63,     0,     0,     0,
       0,   180,   181,     0,     0,     0,     0,     0,   178,   177,
       0,    57,    58,    79,   209,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,   116,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
     127,   141,    65,    73,   119,    75,    67,   177,    71,   110,
     111,   189,   132,   190,   193,   188,    48,     0,     4,   108,
       9,     8,    25,    24,    17,    16,    15,    22,    23,    18,
      19,    20,    21,    10,    11,    12,    13,    14,     0,   100,
      84,     0,    85,    94,    96,    86,   109,     0,     0,     0,
     145,   146,     0,     0,     0,     0,   169,   168,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,    59,    60,    88,     0,   215,     0,   210,    45,
      46,     0,    79,     0,   138,     0,    79,   209,   126,     0,
       0,   117,    79,    79,     0,     0,     0,     0,    68,    92,
       0,     0,     0,     0,     0,   141,   143,     0,    79,     0,
       0,     0,     0,     0,     0,   121,   122,     0,     0,     0,
       0,     0,     0,   107,    79,     0,     0,     0,     0,     0,
       0,   186,   185,   209,     0,     0,     0,     0,     0,     0,
     147,     0,     0,   163,   162,   155,   154,   153,   160,   161,
     156,   157,   158,   159,   164,   165,   148,   149,   150,   151,
     152,    79,    51,     0,    54,     0,   141,   114,   139,   115,
     104,    70,    69,   118,     0,   211,     0,     0,   141,   141,
       0,     0,     0,     0,     0,     0,    77,    78,   194,     0,
      64,   144,    66,    76,   120,   215,   113,   213,   131,   219,
       0,     0,     0,     0,   217,   221,   112,     0,   128,    72,
     163,   200,   162,   199,   198,   197,   196,   195,     5,     0,
      91,     0,     0,   101,   225,     0,    95,     0,    98,    97,
       0,     0,     0,   173,   174,   182,   166,     0,     0,     0,
      89,   216,     0,   140,     0,     0,     0,     0,   125,   124,
       0,     0,   201,   203,   202,   204,    93,     0,   136,     0,
       0,     0,   220,     0,     0,     0,     0,     0,   187,   102,
     226,   227,    87,     0,     0,     0,   187,     0,     0,   175,
     176,    47,   177,   137,   212,   123,   134,   135,     0,     0,
       0,   129,   224,   222,     0,   130,     0,   191,     0,   184,
     183,   171,   209,     0,     0,    74,   214,   218,   223,     0,
       0,     0,     0,     0,   170,     0,     0,    40,     0,   187,
       0,     0,   205,   206,   207,     0,   172,     0,   192,     0,
      99,     0,   208,     0,     0,     6
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,  -311,  -311,  1073,   449,  -311,   488,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,   123,
    -311,   -15,   -90,   268,  -311,  -311,   264,  -311,  -311,     4,
    -249,  -311,   193,   -65,  -311,  -311,  -311,     1,   -54,   437,
     378,  -220,  -311,   135,   -98,  -311,  -215,  -311,  -311,    -8,
    -310,  -109,  -311,  -121,  -311,  -311,    68,  -222,  -311,   278,
    -226,  -311,  -246,  -311
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    55,    21,    22,    23,    24,    25,    26,    79,
      27,    28,    29,    30,    31,    47,    32,    33,    34,   130,
      98,    50,   131,   132,   133,   134,   135,    36,   171,   136,
     215,   361,   238,   172,   173,   368,   174,    99,    39,    40,
      83,   138,   139,   140,   223,   224,   247,   248,   182,   141,
      53,   142,   451,   143,   144,   464,   465,   217,   387,   336,
     218,   345,   346,   365
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    38,   149,   228,    37,   314,   313,   244,   348,   339,
     410,   225,   358,     2,     2,   360,   175,   105,     1,    42,
      38,   106,     2,    41,   169,   337,   337,   339,    37,   340,
     329,     2,   341,   100,    43,   378,   379,   349,   146,   245,
      11,    12,    13,    45,   316,    44,    46,   340,     2,    41,
     137,   371,   380,   281,   226,    38,  -142,  -142,  -142,    37,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,   381,    80,   339,
      48,   359,    81,     2,    49,   186,   187,   188,   265,   190,
      58,   383,   170,   266,   341,   401,   216,   403,   437,   340,
     342,   406,   -90,   390,   391,    52,   441,   214,    54,   411,
      18,    18,   347,   343,   101,   281,   412,   107,   342,    18,
     243,    56,    19,    35,   271,   239,   308,    59,    18,    41,
     137,   343,   306,   282,   384,  -142,    82,   351,   353,   355,
     357,   334,   318,   319,   102,    18,   462,    35,   177,   466,
     463,   260,   261,   178,   179,    11,    12,    13,   433,   434,
     424,    73,    74,    75,   313,   208,   209,   210,   104,   270,
     342,   103,   180,   429,   181,   145,   276,   277,    35,   328,
      18,   278,     2,   343,   275,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   366,   273,   168,   274,   169,   445,   183,
      77,    78,   184,   305,    71,    72,    73,    74,    75,   216,
     453,   185,   250,   137,   252,   444,   254,   137,   191,   192,
     312,   317,   325,   137,   137,   320,   321,   322,   323,   260,
     261,   126,   127,   335,   335,   255,   256,   404,   405,   137,
     350,   352,   354,   356,   344,   344,   189,   212,   137,   414,
     415,   369,   213,   219,   220,   216,   222,   221,   214,   227,
     229,   377,   231,   232,   230,   372,   233,   234,   235,   241,
      84,   236,   344,   344,     2,   237,    85,   111,   240,   112,
     113,   114,     3,     4,    86,   216,   242,    87,    88,    89,
     246,    90,   249,   257,   264,   214,   267,   268,   269,   117,
     272,   281,   301,   282,   118,   307,   119,   304,    91,    92,
     302,   309,   -79,   315,   324,   239,   -79,   326,   120,   121,
     122,   123,   327,     3,     4,   330,     5,     6,   362,   363,
     364,   386,   344,     7,   344,     8,   373,   461,   344,   385,
     388,     9,   389,    93,   206,   207,   208,   209,   210,   400,
     439,    10,   392,   393,    11,    12,    13,   394,   395,   398,
     402,    94,   261,   407,    14,    15,    16,    95,   216,   408,
      96,    18,   409,   413,   128,   137,   422,   426,   416,   129,
     425,   216,   430,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   417,   344,   344,   419,   420,   421,
     443,   428,   431,   427,    84,   432,   108,   109,   110,   435,
      85,   111,   436,   112,   113,   114,     3,     4,    86,   137,
     438,    87,    88,    89,   216,    90,   457,   440,   442,   450,
     449,   115,   116,   117,   331,   446,   448,   452,   118,   455,
     119,   456,    91,    92,   458,   459,   460,    11,    12,    13,
     467,   468,   120,   121,   122,   123,   124,   250,   251,   252,
     253,   254,   125,    67,    68,    69,    70,   469,   470,    71,
      72,    73,    74,    75,   126,   127,   473,    93,   471,   474,
     255,   256,   475,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   148,    94,    71,    72,    73,    74,
      75,    95,    76,   333,    96,    18,   332,   396,   128,   176,
     423,   150,    84,   129,   108,   109,   110,   263,    85,   111,
     338,   112,   113,   114,     3,     4,    86,   472,     0,    87,
      88,    89,     0,    90,     0,     0,     0,     0,     0,   115,
     116,   117,     0,     0,     0,     0,   118,     0,   119,     0,
      91,    92,     0,     0,     0,    11,    12,    13,     0,     0,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
     125,   204,   205,   206,   207,   208,   209,   210,     0,     0,
       0,   262,   126,   127,     0,    93,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    94,    71,    72,    73,    74,    75,    95,
       0,     0,    96,    18,     0,     0,   128,     0,     0,     0,
      84,   129,   108,   109,   310,     0,    85,   111,     0,   112,
     113,   114,     3,     4,    86,     0,     0,    87,    88,    89,
       0,    90,     0,     0,     0,     0,     0,   115,   116,   117,
       0,     0,     0,     0,   118,     0,   119,     0,    91,    92,
       0,     0,     0,    11,    12,    13,     0,     0,   120,   121,
     122,   123,   311,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     126,   127,     0,    93,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    94,    71,    72,    73,    74,    75,    95,     0,     0,
      96,    18,     0,     0,   128,     0,     0,     0,    84,   129,
     108,   109,   310,     0,    85,   111,     0,   112,   113,   114,
       3,     4,    86,     0,     0,    87,    88,    89,     0,    90,
       0,     0,     0,     0,    84,   115,   116,   117,     2,     0,
      85,     0,   118,     0,   119,     0,    91,    92,    86,     0,
       0,    87,    88,    89,     0,    90,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,     0,     0,     0,     0,   126,   127,
       0,    93,   259,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    94,
       0,     0,     0,     0,     0,    95,     0,    93,    96,    18,
       0,     0,   128,     0,     0,     0,     0,   129,    65,    66,
      67,    68,    69,    70,     0,    94,    71,    72,    73,    74,
      75,    95,     1,   -79,    96,    18,     2,   -79,    97,     0,
     367,     0,     0,     0,     3,     4,     0,     5,     6,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    84,    11,    12,    13,     2,     0,
      85,     0,     0,     0,     0,    14,    15,    16,    86,     0,
      84,    87,    88,    89,     2,    90,    85,     0,    17,     0,
       0,     0,     0,     0,    86,     0,     0,    87,    88,    89,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,     0,     0,    91,    92,
       0,     0,     0,    18,     0,     0,    19,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    93,   279,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,    94,     0,     0,     0,     0,
       0,    95,     0,     0,    96,    18,     0,   279,   128,     0,
       0,    94,     0,     0,     0,     0,     0,    95,     0,     0,
      96,    18,     0,     0,    97,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,   258,   259,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   -28,     0,     0,     0,   -79,     0,     0,     0,
     -79,     0,   280,     0,     0,     0,     0,     3,     4,     0,
       5,     6,    57,     0,     0,     0,     0,     7,     0,     8,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,   147,    14,    15,
      16,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   418,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   211,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   370,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   375,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   376,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   447,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   399,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   258,   259,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    71,    72,    73,    74,    75,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    71,    72,    73,    74,    75,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      64,    65,    66,    67,    68,    69,    70,     0,     0,    71,
      72,    73,    74,    75,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210
};

static const yytype_int16 yycheck[] =
{
      15,     0,    56,   112,     0,   227,   226,   128,   254,     3,
       7,   109,     3,     7,     7,   264,    81,     3,     3,    11,
      19,     7,     7,   109,     7,   251,   252,     3,    24,    23,
     245,     7,    88,    41,    11,   281,   282,   257,    53,   129,
      46,    47,    48,     7,     3,     7,    10,    23,     7,   109,
      49,   273,   301,   109,   114,    54,    34,    35,    36,    55,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   303,     4,     3,
     109,    72,     8,     7,   112,    93,    94,    95,   109,    97,
       0,   306,    75,   114,    88,   341,   104,   343,   408,    23,
      94,   347,   108,   318,   319,    49,   416,   103,    68,   106,
     104,   104,    88,   107,    11,   109,   113,   103,    94,   104,
     128,   111,   107,     0,   178,   124,   224,   106,   104,   109,
     129,   107,   222,   109,   114,   113,   111,   258,   259,   260,
     261,   250,   232,   233,    11,   104,     4,    24,   109,   459,
       8,    80,    81,   114,   115,    46,    47,    48,   404,   405,
     386,    95,    96,    97,   384,    95,    96,    97,   107,   177,
      94,   112,     7,   399,     9,     3,   184,   185,    55,   108,
     104,   189,     7,   107,   183,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   268,   107,     7,   109,     7,   428,   107,
      44,    45,   107,   221,    93,    94,    95,    96,    97,   227,
     442,   107,    75,   222,    77,    78,    79,   226,    78,    79,
     226,   230,   240,   232,   233,   234,   235,   236,   237,    80,
      81,    73,    74,   251,   252,    98,    99,   106,   107,   248,
     258,   259,   260,   261,   253,   254,   107,    11,   257,   114,
     115,   269,    11,   110,   110,   273,    36,   107,   264,   107,
     107,   279,     7,   112,   107,   274,   112,   107,   107,    93,
       3,   107,   281,   282,     7,   107,     9,    10,   107,    12,
      13,    14,    15,    16,    17,   303,    93,    20,    21,    22,
      33,    24,   106,    40,   107,   301,   112,   106,    75,    32,
       7,   109,    33,   109,    37,    34,    39,   108,    41,    42,
     113,    35,     4,    11,   106,   324,     8,     3,    51,    52,
      53,    54,     3,    15,    16,   113,    18,    19,     3,     3,
       7,   106,   341,    25,   343,    27,   108,   456,   347,   108,
     108,    33,   108,    76,    93,    94,    95,    96,    97,   107,
     414,    43,   108,   108,    46,    47,    48,   108,   108,   113,
       3,    94,    81,    90,    56,    57,    58,   100,   386,   108,
     103,   104,   110,     3,   107,   384,   385,   113,   108,   112,
     108,   399,   400,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   110,   404,   405,   110,   110,   110,
     418,    63,    87,   113,     3,   108,     5,     6,     7,    87,
       9,    10,     3,    12,    13,    14,    15,    16,    17,   428,
     110,    20,    21,    22,   442,    24,   451,     7,   107,    50,
     106,    30,    31,    32,    33,   108,   108,    29,    37,    73,
      39,   107,    41,    42,   112,   108,    90,    46,    47,    48,
       3,   108,    51,    52,    53,    54,    55,    75,    76,    77,
      78,    79,    61,    87,    88,    89,    90,   106,   113,    93,
      94,    95,    96,    97,    73,    74,    74,    76,   106,    90,
      98,    99,     3,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    55,    94,    93,    94,    95,    96,
      97,   100,    24,   249,   103,   104,   248,   324,   107,    82,
     385,   108,     3,   112,     5,     6,     7,   149,     9,    10,
     252,    12,    13,    14,    15,    16,    17,   469,    -1,    20,
      21,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    70,    73,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    94,    93,    94,    95,    96,    97,   100,
      -1,    -1,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
       3,   112,     5,     6,     7,    -1,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,
      53,    54,    55,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      73,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    94,    93,    94,    95,    96,    97,   100,    -1,    -1,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,     3,   112,
       5,     6,     7,    -1,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,     3,    30,    31,    32,     7,    -1,
       9,    -1,    37,    -1,    39,    -1,    41,    42,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    73,    74,
      -1,    76,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    94,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    76,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,    -1,   112,    85,    86,
      87,    88,    89,    90,    -1,    94,    93,    94,    95,    96,
      97,   100,     3,     4,   103,   104,     7,     8,   107,    -1,
     109,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,     3,    46,    47,    48,     7,    -1,
       9,    -1,    -1,    -1,    -1,    56,    57,    58,    17,    -1,
       3,    20,    21,    22,     7,    24,     9,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      -1,    24,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    41,    42,
      -1,    -1,    -1,   104,    -1,    -1,   107,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    76,    33,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    94,    -1,    -1,    -1,    -1,
      -1,   100,    -1,    -1,   103,   104,    -1,    33,   107,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
     103,   104,    -1,    -1,   107,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,    -1,    -1,    -1,     4,    -1,    -1,    -1,
       8,    -1,   108,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    19,    -1,    -1,    -1,    -1,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    54,    56,    57,
      58,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   114,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    96,    97,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    96,    97,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    93,
      94,    95,    96,    97,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    15,    16,    18,    19,    25,    27,    33,
      43,    46,    47,    48,    56,    57,    58,    69,   104,   107,
     117,   119,   120,   121,   122,   123,   124,   126,   127,   128,
     129,   130,   132,   133,   134,   135,   143,   145,   153,   154,
     155,   109,    11,    11,     7,     7,    10,   131,   109,   112,
     137,   137,    49,   166,    68,   118,   111,   120,     0,   106,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    94,    95,    96,    97,   123,    44,    45,   125,
       4,     8,   111,   156,     3,     9,    17,    20,    21,    22,
      24,    41,    42,    76,    94,   100,   103,   107,   136,   153,
     165,    11,    11,   112,   107,     3,     7,   103,     5,     6,
       7,    10,    12,    13,    14,    30,    31,    32,    37,    39,
      51,    52,    53,    54,    55,    61,    73,    74,   107,   112,
     135,   138,   139,   140,   141,   142,   145,   153,   157,   158,
     159,   165,   167,   169,   170,     3,   137,   120,   121,   154,
     108,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,     7,     7,
      75,   144,   149,   150,   152,   149,   155,   109,   114,   115,
       7,     9,   164,   107,   107,   107,   165,   165,   165,   107,
     165,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   110,    11,    11,   145,   146,   165,   173,   176,   110,
     110,   107,    36,   160,   161,   160,   114,   107,   167,   107,
     107,     7,   112,   112,   107,   107,   107,   107,   148,   153,
     107,    93,    93,   165,   169,   138,    33,   162,   163,   106,
      75,    76,    77,    78,    79,    98,    99,    40,    80,    81,
      80,    81,    70,   156,   107,   109,   114,   112,   106,    75,
     165,   154,     7,   107,   109,   153,   165,   165,   165,    33,
     108,   109,   109,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,    33,   113,   106,   108,   165,   138,    34,   160,    35,
       7,    55,   145,   157,   173,    11,     3,   153,   138,   138,
     153,   153,   153,   153,   106,   165,     3,     3,   108,   162,
     113,    33,   139,   142,   167,   165,   175,   176,   175,     3,
      23,    88,    94,   107,   153,   177,   178,    88,   178,   157,
     165,   169,   165,   169,   165,   169,   165,   169,     3,    72,
     146,   147,     3,     3,     7,   179,   149,   109,   151,   165,
     110,   173,   153,   108,   108,   108,   108,   165,   178,   178,
     146,   176,   108,   162,   114,   108,   106,   174,   108,   108,
     162,   162,   108,   108,   108,   108,   148,   108,   113,   107,
     107,   178,     3,   178,   106,   107,   178,    90,   108,   110,
       7,   106,   113,     3,   114,   115,   108,   110,   114,   110,
     110,   110,   153,   159,   176,   108,   113,   113,    63,   176,
     165,    87,   108,   178,   178,    87,     3,   166,   110,   154,
       7,   166,   107,   165,    78,   157,   108,   108,   108,   106,
      50,   168,    29,   173,   108,    73,   107,   137,   112,   108,
      90,   167,     4,     8,   171,   172,   166,     3,   108,   106,
     113,   106,   172,    74,    90,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   116,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   125,   125,   126,   126,   126,   126,   126,   127,   128,
     129,   130,   131,   131,   132,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   140,   141,   141,   142,   142,   143,
     143,   143,   143,   144,   144,   145,   145,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   150,   151,
     152,   152,   152,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   160,   160,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   167,
     167,   168,   168,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   177,
     177,   178,   178,   178,   178,   179,   179,   179
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     4,    14,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       9,     1,     1,     0,     1,     4,     4,     7,     3,     2,
       2,     5,     1,     1,     5,     1,     1,     3,     3,     4,
       4,     1,     1,     1,     4,     1,     3,     1,     2,     3,
       3,     1,     3,     1,     6,     1,     3,     3,     3,     0,
       1,     1,     1,     0,     1,     3,     3,     6,     1,     3,
       0,     1,     1,     3,     1,     3,     1,     3,     3,     7,
       1,     3,     4,     1,     1,     4,     2,     4,     0,     2,
       1,     1,     3,     3,     3,     3,     1,     2,     3,     1,
       3,     2,     2,     5,     4,     4,     2,     1,     3,     5,
       5,     3,     1,     1,     5,     5,     4,     5,     1,     2,
       3,     0,     1,     1,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     2,     2,     2,
       7,     6,     9,     4,     4,     5,     5,     1,     1,     1,
       1,     1,     4,     6,     6,     3,     3,     0,     2,     1,
       1,     0,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     1,     1,     1,     3,     0,
       1,     0,     2,     1,     4,     1,     3,     1,     4,     1,
       2,     1,     3,     4,     3,     1,     2,     2
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
        yyerror (globalSymTab, mtypes, property, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, globalSymTab, mtypes, property); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (globalSymTab);
  YY_USE (mtypes);
  YY_USE (property);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, globalSymTab, mtypes, property);
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
                 int yyrule, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], globalSymTab, mtypes, property);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, globalSymTab, mtypes, property); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
{
  YY_USE (yyvaluep);
  YY_USE (globalSymTab);
  YY_USE (mtypes);
  YY_USE (property);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, yylval, globalSymTab);
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
  case 3: /* start_parsing: props  */
#line 100 "promela.y"
                                                                                        { if(property) *property = (yyvsp[0].pList);}
#line 2088 "y.tab.c"
    break;

  case 4: /* start_parsing: CHECK cformula program  */
#line 101 "promela.y"
                                                { if(property) *property = (yyvsp[-1].pCostFormula);}
#line 2094 "y.tab.c"
    break;

  case 5: /* cformula: FINALLY prop WITHIN CONST  */
#line 104 "promela.y"
                                                { (yyval.pCostFormula) = createCostFormula((yyvsp[-2].pExpVal), (yyvsp[0].iVal), INT_MAX, INT_MAX);}
#line 2100 "y.tab.c"
    break;

  case 6: /* cformula: FINALLY prop WITHIN TIME LE CONST ',' COST LE CONST ',' QUALITY LE CONST  */
#line 105 "promela.y"
                                                                                           { (yyval.pCostFormula) = createCostFormula((yyvsp[-12].pExpVal), (yyvsp[-8].iVal), (yyvsp[-4].iVal), (yyvsp[0].iVal)); }
#line 2106 "y.tab.c"
    break;

  case 7: /* props: prop  */
#line 108 "promela.y"
                                                                                { (yyval.pList) = listAdd(NULL,(yyvsp[0].pExpVal)); }
#line 2112 "y.tab.c"
    break;

  case 8: /* props: props ',' prop  */
#line 109 "promela.y"
                                                                                { (yyval.pList) = listAdd((yyvsp[-2].pList),(yyvsp[0].pExpVal)); }
#line 2118 "y.tab.c"
    break;

  case 9: /* prop: '(' prop ')'  */
#line 112 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2124 "y.tab.c"
    break;

  case 10: /* prop: prop '+' prop  */
#line 113 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2130 "y.tab.c"
    break;

  case 11: /* prop: prop '-' prop  */
#line 114 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2136 "y.tab.c"
    break;

  case 12: /* prop: prop '*' prop  */
#line 115 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2142 "y.tab.c"
    break;

  case 13: /* prop: prop '/' prop  */
#line 116 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2148 "y.tab.c"
    break;

  case 14: /* prop: prop '%' prop  */
#line 117 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2154 "y.tab.c"
    break;

  case 15: /* prop: prop '&' prop  */
#line 118 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2160 "y.tab.c"
    break;

  case 16: /* prop: prop '^' prop  */
#line 119 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2166 "y.tab.c"
    break;

  case 17: /* prop: prop '|' prop  */
#line 120 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2172 "y.tab.c"
    break;

  case 18: /* prop: prop GT prop  */
#line 121 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2178 "y.tab.c"
    break;

  case 19: /* prop: prop LT prop  */
#line 122 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2184 "y.tab.c"
    break;

  case 20: /* prop: prop GE prop  */
#line 123 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2190 "y.tab.c"
    break;

  case 21: /* prop: prop LE prop  */
#line 124 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2196 "y.tab.c"
    break;

  case 22: /* prop: prop EQ prop  */
#line 125 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2202 "y.tab.c"
    break;

  case 23: /* prop: prop NE prop  */
#line 126 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2208 "y.tab.c"
    break;

  case 24: /* prop: prop AND prop  */
#line 127 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2214 "y.tab.c"
    break;

  case 25: /* prop: prop OR prop  */
#line 128 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2220 "y.tab.c"
    break;

  case 26: /* prop: varref  */
#line 129 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2226 "y.tab.c"
    break;

  case 27: /* prop: CONST  */
#line 130 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2232 "y.tab.c"
    break;

  case 34: /* unit: events  */
#line 167 "promela.y"
                                                                { yyerror("The 'events' construct is currently not supported."); }
#line 2238 "y.tab.c"
    break;

  case 35: /* unit: one_decl  */
#line 168 "promela.y"
                                                                { if((yyvsp[0].pSymTabNodeVal) != NULL) *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[0].pSymTabNodeVal)); }
#line 2244 "y.tab.c"
    break;

  case 36: /* unit: utype  */
#line 169 "promela.y"
                                                                { *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[0].pSymTabNodeVal)); }
#line 2250 "y.tab.c"
    break;

  case 37: /* unit: c_fcts  */
#line 170 "promela.y"
                                                                { yyerror("Embedded C code is not supported."); }
#line 2256 "y.tab.c"
    break;

  case 38: /* unit: ns  */
#line 171 "promela.y"
                                                                { yyerror("The 'named sequence' construct is currently not supported."); }
#line 2262 "y.tab.c"
    break;

  case 40: /* proc: inst proctype NAME '(' decl ')' Opt_priority Opt_enabler body  */
#line 181 "promela.y"
                                                                                        {	(yyvsp[0].pFsmVal)->symTab = addToSymTab((yyvsp[-4].pSymTabNodeVal), (yyvsp[0].pFsmVal)->symTab);
			  										*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, (yyvsp[-6].sVal), nbrLines, 0, 0, (yyvsp[-8].pExpVal), (yyvsp[0].pFsmVal), NULL));
												}
#line 2270 "y.tab.c"
    break;

  case 42: /* proctype: D_PROCTYPE  */
#line 187 "promela.y"
                                                                                { yyerror("Deterministic proctypes are not supported (only useful for simulation)."); }
#line 2276 "y.tab.c"
    break;

  case 43: /* inst: %empty  */
#line 190 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2282 "y.tab.c"
    break;

  case 44: /* inst: ACTIVE  */
#line 191 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 1, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2288 "y.tab.c"
    break;

  case 45: /* inst: ACTIVE '[' CONST ']'  */
#line 192 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, (yyvsp[-1].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2294 "y.tab.c"
    break;

  case 46: /* inst: ACTIVE '[' NAME ']'  */
#line 193 "promela.y"
                                                                        {	ptSymTabNode var = lookupInSymTab(*globalSymTab, (yyvsp[-1].sVal));
													if(var == NULL) yyserror("The variable %s does not exist.", (yyvsp[-1].sVal));
													else if(var->type != T_INT && var->type != T_BIT && var->type != T_SHORT) yyserror("The variable %s is not of type int, short or bit.", (yyvsp[-1].sVal));
													else if(var->init == NULL || var->init->type != E_EXPR_CONST) yyserror("The variable %s does not have a constant value.", (yyvsp[-1].sVal));
													else {
														(yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, var->init->iVal, NULL, NULL, NULL, nbrLines, NULL, NULL);
													}
													free((yyvsp[-1].sVal));
												}
#line 2308 "y.tab.c"
    break;

  case 47: /* inst: ACTIVE '[' COUNT '(' expr ')' ']'  */
#line 202 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[-2].pExpVal), NULL, NULL, nbrLines, NULL, NULL); 
#if !defined(Z3) && !defined(MULTI)
                                         		  failure("Feature clones are not allowed in this variant of SNIP.\n");
#endif
												}
#line 2318 "y.tab.c"
    break;

  case 48: /* init: INIT Opt_priority body  */
#line 209 "promela.y"
                                                                {	if(lookupInSymTab(*globalSymTab, "init") != NULL) yyerror("This is the second init process; only one is allowed.");
													else {
														*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, "init", nbrLines, 1, 0, NULL, (yyvsp[0].pFsmVal), NULL));
													}

												}
#line 2329 "y.tab.c"
    break;

  case 49: /* claim: CLAIM body  */
#line 217 "promela.y"
                                                                        { 	if(neverClaim != NULL) yyerror("Found a second never claim.  Only one claim at a time is allowed.");
													else {
														neverClaim = createSymTabNode(T_NEVER, "__never", nbrLines, 1, 0, NULL, (yyvsp[0].pFsmVal), NULL);
														*globalSymTab = addToSymTab(*globalSymTab, neverClaim);
													}
												}
#line 2340 "y.tab.c"
    break;

  case 50: /* events: TRACE body  */
#line 225 "promela.y"
                                                                        { yyerror("Event sequences (traces) are not supported."); }
#line 2346 "y.tab.c"
    break;

  case 51: /* utype: TYPEDEF NAME '{' decl_lst '}'  */
#line 228 "promela.y"
                                                        {	(yyval.pSymTabNodeVal) = createSymTabNode(T_TDEF, (yyvsp[-3].sVal), nbrLines, 1, 0, NULL, NULL, (yyvsp[-1].pSymTabNodeVal));
													if(!spinMode && strcmp((yyval.pSymTabNodeVal)->name, "features") == 0) {
														ptSymTabNode cur = (yyval.pSymTabNodeVal)->child;
														while(cur != NULL) {
															if(cur->type != T_BOOL && cur->type != T_UTYPE) failure("Feature '%s' is not declared as a boolean or a complex feature but as a '%s'.\n", cur->name, getTypeName(cur->type));
															if(cur->type == T_BOOL && cur->init && cur->init->type != E_EXPR_CONST) failure("The initial value of a Boolean feature must be given as a constant (0 or 1), this is not the case for '%s' at line %d.\n", cur->name, cur->lineNb);
															if(cur->type == T_BOOL)
																cur->type = T_FEAT;
#if defined Z3 || defined MULTI
															else {
																cur->type = T_UFEAT;
																if(!cur->utype || !cur->utype->child || cur->utype->child->type != T_BOOL || (strcmp(cur->utype->child->name, "is_in") != 0))
																	failure("The first subfield of a complex feature like '%s' must be a Boolean called 'is_in'. Here, it is a '%s' called '%s'. \n", cur->name, cur->utype->child ? getTypeName(cur->utype->child->type) : "NULL", cur->utype->child ? cur->utype->child->name : "NULL");
															}
#else 
															else
																failure("The use of complex features without Z3 is forbidden.\n");
															if(cur->bound > 1)
																failure("The use of feature clones without Z3 is forbidden.\n");
#endif
															if(!optimisedSpinMode) {
																cur->capacity = getFeatureID(cur->name);
																if(cur->capacity == -1) failure("Feature '%s' not found in feature model.\n", cur->name);
															}
															cur = cur->next;
														}
													}
												}
#line 2379 "y.tab.c"
    break;

  case 64: /* body: '{' sequence OS '}'  */
#line 282 "promela.y"
                                                                { (yyval.pFsmVal) = (yyvsp[-2].pFsmVal); }
#line 2385 "y.tab.c"
    break;

  case 65: /* sequence: step  */
#line 285 "promela.y"
                                                                                { 	(yyval.pFsmVal) = createFsm();
													if((yyvsp[0].pExpVal)->type == E_DECL) {
														(yyval.pFsmVal)->symTab = (yyvsp[0].pExpVal)->symTab;
														(yyvsp[0].pExpVal)->symTab = NULL;
														destroyExpNode((yyvsp[0].pExpVal));
													} else if((yyvsp[0].pExpVal)->type == E_STMNT) {
														(yyval.pFsmVal) = stmnt2fsm((yyval.pFsmVal), (yyvsp[0].pExpVal)->children[0], *globalSymTab);
														(yyvsp[0].pExpVal)->children[0] = NULL;
														destroyExpNode((yyvsp[0].pExpVal));
													}
												}
#line 2401 "y.tab.c"
    break;

  case 66: /* sequence: sequence MS step  */
#line 296 "promela.y"
                                                                                {	if((yyvsp[0].pExpVal)->type == E_DECL) {
														(yyval.pFsmVal) = (yyvsp[-2].pFsmVal);
														(yyval.pFsmVal)->symTab = addToSymTab((yyval.pFsmVal)->symTab, (yyvsp[0].pExpVal)->symTab);
														(yyvsp[0].pExpVal)->symTab = NULL;
														destroyExpNode((yyvsp[0].pExpVal));
													} else if((yyvsp[0].pExpVal)->type == E_STMNT) {
														(yyval.pFsmVal) = stmnt2fsm((yyvsp[-2].pFsmVal), (yyvsp[0].pExpVal)->children[0], *globalSymTab);
														(yyvsp[0].pExpVal)->children[0] = NULL;
														destroyExpNode((yyvsp[0].pExpVal));
													}
												}
#line 2417 "y.tab.c"
    break;

  case 67: /* step: one_decl  */
#line 309 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_DECL, NULL, 0, NULL, NULL, NULL, nbrLines, NULL, (yyvsp[0].pSymTabNodeVal)); }
#line 2423 "y.tab.c"
    break;

  case 68: /* step: XU vref_lst  */
#line 310 "promela.y"
                                                                                { yyerror("Channel assertions are currently not supported."); }
#line 2429 "y.tab.c"
    break;

  case 69: /* step: NAME ':' one_decl  */
#line 311 "promela.y"
                                                                                { yyerror("Declarations with labels are not suported."); }
#line 2435 "y.tab.c"
    break;

  case 70: /* step: NAME ':' XU  */
#line 312 "promela.y"
                                                                                { yyerror("Channel assertions are currently not supported."); }
#line 2441 "y.tab.c"
    break;

  case 71: /* step: stmnt  */
#line 313 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2447 "y.tab.c"
    break;

  case 72: /* step: stmnt UNLESS stmnt  */
#line 314 "promela.y"
                                                                        { yyerror("Unless statements are currently not supported."); }
#line 2453 "y.tab.c"
    break;

  case 73: /* step: timed_stmnt  */
#line 315 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2459 "y.tab.c"
    break;

  case 74: /* timed_stmnt: WAIT '(' expr ')' THEN stmnt  */
#line 318 "promela.y"
                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_WHEN, NULL, 0, (yyvsp[-3].pExpVal), (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2465 "y.tab.c"
    break;

  case 75: /* nf_stmnt: cost_stmnt  */
#line 321 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2471 "y.tab.c"
    break;

  case 76: /* nf_stmnt: cost_stmnt ',' cost_stmnt  */
#line 322 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[-2].pExpVal), (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2477 "y.tab.c"
    break;

  case 77: /* cost_stmnt: COST '+' CONST  */
#line 325 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_COST, NULL, (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2483 "y.tab.c"
    break;

  case 78: /* cost_stmnt: QUALITY '+' CONST  */
#line 326 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_QUALITY, NULL, (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2489 "y.tab.c"
    break;

  case 80: /* vis: HIDDEN  */
#line 330 "promela.y"
                                                                                        { yyerror("The 'hidden' keyword is not supported."); }
#line 2495 "y.tab.c"
    break;

  case 81: /* vis: SHOW  */
#line 331 "promela.y"
                                                                                        { yyerror("The 'show' keyword is not supported."); }
#line 2501 "y.tab.c"
    break;

  case 82: /* vis: ISLOCAL  */
#line 332 "promela.y"
                                                                                        { yyerror("The 'local' keyword is not supported."); }
#line 2507 "y.tab.c"
    break;

  case 85: /* one_decl: vis TYPE var_list  */
#line 342 "promela.y"
                                                                        {	ptSymTabNode cur = (yyvsp[0].pSymTabNodeVal);
													while(cur != NULL) {
														// If type != 0, then the var is a T_CHAN
														if(cur->type == 0) cur->type = (yyvsp[-1].iVal);
#ifndef CLOCK
														if(cur->type == T_CLOCK) {
															yyerror("Clocks can only be declared when the CLOCK option is enabled.");
														}
#endif
														cur = cur->next;
													}
													(yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal);
												}
#line 2525 "y.tab.c"
    break;

  case 86: /* one_decl: vis UNAME var_list  */
#line 355 "promela.y"
                                                                        {	ptSymTabNode type = lookupInSymTab(*globalSymTab, (yyvsp[-1].sVal));
	 												if(type == NULL) yyserror("The type %s was not declared in a typedef.", (yyvsp[-1].sVal));
													else {
														ptSymTabNode cur = (yyvsp[0].pSymTabNodeVal);
														while(cur != NULL) {
															cur->type = T_UTYPE;
															cur->utype = type;
															cur = cur->next;
														}
														(yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal);
													}
	 												free((yyvsp[-1].sVal));
												}
#line 2543 "y.tab.c"
    break;

  case 87: /* one_decl: vis TYPE asgn '{' nlst '}'  */
#line 368 "promela.y"
                                                                {	if((yyvsp[-4].iVal) != T_MTYPE) yyerror("This syntax only works for MTYPEs.");
													(yyval.pSymTabNodeVal) = NULL;
													/* The mtype values are added in the nlst rule. */ 
												}
#line 2552 "y.tab.c"
    break;

  case 88: /* decl_lst: one_decl  */
#line 374 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2558 "y.tab.c"
    break;

  case 89: /* decl_lst: one_decl SEMI decl_lst  */
#line 375 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[-2].pSymTabNodeVal), (yyvsp[0].pSymTabNodeVal)); }
#line 2564 "y.tab.c"
    break;

  case 90: /* decl: %empty  */
#line 379 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = NULL; }
#line 2570 "y.tab.c"
    break;

  case 91: /* decl: decl_lst  */
#line 380 "promela.y"
                                                                                        { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2576 "y.tab.c"
    break;

  case 94: /* var_list: ivar  */
#line 387 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2582 "y.tab.c"
    break;

  case 95: /* var_list: ivar ',' var_list  */
#line 388 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[-2].pSymTabNodeVal), (yyvsp[0].pSymTabNodeVal)); }
#line 2588 "y.tab.c"
    break;

  case 96: /* ivar: vardcl  */
#line 391 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[0].pDataVal).sVal, nbrLines, (yyvsp[0].pDataVal).iVal,		  0, NULL, NULL, NULL); }
#line 2594 "y.tab.c"
    break;

  case 97: /* ivar: vardcl ASGN expr  */
#line 392 "promela.y"
                                                                                { 	int mtype;
													if((yyvsp[0].pExpVal)->type == E_EXPR_VAR && (mtype = getMTypeValue(*mtypes, (yyvsp[0].pExpVal)->children[0]->children[0]->sVal)) != -1) {
														(yyvsp[0].pExpVal)->type = E_EXPR_CONST;
														(yyvsp[0].pExpVal)->iVal = mtype;
														destroyExpNode((yyvsp[0].pExpVal)->children[0]);
													}
													(yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[-2].pDataVal).sVal, nbrLines, (yyvsp[-2].pDataVal).iVal,	 	  0,   (yyvsp[0].pExpVal), NULL, NULL);
												}
#line 2607 "y.tab.c"
    break;

  case 98: /* ivar: vardcl ASGN ch_init  */
#line 400 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = createSymTabNode(T_CHAN, (yyvsp[-2].pDataVal).sVal, nbrLines, (yyvsp[-2].pDataVal).iVal, (yyvsp[0].pDataVal).iVal, NULL, NULL, (yyvsp[0].pDataVal).symTabNodeVal); }
#line 2613 "y.tab.c"
    break;

  case 99: /* ch_init: '[' CONST ']' OF '{' typ_list '}'  */
#line 403 "promela.y"
                                                        { (yyval.pDataVal).iVal = (yyvsp[-5].iVal); (yyval.pDataVal).symTabNodeVal = (yyvsp[-1].pSymTabNodeVal); }
#line 2619 "y.tab.c"
    break;

  case 100: /* vardcl: NAME  */
#line 406 "promela.y"
                                                                                { (yyval.pDataVal).sVal = (yyvsp[0].sVal); (yyval.pDataVal).iVal = 1; }
#line 2625 "y.tab.c"
    break;

  case 101: /* vardcl: NAME ':' CONST  */
#line 407 "promela.y"
                                                                                { yyerror("The 'unsigned' data type is not supported."); }
#line 2631 "y.tab.c"
    break;

  case 102: /* vardcl: NAME '[' CONST ']'  */
#line 408 "promela.y"
                                                                        { (yyval.pDataVal).sVal = (yyvsp[-3].sVal); (yyval.pDataVal).iVal = (yyvsp[-1].iVal); }
#line 2637 "y.tab.c"
    break;

  case 103: /* varref: cmpnd  */
#line 411 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2643 "y.tab.c"
    break;

  case 104: /* pfld: NAME  */
#line 414 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF_NAME, (yyvsp[0].sVal), 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2649 "y.tab.c"
    break;

  case 105: /* pfld: NAME '[' expr ']'  */
#line 415 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF_NAME,	(yyvsp[-3].sVal), 0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2655 "y.tab.c"
    break;

  case 106: /* cmpnd: pfld sfld  */
#line 418 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 0,   (yyvsp[-1].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2661 "y.tab.c"
    break;

  case 107: /* cmpnd: CONTEXT '.' pfld sfld  */
#line 419 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 1,   (yyvsp[-1].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2667 "y.tab.c"
    break;

  case 108: /* sfld: %empty  */
#line 422 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 2673 "y.tab.c"
    break;

  case 109: /* sfld: '.' cmpnd  */
#line 423 "promela.y"
                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal);   }
#line 2679 "y.tab.c"
    break;

  case 110: /* stmnt: Special  */
#line 426 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2685 "y.tab.c"
    break;

  case 111: /* stmnt: Stmnt  */
#line 427 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2691 "y.tab.c"
    break;

  case 112: /* Special: varref RCV rargs  */
#line 430 "promela.y"
                                                                        { 
													(yyval.pExpVal) = createExpNode(E_STMNT_CHAN_RCV, 	NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); 
												}
#line 2699 "y.tab.c"
    break;

  case 113: /* Special: varref SND margs  */
#line 433 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_CHAN_SND, 	NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2705 "y.tab.c"
    break;

  case 114: /* Special: IF options FI  */
#line 434 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_IF, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL,       (yyvsp[-2].iVal), NULL, NULL); }
#line 2711 "y.tab.c"
    break;

  case 115: /* Special: DO options OD  */
#line 435 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_DO, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL,       (yyvsp[-2].iVal), NULL, NULL); }
#line 2717 "y.tab.c"
    break;

  case 116: /* Special: BREAK  */
#line 436 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_BREAK, 	NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2723 "y.tab.c"
    break;

  case 117: /* Special: GOTO NAME  */
#line 437 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_GOTO, 		(yyvsp[0].sVal), 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2729 "y.tab.c"
    break;

  case 118: /* Special: NAME ':' stmnt  */
#line 438 "promela.y"
                                                                                { if((yyvsp[0].pExpVal)->type == E_STMNT_LABEL && (yyvsp[0].pExpVal)->children[0] && (yyvsp[0].pExpVal)->children[0]->type == E_STMNT_LABEL) yyerror("Only two labels per state are supported."); 
												  (yyval.pExpVal) = createExpNode(E_STMNT_LABEL,		(yyvsp[-2].sVal), 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2736 "y.tab.c"
    break;

  case 119: /* Special: nf_stmnt  */
#line 440 "promela.y"
                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2742 "y.tab.c"
    break;

  case 120: /* Stmnt: varref ASGN full_expr  */
#line 443 "promela.y"
                                                                {
													(yyval.pExpVal) = createExpNode(E_STMNT_ASGN, 		NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL);
												}
#line 2750 "y.tab.c"
    break;

  case 121: /* Stmnt: varref INCR  */
#line 446 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_INCR, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2756 "y.tab.c"
    break;

  case 122: /* Stmnt: varref DECR  */
#line 447 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_DECR, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2762 "y.tab.c"
    break;

  case 123: /* Stmnt: PRINT '(' STRING prargs ')'  */
#line 448 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_PRINT, 	(yyvsp[-2].sVal), 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2768 "y.tab.c"
    break;

  case 124: /* Stmnt: PRINTM '(' varref ')'  */
#line 449 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2774 "y.tab.c"
    break;

  case 125: /* Stmnt: PRINTM '(' CONST ')'  */
#line 450 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL,  (yyvsp[-1].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2780 "y.tab.c"
    break;

  case 126: /* Stmnt: ASSERT full_expr  */
#line 451 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_ASSERT, 	NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2786 "y.tab.c"
    break;

  case 127: /* Stmnt: ccode  */
#line 452 "promela.y"
                                                                                        { yyerror("Embedded C code is not supported."); }
#line 2792 "y.tab.c"
    break;

  case 128: /* Stmnt: varref R_RCV rargs  */
#line 453 "promela.y"
                                                                        { yyerror("Sorted send and random receive are not supported."); }
#line 2798 "y.tab.c"
    break;

  case 129: /* Stmnt: varref RCV LT rargs GT  */
#line 454 "promela.y"
                                                                        { yyerror("Channel poll operations are not supported."); }
#line 2804 "y.tab.c"
    break;

  case 130: /* Stmnt: varref R_RCV LT rargs GT  */
#line 455 "promela.y"
                                                                        { yyerror("Channel poll operations are not supported."); }
#line 2810 "y.tab.c"
    break;

  case 131: /* Stmnt: varref O_SND margs  */
#line 456 "promela.y"
                                                                        { yyerror("Sorted send and random receive are not supported."); }
#line 2816 "y.tab.c"
    break;

  case 132: /* Stmnt: full_expr  */
#line 457 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_EXPR, 		NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2822 "y.tab.c"
    break;

  case 133: /* Stmnt: ELSE  */
#line 458 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_ELSE, 		NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2828 "y.tab.c"
    break;

  case 134: /* Stmnt: ATOMIC '{' sequence OS '}'  */
#line 459 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_ATOMIC,	NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[-2].pFsmVal), NULL); }
#line 2834 "y.tab.c"
    break;

  case 135: /* Stmnt: D_STEP '{' sequence OS '}'  */
#line 460 "promela.y"
                                                                { yyerror("Deterministic steps are not yet supported."); }
#line 2840 "y.tab.c"
    break;

  case 136: /* Stmnt: '{' sequence OS '}'  */
#line 461 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_SEQ, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[-2].pFsmVal), NULL); }
#line 2846 "y.tab.c"
    break;

  case 137: /* Stmnt: INAME '(' args ')' Stmnt  */
#line 462 "promela.y"
                                                                        { yyerror("Inline calls are not yet supported."); }
#line 2852 "y.tab.c"
    break;

  case 138: /* options: option  */
#line 465 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[0].pFsmVal), NULL); }
#line 2858 "y.tab.c"
    break;

  case 139: /* options: option options  */
#line 466 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines,   (yyvsp[-1].pFsmVal), NULL); }
#line 2864 "y.tab.c"
    break;

  case 140: /* option: SEP sequence OS  */
#line 469 "promela.y"
                                                                        { (yyval.pFsmVal) = (yyvsp[-1].pFsmVal); }
#line 2870 "y.tab.c"
    break;

  case 142: /* OS: SEMI  */
#line 473 "promela.y"
                                        { /* redundant semi at end of sequence */ }
#line 2876 "y.tab.c"
    break;

  case 143: /* MS: SEMI  */
#line 476 "promela.y"
                                        { /* at least one semi-colon */ }
#line 2882 "y.tab.c"
    break;

  case 144: /* MS: MS SEMI  */
#line 477 "promela.y"
                                        { /* but more are okay too   */ }
#line 2888 "y.tab.c"
    break;

  case 145: /* aname: NAME  */
#line 480 "promela.y"
                                                                                { (yyval.sVal) = (yyvsp[0].sVal); }
#line 2894 "y.tab.c"
    break;

  case 146: /* aname: PNAME  */
#line 481 "promela.y"
                                                                                        { (yyval.sVal) = (yyvsp[0].sVal); }
#line 2900 "y.tab.c"
    break;

  case 147: /* expr: '(' expr ')'  */
#line 484 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2906 "y.tab.c"
    break;

  case 148: /* expr: expr '+' expr  */
#line 485 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2912 "y.tab.c"
    break;

  case 149: /* expr: expr '-' expr  */
#line 486 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2918 "y.tab.c"
    break;

  case 150: /* expr: expr '*' expr  */
#line 487 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2924 "y.tab.c"
    break;

  case 151: /* expr: expr '/' expr  */
#line 488 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2930 "y.tab.c"
    break;

  case 152: /* expr: expr '%' expr  */
#line 489 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2936 "y.tab.c"
    break;

  case 153: /* expr: expr '&' expr  */
#line 490 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2942 "y.tab.c"
    break;

  case 154: /* expr: expr '^' expr  */
#line 491 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2948 "y.tab.c"
    break;

  case 155: /* expr: expr '|' expr  */
#line 492 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2954 "y.tab.c"
    break;

  case 156: /* expr: expr GT expr  */
#line 493 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2960 "y.tab.c"
    break;

  case 157: /* expr: expr LT expr  */
#line 494 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2966 "y.tab.c"
    break;

  case 158: /* expr: expr GE expr  */
#line 495 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2972 "y.tab.c"
    break;

  case 159: /* expr: expr LE expr  */
#line 496 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2978 "y.tab.c"
    break;

  case 160: /* expr: expr EQ expr  */
#line 497 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2984 "y.tab.c"
    break;

  case 161: /* expr: expr NE expr  */
#line 498 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2990 "y.tab.c"
    break;

  case 162: /* expr: expr AND expr  */
#line 499 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2996 "y.tab.c"
    break;

  case 163: /* expr: expr OR expr  */
#line 500 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3002 "y.tab.c"
    break;

  case 164: /* expr: expr LSHIFT expr  */
#line 501 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LSHIFT,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3008 "y.tab.c"
    break;

  case 165: /* expr: expr RSHIFT expr  */
#line 502 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_RSHIFT,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3014 "y.tab.c"
    break;

  case 166: /* expr: COUNT '(' expr ')'  */
#line 503 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3020 "y.tab.c"
    break;

  case 167: /* expr: '~' expr  */
#line 504 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_BITWNEG,NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3026 "y.tab.c"
    break;

  case 168: /* expr: '-' expr  */
#line 505 "promela.y"
                                                                        { 	if((yyvsp[0].pExpVal)->type != E_EXPR_CONST) (yyval.pExpVal) = createExpNode(E_EXPR_UMIN,	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL);
													else {
														(yyvsp[0].pExpVal)->iVal = - (yyvsp[0].pExpVal)->iVal;
														(yyval.pExpVal) = (yyvsp[0].pExpVal);
													}
												}
#line 3037 "y.tab.c"
    break;

  case 169: /* expr: SND expr  */
#line 511 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NEG, 	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3043 "y.tab.c"
    break;

  case 170: /* expr: '(' expr SEMI expr ':' expr ')'  */
#line 512 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_COND, 	NULL, 	0, (yyvsp[-5].pExpVal),   (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), nbrLines, NULL, NULL); }
#line 3049 "y.tab.c"
    break;

  case 171: /* expr: RUN aname '(' args ')' Opt_priority  */
#line 513 "promela.y"
                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[-4].sVal),   0, (yyvsp[-2].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3055 "y.tab.c"
    break;

  case 172: /* expr: RUN aname '[' varref ']' '(' args ')' Opt_priority  */
#line 515 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[-7].sVal),   0, (yyvsp[-2].pExpVal), (yyvsp[-5].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3061 "y.tab.c"
    break;

  case 173: /* expr: LEN '(' varref ')'  */
#line 516 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_LEN, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3067 "y.tab.c"
    break;

  case 174: /* expr: ENABLED '(' expr ')'  */
#line 517 "promela.y"
                                                                        { yyerror("The enabled keyword is not supported."); }
#line 3073 "y.tab.c"
    break;

  case 175: /* expr: varref RCV '[' rargs ']'  */
#line 518 "promela.y"
                                                                        { yyerror("Construct not supported."); /* Unclear */ }
#line 3079 "y.tab.c"
    break;

  case 176: /* expr: varref R_RCV '[' rargs ']'  */
#line 519 "promela.y"
                                                                { yyerror("Sorted send and random receive are not supported."); }
#line 3085 "y.tab.c"
    break;

  case 177: /* expr: varref  */
#line 520 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_VAR, 	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3091 "y.tab.c"
    break;

  case 178: /* expr: cexpr  */
#line 521 "promela.y"
                                                                                        { yyerror("Embedded C code is not supported."); }
#line 3097 "y.tab.c"
    break;

  case 179: /* expr: CONST  */
#line 522 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3103 "y.tab.c"
    break;

  case 180: /* expr: TIMEOUT  */
#line 523 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_TIMEOUT,NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3109 "y.tab.c"
    break;

  case 181: /* expr: NONPROGRESS  */
#line 524 "promela.y"
                                                                                { yyerror("The 'np_' variable is not supported."); }
#line 3115 "y.tab.c"
    break;

  case 182: /* expr: PC_VAL '(' expr ')'  */
#line 525 "promela.y"
                                                                        { yyerror("The 'pc_value()' construct is not supported."); }
#line 3121 "y.tab.c"
    break;

  case 183: /* expr: PNAME '[' expr ']' '@' NAME  */
#line 526 "promela.y"
                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3127 "y.tab.c"
    break;

  case 184: /* expr: PNAME '[' expr ']' ':' pfld  */
#line 527 "promela.y"
                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3133 "y.tab.c"
    break;

  case 185: /* expr: PNAME '@' NAME  */
#line 528 "promela.y"
                                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3139 "y.tab.c"
    break;

  case 186: /* expr: PNAME ':' pfld  */
#line 529 "promela.y"
                                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3145 "y.tab.c"
    break;

  case 188: /* Opt_priority: PRIORITY CONST  */
#line 533 "promela.y"
                                                                                { yyerror("The 'priority' construct is related to simulation and not supported."); }
#line 3151 "y.tab.c"
    break;

  case 189: /* full_expr: expr  */
#line 536 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3157 "y.tab.c"
    break;

  case 190: /* full_expr: Expr  */
#line 537 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3163 "y.tab.c"
    break;

  case 192: /* Opt_enabler: PROVIDED '(' full_expr ')'  */
#line 541 "promela.y"
                                                                { yyerror("The 'provided' construct is currently not supported."); }
#line 3169 "y.tab.c"
    break;

  case 193: /* Expr: Probe  */
#line 546 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3175 "y.tab.c"
    break;

  case 194: /* Expr: '(' Expr ')'  */
#line 547 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3181 "y.tab.c"
    break;

  case 195: /* Expr: Expr AND Expr  */
#line 548 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3187 "y.tab.c"
    break;

  case 196: /* Expr: Expr AND expr  */
#line 549 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3193 "y.tab.c"
    break;

  case 197: /* Expr: Expr OR Expr  */
#line 550 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3199 "y.tab.c"
    break;

  case 198: /* Expr: Expr OR expr  */
#line 551 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3205 "y.tab.c"
    break;

  case 199: /* Expr: expr AND Expr  */
#line 552 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3211 "y.tab.c"
    break;

  case 200: /* Expr: expr OR Expr  */
#line 553 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3217 "y.tab.c"
    break;

  case 201: /* Probe: FULL '(' varref ')'  */
#line 555 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_FULL, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3223 "y.tab.c"
    break;

  case 202: /* Probe: NFULL '(' varref ')'  */
#line 556 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NFULL, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3229 "y.tab.c"
    break;

  case 203: /* Probe: EMPTY '(' varref ')'  */
#line 557 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_EMPTY, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3235 "y.tab.c"
    break;

  case 204: /* Probe: NEMPTY '(' varref ')'  */
#line 558 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NEMPTY,	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3241 "y.tab.c"
    break;

  case 205: /* basetype: TYPE  */
#line 561 "promela.y"
                                                                                { (yyval.pDataVal).sVal = NULL; (yyval.pDataVal).iVal = (yyvsp[0].iVal); }
#line 3247 "y.tab.c"
    break;

  case 206: /* basetype: UNAME  */
#line 562 "promela.y"
                                                                                        { (yyval.pDataVal).sVal = (yyvsp[0].sVal);   (yyval.pDataVal).iVal = -1; }
#line 3253 "y.tab.c"
    break;

  case 207: /* typ_list: basetype  */
#line 566 "promela.y"
                                                                                {	if((yyvsp[0].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = createSymTabNode((yyvsp[0].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
													} else {
														(yyval.pSymTabNodeVal) = createSymTabNodeUType(*globalSymTab, (yyvsp[0].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if((yyval.pSymTabNodeVal) == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[0].pDataVal).sVal);
														free((yyvsp[0].pDataVal).sVal);
													}
												}
#line 3266 "y.tab.c"
    break;

  case 208: /* typ_list: basetype ',' typ_list  */
#line 574 "promela.y"
                                                                        {	if((yyvsp[-2].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = addToSymTab(createSymTabNode((yyvsp[-2].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL), (yyvsp[0].pSymTabNodeVal));
													} else {
														ptSymTabNode temp = createSymTabNodeUType(*globalSymTab, (yyvsp[-2].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if(temp == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[-2].pDataVal).sVal);
														else (yyval.pSymTabNodeVal) = addToSymTab(temp, (yyvsp[0].pSymTabNodeVal));
														free((yyvsp[-2].pDataVal).sVal);
													}
												}
#line 3280 "y.tab.c"
    break;

  case 209: /* args: %empty  */
#line 586 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 3286 "y.tab.c"
    break;

  case 210: /* args: arg  */
#line 587 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3292 "y.tab.c"
    break;

  case 211: /* prargs: %empty  */
#line 591 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 3298 "y.tab.c"
    break;

  case 212: /* prargs: ',' arg  */
#line 592 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3304 "y.tab.c"
    break;

  case 213: /* margs: arg  */
#line 596 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3310 "y.tab.c"
    break;

  case 214: /* margs: expr '(' arg ')'  */
#line 597 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3316 "y.tab.c"
    break;

  case 215: /* arg: expr  */
#line 600 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3322 "y.tab.c"
    break;

  case 216: /* arg: expr ',' arg  */
#line 601 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3328 "y.tab.c"
    break;

  case 217: /* rarg: varref  */
#line 604 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_RARG_VAR,	NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3334 "y.tab.c"
    break;

  case 218: /* rarg: EVAL '(' expr ')'  */
#line 605 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_RARG_EVAL,	NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3340 "y.tab.c"
    break;

  case 219: /* rarg: CONST  */
#line 606 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL,  (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3346 "y.tab.c"
    break;

  case 220: /* rarg: '-' CONST  */
#line 607 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL, -(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3352 "y.tab.c"
    break;

  case 221: /* rargs: rarg  */
#line 611 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3358 "y.tab.c"
    break;

  case 222: /* rargs: rarg ',' rargs  */
#line 612 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3364 "y.tab.c"
    break;

  case 223: /* rargs: rarg '(' rargs ')'  */
#line 613 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3370 "y.tab.c"
    break;

  case 224: /* rargs: '(' rargs ')'  */
#line 614 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[-1].pExpVal); }
#line 3376 "y.tab.c"
    break;

  case 225: /* nlst: NAME  */
#line 617 "promela.y"
                                                                                { *mtypes = addMType(*mtypes, (yyvsp[0].sVal)); }
#line 3382 "y.tab.c"
    break;

  case 226: /* nlst: nlst NAME  */
#line 618 "promela.y"
                                                                                        { *mtypes = addMType(*mtypes, (yyvsp[0].sVal)); }
#line 3388 "y.tab.c"
    break;


#line 3392 "y.tab.c"

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
      yyerror (globalSymTab, mtypes, property, YY_("syntax error"));
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
                      yytoken, &yylval, globalSymTab, mtypes, property);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, globalSymTab, mtypes, property);
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
  yyerror (globalSymTab, mtypes, property, YY_("memory exhausted"));
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
                  yytoken, &yylval, globalSymTab, mtypes, property);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, globalSymTab, mtypes, property);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 621 "promela.y"



int yyerror(char *msg) {
	fprintf(stderr, "Syntax error on line %d: '%s'.\n", nbrLines, msg);
	exit(1);
}

int yyserror(char *msg, char *param) {
	char buffer [strlen(msg) + strlen(param) + 1];
	sprintf(buffer, msg, param);
	fprintf(stderr, "Syntax error on line %d: '%s'.\n", nbrLines, buffer);
	exit(1);
}
