/*Каждый узел однонаправленного (односвязного) линейного списка (ОЛС) содержит одно поле указателя на следующий узел.
Поле указателя последнего узла содержит нулевое значение (указывает на NULL).*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 30

struct spisok
{
    int data;
    struct spisok *ptr_next;
};

//Функция инициализации списка

struct spisok *init(int a) // a - значение первого узла
{
    struct spisok *root_ptr;
    root_ptr = (struct spisok*)malloc(sizeof(struct spisok));
    root_ptr->data = a;
    root_ptr->ptr_next = NULL;
    return (root_ptr);
}

//Функция добавления узла в список

struct spisok *AddElem(struct spisok *ptr_element, int a)
{
    struct spisok *ptr_new_element, *tmp;
    ptr_new_element = (struct spisok*)malloc(sizeof(struct spisok));
    tmp = ptr_element->ptr_next;
    ptr_element->ptr_next = ptr_new_element;
    ptr_new_element->data = a;
    ptr_new_element->ptr_next = tmp;
    return(ptr_new_element);
}

//Функция удаления узла из списка

struct spisok *DeleteElem(struct spisok *ptr_element, struct spisok *root)
{
    struct spisok *ptr;
    ptr = root;

    while(ptr->ptr_next != ptr_element)
    {
        ptr = ptr->ptr_next;
    }

    ptr->ptr_next = ptr_element->ptr_next;
    free(ptr_element);
    return(ptr);
}

//Функция удаления корня списка

struct spisok *DeleteRoot(struct spisok *root)
{
    struct spisok *new_root;
    new_root = root->ptr_next;
    free(root);
    return(new_root);
}

//Функция вывода элементов списка

void PrintSpisok(struct spisok *root)
{
    struct spisok *ptr;
    int i = 0;
    ptr = root;

    do
    {
        printf("Элемент №%d: %d\n", i, ptr->data);
        ptr = ptr->ptr_next;
        i++;
    }
    while(ptr != NULL);
}

int main()
{
    struct spisok main_spisok[MAX] = {0};
    struct spisok *current_ptr = NULL;
    struct spisok *current_root_ptr = NULL;
    int a = 0;

    printf("Что делаем со списком? 1 - Инициализируем, 2 - добавляем узел, 3 - удаляем узел, 4 -удаляем корень, 5 - выводим элементы, e - выход\n");

    while(1)
    {
        switch(getchar())
        {
            case '1': printf("Введите числовое значение для корневого узла списка\n");
            scanf("%d", &a);
            current_ptr = current_root_ptr = init(a);
            printf("\nКорневой узел добавлен!\n");
            printf("Что делаем со списком? 1 - Инициализируем, 2 - добавляем узел, 3 - удаляем узел, 4 -удаляем корень, 5 - выводим элементы, e - выход\n");
            break;
            case '2': printf("Введите числовое значение для добавляемого узла списка\n");
            scanf("%d", &a);
            current_ptr = AddElem(current_ptr, a);
            printf("Узел со значением %d добавлен!\n", a);
            printf("Что делаем со списком? 1 - Инициализируем, 2 - добавляем узел, 3 - удаляем узел, 4 -удаляем корень, 5 - выводим элементы, e - выход\n");
            break;
            case '3': current_ptr = DeleteElem(current_ptr, current_root_ptr);
            printf("Последний узел удалён!");
            break;
            case '4': current_root_ptr = DeleteRoot(current_root_ptr);
            printf("Корневой узел дуалён!");
            break;
            case '5': PrintSpisok(current_root_ptr);
            printf("Что делаем со списком? 1 - Инициализируем, 2 - добавляем узел, 3 - удаляем узел, 4 -удаляем корень, 5 - выводим элементы, e - выход\n");
            break;
            case 'e': return 0;
        }
    }
}
