#include<iostream>
using namespace std;

int G[10][10],x[11]={-1};

bool safe(int v,int n,int k)
{
    int i;
if(G[x[k-1]][v]==0)
return false;

for(i=0;i<k;i++)
if(x[i]==v)
return false;

return true;


}



void write(int n)
{
int i;
cout<<"the hamiltonion cycle is:"<<endl;
for(i=0;i<n;i++)
cout<<"  "<<x[i]<<" ";
cout<<x[0];

}



bool hamiltonionutil(int n,int k)
{
    if(k==(n))
    {
        if(G[x[k-1]][x[0]]==1)
        return true;
        else
        return false;

    }
int v;
for(v=1;v<n;v++)
if(safe(v,n,k))
{
    x[k]=v;
    if(hamiltonionutil(n,k+1)==true)
    return true;
    x[k]=-1;


}

return false;

}


bool hamiltonion(int n)
{
    x[0]=0;
if(hamiltonionutil(n,1)==false)
{
cout<<"solution doesnt exits\n";
return false;
}

write(n);
return true;

}








int main()
{
    int n,i=1,j=1;
   cout<<"enter n"<<endl;
   cin>>n; 
cout<<"enter the adj matrix:"<<endl;

for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>G[i][j];

hamiltonion(n);

//write(int n);

return 0;
}



