/* 3E-1L. Lex Program for checking a valid URL */

%{
#include<stdio.h>
%}
%%
((http)|(ftp))s?:\/\/[a-zA-Z0-9]{2,}(\.[a-z]{2,})+(\/[a-zA-Z0-9+=?]*)*  {printf("Valid URL\n");}
.+  {printf("Invalid URL\n");}
%%
int main()
{
	printf("Enter the URL: ");
	yylex();
	return 0;
}


