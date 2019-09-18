/*
 ============================================================================
 Name        : detect_deadlock.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#define m 3

typedef struct{
	int pid;
	int allocated[m];
	int request[m];
	int finish;
}process;


int main(void) {

		process p[10];
		int n,i,j,c=0;
		printf("enter number of processes\n");
		scanf("%d",&n);

		int work[m] = {0};
		for(j=0; j<m; j++)
		{
			printf("enter work for resource %d\n",j);
			scanf("%d",&work[j]);
		}
		for( i=0; i<n; i++ )
		{
			c=0;
			p[i].pid = i;
			for(j=0; j<m; j++)
			{
				printf("enter allocated for process %d and resource %d\n", p[i].pid, j);
				scanf("%d",&p[i].allocated[j]);
				if( p[i].allocated[j] != 0 )
					c++;

			}
			for(j=0; j<m; j++)
			{
				printf("enter request for process %d and resource %d\n", p[i].pid, j);
				scanf("%d",&p[i].request[j]);
			}
			if(c!=0)
			p[i].finish = 0;
			else p[i].finish = 1;


		}
		printf("pid \t allocatoin \t request\n");
		for(i=0; i<n; i++ )
		{
			printf("process %d \t",p[i].pid);
			for(j=0; j<m; j++ )
			{
				printf("%d",p[i].allocated[j]);
			}
			printf("\t");
			for(j=0; j<m; j++ )
			{
			printf("%d",p[i].request[j]);
			}
			printf("\t");
			printf("%d",p[i].finish);

			printf("\n");
		}

		int count=0;
		int allocate = 1;
		int sequence[n];
		int k=0;
		while(count!=5)
		{

			for( i=0; i<n; i++ )
			{
				allocate = 1;
				for( j=0; j<m; j++ )		// find if u can grant request
				{
					if( p[i].request[j] > work[j] )
					{
						allocate = 0;
					}
				}
				if( allocate == 1 && p[i].finish == 0 )		// grant request
				{
					sequence[k++] = p[i].pid;
					for( j=0; j<m; j++ )
					{

						work[j] += p[i].allocated[j];
						p[i].allocated[j]-=p[i].allocated[j];;

					}
					p[i].finish = 1;
				}

			}	// else next i
			count++;
		}// after one iteration count increases

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
				printf("request counldnt be granted\n");
			}


	return EXIT_SUCCESS;
}
