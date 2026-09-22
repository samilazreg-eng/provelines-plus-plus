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
#ifdef CLOCK
#include "clockZone.h"
#include "tctl.h"
static ptList _clocks = NULL;
#endif

// extern - lex
extern int nbrLines;


#line 107 "y.tab.c"

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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "promela.y"
 
	int       				iVal;
	char*    				sVal;
	tDataTuple				pDataVal;
	ptExpNode				pExpVal;
	ptSymTabNode			pSymTabNodeVal;
	struct fsm_*			pFsmVal;
	struct list_ *			pList;
    struct _costFormula *    pCostFormula;
    struct _tctlFormula *    pTctlFormula;

#line 265 "y.tab.c"

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
  YYSYMBOL_106_ = 106,                     /* '('  */
  YYSYMBOL_107_ = 107,                     /* ')'  */
  YYSYMBOL_108_ = 108,                     /* ','  */
  YYSYMBOL_109_ = 109,                     /* '['  */
  YYSYMBOL_110_ = 110,                     /* ']'  */
  YYSYMBOL_111_ = 111,                     /* '.'  */
  YYSYMBOL_112_ = 112,                     /* '{'  */
  YYSYMBOL_113_ = 113,                     /* '}'  */
  YYSYMBOL_114_ = 114,                     /* ':'  */
  YYSYMBOL_115_ = 115,                     /* '@'  */
  YYSYMBOL_YYACCEPT = 116,                 /* $accept  */
  YYSYMBOL_start_parsing = 117,            /* start_parsing  */
  YYSYMBOL_tctl = 118,                     /* tctl  */
  YYSYMBOL_cformula = 119,                 /* cformula  */
  YYSYMBOL_props = 120,                    /* props  */
  YYSYMBOL_prop = 121,                     /* prop  */
  YYSYMBOL_program = 122,                  /* program  */
  YYSYMBOL_units = 123,                    /* units  */
  YYSYMBOL_unit = 124,                     /* unit  */
  YYSYMBOL_proc = 125,                     /* proc  */
  YYSYMBOL_proctype = 126,                 /* proctype  */
  YYSYMBOL_inst = 127,                     /* inst  */
  YYSYMBOL_init = 128,                     /* init  */
  YYSYMBOL_claim = 129,                    /* claim  */
  YYSYMBOL_events = 130,                   /* events  */
  YYSYMBOL_utype = 131,                    /* utype  */
  YYSYMBOL_nm = 132,                       /* nm  */
  YYSYMBOL_ns = 133,                       /* ns  */
  YYSYMBOL_c_fcts = 134,                   /* c_fcts  */
  YYSYMBOL_cstate = 135,                   /* cstate  */
  YYSYMBOL_ccode = 136,                    /* ccode  */
  YYSYMBOL_cexpr = 137,                    /* cexpr  */
  YYSYMBOL_body = 138,                     /* body  */
  YYSYMBOL_sequence = 139,                 /* sequence  */
  YYSYMBOL_step = 140,                     /* step  */
  YYSYMBOL_timed_stmnt = 141,              /* timed_stmnt  */
  YYSYMBOL_nf_stmnt = 142,                 /* nf_stmnt  */
  YYSYMBOL_cost_stmnt = 143,               /* cost_stmnt  */
  YYSYMBOL_vis = 144,                      /* vis  */
  YYSYMBOL_asgn = 145,                     /* asgn  */
  YYSYMBOL_one_decl = 146,                 /* one_decl  */
  YYSYMBOL_decl_lst = 147,                 /* decl_lst  */
  YYSYMBOL_decl = 148,                     /* decl  */
  YYSYMBOL_vref_lst = 149,                 /* vref_lst  */
  YYSYMBOL_var_list = 150,                 /* var_list  */
  YYSYMBOL_ivar = 151,                     /* ivar  */
  YYSYMBOL_ch_init = 152,                  /* ch_init  */
  YYSYMBOL_vardcl = 153,                   /* vardcl  */
  YYSYMBOL_varref = 154,                   /* varref  */
  YYSYMBOL_pfld = 155,                     /* pfld  */
  YYSYMBOL_cmpnd = 156,                    /* cmpnd  */
  YYSYMBOL_sfld = 157,                     /* sfld  */
  YYSYMBOL_stmnt = 158,                    /* stmnt  */
  YYSYMBOL_Special = 159,                  /* Special  */
  YYSYMBOL_Stmnt = 160,                    /* Stmnt  */
  YYSYMBOL_options = 161,                  /* options  */
  YYSYMBOL_option = 162,                   /* option  */
  YYSYMBOL_OS = 163,                       /* OS  */
  YYSYMBOL_MS = 164,                       /* MS  */
  YYSYMBOL_aname = 165,                    /* aname  */
  YYSYMBOL_expr = 166,                     /* expr  */
  YYSYMBOL_Opt_priority = 167,             /* Opt_priority  */
  YYSYMBOL_full_expr = 168,                /* full_expr  */
  YYSYMBOL_Opt_enabler = 169,              /* Opt_enabler  */
  YYSYMBOL_Expr = 170,                     /* Expr  */
  YYSYMBOL_Probe = 171,                    /* Probe  */
  YYSYMBOL_basetype = 172,                 /* basetype  */
  YYSYMBOL_typ_list = 173,                 /* typ_list  */
  YYSYMBOL_args = 174,                     /* args  */
  YYSYMBOL_prargs = 175,                   /* prargs  */
  YYSYMBOL_margs = 176,                    /* margs  */
  YYSYMBOL_arg = 177,                      /* arg  */
  YYSYMBOL_rarg = 178,                     /* rarg  */
  YYSYMBOL_rargs = 179,                    /* rargs  */
  YYSYMBOL_nlst = 180                      /* nlst  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1746

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  116
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  497

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
     106,   107,    95,    93,   108,    94,   111,    96,     2,     2,
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
       0,   106,   106,   107,   114,   121,   130,   139,   140,   143,
     144,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     192,   199,   200,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   215,   225,   226,   229,   230,   231,   232,   241,
     248,   256,   264,   267,   297,   298,   301,   304,   305,   308,
     309,   310,   311,   314,   315,   318,   321,   324,   335,   348,
     349,   350,   351,   352,   353,   354,   357,   358,   366,   376,
     377,   380,   381,   384,   385,   386,   387,   390,   391,   397,
     413,   426,   432,   433,   437,   438,   441,   442,   445,   446,
     449,   450,   458,   461,   464,   465,   466,   469,   472,   473,
     476,   477,   480,   481,   484,   485,   488,   491,   492,   493,
     494,   495,   496,   498,   501,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   523,   524,   527,   530,   531,   534,   535,   538,
     539,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   569,   570,   571,   572,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   590,   591,   594,   595,   598,   599,   604,   605,   606,
     607,   608,   609,   610,   611,   613,   614,   615,   616,   619,
     620,   624,   632,   644,   645,   649,   650,   654,   655,   658,
     659,   662,   663,   664,   665,   669,   670,   671,   672,   675,
     676,   677
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
  "DECR", "'~'", "UMIN", "NEG", "COUNT", "CONTEXT", "DOT", "'('", "')'",
  "','", "'['", "']'", "'.'", "'{'", "'}'", "':'", "'@'", "$accept",
  "start_parsing", "tctl", "cformula", "props", "prop", "program", "units",
  "unit", "proc", "proctype", "inst", "init", "claim", "events", "utype",
  "nm", "ns", "c_fcts", "cstate", "ccode", "cexpr", "body", "sequence",
  "step", "timed_stmnt", "nf_stmnt", "cost_stmnt", "vis", "asgn",
  "one_decl", "decl_lst", "decl", "vref_lst", "var_list", "ivar",
  "ch_init", "vardcl", "varref", "pfld", "cmpnd", "sfld", "stmnt",
  "Special", "Stmnt", "options", "option", "OS", "MS", "aname", "expr",
  "Opt_priority", "full_expr", "Opt_enabler", "Expr", "Probe", "basetype",
  "typ_list", "args", "prargs", "margs", "arg", "rarg", "rargs", "nlst", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-387)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-147)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     385,  -387,   -71,  -387,  -387,    20,    37,    99,   156,  -387,
     -17,  -387,  -387,  -387,    -1,    -1,    78,    74,   101,    93,
      13,   189,    84,  1514,  -387,  1099,  -387,  -387,   -21,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,    85,  -387,  -387,
      95,  -387,   945,   182,   191,    97,  -387,  -387,   105,    10,
     567,  -387,  -387,   204,    -1,   144,   985,    13,   985,   207,
    1450,  -387,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  -387,
    -387,  -387,   209,     8,   210,     3,  -387,  -387,   -68,  -387,
     167,   113,   118,   120,  -387,  -387,   945,   945,   945,   121,
     945,  -387,   -22,  1078,   217,   218,   132,   945,   123,   129,
     130,   226,   226,   -72,   159,   905,   162,   177,   259,  -387,
    -387,   172,   174,   181,   185,   190,   219,     3,   227,   228,
     236,   195,   250,   905,   567,  -387,   264,  -387,  -387,  -387,
     245,  -387,   171,   304,  -387,  -387,  1478,  -387,     5,  -387,
    -387,  -387,   249,  -387,   673,  -387,    95,  -387,  1514,  1565,
     234,  1595,  1623,  1649,   453,   453,   244,   244,   244,   244,
     126,   126,  -387,  -387,  -387,   251,    44,  -387,   257,  -387,
     253,   287,  -387,  -387,   945,   207,   356,  -387,  -387,    64,
       3,   945,   945,  -387,  -387,  -387,   945,   973,   261,   262,
     945,   945,   945,   945,   945,   945,   945,   945,   945,   945,
     945,   945,   945,   945,   945,   945,   945,   945,  -387,  -387,
    -387,   339,   263,  1169,   268,  -387,  -387,  -387,   945,   567,
     344,   226,   345,   671,   945,  -387,   368,    22,  -387,   567,
     567,     3,     3,     3,     3,  -387,   274,   945,   945,   945,
     380,   381,  1001,   -54,   264,    46,   272,   463,    82,   905,
     945,   945,    27,   109,  -387,  -387,   775,   905,   905,   905,
     905,   296,    19,  -387,    -3,   387,   388,   389,   210,    81,
    1109,  -387,  -387,   945,     3,   288,  1198,  1226,  1254,   945,
    -387,   131,   131,  1531,   645,  1580,  1609,  1636,   184,   184,
     160,   160,   160,   160,   255,   255,   164,   164,  -387,  -387,
    -387,   132,  -387,   945,  -387,  1282,   264,  -387,  -387,  -387,
      58,  -387,  -387,  -387,   290,   286,   295,   298,   264,   264,
     299,   300,   301,   302,     3,  1310,  1338,  1366,  -387,  -387,
    -387,   303,  -387,  -387,  -387,  -387,  -387,  1140,  -387,  -387,
    -387,  -387,   307,   131,   411,   131,  -387,    80,  -387,   131,
    -387,  -387,  1548,   334,   645,  -387,  1548,   334,   645,  -387,
     414,  -387,   329,  -387,   315,   313,  -387,  -387,    29,  -387,
     421,  -387,  1496,    68,   318,   316,  -387,  -387,  -387,  -387,
     750,   317,   319,  -387,  -387,   320,  -387,   775,   879,   945,
     327,  -387,  -387,   322,   323,  -387,  -387,  -387,  -387,  -387,
     376,   432,   377,  -387,   945,   945,   352,  -387,   337,   131,
     131,   358,   341,   447,    78,  -387,  -387,  -387,  -387,   342,
     207,   444,    78,   347,   945,  -387,  -387,  -387,    66,  -387,
    -387,  -387,  -387,  -387,  -387,   879,   775,   348,  1394,  -387,
    -387,   349,  -387,  -387,   945,   350,   409,   431,  -387,  -387,
    -387,   945,  1422,   -60,  -387,  -387,  -387,  -387,  -387,  1496,
     390,   355,    -1,   353,   357,  -387,   372,   905,  -387,    91,
      78,   464,   364,  -387,  -387,   366,   369,  -387,   373,  -387,
      91,  -387,   412,  -387,   398,   487,  -387
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      45,    29,   108,    63,    64,     0,     0,     0,     0,    41,
      46,    84,    85,    86,     0,     0,   191,     0,     0,     0,
       0,     0,     3,     9,     2,    45,    31,    33,     0,    34,
      35,    36,    38,    40,    39,    58,    57,     0,    37,    28,
     112,   107,     0,     0,     0,     0,    54,    55,     0,     0,
      83,    51,    52,     0,     0,     0,    45,     0,    45,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      43,    44,     0,    87,     0,     0,   110,   183,     0,    65,
       0,     0,     0,     0,   184,   185,     0,     0,     0,     0,
       0,   182,   181,     0,    59,    60,    83,   213,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,   120,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,   131,   145,    67,    75,   123,
      79,    69,   181,    73,   114,   115,   193,   136,   194,   197,
     192,    50,     0,     5,     0,     4,   112,    11,    10,    27,
      26,    19,    18,    17,    24,    25,    20,    21,    22,    23,
      12,    13,    14,    15,    16,     0,   104,    88,     0,    89,
      98,   100,    90,   113,     0,     0,     0,   149,   150,     0,
       0,     0,     0,   173,   172,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,    61,
      62,    92,     0,   219,     0,   214,    47,    48,     0,    83,
       0,   142,     0,    83,   213,   130,     0,     0,   121,    83,
      83,     0,     0,     0,     0,    70,    96,     0,     0,     0,
       0,     0,     0,     0,   145,   147,     0,    83,     0,     0,
       0,     0,     0,     0,   125,   126,     0,     0,     0,     0,
       0,     0,     0,   111,    83,     0,     0,     0,     0,     0,
       0,   190,   189,   213,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   167,   166,   159,   158,   157,   164,   165,
     160,   161,   162,   163,   168,   169,   152,   153,   154,   155,
     156,    83,    53,     0,    56,     0,   145,   118,   143,   119,
     108,    72,    71,   122,     0,   215,     0,     0,   145,   145,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
     198,     0,    66,   148,    68,    80,   124,   219,   117,   217,
     135,   223,     0,     0,     0,     0,   221,   225,   116,     0,
     132,    74,   167,   204,   166,   203,   202,   201,   200,   199,
       0,     7,     0,    95,     0,     0,   105,   229,     0,    99,
       0,   102,   101,     0,     0,     0,   177,   178,   186,   170,
       0,     0,     0,    93,   220,     0,   144,     0,     0,     0,
       0,   129,   128,     0,     0,   205,   207,   206,   208,    97,
       0,     0,     0,   140,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,   191,   106,   230,   231,    91,     0,
       0,     0,   191,     0,     0,   179,   180,    49,   181,   141,
     216,   127,   138,   139,    77,     0,     0,     0,     0,   133,
     228,     0,   226,   134,     0,     0,   195,     0,   188,   187,
     175,   213,     0,     0,    78,    76,   218,   222,   227,     6,
       0,     0,     0,     0,     0,   174,     0,     0,    42,     0,
     191,     0,     0,   209,   210,   211,     0,   176,     0,   196,
       0,   103,     0,   212,     0,     0,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -387,  -387,  -387,  -387,  -387,   582,   143,  -387,   467,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
     152,  -387,   -15,  -115,   241,  -387,  -387,   243,  -387,  -387,
      62,  -256,  -387,   165,   -78,  -387,  -387,  -387,     1,   -56,
     418,   351,  -226,  -387,  -386,  -101,  -387,  -219,  -387,  -387,
      98,  -372,  -113,  -387,  -119,  -387,  -387,    16,  -229,  -387,
     247,  -252,  -387,  -259,  -387
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,    56,    58,    22,    23,    24,    25,    26,    27,
      82,    28,    29,    30,    31,    32,    48,    33,    34,    35,
     135,   101,    51,   136,   137,   138,   139,   140,    37,   178,
     141,   222,   374,   245,   179,   180,   381,   181,   102,    40,
      41,    86,   143,   144,   145,   230,   231,   256,   257,   189,
     146,    54,   147,   472,   148,   149,   485,   486,   224,   400,
     348,   225,   357,   358,   378
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    39,   235,   156,   360,   324,   182,   323,   349,   349,
       2,   232,   439,   108,   253,   176,     1,   109,   373,   254,
       2,    39,   371,    80,    81,   326,   269,   270,   353,     2,
     351,    43,   391,   392,     2,   341,   426,    42,    42,   151,
     361,   184,   233,    11,    12,    13,   185,   186,    44,   291,
     352,   142,   456,   340,   384,   393,   198,   199,    39,   464,
     460,   394,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
    -146,  -146,  -146,   177,    87,   269,   270,    38,     2,    83,
      88,   372,    49,    84,   416,   483,   418,   396,    89,   484,
     421,    90,    91,    92,   -94,    93,    45,    19,   487,   403,
     404,    50,   351,   110,   316,   353,     2,    19,    38,    20,
      38,   354,    94,    95,   328,   329,    19,    53,   246,   281,
     318,    19,   352,   355,   351,   142,   291,   427,     2,    55,
     103,   259,   428,   261,   463,   263,   346,   440,   363,   365,
     367,   369,    36,   275,   352,   131,   132,    96,   276,  -146,
     451,   452,   447,    46,   264,   265,    47,    42,   221,    57,
     283,   323,   397,   284,   187,    97,   188,    36,    11,    12,
      13,    98,   430,   431,    99,    19,   419,   100,   420,    61,
     380,   285,    62,   104,   193,   194,   195,   359,   197,   153,
     379,   155,   105,   354,    59,   223,    85,   150,    36,   106,
      36,   107,   152,    19,     2,   355,   175,   176,   292,   190,
     465,    76,    77,    78,   191,   354,   192,   196,   219,   220,
     142,   252,   474,   226,   142,    19,   228,   355,   327,   227,
     142,   142,   330,   331,   332,   333,   259,   260,   261,   262,
     263,   211,   212,   213,   214,   215,   216,   217,   142,   215,
     216,   217,   229,   356,   356,   234,   238,   142,   236,   264,
     265,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   280,   237,   239,   385,   240,   241,   250,   286,
     287,   242,   356,   356,   288,   322,   243,   255,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   244,   315,    74,    75,    76,
      77,    78,   223,   247,   248,   246,   221,    74,    75,    76,
      77,    78,   249,   251,   266,   335,   336,   337,   213,   214,
     215,   216,   217,   258,   356,   271,   356,   274,   347,   347,
     356,   278,   279,   282,   482,   362,   364,   366,   368,   277,
     291,   292,   311,   221,   458,   314,   312,   382,   317,   325,
     319,   223,   334,   338,   339,   342,   370,   390,     1,   -83,
     375,   376,     2,   -83,   399,   386,   377,   398,   142,   438,
       3,     4,   401,     5,     6,   402,   405,   406,   407,   408,
       7,   223,     8,   415,   417,   270,   413,   422,     9,   423,
     356,   356,   424,   425,   429,   432,   433,   435,    10,   436,
     437,    11,    12,    13,   441,   442,   443,   444,   445,   449,
     446,    14,    15,    16,   450,   453,   438,   142,   454,    17,
     455,   459,   457,   461,    18,   466,   468,   478,   470,   471,
     473,   477,   481,   476,   480,   479,    87,   488,   111,   112,
     113,   489,    88,   114,   490,   115,   116,   117,     3,     4,
      89,   492,   491,    90,    91,    92,   494,    93,   495,    19,
     496,    20,    79,   118,   119,   120,   343,   223,   344,   409,
     121,   345,   122,   183,    94,    95,   493,   273,   350,    11,
      12,    13,   223,   448,   123,   124,   125,   126,   127,     0,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,   462,     0,     0,     0,   131,   132,     0,    96,
      70,    71,    72,    73,     0,     0,    74,    75,    76,    77,
      78,     0,   469,     0,     0,     0,     0,    97,     0,   223,
       0,     0,     0,    98,     0,     0,    99,    19,     0,   133,
      87,     0,   111,   112,   113,   134,    88,   114,     0,   115,
     116,   117,     3,     4,    89,     0,     0,    90,    91,    92,
       0,    93,     0,     0,     0,     0,     0,   118,   119,   120,
       0,     0,    60,     0,   121,     0,   122,     0,    94,    95,
       0,     0,     0,    11,    12,    13,     0,     0,   123,   124,
     125,   126,   127,     0,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
     131,   132,     0,    96,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    97,     0,     0,     0,     0,     0,    98,     0,     0,
      99,    19,     0,   133,    87,     0,   111,   112,   320,   134,
      88,   114,     0,   115,   116,   117,     3,     4,    89,     0,
       0,    90,    91,    92,     0,    93,     0,     0,     0,     0,
       0,   118,   119,   120,     0,     0,     0,     0,   121,     0,
     122,     0,    94,    95,     0,     0,     0,    11,    12,    13,
       0,     0,   123,   124,   125,   126,   321,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   272,   131,   132,     0,    96,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    97,    74,    75,    76,    77,
      78,    98,     0,     0,    99,    19,     0,   133,    87,     0,
     111,   112,   320,   134,    88,   114,     0,   115,   116,   117,
       3,     4,    89,     0,     0,    90,    91,    92,     0,    93,
       0,     0,     0,     0,     0,   118,   119,   120,     0,     0,
       0,     0,   121,     0,   122,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   131,   132,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,    98,     0,     0,    99,    19,
       0,   133,    87,     0,     0,     0,     2,   134,    88,   114,
       0,   115,   116,   117,     3,     4,    89,     0,     0,    90,
      91,    92,     0,    93,     0,     0,     0,     0,    87,     0,
       0,   120,     2,     0,    88,     0,   121,     0,   122,     0,
      94,    95,    89,     0,     0,    90,    91,    92,     0,    93,
     123,   124,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    87,     0,
       0,     0,     2,     0,    88,    96,   123,   124,   125,   126,
       0,     0,    89,     0,     0,    90,    91,    92,     0,    93,
       0,     0,     0,    97,     0,     0,     0,     0,     0,    98,
       0,    96,    99,    19,     0,   133,    94,    95,     0,   -83,
       0,   134,     0,   -83,     0,     0,     0,     0,     0,    97,
       3,     4,     0,     5,     6,    98,   289,     0,    99,    19,
       7,   133,     8,     0,     0,     0,     0,     0,     9,     0,
       0,    96,     0,     0,     0,     0,     0,     0,    10,     0,
       0,    11,    12,    13,   289,     0,     0,     0,     0,    97,
       0,    14,    15,    16,     0,    98,     0,     0,    99,    19,
       0,   100,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   267,   268,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   -30,
       0,     0,     0,   -83,     0,     0,     0,   -83,   290,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     6,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    14,    15,    16,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,   313,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   387,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   411,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   467,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   475,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   267,   268,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,    76,
      77,    78,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   268,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      76,    77,    78,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      76,    77,    78,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,    76,    77,
      78,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      15,     0,   115,    59,   263,   234,    84,   233,   260,   261,
       7,   112,   398,     3,   133,     7,     3,     7,   274,   134,
       7,    20,     3,    44,    45,     3,    80,    81,    88,     7,
       3,    11,   291,   292,     7,   254,     7,   109,   109,    54,
     266,   109,   114,    46,    47,    48,   114,   115,    11,   109,
      23,    50,   424,   107,   283,   311,    78,    79,    57,   445,
     432,   313,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      34,    35,    36,    75,     3,    80,    81,    25,     7,     4,
       9,    72,   109,     8,   353,     4,   355,   316,    17,     8,
     359,    20,    21,    22,   107,    24,     7,   104,   480,   328,
     329,   112,     3,   103,   229,    88,     7,   104,    56,   106,
      58,    94,    41,    42,   239,   240,   104,    49,   127,   185,
     231,   104,    23,   106,     3,   134,   109,   108,     7,    65,
      42,    75,   113,    77,    78,    79,   259,   399,   267,   268,
     269,   270,     0,   109,    23,    73,    74,    76,   114,   113,
     419,   420,   414,     7,    98,    99,    10,   109,   106,    68,
     106,   397,   114,   109,     7,    94,     9,    25,    46,    47,
      48,   100,   114,   115,   103,   104,   106,   106,   108,     0,
     109,   190,   108,    11,    96,    97,    98,    88,   100,    56,
     278,    58,    11,    94,   111,   107,   111,     3,    56,   112,
      58,   106,    68,   104,     7,   106,     7,     7,   109,   106,
     446,    95,    96,    97,   106,    94,   106,   106,    11,    11,
     229,   133,   461,   110,   233,   104,   106,   106,   237,   110,
     239,   240,   241,   242,   243,   244,    75,    76,    77,    78,
      79,    91,    92,    93,    94,    95,    96,    97,   257,    95,
      96,    97,    36,   262,   263,   106,     7,   266,   106,    98,
      99,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   184,   106,   112,   284,   112,   106,    93,   191,
     192,   106,   291,   292,   196,   233,   106,    33,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   106,   228,    93,    94,    95,
      96,    97,   234,   106,   106,   334,   274,    93,    94,    95,
      96,    97,   106,    93,    40,   247,   248,   249,    93,    94,
      95,    96,    97,   108,   353,   106,   355,   106,   260,   261,
     359,   108,    75,     7,   477,   267,   268,   269,   270,   112,
     109,   109,    33,   311,   430,   107,   113,   279,    34,    11,
      35,   283,   108,     3,     3,   113,    90,   289,     3,     4,
       3,     3,     7,     8,   108,   107,     7,   107,   397,   398,
      15,    16,   107,    18,    19,   107,   107,   107,   107,   107,
      25,   313,    27,   106,     3,    81,   113,     3,    33,    90,
     419,   420,   107,   110,     3,   107,   110,   110,    43,   110,
     110,    46,    47,    48,   107,   113,   113,    61,     6,    87,
      63,    56,    57,    58,   107,    87,   445,   446,   107,    64,
       3,     7,   110,   106,    69,   107,   107,   472,   108,    50,
      29,   106,    90,    73,   107,   112,     3,     3,     5,     6,
       7,   107,     9,    10,   108,    12,    13,    14,    15,    16,
      17,   108,   113,    20,    21,    22,    74,    24,    90,   104,
       3,   106,    25,    30,    31,    32,    33,   399,   257,   334,
      37,   258,    39,    85,    41,    42,   490,   156,   261,    46,
      47,    48,   414,   415,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,    -1,    -1,    -1,    73,    74,    -1,    76,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    96,
      97,    -1,   454,    -1,    -1,    -1,    -1,    94,    -1,   461,
      -1,    -1,    -1,   100,    -1,    -1,   103,   104,    -1,   106,
       3,    -1,     5,     6,     7,   112,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    20,    -1,    37,    -1,    39,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      73,    74,    -1,    76,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
     103,   104,    -1,   106,     3,    -1,     5,     6,     7,   112,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    53,    54,    55,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    70,    73,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    94,    93,    94,    95,    96,
      97,   100,    -1,    -1,   103,   104,    -1,   106,     3,    -1,
       5,     6,     7,   112,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    73,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,   103,   104,
      -1,   106,     3,    -1,    -1,    -1,     7,   112,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    32,     7,    -1,     9,    -1,    37,    -1,    39,    -1,
      41,    42,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,     3,    -1,
      -1,    -1,     7,    -1,     9,    76,    51,    52,    53,    54,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    76,   103,   104,    -1,   106,    41,    42,    -1,     4,
      -1,   112,    -1,     8,    -1,    -1,    -1,    -1,    -1,    94,
      15,    16,    -1,    18,    19,   100,    33,    -1,   103,   104,
      25,   106,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    48,    33,    -1,    -1,    -1,    -1,    94,
      -1,    56,    57,    58,    -1,   100,    -1,    -1,   103,   104,
      -1,   106,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      -1,    -1,    -1,     4,    -1,    -1,    -1,     8,   107,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      96,    97,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    96,    97,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    96,    97,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    96,
      97,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    85,    86,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    96,    97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    15,    16,    18,    19,    25,    27,    33,
      43,    46,    47,    48,    56,    57,    58,    64,    69,   104,
     106,   117,   120,   121,   122,   123,   124,   125,   127,   128,
     129,   130,   131,   133,   134,   135,   136,   144,   146,   154,
     155,   156,   109,    11,    11,     7,     7,    10,   132,   109,
     112,   138,   138,    49,   167,    65,   118,    68,   119,   111,
     121,     0,   108,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    93,    94,    95,    96,    97,   124,
      44,    45,   126,     4,     8,   111,   157,     3,     9,    17,
      20,    21,    22,    24,    41,    42,    76,    94,   100,   103,
     106,   137,   154,   166,    11,    11,   112,   106,     3,     7,
     103,     5,     6,     7,    10,    12,    13,    14,    30,    31,
      32,    37,    39,    51,    52,    53,    54,    55,    59,    60,
      61,    73,    74,   106,   112,   136,   139,   140,   141,   142,
     143,   146,   154,   158,   159,   160,   166,   168,   170,   171,
       3,   138,    68,   122,   121,   122,   155,   107,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,     7,     7,    75,   145,   150,
     151,   153,   150,   156,   109,   114,   115,     7,     9,   165,
     106,   106,   106,   166,   166,   166,   106,   166,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   110,    11,
      11,   146,   147,   166,   174,   177,   110,   110,   106,    36,
     161,   162,   161,   114,   106,   168,   106,   106,     7,   112,
     112,   106,   106,   106,   106,   149,   154,   106,   106,   106,
      93,    93,   166,   170,   139,    33,   163,   164,   108,    75,
      76,    77,    78,    79,    98,    99,    40,    80,    81,    80,
      81,   106,    70,   157,   106,   109,   114,   112,   108,    75,
     166,   155,     7,   106,   109,   154,   166,   166,   166,    33,
     107,   109,   109,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,    33,   113,   108,   107,   166,   139,    34,   161,    35,
       7,    55,   146,   158,   174,    11,     3,   154,   139,   139,
     154,   154,   154,   154,   108,   166,   166,   166,     3,     3,
     107,   163,   113,    33,   140,   143,   168,   166,   176,   177,
     176,     3,    23,    88,    94,   106,   154,   178,   179,    88,
     179,   158,   166,   170,   166,   170,   166,   170,   166,   170,
      90,     3,    72,   147,   148,     3,     3,     7,   180,   150,
     109,   152,   166,   110,   174,   154,   107,   107,   107,   107,
     166,   179,   179,   147,   177,   107,   163,   114,   107,   108,
     175,   107,   107,   163,   163,   107,   107,   107,   107,   149,
     107,   107,   107,   113,   106,   106,   179,     3,   179,   106,
     108,   179,     3,    90,   107,   110,     7,   108,   113,     3,
     114,   115,   107,   110,   114,   110,   110,   110,   154,   160,
     177,   107,   113,   113,    61,     6,    63,   177,   166,    87,
     107,   179,   179,    87,   107,     3,   167,   110,   155,     7,
     167,   106,   166,    78,   160,   158,   107,   107,   107,   166,
     108,    50,   169,    29,   174,   107,    73,   106,   138,   112,
     107,    90,   168,     4,     8,   172,   173,   167,     3,   107,
     108,   113,   108,   173,    74,    90,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   116,   117,   117,   117,   117,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   126,   126,   127,   127,   127,   127,   127,
     128,   129,   130,   131,   132,   132,   133,   134,   134,   135,
     135,   135,   135,   136,   136,   137,   138,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   144,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   152,   153,   153,   153,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   167,   167,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   171,   171,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   178,   178,   178,   178,   179,   179,   179,   179,   180,
     180,   180
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     3,     7,     4,    14,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     9,     1,     1,     0,     1,     4,     4,     7,
       3,     2,     2,     5,     1,     1,     5,     1,     1,     3,
       3,     4,     4,     1,     1,     1,     4,     1,     3,     1,
       2,     3,     3,     1,     3,     1,     6,     5,     6,     1,
       3,     3,     3,     0,     1,     1,     1,     0,     1,     3,
       3,     6,     1,     3,     0,     1,     1,     3,     1,     3,
       1,     3,     3,     7,     1,     3,     4,     1,     1,     4,
       2,     4,     0,     2,     1,     1,     3,     3,     3,     3,
       1,     2,     3,     1,     3,     2,     2,     5,     4,     4,
       2,     1,     3,     5,     5,     3,     1,     1,     5,     5,
       4,     5,     1,     2,     3,     0,     1,     1,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     2,     2,     7,     6,     9,     4,     4,     5,
       5,     1,     1,     1,     1,     1,     4,     6,     6,     3,
       3,     0,     2,     1,     1,     0,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     3,     0,     1,     0,     2,     1,     4,     1,
       3,     1,     4,     1,     2,     1,     3,     4,     3,     1,
       2,     2
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
#line 107 "promela.y"
                                                                                        {
#ifdef CLOCK
												yyerror("Property lists are not supported by this CLOCK parser.");
#else
												if(property) *property = (yyvsp[0].pList);
#endif
											}
#line 2035 "y.tab.c"
    break;

  case 4: /* start_parsing: CHECK cformula program  */
