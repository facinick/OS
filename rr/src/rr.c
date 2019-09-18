#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n,i,j,q;
	printf("enter number of processes\n");
	scanf("%d",&n);

	printf("enter q\n");
	scanf("%d",&q);

	int at[n], bt[n], ct[n], pno[n], ct[n], wt[n], tat[n];

	for(i=0; i<n; i++)
	{
		pno[i] = i;
		printf("enter at and bt for process %d",n);
		scanf("%d%d",&at[i],&bt[i]);
	}
	int temp;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(at[j]>at[j+1])
			{
				temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;

				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;

				temp = pno[j];
				pno[j] = pno[j+1];
				pno[j+1] = temp;
			}
		}
	}




	return EXIT_SUCCESS;
}
