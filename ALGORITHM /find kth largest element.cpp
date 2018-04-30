#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void reverse(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
}     

int main()
{
    int n,i,k;
    cout<<"enter size of array"<<"\n";
    cin>>n;
    int arr[n];
     cout<<"enter elements of array"<<"\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	heapSort(arr, n);
	
	for(i=0;i<n;i++)
	{
	cout<<arr[i]<<" ";
	}
	cout<<"enter the kth largest element"<<"\n";
	cin>>k;
	
	if(k<=n)
	cout<<arr[n-1-(k-1)]<<endl;
	else
	cout<<"element not exist";
	return 0;
}
