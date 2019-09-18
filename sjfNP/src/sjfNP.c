/*
 ============================================================================
 Name        : sjfNP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int pid,at,bt,wt,ct,tat,done;

}process;
process p[10];
int i,j,n,x,k;
int least_burst_time(int);
int main(void) {

		int time = 0;
		int TAT=0,WT=0;
		printf("enter number of processes\n");
		scanf("%d",&n);

		for(i=0; i<n; i++)
		{
			p[i].pid = i;
			printf("enter burst time for process %d\n",p[i].pid);
			scanf("%d",&p[i].bt);
			printf("enter arrival time for process %d\n",p[i].pid);
			scanf("%d",&p[i].at);
			p[i].done = 0;
		}
	time=0;
	for( i=0; i<n; i++ )
	{
		x = least_burst_time(time);
		printf("p%d\t",p[x].pid);

		p[x].ct = time+p[x].bt;
		time = time+ p[x].bt;
		p[x].done = 1;
		p[x].tat = p[x].ct - p[x].at;
		p[x].wt = p[x].tat - p[x].bt;
	}

	for( i=0; i<n; i++ )
		{
			TAT = TAT+p[i].tat;
			WT = WT+p[i].wt;
		}
		printf("\naverage waiting time = %f\n",(float)WT/n);
		printf("average turn around time = %f\n",(float)TAT/n);

	return EXIT_SUCCESS;
}
int least_burst_time(int time)
{
	int id = 0;
	process temp;
	for( j=0; j<n; j++ )
	{
		for(k=0; k<n-j-1; k++ )
		{
			if( p[k].bt > p[k+1].bt )
			{
				temp = p[k];
				p[k] = p[k+1];
				p[k+1] = temp;
			}
		}
	}
	for( j=0; j <n; j++ )
	{
		if( p[j].at <= time && p[j].done ==0 )
		{
			id = j;
			break;
		}
	}
	return id;
}
