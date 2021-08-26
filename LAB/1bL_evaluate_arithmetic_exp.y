/*1(b)L. Write YACC program to evaluate arithmetic expression involving operators: +, -, *,
and / */

%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(), yylex();
%}

%token NUMBER 

%left '+''-'
%left '*''/'

%%

E : T { printf("Result = %d\n", $$); }
T : T'+'T { $$ = $1 + $3; }
| T '-' T { $$ = $1 - $3; }
| T '*' T { $$ = $1 * $3; }
| T '/' T { if($3==0){printf("Divide by zero error\n");exit(0);}
	  else {$$ = $1 / $3; }}
| '-' NUMBER { $$ = -$2; }
| '('T')'{ $$ = $2; }
| NUMBER { $$ = $1; }
;

%%

int main() 
{
	printf("Enter the Expression: \n");
	yyparse();
	printf("Valid Expression\n");

}

int yyerror() 
{
	printf("\nInvalid Expression\n");
	exit(0);
}

