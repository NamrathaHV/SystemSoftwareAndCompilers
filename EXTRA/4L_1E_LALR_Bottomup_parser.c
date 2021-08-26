/* 1E-4L. Design a LALR Bottom Up Parser for the given grammar
S → AA
A → aA
A → b */

#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
	puts("\n GRAMMAR:\n S -> AA  \n A  -> aA  \n A -> b   \n");
	puts("Enter the Input String: ");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT");
	puts("Stack \t Input \t Action");
	printf("\n$%s\t%s$\t--",stk,a);
	for(k=0,i=0; j<c; k++,i++,j++)
	{
		if(a[j]=='a')
		{
			stk[i]=a[j];
			stk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%s a",stk,a,act);
			check();
		}
		else
		{
			stk[i]=a[j];
			stk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%s b",stk,a,act);
			check();
		}
	}
	if(strcmp("S",stk) == 0 && a[0] == ' ')
	    printf("\n$%s\t%s$\tACCEPT\n",stk,a);
	else
	    printf("\n$%s\t%s$\tREJECT\n",stk,a);
}
void check()
{
	for(z=0; z<c; z++){
		if(stk[z]=='b')
		{
			stk[z]='A';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: A->b");
			
		}
	}
	for(z=0; z<c; z++)
	{	if(stk[z]=='a' && stk[z+1]=='A')
		{
			stk[z]='A';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: A->aA");
			i=i-1;
			z = -1;
		}
	}
	for(z=0; z<c; z++){
		if(stk[z]=='A' && stk[z+1]=='A')
		{
			stk[z]='S';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: S->AA");
			i=i-1;
		}
	}
}