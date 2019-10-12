#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector<long> c)
{
    long m=c.size();
    long T[m][n+1];
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
    for(long i=0;i<m;i++)
    {
        T[i][0]=1;
    }
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