#line 114 "promela.y"
                                                {
#ifdef CLOCK
												yyerror("CORA cost formulas are not TCTL properties.");
#else
												if(property) *property = (yyvsp[-1].pCostFormula);
#endif
											}
#line 2047 "y.tab.c"
    break;

  case 5: /* start_parsing: SPEC tctl program  */
#line 121 "promela.y"
                                                                                {
#ifdef CLOCK
												if(property) *property = (yyvsp[-1].pTctlFormula);
#else
												yyerror("TCTL properties require the CLOCK option.");
#endif
											}
#line 2059 "y.tab.c"
    break;

  case 6: /* tctl: EVENTUALLY FINALLY '(' LE CONST ')' expr  */
#line 130 "promela.y"
                                                           {
#ifdef CLOCK
												(yyval.pTctlFormula) = createTctlFormula(CTL_EF, NULL, (yyvsp[-2].iVal), (yyvsp[0].pExpVal));
#else
												(yyval.pTctlFormula) = NULL;
#endif
											}
#line 2071 "y.tab.c"
    break;

  case 7: /* cformula: FINALLY prop WITHIN CONST  */
#line 139 "promela.y"
                                                { (yyval.pCostFormula) = createCostFormula((yyvsp[-2].pExpVal), (yyvsp[0].iVal), INT_MAX, INT_MAX);}
