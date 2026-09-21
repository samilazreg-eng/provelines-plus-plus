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
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
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
/* Line 193 of yacc.c.  */
#line 330 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 343 "y.tab.c"

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  116
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNRULES -- Number of states.  */
#define YYNSTATES  476

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    16,    31,    33,    37,
      41,    45,    49,    53,    57,    61,    65,    69,    73,    77,
      81,    85,    89,    93,    97,   101,   105,   107,   109,   111,
     113,   116,   118,   120,   122,   124,   126,   128,   130,   132,
     134,   144,   146,   148,   149,   151,   156,   161,   169,   173,
     176,   179,   185,   187,   189,   195,   197,   199,   203,   207,
     212,   217,   219,   221,   223,   228,   230,   234,   236,   239,
     243,   247,   249,   253,   255,   262,   264,   268,   272,   276,
     277,   279,   281,   283,   284,   286,   290,   294,   301,   303,
     307,   308,   310,   312,   316,   318,   322,   324,   328,   332,
     340,   342,   346,   351,   353,   355,   360,   363,   368,   369,
     372,   374,   376,   380,   384,   388,   392,   394,   397,   401,
     403,   407,   410,   413,   419,   424,   429,   432,   434,   438,
     444,   450,   454,   456,   458,   464,   470,   475,   481,   483,
     486,   490,   491,   493,   495,   498,   500,   502,   506,   510,
     514,   518,   522,   526,   530,   534,   538,   542,   546,   550,
     554,   558,   562,   566,   570,   574,   578,   583,   586,   589,
     592,   600,   607,   617,   622,   627,   633,   639,   641,   643,
     645,   647,   649,   654,   661,   668,   672,   676,   677,   680,
     682,   684,   685,   690,   692,   696,   700,   704,   708,   712,
     716,   720,   725,   730,   735,   740,   742,   744,   746,   750,
     751,   753,   754,   757,   759,   764,   766,   770,   772,   777,
     779,   782,   784,   788,   793,   797,   799,   802
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     117,     0,    -1,   121,    -1,   119,    -1,    69,   118,   121,
      -1,    68,   120,    70,     3,    -1,    68,   120,    70,    72,
      87,     3,   106,    73,    87,     3,   106,    74,    87,     3,
      -1,   120,    -1,   119,   106,   120,    -1,   107,   120,   108,
      -1,   120,    93,   120,    -1,   120,    94,   120,    -1,   120,
      95,   120,    -1,   120,    96,   120,    -1,   120,    97,   120,
      -1,   120,    84,   120,    -1,   120,    83,   120,    -1,   120,
      82,   120,    -1,   120,    90,   120,    -1,   120,    89,   120,
      -1,   120,    88,   120,    -1,   120,    87,   120,    -1,   120,
      86,   120,    -1,   120,    85,   120,    -1,   120,    81,   120,
      -1,   120,    80,   120,    -1,   153,    -1,     3,    -1,   122,
      -1,   123,    -1,   122,   123,    -1,   124,    -1,   127,    -1,
     128,    -1,   129,    -1,   145,    -1,   130,    -1,   133,    -1,
     132,    -1,    33,    -1,   126,   125,     7,   107,   147,   108,
     166,   168,   137,    -1,    44,    -1,    45,    -1,    -1,    43,
      -1,    43,   109,     3,   110,    -1,    43,   109,     7,   110,
      -1,    43,   109,   102,   107,   165,   108,   110,    -1,    58,
     166,   137,    -1,    56,   137,    -1,    57,   137,    -1,    25,
       7,   112,   146,   113,    -1,     7,    -1,    10,    -1,    27,
     131,   107,   173,   108,    -1,   135,    -1,   134,    -1,    18,
      11,    11,    -1,    19,    11,    11,    -1,    18,    11,    11,
      11,    -1,    19,    11,    11,    11,    -1,    15,    -1,    16,
      -1,    17,    -1,   112,   138,   162,   113,    -1,   139,    -1,
     138,   163,   139,    -1,   145,    -1,    55,   148,    -1,     7,
     114,   145,    -1,     7,   114,    55,    -1,   157,    -1,   157,
      40,   157,    -1,   140,    -1,    61,   107,   165,   108,    63,
     157,    -1,   142,    -1,   142,   106,   142,    -1,    73,    93,
       3,    -1,    74,    93,     3,    -1,    -1,    46,    -1,    47,
      -1,    48,    -1,    -1,    75,    -1,   143,     4,   149,    -1,
     143,     8,   149,    -1,   143,     4,   144,   112,   179,   113,
      -1,   145,    -1,   145,    33,   146,    -1,    -1,   146,    -1,
     153,    -1,   153,   106,   148,    -1,   150,    -1,   150,   106,
     149,    -1,   152,    -1,   152,    75,   165,    -1,   152,    75,
     151,    -1,   109,     3,   110,    29,   112,   172,   113,    -1,
       7,    -1,     7,   114,     3,    -1,     7,   109,     3,   110,
      -1,   155,    -1,     7,    -1,     7,   109,   165,   110,    -1,
     154,   156,    -1,   101,   111,   154,   156,    -1,    -1,   111,
     155,    -1,   158,    -1,   159,    -1,   153,    77,   178,    -1,
     153,    79,   175,    -1,     5,   160,    34,    -1,     6,   160,
      35,    -1,    31,    -1,    30,     7,    -1,     7,   114,   157,
      -1,   141,    -1,   153,    75,   167,    -1,   153,    99,    -1,
     153,    98,    -1,    13,   107,    11,   174,   108,    -1,    14,
     107,   153,   108,    -1,    14,   107,     3,   108,    -1,    12,
     167,    -1,   135,    -1,   153,    76,   178,    -1,   153,    77,
      89,   178,    90,    -1,   153,    76,    89,   178,    90,    -1,
     153,    78,   175,    -1,   167,    -1,    32,    -1,    37,   112,
     138,   162,   113,    -1,    39,   112,   138,   162,   113,    -1,
     112,   138,   162,   113,    -1,    10,   107,   173,   108,   159,
      -1,   161,    -1,   161,   160,    -1,    36,   138,   162,    -1,
      -1,    33,    -1,    33,    -1,   163,    33,    -1,     7,    -1,
       9,    -1,   107,   165,   108,    -1,   165,    93,   165,    -1,
     165,    94,   165,    -1,   165,    95,   165,    -1,   165,    96,
     165,    -1,   165,    97,   165,    -1,   165,    84,   165,    -1,
     165,    83,   165,    -1,   165,    82,   165,    -1,   165,    90,
     165,    -1,   165,    89,   165,    -1,   165,    88,   165,    -1,
     165,    87,   165,    -1,   165,    86,   165,    -1,   165,    85,
     165,    -1,   165,    81,   165,    -1,   165,    80,   165,    -1,
     165,    92,   165,    -1,   165,    91,   165,    -1,   102,   107,
     165,   108,    -1,   100,   165,    -1,    94,   165,    -1,    79,
     165,    -1,   107,   165,    33,   165,   114,   165,   108,    -1,
      20,   164,   107,   173,   108,   166,    -1,    20,   164,   109,
     153,   110,   107,   173,   108,   166,    -1,    21,   107,   153,
     108,    -1,    22,   107,   165,   108,    -1,   153,    77,   109,
     178,   110,    -1,   153,    76,   109,   178,   110,    -1,   153,
      -1,   136,    -1,     3,    -1,    41,    -1,    42,    -1,    24,
     107,   165,   108,    -1,     9,   109,   165,   110,   115,     7,
      -1,     9,   109,   165,   110,   114,   154,    -1,     9,   115,
       7,    -1,     9,   114,   154,    -1,    -1,    49,     3,    -1,
     165,    -1,   169,    -1,    -1,    50,   107,   167,   108,    -1,
     170,    -1,   107,   169,   108,    -1,   169,    81,   169,    -1,
     169,    81,   165,    -1,   169,    80,   169,    -1,   169,    80,
     165,    -1,   165,    81,   169,    -1,   165,    80,   169,    -1,
      51,   107,   153,   108,    -1,    53,   107,   153,   108,    -1,
      52,   107,   153,   108,    -1,    54,   107,   153,   108,    -1,
       4,    -1,     8,    -1,   171,    -1,   171,   106,   172,    -1,
      -1,   176,    -1,    -1,   106,   176,    -1,   176,    -1,   165,
     107,   176,   108,    -1,   165,    -1,   165,   106,   176,    -1,
     153,    -1,    23,   107,   165,   108,    -1,     3,    -1,    94,
       3,    -1,   177,    -1,   177,   106,   178,    -1,   177,   107,
     178,   108,    -1,   107,   178,   108,    -1,     7,    -1,   179,
       7,    -1,   179,   106,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   100,   101,   104,   105,   108,   109,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   157,   160,
     161,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     176,   186,   187,   190,   191,   192,   193,   202,   209,   217,
     225,   228,   258,   259,   262,   265,   266,   269,   270,   271,
     272,   275,   276,   279,   282,   285,   296,   309,   310,   311,
     312,   313,   314,   315,   318,   321,   322,   325,   326,   329,
     330,   331,   332,   335,   336,   342,   353,   366,   372,   373,
     377,   378,   381,   382,   385,   386,   389,   390,   398,   401,
     404,   405,   406,   409,   412,   413,   416,   417,   420,   421,
     424,   425,   428,   431,   432,   433,   434,   435,   436,   438,
     441,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   463,   464,
     467,   470,   471,   474,   475,   478,   479,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   509,
     510,   511,   512,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   530,   531,   534,
     535,   538,   539,   544,   545,   546,   547,   548,   549,   550,
     551,   553,   554,   555,   556,   559,   560,   564,   572,   584,
     585,   589,   590,   594,   595,   598,   599,   602,   603,   604,
     605,   609,   610,   611,   612,   615,   616,   617
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "TYPE", "IF", "DO", "NAME",
  "UNAME", "PNAME", "INAME", "STRING", "ASSERT", "PRINT", "PRINTM",
  "C_CODE", "C_DECL", "C_EXPR", "C_STATE", "C_TRACK", "RUN", "LEN",
  "ENABLED", "EVAL", "PC_VAL", "TYPEDEF", "MTYPE", "INLINE", "LABEL", "OF",
  "GOTO", "BREAK", "ELSE", "SEMI", "FI", "OD", "SEP", "ATOMIC",
  "NON_ATOMIC", "D_STEP", "UNLESS", "TIMEOUT", "NONPROGRESS", "ACTIVE",
  "PROCTYPE", "D_PROCTYPE", "HIDDEN", "SHOW", "ISLOCAL", "PRIORITY",
  "PROVIDED", "FULL", "EMPTY", "NFULL", "NEMPTY", "XU", "CLAIM", "TRACE",
  "INIT", "WHILE", "WHEN", "WAIT", "RESET", "THEN", "SPEC", "EVENTUALLY",
  "ALWAYS", "GLOBALLY", "FINALLY", "CHECK", "WITHIN", "MINIMIZE", "TIME",
  "COST", "QUALITY", "ASGN", "R_RCV", "RCV", "O_SND", "SND", "OR", "AND",
  "'|'", "'^'", "'&'", "NE", "EQ", "LE", "GE", "LT", "GT", "RSHIFT",
  "LSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "DECR", "INCR", "'~'",
  "CONTEXT", "COUNT", "NEG", "UMIN", "DOT", "','", "'('", "')'", "'['",
  "']'", "'.'", "'{'", "'}'", "':'", "'@'", "$accept", "start_parsing",
  "cformula", "props", "prop", "program", "units", "unit", "proc",
  "proctype", "inst", "init", "claim", "events", "utype", "nm", "ns",
  "c_fcts", "cstate", "ccode", "cexpr", "body", "sequence", "step",
  "timed_stmnt", "nf_stmnt", "cost_stmnt", "vis", "asgn", "one_decl",
  "decl_lst", "decl", "vref_lst", "var_list", "ivar", "ch_init", "vardcl",
  "varref", "pfld", "cmpnd", "sfld", "stmnt", "Special", "Stmnt",
  "options", "option", "OS", "MS", "aname", "expr", "Opt_priority",
  "full_expr", "Opt_enabler", "Expr", "Probe", "basetype", "typ_list",
  "args", "prargs", "margs", "arg", "rarg", "rargs", "nlst", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   124,    94,    38,   337,   338,   339,   340,   341,
     342,   343,   344,    43,    45,    42,    47,    37,   345,   346,
     126,   347,   348,   349,   350,   351,    44,    40,    41,    91,
      93,    46,   123,   125,    58,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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
       9,     8,    25,    24,    17,    16,    15,    23,    22,    21,
      20,    19,    18,    10,    11,    12,    13,    14,     0,   100,
      84,     0,    85,    94,    96,    86,   109,     0,     0,     0,
     145,   146,     0,     0,     0,     0,   169,   168,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,    59,    60,    88,     0,   215,     0,   210,    45,
      46,     0,    79,     0,   138,     0,    79,   209,   126,     0,
       0,   117,    79,    79,     0,     0,     0,     0,    68,    92,
       0,     0,     0,     0,     0,   141,   143,     0,    79,     0,
       0,     0,     0,     0,     0,   122,   121,     0,     0,     0,
       0,     0,     0,   107,    79,     0,     0,     0,     0,     0,
       0,   186,   185,   209,     0,     0,     0,     0,     0,     0,
     147,     0,     0,   163,   162,   155,   154,   153,   161,   160,
     159,   158,   157,   156,   165,   164,   148,   149,   150,   151,
     152,    79,    51,     0,    54,     0,   141,   114,   139,   115,
     104,    70,    69,   118,     0,   211,     0,     0,   141,   141,
       0,     0,     0,     0,     0,     0,    77,    78,   194,     0,
      64,   144,    66,    76,   120,   219,     0,     0,     0,     0,
     217,   221,   128,     0,   112,   215,   131,   213,   113,    72,
     163,   200,   162,   199,   198,   197,   196,   195,     5,     0,
      91,     0,     0,   101,   225,     0,    95,     0,    98,    97,
       0,     0,     0,   173,   174,   182,   166,     0,     0,     0,
      89,   216,     0,   140,     0,     0,     0,     0,   125,   124,
       0,     0,   201,   203,   202,   204,    93,     0,   136,     0,
       0,   220,     0,     0,     0,     0,     0,     0,   187,   102,
     226,   227,    87,     0,     0,     0,   187,     0,     0,   176,
     175,    47,   177,   137,   212,   123,   134,   135,     0,     0,
     130,   224,   222,     0,   129,     0,     0,   191,     0,   184,
     183,   171,   209,     0,     0,    74,   218,   223,   214,     0,
       0,     0,     0,     0,   170,     0,     0,    40,     0,   187,
       0,     0,   205,   206,   207,     0,   172,     0,   192,     0,
      99,     0,   208,     0,     0,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    55,    21,    22,    23,    24,    25,    26,    79,
      27,    28,    29,    30,    31,    47,    32,    33,    34,   130,
      98,    50,   131,   132,   133,   134,   135,    36,   171,   136,
     215,   361,   238,   172,   173,   368,   174,    99,    39,    40,
      83,   138,   139,   140,   223,   224,   247,   248,   182,   141,
      53,   142,   451,   143,   144,   464,   465,   217,   387,   346,
     218,   341,   342,   365
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -364
static const yytype_int16 yypact[] =
{
     880,  -364,   -94,  -364,  -364,     8,    43,    96,   124,  -364,
     -29,  -364,  -364,  -364,    -1,    -1,    71,    67,    26,    15,
     153,    61,  1479,  -364,  1036,  -364,  -364,   116,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,    82,  -364,  -364,    58,
    -364,   300,   179,   194,    76,  -364,  -364,   102,    10,   523,
    -364,  -364,   208,    -1,    15,  1109,   205,   525,  -364,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,  -364,  -364,  -364,   207,
       3,   215,     9,  -364,  -364,   -83,  -364,    80,   122,   143,
     144,  -364,  -364,   300,   300,   300,   147,   300,  -364,   -36,
    1123,   217,   244,   103,   300,   146,   168,   150,   243,   243,
     -65,   173,   941,   197,   199,   277,  -364,  -364,   196,   198,
     204,   209,   211,   216,     9,   219,   221,   222,   941,   523,
    -364,   279,  -364,  -364,  -364,   225,  -364,    95,   299,  -364,
    -364,  1443,  -364,   -33,  -364,  -364,  -364,   633,  -364,    58,
    -364,  1479,  1530,   177,   741,  1544,   287,   240,   240,   261,
     261,   261,   261,   121,   121,  -364,  -364,  -364,   236,   -21,
    -364,   237,  -364,   242,   284,  -364,  -364,   300,   205,   355,
    -364,  -364,    -8,     9,   300,   300,  -364,  -364,  -364,   300,
     714,   254,   255,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,  -364,  -364,  -364,   345,   274,  1416,   280,  -364,  -364,
    -364,   300,   523,   356,   243,   354,   631,   300,  -364,   380,
      39,  -364,   523,   523,     9,     9,     9,     9,  -364,   286,
     300,   390,   393,   918,   -24,   279,   -11,   285,   411,   128,
     941,    74,   106,   300,   300,  -364,  -364,   739,   941,   941,
     941,   941,    11,  -364,   -13,   394,   396,   399,   215,    97,
    1154,  -364,  -364,   300,     9,   295,  1185,  1214,  1243,   300,
    -364,   125,   125,  1496,   605,   883,  1102,  1557,   498,   498,
     148,   148,   148,   148,   273,   273,   151,   151,  -364,  -364,
    -364,   103,  -364,   300,  -364,  1272,   279,  -364,  -364,  -364,
      94,  -364,  -364,  -364,   301,   302,   303,   304,   279,   279,
     305,   307,   311,   314,     9,  1301,  -364,  -364,  -364,   297,
    -364,  -364,  -364,  -364,  -364,  -364,   323,   125,   431,   125,
    -364,    73,  -364,   125,  -364,  1388,  -364,  -364,  -364,  -364,
    1513,   357,   605,  -364,  1513,   357,   605,  -364,  -364,   350,
    -364,   331,   330,  -364,  -364,     2,  -364,   442,  -364,  1461,
     110,   338,   337,  -364,  -364,  -364,  -364,  1088,   339,   341,
    -364,  -364,   344,  -364,   739,   840,   300,   347,  -364,  -364,
     343,   348,  -364,  -364,  -364,  -364,  -364,   397,  -364,   300,
     377,  -364,   360,   125,   125,   379,   300,   467,    71,  -364,
    -364,  -364,  -364,   361,   205,   466,    71,   367,   300,  -364,
    -364,  -364,    79,  -364,  -364,  -364,  -364,  -364,   739,  1330,
    -364,  -364,  -364,   368,  -364,   369,   373,   425,   451,  -364,
    -364,  -364,   300,  1359,    -4,  -364,  -364,  -364,  -364,   408,
     375,    -1,   371,   378,  -364,   400,   941,  -364,   119,    71,
     485,   381,  -364,  -364,   386,   382,  -364,   387,  -364,   119,
    -364,   420,  -364,   409,   494,  -364
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -364,  -364,  -364,  -364,  1037,   444,  -364,   476,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,    27,
    -364,   -15,   -86,   253,  -364,  -364,   257,  -364,  -364,     4,
    -243,  -364,   178,   -76,  -364,  -364,  -364,     1,   -54,   421,
     358,  -218,  -364,   123,   -98,  -364,  -154,  -364,  -364,    92,
    -363,  -109,  -364,  -116,  -364,  -364,    35,  -221,  -364,   260,
    -224,  -364,  -245,  -364
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -143
static const yytype_int16 yytable[] =
{
      51,    38,   149,   228,    37,   175,   314,   344,   313,   410,
     169,   225,   244,   105,   358,    41,     2,   106,     1,    42,
      38,   360,     2,  -142,  -142,  -142,   177,    35,    37,   347,
     347,   178,   179,    11,    12,    13,   378,   379,   146,   349,
     191,   192,   316,   245,    41,   437,     2,   260,   261,   226,
     137,    35,   371,   441,    43,    38,   260,   261,   380,    37,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,   335,   170,   381,
      48,     2,    35,   359,   328,   343,    80,   180,   265,   181,
      81,   329,   400,   266,   402,   -90,   466,   336,   405,   273,
      84,   274,  -142,    44,     2,   282,    85,   214,   411,   335,
      18,    49,   107,     2,    86,   412,    18,    87,    88,    89,
      52,    90,    19,   462,   271,   239,   308,   463,   335,   336,
     137,    45,     2,   100,    46,    54,   306,    56,    91,    92,
      18,   334,   351,   353,   355,   357,   318,   319,   336,    11,
      12,    13,   383,    58,   250,   251,   444,   253,   432,   433,
      77,    78,   424,   337,   390,   391,   313,    59,   338,    82,
     250,   251,   252,   253,   254,    18,    93,   255,   256,   403,
     404,   339,   435,   281,   275,   186,   187,   188,   103,   190,
     101,    94,   366,   255,   256,   343,   216,    95,    18,    96,
     338,   126,   127,    41,    97,   102,   367,    18,   384,   104,
     445,   145,     2,   339,   168,   282,    73,    74,    75,   338,
     243,   453,   169,   137,   414,   415,    18,   137,   212,   183,
     312,   317,   339,   137,   137,   320,   321,   322,   323,   204,
     205,   206,   207,   208,   209,   210,   208,   209,   210,   137,
     184,   185,   340,   340,   189,   213,   219,   221,   137,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   214,   270,
      71,    72,    73,    74,    75,   372,   276,   277,   220,   222,
     227,   278,   340,   340,   231,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,    84,   229,   214,   230,     2,   232,    85,
     233,   234,   246,   305,   241,   242,   235,    86,   236,   216,
      87,    88,    89,   237,    90,   239,   240,    67,    68,    69,
      70,   249,   325,    71,    72,    73,    74,    75,   340,   257,
     340,    91,    92,   264,   340,   345,   345,   461,   268,   267,
     350,   352,   354,   356,    71,    72,    73,    74,    75,   269,
     439,   369,   272,   281,   282,   216,   206,   207,   208,   209,
     210,   377,    65,    66,    67,    68,    69,    70,   301,    93,
      71,    72,    73,    74,    75,   137,   422,   302,   304,   309,
     307,   315,   324,   326,    94,   216,   327,   362,   330,   363,
      95,    18,    96,   373,   340,   340,   364,    97,   386,   385,
     398,   388,   389,   392,    84,   393,   108,   109,   110,   394,
      85,   111,   395,   112,   113,   114,     3,     4,    86,   137,
     399,    87,    88,    89,   401,    90,   457,   407,   261,   408,
     409,   115,   116,   117,   331,   413,   416,   417,   118,   419,
     119,   420,    91,    92,   421,   425,   426,    11,    12,    13,
     428,   427,   120,   121,   122,   123,   124,   430,   431,   434,
     436,   438,   125,   440,   442,   450,   447,   448,   216,   449,
     452,   455,   456,   458,   126,   127,   459,   460,   467,   468,
      93,   429,   469,   471,   473,   470,   474,   475,   216,   148,
      76,   332,   396,   176,   472,    94,   333,   263,   423,     0,
     443,    95,    18,    96,   348,     0,     0,     0,   128,     0,
       0,     0,     0,   129,     0,     0,    84,     0,   108,   109,
     110,     0,    85,   111,   216,   112,   113,   114,     3,     4,
      86,     0,     0,    87,    88,    89,     0,    90,     0,     0,
       0,     0,     0,   115,   116,   117,     0,     0,     0,     0,
     118,     0,   119,     0,    91,    92,     0,     0,     0,    11,
      12,    13,     0,     0,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,   125,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   126,   127,     0,     0,
       0,     0,    93,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    94,    71,    72,
      73,    74,    75,    95,    18,    96,     0,     0,     0,     0,
     128,     0,     0,   150,    84,   129,   108,   109,   310,     0,
      85,   111,     0,   112,   113,   114,     3,     4,    86,     0,
       0,    87,    88,    89,     0,    90,     0,     0,     0,     0,
       0,   115,   116,   117,     0,     0,     0,     0,   118,     0,
     119,     0,    91,    92,     0,     0,     0,    11,    12,    13,
       0,     0,   120,   121,   122,   123,   311,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   262,   126,   127,     0,     0,     0,     0,
      93,     0,     0,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    94,    71,    72,    73,    74,
      75,    95,    18,    96,     0,     0,     0,     0,   128,     0,
       0,     0,    84,   129,   108,   109,   310,   279,    85,   111,
       0,   112,   113,   114,     3,     4,    86,     0,     0,    87,
      88,    89,     0,    90,     0,     0,     0,     0,     0,   115,
     116,   117,     0,     0,     0,     0,   118,     0,   119,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   126,   127,     0,     0,     0,     0,    93,     0,
       0,     0,   280,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    94,    71,    72,    73,    74,    75,    95,
      18,    96,     0,    84,     0,     0,   128,     2,     0,    85,
     111,   129,   112,   113,   114,     3,     4,    86,     0,     0,
      87,    88,    89,     0,    90,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,   118,     0,   119,
       0,    91,    92,     1,   -79,     0,     0,     2,   -79,     0,
       0,   120,   121,   122,   123,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     0,     7,     0,     8,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    10,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    94,     0,    14,    15,    16,     0,
      95,    18,    96,     0,    84,     0,     0,   128,     2,    17,
      85,   279,   129,     0,     0,     0,     0,     0,    86,     0,
       0,    87,    88,    89,     0,    90,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    18,    91,    92,     0,     0,     0,    19,     0,     0,
       0,     0,   120,   121,   122,   123,     0,     0,   258,   259,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,    94,   -28,     0,     0,     0,
     -79,    95,    18,    96,   -79,     0,     0,     0,   128,     0,
       0,     3,     4,     0,     5,     6,    57,     0,     0,     0,
       0,     7,     0,     8,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
       0,   147,    14,    15,    16,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   -79,     0,     0,     0,   -79,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     6,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    14,    15,    16,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       0,     0,   418,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   375,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   446,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   454,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   406,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   258,   259,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,    71,    72,    73,    74,    75,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   259,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    71,    72,    73,    74,    75,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    71,    72,    73,
      74,    75,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210
};

static const yytype_int16 yycheck[] =
{
      15,     0,    56,   112,     0,    81,   227,   252,   226,     7,
       7,   109,   128,     3,     3,   109,     7,     7,     3,    11,
      19,   264,     7,    34,    35,    36,   109,     0,    24,   253,
     254,   114,   115,    46,    47,    48,   281,   282,    53,   257,
      76,    77,     3,   129,   109,   408,     7,    80,    81,   114,
      49,    24,   273,   416,    11,    54,    80,    81,   301,    55,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     3,    75,   303,
     109,     7,    55,    72,   108,    89,     4,     7,   109,     9,
       8,   245,   337,   114,   339,   108,   459,    23,   343,   107,
       3,   109,   113,     7,     7,   109,     9,   103,   106,     3,
     101,   112,   102,     7,    17,   113,   101,    20,    21,    22,
      49,    24,   107,     4,   178,   124,   224,     8,     3,    23,
     129,     7,     7,    41,    10,    68,   222,   111,    41,    42,
     101,   250,   258,   259,   260,   261,   232,   233,    23,    46,
      47,    48,   306,     0,    75,    76,    77,    78,   403,   404,
      44,    45,   386,    89,   318,   319,   384,   106,    94,   111,
      75,    76,    77,    78,    79,   101,    79,    98,    99,   106,
     107,   107,   406,   109,   183,    93,    94,    95,   112,    97,
      11,    94,   268,    98,    99,    89,   104,   100,   101,   102,
      94,    73,    74,   109,   107,    11,   109,   101,   114,   107,
     428,     3,     7,   107,     7,   109,    95,    96,    97,    94,
     128,   442,     7,   222,   114,   115,   101,   226,    11,   107,
     226,   230,   107,   232,   233,   234,   235,   236,   237,    91,
      92,    93,    94,    95,    96,    97,    95,    96,    97,   248,
     107,   107,   251,   252,   107,    11,   110,   107,   257,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   264,   177,
      93,    94,    95,    96,    97,   274,   184,   185,   110,    36,
     107,   189,   281,   282,     7,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     3,   107,   301,   107,     7,   112,     9,
     112,   107,    33,   221,    93,    93,   107,    17,   107,   227,
      20,    21,    22,   107,    24,   324,   107,    87,    88,    89,
      90,   106,   240,    93,    94,    95,    96,    97,   337,    40,
     339,    41,    42,   107,   343,   253,   254,   456,   106,   112,
     258,   259,   260,   261,    93,    94,    95,    96,    97,    75,
     414,   269,     7,   109,   109,   273,    93,    94,    95,    96,
      97,   279,    85,    86,    87,    88,    89,    90,    33,    79,
      93,    94,    95,    96,    97,   384,   385,   113,   108,    35,
      34,    11,   106,     3,    94,   303,     3,     3,   113,     3,
     100,   101,   102,   108,   403,   404,     7,   107,   106,   108,
     113,   108,   108,   108,     3,   108,     5,     6,     7,   108,
       9,    10,   108,    12,    13,    14,    15,    16,    17,   428,
     107,    20,    21,    22,     3,    24,   451,    87,    81,   108,
     110,    30,    31,    32,    33,     3,   108,   110,    37,   110,
      39,   110,    41,    42,   110,   108,   113,    46,    47,    48,
      63,   113,    51,    52,    53,    54,    55,    90,   108,    90,
       3,   110,    61,     7,   107,    50,   108,   108,   386,   106,
      29,    73,   107,   112,    73,    74,   108,    87,     3,   108,
      79,   399,   106,   106,    74,   113,    87,     3,   406,    55,
      24,   248,   324,    82,   469,    94,   249,   149,   385,    -1,
     418,   100,   101,   102,   254,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,     3,    -1,     5,     6,
       7,    -1,     9,    10,   442,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    73,    74,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    94,    93,    94,
      95,    96,    97,   100,   101,   102,    -1,    -1,    -1,    -1,
     107,    -1,    -1,   108,     3,   112,     5,     6,     7,    -1,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    52,    53,    54,    55,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    70,    73,    74,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    94,    93,    94,    95,    96,
      97,   100,   101,   102,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,     3,   112,     5,     6,     7,    33,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    73,    74,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,   108,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    94,    93,    94,    95,    96,    97,   100,
     101,   102,    -1,     3,    -1,    -1,   107,     7,    -1,     9,
      10,   112,    12,    13,    14,    15,    16,    17,    -1,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    42,     3,     4,    -1,    -1,     7,     8,    -1,
      -1,    51,    52,    53,    54,    15,    16,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    56,    57,    58,    -1,
     100,   101,   102,    -1,     3,    -1,    -1,   107,     7,    69,
       9,    33,   112,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   101,    41,    42,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,     0,    -1,    -1,    -1,
       4,   100,   101,   102,     8,    -1,    -1,    -1,   107,    -1,
      -1,    15,    16,    -1,    18,    19,    19,    -1,    -1,    -1,
      -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    56,    57,    58,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     4,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   114,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    80,    81,    82,    83,    84,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    96,    97,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    96,    97,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      96,    97,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    15,    16,    18,    19,    25,    27,    33,
      43,    46,    47,    48,    56,    57,    58,    69,   101,   107,
     117,   119,   120,   121,   122,   123,   124,   126,   127,   128,
     129,   130,   132,   133,   134,   135,   143,   145,   153,   154,
     155,   109,    11,    11,     7,     7,    10,   131,   109,   112,
     137,   137,    49,   166,    68,   118,   111,   120,     0,   106,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    94,    95,    96,    97,   123,    44,    45,   125,
       4,     8,   111,   156,     3,     9,    17,    20,    21,    22,
      24,    41,    42,    79,    94,   100,   102,   107,   136,   153,
     165,    11,    11,   112,   107,     3,     7,   102,     5,     6,
       7,    10,    12,    13,    14,    30,    31,    32,    37,    39,
      51,    52,    53,    54,    55,    61,    73,    74,   107,   112,
     135,   138,   139,   140,   141,   142,   145,   153,   157,   158,
     159,   165,   167,   169,   170,     3,   137,   120,   121,   154,
     108,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,     7,     7,
      75,   144,   149,   150,   152,   149,   155,   109,   114,   115,
       7,     9,   164,   107,   107,   107,   165,   165,   165,   107,
     165,    76,    77,    80,    81,    82,    83,    84,    85,    86,
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
     113,    33,   139,   142,   167,     3,    23,    89,    94,   107,
     153,   177,   178,    89,   178,   165,   175,   176,   175,   157,
     165,   169,   165,   169,   165,   169,   165,   169,     3,    72,
     146,   147,     3,     3,     7,   179,   149,   109,   151,   165,
     110,   173,   153,   108,   108,   108,   108,   165,   178,   178,
     146,   176,   108,   162,   114,   108,   106,   174,   108,   108,
     162,   162,   108,   108,   108,   108,   148,   108,   113,   107,
     178,     3,   178,   106,   107,   178,   107,    87,   108,   110,
       7,   106,   113,     3,   114,   115,   108,   110,   114,   110,
     110,   110,   153,   159,   176,   108,   113,   113,    63,   165,
      90,   108,   178,   178,    90,   176,     3,   166,   110,   154,
       7,   166,   107,   165,    77,   157,   108,   108,   108,   106,
      50,   168,    29,   173,   108,    73,   107,   137,   112,   108,
      87,   167,     4,     8,   171,   172,   166,     3,   108,   106,
     113,   106,   172,    74,    87,     3
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
      yyerror (globalSymTab, mtypes, property, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, yylval, globalSymTab)
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
		  Type, Value, globalSymTab, mtypes, property); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, globalSymTab, mtypes, property)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct symTabNode_* * globalSymTab;
    struct mTypeNode_* * mtypes;
    void ** property;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (globalSymTab);
  YYUSE (mtypes);
  YYUSE (property);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, globalSymTab, mtypes, property)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct symTabNode_* * globalSymTab;
    struct mTypeNode_* * mtypes;
    void ** property;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, globalSymTab, mtypes, property);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
