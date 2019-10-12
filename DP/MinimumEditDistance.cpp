#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        string p;
        cin>>s;
        cin>>p;
        int n = s.length()+1;
        int m=p.length()+1;
        int a[m+1][n+1];
        for(int j=0;j<n+1;j++)
        {
            a[0][j]=j;
        }
        for(int i=1;i<m+1;i++)
        {
            a[i][0]=i;
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[j-1]==p[i-1])
                {
                    a[i][j]=a[i-1][j-1];
                }
                else
                {
                    a[i][j]=min(min(a[i-1][j-1],a[i-1][j]),a[i][j-1])+1;
                }
            }
        }
        cout<<a[m][n]<<endl;
    }
    return 0;
}

