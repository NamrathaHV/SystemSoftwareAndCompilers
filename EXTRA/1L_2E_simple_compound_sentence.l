/* 2E-1L. Lex Program to check whether the sentence is simple or compound */

%{
#include<stdio.h>
int is_simple=1;
%}

%%
[ \t\n]+[aA][nN][dD][ \t\n]+ {is_simple=0;}
[ \t\n]+[bB][uU][tT][ \t\n]+ {is_simple=0;}
[ \t\n]+[oO][rR][ \t\n]+ {is_simple=0;}
. ;
%%

int yywrap()
{
	return 1;
}
int main()
{
	printf("Enter the Sentence: ");
	yylex();
	if(is_simple==1)
	    printf("\nThe given sentence is Simple sentence\n");
	else
	    printf("\nThe given sentence is Compound sentence\n");
	return 0;
}


