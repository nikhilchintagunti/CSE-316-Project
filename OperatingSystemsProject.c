#include<stdio.h>
int main()
{
	int total_time=0,count=0,a,b,c=-1,i,j,k,l=0,m=0,high_priority=-1,n;
	printf("enter no of processes");
	scanf("%d",&n);
	int pro[n],pri[n],arrival[n],burst_time[n],arr[n],e[n],f[n];
	for(i=0;i<n;i++)
	{
		pro[i]=i;
		pri[i]=-1;
		printf("enter arrival time of %d  process",i+1);
		scanf("%d",&arrival[i]);
		printf("enter burst time of %d th process",i+1);
		scanf("%d",&burst_time[i]);
		total_time+=burst_time[i];
		printf("\n%d",total_time);
	}
	int gantt_chat[total_time],readyqueue[2*total_time];
	for(i=0;i<2*total_time;i++)
	{
		readyqueue[i]=-1;
	}
	for(i=0;i<total_time;i++)
	{
		gantt_chat[i]=-1;
	}
	
	readyqueue[0]=0;
	++m;
	gantt_chat[0]=0;
	pri[0]=0;
	--burst_time[0];
	arr[0]=0;
	count=count+1;
	for(i=1;i<total_time;i++)
	{
		for(j=0;j<n;j++)
		{
			if(pri[j]>=0)
			{
				for(k=0;k<total_time;k++)
				{
					if(gantt_chat[k]!=j)
					l=l+1;
				}
				if(l==total_time)
				pri[j]=pri[j]+2;
				else
				{
					pri[j]=pri[j]+1;
				}
			}
		}
		for(a=1;a<n;a++)
		{
			if(i==arrival[a])
			{
				readyqueue[m]==a;
				++m;
				pri[a]=0;
			}
		}
		for(a=0;a<n;a++)
		{
			printf("priority of pro %d is %d \n",a+1,pri[a]);
		}
		high_priority=0;
		for(a=0;a<n;a++)
		{
			if(pri[a]>high_priority)
			{
			high_priority=pri[a];
			c=a;	
			}
		}
		gantt_chat[i]=c;
		--burst_time[c];
		if(burst_time[c]==0)
		{
			pri[c]=-1;
			for(b=0;b<2*total_time;b++)
			{
				if (readyqueue[b]==c)
				readyqueue[b]=-1;	
			}	
			
		}
			
	}
	
	for(i=0;i<total_time;i++)
	printf("%d th execution is %d\n",i+1,gantt_chat[i]+1);
}
