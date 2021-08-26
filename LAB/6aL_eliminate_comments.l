/* 6(a)L. Write a LEX program to eliminate comment lines in a C program and copy the resulting
program into a separate file. */

%{
#include<stdio.h>
%}
%%
\/\/(.*) ;
\/\*(.*"\n")*.*\*\/ ;
%%
int main(int argc,char **argv)
{
	yyin=fopen(argv[1],"r");
	yyout=fopen("6aL_output_file.c","w");  //output code in out.c file
	yylex();
	return 0;
}