#line 2077 "y.tab.c"
    break;

  case 8: /* cformula: FINALLY prop WITHIN TIME LE CONST ',' COST LE CONST ',' QUALITY LE CONST  */
#line 140 "promela.y"
                                                                                           { (yyval.pCostFormula) = createCostFormula((yyvsp[-12].pExpVal), (yyvsp[-8].iVal), (yyvsp[-4].iVal), (yyvsp[0].iVal)); }
#line 2083 "y.tab.c"
    break;

  case 9: /* props: prop  */
#line 143 "promela.y"
                                                                                { (yyval.pList) = listAdd(NULL,(yyvsp[0].pExpVal)); }
#line 2089 "y.tab.c"
    break;

  case 10: /* props: props ',' prop  */
#line 144 "promela.y"
                                                                                { (yyval.pList) = listAdd((yyvsp[-2].pList),(yyvsp[0].pExpVal)); }
#line 2095 "y.tab.c"
    break;

  case 11: /* prop: '(' prop ')'  */
#line 147 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2101 "y.tab.c"
    break;

  case 12: /* prop: prop '+' prop  */
#line 148 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2107 "y.tab.c"
    break;

  case 13: /* prop: prop '-' prop  */
#line 149 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2113 "y.tab.c"
    break;

  case 14: /* prop: prop '*' prop  */
