#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 10
#define MAX_NUM 1000

int main()
{
    int arr[MAX] = {156, 18, 54, 66, 34, 78, 7, 4, 8, 54};
    int new_arr[MAX] = {0};
    int min;
    int length = MAX;
    int k = 0;

    for(int j = 0; j < MAX; j++)
    {
        min = MAX_NUM;

        for(int i = 0; i < length; i++)
        {

            if(arr[i] < min)
            {
                min = arr[i];
                k = i;
            }
        }

        new_arr[j] = min;
        printf("%d ", new_arr[j]);

        for(int i = k; i < length; i++)
        {
            arr[i] = arr[i + 1];
        }

        length--;
    }
    return 0;
}