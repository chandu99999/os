#include<stdio.h>
#include<conio.h>
#include <limits.h>
int main()
{
float avgTAT,avgWT;
int n,a=0,b=0,e=0,counter=-1;
int time,ATmin,BTmin,point=0,totTAT=0,totWT=0,x=0;
int pno[30],AT[30],BT[30],BT1[30],TAT[30],WT[30];
printf("ENTER TOTAL NO. OF PROCESSES: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("ENTER arrival and burst time\n");
 scanf("%d",&a);
 scanf("%d",&b);
 	
 if(a!=0)
 {	counter++;
	pno[counter]=e;
    AT[counter]=a;
	BT[counter]=b;
	e++;
 }
 else
 {e++;}		
}
//printf("counter %d",counter);
printf("\npno.\tarrivaltime\tbursttime\n");
for(int i=0;i<=counter;i++)
{printf("%d\t%d\t\t%d\n",pno[i],AT[i],BT[i]);}	
ATmin=BTmin=INT_MAX;
for(int i=0;i<=counter;i++)
{
 if(AT[i]<ATmin)
 {ATmin=AT[i];}
}
time=ATmin;
for(int i = 0; i <=counter; i++)
{BT1[i] = BT[i];}
	
for(int i=0;i<=counter;i++)
 {	BTmin=INT_MAX;
	for(int j=0;j<=counter;j++)
	{
		if(BT1[j]<BTmin && AT[j]<=time && BT1[j]!=0)
			{
				BTmin=BT1[j];
				point=j;
				x=1;
			}
	}
		if(x==1)
		{
			time=time+BT1[point];
			TAT[point]=time-AT[point];
			WT[point]=TAT[point]-BT1[point];
			BT1[point]=0;
		}
	time=time+2;
	x=0;
 }
	printf("\npno.\tarrivaltime\tbursttime\tturnaround time\t\twaiting time\n");
	for(int i=0;i<=counter;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\n",pno[i],AT[i],BT[i],TAT[i],WT[i]);
		totTAT=totTAT+TAT[i];
		totWT=totWT+WT[i];
	}			
	avgTAT=totTAT/(counter+1);
	avgWT=totWT/(counter+1);
	printf ("Total turnaround time=%d\n", totTAT);
	printf ("Total Waiting time=%d\n", totWT);
	printf("average turnaround time = %f\n",avgTAT);
	printf("average waiting time = %f\n",avgWT);	
	printf("\ntotal time taken = %d\n",time-2);
}
