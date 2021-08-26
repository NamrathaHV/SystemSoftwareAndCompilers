/* 4E-2L. YACC program for Binary to Decimal Conversion */


%{
#include<stdio.h>
#include<stdlib.h>
void yyerror();
int yylex();
%}

%token ZERO ONE

%%

N : L {printf("\nDecimal Value: %d\n\n", $$);}
;
L : L B	{$$=$1*2+$2;}
| B {$$=$1;}
;
B : ZERO {$$=$1;}
| ONE {$$=$1;}
;

%%

int main()
{
	printf("\nEnter Binary Number: ");
	while(yyparse());
	return 0;
}
void yyerror()
{
	printf("\nNot a Binary Number\n\n");
	exit(0);
}