#else
static void
yy_reduce_print (yyvsp, yyrule, globalSymTab, mtypes, property)
    YYSTYPE *yyvsp;
    int yyrule;
    struct symTabNode_* * globalSymTab;
    struct mTypeNode_* * mtypes;
    void ** property;
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
		       		       , globalSymTab, mtypes, property);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, globalSymTab, mtypes, property); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, globalSymTab, mtypes, property)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    struct symTabNode_* * globalSymTab;
    struct mTypeNode_* * mtypes;
    void ** property;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (globalSymTab);
  YYUSE (mtypes);
  YYUSE (property);

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
int yyparse (struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






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
yyparse (struct symTabNode_* * globalSymTab, struct mTypeNode_* * mtypes, void ** property)
#else
int
yyparse (globalSymTab, mtypes, property)
    struct symTabNode_* * globalSymTab;
    struct mTypeNode_* * mtypes;
    void ** property;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

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
        case 3:
#line 100 "promela.y"
    { if(property) *property = (yyvsp[(1) - (1)].pList);}
    break;

  case 4:
#line 101 "promela.y"
    { if(property) *property = (yyvsp[(2) - (3)].pCostFormula);}
    break;

  case 5:
#line 104 "promela.y"
    { (yyval.pCostFormula) = createCostFormula((yyvsp[(2) - (4)].pExpVal), (yyvsp[(4) - (4)].iVal), INT_MAX, INT_MAX);}
    break;

  case 6:
#line 105 "promela.y"
    { (yyval.pCostFormula) = createCostFormula((yyvsp[(2) - (14)].pExpVal), (yyvsp[(6) - (14)].iVal), (yyvsp[(10) - (14)].iVal), (yyvsp[(14) - (14)].iVal)); }
    break;

  case 7:
#line 108 "promela.y"
    { (yyval.pList) = listAdd(NULL,(yyvsp[(1) - (1)].pExpVal)); }
    break;

  case 8:
#line 109 "promela.y"
    { (yyval.pList) = listAdd((yyvsp[(1) - (3)].pList),(yyvsp[(3) - (3)].pExpVal)); }
    break;

  case 9:
#line 112 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[(2) - (3)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 10:
#line 113 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 11:
#line 114 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 12:
#line 115 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 13:
#line 116 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 14:
#line 117 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 15:
#line 118 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 16:
#line 119 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 17:
#line 120 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 18:
#line 121 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 19:
#line 122 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 20:
#line 123 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 21:
#line 124 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 22:
#line 125 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 23:
#line 126 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 24:
#line 127 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 25:
#line 128 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 26:
#line 129 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 27:
#line 130 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[(1) - (1)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 34:
#line 167 "promela.y"
    { yyerror("The 'events' construct is currently not supported."); }
    break;

  case 35:
#line 168 "promela.y"
    { if((yyvsp[(1) - (1)].pSymTabNodeVal) != NULL) *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[(1) - (1)].pSymTabNodeVal)); }
    break;

  case 36:
