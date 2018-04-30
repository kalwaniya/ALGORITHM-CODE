
#include <iostream>
using namespace std;
void q_sort(int A[],int p,int r);
int part(int A[],int p,int r);

int main()
{
    int N,p,r,i;
    cout<<"size of array\n";
    cin>>N;
    int A[N];
    cout<<"enter element in array\n";
    for(i=0;i<N;i++)
    cin>>A[i];
    p=0;
    r=N-1;
    cout<<"sorted array is :"<<endl;
    q_sort(A,p,r);
    for(i=0;i<N;i++)

    cout<<A[i];
    return 0;
}
void q_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
    q=part(A,p,r);
    q_sort(A,p,q);
    q_sort(A,q+1,r);
    }
}
int part(int A[],int p,int r)
{

    int pivot=A[r],i=p-1,j,temp;
    for(j=p;j<r;j++)
    {
        if(A[j]<=pivot)
        {
            i=i+1;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
        temp=A[r];
        A[r]=A[i+1];
        A[i+1]=temp;
        return i;
}

