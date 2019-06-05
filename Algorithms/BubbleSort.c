/******************************************************************************
Gordon Stangler
Bubble sort.  Space Complexity O(1), Time Complexity O(n^2)
*******************************************************************************/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int ArrayList[], int n)
{
    int i, j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(ArrayList[j] > ArrayList[j+1])   swap(&ArrayList[j], &ArrayList[j+1]);
        }
    }
}

void printList(int ArrayList[], int size)
{
    int i;
    for(i=0;i<size; i++)
    {
        printf("%d ", ArrayList[i]);
    }
    printf("\n");
}

int main()
{
    int ArrayList[] = {5,7,10,54,3,7,33,26,12,8};
    int n = sizeof(ArrayList)/sizeof(ArrayList[0]);
    
    printf("Unsorted List\n");
    printList(ArrayList, n);
    bubbleSort(ArrayList, n);
    printf("Sorted List\n");
    printList(ArrayList, n);

    return 0;
}
