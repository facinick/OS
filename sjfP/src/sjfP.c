#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int pid,at,bt,wt,ct,tat,done,BT; 	// BT to keep a copy of bt as bt gets altered.
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
			p[i].BT = p[i].bt;
			printf("enter arrival time for process %d\n",p[i].pid);
			scanf("%d",&p[i].at);
			p[i].done = 0;
		}


//////////////////////////////////////////////////////////////////////////////////////////////////////

	int DONE=1;
	for( i=0; i<50; i++ )
	{
		DONE=1;
		x = least_burst_time(time);
		time++;

		p[x].bt--;

			if( p[x].bt == 0 )
			{
				p[x].done = 1;
				p[x].ct = time;
				//printf("\t%d\t",p[x].ct);
			}

		for( int k=0; k<n; k++ )
		{
			if(p[k].done == 0)
				DONE=0;
		}
		if( DONE== 1)
			break;

	}

//////////////////////////////////////////////////////////////////////////////////////////////////////
	for( i=0; i<n; i++ )
		{

		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].BT;

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

int least_burst_time(int time)	// returns process with minimum burst time which is available
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
