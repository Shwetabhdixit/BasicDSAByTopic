#include <iostream>
using namespace std;
#include<string>
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,m;
	    string s_n,s_m;
	    cin>>n>>m;
	    cin>>s_n;
	    cin>>s_m;
	    
	    int arr[n+1][m+1];
	    
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<m+1;j++)
	        {
	            arr[i][j]=0;
	        }
	    }
	    int maxx=0;
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<m+1;j++)
	        {
	            if(s_n[i-1]==s_m[j-1])
	            {
	                arr[i][j]=arr[i-1][j-1]+1;
	                if(arr[i][j]>maxx)
	                {
	                    maxx=arr[i][j];
	                }
	            }
	            else
	            {
	                arr[i][j]=0;
	            }
	        }
	    }
	    cout<<maxx<<endl;
	  
	}
	return 0;
}
