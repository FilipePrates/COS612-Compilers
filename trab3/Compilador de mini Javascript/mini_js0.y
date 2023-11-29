%{
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos
{
    vector<string> c; // Código
    int linha = 0,
    int coluna = 0;

    void clear()
    {
        c.clear();
        linha = 0;
        coluna = 0;
    }
};

enum TipoDecl
{
    Let = 1,
    Const,
    Var
};

struct Simbolo
{
    TipoDecl tipo;
    int linha;
    int coluna;
};

map<string, Simbolo> ts;

void insere_simbolo( TipoDecl tipo, string nome, int linha, int coluna );
void checa_simbolo(string nome, bool modificavel);

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror(const char *);

%}

%token NUM CTE X
%start S

%%

S : E { cout << "f(x)     = " << $1.e << endl
             << "df(x)/dx = " << $1.d << endl; }
  ;

E : E '+' T { $$.e = $1.e + " + " + $3.e;
              $$.d = $1.d + " + " + $3.d; }
  | E '-' T { $$.e = $1.e + " - " + $3.e; 
              $$.d = $1.d + " - " + $3.d; }
  | T
  ;
  
T : T '*' F { $$.e = $1.e + "*" + $3.e; 
              $$.d = "(" + $1.d + "*" + $3.e + " + " + $1.e + "*" + $3.d + ")"; }
  | T '/' F { $$.e = $1.e + "/" + $3.e; 
              $$.d = "(" + $1.d + "*" + $3.e + " - " + $1.e + "*" + $3.d + ")"
                   + "/" + $3.e + "^2"
              ; }
  | P
  ;
  
P : F '^' NUM { $$.e = $1.e + "^" + $3.e;
		$$.d = $3.e + "*" + $1.d + "*" + $1.e + "^" + 
		       to_string( (stod( $3.e ) - 1) );  }
  | F '^' CTE { $$.e = $1.e + "^" + $3.e;
		$$.d = $3.e + "*" + $1.d + "*" + $1.e + "^" + 
			   "("+ $3.e + "-1)";  }
  | F   
  ;
  
F : NUM
  | CTE
  | X
  | '(' E ')' { $$.e = "(" + $2.e + ")"; 
                $$.d = "(" + $2.d + ")"; }
  ;
  
%%

void insere_simbolo( TipoDecl tipo, string nome, int linha, int coluna){
    if (ts.count( nome ) == 0){
        ts[nome] = Simbolo{tipo,linha,coluna};
    }else if(tipo == Var && ts[nome].tipo == Var){
        ts[nome] = Simbolo{tipo,linha,coluna};
    }
    else {
        ceer << "Variável '" << nome << "' já declarada na linha: " << linha
            << ", coluna: " << coluna << endl;
        exit(1)
    }
};

void checa_simbolo(){
    if(ts.count( nome ) > 0){
        if(modificavel) {
            printf('h');
        }
    }else{
        ceer << "Variável '" << nome << "' não declarada "<< endl;
        exit(1);
    }
}

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}