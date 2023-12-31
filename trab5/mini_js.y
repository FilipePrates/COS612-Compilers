%{
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
%}

%token ID IF ELSE LET CONST VAR FOR FUNCTION WHILE ASM RETURN BOOLEAN OBJECT FECHA_PARENTESES_FUNC SETA OPEN_BRACKETS_FUNC
%token CDOUBLE CSTRING CINT
%token AND OR ME_IG MA_IG DIF IGUAL
%token MAIS_IGUAL

%right '=' MAIS_IGUAL FECHA_PARENTESES_FUNC SETA 
%nonassoc '<' '>' IGUAL 
%left '+' '-' 
%left '*' '/' '%' OPEN_BRACKETS_FUNC

%left MAIS_MAIS
%right '[' '(' ME_IG MA_IG
%left '.'


%%

S : CMDs { print(resolve_enderecos( $1.c + "." + funcoes)); }
  ;

CMDs : CMDs CMD  { $$.c = $1.c + $2.c; };
     |           { $$.clear();}
     ;
     
CMD : CMD_FUNCTION
    | CMD_LET ';'
    | CMD_VAR ';'
    | CMD_CONST ';'
    | CMD_IF
    | CMD_FOR
    | CMD_WHILE 
    | RETURN E ';'
      { if (in_func) {
        $$.c = $2.c + "'&retorno'" + "@" + "~"; 
       }else{
        cerr << "Erro: Não é permitido 'return' fora de funções." << endl;
        exit( 1 );    
       }
      }
    | RETURN '{' KEYS_VALUE_PAIRS '}' ';'
      { if (in_func) {
        $$.c = vector<string>{"{}"} + $3.c + "'&retorno'" + "@" + "~";
       }else{
        cerr << "Erro: Não é permitido 'return' fora de funções." << endl;
        exit( 1 );    
       }
      }
    | E ';'
      { $$.c = $1.c + "^"; };
    | '{' EMPILHA_TS CMDs '}' 
      { 
        ts.pop_back();
        $$.c = vector<string>{"<{"} + $3.c + vector<string>{"}>"}; }
    | E ASM ';' 	{ $$.c = $1.c + $2.c; }
    | ';' { $$.clear();}
    ; 


EMPILHA_TS : { ts.push_back( map< string, Simbolo >{} );} 
           ;

LISTA_ARGs : ARGs
        | { ts.push_back( map< string, Simbolo >{} ); 
              $$.clear(); }
           ;
             
ARGs : ARGs ',' E
       { $$.c = $1.c + $3.c;
         $$.contador = $1.contador + 1; }
     | E
       { $$.c = $1.c;
         $$.contador = 1; }
     ;

FUNCTION_ANON : FUNCTION { in_func++; } 
             '(' LISTA_PARAMs ')' '{' CMDs '}'
           { 
             string lbl_endereco_funcao = gera_label( "func_anon" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             $$.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";
             funcoes = funcoes + definicao_lbl_endereco_funcao + $4.c + $7.c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func--;
           }
         ;

FUNCTION_SETA : ID { in_func++; ts.push_back( map< string, Simbolo >{} ); 
            declara_var( Let, $1.c[0], $1.linha, $1.coluna );
            $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
          } SETA E
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
            $$.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";

             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              $2.c + $4.c + "'&retorno'" + "@" + "~";
            ts.pop_back();
            in_func--;
           }
           | ID { in_func++; ts.push_back( map< string, Simbolo >{} ); 
            declara_var( Let, $1.c[0], $1.linha, $1.coluna );
            $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
          }  OPEN_BRACKETS_FUNC CMDs '}'
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
            $$.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";
             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              $2.c + $4.c + "'&retorno'" + "@" + "~"; 
            ts.pop_back();
            in_func--;
           }
           | '(' LISTA_PARAMs { in_func++; } FECHA_PARENTESES_FUNC E
           {
             string lbl_endereco_funcao = gera_label( "func_seta" );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             $$.c = vector<string>{"{}"} + "'&funcao'" +
                    lbl_endereco_funcao + "[<=]";

             funcoes = funcoes + definicao_lbl_endereco_funcao + 
              $2.c + $5.c + "'&retorno'" + "@" + "~"; 

            ts.pop_back();
            in_func--; 
           }
         
         ;

