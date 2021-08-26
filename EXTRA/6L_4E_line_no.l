/* 4E-6L. Lex program to add line numbers to a given file */


%{
int line_number = 1;
%}

line .*\n    

%%
{line} { printf("%10d %s", line_number++, yytext); } 
%%
  
int yywrap(){} 
  
int main(int argc, char*argv[])
{
	extern FILE *yyin;    
  
	yyin = fopen("6L_1E_input","r");
  
	yylex();
  
	return 0;
}
