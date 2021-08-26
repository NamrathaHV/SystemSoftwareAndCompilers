/* 2E-4L. Consider the grammar
E –> 2E2
E –> 3E3
E –> 4
Perform Shift Reduce parsing for input string “32423”. */


#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
	puts("\nGRAMMAR:\nE -> 2E2  \nE -> 3E3  \nE -> 4   \n");
	puts("Enter Input String: ");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT");
	puts("Stack \t Input \t Action");
	printf("\n$%s\t%s$\t--",stk,a);
	for(k=0,i=0; j<c; k++,i++,j++)
	{
		stk[i]=a[j];
	    stk[i+1]='\0';
		a[j]=' ';
		printf("\n$%s\t%s$\t%s %c",stk,a,act,stk[i]);
		check();
		
	}
	if(strcmp("E",stk) == 0 && a[0] == ' ')
	    printf("\n$%s\t%s$\tACCEPT\n",stk,a);
	else
	    printf("\n$%s\t%s$\tREJECT\n",stk,a);
}
void check()
{
	for(z=0; z<c; z++){
		if(stk[z]=='4')
		{
			stk[z]='E';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: E->4");
		}
	}
	for(z=0; z<c; z++)
	{	if(stk[z]=='2' && stk[z+1]=='E' && stk[z+2]=='2')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: E->2E2");
			i=i-2;
			z = -1;
		}
	}
	for(z=0; z<c; z++)
	{
		if(stk[z]=='3' && stk[z+1]=='E' && stk[z+2]=='3')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE: E->3E3");
			i=i-2;
		}
	}
}