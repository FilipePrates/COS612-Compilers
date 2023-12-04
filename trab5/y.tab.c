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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini_js.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int linha = 1, coluna = 0; 

int arrayElCounter = 0;

struct Atributos {
  vector<string> c; // Código

  int linha = 0, coluna = 0;
  int contador = 0;     
  vector<string> valor_default; 
  void clear() {
    c.clear();
    valor_default.clear();
    linha = 0;
    coluna = 0;
    contador = 0;
  }};

enum TipoDecl { Let = 1, Const, Var };
map<int, string> nomeTipoDecl = { 
  { Let, "let" }, 
  { Const, "const" }, 
  { Var, "var" }
};

struct Simbolo {
  TipoDecl tipo;
  int linha;
  int coluna;
  int n_args;
};

int in_func = 0;
int in_scope = 0;
// Tabela de símbolos - agora é uma pilha
vector< map< string, Simbolo > > ts = { map< string, Simbolo >{} }; 
vector<string> funcoes;

vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna );
void checa_simbolo( string nome, bool modificavel );

#define YYSTYPE Atributos

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  return vector<string>{ a } + b;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void print( vector<string> codigo ) {
  for( string s : codigo )
    cout << s << " ";
    
  cout << endl;  
}

#line 173 "y.tab.c"

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
    ID = 258,                      /* ID  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    LET = 261,                     /* LET  */
    CONST = 262,                   /* CONST  */
    VAR = 263,                     /* VAR  */
    FOR = 264,                     /* FOR  */
    FUNCTION = 265,                /* FUNCTION  */
    WHILE = 266,                   /* WHILE  */
    ASM = 267,                     /* ASM  */
    RETURN = 268,                  /* RETURN  */
    BOOLEAN = 269,                 /* BOOLEAN  */
    OBJECT = 270,                  /* OBJECT  */
    FECHA_PARENTESES_FUNC = 271,   /* FECHA_PARENTESES_FUNC  */
    SETA = 272,                    /* SETA  */
    OPEN_BRACKETS_FUNC = 273,      /* OPEN_BRACKETS_FUNC  */
    CDOUBLE = 274,                 /* CDOUBLE  */
    CSTRING = 275,                 /* CSTRING  */
    CINT = 276,                    /* CINT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    ME_IG = 279,                   /* ME_IG  */
    MA_IG = 280,                   /* MA_IG  */
    DIF = 281,                     /* DIF  */
    IGUAL = 282,                   /* IGUAL  */
    MAIS_IGUAL = 283,              /* MAIS_IGUAL  */
    MAIS_MAIS = 284                /* MAIS_MAIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define IF 259
#define ELSE 260
#define LET 261
#define CONST 262
#define VAR 263
#define FOR 264
#define FUNCTION 265
#define WHILE 266
#define ASM 267
#define RETURN 268
#define BOOLEAN 269
#define OBJECT 270
#define FECHA_PARENTESES_FUNC 271
#define SETA 272
#define OPEN_BRACKETS_FUNC 273
#define CDOUBLE 274
#define CSTRING 275
#define CINT 276
#define AND 277
#define OR 278
#define ME_IG 279
#define MA_IG 280
#define DIF 281
#define IGUAL 282
#define MAIS_IGUAL 283
#define MAIS_MAIS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_ASM = 12,                       /* ASM  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_BOOLEAN = 14,                   /* BOOLEAN  */
  YYSYMBOL_OBJECT = 15,                    /* OBJECT  */
  YYSYMBOL_FECHA_PARENTESES_FUNC = 16,     /* FECHA_PARENTESES_FUNC  */
  YYSYMBOL_SETA = 17,                      /* SETA  */
  YYSYMBOL_OPEN_BRACKETS_FUNC = 18,        /* OPEN_BRACKETS_FUNC  */
  YYSYMBOL_CDOUBLE = 19,                   /* CDOUBLE  */
  YYSYMBOL_CSTRING = 20,                   /* CSTRING  */
  YYSYMBOL_CINT = 21,                      /* CINT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_ME_IG = 24,                     /* ME_IG  */
  YYSYMBOL_MA_IG = 25,                     /* MA_IG  */
  YYSYMBOL_DIF = 26,                       /* DIF  */
  YYSYMBOL_IGUAL = 27,                     /* IGUAL  */
  YYSYMBOL_MAIS_IGUAL = 28,                /* MAIS_IGUAL  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_MAIS_MAIS = 37,                 /* MAIS_MAIS  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* '.'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_S = 49,                         /* S  */
  YYSYMBOL_CMDs = 50,                      /* CMDs  */
  YYSYMBOL_CMD = 51,                       /* CMD  */
  YYSYMBOL_EMPILHA_TS = 52,                /* EMPILHA_TS  */
  YYSYMBOL_LISTA_ARGs = 53,                /* LISTA_ARGs  */
  YYSYMBOL_ARGs = 54,                      /* ARGs  */
  YYSYMBOL_FUNCTION_ANON = 55,             /* FUNCTION_ANON  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_FUNCTION_SETA = 57,             /* FUNCTION_SETA  */
  YYSYMBOL_58_2 = 58,                      /* @2  */
  YYSYMBOL_59_3 = 59,                      /* @3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_CMD_FUNCTION = 61,              /* CMD_FUNCTION  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_LISTA_PARAMs = 63,              /* LISTA_PARAMs  */
  YYSYMBOL_PARAMs = 64,                    /* PARAMs  */
  YYSYMBOL_PARAM = 65,                     /* PARAM  */
  YYSYMBOL_CMD_FOR = 66,                   /* CMD_FOR  */
  YYSYMBOL_CMD_WHILE = 67,                 /* CMD_WHILE  */
  YYSYMBOL_PRIM_E = 68,                    /* PRIM_E  */
  YYSYMBOL_CMD_LET = 69,                   /* CMD_LET  */
  YYSYMBOL_LET_VARs = 70,                  /* LET_VARs  */
  YYSYMBOL_LET_VAR = 71,                   /* LET_VAR  */
  YYSYMBOL_CMD_VAR = 72,                   /* CMD_VAR  */
  YYSYMBOL_VAR_VARs = 73,                  /* VAR_VARs  */
  YYSYMBOL_VAR_VAR = 74,                   /* VAR_VAR  */
  YYSYMBOL_CMD_CONST = 75,                 /* CMD_CONST  */
  YYSYMBOL_CONST_VARs = 76,                /* CONST_VARs  */
  YYSYMBOL_CONST_VAR = 77,                 /* CONST_VAR  */
  YYSYMBOL_CMD_IF = 78,                    /* CMD_IF  */
  YYSYMBOL_LVALUEPROP = 79,                /* LVALUEPROP  */
  YYSYMBOL_KEYS_VALUE_PAIRS = 80,          /* KEYS_VALUE_PAIRS  */
  YYSYMBOL_ARRAY_ELEMENTS = 81,            /* ARRAY_ELEMENTS  */
  YYSYMBOL_E = 82                          /* E  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   687

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      39,    45,    34,    32,    44,    33,    40,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    41,
      30,    29,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   123,   124,   127,   128,   129,   130,   131,
     132,   133,   134,   142,   150,   152,   156,   157,   161,   164,
     165,   169,   172,   177,   177,   192,   192,   208,   208,   223,
     223,   240,   240,   255,   256,   259,   276,   295,   300,   307,
     323,   338,   339,   340,   341,   345,   348,   349,   352,   354,
     358,   361,   364,   370,   373,   374,   377,   379,   382,   385,
     390,   393,   394,   397,   400,   403,   408,   420,   430,   431,
     434,   436,   438,   440,   442,   444,   449,   451,   453,   455,
     457,   459,   462,   464,   466,   468,   470,   472,   474,   476,
     478,   480,   482,   484,   486,   488,   490,   492,   494,   496,
     498,   502,   503,   504,   505,   506,   508,   510,   512,   514,
     516,   517
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "IF", "ELSE",
  "LET", "CONST", "VAR", "FOR", "FUNCTION", "WHILE", "ASM", "RETURN",
  "BOOLEAN", "OBJECT", "FECHA_PARENTESES_FUNC", "SETA",
  "OPEN_BRACKETS_FUNC", "CDOUBLE", "CSTRING", "CINT", "AND", "OR", "ME_IG",
  "MA_IG", "DIF", "IGUAL", "MAIS_IGUAL", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "MAIS_MAIS", "'['", "'('", "'.'", "';'", "'{'",
  "'}'", "','", "')'", "']'", "':'", "$accept", "S", "CMDs", "CMD",
  "EMPILHA_TS", "LISTA_ARGs", "ARGs", "FUNCTION_ANON", "$@1",
  "FUNCTION_SETA", "@2", "@3", "$@4", "CMD_FUNCTION", "$@5",
  "LISTA_PARAMs", "PARAMs", "PARAM", "CMD_FOR", "CMD_WHILE", "PRIM_E",
  "CMD_LET", "LET_VARs", "LET_VAR", "CMD_VAR", "VAR_VARs", "VAR_VAR",
  "CMD_CONST", "CONST_VARs", "CONST_VAR", "CMD_IF", "LVALUEPROP",
  "KEYS_VALUE_PAIRS", "ARRAY_ELEMENTS", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -138,    14,   289,  -138,   117,   -27,    15,    18,    29,    -6,
      34,     3,   304,  -138,  -138,  -138,  -138,   440,    10,   466,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,     5,     6,
      16,  -138,    -1,   476,   440,   330,    36,    51,   440,    47,
    -138,    39,    50,  -138,    46,    63,  -138,    59,    88,  -138,
      21,   440,  -138,   101,   603,   154,     1,  -138,   -36,   633,
     288,  -138,  -138,    61,  -138,   508,  -138,  -138,  -138,  -138,
     440,   338,    65,   440,   440,   440,   440,   440,   440,   440,
     440,  -138,   440,   440,   107,  -138,   633,     8,   633,   440,
    -138,   524,   364,    15,   372,    18,   398,    29,    73,  -138,
    -138,  -138,   633,    85,   122,   540,    84,    89,  -138,  -138,
      94,   406,  -138,   330,   123,   122,  -138,   109,   633,    12,
     633,  -138,   647,   647,   647,   154,   154,    49,    49,    49,
     491,    96,   100,   633,  -138,  -138,   110,   633,   166,   289,
      31,   -25,   633,  -138,    32,   633,  -138,    35,   633,  -138,
     440,   122,   126,   112,   289,   432,   118,  -138,    38,   633,
     556,   440,  -138,  -138,  -138,   115,  -138,  -138,   440,  -138,
    -138,   156,  -138,   119,  -138,   120,  -138,   121,   618,   133,
     440,   124,  -138,    42,   588,  -138,  -138,   128,   633,  -138,
     633,   289,  -138,  -138,  -138,   440,   139,   633,  -138,   138,
     141,   101,  -138,  -138,   572,  -138,   207,   101,   151,  -138,
     289,   248,  -138,  -138,   101,  -138,  -138,  -138
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,   105,     0,     0,     0,     0,     0,
      23,     0,     0,   103,   101,   104,   102,     0,     0,    18,
      17,    18,     3,   110,   111,     5,    10,    11,     0,     0,
       0,     9,   106,     0,     0,     0,     0,     0,     0,    48,
      45,    47,     0,    60,    62,    56,    53,    55,     0,    31,
       0,     0,    23,     0,     0,    99,     0,   108,     0,    76,
     105,    34,    29,    33,    36,     0,     4,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,    20,     0,    14,    88,     0,    82,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,    44,     0,    18,     0,     0,     0,    12,    77,
       0,     0,   109,     0,     0,     0,   107,     0,    89,     0,
      85,    16,    97,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    19,    22,    69,    83,     0,    26,     0,     0,
       0,   111,    49,    46,     0,    63,    61,     0,    57,    54,
       0,    18,    37,     0,     0,     0,     0,    78,     0,    79,
      38,     0,    35,    15,    86,     0,    68,   100,     0,    84,
      28,    67,    50,     0,    64,     0,    58,     0,     0,     0,
       0,     0,    40,     0,    70,    13,    80,     0,    30,    87,
      21,     0,    51,    65,    59,     0,     0,    38,     4,    71,
       0,     0,    81,    66,     0,     4,     0,     0,    72,    73,
       0,     0,    24,    74,     0,    39,    32,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,   -65,  -137,   144,  -138,  -138,  -138,  -138,   104,
    -138,  -138,  -138,  -138,  -138,  -101,  -138,    82,  -138,  -138,
    -138,   150,   108,  -138,   152,   105,  -138,   155,   111,  -138,
    -138,  -138,   -47,  -138,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    22,    61,   131,   132,    23,    50,    24,
      36,    37,   114,    25,   103,    62,    63,    64,    26,    27,
      98,    28,    40,    41,    29,    46,    47,    30,    43,    44,
      31,    32,   107,    58,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   117,   171,   153,   106,    55,    59,    65,   111,   110,
     112,   106,    38,     4,     3,   106,   -52,   182,    39,   -52,
      52,    42,    86,    88,    13,   138,    91,    70,    71,    14,
      15,    16,    45,    48,   106,   106,   102,    49,   106,   105,
     136,   106,    51,    17,   109,   106,    67,    68,    18,    19,
     179,   135,    56,    89,   203,   164,    57,    69,   118,   120,
     104,   122,   123,   124,   125,   126,   127,   128,   129,    90,
     130,   133,   165,   215,   172,   174,    92,   137,   176,    94,
     142,   186,   145,    93,   148,   199,    81,    82,    83,    84,
      95,     4,    96,   173,     6,     7,     8,   175,    52,   159,
     177,   160,    13,    97,   106,   115,   121,    14,    15,    16,
     134,   187,     4,     5,   150,     6,     7,     8,     9,    10,
      11,    17,    12,    13,   151,   152,    18,    19,    14,    15,
      16,   155,   156,   206,   -25,   -27,   200,   157,   178,   161,
     211,   167,    17,   184,   168,    34,    35,    18,    19,   188,
      20,    21,   163,   169,   209,   180,   190,   181,   189,   185,
     213,   191,   192,   193,   194,    66,   198,   217,   197,     4,
       5,   202,     6,     7,     8,     9,    10,    11,   196,    12,
      13,   205,   207,   204,   208,    14,    15,    16,    78,    79,
      80,    81,    82,    83,    84,   214,   141,   162,    99,    17,
     100,   143,   149,   101,    18,    19,   146,    20,    21,   170,
       4,     5,     0,     6,     7,     8,     9,    10,    11,     0,
      12,    13,     0,     0,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    18,    19,     0,    20,    21,
     212,     4,     5,     0,     6,     7,     8,     9,    10,    11,
       0,    12,    13,     0,     0,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,     0,    20,
      21,   216,     4,     5,     0,     6,     7,     8,     9,    10,
      11,     0,    12,    13,   -37,   -25,   -27,     4,    14,    15,
      16,     0,     0,     0,    52,     0,    34,   113,    13,     0,
       0,     0,    17,    14,    15,    16,     0,    18,    19,     0,
      20,    21,   -37,     4,     0,     0,     0,    17,     0,     0,
      52,     4,    18,    19,    13,     0,    53,     0,    52,    14,
      15,    16,    13,     0,     0,     0,     0,    14,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     4,    18,    19,
       0,    17,    87,     0,    52,     4,    18,    19,    13,     0,
     119,     0,    52,    14,    15,    16,    13,     0,     0,     0,
       0,    14,    15,    16,     0,     0,     0,    17,     0,     0,
       0,     4,    18,    19,     0,    17,   140,     0,    52,     4,
      18,    19,    13,     0,   144,     0,    52,    14,    15,    16,
      13,     0,     0,     0,     0,    14,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     4,    18,    19,     0,    17,
     147,     0,    52,     4,    18,    19,    13,     0,   158,     0,
      52,    14,    15,    16,    13,     0,     0,     0,     0,    14,
      15,    16,     0,     0,     0,    17,     0,     0,     0,    60,
      18,    19,     0,    17,   183,     0,    52,     0,    18,    19,
      13,     0,     0,     0,     0,    14,    15,    16,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,    73,    18,    19,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    73,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,    73,     0,   166,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    73,     0,   116,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,    73,     0,   139,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,    73,     0,   154,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    73,
       0,   -82,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    73,     0,   210,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      73,     0,   201,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   108,    73,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   195,
      73,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   -83,     0,     0,   -83,   -83,    76,
      77,    78,    79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,    66,   139,   104,     3,    17,    18,    19,    44,    56,
      46,     3,    39,     3,     0,     3,    41,   154,     3,    44,
      10,     3,    34,    35,    14,    90,    38,    28,    29,    19,
      20,    21,     3,    39,     3,     3,    48,     3,     3,    51,
      87,     3,    39,    33,    43,     3,    41,    41,    38,    39,
     151,    43,    42,    17,   191,    43,    46,    41,    70,    71,
      39,    73,    74,    75,    76,    77,    78,    79,    80,    18,
      82,    83,   119,   210,    43,    43,    29,    89,    43,    29,
      92,    43,    94,    44,    96,    43,    37,    38,    39,    40,
      44,     3,    29,   140,     6,     7,     8,   144,    10,   111,
     147,   113,    14,    44,     3,    44,    41,    19,    20,    21,
       3,   158,     3,     4,    41,     6,     7,     8,     9,    10,
      11,    33,    13,    14,    39,     3,    38,    39,    19,    20,
      21,    47,    43,   198,    17,    18,   183,    43,   150,    16,
     205,    45,    33,   155,    44,    28,    29,    38,    39,   161,
      41,    42,    43,    43,   201,    29,   168,    45,    43,    41,
     207,     5,    43,    43,    43,    21,    42,   214,   180,     3,
       4,    43,     6,     7,     8,     9,    10,    11,    45,    13,
      14,    42,    44,   195,    43,    19,    20,    21,    34,    35,
      36,    37,    38,    39,    40,    44,    92,   115,    48,    33,
      48,    93,    97,    48,    38,    39,    95,    41,    42,    43,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    16,    17,    18,     3,    19,    20,
      21,    -1,    -1,    -1,    10,    -1,    28,    29,    14,    -1,
      -1,    -1,    33,    19,    20,    21,    -1,    38,    39,    -1,
      41,    42,    44,     3,    -1,    -1,    -1,    33,    -1,    -1,
      10,     3,    38,    39,    14,    -1,    42,    -1,    10,    19,
      20,    21,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
      -1,    -1,    -1,    33,    -1,    -1,    -1,     3,    38,    39,
      -1,    33,    42,    -1,    10,     3,    38,    39,    14,    -1,
      42,    -1,    10,    19,    20,    21,    14,    -1,    -1,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    33,    -1,    -1,
      -1,     3,    38,    39,    -1,    33,    42,    -1,    10,     3,
      38,    39,    14,    -1,    42,    -1,    10,    19,    20,    21,
      14,    -1,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    33,    -1,    -1,    -1,     3,    38,    39,    -1,    33,
      42,    -1,    10,     3,    38,    39,    14,    -1,    42,    -1,
      10,    19,    20,    21,    14,    -1,    -1,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    33,    -1,    -1,    -1,     3,
      38,    39,    -1,    33,    42,    -1,    10,    -1,    38,    39,
      14,    -1,    -1,    -1,    -1,    19,    20,    21,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    27,    38,    39,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    27,    -1,    46,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    27,    -1,    45,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    27,    -1,    45,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    27,    -1,    45,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    27,
      -1,    45,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    27,    -1,    45,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      27,    -1,    44,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    13,    14,    19,    20,    21,    33,    38,    39,
      41,    42,    51,    55,    57,    61,    66,    67,    69,    72,
      75,    78,    79,    82,    28,    29,    58,    59,    39,     3,
      70,    71,     3,    76,    77,     3,    73,    74,    39,     3,
      56,    39,    10,    42,    82,    82,    42,    46,    81,    82,
       3,    52,    63,    64,    65,    82,    52,    41,    41,    41,
      28,    29,    12,    27,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    82,    42,    82,    17,
      18,    82,    29,    44,    29,    44,    29,    44,    68,    69,
      72,    75,    82,    62,    39,    82,     3,    80,    41,    43,
      80,    44,    46,    29,    60,    44,    45,    50,    82,    42,
      82,    41,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    53,    54,    82,     3,    43,    80,    82,    50,    45,
      42,    57,    82,    70,    42,    82,    76,    42,    82,    73,
      41,    39,     3,    63,    45,    47,    43,    43,    42,    82,
      82,    16,    65,    43,    43,    80,    46,    45,    44,    43,
      43,    51,    43,    80,    43,    80,    43,    80,    82,    63,
      29,    45,    51,    42,    82,    41,    43,    80,    82,    43,
      82,     5,    43,    43,    43,    41,    45,    82,    42,    43,
      80,    44,    43,    51,    82,    42,    50,    44,    43,    80,
      45,    50,    43,    80,    44,    51,    43,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    56,    55,    58,    57,    59,    57,    60,
      57,    62,    61,    63,    63,    64,    64,    65,    65,    66,
      67,    68,    68,    68,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    72,    73,    73,    74,    74,    74,    74,
      75,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     2,     2,     1,
       1,     1,     3,     5,     2,     4,     3,     1,     0,     1,
       0,     3,     1,     0,     8,     0,     4,     0,     5,     0,
       5,     0,     9,     1,     1,     3,     1,     1,     3,     9,
       5,     1,     1,     1,     1,     2,     3,     1,     1,     3,
       4,     5,     3,     2,     3,     1,     1,     3,     4,     5,
       2,     3,     1,     3,     4,     5,     7,     5,     4,     3,
       3,     4,     5,     5,     6,     7,     1,     2,     3,     3,
       4,     5,     3,     4,     5,     3,     4,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       1,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
  case 2: /* S: CMDs  */
