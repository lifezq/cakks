#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
 *  希尔排序
 *-----------------------------------------------------------------------------*/

int n;

void ShellSort(int *array)
{
    int k = n/2;
    while(k>0)
    {
        int i,j;
        for(i = k+1; i <= n; i++)
        {
            if(array[i] > array[i-k])
            {
                array[0] = array[i];
                for(j=i-k; j>0 && array[0] < array[j]; j -= k)
                {
                    array[j+k] = array[0];
                }

                array[j+k] = array[0];
            }
        }

        k = k/2;
    }
}

int main()
{
    int i;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) *n );
    printf("请输入数据（用空格分隔）：");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }

    ShellSort(array);
    printf("排序后为：");
    for(i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
