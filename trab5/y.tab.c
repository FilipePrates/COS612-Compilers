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

#line 171 "y.tab.c"

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
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_S = 46,                         /* S  */
  YYSYMBOL_CMDs = 47,                      /* CMDs  */
  YYSYMBOL_CMD = 48,                       /* CMD  */
  YYSYMBOL_EMPILHA_TS = 49,                /* EMPILHA_TS  */
  YYSYMBOL_LISTA_ARGs = 50,                /* LISTA_ARGs  */
  YYSYMBOL_ARGs = 51,                      /* ARGs  */
  YYSYMBOL_CMD_FUNCTION = 52,              /* CMD_FUNCTION  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_LISTA_PARAMs = 54,              /* LISTA_PARAMs  */
  YYSYMBOL_PARAMs = 55,                    /* PARAMs  */
  YYSYMBOL_PARAM = 56,                     /* PARAM  */
  YYSYMBOL_CMD_FOR = 57,                   /* CMD_FOR  */
  YYSYMBOL_CMD_WHILE = 58,                 /* CMD_WHILE  */
  YYSYMBOL_PRIM_E = 59,                    /* PRIM_E  */
  YYSYMBOL_CMD_LET = 60,                   /* CMD_LET  */
  YYSYMBOL_LET_VARs = 61,                  /* LET_VARs  */
  YYSYMBOL_LET_VAR = 62,                   /* LET_VAR  */
  YYSYMBOL_CMD_VAR = 63,                   /* CMD_VAR  */
  YYSYMBOL_VAR_VARs = 64,                  /* VAR_VARs  */
  YYSYMBOL_VAR_VAR = 65,                   /* VAR_VAR  */
  YYSYMBOL_CMD_CONST = 66,                 /* CMD_CONST  */
  YYSYMBOL_CONST_VARs = 67,                /* CONST_VARs  */
  YYSYMBOL_CONST_VAR = 68,                 /* CONST_VAR  */
  YYSYMBOL_CMD_IF = 69,                    /* CMD_IF  */
  YYSYMBOL_LVALUEPROP = 70,                /* LVALUEPROP  */
  YYSYMBOL_E = 71                          /* E  */
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
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
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
       0,   118,   118,   121,   122,   125,   126,   127,   128,   129,
     130,   131,   132,   136,   138,   142,   143,   147,   150,   151,
     155,   158,   162,   162,   177,   178,   181,   199,   218,   223,
     230,   246,   261,   262,   263,   264,   268,   271,   272,   275,
     277,   283,   286,   287,   290,   292,   297,   300,   301,   304,
     309,   321,   331,   332,   336,   338,   340,   342,   344,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,   366,
     368,   370,   374,   375,   376,   377,   378,   380,   382,   384
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
  "'['", "'('", "'.'", "';'", "'{'", "'}'", "','", "')'", "']'", "$accept",
  "S", "CMDs", "CMD", "EMPILHA_TS", "LISTA_ARGs", "ARGs", "CMD_FUNCTION",
  "$@1", "LISTA_PARAMs", "PARAMs", "PARAM", "CMD_FOR", "CMD_WHILE",
  "PRIM_E", "CMD_LET", "LET_VARs", "LET_VAR", "CMD_VAR", "VAR_VARs",
  "VAR_VAR", "CMD_CONST", "CONST_VARs", "CONST_VAR", "CMD_IF",
  "LVALUEPROP", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,     6,   147,   -51,   -23,   -25,    11,    12,    16,   -10,
      22,    -9,    23,   -51,   -51,   -51,   -51,    23,   -15,    23,
     -51,   -51,   -51,   -51,   -51,   -51,    -8,    -6,    19,   -51,
      -3,   223,    23,    -1,    23,    30,   -51,    -4,    34,   -51,
       3,    35,   -51,    24,   213,   -51,    23,   319,    97,   -51,
     255,   -51,   -51,   -51,   -51,    23,   171,    25,   178,    23,
      23,    23,    23,    23,    23,    23,   -51,    23,    23,    65,
     -51,   349,    28,   349,   271,    23,    11,    23,    12,    23,
      16,    33,   -51,   -51,   -51,   349,    42,   287,   -51,   -51,
      67,   349,    41,   349,   -51,    46,   363,   363,   363,    97,
      97,   -27,   -27,   -27,   238,    40,    47,   349,   -51,   -51,
     147,   349,   -51,   349,   -51,   349,   -51,    23,    85,   147,
     -51,   -51,   -51,   -51,   -51,    23,    86,   334,    63,    50,
      52,   -51,   -51,   349,   147,    23,    23,    55,    85,   -51,
     303,   349,   -51,   -51,   147,   108,   -51,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    72,    75,    73,     0,     0,     0,
      16,    17,     3,     5,    10,    11,     0,     0,     0,     9,
      77,     0,     0,     0,     0,    39,    36,    38,     0,    46,
      48,    44,    41,    43,     0,    22,     0,     0,    70,    79,
       0,     4,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    19,     0,
      13,    58,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,     0,     0,    12,    78,
       0,    59,     0,    55,    15,     0,    67,    60,    61,    62,
      63,    64,    65,    66,     0,     0,    18,    21,    53,    56,
       0,    40,    37,    49,    47,    45,    42,     0,    25,     0,
      14,    57,    68,    52,    71,     0,    51,     0,    28,     0,
      24,    27,    31,    20,     0,     0,     0,     0,     0,    50,
       0,    29,     4,    26,     0,     0,    30,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -50,    18,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -42,   -51,   -51,   -51,    53,    26,   -51,    56,    21,
     -51,    66,    31,   -51,   -51,   -51,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    22,    51,   105,   106,    23,    86,   129,
     130,   131,    24,    25,    81,    26,    36,    37,    27,    42,
      43,    28,    39,    40,    29,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    90,     4,    32,    33,    48,     3,    50,    66,    67,
      68,    69,    34,    13,    35,    38,    14,    15,    16,    41,
      71,    73,    74,    55,    56,    45,     4,    44,    46,    49,
      17,    52,    85,    53,    87,    18,    19,    13,    76,    72,
      14,    15,    16,    91,    93,    78,    96,    97,    98,    99,
     100,   101,   102,   103,    17,   104,   107,    75,    54,    18,
      19,    77,    79,   111,    94,   113,    80,   115,   108,   109,
       4,     5,   117,     6,     7,     8,     9,    10,    11,   118,
      12,    13,   121,   124,    14,    15,    16,   122,   128,   125,
     136,   134,   145,   137,   138,   142,   143,    82,    17,     0,
      83,   116,   112,    18,    19,   127,    20,    21,   120,   114,
      84,     4,     5,   133,     6,     7,     8,     9,    10,    11,
       0,    12,    13,   140,   141,    14,    15,    16,   126,    63,
      64,    65,    66,    67,    68,    69,     0,   132,     0,    17,
       0,     0,     0,     0,    18,    19,     0,    20,    21,   147,
       4,     5,   139,     6,     7,     8,     9,    10,    11,     0,
      12,    13,   146,     0,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     0,    17,     0,
       0,     4,     0,    18,    19,    13,    20,    21,    14,    15,
      16,     0,    13,     0,     0,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,    19,    17,
       0,    92,     0,     0,    18,    19,     4,     0,    95,     6,
       7,     8,     0,     0,     0,     0,     0,    13,     0,     0,
      14,    15,    16,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,    58,    18,
      19,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    58,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      58,     0,   123,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    58,     0,    89,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    58,     0,   110,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    58,     0,
     119,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    58,     0,   144,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    88,    58,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   135,    58,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,     0,
       0,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69
};

