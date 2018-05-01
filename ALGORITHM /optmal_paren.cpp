#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;

int s[20][20];
int m[20][20];

void print_optimal(int s[20][20],int i,int j)
{
if(i==j)
cout<< "A" << i;
else
{
 cout<<"(";
 print_optimal(s,i,s[i][j]);
 print_optimal(s,s[i][j]+1,j);
 cout<<")";
}
} 

void matrix_chain(int p[],int n)
{
 int i,j,k,q,l;
 
 for(i=1;i<=n;i++)
 m[i][i]=0;
 for(l=2;l<=n;l++)
 	{
 	 for(i=1;i<=n-l+1;i++)
 	 	{
 	 		j=i+l-1;
 	 		m[i][j]=INT_MAX;
 	 		for(k=i;k<=j-1;k++)
 	 			{
 	 			 q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
 	 			 if(q<m[i][j])
 	 			 	{
 	 			 	 m[i][j]=q;
 	 			 	 s[i][j]=k;
 	 			 	 }
 	 			}
 	 	}
 	} 
 	for(i=1;i<=n;i++)
 	{
 	 for(j=1;j<=n;j++)
 	  {
 	 cout<<m[i][j]<<"\t";
 	  }
 	  cout << "\n";
 	 }			 	 
}	



int main()
{
int n,i;
cout<<"enter total no";
cin>>n;
int p[n];
cout<<"enter the dimensions of matrix"<<endl;
for(i=0;i<n;i++)
cin>>p[i];
matrix_chain(p,n-1);
print_optimal(s,1,n-1);

}


