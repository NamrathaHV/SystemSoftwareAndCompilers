/*2L. Develop, Implement and Execute a program using YACC tool to recognize all strings
ending with b preceded by n a’s using the grammar an b (note: input n value) */

%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex();
%}

%token A B

%%

str: s '\n'
s : x B
| B
;
x : x A
| A
;

%%

int main()
{
        printf("Enter string: \n");
        if(!yyparse())
                printf("Valid String\n ");
}

int yyerror()
{
        printf("Invalid String\n");
        exit(0);
}