#line 120 "mini_js.y"
         { print(resolve_enderecos( yyvsp[0].c + "." + funcoes)); }
#line 1575 "y.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 123 "mini_js.y"
                 { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1581 "y.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 124 "mini_js.y"
                 { yyval.clear();}
#line 1587 "y.tab.c"
    break;

  case 12: /* CMD: RETURN E ';'  */
#line 135 "mini_js.y"
      { if (in_func) {
        yyval.c = yyvsp[-1].c + "'&retorno'" + "@" + "~"; 
       }else{
        cerr << "Erro: Não é permitido 'return' fora de funções." << endl;
        exit( 1 );    
       }
      }
#line 1599 "y.tab.c"
    break;

  case 13: /* CMD: RETURN '{' KEYS_VALUE_PAIRS '}' ';'  */
#line 143 "mini_js.y"
      { if (in_func) {
        yyval.c = vector<string>{"{}"} + yyvsp[-2].c + "'&retorno'" + "@" + "~";
       }else{
        cerr << "Erro: Não é permitido 'return' fora de funções." << endl;
        exit( 1 );    
       }
      }
#line 1611 "y.tab.c"
    break;

  case 14: /* CMD: E ';'  */
#line 151 "mini_js.y"
      { yyval.c = yyvsp[-1].c + "^"; }
#line 1617 "y.tab.c"
    break;

  case 15: /* CMD: '{' EMPILHA_TS CMDs '}'  */
#line 153 "mini_js.y"
      { 
        ts.pop_back();
        yyval.c = vector<string>{"<{"} + yyvsp[-1].c + vector<string>{"}>"}; }
#line 1625 "y.tab.c"
    break;

  case 16: /* CMD: E ASM ';'  */
#line 156 "mini_js.y"
                        { yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 1631 "y.tab.c"
    break;

  case 17: /* CMD: ';'  */
#line 157 "mini_js.y"
          { yyval.clear();}
#line 1637 "y.tab.c"
    break;

  case 18: /* EMPILHA_TS: %empty  */
#line 161 "mini_js.y"
             { ts.push_back( map< string, Simbolo >{} );}
#line 1643 "y.tab.c"
    break;

  case 20: /* LISTA_ARGs: %empty  */
#line 165 "mini_js.y"
          { ts.push_back( map< string, Simbolo >{} ); 
              yyval.clear(); }
#line 1650 "y.tab.c"
    break;

  case 21: /* ARGs: ARGs ',' E  */
#line 170 "mini_js.y"
       { yyval.c = yyvsp[-2].c + yyvsp[0].c;
         yyval.contador = yyvsp[-2].contador + 1; }
#line 1657 "y.tab.c"
    break;

  case 22: /* ARGs: E  */
#line 173 "mini_js.y"
       { yyval.c = yyvsp[0].c;
         yyval.contador = 1; }
#line 1664 "y.tab.c"
    break;

  case 23: /* $@1: %empty  */
#line 177 "mini_js.y"
                         { in_func++; }
#line 1670 "y.tab.c"
    break;

  case 24: /* FUNCTION_ANON: FUNCTION $@1 '(' LISTA_PARAMs ')' '{' CMDs '}'  */
#line 179 "mini_js.y"
           { 
             string lbl_endereco_funcao = gera_label( "func_anon" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             yyval.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";
             funcoes = funcoes + definicao_lbl_endereco_funcao + yyvsp[-4].c + yyvsp[-1].c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func--;
           }
#line 1686 "y.tab.c"
    break;

  case 25: /* @2: %empty  */
#line 192 "mini_js.y"
                   { in_func++; ts.push_back( map< string, Simbolo >{} ); 
            declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna );
            yyval.c = yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
          }
#line 1695 "y.tab.c"
    break;

  case 26: /* FUNCTION_SETA: ID @2 SETA E  */
#line 196 "mini_js.y"
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
            yyval.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";

             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              yyvsp[-2].c + yyvsp[0].c + "'&retorno'" + "@" + "~";
            ts.pop_back();
            in_func--;
           }
#line 1712 "y.tab.c"
    break;

  case 27: /* @3: %empty  */
#line 208 "mini_js.y"
                { in_func++; ts.push_back( map< string, Simbolo >{} ); 
            declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna );
            yyval.c = yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
          }
