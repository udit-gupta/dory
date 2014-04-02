/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "E--_parser.y++"


#include "Ast.h"
#include "ParserUtil.h"
#include "Error.h"

using namespace std;

extern int verbosity;
extern int yylex();
extern void yyerror(const char *s);
int offSet;
extern const OpNode::OpInfo opInfo[];



/* Line 268 of yacc.c  */
#line 88 "E--_parser.C"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_LEX_ERROR = 258,
     TOK_PAT_STAR = 259,
     TOK_PAT_OR = 260,
     TOK_PAT_NOT = 261,
     TOK_PLUS = 262,
     TOK_MINUS = 263,
     TOK_UMINUS = 264,
     TOK_MULT = 265,
     TOK_DIV = 266,
     TOK_MOD = 267,
     TOK_BITAND = 268,
     TOK_BITOR = 269,
     TOK_BITNOT = 270,
     TOK_BITXOR = 271,
     TOK_SHL = 272,
     TOK_SHR = 273,
     TOK_GT = 274,
     TOK_LT = 275,
     TOK_GE = 276,
     TOK_LE = 277,
     TOK_EQ = 278,
     TOK_NE = 279,
     TOK_AND = 280,
     TOK_OR = 281,
     TOK_NOT = 282,
     TOK_COMMA = 283,
     TOK_ASSIGN = 284,
     TOK_SEMICOLON = 285,
     TOK_COLON = 286,
     TOK_ARROW = 287,
     TOK_LBRACE = 288,
     TOK_RBRACE = 289,
     TOK_LPAREN = 290,
     TOK_RPAREN = 291,
     TOK_IF = 292,
     TOK_ELSE = 293,
     TOK_CLASS = 294,
     TOK_RETURN = 295,
     TOK_EVENT = 296,
     TOK_ANY = 297,
     TOK_PRINT = 298,
     TOK_UINTNUM = 299,
     TOK_DOUBLENUM = 300,
     TOK_VOID = 301,
     TOK_STRING = 302,
     TOK_STRCONST = 303,
     TOK_INT = 304,
     TOK_UNSIGNED = 305,
     TOK_BOOL = 306,
     TOK_BYTE = 307,
     TOK_DOUBLE = 308,
     TOK_SHORT = 309,
     TOK_TRUE = 310,
     TOK_FALSE = 311,
     TOK_IDENT = 312,
     TOK_DOUBLE_COLON = 313,
     TOK_LBRACK = 314,
     TOK_DOT = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 17 "E--_parser.y++"

  unsigned int 		 uVal;
  double             dVal;
  char*              cVal;
  vector<string>*    strVector;
  Value*             valVal;

  ExprNode*          exprVal;
  vector<ExprNode*>* exprList;
  RefExprNode*       refexpVal;

  ClassEntry*        classEntry;
  Type*              typeVal;
  vector<Type*>*     typeList; 

  EventEntry*        eventEntry;                        
  VariableEntry*     variableEntry;
  FunctionEntry*     functionEntry;

  vector<VariableEntry*>* variableEntries;


  BasePatNode*       patVal;
  PrimitivePatNode*  primPatVal;
  StmtNode*          stmtVal;
  list<StmtNode*>*   stmtList;
  IfNode*            ifVal;
  CompoundStmtNode*  compoundStmtVal;
  RuleNode*          ruleNode;

  vector<RuleNode*>* transList;
  
  vector<Type*>*     formalTypeVal;
  const OpNode::OpInfo*    funIval;



