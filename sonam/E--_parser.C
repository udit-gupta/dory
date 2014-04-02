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

extern SymTabMgr stm;

/* Global variables for inherited attributes */
Type *var_type;
Type *fun_ret_type;
int unsigned_set;

int start_rule_scope = 0;
RuleBlockEntry* rbe = NULL;



/* Line 268 of yacc.c  */
#line 98 "E--_parser.C"

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
#line 27 "E--_parser.y++"

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
#line 229 "E--_parser.C"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 241 "E--_parser.C"

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
#define YYLAST   408

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    14,    16,    18,    21,
      23,    25,    29,    33,    37,    41,    45,    48,    50,    54,
      55,    57,    60,    62,    63,    65,    67,    72,    76,    80,
      83,    86,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   106,   108,   109,   112,   116,   120,   124,   126,   130,
     134,   140,   145,   151,   155,   160,   163,   167,   169,   171,
     175,   179,   182,   186,   189,   191,   195,   196,   198,   199,
     202,   205,   209,   213,   219,   220,   223,   227,   229,   233,
     236,   239,   241,   243,   245,   249,   250,   252,   254,   256,
     258,   260,   262,   264,   268,   273,   275,   279,   283,   287,
     291,   295,   298,   302,   306,   310,   313,   317,   321,   325,
     329,   333,   337,   341,   345,   349,   353,   356,   360,   362,
     364,   366,   370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    83,    -1,    -1,    63,    64,    -1,
      63,     1,    30,    -1,    30,    -1,    65,    -1,    67,    72,
      -1,    76,    -1,    81,    -1,    39,    57,    30,    -1,    39,
       1,    30,    -1,    79,    57,    35,    -1,    79,     1,    35,
      -1,    66,    70,    36,    -1,    71,    57,    -1,    68,    -1,
      69,    28,    68,    -1,    -1,    69,    -1,    77,    78,    -1,
      57,    -1,    -1,    74,    -1,    33,    -1,    73,    80,    94,
      34,    -1,    41,    57,    35,    -1,    75,    69,    36,    -1,
      75,    36,    -1,    41,    42,    -1,    -1,    50,    -1,    46,
      -1,    49,    -1,    53,    -1,    51,    -1,    47,    -1,    52,
      -1,    54,    -1,    77,    78,    -1,    57,    -1,    -1,    80,
      81,    -1,    79,    82,    30,    -1,    57,     1,    30,    -1,
      79,     1,    30,    -1,    57,    -1,    57,    29,   101,    -1,
      82,    28,    57,    -1,    82,    28,    57,    29,   101,    -1,
      86,    32,    94,    30,    -1,    83,    86,    32,    94,    30,
      -1,    86,    32,    94,    -1,    83,    86,    32,    94,    -1,
      57,    35,    -1,    84,    88,    36,    -1,    42,    -1,    90,
      -1,    35,    86,    36,    -1,    86,    31,    86,    -1,    86,
       4,    -1,    86,     5,    86,    -1,    27,    86,    -1,    57,
      -1,    87,    28,    57,    -1,    -1,    87,    -1,    -1,    14,
     101,    -1,    85,    89,    -1,    33,    93,    34,    -1,    37,
     101,    94,    -1,    37,   101,    94,    38,    94,    -1,    -1,
      93,    94,    -1,    93,     1,    30,    -1,    30,    -1,    40,
     101,    30,    -1,    99,    30,    -1,   100,    30,    -1,    91,
      -1,    92,    -1,   101,    -1,    95,    28,   101,    -1,    -1,
      95,    -1,    44,    -1,    45,    -1,    48,    -1,    55,    -1,
      56,    -1,    57,    -1,    98,    29,   101,    -1,    57,    35,
      96,    36,    -1,    97,    -1,   101,     7,   101,    -1,   101,
       8,   101,    -1,   101,    10,   101,    -1,   101,    11,   101,
      -1,   101,    12,   101,    -1,     8,   101,    -1,   101,    16,
     101,    -1,   101,    14,   101,    -1,   101,    13,   101,    -1,
      15,   101,    -1,   101,    17,   101,    -1,   101,    18,   101,
      -1,   101,    19,   101,    -1,   101,    20,   101,    -1,   101,
      21,   101,    -1,   101,    22,   101,    -1,   101,    23,   101,
      -1,   101,    24,   101,    -1,   101,    25,   101,    -1,   101,
      26,   101,    -1,    27,   101,    -1,    35,   101,    36,    -1,
      98,    -1,    99,    -1,   100,    -1,   101,    60,   101,    -1,
      59,   101,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   152,   154,   155,   160,   161,   162,   167,
     171,   174,   178,   181,   186,   189,   195,   212,   216,   228,
     229,   232,   233,   239,   241,   244,   247,   255,   258,   259,
     260,   266,   268,   271,   272,   278,   279,   280,   281,   282,
     290,   294,   300,   302,   305,   306,   307,   310,   325,   340,
     355,   372,   379,   386,   393,   402,   415,   429,   441,   442,
     443,   444,   445,   446,   449,   450,   453,   455,   458,   460,
     463,   469,   472,   473,   476,   478,   479,   482,   483,   484,
     485,   486,   487,   490,   491,   494,   495,   498,   499,   500,
     501,   502,   505,   508,   511,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545
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
  "TOK_DOUBLE_COLON", "TOK_LBRACK", "TOK_DOT", "$accept", "specification",
  "ifc_decl_star", "ifc_decl", "class_decl", "function_header",
  "function_decl", "formal_param", "formal_param_plus",
  "formal_param_list", "formal_param_type", "body_star", "body_header",
  "body", "event_decl_header", "event_decl", "type_sign", "baseType",
  "type", "variable_decl_star", "variable_decl", "variable", "rule_star",
  "event_header", "event", "event_pattern", "identifier",
  "identifier_list", "opt_cond", "primitive_pattern", "compound_statement",
  "if_then_else_stmt", "statement_star", "statement", "expr_plus",
  "expr_list", "literal", "ref_expr", "asg_stmt", "function_invocation",
  "expr", 0
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
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    74,    75,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    83,    83,    83,    83,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    91,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    98,    99,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     1,     2,     1,
       1,     3,     3,     3,     3,     3,     2,     1,     3,     0,
       1,     2,     1,     0,     1,     1,     4,     3,     3,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     2,     3,     3,     3,     1,     3,     3,
       5,     4,     5,     3,     4,     2,     3,     1,     1,     3,
       3,     2,     3,     2,     1,     3,     0,     1,     0,     2,
       2,     3,     3,     5,     0,     2,     3,     1,     3,     2,
       2,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     6,     0,     0,     0,
      57,    32,     0,     4,     7,    31,    23,    31,     9,     0,
       0,    10,     2,    66,    68,     0,    58,     5,     0,    63,
       0,     0,     0,    30,     0,     0,    55,    22,    17,    20,
       0,     0,     0,    25,     8,    42,    24,    29,     0,    33,
      37,    34,    36,    38,    35,    39,    40,     0,    47,     0,
       0,    64,    67,     0,     0,    70,    61,     0,     0,     0,
      59,    12,    11,    27,    45,    31,    15,    16,    21,    31,
      28,    46,    14,     0,    13,     0,    44,     0,     0,    56,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
       0,    95,   118,   119,   120,    69,    62,    60,    77,    74,
       0,     0,    81,    82,    53,     0,     0,     0,    18,     0,
       0,    43,     0,    48,    49,    54,    65,   101,   105,   116,
       0,    85,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    79,    80,     0,
      47,    26,     0,    52,   117,    86,     0,    83,    93,    96,
      97,    98,    99,   100,   104,   103,   102,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   121,     0,    71,
      75,    72,    78,    50,     0,    94,    76,     0,    84,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    15,    16,    38,    39,    40,
      41,    44,    45,    46,    17,    18,    42,    56,    20,    79,
      21,    59,    22,    23,    24,    25,    62,    63,    65,    26,
     112,   113,   153,   114,   165,   166,   101,   102,   103,   104,
     105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
     -79,    33,   113,   -79,   -23,   -10,   -79,   -10,     7,   -18,
     -79,   -79,     5,   -79,   -79,   140,     2,   156,   -79,   314,
      14,   -79,   -10,   -34,    31,   184,   -79,   -79,    11,   -79,
     108,    26,    36,   -79,    20,    38,   -79,   -79,   -79,    49,
      42,    24,   314,   -79,   -79,   -79,   -79,   -79,    -9,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,    23,    28,    37,
     324,   -79,    55,    80,   349,   -79,   -79,   -10,   -10,   101,
     -79,   -79,   -79,   -79,   -79,   -14,   -79,   -79,   -79,    85,
     -79,   -79,   -79,   349,   -79,    34,   -79,   101,    60,   -79,
     349,   349,   349,   349,   -79,   -79,   -79,   -79,   -79,    88,
     349,   -79,    91,   -79,   -79,   257,    17,   120,   -79,   -79,
     349,   349,   -79,   -79,    96,    91,    97,    99,   -79,    25,
      15,   -79,   102,   257,   104,   107,   -79,   133,   139,   302,
     212,   349,   133,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,     4,   161,   233,   -79,   -79,   -79,   115,
     132,   -79,   349,   -79,   -79,   167,   160,   257,   257,    19,
      19,   133,   133,   133,   139,   341,   341,   200,   200,   323,
     323,   323,   323,   323,   323,   302,   278,   -79,   170,   -79,
     -79,   164,   -79,   257,   349,   -79,   -79,   101,   257,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   128,   187,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,     1,   163,   130,   -79,
     135,   -79,   -79,   -79,   -79,     6,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -78,   -79,   -79,   -79,   -69,   -67,   -65,
     -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
     115,   122,   116,    19,   117,   188,    35,    27,    31,   125,
     115,    29,   116,    30,   117,    57,   159,     5,   115,    75,
     116,    66,   117,    61,    33,     7,    35,    80,    60,   136,
     137,   138,    10,     3,   108,    43,    11,   109,   189,    34,
      36,   110,   123,    37,   111,    64,    36,    28,    68,   127,
     128,   129,   130,    81,   -92,    73,    71,    83,    82,   132,
     131,    99,   -41,    84,    32,    85,    72,    86,    74,   154,
     155,    58,   160,   106,   107,   190,   191,    75,    76,   152,
      19,    77,   -41,    88,   115,   115,   116,   116,   117,   117,
     167,   124,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    66,    67,     4,   108,    89,   126,   109,   199,
     133,   193,   110,   131,    66,   111,   156,   157,   115,   158,
     116,   108,   117,   162,   109,    11,   161,   163,   110,    68,
       5,   111,   119,     6,    70,    81,   134,   135,     7,   136,
     137,   138,     8,   198,     9,    10,   142,   143,    99,   -31,
     -31,    83,   -31,    11,   -31,   -31,   -31,   -31,   134,   135,
      12,   136,   137,   138,   139,   140,   -19,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    66,    67,
      11,   108,    47,   152,   109,   194,   195,    37,   110,   152,
     196,   111,   197,   118,    48,    78,    11,   134,   135,   120,
     136,   137,   138,    37,   121,    68,    69,     0,    99,   134,
     135,   152,   136,   137,   138,   139,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     134,   135,     0,   136,   137,   138,   139,   140,   164,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,   192,   134,   135,     0,   136,   137,   138,
     139,   140,   152,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,   134,   135,     0,   136,   137,
     138,   139,   140,   152,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,   134,
     135,     0,   136,   137,   138,   139,   140,   152,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,    66,    67,
     134,   135,     0,   136,   137,   138,   139,   140,   152,   141,
     142,   143,   -93,   -93,   -93,   -93,   -93,   -93,   134,   135,
       0,   136,   137,   138,   139,    68,    87,    90,   142,   143,
      49,    50,   152,    51,    91,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,   152,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,    96,     0,     0,
       0,   152,     0,     0,    97,    98,    99,     0,   100
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-79))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-93))

