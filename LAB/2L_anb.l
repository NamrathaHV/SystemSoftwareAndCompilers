/*2L. Develop, Implement and Execute a program using YACC tool to recognize all strings
ending with b preceded by n a’s using the grammar an b (note: input n value) */

%{
#include "y.tab.h"
%}
%%
[aA] return A;
[bB] return B;
. return yytext[0];
\n return yytext[0];
%%
