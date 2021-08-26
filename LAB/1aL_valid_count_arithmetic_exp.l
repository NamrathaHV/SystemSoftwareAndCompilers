/*1(a)L. Write a LEX program to recognize valid arithmetic expression. Identifiers in the
expression could be only integers and operators could be + and *. Count the identifiers &
operators present and print them separately.*/

%{
int a[]={0,0,0,0},i,valid=1,opnd=0;
void ext();
%}
%x OPER
%%
[a-zA-Z0-9]+ {BEGIN OPER; opnd++;}
<OPER>"+" {if(valid){valid=0;i=0;} else ext();}
<OPER>"-" {if(valid){valid=0;i=1;} else ext();}
<OPER>"*" {if(valid){valid=0;i=2;} else ext();}
<OPER>"/" {if(valid){valid=0;i=3;} else ext();}
<OPER>[a-zA-Z0-9]+ {opnd++; if(valid==0){valid=1;a[i]++;} else ext();}
<OPER>"\n" {if(valid==0)ext(); else return 0;}
.|"\n" ext();
%%
void ext()
{ 
	printf("Invalid Expression \n"); 
	exit(0);
}
int main()
{
	printf("Type the arithmetic Expression \n");
	yylex();
	printf("Valid Arithmetic Expression\n");
	printf("No. of operands/identifiers: %d\n",opnd);
	printf("No. of additions:%d\n No. of subtractions:%d\n",a[0],a[1]);
	printf("No. of multiplication:%d\n No. of divisions:%d\n",a[2],a[3]);
	return 0;
}
