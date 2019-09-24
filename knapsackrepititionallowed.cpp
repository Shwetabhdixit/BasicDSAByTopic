#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        int weights[n];
        int values[n];
        for(int i=0;i<n;i++)
        {
            cin>>values[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>weights[i];
        }
        int dp[n][w+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=1;i<w+1;i++)
        {
            if(i%weights[0]==0)
            {
                dp[0][i] = (i/weights[0])*values[0];
            }
            else
            {
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<w+1;j++)
            {
                if(j>=weights[i])
                {
                    dp[i][j] = max(dp[i][j-weights[i]]+values[i],dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        cout<<dp[n-1][w]<<endl;
    }
    return 0;
}
