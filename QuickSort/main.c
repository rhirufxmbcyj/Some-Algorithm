#include <stdio.h>

void quick_sort(int *array, int len)
{
    if (len <= 1)
        return;
    int tmp = 0;
    int mid = array[0];
    int i = 0, j = len - 1;
    while (i != j)
    {
        while (array[j] >= mid && j > i)
            j--;
        while (array[i] <= mid && i < j)
            i++;
        if (i < j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    array[0] = array[i];
    array[i] = mid;

    quick_sort(array, i);
    quick_sort(array + i + 1, len - i-1);
}

int main()
{
    int array[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
    int len = sizeof(array)/4;
    int i = 0;
    while (i != len)
    {
        printf("%d ", array[i++]);
    }
    printf("\n");

    quick_sort(array, len);

    i = 0;
    while (i != len)
    {
        printf("%d ", array[i++]);
    }
    printf("\n");
}