static const yytype_int16 yycheck[] =
{
      12,    51,     3,    26,    27,    17,     0,    19,    35,    36,
      37,    38,    37,    14,     3,     3,    17,    18,    19,     3,
      32,    33,    34,    26,    27,     3,     3,    37,    37,    44,
      31,    39,    44,    39,    46,    36,    37,    14,    42,    40,
      17,    18,    19,    55,    56,    42,    58,    59,    60,    61,
      62,    63,    64,    65,    31,    67,    68,    27,    39,    36,
      37,    27,    27,    75,    39,    77,    42,    79,     3,    41,
       3,     4,    39,     6,     7,     8,     9,    10,    11,    37,
      13,    14,    41,    43,    17,    18,    19,    41,     3,    42,
      27,     5,   142,    43,    42,    40,   138,    44,    31,    -1,
      44,    80,    76,    36,    37,   117,    39,    40,    41,    78,
      44,     3,     4,   125,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,   135,   136,    17,    18,    19,   110,    32,
      33,    34,    35,    36,    37,    38,    -1,   119,    -1,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    39,    40,    41,
       3,     4,   134,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,   144,    -1,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    31,    -1,
      -1,     3,    -1,    36,    37,    14,    39,    40,    17,    18,
      19,    -1,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,    31,
      -1,    40,    -1,    -1,    36,    37,     3,    -1,    40,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    25,    36,
      37,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      25,    -1,    44,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    25,    -1,    43,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    25,    -1,    43,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    25,    -1,
      43,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    25,    -1,    43,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    13,    14,    17,    18,    19,    31,    36,    37,
      39,    40,    48,    52,    57,    58,    60,    63,    66,    69,
      70,    71,    26,    27,    37,     3,    61,    62,     3,    67,
      68,     3,    64,    65,    37,     3,    37,    71,    71,    44,
      71,    49,    39,    39,    39,    26,    27,    12,    25,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    71,    40,    71,    71,    27,    42,    27,    42,    27,
      42,    59,    60,    63,    66,    71,    53,    71,    39,    43,
      47,    71,    40,    71,    39,    40,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    50,    51,    71,     3,    41,
      43,    71,    61,    71,    67,    71,    64,    39,    37,    43,
      41,    41,    41,    44,    43,    42,    48,    71,     3,    54,
      55,    56,    48,    71,     5,    39,    27,    43,    42,    48,
      71,    71,    40,    56,    43,    47,    48,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    50,    50,
      51,    51,    53,    52,    54,    54,    55,    55,    56,    56,
      57,    58,    59,    59,    59,    59,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     2,     2,     1,
       1,     1,     3,     2,     4,     3,     1,     0,     1,     0,
       3,     1,     0,     9,     1,     0,     3,     1,     1,     3,
       9,     5,     1,     1,     1,     1,     2,     3,     1,     1,
       3,     2,     3,     1,     1,     3,     2,     3,     1,     3,
       7,     5,     4,     3,     3,     3,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     3,     2
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
#line 118 "mini_js.y"
         { print(resolve_enderecos( yyvsp[0].c + "." + funcoes)); }
#line 1465 "y.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 121 "mini_js.y"
                 { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1471 "y.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 122 "mini_js.y"
                 { yyval.clear();}
#line 1477 "y.tab.c"
    break;

  case 12: /* CMD: RETURN E ';'  */
#line 133 "mini_js.y"
      { 
        yyval.c = yyvsp[-1].c + "'&retorno'" + "@" + "~";
      }
#line 1485 "y.tab.c"
    break;

  case 13: /* CMD: E ';'  */
#line 137 "mini_js.y"
      { yyval.c = yyvsp[-1].c + "^"; }
#line 1491 "y.tab.c"
    break;

  case 14: /* CMD: '{' EMPILHA_TS CMDs '}'  */
#line 139 "mini_js.y"
      { 
        ts.pop_back();
        yyval.c = vector<string>{"<{"} + yyvsp[-1].c + vector<string>{"}>"}; }
#line 1499 "y.tab.c"
    break;

  case 15: /* CMD: E ASM ';'  */
#line 142 "mini_js.y"
                        { yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 1505 "y.tab.c"
    break;

  case 16: /* CMD: ';'  */
#line 143 "mini_js.y"
          { yyval.clear();}
#line 1511 "y.tab.c"
    break;

  case 17: /* EMPILHA_TS: %empty  */
#line 147 "mini_js.y"
             { ts.push_back( map< string, Simbolo >{} ); }
#line 1517 "y.tab.c"
    break;

  case 19: /* LISTA_ARGs: %empty  */
#line 151 "mini_js.y"
          { ts.push_back( map< string, Simbolo >{} ); 
              yyval.clear(); }
#line 1524 "y.tab.c"
    break;

  case 20: /* ARGs: ARGs ',' E  */
#line 156 "mini_js.y"
       { yyval.c = yyvsp[-2].c + yyvsp[0].c;
         yyval.contador = yyvsp[-2].contador + 1; }
#line 1531 "y.tab.c"
    break;

  case 21: /* ARGs: E  */
#line 159 "mini_js.y"
       { yyval.c = yyvsp[0].c;
         yyval.contador = 1; }
#line 1538 "y.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 162 "mini_js.y"
                           { declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); in_func = 1; }
#line 1544 "y.tab.c"
    break;

  case 23: /* CMD_FUNCTION: FUNCTION ID $@1 '(' LISTA_PARAMs ')' '{' CMDs '}'  */
#line 164 "mini_js.y"
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
#line 1560 "y.tab.c"
    break;

  case 25: /* LISTA_PARAMs: %empty  */
#line 178 "mini_js.y"
             { yyval.clear(); }
#line 1566 "y.tab.c"
    break;

  case 26: /* PARAMs: PARAMs ',' PARAM  */
#line 182 "mini_js.y"
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
#line 1588 "y.tab.c"
    break;

  case 27: /* PARAMs: PARAM  */
#line 200 "mini_js.y"
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
#line 1609 "y.tab.c"
    break;

  case 28: /* PARAM: ID  */
#line 219 "mini_js.y"
      { yyval.c = yyvsp[0].c;      
        yyval.contador = 1;
        yyval.valor_default.clear();
      }
#line 1618 "y.tab.c"
    break;

  case 29: /* PARAM: ID '=' E  */
#line 224 "mini_js.y"
      { // Código do IF
        yyval.c = yyvsp[-2].c;
        yyval.contador = 1;
        yyval.valor_default = yyvsp[0].c;         
      }
#line 1628 "y.tab.c"
    break;

  case 30: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 231 "mini_js.y"
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
#line 1646 "y.tab.c"
    break;

  case 31: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 247 "mini_js.y"
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
#line 1663 "y.tab.c"
    break;

  case 35: /* PRIM_E: E  */
#line 265 "mini_js.y"
         { yyval.c = yyvsp[0].c + "^"; }
#line 1669 "y.tab.c"
    break;

  case 36: /* CMD_LET: LET LET_VARs  */
#line 268 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1675 "y.tab.c"
    break;

  case 37: /* LET_VARs: LET_VAR ',' LET_VARs  */
#line 271 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1681 "y.tab.c"
    break;

  case 39: /* LET_VAR: ID  */
#line 276 "mini_js.y"
          { yyval.c = declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1687 "y.tab.c"
    break;

  case 40: /* LET_VAR: ID '=' E  */
#line 278 "mini_js.y"
          { 
            yyval.c = declara_var( Let, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                   yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1695 "y.tab.c"
    break;

  case 41: /* CMD_VAR: VAR VAR_VARs  */
#line 283 "mini_js.y"
                       { yyval.c = yyvsp[0].c; }
#line 1701 "y.tab.c"
    break;

  case 42: /* VAR_VARs: VAR_VAR ',' VAR_VARs  */
#line 286 "mini_js.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1707 "y.tab.c"
    break;

  case 44: /* VAR_VAR: ID  */
#line 291 "mini_js.y"
          { yyval.c = declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1713 "y.tab.c"
    break;

  case 45: /* VAR_VAR: ID '=' E  */
#line 293 "mini_js.y"
          {  yyval.c = declara_var( Var, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                    yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1720 "y.tab.c"
    break;

  case 46: /* CMD_CONST: CONST CONST_VARs  */
#line 297 "mini_js.y"
                            { yyval.c = yyvsp[0].c; }
#line 1726 "y.tab.c"
    break;

  case 47: /* CONST_VARs: CONST_VAR ',' CONST_VARs  */
#line 300 "mini_js.y"
                                      { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1732 "y.tab.c"
    break;

  case 49: /* CONST_VAR: ID '=' E  */
#line 305 "mini_js.y"
            { yyval.c = declara_var( Const, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) + 
                     yyvsp[-2].c + yyvsp[0].c + "=" + "^";}
#line 1739 "y.tab.c"
    break;

  case 50: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 310 "mini_js.y"
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
#line 1755 "y.tab.c"
    break;

  case 51: /* CMD_IF: IF '(' E ')' CMD  */
#line 322 "mini_js.y"
        { string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          yyval.c = yyvsp[-2].c + lbl_true + "?" + lbl_fim_if + "#" +
          definicao_lbl_true + yyvsp[0].c + definicao_lbl_fim_if;
        }
#line 1767 "y.tab.c"
    break;

  case 52: /* LVALUEPROP: E '[' E ']'  */
#line 331 "mini_js.y"
                         { yyval.c = yyvsp[-3].c + yyvsp[-1].c; }
#line 1773 "y.tab.c"
    break;

  case 53: /* LVALUEPROP: E '.' ID  */
#line 332 "mini_js.y"
                       { yyval.c = yyvsp[-2].c+ yyvsp[0].c; }
#line 1779 "y.tab.c"
    break;

  case 54: /* E: ID '=' E  */
#line 337 "mini_js.y"
    { checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1785 "y.tab.c"
    break;

  case 55: /* E: LVALUEPROP '=' E  */
#line 339 "mini_js.y"
    { checa_simbolo( yyvsp[-2].c[0], true );  yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1791 "y.tab.c"
    break;

  case 56: /* E: ID '=' '{' '}'  */
#line 341 "mini_js.y"
    { checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + yyvsp[-1].c + "="; }
#line 1797 "y.tab.c"
    break;

  case 57: /* E: LVALUEPROP '=' '{' '}'  */
#line 343 "mini_js.y"
      { checa_simbolo( yyvsp[-3].c[0], true );  yyval.c = yyvsp[-3].c + yyvsp[-1].c + "="; }
#line 1803 "y.tab.c"
    break;

  case 58: /* E: ID MAIS_IGUAL E  */
#line 345 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "+="; }
#line 1809 "y.tab.c"
    break;

  case 59: /* E: LVALUEPROP MAIS_IGUAL E  */
#line 347 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "+="; }
#line 1815 "y.tab.c"
    break;

  case 60: /* E: E '<' E  */
#line 349 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1821 "y.tab.c"
    break;

  case 61: /* E: E '>' E  */
#line 351 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1827 "y.tab.c"
    break;

  case 62: /* E: E '+' E  */
#line 353 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1833 "y.tab.c"
    break;

  case 63: /* E: E '-' E  */
#line 355 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1839 "y.tab.c"
    break;

  case 64: /* E: E '*' E  */
#line 357 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1845 "y.tab.c"
    break;

  case 65: /* E: E '/' E  */
#line 359 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1851 "y.tab.c"
    break;

  case 66: /* E: E '%' E  */
#line 361 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1857 "y.tab.c"
    break;

  case 67: /* E: E IGUAL E  */
#line 363 "mini_js.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 1863 "y.tab.c"
    break;

  case 68: /* E: E IGUAL '{' '}'  */
#line 365 "mini_js.y"
    { yyval.c = yyvsp[-3].c + yyvsp[-1].c + "{}"; }
#line 1869 "y.tab.c"
    break;

  case 69: /* E: E MAIS_MAIS  */
#line 367 "mini_js.y"
    { yyval.c = yyvsp[-1].c + "++"; }
#line 1875 "y.tab.c"
    break;

  case 70: /* E: '-' E  */
#line 369 "mini_js.y"
    { yyval.c = "0" + yyvsp[0].c + yyvsp[-1].c; }
#line 1881 "y.tab.c"
    break;

  case 71: /* E: E '(' LISTA_ARGs ')'  */
#line 371 "mini_js.y"
    { 
    yyval.c = yyvsp[-1].c + to_string( yyvsp[-1].contador ) + yyvsp[-3].c + "$";
    }
#line 1889 "y.tab.c"
    break;

  case 76: /* E: ID  */
#line 379 "mini_js.y"
    { checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "@"; }
#line 1895 "y.tab.c"
    break;

  case 77: /* E: LVALUEPROP  */
#line 381 "mini_js.y"
    { checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "[@]"; }
#line 1901 "y.tab.c"
    break;

  case 78: /* E: '(' E ')'  */
#line 383 "mini_js.y"
    { yyval.c = yyvsp[-1].c; }
#line 1907 "y.tab.c"
    break;

  case 79: /* E: '[' ']'  */
#line 385 "mini_js.y"
    { yyval.c = {"[]"}; }
#line 1913 "y.tab.c"
    break;


#line 1917 "y.tab.c"

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

#line 389 "mini_js.y"


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