#line 169 "promela.y"
    { *globalSymTab = addToSymTab(*globalSymTab, (yyvsp[(1) - (1)].pSymTabNodeVal)); }
    break;

  case 37:
#line 170 "promela.y"
    { yyerror("Embedded C code is not supported."); }
    break;

  case 38:
#line 171 "promela.y"
    { yyerror("The 'named sequence' construct is currently not supported."); }
    break;

  case 40:
#line 181 "promela.y"
    {	(yyvsp[(9) - (9)].pFsmVal)->symTab = addToSymTab((yyvsp[(5) - (9)].pSymTabNodeVal), (yyvsp[(9) - (9)].pFsmVal)->symTab);
			  										*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, (yyvsp[(3) - (9)].sVal), nbrLines, 0, 0, (yyvsp[(1) - (9)].pExpVal), (yyvsp[(9) - (9)].pFsmVal), NULL));
												}
    break;

  case 42:
#line 187 "promela.y"
    { yyerror("Deterministic proctypes are not supported (only useful for simulation)."); }
    break;

  case 43:
#line 190 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 44:
#line 191 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, 1, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 45:
#line 192 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, (yyvsp[(3) - (4)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 46:
#line 193 "promela.y"
    {	ptSymTabNode var = lookupInSymTab(*globalSymTab, (yyvsp[(3) - (4)].sVal));
													if(var == NULL) yyserror("The variable %s does not exist.", (yyvsp[(3) - (4)].sVal));
													else if(var->type != T_INT && var->type != T_BIT && var->type != T_SHORT) yyserror("The variable %s is not of type int, short or bit.", (yyvsp[(3) - (4)].sVal));
													else if(var->init == NULL || var->init->type != E_EXPR_CONST) yyserror("The variable %s does not have a constant value.", (yyvsp[(3) - (4)].sVal));
													else {
														(yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL, var->init->iVal, NULL, NULL, NULL, nbrLines, NULL, NULL);
													}
													free((yyvsp[(3) - (4)].sVal));
												}
    break;

  case 47:
