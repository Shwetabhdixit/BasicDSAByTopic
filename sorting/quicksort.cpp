#include<iostream>
using namespace std;

int Partition(int* arr,int start ,int end)
{
	int pivot = arr[end];
	int pIndex = start;
	for(int i=start;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex],arr[end]);
	return pIndex;
}

void quicksort(int *arr,int start, int end)
{
	if(start<end)
	{
		int pindex = Partition(arr,start,end);
		quicksort(arr,start,pindex-1);
		quicksort(arr,pindex+1,end)	;
	}
	return;
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
}
