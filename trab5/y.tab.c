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
    CDOUBLE = 272,                 /* CDOUBLE  */
    CSTRING = 273,                 /* CSTRING  */
    CINT = 274,                    /* CINT  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    ME_IG = 277,                   /* ME_IG  */
    MA_IG = 278,                   /* MA_IG  */
    DIF = 279,                     /* DIF  */
    IGUAL = 280,                   /* IGUAL  */
    MAIS_IGUAL = 281,              /* MAIS_IGUAL  */
    MAIS_MAIS = 282                /* MAIS_MAIS  */
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
#define CDOUBLE 272
#define CSTRING 273
#define CINT 274
#define AND 275
#define OR 276
#define ME_IG 277
#define MA_IG 278
#define DIF 279
#define IGUAL 280
#define MAIS_IGUAL 281
#define MAIS_MAIS 282

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
  YYSYMBOL_CDOUBLE = 17,                   /* CDOUBLE  */
  YYSYMBOL_CSTRING = 18,                   /* CSTRING  */
  YYSYMBOL_CINT = 19,                      /* CINT  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_ME_IG = 22,                     /* ME_IG  */
  YYSYMBOL_MA_IG = 23,                     /* MA_IG  */
  YYSYMBOL_DIF = 24,                       /* DIF  */
  YYSYMBOL_IGUAL = 25,                     /* IGUAL  */
  YYSYMBOL_MAIS_IGUAL = 26,                /* MAIS_IGUAL  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_MAIS_MAIS = 35,                 /* MAIS_MAIS  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* '.'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_S = 47,                         /* S  */
  YYSYMBOL_CMDs = 48,                      /* CMDs  */
  YYSYMBOL_CMD = 49,                       /* CMD  */
  YYSYMBOL_EMPILHA_TS = 50,                /* EMPILHA_TS  */
  YYSYMBOL_LISTA_ARGs = 51,                /* LISTA_ARGs  */
  YYSYMBOL_ARGs = 52,                      /* ARGs  */
  YYSYMBOL_FUNCTION_ANON = 53,             /* FUNCTION_ANON  */
  YYSYMBOL_54_1 = 54,                      /* @1  */
  YYSYMBOL_CMD_FUNCTION = 55,              /* CMD_FUNCTION  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_LISTA_PARAMs = 57,              /* LISTA_PARAMs  */
  YYSYMBOL_PARAMs = 58,                    /* PARAMs  */
  YYSYMBOL_PARAM = 59,                     /* PARAM  */
  YYSYMBOL_CMD_FOR = 60,                   /* CMD_FOR  */
  YYSYMBOL_CMD_WHILE = 61,                 /* CMD_WHILE  */
  YYSYMBOL_PRIM_E = 62,                    /* PRIM_E  */
  YYSYMBOL_CMD_LET = 63,                   /* CMD_LET  */
  YYSYMBOL_LET_VARs = 64,                  /* LET_VARs  */
  YYSYMBOL_LET_VAR = 65,                   /* LET_VAR  */
  YYSYMBOL_CMD_VAR = 66,                   /* CMD_VAR  */
  YYSYMBOL_VAR_VARs = 67,                  /* VAR_VARs  */
  YYSYMBOL_VAR_VAR = 68,                   /* VAR_VAR  */
  YYSYMBOL_CMD_CONST = 69,                 /* CMD_CONST  */
  YYSYMBOL_CONST_VARs = 70,                /* CONST_VARs  */
  YYSYMBOL_CONST_VAR = 71,                 /* CONST_VAR  */
  YYSYMBOL_CMD_IF = 72,                    /* CMD_IF  */
  YYSYMBOL_LVALUEPROP = 73,                /* LVALUEPROP  */
  YYSYMBOL_KEYS_VALUE_PAIRS = 74,          /* KEYS_VALUE_PAIRS  */
  YYSYMBOL_ARRAY_ELEMENTS = 75,            /* ARRAY_ELEMENTS  */
  YYSYMBOL_E = 76                          /* E  */
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
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      37,    43,    32,    30,    42,    31,    38,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    39,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   123,   124,   127,   128,   129,   130,   131,
     132,   133,   134,   138,   140,   144,   145,   149,   152,   153,
     157,   160,   165,   165,   180,   180,   195,   196,   199,   217,
     236,   241,   248,   264,   279,   280,   281,   282,   286,   289,
     290,   293,   295,   299,   302,   307,   310,   311,   314,   316,
     319,   322,   327,   330,   331,   334,   337,   340,   345,   357,
     367,   368,   371,   373,   375,   377,   382,   384,   386,   388,
     392,   394,   396,   398,   400,   402,   404,   406,   408,   410,
     412,   414,   416,   418,   420,   422,   424,   428,   429,   430,
     431,   432,   434,   436,   438,   440,   442
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
  "BOOLEAN", "OBJECT", "FECHA_PARENTESES_FUNC", "CDOUBLE", "CSTRING",
  "CINT", "AND", "OR", "ME_IG", "MA_IG", "DIF", "IGUAL", "MAIS_IGUAL",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "MAIS_MAIS",
  "'['", "'('", "'.'", "';'", "'{'", "'}'", "','", "')'", "']'", "':'",
  "$accept", "S", "CMDs", "CMD", "EMPILHA_TS", "LISTA_ARGs", "ARGs",
  "FUNCTION_ANON", "@1", "CMD_FUNCTION", "$@2", "LISTA_PARAMs", "PARAMs",
  "PARAM", "CMD_FOR", "CMD_WHILE", "PRIM_E", "CMD_LET", "LET_VARs",
  "LET_VAR", "CMD_VAR", "VAR_VARs", "VAR_VAR", "CMD_CONST", "CONST_VARs",
  "CONST_VAR", "CMD_IF", "LVALUEPROP", "KEYS_VALUE_PAIRS",
  "ARRAY_ELEMENTS", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,     8,   238,  -118,    -2,   -26,    11,    26,    27,    -6,
      29,    -3,   427,  -118,  -118,  -118,  -118,   427,    62,   427,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,    -4,     3,     4,
    -118,     1,   437,   427,    72,   427,    12,  -118,    -5,    17,
    -118,     5,    39,  -118,    25,   417,  -118,    31,   427,  -118,
     563,   112,    -1,  -118,    30,   533,   469,  -118,  -118,  -118,
    -118,   427,   262,    38,   427,   427,   427,   427,   427,   427,
     427,   427,  -118,   427,   427,    35,  -118,   593,    37,   593,
     485,   286,    11,   310,    26,   334,    27,    44,  -118,  -118,
    -118,   593,    33,    81,   501,  -118,    40,  -118,    46,  -118,
     358,  -118,   121,   593,    51,   593,  -118,   607,   607,   607,
     112,   112,   -19,   -19,   -19,   452,    52,    54,   593,  -118,
    -118,   238,     0,   593,  -118,     7,   593,  -118,    10,   593,
    -118,   427,    81,    67,    57,    55,  -118,   238,   382,  -118,
    -118,  -118,  -118,  -118,  -118,   427,    96,  -118,    63,  -118,
      64,  -118,    66,   578,    68,   427,    70,    81,  -118,    23,
     548,   593,   238,  -118,  -118,  -118,   427,    74,   593,  -118,
    -118,  -118,    75,   114,  -118,   517,  -118,   160,  -118,  -118,
     238,   199,  -118,  -118,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    91,     0,     0,     0,     0,     0,
      22,     0,     0,    89,    87,    90,    88,     0,     0,     0,
      16,    17,     3,    96,     5,    10,    11,     0,     0,     0,
       9,    92,     0,     0,     0,     0,    41,    38,    40,     0,
      52,    54,    48,    45,    47,     0,    24,     0,     0,    22,
       0,    85,     0,    94,     0,    67,     0,     4,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,    19,     0,    13,    74,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
      36,    37,     0,    27,     0,    12,     0,    68,     0,    95,
       0,    93,     0,    75,     0,    71,    15,    83,    76,    77,
      78,    79,    80,    81,    82,     0,     0,    18,    21,    61,
      72,     0,     0,    42,    39,     0,    55,    53,     0,    49,
      46,     0,    27,    30,     0,    26,    29,     0,     0,    69,
      66,    14,    73,    60,    86,     0,    59,    43,     0,    56,
       0,    50,     0,     0,     0,     0,     0,     0,    33,     0,
      63,    20,     0,    44,    57,    51,     0,     0,    31,     4,
      28,    64,     0,     0,    58,     0,     4,     0,    65,    62,
       0,     0,    23,    32,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -118,  -118,   -56,  -117,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,   -17,  -118,   -39,  -118,  -118,  -118,    76,    41,  -118,
      77,    50,  -118,    92,    58,  -118,  -118,  -118,  -113,    53,
     -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    22,    57,   116,   117,    23,    47,    24,
      92,   134,   135,   136,    25,    26,    87,    27,    37,    38,
      28,    43,    44,    29,    40,    41,    30,    31,    98,    54,
      32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   102,    96,    96,   146,    51,    55,    56,     3,   148,
      96,    35,   150,    96,    36,   152,    72,    73,    74,    75,
     158,    77,    79,    80,    33,    34,    96,    61,    62,    39,
      42,    45,    46,    91,    48,    58,    94,    82,   119,    81,
      97,   147,    59,    60,    83,   174,   172,    84,   149,   103,
     105,   151,   107,   108,   109,   110,   111,   112,   113,   114,
     179,   115,   118,   183,   171,     4,    85,    86,    93,   123,
     132,   126,    49,   129,    99,     4,    13,   106,   120,    14,
      15,    16,    49,   131,   133,   138,    13,   139,    55,    14,
      15,    16,   142,    17,   155,   144,   145,   157,    18,    19,
     156,   162,    52,    17,   163,   164,    53,   165,    18,    19,
     169,   167,    78,   177,   176,   154,   178,    96,   170,   153,
     181,    88,    89,   124,     4,     5,   160,     6,     7,     8,
       9,    10,    11,   161,    12,    13,   130,    90,    14,    15,
      16,     0,   127,   168,    69,    70,    71,    72,    73,    74,
      75,     0,    17,   140,   175,     0,     0,    18,    19,     0,
      20,    21,   141,     4,     5,     0,     6,     7,     8,     9,
      10,    11,     0,    12,    13,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,     0,    20,
      21,   182,     4,     5,     0,     6,     7,     8,     9,    10,
      11,     0,    12,    13,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    18,    19,     0,    20,    21,
     184,     4,     5,     0,     6,     7,     8,     9,    10,    11,
       0,    12,    13,     0,     0,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,    17,
       0,     0,    49,     0,    18,    19,    13,    20,    21,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,    17,     0,     0,    49,     0,    18,    19,
      13,     0,   104,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,    17,     0,     0,
      49,     0,    18,    19,    13,     0,   122,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,    17,     0,     0,    49,     0,    18,    19,    13,     0,
     125,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,    17,     0,     0,    49,     0,
      18,    19,    13,     0,   128,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,    17,
       0,     0,    49,     0,    18,    19,    13,     0,    52,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,    18,    19,
       4,     0,   159,     6,     7,     8,     0,    49,     0,     0,
       4,    13,     0,     0,    14,    15,    16,    49,     0,     0,
       0,    13,     0,     0,    14,    15,    16,     0,    17,    63,
       0,     0,     0,    18,    19,     0,     0,     0,    17,     0,
       0,     0,    64,    18,    19,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    64,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,    64,     0,   143,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      64,     0,   101,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    64,     0,   121,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    64,     0,   137,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    64,     0,
     180,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    64,     0,   100,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    64,     0,
     173,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    95,    64,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   166,    64,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,     0,     0,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      12,    57,     3,     3,   121,    17,    18,    19,     0,   122,
       3,    37,   125,     3,     3,   128,    35,    36,    37,    38,
     137,    33,    34,    35,    26,    27,     3,    26,    27,     3,
       3,    37,     3,    45,    37,    39,    48,    42,     3,    27,
      41,    41,    39,    39,    27,   162,   159,    42,    41,    61,
      62,    41,    64,    65,    66,    67,    68,    69,    70,    71,
     173,    73,    74,   180,    41,     3,    27,    42,    37,    81,
      37,    83,    10,    85,    44,     3,    14,    39,    41,    17,
      18,    19,    10,    39,     3,    45,    14,    41,   100,    17,
      18,    19,    41,    31,    27,    43,    42,    42,    36,    37,
      43,     5,    40,    31,    41,    41,    44,    41,    36,    37,
      40,    43,    40,   169,    40,   132,    41,     3,   157,   131,
     176,    45,    45,    82,     3,     4,   138,     6,     7,     8,
       9,    10,    11,   145,    13,    14,    86,    45,    17,    18,
      19,    -1,    84,   155,    32,    33,    34,    35,    36,    37,
      38,    -1,    31,   100,   166,    -1,    -1,    36,    37,    -1,
      39,    40,    41,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,
      40,    41,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,    40,
      41,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    31,
      -1,    -1,    10,    -1,    36,    37,    14,    39,    40,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    31,    -1,    -1,    10,    -1,    36,    37,
      14,    -1,    40,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    31,    -1,    -1,
      10,    -1,    36,    37,    14,    -1,    40,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    31,    -1,    -1,    10,    -1,    36,    37,    14,    -1,
      40,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    31,    -1,    -1,    10,    -1,
      36,    37,    14,    -1,    40,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    31,
      -1,    -1,    10,    -1,    36,    37,    14,    -1,    40,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,
       3,    -1,    40,     6,     7,     8,    -1,    10,    -1,    -1,
       3,    14,    -1,    -1,    17,    18,    19,    10,    -1,    -1,
      -1,    14,    -1,    -1,    17,    18,    19,    -1,    31,    12,
      -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    25,    36,    37,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    25,    -1,    44,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      25,    -1,    43,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    25,    -1,    43,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    25,    -1,    43,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    25,    -1,
      43,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    25,    -1,    42,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    25,    -1,
      42,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    25,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    13,    14,    17,    18,    19,    31,    36,    37,
      39,    40,    49,    53,    55,    60,    61,    63,    66,    69,
      72,    73,    76,    26,    27,    37,     3,    64,    65,     3,
      70,    71,     3,    67,    68,    37,     3,    54,    37,    10,
      76,    76,    40,    44,    75,    76,    76,    50,    39,    39,
      39,    26,    27,    12,    25,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    76,    40,    76,
      76,    27,    42,    27,    42,    27,    42,    62,    63,    66,
      69,    76,    56,    37,    76,    39,     3,    41,    74,    44,
      42,    43,    48,    76,    40,    76,    39,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    51,    52,    76,     3,
      41,    43,    40,    76,    64,    40,    76,    70,    40,    76,
      67,    39,    37,     3,    57,    58,    59,    43,    45,    41,
      75,    41,    41,    44,    43,    42,    49,    41,    74,    41,
      74,    41,    74,    76,    57,    27,    43,    42,    49,    40,
      76,    76,     5,    41,    41,    41,    39,    43,    76,    40,
      59,    41,    74,    42,    49,    76,    40,    48,    41,    74,
      43,    48,    41,    49,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    51,    51,
      52,    52,    54,    53,    56,    55,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    62,    62,    62,    63,    64,
      64,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      68,    68,    69,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     2,     2,     1,
       1,     1,     3,     2,     4,     3,     1,     0,     1,     0,
       3,     1,     0,     8,     0,     9,     1,     0,     3,     1,
       1,     3,     9,     5,     1,     1,     1,     1,     2,     3,
       1,     1,     3,     4,     5,     2,     3,     1,     1,     3,
       4,     5,     2,     3,     1,     3,     4,     5,     7,     5,
       4,     3,     5,     3,     4,     5,     3,     1,     2,     3,
       3,     3,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     1
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
#line 1541 "y.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 123 "mini_js.y"
                 { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1547 "y.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 124 "mini_js.y"
                 { yyval.clear();}
#line 1553 "y.tab.c"
    break;

  case 12: /* CMD: RETURN E ';'  */
#line 135 "mini_js.y"
      { 
        yyval.c = yyvsp[-1].c + "'&retorno'" + "@" + "~";
      }
#line 1561 "y.tab.c"
    break;

  case 13: /* CMD: E ';'  */
#line 139 "mini_js.y"
      { yyval.c = yyvsp[-1].c + "^"; }
#line 1567 "y.tab.c"
    break;

  case 14: /* CMD: '{' EMPILHA_TS CMDs '}'  */
#line 141 "mini_js.y"
      { 
        ts.pop_back();
        yyval.c = vector<string>{"<{"} + yyvsp[-1].c + vector<string>{"}>"}; }
#line 1575 "y.tab.c"
    break;

  case 15: /* CMD: E ASM ';'  */
#line 144 "mini_js.y"
                        { yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 1581 "y.tab.c"
    break;

  case 16: /* CMD: ';'  */
#line 145 "mini_js.y"
          { yyval.clear();}
#line 1587 "y.tab.c"
    break;

  case 17: /* EMPILHA_TS: %empty  */
#line 149 "mini_js.y"
             { ts.push_back( map< string, Simbolo >{} ); }
#line 1593 "y.tab.c"
    break;

  case 19: /* LISTA_ARGs: %empty  */
#line 153 "mini_js.y"
          { ts.push_back( map< string, Simbolo >{} ); 
              yyval.clear(); }
#line 1600 "y.tab.c"
    break;

  case 20: /* ARGs: ARGs ',' E  */
#line 158 "mini_js.y"
       { yyval.c = yyvsp[-2].c + yyvsp[0].c;
         yyval.contador = yyvsp[-2].contador + 1; }
#line 1607 "y.tab.c"
    break;

  case 21: /* ARGs: E  */
#line 161 "mini_js.y"
       { yyval.c = yyvsp[0].c;
         yyval.contador = 1; }
#line 1614 "y.tab.c"
    break;

  case 22: /* @1: %empty  */
#line 165 "mini_js.y"
                         { in_func = 1; }
#line 1620 "y.tab.c"
    break;

  case 23: /* FUNCTION_ANON: FUNCTION @1 '(' LISTA_PARAMs ')' '{' CMDs '}'  */
#line 167 "mini_js.y"
           { 
             string lbl_endereco_funcao = gera_label( "func_" + yyvsp[-6].c[0] );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             yyval.c = yyvsp[-6].c + "&" + yyvsp[-6].c + "{}"  + "=" + "'&funcao'" +
                    lbl_endereco_funcao + "[=]" + "^";
             funcoes = funcoes + definicao_lbl_endereco_funcao + yyvsp[-3].c + yyvsp[0].c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func = 0;
           }
#line 1636 "y.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 180 "mini_js.y"
                           { declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); in_func = 1; }
#line 1642 "y.tab.c"
    break;

  case 25: /* CMD_FUNCTION: FUNCTION ID $@2 '(' LISTA_PARAMs ')' '{' CMDs '}'  */
#line 182 "mini_js.y"
           { 
             string lbl_endereco_funcao = gera_label( "func_" + yyvsp[-7].c[0] );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             yyval.c = yyvsp[-7].c + "&" + yyvsp[-7].c + "{}"  + "=" + "'&funcao'" +
                    lbl_endereco_funcao + "[=]" + "^";
             funcoes = funcoes + definicao_lbl_endereco_funcao + yyvsp[-4].c + yyvsp[-1].c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func = 0;
           }
#line 1658 "y.tab.c"
    break;

  case 27: /* LISTA_PARAMs: %empty  */
#line 196 "mini_js.y"
             { yyval.clear(); }
#line 1664 "y.tab.c"
    break;

  case 28: /* PARAMs: PARAMs ',' PARAM  */
#line 200 "mini_js.y"
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
#line 1686 "y.tab.c"
    break;

  case 29: /* PARAMs: PARAM  */
#line 218 "mini_js.y"
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
#line 1707 "y.tab.c"
    break;

  case 30: /* PARAM: ID  */
#line 237 "mini_js.y"
      { yyval.c = yyvsp[0].c;      
        yyval.contador = 1;
        yyval.valor_default.clear();
      }
#line 1716 "y.tab.c"
    break;

  case 31: /* PARAM: ID '=' E  */
#line 242 "mini_js.y"
      { // Código do IF
        yyval.c = yyvsp[-2].c;
        yyval.contador = 1;
        yyval.valor_default = yyvsp[0].c;         
      }
#line 1726 "y.tab.c"
    break;

  case 32: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 249 "mini_js.y"
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
#line 1744 "y.tab.c"
    break;

  case 33: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 265 "mini_js.y"
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
#line 1761 "y.tab.c"
    break;

  case 37: /* PRIM_E: E  */
#line 283 "mini_js.y"
         { yyval.c = yyvsp[0].c + "^"; }
#line 1767 "y.tab.c"
    break;

  case 38: /* CMD_LET: LET LET_VARs  */
#line 286 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1773 "y.tab.c"
    break;

  case 39: /* LET_VARs: LET_VAR ',' LET_VARs  */
#line 289 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1779 "y.tab.c"
    break;

  case 41: /* LET_VAR: ID  */
#line 294 "mini_js.y"
          { yyval.c = declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1785 "y.tab.c"
    break;

  case 42: /* LET_VAR: ID '=' E  */
#line 296 "mini_js.y"
          { 
            yyval.c = declara_var( Let, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                   yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1793 "y.tab.c"
    break;

  case 43: /* LET_VAR: ID '=' '{' '}'  */
#line 300 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 1800 "y.tab.c"
    break;

  case 44: /* LET_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 303 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 1807 "y.tab.c"
    break;

  case 45: /* CMD_VAR: VAR VAR_VARs  */
#line 307 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1813 "y.tab.c"
    break;

  case 46: /* VAR_VARs: VAR_VAR ',' VAR_VARs  */
#line 310 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1819 "y.tab.c"
    break;

  case 48: /* VAR_VAR: ID  */
#line 315 "mini_js.y"
          { yyval.c = declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1825 "y.tab.c"
    break;

  case 49: /* VAR_VAR: ID '=' E  */
#line 317 "mini_js.y"
          {  yyval.c = declara_var( Var, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                    yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1832 "y.tab.c"
    break;

  case 50: /* VAR_VAR: ID '=' '{' '}'  */
#line 320 "mini_js.y"
            { yyval.c = declara_var( Var, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 1839 "y.tab.c"
    break;

  case 51: /* VAR_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 323 "mini_js.y"
            { yyval.c = declara_var( Var, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 1846 "y.tab.c"
    break;

  case 52: /* CMD_CONST: CONST CONST_VARs  */
#line 327 "mini_js.y"
                            { yyval.c = yyvsp[0].c; }
#line 1852 "y.tab.c"
    break;

  case 53: /* CONST_VARs: CONST_VAR ',' CONST_VARs  */
#line 330 "mini_js.y"
                                      { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1858 "y.tab.c"
    break;

  case 55: /* CONST_VAR: ID '=' E  */
#line 335 "mini_js.y"
            { yyval.c = declara_var( Const, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                     yyvsp[-2].c + yyvsp[0].c + "=" + "^";}
#line 1865 "y.tab.c"
    break;

  case 56: /* CONST_VAR: ID '=' '{' '}'  */
#line 338 "mini_js.y"
            { yyval.c = declara_var( Const, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) + 
                     yyvsp[-3].c + "{}" + "=" + "^";}
#line 1872 "y.tab.c"
    break;

  case 57: /* CONST_VAR: ID '=' '{' KEYS_VALUE_PAIRS '}'  */
#line 341 "mini_js.y"
            { yyval.c = declara_var( Let, yyvsp[-4].c[0], yyvsp[-4].linha, yyvsp[-4].coluna ) + 
            yyvsp[-4].c + "{}" + "=" + yyvsp[-1].c  + "^";}
#line 1879 "y.tab.c"
    break;

  case 58: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 346 "mini_js.y"
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
#line 1895 "y.tab.c"
    break;

  case 59: /* CMD_IF: IF '(' E ')' CMD  */
#line 358 "mini_js.y"
        { string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          yyval.c = yyvsp[-2].c + lbl_true + "?" + lbl_fim_if + "#" +
          definicao_lbl_true + yyvsp[0].c + definicao_lbl_fim_if;
        }
#line 1907 "y.tab.c"
    break;

  case 60: /* LVALUEPROP: E '[' E ']'  */
#line 367 "mini_js.y"
                         { yyval.c = yyvsp[-3].c + yyvsp[-1].c; }
#line 1913 "y.tab.c"
    break;

  case 61: /* LVALUEPROP: E '.' ID  */
#line 368 "mini_js.y"
                       { yyval.c = yyvsp[-2].c+ yyvsp[0].c; }
#line 1919 "y.tab.c"
    break;

  case 62: /* KEYS_VALUE_PAIRS: ID ':' E ',' KEYS_VALUE_PAIRS  */
#line 372 "mini_js.y"
                  {yyval.c =  yyvsp[0].c + yyvsp[-4].c + yyvsp[-2].c + "[<=]"; }
#line 1925 "y.tab.c"
    break;

  case 63: /* KEYS_VALUE_PAIRS: ID ':' E  */
#line 374 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[<=]";}
#line 1931 "y.tab.c"
    break;

  case 64: /* KEYS_VALUE_PAIRS: ID ':' '{' '}'  */
#line 376 "mini_js.y"
                  { yyval.c = yyvsp[-3].c + "{}" + "[<=]";}
#line 1937 "y.tab.c"
    break;

  case 65: /* KEYS_VALUE_PAIRS: ID ':' '{' KEYS_VALUE_PAIRS '}'  */
#line 378 "mini_js.y"
                  { yyval.c = yyvsp[-4].c + "{}" + yyvsp[-1].c + "[<=]";}
#line 1943 "y.tab.c"
    break;

  case 66: /* ARRAY_ELEMENTS: E ',' ARRAY_ELEMENTS  */
#line 383 "mini_js.y"
               { yyval.c = vector<string>{} + to_string(arrayElCounter) + yyvsp[-2].c + "[<=]" + yyvsp[0].c; arrayElCounter++;}
#line 1949 "y.tab.c"
    break;

  case 67: /* ARRAY_ELEMENTS: E  */
#line 385 "mini_js.y"
               { yyval.c = vector<string>{} + to_string(arrayElCounter) + yyvsp[0].c + "[<=]"; arrayElCounter++;}
#line 1955 "y.tab.c"
    break;

  case 68: /* ARRAY_ELEMENTS: '{' '}'  */
#line 387 "mini_js.y"
                { yyval.c = vector<string>{} + to_string(arrayElCounter) + "{}" + "[<=]"; arrayElCounter++;}
#line 1961 "y.tab.c"
    break;

  case 69: /* ARRAY_ELEMENTS: '{' KEYS_VALUE_PAIRS '}'  */
#line 389 "mini_js.y"
                { yyval.c = vector<string>{} + to_string(arrayElCounter) + "{}" + yyvsp[-1].c + "[<=]"; arrayElCounter++;}
#line 1967 "y.tab.c"
    break;

  case 70: /* E: ID '=' E  */
#line 393 "mini_js.y"
    { checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1973 "y.tab.c"
    break;

  case 71: /* E: LVALUEPROP '=' E  */
#line 395 "mini_js.y"
    { checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1979 "y.tab.c"
    break;

  case 72: /* E: ID '=' '{' '}'  */
#line 397 "mini_js.y"
    { checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + yyvsp[-1].c + "="; }
#line 1985 "y.tab.c"
    break;

  case 73: /* E: LVALUEPROP '=' '{' '}'  */
#line 399 "mini_js.y"
      { checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + yyvsp[-1].c + "="; }
#line 1991 "y.tab.c"
    break;

  case 74: /* E: ID MAIS_IGUAL E  */
#line 401 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "+" + "="; }
#line 1997 "y.tab.c"
    break;

  case 75: /* E: LVALUEPROP MAIS_IGUAL E  */
#line 403 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "+" + "="; }
#line 2003 "y.tab.c"
    break;

  case 76: /* E: E '<' E  */
#line 405 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2009 "y.tab.c"
    break;

  case 77: /* E: E '>' E  */
#line 407 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2015 "y.tab.c"
    break;

  case 78: /* E: E '+' E  */
#line 409 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2021 "y.tab.c"
    break;

  case 79: /* E: E '-' E  */
#line 411 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2027 "y.tab.c"
    break;

  case 80: /* E: E '*' E  */
#line 413 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2033 "y.tab.c"
    break;

  case 81: /* E: E '/' E  */
#line 415 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2039 "y.tab.c"
    break;

  case 82: /* E: E '%' E  */
#line 417 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 2045 "y.tab.c"
    break;

  case 83: /* E: E IGUAL E  */
#line 419 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 2051 "y.tab.c"
    break;

  case 84: /* E: E MAIS_MAIS  */
#line 421 "mini_js.y"
    { yyval.c = vector<string>{} + yyvsp[-1].c[0] + yyvsp[-1].c[0] + "@" + "1" + "+" + "="; }
#line 2057 "y.tab.c"
    break;

  case 85: /* E: '-' E  */
#line 423 "mini_js.y"
    { yyval.c = "0" + yyvsp[0].c + yyvsp[-1].c; }
#line 2063 "y.tab.c"
    break;

  case 86: /* E: E '(' LISTA_ARGs ')'  */
#line 425 "mini_js.y"
    { 
    yyval.c = yyvsp[-1].c + to_string( yyvsp[-1].contador ) + yyvsp[-3].c + "$";
    }
#line 2071 "y.tab.c"
    break;

  case 91: /* E: ID  */
#line 433 "mini_js.y"
    { checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "@"; }
#line 2077 "y.tab.c"
    break;

  case 92: /* E: LVALUEPROP  */
#line 435 "mini_js.y"
    { checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "[@]"; }
#line 2083 "y.tab.c"
    break;

  case 93: /* E: '(' E ')'  */
#line 437 "mini_js.y"
    { yyval.c = yyvsp[-1].c; }
#line 2089 "y.tab.c"
    break;

  case 94: /* E: '[' ']'  */
#line 439 "mini_js.y"
    { yyval.c = {"[]"}; }
#line 2095 "y.tab.c"
    break;

  case 95: /* E: '[' ARRAY_ELEMENTS ']'  */
#line 441 "mini_js.y"
  { yyval.c = vector<string>{} + "[]" + yyvsp[-1].c; arrayElCounter = 0;}
#line 2101 "y.tab.c"
    break;


#line 2105 "y.tab.c"

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

#line 446 "mini_js.y"


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
