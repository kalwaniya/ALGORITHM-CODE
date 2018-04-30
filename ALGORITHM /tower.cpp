#include<iostream>
using namespace std;
 int count=0;
void tower(int n,char a,char b,char c)
{

 if(n==1)
 {cout<<"move disc 1"<<" "<<a<<"->"<<c<<endl;
 count++;}
 else
 	{
 	tower(n-1,a,c,b);
 	
 	cout<<"move disc"<<" "<<n<<" "<<a<<"->"<<c<<endl;
 	count++;
	tower(n-1,b,a,c);
	}

}	
int main()
{
 
 int n;
 cout<<"Enter no.of disc"<<endl;
 cin >> n;
 tower(n,'A','B','C');
 cout<<count<<endl;	
 return 0;
 }
 
