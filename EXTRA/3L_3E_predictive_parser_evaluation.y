/* 3E-3L. Implement a predictive parser for an expression that generates arithmetic expressions with digits, +,* */


%{
	#include<stdio.h>
%}
%union
{
	double dval;
}
%token <dval> DIGIT
%type <dval> expr
%type <dval> term
%type <dval> factor

%%

line: expr '\n' {printf("%g\n",$1);}
	;
expr: expr '+' term {$$=$1 + $3 ;}
	| term
	;
	
term: term '*' factor {$$=$1 * $3 ;}
	| factor
	; 

factor: '(' expr ')' {$$=$2 ;}
	  | DIGIT
	  ;

%%

int main()
{
	printf("Enter the string: ");
	yyparse();
	return 0;
}

yyerror(char *s)
{
	printf("%s",s);
}

