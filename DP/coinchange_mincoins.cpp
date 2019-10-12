#include <iostream>
using namespace std;
#define INT_MAX 90000
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int arr[n+1];
	    int arr2[n+1];
	    arr[0]=0;
	    for(int i=0;i<n+1;i++)
	    {
	        arr2[i]=-1;
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        arr[i]=INT_MAX;
	    }
	    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	    int m = sizeof(coins)/sizeof(coins[0]);
	    
	    for(int j=0;j<m;j++)
	    {
	        for(int i=1;i<n+1;i++)
	        {
	            if(coins[j]<=i)
	            {
	                arr[i]=min(arr[i],arr[i-coins[j]]+1);
	                arr2[i]=j;
	            }
	        }
	    }
	    int q=n;
	    while(arr2[q]>=0)
	    {
	        cout<<coins[arr2[q]]<<" ";
	        q-=coins[arr2[q]];
	    }
	    cout<<endl;
	}
	return 0;
}
