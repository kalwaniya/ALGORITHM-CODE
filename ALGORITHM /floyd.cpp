
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void printallpair(int pi[][5],int i,int j)
{
	if(i==j)
		cout<<i;
	else if(pi[i-1][j-1]==INT_MAX)
		cout<<"no path";
	else
	{
		printallpair(pi,i,pi[i-1][j-1]);
		cout<<"->"<<j;
	}

}
void allpair(int g[][5],int n)
{
	int d[5][5],pi[5][5];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			d[i][j]=g[i][j];
			if (g[i][j]==0||g[i][j]==INT_MAX)
			{
				pi[i][j]=INT_MAX;
			}
			else
				pi[i][j]=i+1;
		} 3
	}	
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if((d[i][k]!=INT_MAX)&&(d[k][j]!=INT_MAX)&&(d[i][j]>d[i][k]+d[k][j]))
				{
					d[i][j]=d[i][k]+d[k][j];
					pi[i][j]=pi[k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<pi[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Enter i and j to print shortest path from i to j"<<endl;
	int x,y;
	cin>>x>>y;
	if(x==y)
		cout<<"same node"<<endl;
	else
		printallpair(pi,x,y);
}

int main()
{
	int n,m,a,b,c;
	cout<<"enter no. of nodes\t";
	 cin>>n;
	int g[5][5];
	// cout<<"Enter the no. of edges";
	// cin>>m; 
	  for(int i=0;i<n;i++)
	  {
	 	for (int j=0;j<n;j++)
	 	{ 
                        cin>>g[i][j];
              		if(g[i][j]==999)
                         {
                             g[i][j]=INT_MAX;                         
                          }
		}
	 }
	 	//g[i][i]=0;
	// // 
	// // for(int i=0;i<m;i++)
	// // {
	// // 	cin>>a>>b>>c;
	// // 	g[a][b]=c;
	// // }
	/*int g[5][5] = { 	{0,   3,  8, INT_MAX,-4},
                        {INT_MAX, 0,   INT_MAX, 1,7},
                        {INT_MAX, 4, 0,   INT_MAX,INT_MAX},
                        {2, INT_MAX, -5, 0,INT_MAX},
                        {INT_MAX, INT_MAX,INT_MAX,6,0}
                      };*/
	allpair(g,n);
}

