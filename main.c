#include<stdio.h>
int main()
{
/////fcfs/////
int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
int n,sum=0;
float totalTAT=0,totalWT=0;
int star[10],finish[10];
int totwt=0,tottat=0;
/////////sjf/////
int temp,tt=0,min,d,i,j;
float atat=0, sjf=0,stat=0,swt=0;
int e[10];
char pn[10][10],t[10];
/////////priority/////////
int p[10],st[10],ft[10];
float priority=0;
//////input section/////
freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=0;i<n;i++)
{

scanf("%d",&at[i]);
}

for(int i=0;i<n;i++)
{


scanf("%d",&bt[i]);
}

for(i=0; i<n; i++)
{

scanf("%d",&p[i]);
}
//starting of fcfs scheduling//
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(at[i]<at[j])
{
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
strcpy(t,pn[i]);
strcpy(pn[i],pn[j]);
strcpy(pn[j],t);
}
}
}
for(i=0; i<n; i++)
{
if(i==0)
star[i]=at[i];
else
star[i]=finish[i-1];
wt[i]=star[i]-at[i];
finish[i]=star[i]+bt[i];
tat[i]=finish[i]-at[i];
}
for(i=0; i<n; i++)

{
totwt+=wt[i];
}
float fcfs=totwt/n;
printf("\n\nAverage waiting time of FCFS is: %.2f\n",fcfs);
//starting of sjf np scheduling//
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
}
}
min=at[0];
for(i=0;i<n;i++)
{
if(min>at[i])
{
min=at[i];
d=i;
}
}
tt=min;
e[d]=tt+bt[d];
tt=e[d];
for(i=0;i<n;i++)
{
if(at[i]!=min)
{
e[i]=bt[i]+tt;
tt=e[i];
}
}

for(i=0;i<n;i++)
{
tat[i]=e[i]-at[i];
stat=stat+tat[i];
wt[i]=tat[i]-bt[i];
swt=swt+wt[i];
}
atat=stat/n;
sjf=swt/n;
printf("\nAverage waiting time of SFJ Non Preemptive is: %.2f\n",sjf);
//starting of priority scheduling//
for(i=0; i<n; i++)
for(j=0; j<n; j++)
{
if(p[i]<p[j])
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
strcpy(t,pn[i]);
strcpy(pn[i],pn[j]);
strcpy(pn[j],t);
}
}
for(i=0; i<n; i++)
{
if(i==0)
{
st[i]=at[i];
wt[i]=st[i]-at[i];
ft[i]=st[i]+bt[i];
tat[i]=ft[i]-at[i];

}
else
{
st[i]=ft[i-1];
wt[i]=st[i]-at[i];
ft[i]=st[i]+bt[i];
tat[i]=ft[i]-at[i];
}
totwt+=wt[i];
tottat+=tat[i];
}
priority= totwt/n;
atat=tottat/n;
printf("\nAverage waiting time of Priority scheduling is: %.2f\n\n",priority);
//the best scheduling//
printf("\nThe best scheduling is given below:\n");
if ( fcfs< sjf && fcfs < priority)
{
printf("\n FCFS is the best scheduling.\n\n");
}
else if(sjf < priority)
{
printf("\n SJF Non-Preemptive is the best scheduling.\n\n");
}
else
{
printf("\n Priority is the best scheduling.\n\n");
}
return 0;
}