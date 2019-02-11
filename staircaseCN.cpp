long stairs(long n,long *arr)
{
  if(n<1)
  {
    return 0;
  }
  if(n==3)
  {
    return arr[3];
  }
  if(n==2)
  {
    return arr[2];
  }
  if(n==1)
  {
    return arr[1];
  }
  if(arr[n]>0)
  {
    return arr[n];
  }
  long ans1 = stairs(n-3,arr);
  long ans2 = stairs(n-2,arr);
  long ans3 = stairs(n-1,arr);
  long ans =ans1+ans2+ans3;
  arr[n]=ans;
}


long staircase(int n)
{
  if(n==3)
  {
    return 3;
  }
  if(n==2)
  {
    return 2;
  }
  if(n==1)
  {
    return 1;
  }
  long *arr= new long[n+1];
  for(int i=0;i<=n;i++)
  {
    arr[i]=0;
  }
  arr[1]=1;
  arr[2]=2;
  arr[3]=4;
  long final_ans = stairs(n,arr);
  return final_ans;
}

