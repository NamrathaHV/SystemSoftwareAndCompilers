/* 5E-2L. YACC program for Conversion of Infix to Postfix expression */


%{
#include<stdio.h>
#include<stdlib.h>
char st[50];
int top=0;
char * yytext;
int yyerror();
int yylex();
void A1();
void A2();
void A3();
%}

%token    ID
%left    '+' '-'
%left    '*' '/'
%left    UMINUS

%%
  
S  :  E
   ;
E  :  E'+'{A1();}T{A2();}
   |  E'-'{A1();}T{A2();}
   |  T
   ;
T  :  T'*'{A1();}F{A2();}
   |  T'/'{A1();}F{A2();}
   |  F
   ;
F  :  '('E{A2();}')'
   |  '-'{A1();}F{A2();}
   |  ID{A3();}
   ;
  
%%

int main()
{
    printf("\nEnter Infix Expression:  "); 
    yyparse();
    printf("\n\n");
    return 0;
}

int yyerror()
{
    printf("\nError\n");
    exit(0);
}
void A1()
{
    st[top++]=yytext[0];
}
  
void A2()
{
    printf("%c", st[--top]);
}
  
void A3()
{
    printf("%c", yytext[0]);
}