#line 202 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[(5) - (7)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); 
#if !defined(Z3) && !defined(MULTI)
                                         		  failure("Feature clones are not allowed in this variant of SNIP.\n");
#endif
												}
    break;

  case 48:
#line 209 "promela.y"
    {	if(lookupInSymTab(*globalSymTab, "init") != NULL) yyerror("This is the second init process; only one is allowed.");
													else {
														*globalSymTab = addToSymTab(*globalSymTab, createSymTabNode(T_PROC, "init", nbrLines, 1, 0, NULL, (yyvsp[(3) - (3)].pFsmVal), NULL));
													}

												}
    break;

  case 49:
#line 217 "promela.y"
    { 	if(neverClaim != NULL) yyerror("Found a second never claim.  Only one claim at a time is allowed.");
													else {
														neverClaim = createSymTabNode(T_NEVER, "__never", nbrLines, 1, 0, NULL, (yyvsp[(2) - (2)].pFsmVal), NULL);
														*globalSymTab = addToSymTab(*globalSymTab, neverClaim);
													}
												}
    break;

  case 50:
#line 225 "promela.y"
    { yyerror("Event sequences (traces) are not supported."); }
    break;

  case 51:
#line 228 "promela.y"
    {	(yyval.pSymTabNodeVal) = createSymTabNode(T_TDEF, (yyvsp[(2) - (5)].sVal), nbrLines, 1, 0, NULL, NULL, (yyvsp[(4) - (5)].pSymTabNodeVal));
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
    break;

  case 64:
#line 282 "promela.y"
    { (yyval.pFsmVal) = (yyvsp[(2) - (4)].pFsmVal); }
    break;

  case 65:
#line 285 "promela.y"
    { 	(yyval.pFsmVal) = createFsm();
													if((yyvsp[(1) - (1)].pExpVal)->type == E_DECL) {
														(yyval.pFsmVal)->symTab = (yyvsp[(1) - (1)].pExpVal)->symTab;
														(yyvsp[(1) - (1)].pExpVal)->symTab = NULL;
														destroyExpNode((yyvsp[(1) - (1)].pExpVal));
													} else if((yyvsp[(1) - (1)].pExpVal)->type == E_STMNT) {
														(yyval.pFsmVal) = stmnt2fsm((yyval.pFsmVal), (yyvsp[(1) - (1)].pExpVal)->children[0], *globalSymTab);
														(yyvsp[(1) - (1)].pExpVal)->children[0] = NULL;
														destroyExpNode((yyvsp[(1) - (1)].pExpVal));
													}
												}
    break;

  case 66:
#line 296 "promela.y"
    {	if((yyvsp[(3) - (3)].pExpVal)->type == E_DECL) {
														(yyval.pFsmVal) = (yyvsp[(1) - (3)].pFsmVal);
														(yyval.pFsmVal)->symTab = addToSymTab((yyval.pFsmVal)->symTab, (yyvsp[(3) - (3)].pExpVal)->symTab);
														(yyvsp[(3) - (3)].pExpVal)->symTab = NULL;
														destroyExpNode((yyvsp[(3) - (3)].pExpVal));
													} else if((yyvsp[(3) - (3)].pExpVal)->type == E_STMNT) {
														(yyval.pFsmVal) = stmnt2fsm((yyvsp[(1) - (3)].pFsmVal), (yyvsp[(3) - (3)].pExpVal)->children[0], *globalSymTab);
														(yyvsp[(3) - (3)].pExpVal)->children[0] = NULL;
														destroyExpNode((yyvsp[(3) - (3)].pExpVal));
													}
												}
    break;

  case 67:
#line 309 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_DECL, NULL, 0, NULL, NULL, NULL, nbrLines, NULL, (yyvsp[(1) - (1)].pSymTabNodeVal)); }
    break;

  case 68:
#line 310 "promela.y"
    { yyerror("Channel assertions are currently not supported."); }
    break;

  case 69:
#line 311 "promela.y"
    { yyerror("Declarations with labels are not suported."); }
    break;

  case 70:
#line 312 "promela.y"
    { yyerror("Channel assertions are currently not supported."); }
    break;

  case 71:
#line 313 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 72:
#line 314 "promela.y"
    { yyerror("Unless statements are currently not supported."); }
    break;

  case 73:
#line 315 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT, NULL, 0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 74:
#line 318 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_WHEN, NULL, 0, (yyvsp[(3) - (6)].pExpVal), (yyvsp[(6) - (6)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 75:
#line 321 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 76:
#line 322 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_NF, NULL, 0, (yyvsp[(1) - (3)].pExpVal), (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 77:
#line 325 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_COST, NULL, (yyvsp[(3) - (3)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 78:
#line 326 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_QUALITY, NULL, (yyvsp[(3) - (3)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 80:
#line 330 "promela.y"
    { yyerror("The 'hidden' keyword is not supported."); }
    break;

  case 81:
#line 331 "promela.y"
    { yyerror("The 'show' keyword is not supported."); }
    break;

  case 82:
#line 332 "promela.y"
    { yyerror("The 'local' keyword is not supported."); }
    break;

  case 85:
#line 342 "promela.y"
    {	ptSymTabNode cur = (yyvsp[(3) - (3)].pSymTabNodeVal);
													while(cur != NULL) {
														// If type != 0, then the var is a T_CHAN
														if(cur->type == 0) cur->type = (yyvsp[(2) - (3)].iVal);
														if(cur->type == T_CLOCK) {
															yyerror("Clocks can only be declared when the CLOCK option is enabled.");
														}
														cur = cur->next;
													}
													(yyval.pSymTabNodeVal) = (yyvsp[(3) - (3)].pSymTabNodeVal);
												}
    break;

  case 86:
#line 353 "promela.y"
    {	ptSymTabNode type = lookupInSymTab(*globalSymTab, (yyvsp[(2) - (3)].sVal));
	 												if(type == NULL) yyserror("The type %s was not declared in a typedef.", (yyvsp[(2) - (3)].sVal));
													else {
														ptSymTabNode cur = (yyvsp[(3) - (3)].pSymTabNodeVal);
														while(cur != NULL) {
															cur->type = T_UTYPE;
															cur->utype = type;
															cur = cur->next;
														}
														(yyval.pSymTabNodeVal) = (yyvsp[(3) - (3)].pSymTabNodeVal);
													}
	 												free((yyvsp[(2) - (3)].sVal));
												}
    break;

  case 87:
#line 366 "promela.y"
    {	if((yyvsp[(2) - (6)].iVal) != T_MTYPE) yyerror("This syntax only works for MTYPEs.");
													(yyval.pSymTabNodeVal) = NULL;
													/* The mtype values are added in the nlst rule. */ 
												}
    break;

  case 88:
#line 372 "promela.y"
    { (yyval.pSymTabNodeVal) = (yyvsp[(1) - (1)].pSymTabNodeVal); }
    break;

  case 89:
#line 373 "promela.y"
    { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[(1) - (3)].pSymTabNodeVal), (yyvsp[(3) - (3)].pSymTabNodeVal)); }
    break;

  case 90:
