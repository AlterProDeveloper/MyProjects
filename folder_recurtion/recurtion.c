//Сумма значений элементов статического массива рекурсией b подсчёт элементов до конца массива, который обозначен нулём.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 4

int recursion(int *p, int i)
{
    if (i == 1)
    {
        return *p;
    }
    else
    {
        return recursion(p + 1, i - 1) + *p;
    }
}

int recursion_count(int *p)
{
    if (*p == 0)
    {
        return 0;
    }
    else
    {
        return recursion_count(p + 1) + 1;
    }
}

int main() {

    int x[MAX] = {1, 200, 3000, 0};
    int *p = x;
    int i = MAX;
    printf("%d ", recursion(p, i));
    printf("%d ", recursion_count(p));

    return 0;
}