#line 1721 "y.tab.c"
    break;

  case 28: /* FUNCTION_SETA: ID @3 OPEN_BRACKETS_FUNC CMDs '}'  */
#line 212 "mini_js.y"
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
            yyval.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";
             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              yyvsp[-3].c + yyvsp[-1].c + "'&retorno'" + "@" + "~"; 
            ts.pop_back();
            in_func--;
           }
#line 1737 "y.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 223 "mini_js.y"
                              { in_func++; }
#line 1743 "y.tab.c"
    break;

  case 30: /* FUNCTION_SETA: '(' LISTA_PARAMs $@4 FECHA_PARENTESES_FUNC E  */
#line 224 "mini_js.y"
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             yyval.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";

             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              yyvsp[-3].c + yyvsp[0].c + "'&retorno'" + "@" + "~"; 

            ts.pop_back();
            in_func--; 
           }
#line 1761 "y.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 240 "mini_js.y"
                           { declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); in_func++; }
#line 1767 "y.tab.c"
    break;

  case 32: /* CMD_FUNCTION: FUNCTION ID $@5 '(' LISTA_PARAMs ')' '{' CMDs '}'  */
#line 242 "mini_js.y"
           { 
             string lbl_endereco_funcao = gera_label( "func_" + yyvsp[-7].c[0] );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             yyval.c = yyvsp[-7].c + "&" + yyvsp[-7].c + "{}"  + "=" + "'&funcao'" +
                    lbl_endereco_funcao + "[=]" + "^";
             funcoes = funcoes + definicao_lbl_endereco_funcao + yyvsp[-4].c + yyvsp[-1].c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func--;
           }
