/* 3E-4L. Consider the following grammar-
S → ( L ) | a
L → L , S | S
Parse the input string (a , ( a , a ) ) using a shift-reduce parser. */

#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
	puts("\nGRAMMAR:\nS -> (L) | a  \nL -> L,S | S   \n");
	puts("Enter Input String: ");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT");
	puts("\nSTACK \t\t INPUT \t\t\t ACTION");
	printf("\n$%s\t\t%s$\t\t--",stk,a);
	for(k=0,i=0; j<c; k++,i++,j++)
	{
		stk[i]=a[j];
	    stk[i+1]='\0';
		a[j]=' ';
		printf("\n$%s\t\t%s$\t\t%s %c",stk,a,act,stk[i]);
		check();
		
	}
	if(strcmp("S",stk) == 0 && a[0] == ' ')
	    printf("\n$%s\t\t%s$\t\tACCEPT\n",stk,a);
	else
	    printf("\n$%s\t\t%s$\t\tREJECT\n",stk,a);
}
void check()
{
	for(z=0; z<c; z++){
		if(stk[z]=='a')
		{
			stk[z]='S';
			stk[z+1]='\0';
			printf("\n$%s\t\t%s$\t\t%s",stk,a,"REDUCE: S->a");
			
		}
	}
	for(z=0; z<c; z++){
	    if(z!=0 && stk[z-1]==',' && stk[z] == 'S')
	    {
	        stk[z]='S';
			stk[z+1]='\0';
			break;
	    }
	    else if(stk[z]=='S')
		{
			stk[z]='L';
			stk[z+1]='\0';
			printf("\n$%s\t\t%s$\t\t%s",stk,a,"REDUCE: L->S");
			break;
		}
	}  
	for(z=0; z<c; z++)
	{	
		if(stk[z]=='(' && stk[z+1]=='L' && stk[z+2]==')')
		{
			stk[z]='S';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t\t%s$\t\t%s",stk,a,"REDUCE: S->(L)");
			i=i-2;
			z = -1;
		}
	}
	for(z=0; z<c; z++){
		if(stk[z]=='L' && stk[z+1]==',' && stk[z+2]=='S')
		{
			stk[z]='L';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t\t%s$\t\t%s",stk,a,"REDUCE: L->L,S");
			i=i-2;
		}
	}
	/*for(z=0; z<c; z++)
		if(stk[z]=='L' && stk[z+1]==',' && stk[z+2]=='L')
		{
		    
			stk[z]='L';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,"REDUCE TO L");
			i=i-2;
		}*/
	
}