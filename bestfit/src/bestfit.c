#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ps, *bs;

	int bno[20],s[20];
	int p, b, i, j, m=10000,k=0;

	printf("enter number of processes\n");
	scanf("%d",&p);
	printf("enter number of blocks\n");
	scanf("%d",&b);

	ps = (int*) calloc(p,sizeof(int));
	bs = (int*) calloc(b,sizeof(int));

	for( i=0; i<p; i++ )
	{
		printf("enter process %d size\n",i);
		scanf("%d",&ps[i]);
		bno[i] = -1;
	}
	for( i=0; i<b; i++ )
	{
		printf("enter block %d size\n",i);
		scanf("%d",&bs[i]);
		s[i] = i;
	}
	for( i=0; i<p; i++ )
	{	m=10000;
		for( j=0; j<b; j++ )
		{

			if( bs[j] > ps[i] )
			{
				if( bs[j] < m )
				{
					k = j;
					m= bs[j];
				}
			}

		}
				if( m!= 10000){
						bs[k] -= ps[i];
						bno[i] = s[k];}


	}
	printf("process no\tprocess size\tblock no\n");
	for(i=0; i<p; i++)
	{

		printf("%d\t%d\t%d\n",i,ps[i],bno[i]);


	}
	free(bs);
	free(ps);
	return 0;

}
