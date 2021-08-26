/*1E-2L. YACC program which accept strings that starts and ends with 0 or 1 */


%{
#include "y.tab.h"
extern int yylval;
%}

%%

0 {yylval = 0; return ZERO;}

1 {yylval = 1; return ONE;}

.	 ;

[ \n\t]  {yylval = 2; return 0;}

%%

