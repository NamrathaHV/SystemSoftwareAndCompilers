/* 1E-7L. C program for FCFS algorithm */



#include<stdio.h>

void findWaitingTime(int processes[], int n,int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0,s,t,i;
	findWaitingTime(processes, n, bt, wt);
	findTurnAroundTime(processes, n, bt, wt, tat);

	printf("\nProcesses | Burst time | Waiting time | Turn around time\n");
	for (i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("\t\t%d ", bt[i] );
		printf("\t\t%d",wt[i] );
		printf("\t\t%d\n",tat[i] );
	}
	s=(float)total_wt / (float)n;
	t=(float)total_tat / (float)n;
	printf("\nAverage waiting time = %d\n",s);
	printf("Average turn around time = %d\n",t);
}

int main()
{
	int i,n;
	printf("Enter the no. of process: ");
	scanf("%d",&n);
	int burst_time[n],processes[n];
	for(i=0;i<n;i++)
	{
		processes[i]=i+1;
	}
	printf("Enter the burst_time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst_time[i]);
	}
	findavgTime(processes, n, burst_time);
	return 0;
}

