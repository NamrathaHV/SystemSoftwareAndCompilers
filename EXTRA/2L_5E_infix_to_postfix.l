/* 5E-2L. YACC program for Conversion of Infix to Postfix expression */


%{
#include "y.tab.h"
%}
ALPHA [A-Z a-z]
DIGIT [0-9]

%%
{ALPHA}({ALPHA}|{DIGIT})*  {return ID;}
{DIGIT}+                   {yylval=atoi(yytext); return ID;}
[ \t\n]                    yyterminate();
.                          {return yytext[0];}
%%

