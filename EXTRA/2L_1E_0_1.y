/* 1E-2L. YACC program which accept strings that starts and ends with 0 or 1 */


%{
#include<stdio.h>
#include <stdlib.h>
void yyerror();
int yylex();
%}

%token ZERO ONE

%%

r : s {printf("\nSequence Accepted\n\n");}
;

s : n
| ZERO a
| ONE b
;

a : n a
| ZERO
;

b : n b
| ONE
;

n : ZERO
| ONE
;

%%
void yyerror() 
{
	printf("\nSequence Rejected\n");        
}
int main()
{
	printf("\nEnter The String : ");
	yyparse();
	printf("\n");
	return 0;
}


