#include<stdio.h>
main()
{
	int n,i;
	float avgwt =0.0, avgta=0.0;
	printf("enter the number of processes:");
	scanf("%d",&n);
	int p[n],bt[n],wt[n],ta[n];
	for(i=0;i<n;i++)
	{
		printf("enter process number:");
		scanf("%d",&p[i]);
		printf("Enter CPU time for each process:");
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	ta[0]=bt[0];
	avgta=ta[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		avgwt=avgwt+wt[i];
		ta[i]=wt[i]+bt[i];
		avgta=avgta+ta[i];
	}
	avgwt=avgwt/n;
	avgta=avgta/n;
	printf("pno \t cpu time \t wt \t ta \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\t%d\t",p[i],bt[i],wt[i],ta[i]);
		printf("\n");
	}
	printf("Average waiting time is%f\n",avgwt);
	printf("Average turn around time is %f\n",avgta);
}

	
	




