#include <stdio.h>
int partition (int a[],int p,int r);
int quicksort (int a[],int p,int r);
int swap (int *i,int *j);
int main()
{
    int x,y,z;
    printf("Enter number of elements:");
    scanf("%d",&x);
    int a[x];
    printf("Enter elements:");
    for(y=0;y<=x-1;y++)
    {
        scanf("%d",&a[y]);
    }
    int p= 0;
    int r= x-1;
    quicksort(a,p,r);
    printf("Sorted array: \n");
    for (y=0;y<=x-1;y++)
    {
       printf("%d ", a[y]);
    }
    return 0;
}
int quicksort (int a[],int p, int r)
{ 
  if (p<r)
  {
      int q= partition(a,p,r);
      quicksort(a,p,q-1);
      quicksort(a,q+1,r);
  }
}
int partition(int a[],int p, int r)
{
    int t=a[r];
    int i=p-1;
    for (int j=p;j<=r-1;j++)
    {
        if(a[j]<=t)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
      swap(&a[i+1],&a[r]);
      return i+1;
}
int swap(int *i, int *j)
{
    int temp=  *i;
     *i= *j;
     *j= temp;
}