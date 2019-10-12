int calways(int d[],int numD,int value,int output[][11])
{
  if(numD==0)
  {
    return 0;
  }
  if(value==0)
  {
    return 1;
  }
  if(value<0)
  {
    return 0;
  }
  if(output[value][numD]>-1)
  {
    return output[value][numD];
  }
  int first = calways(d,numD,value-d[0],output);
  int second = calways(d+1,numD-1,value,output);
  output[value][numD]=first+second;
  return output[value][numD];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
  int output[value+1][11];
  for(int i=0;i<=value;i++)
  {
    for(int j=0;j<=10;j++)
    {
      output[i][j]=-1;
    }
  }
  int count = calways(denominations,numDenominations,value,output);
  return count;
}

