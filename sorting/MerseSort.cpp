#include<iostream>
using namespace std;

void mergeSort(int input[], int size)
{
  if(size==0 ||size==1)
  {
    return;
  }
  
  int mid = size/2;
  int b[mid];
  int c[size-mid];
  for(int i=0;i<mid;i++)
  {
    b[i]=input[i];
  }
  for(int i=mid;i<size;i++)
  {
    c[i-mid]=input[i];
    //cout<<input[i]<<" ";
  }
  //cout<<endl;
  mergeSort(b,mid);
  mergeSort(c,size-mid);
  int i=0;
  int j=0;
  int k=0;
  //cout<<mid<<size-mid<<size<<endl;
  while(i<mid && j<size-mid && k<size)
  {
    if(b[i]>c[j])
    {
      input[k]=c[j];
      //cout<<input[k]<<endl;
      j++;
      k++;
    }
    else
    {
      input[k]=b[i];
      i++;
      k++;
    }
  }
  while(i<mid && k<size)
  {
    input[k]=b[i];
    i++;
    k++;
  }
  while(j<size-mid && k<size)
  {
    input[k]=c[j];
    j++;
    k++;
  }
}
int main()
{
	int arr[5]={3,2,0,1,5};
	mergeSort(arr,5);
	cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<endl;
}

