#include <iostream>

using namespace std;

#include<string>

int main() 
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        int len = s.length();
        int mat[len][len];
        for(int i=0;i<len;i++)
        {
            mat[i][i]=1;
        }
        for(int l=2;l<=len;l++)
        {
            for(int i=0;i<len-l+1;i++)
            {
                int j=i+l-1;
                if(s[i]==s[j] && l==2)
                {
                    mat[i][j]=2;
                }
                else if(s[i]==s[j])
                {
                    mat[i][j]=max(mat[i+1][j-1]+2,mat[i+1][j-1]);
                }
                else
                {
                    mat[i][j]=max(mat[i][j-1],mat[i+1][j]);
                }
            }
        }
        cout<<mat[0][len-1]<<endl;
        
    }
	return 0;
}
