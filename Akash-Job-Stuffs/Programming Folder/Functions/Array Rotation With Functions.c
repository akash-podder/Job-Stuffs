#include<stdio.h>

void leftRotatebyOne(long long int arr[],long long int n);

void leftRotate(long long int arr[],long long int d,long long int n)
{
  long long int i;
  for (i = 0; i < d; i++)
    {
    leftRotatebyOne(arr,n);
    }

      for(i = 0; i < n; i++)
  {
      printf("%lld ", arr[i]);
  }
}

void leftRotatebyOne(long long int arr[],long long int n)
{
  long long int i, temp;
  temp = arr[0];
  for (i = 0; i < n-1; i++)
  {
     arr[i] = arr[i+1];
  }
    arr[i] = temp;

}

/*
void printArray(long long int arr[], long long int size)
{
  long long int i;
  for(i = 0; i < size; i++)
  {
      printf("%lld ", arr[i]);
  }
}
*/
int main()
{
    long long int n,i,d;
    scanf("%lld %lld",&n,&d);
    long long int ara[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&ara[i]);
    }
    leftRotate(ara,d,n);
    /*printArray(ara,n);*/
    return 0;
}
