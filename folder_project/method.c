#include <stdio.h>
#include <string.h>
#define MAX 100 //Пусть количество символов в строках будет равно 100, считая нуль-символ.

const int Table_size = 100;
struct data
{
    char ANUMBER_HASH[MAX], ID_TRUNK[MAX];
};

int main()
{
    struct data BlackList[Table_size]; //Пусть БД "Чёрный лист" будет представлена структурой BlackList типа struct data с количеством строк Table_size и стобцами ANUMBER_HASH[MAX], ID_TRUNK[MAX].
    char incoming_ANUMBER_HASH[MAX] = {0}; //Пусть значение ANUMBER_HASH входящего вызова будет представлено символьной строкой incoming_ANUMBER_HASH с количеством символов в строке MAX. В примере строка принимает нулевое значение.
    char incoming_ID_TRUNK[MAX] = {0}; //Пусть значение ID_входящего_транка входящего вызова будет представлено символьной строкой incoming_ID_TRUNK с количеством символов в строке MAX. В примере строка принимает нулевое значение.

/*Предполагаем, что структура struct data BlackList[Table_size] заполнена данными, а строки char incoming_ANUMBER_HASH[MAX], char incoming_ID_TRUNK[MAX] заполнены символьными значениями.*/

    for(int i = 0; i <= Table_size; i++)
        {
            if(strncmp(incoming_ANUMBER_HASH, BlackList[i].ANUMBER_HASH, MAX) == 0)
            {
                printf("Совпадение найдено. Отправить уведомление в банк!\n");
                return 0;
            }
            else if(i == Table_size)
            {
                printf("Совпадение не найдено\n");
                break;
            }
        }

    for(int i = 0; i <= Table_size; i++)
        {
            if(strncmp(incoming_ID_TRUNK, BlackList[i].ID_TRUNK, MAX) == 0)
            {
                printf("Совпадение найдено. Отправить уведомление в банк!\n");
                return 0;
            }
            else if(i == Table_size)
            {
                printf("Совпадение не найдено\n");
                break;
            }
        }

    return 0;
}