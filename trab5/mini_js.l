%{
int token( int tk );
string lexema;
size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();
    while( pos != string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }
    strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
%}

D  	    [0-9]
L   	[A-Za-z_]
INT	    {D}+
DOUBLE  {D}+"."{D}+([Ee][+\-]?{D}+)?
ID      {L}({L}|{D})*
STRING	\"(\"\"|\\\"|[^\"])*\"
STRING2	\'(\'\'|\\\'|[^\'])*\'
BOOLEAN    "true"|"false" 

%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { linha++; coluna = 0; }

{DOUBLE}   { return token( CDOUBLE ); }
{INT}	   { return token( CINT ); } 
{STRING}   { return token( CSTRING ); }
{STRING2}  { return token( CSTRING ); }
{BOOLEAN}  { return token( BOOLEAN ); }	

	

"&&"	   { return token( AND ); }
"||"	   { return token( OR ); }
"<="	   { return token( ME_IG ); }
">="	   { return token( MA_IG ); }
"!="	   { return token( DIF ); }
"=="	   { return token( IGUAL ); }

"+="       { return token( MAIS_IGUAL ); }
"++"       { return token( MAIS_MAIS ); }

"let"      { return token( LET ); }
"const"    { return token( CONST ); }
"var"      { return token( VAR ); }
"if"       { return token( IF ); }
"else"     { return token( ELSE ); }
"for"      { return token( FOR ); }
"while"    { return token( WHILE ); }
"function" { return token( FUNCTION ); }
"return"   { return token( RETURN );}

"asm{".*"}"  {  
                vector<string> v;
                string text(yytext);
                string cleanText = text.substr(4,text.length() - 5);
                split( cleanText, v, ' ');
                // for(int i = 0; i < v.size(); i++){
                //     cout << cleanText[i] << endl;
                // }
                // cout << endl;
                coluna += strlen( yytext ); 
                yylval.c = v;
                yylval.c.push_back("^");
                return ASM; }

{ID}       { return token( ID ); }

.          { return token( *yytext ); }

%%

int token( int tk ) {  
  if(tk != ASM){
      yylval.c = vector<string>{ yytext };
      coluna += strlen( yytext ); 
  }
  yylval.linha = linha;
  yylval.coluna = coluna;

  return tk;
}
