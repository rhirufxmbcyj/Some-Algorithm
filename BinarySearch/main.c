#include <stdio.h>
#include <assert.h>
/*被查询的数据应是有序的*/
int binary_search(int *data, int length, int value)
{
    int start = 0, end = length - 1;
    int mid = 0;
    while(start <= end)
    {
        mid = (end + start) / 2;
        if(data[mid] == value)
            return mid;
        if(data[mid] > value)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int test_value[]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19,0,21,22,23,24,25,26,27,28};
    printf("index is %d\n", binary_search(test_value,sizeof(test_value)/sizeof(int),15));
    return 0;
}