CMD_FUNCTION : FUNCTION ID { declara_var( Var, $2.c[0], $2.linha, $2.coluna ); in_func++; } 
             '(' LISTA_PARAMs ')' '{' CMDs '}'
           { 
             string lbl_endereco_funcao = gera_label( "func_" + $2.c[0] );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             $$.c = $2.c + "&" + $2.c + "{}"  + "=" + "'&funcao'" +
                    lbl_endereco_funcao + "[=]" + "^";
             funcoes = funcoes + definicao_lbl_endereco_funcao + $5.c + $8.c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             in_func--;
           }
         ;
         
LISTA_PARAMs : PARAMs
            | EMPILHA_TS { $$.clear(); }
           ;

PARAMs : PARAMs ',' PARAM  
       { // Cria var local
         declara_var( Let, $3.c[0], $3.linha, $3.coluna ); 
         $$.c = $1.c + $3.c + "&" + $3.c + "arguments" + "@" + to_string( $1.contador )
                + "[@]" + "=" + "^"; 
         if( $3.valor_default.size() > 0 ) {
          string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          $$.c = $$.c + declara_var( Var, "placeholder", 1, 1 ) +
          $3.c + "@" + "placeholder" + "@" + "!=" +
          lbl_true + "?" + $3.c + $3.valor_default + "=" + "^" +
          lbl_fim_if + "#" + definicao_lbl_true + definicao_lbl_fim_if;
         }
         $$.contador = $1.contador + $3.contador; 
       }
     | PARAM 
       { // a & a arguments @ 0 [@] = ^
         ts.push_back( map< string, Simbolo >{} ); 
         declara_var( Let, $1.c[0], $1.linha, $1.coluna ); 
         $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
                
         if( $1.valor_default.size() > 0 ) {
           string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
           $$.c = $$.c + declara_var( Var, "placeholder", 1, 1 ) +
           $1.c + "@" + "placeholder" + "@" + "!=" +
            lbl_true + "?" + $1.c + $1.valor_default + "=" + "^" +
            lbl_fim_if + "#" + definicao_lbl_true + definicao_lbl_fim_if;          }
         $$.contador = 1; 
       }
     ;
     
PARAM : ID 
      { $$.c = $1.c;      
        $$.contador = 1;
        $$.valor_default.clear();
      }
    | ID '=' E
      { // Código do IF
        $$.c = $1.c;
        $$.contador = 1;
        $$.valor_default = $3.c;         
      }
    ;
CMD_FOR : FOR '(' PRIM_E ';' E ';' E ')' CMD 
        { string lbl_fim_for = gera_label( "fim_for" );
          string lbl_condicao_for = gera_label( "condicao_for" );
          string lbl_comando_for = gera_label( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;
          
          $$.c = $3.c + definicao_lbl_condicao_for +
                 $5.c + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + $9.c + 
                 $7.c + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
        ;

CMD_WHILE : WHILE '(' E ')' CMD
    { string lbl_comeco_while = gera_label("comeco_while");
      string lbl_fim_while = gera_label("fim_while");
      string lbl_condicao_while = gera_label("condicao_while");
      string definicao_lbl_comeco_while = ":" + lbl_comeco_while;
      string definicao_lbl_fim_while = ":" + lbl_fim_while;
      string definicao_lbl_condicao_while = ":" + lbl_condicao_while;
      $$.c = definicao_lbl_condicao_while + $3.c +
              lbl_comeco_while + "?" +
              lbl_fim_while + "#" +
              definicao_lbl_comeco_while + $5.c +
              lbl_condicao_while + "#" +
              definicao_lbl_fim_while;}
  ;

PRIM_E : CMD_LET 
       | CMD_VAR
       | CMD_CONST
       | E  
         { $$.c = $1.c + "^"; }
       ;

CMD_LET : LET LET_VARs { $$.c = $2.c; }
        ;

LET_VARs : LET_VAR ',' LET_VARs { $$.c = $1.c + $3.c; } 
         | LET_VAR
         ;

LET_VAR : ID  
          { $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna );}
        | ID '=' E
          { 
            $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna ) + 
                   $1.c + $3.c + "=" + "^"; }
        | ID '=' '{' '}'
            { $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna ) + 
                     $1.c + "{}" + "=" + "^";}
        | ID '=' '{' KEYS_VALUE_PAIRS '}'
            { $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna ) + 
            $1.c + "{}" + "=" + $4.c  + "^";}
        | ID '=' FUNCTION_SETA
            { $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna ) + 
            $1.c + $3.c + "=" + "^";}

        ;
  