static const yytype_int16 yycheck[] =
{
      69,    79,    69,     2,    69,     1,     1,    30,     1,    87,
      79,     5,    79,     7,    79,     1,     1,    27,    87,    28,
      87,     4,    87,    57,    42,    35,     1,    36,    22,    10,
      11,    12,    42,     0,    30,    33,    50,    33,    34,    57,
      35,    37,    83,    57,    40,    14,    35,    57,    31,    90,
      91,    92,    93,    30,    29,    35,    30,    29,    35,   100,
      35,    57,    57,    35,    57,    28,    30,    30,    30,   110,
     111,    57,    57,    67,    68,   153,   154,    28,    36,    60,
      79,    57,    57,    28,   153,   154,   153,   154,   153,   154,
     131,    57,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     4,     5,     1,    30,    36,    57,    33,   197,
      29,   162,    37,    35,     4,    40,    30,    30,   197,    30,
     197,    30,   197,    29,    33,    50,    34,    30,    37,    31,
      27,    40,    57,    30,    36,    30,     7,     8,    35,    10,
      11,    12,    39,   194,    41,    42,    17,    18,    57,    46,
      47,    29,    49,    50,    51,    52,    53,    54,     7,     8,
      57,    10,    11,    12,    13,    14,    36,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     4,     5,
      50,    30,    36,    60,    33,    28,    36,    57,    37,    60,
      30,    40,    38,    75,    17,    42,    50,     7,     8,    79,
      10,    11,    12,    57,    79,    31,    32,    -1,    57,     7,
       8,    60,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    36,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      60,    -1,    -1,    30,     7,     8,    -1,    10,    11,    12,
      13,    14,    60,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    60,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,     7,
       8,    -1,    10,    11,    12,    13,    14,    60,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,     4,     5,
       7,     8,    -1,    10,    11,    12,    13,    14,    60,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,     8,
      -1,    10,    11,    12,    13,    31,    32,     8,    17,    18,
      46,    47,    60,    49,    15,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,    -1,
      -1,    60,    -1,    -1,    55,    56,    57,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,     1,    27,    30,    35,    39,    41,
      42,    50,    57,    64,    65,    66,    67,    75,    76,    77,
      79,    81,    83,    84,    85,    86,    90,    30,    57,    86,
      86,     1,    57,    42,    57,     1,    35,    57,    68,    69,
      70,    71,    77,    33,    72,    73,    74,    36,    69,    46,
      47,    49,    51,    52,    53,    54,    78,     1,    57,    82,
      86,    57,    87,    88,    14,    89,     4,     5,    31,    32,
      36,    30,    30,    35,    30,    28,    36,    57,    78,    80,
      36,    30,    35,    29,    35,    28,    30,    32,    28,    36,
       8,    15,    27,    35,    44,    45,    48,    55,    56,    57,
      59,    97,    98,    99,   100,   101,    86,    86,    30,    33,
      37,    40,    91,    92,    94,    98,    99,   100,    68,    57,
      79,    81,    94,   101,    57,    94,    57,   101,   101,   101,
     101,    35,   101,    29,     7,     8,    10,    11,    12,    13,
      14,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    60,    93,   101,   101,    30,    30,    30,     1,
      57,    34,    29,    30,    36,    95,    96,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,     1,    34,
      94,    94,    30,   101,    28,    36,    30,    38,   101,    94
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
#line 149 "E--_parser.y++"
    { }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 152 "E--_parser.y++"
    {
}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 154 "E--_parser.y++"
    { }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 155 "E--_parser.y++"
    {
        errMsg("Syntax error, expecting a declaration");
}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 160 "E--_parser.y++"
    {  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 161 "E--_parser.y++"
    {  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 162 "E--_parser.y++"
    { 
	(yyvsp[(1) - (2)].functionEntry)->body((yyvsp[(2) - (2)].compoundStmtVal));
	stm.leaveScope();
	stm.insert((yyvsp[(1) - (2)].functionEntry));
}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 167 "E--_parser.y++"
    {
	stm.leaveScope();
	stm.insert((yyvsp[(1) - (1)].eventEntry));
}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 171 "E--_parser.y++"
    { }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 174 "E--_parser.y++"
    {
	(yyval.classEntry) = new ClassEntry((yyvsp[(2) - (3)].cVal));
	stm.insert((yyval.classEntry));
}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 178 "E--_parser.y++"
    { errMsg("Syntax error in class declaration: expecting class name"); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 181 "E--_parser.y++"
    {
	(yyval.functionEntry) = new FunctionEntry((yyvsp[(2) - (3)].cVal), nullptr);
	fun_ret_type = (yyvsp[(1) - (3)].typeVal);
	stm.enterScope((yyval.functionEntry));
}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 186 "E--_parser.y++"
    { errMsg("Expecting a function declaration -- may be a missing function name"); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 189 "E--_parser.y++"
    {
	(yyvsp[(1) - (3)].functionEntry)->type(new Type((yyvsp[(2) - (3)].typeList), fun_ret_type));
	(yyval.functionEntry) = (yyvsp[(1) - (3)].functionEntry);
}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 195 "E--_parser.y++"
    {
	VariableEntry::VarKind mk;
	SymTabEntry::Kind k = stm.currentScope()->kind();

	if (k == SymTabEntry::Kind::GLOBAL_KIND)
		mk = VariableEntry::VarKind::GLOBAL_VAR;
	else if (k == SymTabEntry::Kind::FUNCTION_KIND || k == SymTabEntry::Kind::EVENT_KIND)
		mk = VariableEntry::VarKind::PARAM_VAR;
	else
		mk = VariableEntry::VarKind::LOCAL_VAR;

	(yyval.variableEntry) = new VariableEntry((yyvsp[(2) - (2)].cVal), mk, (yyvsp[(1) - (2)].typeVal));
	stm.insert((yyval.variableEntry));
	var_type = (yyvsp[(1) - (2)].typeVal);
}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 212 "E--_parser.y++"
    {
	(yyval.typeList) = new std::vector<Type*>();
	(yyval.typeList)->push_back(var_type);
}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 216 "E--_parser.y++"
    {
	if ((yyvsp[(1) - (3)].typeList))
		(yyvsp[(1) - (3)].typeList)->push_back(var_type);
	else {
		(yyvsp[(1) - (3)].typeList) = new std::vector<Type*>();
		(yyvsp[(1) - (3)].typeList)->push_back(var_type);
	}

	(yyval.typeList) = (yyvsp[(1) - (3)].typeList);
}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 228 "E--_parser.y++"
    { (yyval.typeList) = nullptr; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 229 "E--_parser.y++"
    { (yyval.typeList) = (yyvsp[(1) - (1)].typeList); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 232 "E--_parser.y++"
    { (yyval.typeVal) = (yyvsp[(2) - (2)].typeVal); unsigned_set = 0; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 233 "E--_parser.y++"
    {
	SymTabEntry *lp = stm.lookUp((yyvsp[(1) - (1)].cVal));
	(yyval.typeVal) = new Type(lp, Type::TypeTag::CLASS);
}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 239 "E--_parser.y++"
    { (yyval.compoundStmtVal) = nullptr;
}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 241 "E--_parser.y++"
    { (yyval.compoundStmtVal) = (yyvsp[(1) - (1)].compoundStmtVal); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 244 "E--_parser.y++"
    { }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 247 "E--_parser.y++"
    {
	std::list<StmtNode*>* s = new std::list<StmtNode*>();

	s->push_back((yyvsp[(3) - (4)].stmtVal));
	(yyval.compoundStmtVal) = new CompoundStmtNode(s);
}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 255 "E--_parser.y++"
    { (yyval.eventEntry) = new EventEntry((yyvsp[(2) - (3)].cVal)); stm.enterScope((yyval.eventEntry)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 258 "E--_parser.y++"
    { (yyval.eventEntry) = (yyvsp[(1) - (3)].eventEntry); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 259 "E--_parser.y++"
    { (yyval.eventEntry) = (yyvsp[(1) - (2)].eventEntry); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 260 "E--_parser.y++"
    {
	(yyval.eventEntry) = new EventEntry("any");
	stm.enterScope((yyval.eventEntry));
}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 266 "E--_parser.y++"
    {
}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 268 "E--_parser.y++"
    { unsigned_set = 1; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 271 "E--_parser.y++"
    { (yyval.typeVal) = new Type(Type::voidType); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 272 "E--_parser.y++"
    {
	if (unsigned_set)
		(yyval.typeVal) = new Type(Type::uintType);
	else
		(yyval.typeVal) = new Type(Type::intType);
}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 278 "E--_parser.y++"
    { (yyval.typeVal) = new Type(Type::doubleType); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 279 "E--_parser.y++"
    { (yyval.typeVal) = new Type(Type::boolType); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 280 "E--_parser.y++"
    { (yyval.typeVal) = new Type(Type::stringType); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 281 "E--_parser.y++"
    { (yyval.typeVal) = new Type(Type::byteType); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 282 "E--_parser.y++"
    {
	if (unsigned_set)
		(yyval.typeVal) = new Type(Type::uintType);
	else
		(yyval.typeVal) = new Type(Type::intType);
}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 290 "E--_parser.y++"
    {
	(yyval.typeVal) = var_type = (yyvsp[(2) - (2)].typeVal);
	unsigned_set = 0;
}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 294 "E--_parser.y++"
    {
	SymTabEntry *lp = stm.lookUp((yyvsp[(1) - (1)].cVal));
        (yyval.typeVal) = var_type = new Type(lp, Type::TypeTag::CLASS);
}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 300 "E--_parser.y++"
    {
}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 302 "E--_parser.y++"
    { }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 305 "E--_parser.y++"
    { (yyval.variableEntry) = (yyvsp[(2) - (3)].variableEntry); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 306 "E--_parser.y++"
    { errMsg("Error in variable declaration, may be a missing type name or identifier"); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 307 "E--_parser.y++"
    { errMsg("Error in variable declaration, may be a missing identifier"); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 310 "E--_parser.y++"
    {
	VariableEntry::VarKind mk;
	SymTabEntry::Kind k = stm.currentScope()->kind();

	if (k == SymTabEntry::Kind::GLOBAL_KIND)
		mk = VariableEntry::VarKind::GLOBAL_VAR;
	else if (k == SymTabEntry::Kind::FUNCTION_KIND || k == SymTabEntry::Kind::EVENT_KIND)
		mk = VariableEntry::VarKind::PARAM_VAR;
	else
		mk = VariableEntry::VarKind::LOCAL_VAR;

	(yyval.variableEntry) = new VariableEntry((yyvsp[(1) - (1)].cVal), mk, var_type);

	stm.insert((yyval.variableEntry));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 325 "E--_parser.y++"
    {
	VariableEntry::VarKind mk;
	SymTabEntry::Kind k = stm.currentScope()->kind();

	if (k == SymTabEntry::Kind::GLOBAL_KIND)
		mk = VariableEntry::VarKind::GLOBAL_VAR;
	else if (k == SymTabEntry::Kind::FUNCTION_KIND || k == SymTabEntry::Kind::EVENT_KIND)
		mk = VariableEntry::VarKind::PARAM_VAR;
	else
		mk = VariableEntry::VarKind::LOCAL_VAR;

	(yyval.variableEntry) = new VariableEntry((yyvsp[(1) - (3)].cVal), mk, var_type, (yyvsp[(3) - (3)].exprVal));

	stm.insert((yyval.variableEntry));
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 340 "E--_parser.y++"
    {
	VariableEntry::VarKind mk;
	SymTabEntry::Kind k = stm.currentScope()->kind();

	if (k == SymTabEntry::Kind::GLOBAL_KIND)
		mk = VariableEntry::VarKind::GLOBAL_VAR;
	else if (k == SymTabEntry::Kind::FUNCTION_KIND || k == SymTabEntry::Kind::EVENT_KIND)
		mk = VariableEntry::VarKind::PARAM_VAR;
	else
		mk = VariableEntry::VarKind::LOCAL_VAR;

	(yyval.variableEntry) = new VariableEntry((yyvsp[(3) - (3)].cVal), mk, var_type);

	stm.insert((yyval.variableEntry));
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 355 "E--_parser.y++"
    {
	VariableEntry::VarKind mk;
	SymTabEntry::Kind k = stm.currentScope()->kind();

	if (k == SymTabEntry::Kind::GLOBAL_KIND)
		mk = VariableEntry::VarKind::GLOBAL_VAR;
	else if (k == SymTabEntry::Kind::FUNCTION_KIND || k == SymTabEntry::Kind::EVENT_KIND)
		mk = VariableEntry::VarKind::PARAM_VAR;
	else
		mk = VariableEntry::VarKind::LOCAL_VAR;

	(yyval.variableEntry) = new VariableEntry((yyvsp[(3) - (5)].cVal), mk, var_type, (yyvsp[(5) - (5)].exprVal));

	stm.insert((yyval.variableEntry));
}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 372 "E--_parser.y++"
    {
	(yyval.ruleNode) = new RuleNode(static_cast <BlockEntry*> (stm.currentScope()), (yyvsp[(1) - (4)].patVal), (yyvsp[(3) - (4)].stmtVal));
	stm.leaveScope();
	stm.insert(rbe);
	start_rule_scope = 0;
	static_cast <GlobalEntry*> (stm.currentScope())->addRule((yyval.ruleNode));
}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 379 "E--_parser.y++"
    {
	(yyval.ruleNode) = new RuleNode(static_cast <BlockEntry*> (stm.currentScope()), (yyvsp[(2) - (5)].patVal), (yyvsp[(4) - (5)].stmtVal));
	stm.leaveScope();
	stm.insert(rbe);
	start_rule_scope = 0;
	static_cast <GlobalEntry*> (stm.currentScope())->addRule((yyval.ruleNode));
}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 386 "E--_parser.y++"
    {
	(yyval.ruleNode) = new RuleNode(static_cast <BlockEntry*> (stm.currentScope()), (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].stmtVal));
	stm.leaveScope();
	stm.insert(rbe);
	start_rule_scope = 0;
	static_cast <GlobalEntry*> (stm.currentScope())->addRule((yyval.ruleNode));
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 393 "E--_parser.y++"
    {
	(yyval.ruleNode) = new RuleNode(static_cast <BlockEntry*> (stm.currentScope()), (yyvsp[(2) - (4)].patVal), (yyvsp[(4) - (4)].stmtVal));
	stm.leaveScope();
	stm.insert(rbe);
	start_rule_scope = 0;
	static_cast <GlobalEntry*> (stm.currentScope())->addRule((yyval.ruleNode));
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 402 "E--_parser.y++"
    {
	EventEntry *epl = static_cast <EventEntry*> (stm.lookUp((yyvsp[(1) - (2)].cVal))); //TODO: lookUpScope() ?
	rbe = new RuleBlockEntry();

	if(!start_rule_scope) {
		stm.enterScope(rbe);
		start_rule_scope = 1;
	}

	(yyval.eventEntry) = epl;
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 415 "E--_parser.y++"
    {
	std::vector<VariableEntry*>* vent = new std::vector<VariableEntry*>();
	std::vector<string>::iterator it;

	if ((yyvsp[(1) - (3)].eventEntry) && (yyvsp[(1) - (3)].eventEntry)->symTab()) {
		SymTab::iterator it_sym = (yyvsp[(1) - (3)].eventEntry)->symTab()->begin();

		for (it = (yyvsp[(2) - (3)].strVector)->begin(), it_sym = (yyvsp[(1) - (3)].eventEntry)->symTab()->begin(); it != (yyvsp[(2) - (3)].strVector)->end(), it_sym != (yyvsp[(1) - (3)].eventEntry)->symTab()->end(); ++it, ++it_sym) {
			vent->push_back(new VariableEntry(*it, VariableEntry::VarKind::PARAM_VAR, (*it_sym)->type()));
		}
	}

	(yyval.primPatVal) = new PrimitivePatNode((yyvsp[(1) - (3)].eventEntry), vent, nullptr);
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 429 "E--_parser.y++"
    {
	EventEntry *epl = static_cast <EventEntry*> (stm.lookUp("any")); //TODO: lookUpScope() ?
	rbe = new RuleBlockEntry();

	(yyval.primPatVal) = new PrimitivePatNode(epl, nullptr, nullptr);
	if(!start_rule_scope) {
		stm.enterScope(rbe);
		start_rule_scope = 1;
	}
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 441 "E--_parser.y++"
    { (yyval.patVal) = (yyvsp[(1) - (1)].primPatVal); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 442 "E--_parser.y++"
    { (yyval.patVal) = (yyvsp[(2) - (3)].patVal); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 443 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::SEQ, (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].patVal)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 444 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::STAR, (yyvsp[(1) - (2)].patVal), nullptr); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 445 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::OR, (yyvsp[(1) - (3)].patVal), (yyvsp[(3) - (3)].patVal)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 446 "E--_parser.y++"
    { (yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::NEG, (yyvsp[(2) - (2)].patVal), nullptr); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 449 "E--_parser.y++"
    { (yyval.strVector) = new std::vector<string>(); (yyval.strVector)->push_back((yyvsp[(1) - (1)].cVal)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 450 "E--_parser.y++"
    { if ((yyvsp[(1) - (3)].strVector)) { (yyvsp[(1) - (3)].strVector)->push_back((yyvsp[(3) - (3)].cVal)); (yyval.strVector) = (yyvsp[(1) - (3)].strVector); } else { (yyval.strVector) = new std::vector<string>(); (yyval.strVector)->push_back((yyvsp[(3) - (3)].cVal));  } }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 453 "E--_parser.y++"
    { (yyval.strVector) = nullptr;
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 455 "E--_parser.y++"
    { (yyval.strVector) = (yyvsp[(1) - (1)].strVector); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 458 "E--_parser.y++"
    { (yyval.exprVal) = nullptr;
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 460 "E--_parser.y++"
    { (yyval.exprVal) = (yyvsp[(2) - (2)].exprVal); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 463 "E--_parser.y++"
    { 
	(yyvsp[(1) - (2)].primPatVal)->cond((yyvsp[(2) - (2)].exprVal));
	(yyval.primPatVal) = (yyvsp[(1) - (2)].primPatVal);
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 469 "E--_parser.y++"
    { (yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[(2) - (3)].stmtList)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 472 "E--_parser.y++"
    { (yyval.ifVal) = new IfNode((yyvsp[(2) - (3)].exprVal), (yyvsp[(3) - (3)].stmtVal)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 473 "E--_parser.y++"
    { (yyval.ifVal) = new IfNode((yyvsp[(2) - (5)].exprVal), (yyvsp[(3) - (5)].stmtVal), (yyvsp[(5) - (5)].stmtVal)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 476 "E--_parser.y++"
    { (yyval.stmtList) = nullptr;
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 478 "E--_parser.y++"
    { if ((yyvsp[(1) - (2)].stmtList)) { (yyvsp[(1) - (2)].stmtList)->push_back((yyvsp[(2) - (2)].stmtVal)); (yyval.stmtList) = (yyvsp[(1) - (2)].stmtList); } else { (yyval.stmtList) = new std::list<StmtNode*>(); (yyval.stmtList)->push_back((yyvsp[(2) - (2)].stmtVal)); } }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 479 "E--_parser.y++"
    { errMsg("Syntax error while parsing a statement"); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 482 "E--_parser.y++"
    { (yyval.stmtVal) = nullptr; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 483 "E--_parser.y++"
    { (yyval.stmtVal) = new ReturnStmtNode((yyvsp[(2) - (3)].exprVal), nullptr); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 484 "E--_parser.y++"
    { (yyval.stmtVal) = new ExprStmtNode((yyvsp[(1) - (2)].exprVal)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 485 "E--_parser.y++"
    { (yyval.stmtVal) = new ExprStmtNode((yyvsp[(1) - (2)].exprVal)); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 486 "E--_parser.y++"
    { (yyval.stmtVal) = (yyvsp[(1) - (1)].compoundStmtVal); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 487 "E--_parser.y++"
    { (yyval.stmtVal) = (yyvsp[(1) - (1)].ifVal); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 490 "E--_parser.y++"
    { (yyval.exprList) = new std::vector<ExprNode*>(); (yyval.exprList)->push_back((yyvsp[(1) - (1)].exprVal)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 491 "E--_parser.y++"
    { if((yyvsp[(1) - (3)].exprList)) (yyvsp[(1) - (3)].exprList)->push_back((yyvsp[(3) - (3)].exprVal)); (yyval.exprList) = (yyvsp[(1) - (3)].exprList); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 494 "E--_parser.y++"
    { (yyval.exprList) = nullptr; }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 495 "E--_parser.y++"
    { (yyval.exprList) = (yyvsp[(1) - (1)].exprList); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 498 "E--_parser.y++"
    { (yyval.valVal) = new Value((yyvsp[(1) - (1)].uVal), Type::TypeTag::UINT); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 499 "E--_parser.y++"
    { (yyval.valVal) = new Value((yyvsp[(1) - (1)].dVal)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 500 "E--_parser.y++"
    { (yyval.valVal) = new Value((yyvsp[(1) - (1)].cVal)); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 501 "E--_parser.y++"
    { (yyval.valVal) = new Value(true); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 502 "E--_parser.y++"
    { (yyval.valVal) = new Value(false); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 505 "E--_parser.y++"
    { (yyval.refexpVal) = new RefExprNode((yyvsp[(1) - (1)].cVal), nullptr); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 508 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::ASSIGN, (yyvsp[(1) - (3)].refexpVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 511 "E--_parser.y++"
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[(1) - (4)].cVal));
	(yyval.exprVal) = new InvocationNode(ste, (yyvsp[(3) - (4)].exprList));
}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 518 "E--_parser.y++"
    { (yyval.exprVal) = new ValueNode((yyvsp[(1) - (1)].valVal)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 519 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::PLUS, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 520 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::MINUS, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 521 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::MULT, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 522 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::DIV, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 523 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::MOD, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 524 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::UMINUS, (yyvsp[(2) - (2)].exprVal)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 525 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::BITXOR, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 526 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::BITOR, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 527 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::BITAND, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 528 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::BITNOT, (yyvsp[(2) - (2)].exprVal)); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 529 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::SHL, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 530 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::SHR, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 531 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::GT, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 532 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::LT, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 533 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::GE, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 534 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::LE, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 535 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::EQ, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 536 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::NE, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 537 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::AND, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 538 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::OR, (yyvsp[(1) - (3)].exprVal), (yyvsp[(3) - (3)].exprVal)); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 539 "E--_parser.y++"
    { (yyval.exprVal) = new OpNode(OpNode::OpCode::NOT, (yyvsp[(2) - (2)].exprVal)); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 540 "E--_parser.y++"
    { (yyval.exprVal) = (yyvsp[(2) - (3)].exprVal); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 541 "E--_parser.y++"
    { (yyval.exprVal) = (yyvsp[(1) - (1)].refexpVal); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 542 "E--_parser.y++"
    { (yyval.exprVal) = (yyvsp[(1) - (1)].exprVal); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 543 "E--_parser.y++"
    { (yyval.exprVal) = (yyvsp[(1) - (1)].exprVal); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 544 "E--_parser.y++"
    {          }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 545 "E--_parser.y++"
    {          }
    break;



/* Line 1806 of yacc.c  */
#line 2756 "E--_parser.C"
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
#line 548 "E--_parser.y++"


