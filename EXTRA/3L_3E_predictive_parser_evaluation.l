/* 3E-3L. Implement a predictive parser for an expression that generates arithmetic expressions with digits, +,* */

%{
#include "y.tab.h"
%}

%%
[0-9]+	{ yylval.dval=atof(yytext);	return DIGIT; }
\n|.	return yytext[0];
%%