/* Line 293 of yacc.c  */
#line 222 "E--_parser.C"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 234 "E--_parser.C"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    14,    16,    19,    21,
      24,    26,    30,    34,    38,    40,    43,    47,    49,    51,
      55,    58,    61,    63,    66,    69,    73,    74,    76,    78,
      82,    85,    89,    93,    96,    99,   103,   105,   108,   110,
     113,   117,   119,   122,   125,   129,   133,   137,   139,   143,
     145,   147,   150,   154,   155,   157,   161,   163,   166,   168,
     171,   173,   175,   177,   180,   184,   187,   189,   192,   195,
     197,   201,   205,   209,   212,   216,   217,   219,   223,   225,
     229,   233,   237,   241,   245,   249,   253,   257,   261,   265,
     269,   273,   277,   281,   285,   289,   293,   297,   301,   304,
     307,   310,   312,   314,   316,   318,   322,   324,   326,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   346,   349,
     351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    83,    -1,    -1,    65,    66,    -1,
      65,     1,    30,    -1,    67,    -1,    73,    30,    -1,    79,
      -1,    71,    30,    -1,    30,    -1,   108,    69,    30,    -1,
     108,     1,    30,    -1,    57,     1,    30,    -1,    67,    -1,
      68,    67,    -1,    69,    28,    70,    -1,    70,    -1,    57,
      -1,    57,    29,   102,    -1,    39,    72,    -1,    39,     1,
      -1,    57,    -1,    74,    75,    -1,    41,    57,    -1,    35,
      76,    36,    -1,    -1,    77,    -1,    78,    -1,    77,    28,
      78,    -1,   108,    70,    -1,    80,    75,    30,    -1,    80,
      75,    81,    -1,   108,    57,    -1,   108,     1,    -1,    33,
      82,    34,    -1,    94,    -1,    68,    94,    -1,    84,    -1,
      83,    84,    -1,    85,    32,    91,    -1,    86,    -1,    85,
       4,    -1,    27,    85,    -1,    85,     5,    85,    -1,    85,
      31,    85,    -1,    35,    85,    36,    -1,    87,    -1,    87,
      14,   102,    -1,    88,    -1,    42,    -1,    57,    89,    -1,
      35,    90,    36,    -1,    -1,    57,    -1,    90,    28,    57,
      -1,    30,    -1,    95,    30,    -1,    92,    -1,   104,    30,
      -1,    96,    -1,    98,    -1,    93,    -1,    93,    30,    -1,
      33,    94,    34,    -1,    94,    91,    -1,    91,    -1,    94,
       1,    -1,    40,   102,    -1,    97,    -1,    97,    38,    91,
      -1,    37,   102,    91,    -1,    57,   100,    30,    -1,    57,
     100,    -1,    35,   101,    36,    -1,    -1,   102,    -1,   101,
      28,   102,    -1,   103,    -1,   102,     7,   102,    -1,   102,
       8,   102,    -1,   102,    10,   102,    -1,   102,    11,   102,
      -1,   102,    12,   102,    -1,   102,    13,   102,    -1,   102,
      14,   102,    -1,   102,    16,   102,    -1,   102,    17,   102,
      -1,   102,    18,   102,    -1,   102,    25,   102,    -1,   102,
      26,   102,    -1,   102,    23,   102,    -1,   102,    24,   102,
      -1,   102,    19,   102,    -1,   102,    20,   102,    -1,   102,
      21,   102,    -1,   102,    22,   102,    -1,    35,   102,    36,
      -1,     8,   102,    -1,    27,   102,    -1,    15,   102,    -1,
     106,    -1,   105,    -1,   104,    -1,    99,    -1,   105,    29,
     102,    -1,    57,    -1,    48,    -1,    44,    -1,    45,    -1,
      55,    -1,    56,    -1,    51,    -1,    52,    -1,    46,    -1,
      49,    -1,    53,    -1,    47,    -1,    50,    49,    -1,   107,
      -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   178,   178,   184,   185,   186,   192,   193,   194,   195,
     196,   200,   206,   209,   214,   215,   217,   221,   229,   236,
     250,   255,   258,   264,   266,   271,   276,   277,   278,   279,
     280,   289,   293,   298,   303,   306,   311,   312,   319,   324,
     329,   336,   337,   338,   339,   340,   341,   342,   343,   347,
     348,   352,   371,   372,   373,   378,   386,   387,   388,   389,
     390,   391,   393,   394,   396,   397,   401,   406,   409,   418,
     419,   421,   427,   430,   431,   432,   433,   438,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   472,   473,   474,   475,   477,   479,   485,   486,   487,
     488,   489,   495,   496,   497,   498,   499,   500,   501,   504,
     505
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_LEX_ERROR", "TOK_PAT_STAR",
  "TOK_PAT_OR", "TOK_PAT_NOT", "TOK_PLUS", "TOK_MINUS", "TOK_UMINUS",
  "TOK_MULT", "TOK_DIV", "TOK_MOD", "TOK_BITAND", "TOK_BITOR",
  "TOK_BITNOT", "TOK_BITXOR", "TOK_SHL", "TOK_SHR", "TOK_GT", "TOK_LT",
  "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_COMMA", "TOK_ASSIGN", "TOK_SEMICOLON", "TOK_COLON", "TOK_ARROW",
  "TOK_LBRACE", "TOK_RBRACE", "TOK_LPAREN", "TOK_RPAREN", "TOK_IF",
  "TOK_ELSE", "TOK_CLASS", "TOK_RETURN", "TOK_EVENT", "TOK_ANY",
  "TOK_PRINT", "TOK_UINTNUM", "TOK_DOUBLENUM", "TOK_VOID", "TOK_STRING",
  "TOK_STRCONST", "TOK_INT", "TOK_UNSIGNED", "TOK_BOOL", "TOK_BYTE",
  "TOK_DOUBLE", "TOK_SHORT", "TOK_TRUE", "TOK_FALSE", "TOK_IDENT",
  "TOK_DOUBLE_COLON", "TOK_LBRACK", "TOK_DOT", "\"reduce\"", "\"then\"",
  "$accept", "specification", "decl_star", "decl", "variable", "var_star",
  "ident_list", "var_ident", "class_decl", "class_ident", "event_decl",
  "event_hdr", "formal_list", "formal_param_list", "formal_params",
  "formal_param", "func", "func_hdr", "func_body", "func_stmt",
  "rule_star", "rule", "rule_pattern", "primitive_pat_star",
  "primitive_pat", "event_call", "event_params_list", "event_params",
  "stmt", "compstmt_star", "compstmt", "stmt_star", "return_stmt",
  "if_expr_star", "if_expr", "fun_call_stmt", "fun_call", "func_params",
  "func_param_list", "expr", "expr_star", "assign_expr", "ref_expr",
  "literal", "baseType", "type", 0
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
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    89,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    93,    94,    94,    94,    95,    96,
      96,    97,    98,    99,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   104,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   108,
     108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     1,     2,
       1,     3,     3,     3,     1,     2,     3,     1,     1,     3,
       2,     2,     1,     2,     2,     3,     0,     1,     1,     3,
       2,     3,     3,     2,     2,     3,     1,     2,     1,     2,
       3,     1,     2,     2,     3,     3,     3,     1,     3,     1,
       1,     2,     3,     0,     1,     3,     1,     2,     1,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     2,     1,
       3,     3,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    10,     0,     0,     0,
      50,   114,   117,   115,     0,   112,   113,   116,     0,     4,
       6,     0,     0,     0,     8,     0,     2,    38,     0,    41,
      47,    49,   119,     0,     5,     0,    43,     0,    21,    22,
      20,    24,   118,     0,    53,    51,     9,     7,    26,    23,
       0,    39,    42,     0,     0,     0,     0,    34,    18,     0,
      17,    46,    13,    54,     0,   120,     0,    27,    28,     0,
      31,     0,    32,    44,    45,    56,     0,     0,     0,   106,
      40,    58,    62,     0,    60,    69,    61,     0,     0,     0,
       0,     0,     0,   108,   109,   107,   110,   111,   106,   104,
      48,    78,   103,   102,   101,    12,     0,     0,    11,     0,
      52,    25,     0,    18,    30,     0,    14,     0,     0,    66,
       0,     0,     0,     0,    68,    75,     0,    63,    57,     0,
      59,     0,    98,   100,    99,     0,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    16,    55,    29,    15,
       0,    35,    67,    65,     0,    64,    71,     0,    76,    72,
      70,   105,    97,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    93,    94,    95,    96,    91,    92,    89,
      90,     0,    74,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    19,    20,   117,    59,    60,    21,    40,
      22,    23,    49,    66,    67,    68,    24,    25,    72,   118,
      26,    27,    28,    29,    30,    31,    45,    64,   119,    81,
      82,   120,    83,    84,    85,    86,    99,   126,   167,   100,
     101,   102,   103,   104,    32,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     -70,    20,    95,   -70,     1,   174,   -70,   174,     2,   -19,
     -70,   -70,   -70,   -70,   -17,   -70,   -70,   -70,     6,   -70,
     -70,    26,    37,    18,   -70,    18,   174,   -70,    23,   -70,
      54,   -70,   -70,     4,   -70,    55,   -70,   102,   -70,   -70,
     -70,   -70,   -70,    59,    46,   -70,   -70,   -70,   117,   -70,
      79,   -70,   -70,   174,   174,    83,   192,    75,   -20,   -14,
     -70,   -70,   -70,   -70,   -15,   -70,    74,    86,   -70,    70,
     -70,   240,   -70,    14,   124,   -70,    83,   192,   192,    76,
     -70,   -70,    99,   113,   -70,    94,   -70,   119,   122,   192,
     192,   192,   192,   -70,   -70,   -70,   -70,   -70,    76,   -70,
     288,   -70,   -70,   122,   -70,   -70,   192,    70,   -70,   104,
     -70,   -70,   117,   127,   -70,     0,   -70,   240,   137,   -70,
       3,     5,   120,   173,   288,   192,   142,   -70,   -70,    83,
     -70,   192,   107,   264,   327,   243,   -70,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   288,   -70,   -70,   -70,   -70,
     125,   -70,   -70,   -70,    75,   -70,   -70,    16,   288,   -70,
     -70,   288,   -70,   107,   107,   -70,   -70,   -70,   264,   363,
     363,   210,   210,   345,   345,   345,   345,   345,   345,   327,
     308,   192,   -70,   288
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -69,   -70,   -70,   -57,   -70,   -70,
     -70,   -70,   148,   -70,   -70,    63,   -70,   -70,   -70,   -70,
     -70,   150,    12,   -70,   -70,   -70,   -70,   -70,   -21,   -70,
     -70,   -68,   -70,   -70,   -70,   -70,   -70,    80,   -70,   -67,
     -70,   -29,   -25,   -70,   -70,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -121
