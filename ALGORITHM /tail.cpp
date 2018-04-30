#include<iostream>
using namespace std;

int fact(int n,int a)
{
int r;
if(n==1)
return a;
else
 r=fact(n-1,n*a);
return r;
}
int main()
{
int n,f;
cout<<"enter no.:"<<endl;
cin >>n;
f=fact(n,1);
cout <<"factorial is:"<<f<<endl;
return 0;
}
