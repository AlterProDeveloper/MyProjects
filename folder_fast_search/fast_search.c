#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void qsortRecursive(int *mas, int size) {
    //Указатели в начало и в конец массива
    int start = 0;
    int end = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[start] < mid) {
            start++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[end] > mid) {
            end--;
        }

        //Меняем элементы местами
        if (start <= end) {
            int tmp = mas[start];
            mas[start] = mas[end];
            mas[end] = tmp;

            start++; //Двигаем границы, пока они не встретятся
            end--; //Двигаем границы, пока они не встретятся
        }
    } while (start <= end); //Если start и end встретились на середине, то сортировка первичного массива выполнена, переход к рекурсиям, либо выходу из функции


    //Рекурсивные вызовы, если осталось, что сортировать
    if(end > 0) {
        //"Левый кусок"
        qsortRecursive(mas, end + 1);
    }
    if (start < size) {
        //"Првый кусок"
        qsortRecursive(&mas[start], size - start);
    }
}

int main()
{
    int arr[MAX] = {10, 4, 2, 14, 67, 2, 11, 33, 1, 15};
    int *p = arr;
    qsortRecursive(p, MAX);
    
    for(int i = 0; i < MAX; i++)
    {
        printf("%d", *p);
        p++;
    }

    return 0;
}
