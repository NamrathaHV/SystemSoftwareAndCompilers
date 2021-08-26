/* 1E-1L. Lex Program to count no of vowels and consonants in a given string */

%{
#include<stdio.h>
#include<stdlib.h>
int v=0,c=0;
%}

%%
[aeiouAEIOU] { v++;}
[a-zA-Z] { c++;}
%%

int main()
{	
	printf("Enter the string: \n");
	yylex();
	printf("The number of vowels in the string is: %d\n",v);
	printf("The number of consonants in the string is: %d\n",c);
	return 0;
}

