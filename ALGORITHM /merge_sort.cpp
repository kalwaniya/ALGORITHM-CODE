
#include<iostream>
using namespace std;
void merge_sort(int A[],int p,int r);
void merge(int A[],int p,int q,int r);

int main()
{
    int N,p,r,i;
    cout<<"size of array\n";
    cin>>N;
    int A[N];
    cout<<"enter element in arry\n";
    for(i=0;i<N;i++)
    cin>>A[i];
    p=0;
    r=N-1;
    merge_sort(A,p,r);
    cout<<"sorted array is\n";
    for(i=0;i<N;i++)
        cout<<A[i];
    return 0;
}
void merge_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
void merge(int A[],int p,int q,int r)
{

    	int i=p,j=q+1,arr[r-p+1],k=0;
    	while(i<=q&&j<=r)
    	{
        	if(A[i]<=A[j])
		arr[k++]=A[i++];
		else
		arr[k++]=A[j++];
    	}
	if(i<=q)
	{
		while(i<=q)
		arr[k++]=A[i++];
	}
	else
	{
		while(j<=r)
		arr[k++]=A[j++];
	}
	k=0;
	for(i=p;i<=r;i++)
	A[i]=arr[k++];	
  
}
