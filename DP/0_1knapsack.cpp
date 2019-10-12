#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        int w;
        cin>>n;
        cin>>w;
        int val[n];
        int weight[n];
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>weight[i];
        }
        
        int T[n][w+1];
        for(int i=0;i<n;i++)
        {
            T[i][0]=0;
        }
        for(int i=1;i<w+1;i++)
        {
            if(i>=weight[0])
            {
                T[0][i]=val[0];
            }
            else
            {
                T[0][i]=0;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<w+1;j++)
            {
                if(j>=weight[i])
                {
                    T[i][j]=max(T[i-1][j],val[i]+T[i-1][j-weight[i]]);
                }
                else
                {
                    T[i][j]=T[i-1][j];
                }
            }
        }
        cout<<T[n-1][w]<<endl;
        
    }
	return 0;
}
