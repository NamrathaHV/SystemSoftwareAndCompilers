/* 3E-2L. YACC program to recognize strings of { anb | n≥5 } */

%{
#include "y.tab.h"
%}

%%
[aA] {return A;}
[bB] {return B;}
.    {return yytext[0];}
[ \t\n]   {return NL;}
%%

int yywrap()
{
	return 1;
}

