/******************************************************************************
Gordon Stangler
TimSort in C. Time Complexity O(n), Space Complexity O(n)
*******************************************************************************/

#include <stdio.h>
const int RUN = 32;  //used for insertion sort, which works best with 2**n

//sorts array from left for RUN characters
void insertionSort(int arr[], int left, int right)
{
    int i;
    for(i = left+1;i<right;i++)
    {
        int temp = arr[i];
        int j = i-1;
        
        while((arr[j] > temp) && (j >= left))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

//merges sorted arrays
void merge(int arr[], int l, int m, int r)
{
    int len1 = m-l+1;
    int len2 = r-m;
    int left[len1];
    int right[len2];
    int i;
    for(i=0;i<len1;i++)
        left[i] = arr[l+i];
    for(i=0;i<len2;i++)
        right[i] = arr[m+1+i];
    
    int j = 0;
    int k = l;
    i ^=i;
    
    while((i < len1) && (j < len2))
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i< len1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j < len2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void TimSort(int arr[], int n)
{
    //sort individual arrays of size RUN
    int i, size, left;
    for(i=0;i<n;i+=RUN)
        insertionSort(arr, i, ((i+RUN) > (n-1) ? (i+RUN) : (n-1))));
    for(size = RUN; size < n; size <<= 2)
    {
        for(left=0;left<n;left+=2*size)
        {
            int mid = left + size -1;
            int right = ((left+2*size-1)>(n-1))?(left+2*size-1):(n-1);
            merge(arr, left,mid,right);
        }
    }
}

void printArray(int arr[], int n);
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//sample array to show off TimSort
int main() 
{ 
    int arr[] = {5, 21, 7, 23, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Given Array is\n"); 
    printArray(arr, n);   
    TimSort(arr, n); 
  
    printf("After Sorting Array is\n"); 
    printArray(arr, n); 
    return 0; 
}