#line 1783 "y.tab.c"
    break;

  case 34: /* LISTA_PARAMs: EMPILHA_TS  */
#line 256 "mini_js.y"
                         { yyval.clear(); }
#line 1789 "y.tab.c"
    break;

  case 35: /* PARAMs: PARAMs ',' PARAM  */
#line 260 "mini_js.y"
       { // Cria var local
         declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); 
         yyval.c = yyvsp[-2].c + yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + to_string( yyvsp[-2].contador )
                + "[@]" + "=" + "^"; 
         if( yyvsp[0].valor_default.size() > 0 ) {
          string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          yyval.c = yyval.c + declara_var( Var, "placeholder", 1, 1 ) +
          yyvsp[0].c + "@" + "placeholder" + "@" + "!=" +
          lbl_true + "?" + yyvsp[0].c + yyvsp[0].valor_default + "=" + "^" +
          lbl_fim_if + "#" + definicao_lbl_true + definicao_lbl_fim_if;
         }
         yyval.contador = yyvsp[-2].contador + yyvsp[0].contador; 
       }
#line 1810 "y.tab.c"
    break;

  case 36: /* PARAMs: PARAM  */
#line 277 "mini_js.y"
       { // a & a arguments @ 0 [@] = ^
         ts.push_back( map< string, Simbolo >{} ); 
         declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); 
         yyval.c = yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
                
         if( yyvsp[0].valor_default.size() > 0 ) {
           string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
           yyval.c = yyval.c + declara_var( Var, "placeholder", 1, 1 ) +
           yyvsp[0].c + "@" + "placeholder" + "@" + "!=" +
            lbl_true + "?" + yyvsp[0].c + yyvsp[0].valor_default + "=" + "^" +
            lbl_fim_if + "#" + definicao_lbl_true + definicao_lbl_fim_if;          }
         yyval.contador = 1; 
       }