#line 150 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2119 "y.tab.c"
    break;

  case 15: /* prop: prop '/' prop  */
#line 151 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2125 "y.tab.c"
    break;

  case 16: /* prop: prop '%' prop  */
#line 152 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2131 "y.tab.c"
    break;

  case 17: /* prop: prop '&' prop  */
#line 153 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2137 "y.tab.c"
    break;

  case 18: /* prop: prop '^' prop  */
#line 154 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2143 "y.tab.c"
    break;

  case 19: /* prop: prop '|' prop  */
#line 155 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2149 "y.tab.c"
    break;

  case 20: /* prop: prop GT prop  */
#line 156 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2155 "y.tab.c"
    break;

  case 21: /* prop: prop LT prop  */
#line 157 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2161 "y.tab.c"
    break;

  case 22: /* prop: prop GE prop  */
#line 158 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2167 "y.tab.c"
    break;

  case 23: /* prop: prop LE prop  */
#line 159 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2173 "y.tab.c"
    break;

  case 24: /* prop: prop EQ prop  */
#line 160 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2179 "y.tab.c"
    break;

  case 25: /* prop: prop NE prop  */
#line 161 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2185 "y.tab.c"
    break;

  case 26: /* prop: prop AND prop  */
#line 162 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2191 "y.tab.c"
    break;

  case 27: /* prop: prop OR prop  */
