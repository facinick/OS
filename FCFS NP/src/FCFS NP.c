/*
 ============================================================================
 Name        : FCFS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : French Connection in C, Sexy-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct{

	int at, bt, tat, ct, wt;
	int pid, done;

}process;
int first(void);
int i,j,n,x;
process p[20];
int main(void) {

	int time = 0;
	int TAT=0,WT=0;

	printf("enter number of processes\n");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		p[i].pid = i;
		printf("enter burst time for process %d",p[i].pid);
		scanf("%d",&p[i].bt);
		printf("enter arrival time for process %d",p[i].pid);
		scanf("%d",&p[i].at);
		p[i].done = 0;
	}

	printf("p%d\t",x);

	for( i=0; i<n; i++ )
	{
		x = first();

		printf("p%d\t",x);

		p[x].ct = time+p[x].bt;

		time = time+p[x].bt;

		p[x].tat = p[x].ct - p[x].at;

		p[x].wt = p[x].tat-p[x].bt;

		p[x].done = 1;

	}

	printf("%d",TAT);

	for( i=0; i<n; i++ )
	{

		TAT = TAT+p[i].tat;
		WT = WT+p[i].wt;
	}
	printf("average waiting time = %f\n",(float)WT/n);
	printf("average turn around time = %f\n",(float)TAT/n);

	return EXIT_SUCCESS;
}
int first()
{
	int least = 10000;
	int index = 0;
	for( j=0; j<n; j++ )
	{
		if( p[j].at < least && p[j].done !=1 )
		{
			least = p[j].at;
			index = j;
		}
	}
	return index;
}
