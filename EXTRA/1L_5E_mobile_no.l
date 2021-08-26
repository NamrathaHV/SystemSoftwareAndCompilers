/* 5E-1L. Lex program to check valid Mobile Number */

%{
#include<stdio.h>
%}
%%
"\n" {printf("\nEnter Mobile number: ");}
[6-9][0-9]{9} {printf("Valid Mobile number\n");}
.* {printf("Invalid Mobile number\n");}
%%
int main()
{
	printf("\nEnter mobile Number: ");
	yylex();
	return 0;
}