#line 1831 "y.tab.c"
    break;

  case 37: /* PARAM: ID  */
#line 296 "mini_js.y"
      { yyval.c = yyvsp[0].c;      
        yyval.contador = 1;
        yyval.valor_default.clear();
      }
#line 1840 "y.tab.c"
    break;

  case 38: /* PARAM: ID '=' E  */
#line 301 "mini_js.y"
      { // Código do IF
        yyval.c = yyvsp[-2].c;
        yyval.contador = 1;
        yyval.valor_default = yyvsp[0].c;         
      }
#line 1850 "y.tab.c"
    break;

  case 39: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 308 "mini_js.y"
        { string lbl_fim_for = gera_label( "fim_for" );
          string lbl_condicao_for = gera_label( "condicao_for" );
          string lbl_comando_for = gera_label( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;
          
          yyval.c = yyvsp[-6].c + definicao_lbl_condicao_for +
                 yyvsp[-4].c + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + yyvsp[0].c + 
                 yyvsp[-2].c + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
#line 1868 "y.tab.c"
    break;

  case 40: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 324 "mini_js.y"
    { string lbl_comeco_while = gera_label("comeco_while");
      string lbl_fim_while = gera_label("fim_while");
      string lbl_condicao_while = gera_label("condicao_while");
      string definicao_lbl_comeco_while = ":" + lbl_comeco_while;
      string definicao_lbl_fim_while = ":" + lbl_fim_while;
      string definicao_lbl_condicao_while = ":" + lbl_condicao_while;
      yyval.c = definicao_lbl_condicao_while + yyvsp[-2].c +
              lbl_comeco_while + "?" +
              lbl_fim_while + "#" +
              definicao_lbl_comeco_while + yyvsp[0].c +
              lbl_condicao_while + "#" +
              definicao_lbl_fim_while;}
#line 1885 "y.tab.c"
    break;

  case 44: /* PRIM_E: E  */
#line 342 "mini_js.y"
         { yyval.c = yyvsp[0].c + "^"; }
#line 1891 "y.tab.c"
    break;

  case 45: /* CMD_LET: LET LET_VARs  */
#line 345 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1897 "y.tab.c"
    break;

  case 46: /* LET_VARs: LET_VAR ',' LET_VARs  */
#line 348 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1903 "y.tab.c"
    break;

  case 48: /* LET_VAR: ID  */
#line 353 "mini_js.y"
          { yyval.c = declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna );}
#line 1909 "y.tab.c"
    break;

  case 49: /* LET_VAR: ID '=' E  */
#line 355 "mini_js.y"
          { 
            yyval.c = declara_var( Let, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                   yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1917 "y.tab.c"
    break;

  case 50: /* LET_VAR: ID '=' '{' '}'  */
#line 359 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 1924 "y.tab.c"
    break;

  case 51: /* LET_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 362 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 1931 "y.tab.c"
    break;

  case 52: /* LET_VAR: ID '=' FUNCTION_SETA  */
#line 365 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
            yyvsp[-2].c + yyvsp[0].c + "=" + "^";}
#line 1938 "y.tab.c"
    break;

  case 53: /* CMD_VAR: VAR VAR_VARs  */
#line 370 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1944 "y.tab.c"
    break;

  case 54: /* VAR_VARs: VAR_VAR ',' VAR_VARs  */
#line 373 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1950 "y.tab.c"
    break;

  case 56: /* VAR_VAR: ID  */
#line 378 "mini_js.y"
          { yyval.c = declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1956 "y.tab.c"
    break;

  case 57: /* VAR_VAR: ID '=' E  */
#line 380 "mini_js.y"
          {  yyval.c = declara_var( Var, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                    yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1963 "y.tab.c"
    break;

  case 58: /* VAR_VAR: ID '=' '{' '}'  */
#line 383 "mini_js.y"
            { yyval.c = declara_var( Var, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 1970 "y.tab.c"
    break;

  case 59: /* VAR_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 386 "mini_js.y"
            { yyval.c = declara_var( Var, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 1977 "y.tab.c"
    break;

  case 60: /* CMD_CONST: CONST CONST_VARs  */
#line 390 "mini_js.y"
                            { yyval.c = yyvsp[0].c; }
#line 1983 "y.tab.c"
    break;

  case 61: /* CONST_VARs: CONST_VAR ',' CONST_VARs  */
#line 393 "mini_js.y"
                                      { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1989 "y.tab.c"
    break;

  case 63: /* CONST_VAR: ID '=' E  */
#line 398 "mini_js.y"
            { yyval.c = declara_var( Const, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                     yyvsp[-2].c + yyvsp[0].c + "=" + "^";}
#line 1996 "y.tab.c"
    break;

  case 64: /* CONST_VAR: ID '=' '{' '}'  */
#line 401 "mini_js.y"
            { yyval.c = declara_var( Const, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 2003 "y.tab.c"
    break;

  case 65: /* CONST_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 404 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 2010 "y.tab.c"
    break;

  case 66: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 409 "mini_js.y"
         { string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
            yyval.c = yyvsp[-4].c +                       // Codigo da expressão
                   lbl_true + "?" +             // Código do IF
                   yyvsp[0].c + lbl_fim_if + "#" +    // Código do False
                   definicao_lbl_true + yyvsp[-2].c +  // Código do True
                   definicao_lbl_fim_if         // Fim do IF
                   ;
         }
#line 2026 "y.tab.c"
    break;

  case 67: /* CMD_IF: IF '(' E ')' CMD  */
#line 421 "mini_js.y"
        { string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          yyval.c = yyvsp[-2].c + lbl_true + "?" + lbl_fim_if + "#" +
          definicao_lbl_true + yyvsp[0].c + definicao_lbl_fim_if;
        }
#line 2038 "y.tab.c"
    break;

  case 68: /* LVALUEPROP: E '[' E ']'  */
#line 430 "mini_js.y"
                         { yyval.c = yyvsp[-3].c + yyvsp[-1].c; }
#line 2044 "y.tab.c"
    break;

  case 69: /* LVALUEPROP: E '.' ID  */
#line 431 "mini_js.y"
                       { yyval.c = yyvsp[-2].c+ yyvsp[0].c; }
#line 2050 "y.tab.c"
    break;

  case 70: /* KEYS_VALUE_PAIRS: ID ':' E  */
#line 435 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[<=]";}
#line 2056 "y.tab.c"
    break;

  case 71: /* KEYS_VALUE_PAIRS: ID ':' '{' '}'  */
#line 437 "mini_js.y"
                  { yyval.c = yyvsp[-3].c + "{}" + "[<=]";}
#line 2062 "y.tab.c"
    break;

  case 72: /* KEYS_VALUE_PAIRS: ID ':' '{' KEYS_VALUE_PAIRS '}'  */
#line 439 "mini_js.y"
                  { yyval.c = yyvsp[-4].c + "{}" + yyvsp[-1].c + "[<=]";}
#line 2068 "y.tab.c"
    break;

  case 73: /* KEYS_VALUE_PAIRS: ID ':' E ',' KEYS_VALUE_PAIRS  */
#line 441 "mini_js.y"
                  {yyval.c =  yyvsp[0].c + yyvsp[-4].c + yyvsp[-2].c + "[<=]"; }
#line 2074 "y.tab.c"
    break;

  case 74: /* KEYS_VALUE_PAIRS: ID ':' '{' '}' ',' KEYS_VALUE_PAIRS  */
#line 443 "mini_js.y"
                  {yyval.c =  yyvsp[0].c + yyvsp[-5].c + "{}" + "[<=]"; }
#line 2080 "y.tab.c"
    break;

  case 75: /* KEYS_VALUE_PAIRS: ID ':' '{' KEYS_VALUE_PAIRS '}' ',' KEYS_VALUE_PAIRS  */
#line 445 "mini_js.y"
                  { yyval.c = yyvsp[0].c + yyvsp[-6].c + "{}" + yyvsp[-3].c + "[<=]";}
#line 2086 "y.tab.c"
    break;

  case 76: /* ARRAY_ELEMENTS: E  */
#line 450 "mini_js.y"
               { yyval.c = vector<string>{"[]"} + to_string(arrayElCounter) + yyvsp[0].c + "[<=]"; arrayElCounter++;}
#line 2092 "y.tab.c"
    break;

  case 77: /* ARRAY_ELEMENTS: '{' '}'  */
#line 452 "mini_js.y"
                { yyval.c = vector<string>{"[]"} + to_string(arrayElCounter) + "{}" + "[<=]"; arrayElCounter++;}
#line 2098 "y.tab.c"
    break;

  case 78: /* ARRAY_ELEMENTS: '{' KEYS_VALUE_PAIRS '}'  */
#line 454 "mini_js.y"
                { yyval.c = vector<string>{"[]"} + to_string(arrayElCounter) + "{}" + yyvsp[-1].c + "[<=]"; arrayElCounter++;}
#line 2104 "y.tab.c"
    break;

  case 79: /* ARRAY_ELEMENTS: ARRAY_ELEMENTS ',' E  */
#line 456 "mini_js.y"
               { yyval.c = yyvsp[-2].c + to_string(arrayElCounter) + yyvsp[0].c + "[<=]"; arrayElCounter++;}
#line 2110 "y.tab.c"
    break;

  case 80: /* ARRAY_ELEMENTS: ARRAY_ELEMENTS ',' '{' '}'  */
#line 458 "mini_js.y"
                { yyval.c = yyvsp[-3].c + to_string(arrayElCounter) + "{}" + "[<=]"; arrayElCounter++;}
#line 2116 "y.tab.c"
    break;

  case 81: /* ARRAY_ELEMENTS: ARRAY_ELEMENTS ',' '{' KEYS_VALUE_PAIRS '}'  */
#line 460 "mini_js.y"
                { yyval.c = yyvsp[-4].c + to_string(arrayElCounter)  + "{}" + yyvsp[-1].c + "[<=]"; arrayElCounter++;}
#line 2122 "y.tab.c"
    break;

  case 82: /* E: ID '=' E  */
#line 463 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 2128 "y.tab.c"
    break;

  case 83: /* E: ID '=' '{' '}'  */
#line 465 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + "{}" + "="; }
#line 2134 "y.tab.c"
    break;

  case 84: /* E: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 467 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-4].c[0], true );  yyval.c = yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c; }
#line 2140 "y.tab.c"
    break;

  case 85: /* E: LVALUEPROP '=' E  */
#line 469 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "[<=]" + "^" + yyvsp[0].c; }
#line 2146 "y.tab.c"
    break;

  case 86: /* E: LVALUEPROP '=' '{' '}'  */
#line 471 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + "{}" + "[<=]"; }
#line 2152 "y.tab.c"
    break;

  case 87: /* E: LVALUEPROP '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 473 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[-4].c[0], true );  yyval.c = yyvsp[-4].c  + "{}" + yyvsp[-1].c + "[<=]" + "[<=]"; }
#line 2158 "y.tab.c"
    break;

  case 88: /* E: ID MAIS_IGUAL E  */
#line 475 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "+" + "="; }
#line 2164 "y.tab.c"
    break;

  case 89: /* E: LVALUEPROP MAIS_IGUAL E  */
#line 477 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[-2].c + "[@]" + yyvsp[0].c + "+" + "[<=]"; }
#line 2170 "y.tab.c"
    break;

  case 90: /* E: E '<' E  */
#line 479 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2176 "y.tab.c"
    break;

  case 91: /* E: E '>' E  */
#line 481 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2182 "y.tab.c"
    break;

  case 92: /* E: E '+' E  */
#line 483 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2188 "y.tab.c"
    break;

  case 93: /* E: E '-' E  */
#line 485 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2194 "y.tab.c"
    break;

  case 94: /* E: E '*' E  */
#line 487 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2200 "y.tab.c"
    break;

  case 95: /* E: E '/' E  */
#line 489 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2206 "y.tab.c"
    break;

  case 96: /* E: E '%' E  */
#line 491 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2212 "y.tab.c"
    break;

  case 97: /* E: E IGUAL E  */
#line 493 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 2218 "y.tab.c"
    break;

  case 98: /* E: E MAIS_MAIS  */
#line 495 "mini_js.y"
    { yyval.c = vector<string>{} + yyvsp[-1].c[0] + yyvsp[-1].c[0] + "@" + "1" + "+" + "="; }
#line 2224 "y.tab.c"
    break;

  case 99: /* E: '-' E  */
#line 497 "mini_js.y"
    { yyval.c = "0" + yyvsp[0].c + yyvsp[-1].c; }
#line 2230 "y.tab.c"
    break;

  case 100: /* E: E '(' LISTA_ARGs ')'  */
#line 499 "mini_js.y"
    { 
    yyval.c = yyvsp[-1].c + to_string( yyvsp[-1].contador ) + yyvsp[-3].c + "$";
    }
#line 2238 "y.tab.c"
    break;

  case 105: /* E: ID  */
#line 507 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "@"; }
#line 2244 "y.tab.c"
    break;

  case 106: /* E: LVALUEPROP  */
#line 509 "mini_js.y"
    { if (!in_func) checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "[@]"; }
#line 2250 "y.tab.c"
    break;

  case 107: /* E: '(' E ')'  */
#line 511 "mini_js.y"
    { yyval.c = yyvsp[-1].c; }
#line 2256 "y.tab.c"
    break;

  case 108: /* E: '[' ']'  */
#line 513 "mini_js.y"
    { yyval.c = {"[]"}; }
#line 2262 "y.tab.c"
    break;

  case 109: /* E: '[' ARRAY_ELEMENTS ']'  */
#line 515 "mini_js.y"
  { yyval.c = yyvsp[-1].c; arrayElCounter = 0;}
#line 2268 "y.tab.c"
    break;


#line 2272 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 521 "mini_js.y"


#include "lex.yy.c"
vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna ) {
  auto& topo = ts.back(); 
  if( topo.count( nome ) == 0 ) {
    topo[nome] = Simbolo{ tipo, linha, coluna };
    vector<string> returnVector;
    returnVector.push_back(nome);
    returnVector.push_back("&");
    return returnVector;
  }
  else if( tipo == Var && topo[nome].tipo == Var ) {
    topo[nome] = Simbolo{ tipo, linha, coluna };
    vector<string> emptyVector;
    return emptyVector;
  } 
  else {
    cerr << "Erro: a variável '" << nome << "' já foi declarada na linha " << topo[nome].linha << "." << endl;
    exit( 1 );     
  }
}

void checa_simbolo( string nome, bool modificavel ) {
  if(in_func == 0){
    for( int i = ts.size() - 1; i >= 0; i-- ) {  
      auto& atual = ts[i];
      
      if( atual.count( nome ) > 0 ) {
        if( modificavel && atual[nome].tipo == Const ) {
          cerr << "Variavel '" << nome << "' não pode ser modificada." << endl;
          exit( 1 );     
        }
        else 
          return;
      }
    }

    cerr << "Variavel '" << nome << "' não declarada." << endl;
    exit( 1 );     
  }
}

void yyerror( const char* st ) {
   cerr << st << endl; 
   cerr << "Proximo a: " << yytext << endl;
   exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}