#line 377 "promela.y"
    { (yyval.pSymTabNodeVal) = NULL; }
    break;

  case 91:
#line 378 "promela.y"
    { (yyval.pSymTabNodeVal) = (yyvsp[(1) - (1)].pSymTabNodeVal); }
    break;

  case 94:
#line 385 "promela.y"
    { (yyval.pSymTabNodeVal) = (yyvsp[(1) - (1)].pSymTabNodeVal); }
    break;

  case 95:
#line 386 "promela.y"
    { (yyval.pSymTabNodeVal) = addToSymTab((yyvsp[(1) - (3)].pSymTabNodeVal), (yyvsp[(3) - (3)].pSymTabNodeVal)); }
    break;

  case 96:
#line 389 "promela.y"
    { (yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[(1) - (1)].pDataVal).sVal, nbrLines, (yyvsp[(1) - (1)].pDataVal).iVal,		  0, NULL, NULL, NULL); }
    break;

  case 97:
#line 390 "promela.y"
    { 	int mtype;
													if((yyvsp[(3) - (3)].pExpVal)->type == E_EXPR_VAR && (mtype = getMTypeValue(*mtypes, (yyvsp[(3) - (3)].pExpVal)->children[0]->children[0]->sVal)) != -1) {
														(yyvsp[(3) - (3)].pExpVal)->type = E_EXPR_CONST;
														(yyvsp[(3) - (3)].pExpVal)->iVal = mtype;
														destroyExpNode((yyvsp[(3) - (3)].pExpVal)->children[0]);
													}
													(yyval.pSymTabNodeVal) = createSymTabNode(	 0, (yyvsp[(1) - (3)].pDataVal).sVal, nbrLines, (yyvsp[(1) - (3)].pDataVal).iVal,	 	  0,   (yyvsp[(3) - (3)].pExpVal), NULL, NULL);
												}
    break;

  case 98:
