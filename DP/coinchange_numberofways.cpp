#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector<long> c)
{
    long m=c.size(); // no. of coins
    long T[m][n+1]; //n is the amount
    //checking if the first coin is a factor of any of the numbers leading up to the amount
    for(long i=1;i<n+1;i++)
    {
        if(i%c[0]==0)
        {
            T[0][i]=1;
        }
        else
        {
            T[0][i]=0;
        }
    }
    //there is 1 way of getting 0 sum, dont choose any coin
    for(long i=0;i<m;i++)
    {
        T[i][0]=1;
    }
    //for each cell , if the amount is greater than the coin, then the no. of ways is
    //1 + 2 
    //1. No. of ways of getting the amount without considering the current coin ( arr[i-1][j])
    //2. No. of ways of getting the amount - taking current coin once ( arr[i][j-coins[i]])
    //if the amount is lesser than the current coin value, we can only have the no. of ways without considering current coin (arr[i-1][j])
    for(long i=1;i<m;i++)
    {
        for(long j=1;j<n+1;j++)
        {
            if(j>=c[i])
            {
                T[i][j]=T[i-1][j]+T[i][j-c[i]];
            }
            else
            {
                T[i][j]=T[i-1][j];
            }
        }
    }
    long ans=T[m-1][n];
    return ans;
}

int main()
{
    long n,m;
    cin>>n>>m;
    vector<long> c(m);
    for(long i=0;i<m;i++)
    {
        cin>>c[i];
    }
    long res=getWays(n,c);
    cout<<res;
}

