#include <stdlib.h>
#include <stdio.h>

// 冒泡排序
void BubbleSort(int *array)
{
    int j,j,temp;

    for(i = 0; i < n - 1; i++)
    {

        for ( j = 0; j < n - 1 - i; j++ )
        {
            if( array[j] > array[j+1] )
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// 快速排序
int Partition(int *array, int low, int high)
{
    int pivotkey = array[low];
    array[0] = array[low];

    while(low < high)
    {

        while(low < high && array[high] >= pivotkey)
        {
            high--;
        }

        array[low] = array[high];

        while(low < high && array[low] <= pivotkey)
        {
            low++;
        }

        array[high] = array[low];
    }

    array[low] = array[0];

    return low;
}

void QuickSort(int *array, int low, int high)
{
    if(low < high)
    {
        int pivotloc = Partition(array, low, high);

        QuickSort(array, low, pivotloc-1);
        QuickSort(array,  pivotloc+1, high);
    }
}

