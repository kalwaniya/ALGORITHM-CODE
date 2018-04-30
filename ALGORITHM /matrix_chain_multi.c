#include<stdio.h>
#include<string.h>
#define max 10
int m[10][10],p[10],s[10][10];



void printopt(int s[10][10],int i,int j)
{

if(i==j)
{
printf("A%d",i);
return;
}

else
{
printf("(");
//printf("dhjdehcd");
printopt(s,i,s[i][j]);
printopt(s,s[i][j]+1,j);
printf(")");

}

}




void matmul(int p[],int n)
{
int i,j,k,l,q;
for(i=1;i<=n;i++)
m[i][i]=0;


for(l=2;l<=n;l++)
{

	for(i=1;i<=(n-l+1);i++)
	{
	j=i+l-1;
	m[i][j]=100000;
		for(k=1;k<j;k++)
		{

		q=m[i][k]+m[k+1][j]+(p[i-1]*p[j]*p[k]);
		if(q<m[i][j])
		{
		m[i][j]=q;
		s[i][j]=k;
		}

		}


	}

}


}





int main()
{
int n,i=0;
printf("enter no. of matrices");
scanf("%d",&n);

printf("enter p ");
for(i=0;i<=n;i++)
scanf("%d",&p[i]);

matmul(p,n);

printopt(s,1,n);

}
