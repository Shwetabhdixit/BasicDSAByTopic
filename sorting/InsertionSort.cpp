#include<iostream>
#include<vector>

using namespace std;

vector<int> InsertionSort(vector<int> arr ,int n)
{
	for(int i=1;i<n;i++)
	{
		int value = arr[i];
		int hole=i;
		while(hole>0 && arr[hole-1]>value)
		{
			arr[hole]=arr[hole-1];
			hole=hole-1;
		}
		arr[hole]=value;
	}
	return arr;
}

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	arr = InsertionSort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
