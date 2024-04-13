#include <stdio.h>
int insertionsort(int a[],int i, int j,int x);
int main()
{
    int x,y,z;
    printf("Enter number of elements:");
    scanf("%d",&x);
    int a[x];
    printf("Enter elements:");
    for(y=1;y<=x;y++)
    {
        scanf("%d",&a[y]);
    }
    int i= 1;
    int j= 2;
    insertionsort(a,i,j,x);
    
    return 0;
}
int insertionsort(int a[], int i, int j, int x)
{
    int key,y;
    for (j=2;j<x;j++)
    {
        key = a[j];
        i=j-1;
        while(i>0 && a[i]>key)
        {
            a[i+1]= a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    
    printf("Sorted array: \n");
    for (y=1;y<=x;y++)
    {
       printf("%d ", a[y]);
    }
}
