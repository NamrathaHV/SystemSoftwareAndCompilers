/* 7L. Design, develop and implement a C/C++/Java program to simulate the working of Shortest
remaining time and Round Robin (RR) scheduling algorithms. Experiment with different
quantum sizes for RR algorithm. */

#include<stdio.h>
#include<stdlib.h>
int no;
void roundrobin(int,int,int[],int[]);
void srtf();
int main()
{
	int n,tq,choice;
	int bt[10], st[10], i,j,k;
	for(;;)
	{
		printf("\nEnter choice:\n");
		printf("1.Round Robin \n2.SRT \n3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n\nRound robin scheduling algorithm:\n\n");
				printf("Enter the number of process: ");
				scanf("%d",&n);
				printf("Enter burst time for sequences:\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&bt[i]);
					st[i]=bt[i];
				}
				printf("Enter time quantum: ");
				scanf("%d",&tq);
				roundrobin(n,tq,st,bt);
				break;
			case 2: printf("\n\nShortest Remaining Time:\n\n");
				srtf();
				break;
			case 3: exit(0);
				break;
		}
	}
}
void roundrobin(int n, int tq, int st[], int bt[])
{
	int time=0;
	int tat[10],wt[10],i,count=0,swt=0,stat=0,temp1,sq=0,j,k;
	float awt=0.0, atat=0.0;
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp1=tq;
			if(st[i]==0)
			{
				count++;
				continue;
			}
			if (st[i]>tq)
				st[i]=st[i]-tq;
			else if(st[i]>=0)
			{
				temp1=st[i];
				st[i]=0;
			}
			sq=sq+temp1;
			tat[i]=sq;
		}
		if(n==count)
			break;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		swt=swt+wt[i];
		stat=stat+tat[i];
	}
	awt=(float)swt/n;
	atat=(float)stat/n;
	printf("\nProcess no. | Burst time | Waiting time | Turnaround time\n");
	for(i=0;i<n;i++)
		printf("%d \t\t %d \t\t %d \t\t %d \n",i+1,bt[i],wt[i],tat[i]);

	printf("\nAverage waiting time is: %f\nAvg turnaround time is: %f\n\n",awt,atat);
}

void srtf()
{
	int n,j=0,st[10],bt[10],rt[10],remain=0,smallest,time=0,i,endtime,swt=0,stat=0;
	printf("Enter the no. of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time for p[%d]: ",i+1);
		scanf("%d",&st[i]);
		printf("Enter the burst time for p[%d]: ",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	rt[100]=999;
	printf("\nProcess\t| Waiting time\t| Turnaround time\n");
	for(time=0;remain!=n;time++)
	{
		smallest=100;
		for(i=0;i<n;i++)
		{
			if(st[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
			{
				smallest=i;
			}
		}
		rt[smallest]--;
		if(rt[smallest]==0)
		{
			remain++;
			endtime=time+1;
			j=smallest;
			printf("p[%d]\t|\t%d\t|\t%d\n",smallest+1,endtime-bt[j]-st[j],endtime-st[j]);
			swt +=endtime-bt[j]-st[j];
			stat +=endtime-st[j];
		}
	}
	float awt=0.0,atat=0.0;
	awt=(float)swt/n;
	atat=(float)stat/n;
	printf("\nAverage waiting time: %f\n",awt);
	printf("Average turnaround time: %f\n",atat);
}

