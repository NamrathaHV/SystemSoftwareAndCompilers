/* 2E-2L. YACC program to recognize string with grammar { anbn | n≥0 } */


%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex();
%}

%token A B NL

%%
stmt: S NL { printf("\nValid String\n\n"); exit(0); }
;
S: A S B 
|
;
%%

int yyerror()
{
	printf("\nInvalid String\n\n");
	exit(0);
}

int main()
{
	printf("\nEnter the String: ");
	yyparse();
	return 0;
}
