#include<stdio.h>
double v[10],w[10],r[10];

void knapsack(int n,int u)
{
int i=0;
double x[10]={0.0},tp;
for(i=0;i<n;i++)
{
if(w[i]>u)
break;
else
{
x[i]=1.0;
u=u-w[i];
tp=tp+v[i];

}
}


if(i<=n)
{
x[i]=u/w[i];
tp=tp+x[i]*v[i];

}


printf("the fractional items are:\n");
for(i=0;i<n;i++)
printf("\nx[%d]=%lf\n",i,x[i]);

printf("the total profit=%lf",tp);



}









int main()
{
int n,i=0,j=0,t,cap;

printf("enter n");
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%lf%lf",&w[i],&v[i]);

printf("enter max capacity");
scanf("%d",&cap);

for(i=0;i<n;i++)
r[i]=(v[i]/w[i]);

for(i=0;i<=n-1;i++)
{
	for(j=i;j<=n-1;j++)
	{
	if(r[i]<r[j])
{

t=r[j];
r[j]=r[i];
r[i]=t;

t=w[j];
w[j]=w[i];
w[i]=t;


t=v[j];
v[j]=v[i];
v[i]=t;


}
	}


}


knapsack(n,cap);

}
