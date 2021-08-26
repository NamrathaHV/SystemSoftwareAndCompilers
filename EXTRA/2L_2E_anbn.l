/* 2E-2L. YACC program to recognize string with grammar { anbn | n≥0 } */

%{
#include "y.tab.h"
%}

%%
[aA] {return A;}
[bB] {return B;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}

