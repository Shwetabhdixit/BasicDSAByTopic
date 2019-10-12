#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
#define m 1000000007

ull calstrings(string str,ull size)
{
  ull *arr = new ull[size+1];
  arr[0]=1;
  arr[1]=1;
  for(ull i=2;i<=size;i++)
  {
    if((int)str[i-1]-48 ==0 && (((int)str[i-2]-48)==2 || ((int)str[i-2]-48)==1))
    {
      arr[i]=arr[i-2];
      arr[i-1]=arr[i-2];
      continue;
    }
    if((int)str[i-1]-48 ==0 && ((str[i-2]-48)*10+(str[i-1]-48))>26)
    {
      return 0;
    }
    arr[i]=arr[i-1]%m;
    int num = ((str[i-2]-48)*10+(str[i-1]-48));
    if(num<=26 && (int)str[i-2]-48!=0) 
    {
      arr[i]= (arr[i]%m+arr[i-2]%m)%m;
    }
  }
 /* for(int i=0;i<=size;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;*/
  return (arr[size]+m)%m;
}
int main()
{
  string n;
  while(true)
  {
    cin>>n;
    if(n[0]=='0')
    {
      break;
    }
    ull size = n.length();
    bool flag=true;
    for(int i=0;i<size-1;i++)
    {
      if(n[i]=='0' && n[i+1]=='0')
      {
        cout<<0<<endl;
        flag=false;
      }
    }
    ull count=calstrings(n,size);
    if(flag==true)
    {
    cout<<count%m<<endl;}
  }
  return 0;
}