static const yytype_int16 yytable[] =
{
      33,    43,   116,    38,   162,    57,   164,    43,   122,   106,
     123,   124,   114,   109,   107,   -33,   108,    36,    52,    37,
       3,   110,   132,   133,   134,   135,    87,    52,    53,  -106,
      88,    34,    42,    75,    80,   125,    76,   -36,    41,   155,
      77,    44,    87,    78,   191,    54,    88,    87,   159,   160,
     156,    88,   192,    48,    54,    55,    46,  -120,   168,    39,
      79,    58,   113,  -120,   171,    73,    74,    47,    56,   121,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    87,    62,
      44,    87,    88,    87,    87,    88,     4,    88,    88,   163,
      87,   163,   166,    63,    88,   105,    52,    53,   170,    70,
     111,   125,    71,    75,   112,   121,    76,   139,   140,   141,
      77,   162,     5,    78,   193,     6,   162,   113,    52,   127,
       7,    87,   129,    54,     8,    88,     9,    10,    61,   163,
      79,    11,    12,   128,    13,    14,    15,    16,    17,   130,
      75,   131,    18,    76,   165,    75,   106,    77,    76,   -37,
      78,   157,    77,    11,    12,    78,    13,    14,    15,    16,
      17,   161,   169,    50,    65,   158,    51,    79,   136,     0,
     137,   138,    79,   139,   140,   141,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      89,     5,     0,    75,     0,     0,    76,    90,     0,     7,
      77,     0,     0,    78,     0,     0,    10,   137,   138,    91,
     139,   140,   141,     0,     0,     0,     0,    92,     0,     0,
      79,    35,     0,     0,     0,     0,    93,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
     137,   138,     0,   139,   140,   141,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      75,   137,   138,    76,   139,   140,   141,    77,     0,   172,
      78,   145,   146,     0,     0,     0,    11,    12,     0,    13,
      14,    15,    16,    17,     0,   137,   138,   115,   139,   140,
     141,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   137,   138,     0,   139,   140,
     141,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   137,   138,     0,   139,   140,   141,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   137,   138,     0,   139,   140,   141,   142,   143,
       0,   144,   145,   146,  -121,  -121,  -121,  -121,  -121,  -121,
     137,   138,     0,   139,   140,   141,   142,     0,     0,     0,
     145,   146
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-70))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-121))

