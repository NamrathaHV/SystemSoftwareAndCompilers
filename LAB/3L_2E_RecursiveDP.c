/*2E-3L. Write a C program to Construct of recursive descent parsing for the following grammar.
S -> a S a| T
T-> bT | @ where”@ represents null character”*/

#include <stdio.h>
#include <string.h>
char input[100];
int i=0,S(),T();
void main()
{
	printf("\nRecursive descent parsing for the following grammar\n");
 	printf("\nS->aSa|T\nT->bT|@\n");
	printf("\nEnter the string to be checked:");
	gets(input);
	if(S())
	{
		if(input[i]=='\0')
			printf("String is accepted\n");
		else
			printf("String not accepted\n");
	}
	else
		printf("String is not accepted\n");
}
int S()
{
	if(input[i]=='a')
	{
		i++;
		if(S())
		{
			if(input[i]=='a')
			{
				i++;
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else if(T())
	{
		return 1;
	}
	else 
		return 0;
}
int T()
{
	if(input[i]=='b')
	{
		i++;
		if(T())
			return 1;
		else
			return 0;
	}
	else
		return 1;
}










/*#include<bits/stdc++.h>
using namespace std;

char input[100];
char *l;

void match(char c)
{
	if(*l==c)
		(l++);
	else
		cout<<"error\n";
}

void T()
{
	if(*l=='b')
	{
		match('b');
		T();
	}
	else 
		return;
}

void S()
{
	if(*l=='a')
	{
		match('a');
		S();
		match('a');
	}
	else
	{ 
		T();
	}
		
}


int main()
{
	cout<<"\nRecursive descent parsing for the following grammar\n";
 	cout<<"\nS->aSa|T\nT->bT|@\n";
 	cout<<"\nEnter the string ending with $ to be checked:";
 	cin>>input;
 	l=input;
 	S();
 	if(*l=='$')
 		cout<<"\nSuccessfully parsed\n";
 	else
 		cout<<"\nString is not accepted\n";
}*/