#line 398 "promela.y"
    { (yyval.pSymTabNodeVal) = createSymTabNode(T_CHAN, (yyvsp[(1) - (3)].pDataVal).sVal, nbrLines, (yyvsp[(1) - (3)].pDataVal).iVal, (yyvsp[(3) - (3)].pDataVal).iVal, NULL, NULL, (yyvsp[(3) - (3)].pDataVal).symTabNodeVal); }
    break;

  case 99:
#line 401 "promela.y"
    { (yyval.pDataVal).iVal = (yyvsp[(2) - (7)].iVal); (yyval.pDataVal).symTabNodeVal = (yyvsp[(6) - (7)].pSymTabNodeVal); }
    break;

  case 100:
#line 404 "promela.y"
    { (yyval.pDataVal).sVal = (yyvsp[(1) - (1)].sVal); (yyval.pDataVal).iVal = 1; }
    break;

  case 101:
#line 405 "promela.y"
    { yyerror("The 'unsigned' data type is not supported."); }
    break;

  case 102:
#line 406 "promela.y"
    { (yyval.pDataVal).sVal = (yyvsp[(1) - (4)].sVal); (yyval.pDataVal).iVal = (yyvsp[(3) - (4)].iVal); }
    break;

  case 103:
#line 409 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 104:
#line 412 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_VARREF_NAME, (yyvsp[(1) - (1)].sVal), 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 105:
#line 413 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_VARREF_NAME,	(yyvsp[(1) - (4)].sVal), 0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 106:
#line 416 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 0,   (yyvsp[(1) - (2)].pExpVal),   (yyvsp[(2) - (2)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 107:
#line 417 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_VARREF, 	  NULL, 1,   (yyvsp[(3) - (4)].pExpVal),   (yyvsp[(4) - (4)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 108:
#line 420 "promela.y"
    { (yyval.pExpVal) = NULL; }
    break;

  case 109:
