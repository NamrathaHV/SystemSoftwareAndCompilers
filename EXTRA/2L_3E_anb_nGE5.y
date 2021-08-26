/* 3E-2L. YACC program to recognize strings of { anb | n≥5 } */

%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex();
%}
  
%token A B NL

%%

S: A A A A I B NL { printf("Valid String\n"); exit(0);}
;
I: A I
| A
;
%%
  
int yyerror()
{
	printf("Invalid String\n");
	exit(0);
}
  
int main()
{
	printf("\nEnter the String: ");
	yyparse();
	return 0;
}

