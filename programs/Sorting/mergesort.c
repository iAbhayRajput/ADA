#include <stdio.h>

int merge(int array[],int start, int mid,int last)
{
        int n1= mid - start + 1;
        int n2= last - mid;
        
        int L[n1],R[n2];
        
        for(int i=0;i<n1;i++)
        {
            L[i]=array[start+i];   //creating Left subarrays 
        }
        for(int j=0; j<n2;j++)
        {
            R[j]=array[mid+1+j];   //creating right subarray 
        }
        
       int  i=0;// intitial element of left subarray
       int  j=0;// intitial element of right subarray
      int  k=start;// intitial element of main array 
      
      while (i<n1 && j<n2)
      {
          if ( L[i]<=R[j])
          {
              array[k]=L[i];
              i++;
          }
          else 
          {
              array[k]=R[j];
              j++;
          }
          k++;
      }
      
      while(i<n1)
      {
          array[k]=L[i];
          i++;
          k++;
      }
      
      while (j<n2)
      {
          array[k]=R[j];
          j++;
          k++;
      }
}

int mergesort(int array[],int start, int last)
{
    if (start < last)
    {
     
    
    int mid = (start+last)/2;
    
    mergesort(array,start,mid);
    mergesort(array,mid+1,last);
    
    merge(array,start,mid,last);
    
    }
}
int main()
{
    int x,y,z;
    printf("Enter number of elements:");
    scanf("%d",&x);
    int array[x];
    printf("Enter elements:");
    for(y=0;y<x;y++)
    {
        scanf("%d",&array[y]);
    }
    
    mergesort(array,0,x-1);
    
    printf("Sorted array: \n");
    for (int k=0;k<=x-1;k++)
    {
       printf("%d ", array[k]);
    }

    return 0;
}