#line 421 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(2) - (2)].pExpVal);   }
    break;

  case 110:
#line 424 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 111:
#line 425 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 112:
#line 428 "promela.y"
    { 
													(yyval.pExpVal) = createExpNode(E_STMNT_CHAN_RCV, 	NULL, 	0,   (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); 
												}
    break;

  case 113:
#line 431 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_CHAN_SND, 	NULL, 	0,   (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 114:
#line 432 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_IF, 		NULL, 	0,   (yyvsp[(2) - (3)].pExpVal), NULL, NULL,       (yyvsp[(1) - (3)].iVal), NULL, NULL); }
    break;

  case 115:
#line 433 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_DO, 		NULL, 	0,   (yyvsp[(2) - (3)].pExpVal), NULL, NULL,       (yyvsp[(1) - (3)].iVal), NULL, NULL); }
    break;

  case 116:
#line 434 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_BREAK, 	NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 117:
#line 435 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_GOTO, 		(yyvsp[(2) - (2)].sVal), 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 118:
#line 436 "promela.y"
    { if((yyvsp[(3) - (3)].pExpVal)->type == E_STMNT_LABEL && (yyvsp[(3) - (3)].pExpVal)->children[0] && (yyvsp[(3) - (3)].pExpVal)->children[0]->type == E_STMNT_LABEL) yyerror("Only two labels per state are supported."); 
												  (yyval.pExpVal) = createExpNode(E_STMNT_LABEL,		(yyvsp[(1) - (3)].sVal), 	0,   (yyvsp[(3) - (3)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 119:
#line 438 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 120:
#line 441 "promela.y"
    {
													(yyval.pExpVal) = createExpNode(E_STMNT_ASGN, 		NULL, 	0,   (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL);
												}
    break;

  case 121:
#line 444 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_INCR, 		NULL, 	0,   (yyvsp[(1) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 122:
#line 445 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_DECR, 		NULL, 	0,   (yyvsp[(1) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 123:
#line 446 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_PRINT, 	(yyvsp[(3) - (5)].sVal), 	0,   (yyvsp[(4) - (5)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 124:
#line 447 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL, 	0,   (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 125:
#line 448 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_PRINTM, 	NULL,  (yyvsp[(3) - (4)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 126:
#line 449 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_ASSERT, 	NULL, 	0,   (yyvsp[(2) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 127:
#line 450 "promela.y"
    { yyerror("Embedded C code is not supported."); }
    break;

  case 128:
#line 451 "promela.y"
    { yyerror("Sorted send and random receive are not supported."); }
    break;

  case 129:
#line 452 "promela.y"
    { yyerror("Channel poll operations are not supported."); }
    break;

  case 130:
#line 453 "promela.y"
    { yyerror("Channel poll operations are not supported."); }
    break;

  case 131:
#line 454 "promela.y"
    { yyerror("Sorted send and random receive are not supported."); }
    break;

  case 132:
#line 455 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_EXPR, 		NULL, 	0,   (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 133:
#line 456 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_ELSE, 		NULL, 	0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 134:
#line 457 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_ATOMIC,	NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[(3) - (5)].pFsmVal), NULL); }
    break;

  case 135:
#line 458 "promela.y"
    { yyerror("Deterministic steps are not yet supported."); }
    break;

  case 136:
#line 459 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_SEQ, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[(2) - (4)].pFsmVal), NULL); }
    break;

  case 137:
#line 460 "promela.y"
    { yyerror("Inline calls are not yet supported."); }
    break;

  case 138:
#line 463 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0, NULL, NULL, NULL, nbrLines,   (yyvsp[(1) - (1)].pFsmVal), NULL); }
    break;

  case 139:
#line 464 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_STMNT_OPT, 		NULL, 	0,   (yyvsp[(2) - (2)].pExpVal), NULL, NULL, nbrLines,   (yyvsp[(1) - (2)].pFsmVal), NULL); }
    break;

  case 140:
#line 467 "promela.y"
    { (yyval.pFsmVal) = (yyvsp[(2) - (3)].pFsmVal); }
    break;

  case 142:
#line 471 "promela.y"
    { /* redundant semi at end of sequence */ }
    break;

  case 143:
#line 474 "promela.y"
    { /* at least one semi-colon */ }
    break;

  case 144:
#line 475 "promela.y"
    { /* but more are okay too   */ }
    break;

  case 145:
#line 478 "promela.y"
    { (yyval.sVal) = (yyvsp[(1) - (1)].sVal); }
    break;

  case 146:
#line 479 "promela.y"
    { (yyval.sVal) = (yyvsp[(1) - (1)].sVal); }
    break;

  case 147:
#line 482 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[(2) - (3)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 148:
#line 483 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_PLUS, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 149:
#line 484 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_MINUS, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 150:
#line 485 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_TIMES, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 151:
#line 486 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_DIV, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 152:
#line 487 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_MOD, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 153:
#line 488 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWAND,NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 154:
#line 489 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWXOR,NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 155:
#line 490 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWOR,	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 156:
#line 491 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_GT, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 157:
#line 492 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LT, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 158:
#line 493 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_GE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 159:
#line 494 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 160:
#line 495 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_EQ, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 161:
#line 496 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_NE, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 162:
#line 497 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 163:
#line 498 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 164:
#line 499 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LSHIFT,	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 165:
#line 500 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_RSHIFT,	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 166:
#line 501 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_COUNT,  NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 167:
#line 502 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_BITWNEG,NULL, 	0, (yyvsp[(2) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 168:
#line 503 "promela.y"
    { 	if((yyvsp[(2) - (2)].pExpVal)->type != E_EXPR_CONST) (yyval.pExpVal) = createExpNode(E_EXPR_UMIN,	NULL, 	0, (yyvsp[(2) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL);
													else {
														(yyvsp[(2) - (2)].pExpVal)->iVal = - (yyvsp[(2) - (2)].pExpVal)->iVal;
														(yyval.pExpVal) = (yyvsp[(2) - (2)].pExpVal);
													}
												}
    break;

  case 169:
#line 509 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_NEG, 	NULL, 	0, (yyvsp[(2) - (2)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 170:
#line 510 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_COND, 	NULL, 	0, (yyvsp[(2) - (7)].pExpVal),   (yyvsp[(4) - (7)].pExpVal),   (yyvsp[(6) - (7)].pExpVal), nbrLines, NULL, NULL); }
    break;

  case 171:
#line 511 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[(2) - (6)].sVal),   0, (yyvsp[(4) - (6)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 172:
#line 513 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_RUN, 	  (yyvsp[(2) - (9)].sVal),   0, (yyvsp[(7) - (9)].pExpVal), (yyvsp[(4) - (9)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 173:
#line 514 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_LEN, 	NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 174:
#line 515 "promela.y"
    { yyerror("The enabled keyword is not supported."); }
    break;

  case 175:
#line 516 "promela.y"
    { yyerror("Construct not supported."); /* Unclear */ }
    break;

  case 176:
#line 517 "promela.y"
    { yyerror("Sorted send and random receive are not supported."); }
    break;

  case 177:
#line 518 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_VAR, 	NULL, 	0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 178:
#line 519 "promela.y"
    { yyerror("Embedded C code is not supported."); }
    break;

  case 179:
#line 520 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_CONST,  NULL,(yyvsp[(1) - (1)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 180:
#line 521 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_TIMEOUT,NULL, 0, NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 181:
#line 522 "promela.y"
    { yyerror("The 'np_' variable is not supported."); }
    break;

  case 182:
#line 523 "promela.y"
    { yyerror("The 'pc_value()' construct is not supported."); }
    break;

  case 183:
#line 524 "promela.y"
    { yyerror("Construct not supported."); /* Unclear */ }
    break;

  case 184:
#line 525 "promela.y"
    { yyerror("Construct not supported."); /* Unclear */ }
    break;

  case 185:
#line 526 "promela.y"
    { yyerror("Construct not supported."); /* Unclear */ }
    break;

  case 186:
#line 527 "promela.y"
    { yyerror("Construct not supported."); /* Unclear */ }
    break;

  case 188:
#line 531 "promela.y"
    { yyerror("The 'priority' construct is related to simulation and not supported."); }
    break;

  case 189:
#line 534 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 190:
#line 535 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 192:
#line 539 "promela.y"
    { yyerror("The 'provided' construct is currently not supported."); }
    break;

  case 193:
#line 544 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 194:
#line 545 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_PAR, 	NULL, 	0, (yyvsp[(2) - (3)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 195:
#line 546 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 196:
#line 547 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 197:
#line 548 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 198:
#line 549 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 199:
#line 550 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_AND, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 200:
#line 551 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_OR, 	NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 201:
#line 553 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_FULL, 	NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 202:
#line 554 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_NFULL, 	NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 203:
#line 555 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_EMPTY, 	NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 204:
#line 556 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_EXPR_NEMPTY,	NULL, 	0, (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 205:
#line 559 "promela.y"
    { (yyval.pDataVal).sVal = NULL; (yyval.pDataVal).iVal = (yyvsp[(1) - (1)].iVal); }
    break;

  case 206:
#line 560 "promela.y"
    { (yyval.pDataVal).sVal = (yyvsp[(1) - (1)].sVal);   (yyval.pDataVal).iVal = -1; }
    break;

  case 207:
#line 564 "promela.y"
    {	if((yyvsp[(1) - (1)].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = createSymTabNode((yyvsp[(1) - (1)].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
													} else {
														(yyval.pSymTabNodeVal) = createSymTabNodeUType(*globalSymTab, (yyvsp[(1) - (1)].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if((yyval.pSymTabNodeVal) == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[(1) - (1)].pDataVal).sVal);
														free((yyvsp[(1) - (1)].pDataVal).sVal);
													}
												}
    break;

  case 208:
#line 572 "promela.y"
    {	if((yyvsp[(1) - (3)].pDataVal).iVal > -1) {
														(yyval.pSymTabNodeVal) = addToSymTab(createSymTabNode((yyvsp[(1) - (3)].pDataVal).iVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL), (yyvsp[(3) - (3)].pSymTabNodeVal));
													} else {
														ptSymTabNode temp = createSymTabNodeUType(*globalSymTab, (yyvsp[(1) - (3)].pDataVal).sVal, NULL, nbrLines, 1, 0, NULL, NULL, NULL);
														if(temp == NULL) yyerror("The type %s was not declared in a typedef.", (yyvsp[(1) - (3)].pDataVal).sVal);
														else (yyval.pSymTabNodeVal) = addToSymTab(temp, (yyvsp[(3) - (3)].pSymTabNodeVal));
														free((yyvsp[(1) - (3)].pDataVal).sVal);
													}
												}
    break;

  case 209:
#line 584 "promela.y"
    { (yyval.pExpVal) = NULL; }
    break;

  case 210:
#line 585 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 211:
#line 589 "promela.y"
    { (yyval.pExpVal) = NULL; }
    break;

  case 212:
#line 590 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(2) - (2)].pExpVal); }
    break;

  case 213:
#line 594 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(1) - (1)].pExpVal); }
    break;

  case 214:
#line 595 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (4)].pExpVal),   (yyvsp[(3) - (4)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 215:
#line 598 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 216:
#line 599 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 217:
#line 602 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_RARG_VAR,	NULL, 	0,   (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 218:
#line 603 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_RARG_EVAL,	NULL, 	0,   (yyvsp[(3) - (4)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 219:
#line 604 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL,  (yyvsp[(1) - (1)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 220:
#line 605 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_RARG_CONST,	NULL, -(yyvsp[(2) - (2)].iVal), NULL, NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 221:
#line 609 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (1)].pExpVal), NULL, NULL, nbrLines, NULL, NULL); }
    break;

  case 222:
#line 610 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (3)].pExpVal),   (yyvsp[(3) - (3)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 223:
#line 611 "promela.y"
    { (yyval.pExpVal) = createExpNode(E_ARGLIST,		NULL, 	0, (yyvsp[(1) - (4)].pExpVal),   (yyvsp[(3) - (4)].pExpVal), NULL, nbrLines, NULL, NULL); }
    break;

  case 224:
#line 612 "promela.y"
    { (yyval.pExpVal) = (yyvsp[(2) - (3)].pExpVal); }
    break;

  case 225:
#line 615 "promela.y"
    { *mtypes = addMType(*mtypes, (yyvsp[(1) - (1)].sVal)); }
    break;

  case 226:
#line 616 "promela.y"
    { *mtypes = addMType(*mtypes, (yyvsp[(2) - (2)].sVal)); }
    break;


/* Line 1267 of yacc.c.  */
#line 3344 "y.tab.c"
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
      yyerror (globalSymTab, mtypes, property, YY_("syntax error"));
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
	    yyerror (globalSymTab, mtypes, property, yymsg);
	  }
	else
	  {
	    yyerror (globalSymTab, mtypes, property, YY_("syntax error"));
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
		      yytoken, &yylval, globalSymTab, mtypes, property);
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
		  yystos[yystate], yyvsp, globalSymTab, mtypes, property);
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
  yyerror (globalSymTab, mtypes, property, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, globalSymTab, mtypes, property);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, globalSymTab, mtypes, property);
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


#line 619 "promela.y"



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

