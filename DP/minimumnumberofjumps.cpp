#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int arr1[n];
	    arr1[0]=0;
	    for(int i=1;i<n;i++)
	    {
	        arr1[i]=9999;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(int i=1;i<n;i++)
	    {
	        int j=0;
	        while(j<i)
	        {
	            if(i<=j+arr[j])
	            {
	                arr1[i]=min(arr1[j]+1,arr1[i]);
	            }
	            j++;
	        }
	    }
	    if(arr1[n-1]==9999)
	    {
	        cout<<"-1"<<endl;
	    }
	    else
	    {
	        cout<<arr1[n-1]<<endl;
	    }
	}
	return 0;
}
