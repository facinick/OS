/*
 ============================================================================
 Name        : bankers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define m 3

typedef struct{
	int pid;
	int allocated[m];
	int max[m];
	int need[m];
	int finish;
}process;

int main(void) {

	int request[m];
	int i, j, n;
	printf("enter number of processes\n");
	scanf("%d",&n);

	process p[n];
	int work[m]={0};
	int work_request[m]={0};
	int sequence[n];

	for( j=0; j<m; j++ )
	{
		printf("enter work in order\n");
		scanf("%d",&work[j]);
		work_request[j] = work[j];
	}

	for(i=0; i<n; i++)
	{
		p[i].pid = i;

		for(j=0; j<m; j++)
		{
			printf("enter allocated for process %d and resource %d\n",p[i].pid,j);
			scanf("%d",&p[i].allocated[j]);
		}
		for(j=0; j<m; j++)
		{
			printf("enter max for process %d and resource %d\n",p[i].pid,j);
			scanf("%d",&p[i].max[j]);
		}
		for(j=0; j<m; j++)
		{
			p[i].need[j] = p[i].max[j] - p[i].allocated[j];
		}

		p[i].finish = 0;

	}

	int allocate;
	int k=0;
	int count=0;

	while(count!=5)
	{

		for(i=0; i<n; i++)
		{
			allocate = 1;
			for(j=0; j<m; j++)
			{
				if( p[i].need[j] > work[j])
				{
					allocate = 0;
				}
			}
			if( allocate == 1 && p[i].finish == 0 )
			{
				sequence[k++] = p[i].pid;		// add to sequence

				for(j=0; j<m; j++)
				{
					work[j] += p[i].allocated[j] ;
					p[i].allocated[j] -= p[i].allocated[j];
					p[i].need[j] = 0;
				}

				p[i].finish = 1;				// finished

			}

		}
		count++;
	}
	int done = 1;
	for(i=0; i<n; i++)
	{	if( p[i].finish == 0 )
			done = 0;
	}
	if( done == 1 )
	{
		printf("allocated to all\n");
		printf("sequence:\n");
		for( i=0; i<n; i++ )
		{
			printf("p%d\t",sequence[i]);
		}
		printf("\nwork matrix\n");
		for( j=0; j<m; j++ )
				{
					printf("%d\t",work[j]);
		}
	}
	else{
		printf(" not possible\n ");
	}


//	/////////////////////////////////////////////////////////////////////////////////////////
//	int request_process;
//	printf("enter requesting process 0 to m\n");
//	//scanf("%d"&request_process);
//	for( j=0; j<m; j++ )
//	{
//		printf("enter request in order\n");
//		scanf("%d",&request[j]);
//	}
//	allocate = 1;
//	for(j=0; j<m; j++)
//	{
//		if(work_request[j]<request[j] || (p[request_process].need[j] < request[j] ) )
//				{
//					allocate = 0;
//				}
//	}
//	if( allocate == 1 )
//	{
//		work[j] += p[i].allocated[j] ;
//		p[i].allocated[j] -= p[i].allocated[j];
//		p[i].need[j] = 0;
//	}

	return EXIT_SUCCESS;
}
