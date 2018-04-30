# include<iostream>
using namespace std;
int max(int arr[],int n)
  {
   int m=arr[0];
   for(int i=0;i<n;i++)

      if(arr[i]>m)   
             m=arr[i];
	    return m;
	  }
void countsort(int arr[],int n,int exp)
{
 int out[n],count[10]={0},i;

  for(i=0;i<n;i++)
  {
          count[(arr[i]/exp)%10]++;
  } 
  for(i=1;i<10;i++)
  {
          count[i]+=count[i-1];
  }
  for(i=n-1;i>=0;i--)
  {
          out[count[(arr[i]/exp)%10]-1]=arr[i];
          count[(arr[i]/exp)%10]--;
  }
  for(i=0;i<n;i++)
  {
    arr[i]=out[i];
  }
}
void radixsort(int arr[],int n)
 {
 
   int m=max(arr,n);
   for(int exp=1;m/exp>0;exp=exp*10)
	countsort(arr,n,exp);

 }
int main()
 {
   int arr[10],n,i;
   cout<<"no.of element";
   cin>>n;
   cout<<"enter the element\n";
   for(i=0;i<n;i++)
      {
      cin>>arr[i];
      }
    radixsort(arr,n);
    for(i=0;i<n;i++)
      {
      cout<<arr[i]<<"\t";
      }
    return 0;
  }

           
 