static const yytype_int16 yycheck[] =
{
       2,     1,    71,     1,     1,     1,     1,     1,    76,    29,
      77,    78,    69,    28,    28,    35,    30,     5,     4,     7,
       0,    36,    89,    90,    91,    92,    55,     4,     5,    29,
      55,    30,    49,    30,    55,    35,    33,    34,    57,   106,
      37,    35,    71,    40,    28,    31,    71,    76,   117,   117,
     107,    76,    36,    35,    31,    32,    30,    57,   125,    57,
      57,    57,    57,    57,   131,    53,    54,    30,    14,    71,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   117,    30,
      35,   120,   117,   122,   123,   120,     1,   122,   123,   120,
     129,   122,   123,    57,   129,    30,     4,     5,   129,    30,
      36,    35,    33,    30,    28,   117,    33,    10,    11,    12,
      37,     1,    27,    40,   191,    30,     1,    57,     4,    30,
      35,   160,    38,    31,    39,   160,    41,    42,    36,   160,
      57,    46,    47,    30,    49,    50,    51,    52,    53,    30,
      30,    29,    57,    33,    34,    30,    29,    37,    33,    34,
      40,    57,    37,    46,    47,    40,    49,    50,    51,    52,
      53,    34,    30,    25,    57,   112,    26,    57,    98,    -1,
       7,     8,    57,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       8,    27,    -1,    30,    -1,    -1,    33,    15,    -1,    35,
      37,    -1,    -1,    40,    -1,    -1,    42,     7,     8,    27,
      10,    11,    12,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      57,    57,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
       7,     8,    -1,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      30,     7,     8,    33,    10,    11,    12,    37,    -1,    36,
      40,    17,    18,    -1,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    -1,     7,     8,    57,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     7,     8,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     7,     8,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     7,     8,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       7,     8,    -1,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,     1,    27,    30,    35,    39,    41,
      42,    46,    47,    49,    50,    51,    52,    53,    57,    66,
      67,    71,    73,    74,    79,    80,    83,    84,    85,    86,
      87,    88,   107,   108,    30,    57,    85,    85,     1,    57,
      72,    57,    49,     1,    35,    89,    30,    30,    35,    75,
      75,    84,     4,     5,    31,    32,    14,     1,    57,    69,
      70,    36,    30,    57,    90,    57,    76,    77,    78,   108,
      30,    33,    81,    85,    85,    30,    33,    37,    40,    57,
      91,    92,    93,    95,    96,    97,    98,   104,   105,     8,
      15,    27,    35,    44,    45,    48,    55,    56,    57,    99,
     102,   103,   104,   105,   106,    30,    29,    28,    30,    28,
      36,    36,    28,    57,    70,    57,    67,    68,    82,    91,
      94,   108,    94,   102,   102,    35,   100,    30,    30,    38,
      30,    29,   102,   102,   102,   102,   100,     7,     8,    10,
      11,    12,    13,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   102,    70,    57,    78,    67,
      94,    34,     1,    91,     1,    34,    91,   101,   102,    30,
      91,   102,    36,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,    28,    36,   102
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Discard the shifted token.  */
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
        case 2:

/* Line 1806 of yacc.c  */
#line 178 "E--_parser.y++"
    { }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 184 "E--_parser.y++"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 185 "E--_parser.y++"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 186 "E--_parser.y++"
    {
                             errMsg("Syntax error, expecting a declaration");
                        }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 192 "E--_parser.y++"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 193 "E--_parser.y++"
    {}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 194 "E--_parser.y++"
    {}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 195 "E--_parser.y++"
    {}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 196 "E--_parser.y++"
    {}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 200 "E--_parser.y++"
    {                                              
                            for(std::vector<VariableEntry*>::iterator it = (yyvsp[(2) - (3)].variableEntries)->begin(); it != (yyvsp[(2) - (3)].variableEntries)->end();  it++) {
                                    (*it)->type((yyvsp[(1) - (3)].typeVal));
                                    stm.insert((*it));
                            } 
                        }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 206 "E--_parser.y++"
    {
                            errMsg("Error in variable declaration, may be a missing identifier");
                        }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 209 "E--_parser.y++"
    {
                             errMsg("Error in variable declaration, may be a missing type name or identifier");
                        }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 214 "E--_parser.y++"
    {}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 215 "E--_parser.y++"
    {}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 217 "E--_parser.y++"
    {
                            if((yyvsp[(3) - (3)].variableEntry) != NULL)
                                (yyval.variableEntries)->push_back((yyvsp[(3) - (3)].variableEntry)); 
                        }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 221 "E--_parser.y++"
    {
                                (yyval.variableEntries) = new vector<VariableEntry*>();
                                if((yyvsp[(1) - (1)].variableEntry) != NULL)
                                    (yyval.variableEntries)->push_back((yyvsp[(1) - (1)].variableEntry)); 
                        }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 229 "E--_parser.y++"
    {
                                SymTabEntry *ce = stm.currentScope();
                                VariableEntry::VarKind vk = VariableEntry::VarKind::LOCAL_VAR;
                                if(ce->kind() == SymTabEntry::Kind::GLOBAL_KIND) 
                                    vk = VariableEntry::VarKind::GLOBAL_VAR;
                                (yyval.variableEntry) = new VariableEntry((yyvsp[(1) - (1)].cVal), vk); 
                        }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 236 "E--_parser.y++"
    {
                                SymTabEntry *ce = stm.currentScope();
                                VariableEntry::VarKind vk = VariableEntry::VarKind::LOCAL_VAR;
                                if(ce->kind() == SymTabEntry::Kind::GLOBAL_KIND) 
                                    vk = VariableEntry::VarKind::GLOBAL_VAR;
                                (yyval.variableEntry) = new VariableEntry((yyvsp[(1) - (3)].cVal), vk, NULL, (yyvsp[(3) - (3)].exprVal));  
                        }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 250 "E--_parser.y++"
    {   
                            (yyval.classEntry)=new ClassEntry((yyvsp[(2) - (2)].cVal));        
                            stm.insert((yyval.classEntry));
                        }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 255 "E--_parser.y++"
    {
                            errMsg("Syntax error in class declaration: expecting class name"); 
                        }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 258 "E--_parser.y++"
    { (yyval.cVal) = (yyvsp[(1) - (1)].cVal); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 264 "E--_parser.y++"
    { (yyval.eventEntry)=(yyvsp[(1) - (2)].eventEntry); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 266 "E--_parser.y++"
    {
                            (yyval.eventEntry) = new EventEntry((yyvsp[(2) - (2)].cVal));
                            stm.insert((yyval.eventEntry));
                            stm.enterScope((yyval.eventEntry));
                        }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 271 "E--_parser.y++"
    {
                           SymTabEntry *cs = stm.currentScope();
                            if(cs->kind() == SymTabEntry::Kind::EVENT_KIND) 
                                    stm.leaveScope();
                        }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 276 "E--_parser.y++"
    {}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 277 "E--_parser.y++"
    {}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 280 "E--_parser.y++"
    {
                            stm.insert(new VariableEntry((yyvsp[(2) - (2)].variableEntry)->name(), VariableEntry::VarKind::PARAM_VAR, (yyvsp[(1) - (2)].typeVal)));
                        }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 289 "E--_parser.y++"
    {
                            (yyval.functionEntry) = (yyvsp[(1) - (3)].functionEntry); 
                            stm.leaveScope();
                        }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 293 "E--_parser.y++"
    {
                            (yyval.functionEntry) = (yyvsp[(1) - (3)].functionEntry); 
                            stm.leaveScope();
                        }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 298 "E--_parser.y++"
    {
                            (yyval.functionEntry) = new FunctionEntry((yyvsp[(2) - (2)].cVal), (yyvsp[(1) - (2)].typeVal));
                            stm.insert((yyval.functionEntry));
                            stm.enterScope((yyval.functionEntry)); 
                        }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 303 "E--_parser.y++"
    {
                            errMsg("Expecting a function declaration -- may be a missing function name");
                        }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 306 "E--_parser.y++"
    { 
                            SymTabEntry *ce = stm.currentScope();
                            if(ce->kind() == SymTabEntry::Kind::FUNCTION_KIND) 
                                ((FunctionEntry*)ce)->body((yyvsp[(2) - (3)].compoundStmtVal));
                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 311 "E--_parser.y++"
    { (yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[(1) - (1)].stmtList)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 312 "E--_parser.y++"
    { (yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[(2) - (2)].stmtList));                            }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 319 "E--_parser.y++"
    {
                            SymTabEntry *ce = stm.currentScope();
                            if(ce->kind() == SymTabEntry::Kind::GLOBAL_KIND) 
                                ((GlobalEntry*)ce)->addRule((yyvsp[(1) - (1)].ruleNode));
                        }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 324 "E--_parser.y++"
    {
                                SymTabEntry *ce = stm.currentScope();
                                if(ce->kind() == SymTabEntry::Kind::GLOBAL_KIND) 
                                    ((GlobalEntry*)ce)->addRule((yyvsp[(2) - (2)].ruleNode));
                        }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 329 "E--_parser.y++"
    {
                            RuleBlockEntry *bE = new RuleBlockEntry();
                            (yyval.ruleNode) = new RuleNode(bE, (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].stmtVal));
                        }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 336 "E--_parser.y++"
    { (yyval.patVal)=(yyvsp[(1) - (1)].primPatVal);                                                    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 337 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::STAR, (yyvsp[(1) - (2)].patVal));     }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 338 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::NEG, (yyvsp[(2) - (2)].patVal));      }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 339 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::OR, (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].patVal));   }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 340 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::SEQ, (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].patVal));  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 341 "E--_parser.y++"
    { (yyval.patVal) = (yyvsp[(2) - (3)].patVal);                                                  }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 342 "E--_parser.y++"
    { (yyval.primPatVal)=(yyvsp[(1) - (1)].primPatVal);                                                    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 343 "E--_parser.y++"
    { 
                                (yyvsp[(1) - (3)].primPatVal)->cond((yyvsp[(3) - (3)].exprVal));
                                (yyval.primPatVal) = (yyvsp[(1) - (3)].primPatVal); 
                        }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 347 "E--_parser.y++"
    { (yyval.primPatVal)=(yyvsp[(1) - (1)].primPatVal);                                                    }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 348 "E--_parser.y++"
    { (yyval.primPatVal) = new PrimitivePatNode(new EventEntry("any"), NULL);   }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 352 "E--_parser.y++"
    { 
                            SymTabEntry *ste = stm.lookUp((yyvsp[(1) - (2)].cVal));
                            EventEntry *ee = (EventEntry*) ste;
                            if(ee->kind() == SymTabEntry::Kind::EVENT_KIND) 
                                ee = (EventEntry*) ste;
                            vector<VariableEntry*> *prm = new vector<VariableEntry*>();
                            const SymTab *cST = ee->symTab();
                            if(cST != NULL) {
                                SymTab::const_iterator it = cST->begin();
                                std::vector<string>::const_iterator it1  = (yyvsp[(2) - (2)].strVector)->begin();
                                for(; it != cST->end() || it1 != (yyvsp[(2) - (2)].strVector)->end(); ++it, ++it1) {
                                    if((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
                                        VariableEntry *ve = (VariableEntry*)(*it);
                                        prm->push_back(new VariableEntry((*it1), ve->varKind(), ve->type()));
                                    }
                                }
                            }
                            (yyval.primPatVal) = new PrimitivePatNode(ee, prm); 
                        }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 371 "E--_parser.y++"
    { (yyval.strVector)=(yyvsp[(2) - (3)].strVector);                                                    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 372 "E--_parser.y++"
    {}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 373 "E--_parser.y++"
    {
                                (yyval.strVector) = new vector<string>();
                                if((yyvsp[(1) - (1)].cVal) != NULL)
                                    (yyval.strVector)->push_back((yyvsp[(1) - (1)].cVal));
                        }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 378 "E--_parser.y++"
    {
                                if((yyvsp[(3) - (3)].cVal) != NULL)
                                    (yyval.strVector)->push_back((yyvsp[(3) - (3)].cVal));
                        }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 386 "E--_parser.y++"
    { (yyval.stmtVal)=NULL;                                                  }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 387 "E--_parser.y++"
    { (yyval.stmtVal)=(yyvsp[(1) - (2)].stmtVal);                                                    }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 388 "E--_parser.y++"
    { (yyval.stmtVal)=(yyvsp[(1) - (1)].compoundStmtVal);                                                    }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 389 "E--_parser.y++"
    { (yyval.stmtVal)=new ExprStmtNode((yyvsp[(1) - (2)].exprVal));                                  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 390 "E--_parser.y++"
    { (yyval.stmtVal)=(yyvsp[(1) - (1)].ifVal);                                                    }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 391 "E--_parser.y++"
    { (yyval.stmtVal)=(yyvsp[(1) - (1)].stmtVal);                                                    }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 393 "E--_parser.y++"
    { (yyval.compoundStmtVal)=(yyvsp[(1) - (1)].compoundStmtVal); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 394 "E--_parser.y++"
    { (yyval.compoundStmtVal)=(yyvsp[(1) - (2)].compoundStmtVal);                                                    }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 396 "E--_parser.y++"
    { (yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[(2) - (3)].stmtList));                            }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 397 "E--_parser.y++"
    {
                            if((yyvsp[(1) - (2)].stmtList) != NULL)
                                (yyval.stmtList)->push_back((yyvsp[(2) - (2)].stmtVal)); 
                        }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 401 "E--_parser.y++"
    {
                            (yyval.stmtList) = new list<StmtNode*>();
                            if((yyvsp[(1) - (1)].stmtVal) != NULL)
                                (yyval.stmtList)->push_back((yyvsp[(1) - (1)].stmtVal));
                        }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 406 "E--_parser.y++"
    {
                            errMsg("Syntax error while parsing a statement");
                        }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 409 "E--_parser.y++"
    {
                            SymTabEntry *ce = stm.currentScope();
                            if(ce->kind() == SymTabEntry::Kind::FUNCTION_KIND) 
                                (yyval.stmtVal) = new ReturnStmtNode((yyvsp[(2) - (2)].exprVal), ((FunctionEntry*)ce));
                        }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 418 "E--_parser.y++"
    { (yyval.ifVal)=(yyvsp[(1) - (1)].ifVal); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 419 "E--_parser.y++"
    { (yyval.ifVal) = new IfNode(((IfNode*)(yyvsp[(1) - (3)].ifVal))->cond(), ((IfNode*)(yyvsp[(1) - (3)].ifVal))->thenStmt(), (yyvsp[(3) - (3)].stmtVal));           
                        }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 421 "E--_parser.y++"
    { (yyval.ifVal) = new IfNode((yyvsp[(2) - (3)].exprVal), (yyvsp[(3) - (3)].stmtVal)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 427 "E--_parser.y++"
    {
                           (yyval.stmtVal) = new ExprStmtNode(new InvocationNode(stm.lookUp((yyvsp[(1) - (3)].cVal)), (yyvsp[(2) - (3)].exprList))); 
                        }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 430 "E--_parser.y++"
    { (yyval.exprVal)=new InvocationNode(stm.lookUp((yyvsp[(1) - (2)].cVal)), (yyvsp[(2) - (2)].exprList));                }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 431 "E--_parser.y++"
    { (yyval.exprList)=(yyvsp[(2) - (3)].exprList);                                                    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 432 "E--_parser.y++"
    { (yyval.exprList) = new vector<ExprNode*>();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 433 "E--_parser.y++"
    { 
                                (yyval.exprList) = new vector<ExprNode*>(); 
                                if((yyvsp[(1) - (1)].exprVal) != NULL)
                                    (yyval.exprList)->push_back((yyvsp[(1) - (1)].exprVal)); 
                        }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 438 "E--_parser.y++"
    {
                                if((yyvsp[(3) - (3)].exprVal) != NULL)
                                    (yyval.exprList)->push_back((yyvsp[(3) - (3)].exprVal));
                        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 447 "E--_parser.y++"
    {   (yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);                                                  }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 448 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::PLUS,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));              }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 449 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::MINUS,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));             }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 450 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::MULT,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));              }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 451 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::DIV,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));               }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 452 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::MOD,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));               }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 453 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::BITAND,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));            }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 454 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::BITOR,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));             }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 455 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::BITXOR,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));            }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 456 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::SHL,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));               }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 457 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::SHR,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));               }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 458 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::AND,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));               }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 459 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::OR,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 460 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::EQ,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 461 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::NE,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 462 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::GT,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 463 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::LT,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 464 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::GE,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 465 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::LE,(yyvsp[(1) - (3)].exprVal),(yyvsp[(3) - (3)].exprVal));                }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 466 "E--_parser.y++"
    {   (yyval.exprVal)=(yyvsp[(2) - (3)].exprVal);                                                  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 467 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::UMINUS,(yyvsp[(2) - (2)].exprVal));               }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 468 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::NOT,(yyvsp[(2) - (2)].exprVal));                  }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 469 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::BITNOT,(yyvsp[(2) - (2)].exprVal));               }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 472 "E--_parser.y++"
    {   (yyval.exprVal)=new ValueNode((yyvsp[(1) - (1)].valVal));                                   }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 473 "E--_parser.y++"
    {   (yyval.exprVal)=(yyvsp[(1) - (1)].refexpVal);                                                  }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 474 "E--_parser.y++"
    {   (yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);                                                  }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 475 "E--_parser.y++"
    {   (yyval.exprVal)=(yyvsp[(1) - (1)].exprVal);                                                  }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 477 "E--_parser.y++"
    {   (yyval.exprVal)=new OpNode(OpNode::OpCode::ASSIGN,(yyvsp[(1) - (3)].refexpVal),(yyvsp[(3) - (3)].exprVal));            }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 479 "E--_parser.y++"
    {   (yyval.refexpVal)=new RefExprNode((yyvsp[(1) - (1)].cVal));                                 }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 485 "E--_parser.y++"
    {   (yyval.valVal)=new Value((yyvsp[(1) - (1)].cVal));                                       }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 486 "E--_parser.y++"
    {   (yyval.valVal)=new Value((yyvsp[(1) - (1)].uVal), Type::Type::UINT);                     }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 487 "E--_parser.y++"
    {   (yyval.valVal)=new Value((yyvsp[(1) - (1)].dVal));                                       }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 488 "E--_parser.y++"
    {   (yyval.valVal)=new Value(true);                                     }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 489 "E--_parser.y++"
    {   (yyval.valVal)=new Value(false);                                    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 495 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::BOOL);                       }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 496 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::BYTE);                       }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 497 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::VOID);                       }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 498 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::INT);                        }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 499 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::DOUBLE);                     }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 500 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::STRING);                     }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 501 "E--_parser.y++"
    {   (yyval.typeVal)=new Type(Type::TypeTag::UINT);                       }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 504 "E--_parser.y++"
    {   (yyval.typeVal)=(yyvsp[(1) - (1)].typeVal);                                                  }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 505 "E--_parser.y++"
    {   
                                SymTabEntry *ce=stm.lookUp((yyvsp[(1) - (1)].cVal));
                                if(ce==NULL)
                                    (yyval.typeVal)=new Type(ce,Type::UNKNOWN);
                                else
                                    (yyval.typeVal)=new Type(ce,Type::CLASS);
                        }
    break;



/* Line 1806 of yacc.c  */
#line 2647 "E--_parser.C"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval);
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
      if (!yypact_value_is_default (yyn))
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 514 "E--_parser.y++"