CMD_VAR : VAR VAR_VARs { $$.c = $2.c; }
        ;
        
VAR_VARs : VAR_VAR ',' VAR_VARs { $$.c = $1.c + $3.c; } 
         | VAR_VAR
         ;

VAR_VAR : ID  
          { $$.c = declara_var( Var, $1.c[0], $1.linha, $1.coluna ); }
        | ID '=' E
          {  $$.c = declara_var( Var, $1.c[0], $1.linha, $1.coluna ) + 
                    $1.c + $3.c + "=" + "^"; }
        | ID '=' '{' '}'
            { $$.c = declara_var( Var, $1.c[0], $1.linha, $1.coluna ) + 
                     $1.c + "{}" + "=" + "^";}
        | ID '=' '{' KEYS_VALUE_PAIRS '}'
            { $$.c = declara_var( Var, $1.c[0], $1.linha, $1.coluna ) + 
            $1.c + "{}" + "=" + $4.c  + "^";}
        ;
  
CMD_CONST: CONST CONST_VARs { $$.c = $2.c; }
         ;
  
CONST_VARs : CONST_VAR ',' CONST_VARs { $$.c = $1.c + $3.c; } 
           | CONST_VAR
           ;

CONST_VAR : ID '=' E
            { $$.c = declara_var( Const, $1.c[0], $1.linha, $1.coluna ) + 
                     $1.c + $3.c + "=" + "^";}
          | ID '=' '{' '}'
            { $$.c = declara_var( Const, $1.c[0], $1.linha, $1.coluna ) + 
                     $1.c + "{}" + "=" + "^";}
          | ID '=' '{' KEYS_VALUE_PAIRS '}'
            { $$.c = declara_var( Let, $1.c[0], $1.linha, $1.coluna ) + 
            $1.c + "{}" + "=" + $4.c  + "^";}
          ;

CMD_IF : IF '(' E ')' CMD ELSE CMD
         { string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
            $$.c = $3.c +                       // Codigo da expressão
                   lbl_true + "?" +             // Código do IF
                   $7.c + lbl_fim_if + "#" +    // Código do False
                   definicao_lbl_true + $5.c +  // Código do True
                   definicao_lbl_fim_if         // Fim do IF
                   ;
         }
        | IF '(' E ')' CMD
        { string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          $$.c = $3.c + lbl_true + "?" + lbl_fim_if + "#" +
          definicao_lbl_true + $5.c + definicao_lbl_fim_if;
        } 
       ;
       
LVALUEPROP : E '[' E ']' { $$.c = $1.c + $3.c; } 
           | E '.' ID  { $$.c = $1.c+ $3.c; } 
           ;

