#include<iostream>
using namespace std;
void print(int*arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int* bubblesort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0; // optimazation 1
		for(int j=0;j<n-1-i;j++) // optimazation 2
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j+1],arr[j]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
		print(arr,n);
	}
	return arr;
	
}
int main()
{
	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	arr = bubblesort(arr,n);
	for(int i=0;i<n;i++)
	{
		//cout<<arr[i]<<" ";
	}
	return 0;
}