#line 163 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2197 "y.tab.c"
    break;

  case 28: /* prop: varref  */
#line 164 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2203 "y.tab.c"
    break;

  case 29: /* prop: CONST  */
#line 165 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2209 "y.tab.c"
    break;

  case 30: /* program: units  */
#line 192 "promela.y"
                                                                                {
#ifdef CLOCK
											if(_clocks) encodeClocks(_clocks);
#endif
											}
#line 2219 "y.tab.c"
    break;

  case 36: /* unit: events  */
#line 206 "promela.y"
                                                                { yyerror("The 'events' construct is currently not supported."); }
#line 2225 "y.tab.c"
    break;

  case 37: /* unit: one_decl  */
#line 207 "promela.y"
                                                                { if((yyvsp[0].pSymTabNodeVal) != NULL) *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[0].pSymTabNodeVal)); }
#line 2231 "y.tab.c"
    break;

  case 38: /* unit: utype  */
#line 208 "promela.y"
                                                                { *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[0].pSymTabNodeVal)); }
#line 2237 "y.tab.c"
    break;

  case 39: /* unit: c_fcts  */
#line 209 "promela.y"
                                                                { yyerror("Embedded C code is not supported."); }
#line 2243 "y.tab.c"
    break;

  case 40: /* unit: ns  */
#line 210 "promela.y"
                                                                { yyerror("The 'named sequence' construct is currently not supported."); }
#line 2249 "y.tab.c"
    break;

  case 42: /* proc: inst proctype NAME '(' decl ')' Opt_priority Opt_enabler body  */
#line 220 "promela.y"
                                                                                        {	(yyvsp[0].pFsmVal)->symTab = addToSymTab((yyvsp[-4].pSymTabNodeVal), (yyvsp[0].pFsmVal)->symTab);
			  										*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, (yyvsp[-6].sVal), nbrLines, 0, 0, (yyvsp[-8].pExpVal), (yyvsp[0].pFsmVal), NULL));
												}
#line 2257 "y.tab.c"
    break;

  case 44: /* proctype: D_PROCTYPE  */
#line 226 "promela.y"
                                                                                { yyerror("Deterministic proctypes are not supported (only useful for simulation)."); }
#line 2263 "y.tab.c"
    break;

  case 45: /* inst: %empty  */
#line 229 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2269 "y.tab.c"
    break;

  case 46: /* inst: ACTIVE  */
#line 230 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 1, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2275 "y.tab.c"
    break;

  case 47: /* inst: ACTIVE '[' CONST ']'  */
#line 231 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, (yyvsp[-1].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2281 "y.tab.c"
    break;

  case 48: /* inst: ACTIVE '[' NAME ']'  */
#line 232 "promela.y"
                                                                        {	ptSymTabNode var = lookupInSymTab(*globalSymTab, (yyvsp[-1].sVal));
													if(var == NULL) yyserror("The variable %s does not exist.", (yyvsp[-1].sVal));
													else if(var->type != T_INT && var->type != T_BIT && var->type != T_SHORT) yyserror("The variable %s is not of type int, short or bit.", (yyvsp[-1].sVal));
													else if(var->init == NULL || var->init->type != E_EXPR_CONST) yyserror("The variable %s does not have a constant value.", (yyvsp[-1].sVal));
													else {
														(yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, var->init->iVal, NULL, NULL, NULL, nbrLines, NULL, NULL);
													}
													free((yyvsp[-1].sVal));
												}
#line 2295 "y.tab.c"
    break;

  case 49: /* inst: ACTIVE '[' COUNT '(' expr ')' ']'  */
#line 241 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[-2].pExpVal), NULL, NULL, nbrLines, NULL, NULL); 
#if !defined(Z3) && !defined(MULTI)
                                         		  failure("Feature clones are not allowed in this variant of SNIP.\n");
#endif
												}
#line 2305 "y.tab.c"
    break;

  case 50: /* init: INIT Opt_priority body  */
#line 248 "promela.y"
                                                                {	if(lookupInSymTab(*globalSymTab, "init") != NULL) yyerror("This is the second init process; only one is allowed.");
													else {
														*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, "init", nbrLines, 1, 0, NULL, (yyvsp[0].pFsmVal), NULL));
													}

												}
#line 2316 "y.tab.c"
    break;

  case 51: /* claim: CLAIM body  */
#line 256 "promela.y"
                                                                        { 	if(neverClaim != NULL) yyerror("Found a second never claim.  Only one claim at a time is allowed.");
													else {
														neverClaim = createSymTabNode(T_NEVER, "__never", nbrLines, 1, 0, NULL, (yyvsp[0].pFsmVal), NULL);
														*globalSymTab = addToSymTab(*globalSymTab, neverClaim);
													}
												}
#line 2327 "y.tab.c"
    break;

  case 52: /* events: TRACE body  */
#line 264 "promela.y"
                                                                        { yyerror("Event sequences (traces) are not supported."); }
#line 2333 "y.tab.c"
    break;

  case 53: /* utype: TYPEDEF NAME '{' decl_lst '}'  */
#line 267 "promela.y"
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
#line 2366 "y.tab.c"
    break;

  case 66: /* body: '{' sequence OS '}'  */
#line 321 "promela.y"
                                                                { (yyval.pFsmVal) = (yyvsp[-2].pFsmVal); }
#line 2372 "y.tab.c"
    break;

  case 67: /* sequence: step  */
#line 324 "promela.y"
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
#line 2388 "y.tab.c"
    break;

  case 68: /* sequence: sequence MS step  */
#line 335 "promela.y"
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
#line 2404 "y.tab.c"
    break;

  case 69: /* step: one_decl  */
#line 348 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_DECL, NULL, 0, NULL, NULL, NULL, nbrLines, NULL, (yyvsp[0].pSymTabNodeVal)); }
#line 2410 "y.tab.c"
    break;

  case 70: /* step: XU vref_lst  */
#line 349 "promela.y"
                                                                                { yyerror("Channel assertions are currently not supported."); }
#line 2416 "y.tab.c"
    break;

  case 71: /* step: NAME ':' one_decl  */
#line 350 "promela.y"
                                                                                { yyerror("Declarations with labels are not suported."); }
#line 2422 "y.tab.c"
    break;

  case 72: /* step: NAME ':' XU  */
#line 351 "promela.y"
                                                                                { yyerror("Channel assertions are currently not supported."); }
#line 2428 "y.tab.c"
    break;

  case 73: /* step: stmnt  */
#line 352 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2434 "y.tab.c"
    break;

  case 74: /* step: stmnt UNLESS stmnt  */
#line 353 "promela.y"
                                                                        { yyerror("Unless statements are currently not supported."); }
#line 2440 "y.tab.c"
    break;

  case 75: /* step: timed_stmnt  */
#line 354 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2446 "y.tab.c"
    break;

  case 76: /* timed_stmnt: WAIT '(' expr ')' THEN stmnt  */