KEYS_VALUE_PAIRS : ID ':' E 
                  { $$.c = $1.c + $3.c + "[<=]";}
                 | ID ':' '{' '}'
                  { $$.c = $1.c + "{}" + "[<=]";}
                 | ID ':' '{' KEYS_VALUE_PAIRS '}' 
                  { $$.c = $1.c + "{}" + $4.c + "[<=]";}
                 | ID ':' E ',' KEYS_VALUE_PAIRS
                  {$$.c =  $5.c + $1.c + $3.c + "[<=]"; }
                 | ID ':' '{' '}' ',' KEYS_VALUE_PAIRS
                  {$$.c =  $6.c + $1.c + "{}" + "[<=]"; }
                 | ID ':' '{' KEYS_VALUE_PAIRS '}' ',' KEYS_VALUE_PAIRS
                  { $$.c = $7.c + $1.c + "{}" + $4.c + "[<=]";}
                 ;

ARRAY_ELEMENTS :
                E
               { $$.c = vector<string>{"[]"} + to_string(arrayElCounter) + $1.c + "[<=]"; arrayElCounter++;}
               | '{' '}'
                { $$.c = vector<string>{"[]"} + to_string(arrayElCounter) + "{}" + "[<=]"; arrayElCounter++;}
               | '{' KEYS_VALUE_PAIRS '}'
                { $$.c = vector<string>{"[]"} + to_string(arrayElCounter) + "{}" + $2.c + "[<=]"; arrayElCounter++;}
                | ARRAY_ELEMENTS ','  E 
               { $$.c = $1.c + to_string(arrayElCounter) + $3.c + "[<=]"; arrayElCounter++;}
               |  ARRAY_ELEMENTS  ',' '{' '}'
                { $$.c = $1.c + to_string(arrayElCounter) + "{}" + "[<=]"; arrayElCounter++;}
               |  ARRAY_ELEMENTS ',' '{' KEYS_VALUE_PAIRS '}'
                { $$.c = $1.c + to_string(arrayElCounter)  + "{}" + $4.c + "[<=]"; arrayElCounter++;}
               ;
E : ID '=' E
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c + $3.c + "="; }
  | ID  '=' '{' '}'
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c + "{}" + "="; }
  | ID '=' '{' KEYS_VALUE_PAIRS '}'
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c + "{}" + "=" + $4.c; }
  | LVALUEPROP '=' E
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c + $3.c + "[<=]" + "^" + $3.c; }
  | LVALUEPROP '=' '{' '}'
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c + "{}" + "[<=]"; }
  | LVALUEPROP '=' '{' KEYS_VALUE_PAIRS '}'
    { if (!in_func) checa_simbolo( $1.c[0], true );  $$.c = $1.c  + "{}" + $4.c + "[<=]" + "[<=]"; }
  | ID MAIS_IGUAL E 
    { $$.c = $1.c + $1.c + "@" + $3.c + "+" + "="; }
  | LVALUEPROP MAIS_IGUAL E
    { $$.c = $1.c + $1.c + "[@]" + $3.c + "+" + "[<=]"; }
  | E '<' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '>' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '+' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '-' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '*' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '/' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E '%' E
    { $$.c = $1.c + $3.c + $2.c; }
  | E IGUAL E
    { $$.c = $1.c + $3.c + "=="; }
  | E MAIS_MAIS
    { $$.c = vector<string>{} + $1.c[0] + $1.c[0] + "@" + "1" + "+" + "="; }
  | '-' E
    { $$.c = "0" + $2.c + $1.c; } 
  | E '(' LISTA_ARGs ')'
    { 
    $$.c = $3.c + to_string( $3.contador ) + $1.c + "$";
    }
  | CDOUBLE
  | CINT
  | BOOLEAN
  | CSTRING
  | ID 
    { if (!in_func) checa_simbolo( $1.c[0], false ); $$.c = $1.c + "@"; } 
  | LVALUEPROP
    { if (!in_func) checa_simbolo( $1.c[0], false ); $$.c = $1.c + "[@]"; } 
  | '(' E ')'
    { $$.c = $2.c; }
  | '[' ']'
    { $$.c = {"[]"}; }
  | '[' ARRAY_ELEMENTS ']'
  { $$.c = $2.c; arrayElCounter = 0;}
  | FUNCTION_ANON
  | FUNCTION_SETA
  ;
  
  
%%

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