#line 357 "promela.y"
                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_WHEN, NULL, 0, (yyvsp[-3].pExpVal), (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2452 "y.tab.c"
    break;

  case 77: /* timed_stmnt: WHILE '(' expr ')' WAIT  */
#line 358 "promela.y"
                                                                        {
#ifdef CLOCK
											(yyval.pExpVal) = createExpNode(E_STMNT_WAIT, NULL, 0, (yyvsp[-2].pExpVal), NULL, NULL, nbrLines, NULL, NULL);
#else
											yyerror("Clock invariants require the CLOCK option.");
											(yyval.pExpVal) = NULL;
#endif
										}
#line 2465 "y.tab.c"
    break;

  case 78: /* timed_stmnt: WHEN '(' expr ')' DO Stmnt  */
#line 366 "promela.y"
                                                                {
#ifdef CLOCK
											(yyval.pExpVal) = createExpNode(E_STMNT_WHEN, NULL, 0, (yyvsp[-3].pExpVal), (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL);
#else
											yyerror("Clock guards require the CLOCK option.");
											(yyval.pExpVal) = NULL;
#endif
										}
#line 2478 "y.tab.c"
    break;

  case 79: /* nf_stmnt: cost_stmnt  */
#line 376 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2484 "y.tab.c"
    break;

  case 80: /* nf_stmnt: cost_stmnt ',' cost_stmnt  */
#line 377 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[-2].pExpVal), (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2490 "y.tab.c"
    break;

  case 81: /* cost_stmnt: COST '+' CONST  */
#line 380 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_COST, NULL, (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2496 "y.tab.c"
    break;

  case 82: /* cost_stmnt: QUALITY '+' CONST  */
#line 381 "promela.y"
                                                { (yyval.pExpVal) = createExpNode(E_STMNT_QUALITY, NULL, (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2502 "y.tab.c"
    break;

  case 84: /* vis: HIDDEN  */
#line 385 "promela.y"
                                                                                        { yyerror("The 'hidden' keyword is not supported."); }
#line 2508 "y.tab.c"
    break;

  case 85: /* vis: SHOW  */
#line 386 "promela.y"
                                                                                        { yyerror("The 'show' keyword is not supported."); }
#line 2514 "y.tab.c"
    break;

  case 86: /* vis: ISLOCAL  */
#line 387 "promela.y"
                                                                                        { yyerror("The 'local' keyword is not supported."); }
#line 2520 "y.tab.c"
    break;

  case 89: /* one_decl: vis TYPE var_list  */
#line 397 "promela.y"
                                                                        {	ptSymTabNode cur = (yyvsp[0].pSymTabNodeVal);
													while(cur != NULL) {
														// If type != 0, then the var is a T_CHAN
														if(cur->type == 0) cur->type = (yyvsp[-1].iVal);
												if(cur->type == T_CLOCK) {
#ifdef CLOCK
													if(!_clocks) _clocks = listAdd(NULL, GLOBAL_CLOCK);
													_clocks = listAdd(_clocks, cur->name);
#else
													yyerror("Clocks can only be declared when the CLOCK option is enabled.");
#endif
												}
														cur = cur->next;
													}
													(yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal);
												}
#line 2541 "y.tab.c"
    break;

  case 90: /* one_decl: vis UNAME var_list  */
#line 413 "promela.y"
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
#line 2559 "y.tab.c"
    break;

  case 91: /* one_decl: vis TYPE asgn '{' nlst '}'  */
#line 426 "promela.y"
                                                                {	if((yyvsp[-4].iVal) != T_MTYPE) yyerror("This syntax only works for MTYPEs.");
													(yyval.pSymTabNodeVal) = NULL;
													/* The mtype values are added in the nlst rule. */ 
												}
#line 2568 "y.tab.c"
    break;

  case 92: /* decl_lst: one_decl  */
#line 432 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2574 "y.tab.c"
    break;

  case 93: /* decl_lst: one_decl SEMI decl_lst  */
#line 433 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[-2].pSymTabNodeVal), (yyvsp[0].pSymTabNodeVal)); }
#line 2580 "y.tab.c"
    break;

  case 94: /* decl: %empty  */
#line 437 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = NULL; }
#line 2586 "y.tab.c"
    break;

  case 95: /* decl: decl_lst  */
#line 438 "promela.y"
                                                                                        { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2592 "y.tab.c"
    break;

  case 98: /* var_list: ivar  */
#line 445 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = (yyvsp[0].pSymTabNodeVal); }
#line 2598 "y.tab.c"
    break;

  case 99: /* var_list: ivar ',' var_list  */
#line 446 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[-2].pSymTabNodeVal), (yyvsp[0].pSymTabNodeVal)); }
#line 2604 "y.tab.c"
    break;

  case 100: /* ivar: vardcl  */
#line 449 "promela.y"
                                                                                { (yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[0].pDataVal).sVal, nbrLines, (yyvsp[0].pDataVal).iVal,		  0, NULL, NULL, NULL); }
#line 2610 "y.tab.c"
    break;

  case 101: /* ivar: vardcl ASGN expr  */
#line 450 "promela.y"
                                                                                { 	int mtype;
													if((yyvsp[0].pExpVal)->type == E_EXPR_VAR && (mtype = getMTypeValue(*mtypes, (yyvsp[0].pExpVal)->children[0]->children[0]->sVal)) != -1) {
														(yyvsp[0].pExpVal)->type = E_EXPR_CONST;
														(yyvsp[0].pExpVal)->iVal = mtype;
														destroyExpNode((yyvsp[0].pExpVal)->children[0]);
													}
													(yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[-2].pDataVal).sVal, nbrLines, (yyvsp[-2].pDataVal).iVal,	 	  0,   (yyvsp[0].pExpVal), NULL, NULL);
												}
#line 2623 "y.tab.c"
    break;

  case 102: /* ivar: vardcl ASGN ch_init  */
#line 458 "promela.y"
                                                                        { (yyval.pSymTabNodeVal) = createSymTabNode(T_CHAN, (yyvsp[-2].pDataVal).sVal, nbrLines, (yyvsp[-2].pDataVal).iVal, (yyvsp[0].pDataVal).iVal, NULL, NULL, (yyvsp[0].pDataVal).symTabNodeVal); }
#line 2629 "y.tab.c"
    break;

  case 103: /* ch_init: '[' CONST ']' OF '{' typ_list '}'  */
#line 461 "promela.y"
                                                        { (yyval.pDataVal).iVal = (yyvsp[-5].iVal); (yyval.pDataVal).symTabNodeVal = (yyvsp[-1].pSymTabNodeVal); }
#line 2635 "y.tab.c"
    break;

  case 104: /* vardcl: NAME  */
#line 464 "promela.y"
                                                                                { (yyval.pDataVal).sVal = (yyvsp[0].sVal); (yyval.pDataVal).iVal = 1; }
#line 2641 "y.tab.c"
    break;

  case 105: /* vardcl: NAME ':' CONST  */
#line 465 "promela.y"
                                                                                { yyerror("The 'unsigned' data type is not supported."); }
#line 2647 "y.tab.c"
    break;

  case 106: /* vardcl: NAME '[' CONST ']'  */
#line 466 "promela.y"
                                                                        { (yyval.pDataVal).sVal = (yyvsp[-3].sVal); (yyval.pDataVal).iVal = (yyvsp[-1].iVal); }
#line 2653 "y.tab.c"
    break;

  case 107: /* varref: cmpnd  */
#line 469 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2659 "y.tab.c"
    break;

  case 108: /* pfld: NAME  */
#line 472 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF_NAME, (yyvsp[0].sVal), 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2665 "y.tab.c"
    break;

  case 109: /* pfld: NAME '[' expr ']'  */
#line 473 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF_NAME,	(yyvsp[-3].sVal), 0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2671 "y.tab.c"
    break;

  case 110: /* cmpnd: pfld sfld  */
#line 476 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 0,   (yyvsp[-1].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2677 "y.tab.c"
    break;

  case 111: /* cmpnd: CONTEXT '.' pfld sfld  */
#line 477 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 1,   (yyvsp[-1].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2683 "y.tab.c"
    break;

  case 112: /* sfld: %empty  */
#line 480 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 2689 "y.tab.c"
    break;

  case 113: /* sfld: '.' cmpnd  */
#line 481 "promela.y"
                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal);   }
#line 2695 "y.tab.c"
    break;

  case 114: /* stmnt: Special  */
#line 484 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2701 "y.tab.c"
    break;

  case 115: /* stmnt: Stmnt  */
#line 485 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2707 "y.tab.c"
    break;

  case 116: /* Special: varref RCV rargs  */
#line 488 "promela.y"
                                                                        { 
													(yyval.pExpVal) = createExpNode(E_STMNT_CHAN_RCV, 	NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); 
												}
#line 2715 "y.tab.c"
    break;

  case 117: /* Special: varref SND margs  */
#line 491 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_CHAN_SND, 	NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2721 "y.tab.c"
    break;

  case 118: /* Special: IF options FI  */
#line 492 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_IF, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL,       (yyvsp[-2].iVal), NULL, NULL); }
#line 2727 "y.tab.c"
    break;

  case 119: /* Special: DO options OD  */
#line 493 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_DO, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL,       (yyvsp[-2].iVal), NULL, NULL); }
#line 2733 "y.tab.c"
    break;

  case 120: /* Special: BREAK  */
#line 494 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_BREAK, 	NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2739 "y.tab.c"
    break;

  case 121: /* Special: GOTO NAME  */
#line 495 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_GOTO, 		(yyvsp[0].sVal), 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2745 "y.tab.c"
    break;

  case 122: /* Special: NAME ':' stmnt  */
#line 496 "promela.y"
                                                                                { if((yyvsp[0].pExpVal)->type == E_STMNT_LABEL && (yyvsp[0].pExpVal)->children[0] && (yyvsp[0].pExpVal)->children[0]->type == E_STMNT_LABEL) yyerror("Only two labels per state are supported."); 
												  (yyval.pExpVal) = createExpNode(E_STMNT_LABEL,		(yyvsp[-2].sVal), 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2752 "y.tab.c"
    break;

  case 123: /* Special: nf_stmnt  */
#line 498 "promela.y"
                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 2758 "y.tab.c"
    break;

  case 124: /* Stmnt: varref ASGN full_expr  */
#line 501 "promela.y"
                                                                {
													(yyval.pExpVal) = createExpNode(E_STMNT_ASGN, 		NULL, 	0,   (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL);
												}
#line 2766 "y.tab.c"
    break;

  case 125: /* Stmnt: varref INCR  */
#line 504 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_INCR, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2772 "y.tab.c"
    break;

  case 126: /* Stmnt: varref DECR  */
#line 505 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_DECR, 		NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2778 "y.tab.c"
    break;

  case 127: /* Stmnt: PRINT '(' STRING prargs ')'  */
#line 506 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_PRINT, 	(yyvsp[-2].sVal), 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2784 "y.tab.c"
    break;

  case 128: /* Stmnt: PRINTM '(' varref ')'  */
#line 507 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2790 "y.tab.c"
    break;

  case 129: /* Stmnt: PRINTM '(' CONST ')'  */
#line 508 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL,  (yyvsp[-1].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2796 "y.tab.c"
    break;

  case 130: /* Stmnt: ASSERT full_expr  */
#line 509 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_ASSERT, 	NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2802 "y.tab.c"
    break;

  case 131: /* Stmnt: ccode  */
#line 510 "promela.y"
                                                                                        { yyerror("Embedded C code is not supported."); }
#line 2808 "y.tab.c"
    break;

  case 132: /* Stmnt: varref R_RCV rargs  */
#line 511 "promela.y"
                                                                        { yyerror("Sorted send and random receive are not supported."); }
#line 2814 "y.tab.c"
    break;

  case 133: /* Stmnt: varref RCV LT rargs GT  */
#line 512 "promela.y"
                                                                        { yyerror("Channel poll operations are not supported."); }
#line 2820 "y.tab.c"
    break;

  case 134: /* Stmnt: varref R_RCV LT rargs GT  */
#line 513 "promela.y"
                                                                        { yyerror("Channel poll operations are not supported."); }
#line 2826 "y.tab.c"
    break;

  case 135: /* Stmnt: varref O_SND margs  */
#line 514 "promela.y"
                                                                        { yyerror("Sorted send and random receive are not supported."); }
#line 2832 "y.tab.c"
    break;

  case 136: /* Stmnt: full_expr  */
#line 515 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_EXPR, 		NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2838 "y.tab.c"
    break;

  case 137: /* Stmnt: ELSE  */
#line 516 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_ELSE, 		NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 2844 "y.tab.c"
    break;

  case 138: /* Stmnt: ATOMIC '{' sequence OS '}'  */
#line 517 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_ATOMIC,	NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[-2].pFsmVal), NULL); }
#line 2850 "y.tab.c"
    break;

  case 139: /* Stmnt: D_STEP '{' sequence OS '}'  */
#line 518 "promela.y"
                                                                { yyerror("Deterministic steps are not yet supported."); }
#line 2856 "y.tab.c"
    break;

  case 140: /* Stmnt: '{' sequence OS '}'  */
#line 519 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_STMNT_SEQ, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[-2].pFsmVal), NULL); }
#line 2862 "y.tab.c"
    break;

  case 141: /* Stmnt: INAME '(' args ')' Stmnt  */
#line 520 "promela.y"
                                                                        { yyerror("Inline calls are not yet supported."); }
#line 2868 "y.tab.c"
    break;

  case 142: /* options: option  */
#line 523 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[0].pFsmVal), NULL); }
#line 2874 "y.tab.c"
    break;

  case 143: /* options: option options  */
#line 524 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines,   (yyvsp[-1].pFsmVal), NULL); }
#line 2880 "y.tab.c"
    break;

  case 144: /* option: SEP sequence OS  */
#line 527 "promela.y"
                                                                        { (yyval.pFsmVal) = (yyvsp[-1].pFsmVal); }
#line 2886 "y.tab.c"
    break;

  case 146: /* OS: SEMI  */
#line 531 "promela.y"
                                        { /* redundant semi at end of sequence */ }
#line 2892 "y.tab.c"
    break;

  case 147: /* MS: SEMI  */
#line 534 "promela.y"
                                        { /* at least one semi-colon */ }
#line 2898 "y.tab.c"
    break;

  case 148: /* MS: MS SEMI  */
#line 535 "promela.y"
                                        { /* but more are okay too   */ }
#line 2904 "y.tab.c"
    break;

  case 149: /* aname: NAME  */
#line 538 "promela.y"
                                                                                { (yyval.sVal) = (yyvsp[0].sVal); }
#line 2910 "y.tab.c"
    break;

  case 150: /* aname: PNAME  */
#line 539 "promela.y"
                                                                                        { (yyval.sVal) = (yyvsp[0].sVal); }
#line 2916 "y.tab.c"
    break;

  case 151: /* expr: '(' expr ')'  */
#line 542 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 2922 "y.tab.c"
    break;

  case 152: /* expr: expr '+' expr  */
#line 543 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2928 "y.tab.c"
    break;

  case 153: /* expr: expr '-' expr  */
#line 544 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2934 "y.tab.c"
    break;

  case 154: /* expr: expr '*' expr  */
#line 545 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2940 "y.tab.c"
    break;

  case 155: /* expr: expr '/' expr  */
#line 546 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2946 "y.tab.c"
    break;

  case 156: /* expr: expr '%' expr  */
#line 547 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2952 "y.tab.c"
    break;

  case 157: /* expr: expr '&' expr  */
#line 548 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2958 "y.tab.c"
    break;

  case 158: /* expr: expr '^' expr  */
#line 549 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2964 "y.tab.c"
    break;

  case 159: /* expr: expr '|' expr  */
#line 550 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2970 "y.tab.c"
    break;

  case 160: /* expr: expr GT expr  */
#line 551 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2976 "y.tab.c"
    break;

  case 161: /* expr: expr LT expr  */
#line 552 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2982 "y.tab.c"
    break;

  case 162: /* expr: expr GE expr  */
#line 553 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2988 "y.tab.c"
    break;

  case 163: /* expr: expr LE expr  */
#line 554 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 2994 "y.tab.c"
    break;

  case 164: /* expr: expr EQ expr  */
#line 555 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3000 "y.tab.c"
    break;

  case 165: /* expr: expr NE expr  */
#line 556 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3006 "y.tab.c"
    break;

  case 166: /* expr: expr AND expr  */
#line 557 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3012 "y.tab.c"
    break;

  case 167: /* expr: expr OR expr  */
#line 558 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3018 "y.tab.c"
    break;

  case 168: /* expr: expr LSHIFT expr  */
#line 559 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_LSHIFT,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3024 "y.tab.c"
    break;

  case 169: /* expr: expr RSHIFT expr  */
#line 560 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_RSHIFT,	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3030 "y.tab.c"
    break;

  case 170: /* expr: COUNT '(' expr ')'  */
#line 561 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3036 "y.tab.c"
    break;

  case 171: /* expr: '~' expr  */
#line 562 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_BITWNEG,NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3042 "y.tab.c"
    break;

  case 172: /* expr: '-' expr  */
#line 563 "promela.y"
                                                                        { 	if((yyvsp[0].pExpVal)->type != E_EXPR_CONST) (yyval.pExpVal) = createExpNode(E_EXPR_UMIN,	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL);
													else {
														(yyvsp[0].pExpVal)->iVal = - (yyvsp[0].pExpVal)->iVal;
														(yyval.pExpVal) = (yyvsp[0].pExpVal);
													}
												}
#line 3053 "y.tab.c"
    break;

  case 173: /* expr: SND expr  */
#line 569 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NEG, 	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3059 "y.tab.c"
    break;

  case 174: /* expr: '(' expr SEMI expr ':' expr ')'  */
#line 570 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_COND, 	NULL, 	0, (yyvsp[-5].pExpVal),   (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), nbrLines, NULL, NULL); }
#line 3065 "y.tab.c"
    break;

  case 175: /* expr: RUN aname '(' args ')' Opt_priority  */
#line 571 "promela.y"
                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[-4].sVal),   0, (yyvsp[-2].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3071 "y.tab.c"
    break;

  case 176: /* expr: RUN aname '[' varref ']' '(' args ')' Opt_priority  */
#line 573 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[-7].sVal),   0, (yyvsp[-2].pExpVal), (yyvsp[-5].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3077 "y.tab.c"
    break;

  case 177: /* expr: LEN '(' varref ')'  */
#line 574 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_LEN, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3083 "y.tab.c"
    break;

  case 178: /* expr: ENABLED '(' expr ')'  */
#line 575 "promela.y"
                                                                        { yyerror("The enabled keyword is not supported."); }
#line 3089 "y.tab.c"
    break;

  case 179: /* expr: varref RCV '[' rargs ']'  */
#line 576 "promela.y"
                                                                        { yyerror("Construct not supported."); /* Unclear */ }
#line 3095 "y.tab.c"
    break;

  case 180: /* expr: varref R_RCV '[' rargs ']'  */
#line 577 "promela.y"
                                                                { yyerror("Sorted send and random receive are not supported."); }
#line 3101 "y.tab.c"
    break;

  case 181: /* expr: varref  */
#line 578 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_VAR, 	NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3107 "y.tab.c"
    break;

  case 182: /* expr: cexpr  */
#line 579 "promela.y"
                                                                                        { yyerror("Embedded C code is not supported."); }
#line 3113 "y.tab.c"
    break;

  case 183: /* expr: CONST  */
#line 580 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3119 "y.tab.c"
    break;

  case 184: /* expr: TIMEOUT  */
#line 581 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_TIMEOUT,NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3125 "y.tab.c"
    break;

  case 185: /* expr: NONPROGRESS  */
#line 582 "promela.y"
                                                                                { yyerror("The 'np_' variable is not supported."); }
#line 3131 "y.tab.c"
    break;

  case 186: /* expr: PC_VAL '(' expr ')'  */
#line 583 "promela.y"
                                                                        { yyerror("The 'pc_value()' construct is not supported."); }
#line 3137 "y.tab.c"
    break;

  case 187: /* expr: PNAME '[' expr ']' '@' NAME  */
#line 584 "promela.y"
                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3143 "y.tab.c"
    break;

  case 188: /* expr: PNAME '[' expr ']' ':' pfld  */
#line 585 "promela.y"
                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3149 "y.tab.c"
    break;

  case 189: /* expr: PNAME '@' NAME  */
#line 586 "promela.y"
                                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3155 "y.tab.c"
    break;

  case 190: /* expr: PNAME ':' pfld  */
#line 587 "promela.y"
                                                                                { yyerror("Construct not supported."); /* Unclear */ }
#line 3161 "y.tab.c"
    break;

  case 192: /* Opt_priority: PRIORITY CONST  */
#line 591 "promela.y"
                                                                                { yyerror("The 'priority' construct is related to simulation and not supported."); }
#line 3167 "y.tab.c"
    break;

  case 193: /* full_expr: expr  */
#line 594 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3173 "y.tab.c"
    break;

  case 194: /* full_expr: Expr  */
#line 595 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3179 "y.tab.c"
    break;

  case 196: /* Opt_enabler: PROVIDED '(' full_expr ')'  */
#line 599 "promela.y"
                                                                { yyerror("The 'provided' construct is currently not supported."); }
#line 3185 "y.tab.c"
    break;

  case 197: /* Expr: Probe  */
#line 604 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3191 "y.tab.c"
    break;

  case 198: /* Expr: '(' Expr ')'  */
#line 605 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3197 "y.tab.c"
    break;

  case 199: /* Expr: Expr AND Expr  */
#line 606 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3203 "y.tab.c"
    break;

  case 200: /* Expr: Expr AND expr  */
#line 607 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3209 "y.tab.c"
    break;

  case 201: /* Expr: Expr OR Expr  */
#line 608 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3215 "y.tab.c"
    break;

  case 202: /* Expr: Expr OR expr  */
#line 609 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3221 "y.tab.c"
    break;

  case 203: /* Expr: expr AND Expr  */
#line 610 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3227 "y.tab.c"
    break;

  case 204: /* Expr: expr OR Expr  */
#line 611 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3233 "y.tab.c"
    break;

  case 205: /* Probe: FULL '(' varref ')'  */
#line 613 "promela.y"
                                                                { (yyval.pExpVal) = createExpNode(E_EXPR_FULL, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3239 "y.tab.c"
    break;

  case 206: /* Probe: NFULL '(' varref ')'  */
#line 614 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NFULL, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3245 "y.tab.c"
    break;

  case 207: /* Probe: EMPTY '(' varref ')'  */
#line 615 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_EMPTY, 	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3251 "y.tab.c"
    break;

  case 208: /* Probe: NEMPTY '(' varref ')'  */
#line 616 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_EXPR_NEMPTY,	NULL, 	0, (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3257 "y.tab.c"
    break;

  case 209: /* basetype: TYPE  */
#line 619 "promela.y"
                                                                                { (yyval.pDataVal).sVal = NULL; (yyval.pDataVal).iVal = (yyvsp[0].iVal); }
#line 3263 "y.tab.c"
    break;

  case 210: /* basetype: UNAME  */
#line 620 "promela.y"
                                                                                        { (yyval.pDataVal).sVal = (yyvsp[0].sVal);   (yyval.pDataVal).iVal = -1; }
#line 3269 "y.tab.c"
    break;

  case 211: /* typ_list: basetype  */
#line 624 "promela.y"
                                                                                {	if((yyvsp[0].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = createSymTabNode((yyvsp[0].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
													} else {
														(yyval.pSymTabNodeVal) = createSymTabNodeUType(*globalSymTab, (yyvsp[0].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if((yyval.pSymTabNodeVal) == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[0].pDataVal).sVal);
														free((yyvsp[0].pDataVal).sVal);
													}
												}
#line 3282 "y.tab.c"
    break;

  case 212: /* typ_list: basetype ',' typ_list  */
#line 632 "promela.y"
                                                                        {	if((yyvsp[-2].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = addToSymTab(createSymTabNode((yyvsp[-2].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL), (yyvsp[0].pSymTabNodeVal));
													} else {
														ptSymTabNode temp = createSymTabNodeUType(*globalSymTab, (yyvsp[-2].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if(temp == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[-2].pDataVal).sVal);
														else (yyval.pSymTabNodeVal) = addToSymTab(temp, (yyvsp[0].pSymTabNodeVal));
														free((yyvsp[-2].pDataVal).sVal);
													}
												}
#line 3296 "y.tab.c"
    break;

  case 213: /* args: %empty  */
#line 644 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 3302 "y.tab.c"
    break;

  case 214: /* args: arg  */
#line 645 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3308 "y.tab.c"
    break;

  case 215: /* prargs: %empty  */
#line 649 "promela.y"
                                                                        { (yyval.pExpVal) = NULL; }
#line 3314 "y.tab.c"
    break;

  case 216: /* prargs: ',' arg  */
#line 650 "promela.y"
                                                                                        { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3320 "y.tab.c"
    break;

  case 217: /* margs: arg  */
#line 654 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[0].pExpVal); }
#line 3326 "y.tab.c"
    break;

  case 218: /* margs: expr '(' arg ')'  */
#line 655 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3332 "y.tab.c"
    break;

  case 219: /* arg: expr  */
#line 658 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3338 "y.tab.c"
    break;

  case 220: /* arg: expr ',' arg  */
#line 659 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3344 "y.tab.c"
    break;

  case 221: /* rarg: varref  */
#line 662 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_RARG_VAR,	NULL, 	0,   (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3350 "y.tab.c"
    break;

  case 222: /* rarg: EVAL '(' expr ')'  */
#line 663 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_RARG_EVAL,	NULL, 	0,   (yyvsp[-1].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3356 "y.tab.c"
    break;

  case 223: /* rarg: CONST  */
#line 664 "promela.y"
                                                                                        { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL,  (yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3362 "y.tab.c"
    break;

  case 224: /* rarg: '-' CONST  */
#line 665 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL, -(yyvsp[0].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
#line 3368 "y.tab.c"
    break;

  case 225: /* rargs: rarg  */
#line 669 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[0].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
#line 3374 "y.tab.c"
    break;

  case 226: /* rargs: rarg ',' rargs  */
#line 670 "promela.y"
                                                                                { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-2].pExpVal),   (yyvsp[0].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3380 "y.tab.c"
    break;

  case 227: /* rargs: rarg '(' rargs ')'  */
#line 671 "promela.y"
                                                                        { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[-3].pExpVal),   (yyvsp[-1].pExpVal), NULL, nbrLines, NULL, NULL); }
#line 3386 "y.tab.c"
    break;

  case 228: /* rargs: '(' rargs ')'  */
#line 672 "promela.y"
                                                                                { (yyval.pExpVal) = (yyvsp[-1].pExpVal); }
#line 3392 "y.tab.c"
    break;

  case 229: /* nlst: NAME  */
#line 675 "promela.y"
                                                                                { *mtypes = addMType(*mtypes, (yyvsp[0].sVal)); }
#line 3398 "y.tab.c"
    break;

  case 230: /* nlst: nlst NAME  */
#line 676 "promela.y"
                                                                                        { *mtypes = addMType(*mtypes, (yyvsp[0].sVal)); }
#line 3404 "y.tab.c"
    break;


#line 3408 "y.tab.c"

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

#line 679 "promela.y"



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
