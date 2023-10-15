#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_MAIN_STRING 100

char **func_dynamic_massive()
{
    char main_string[MAX_MAIN_STRING] = {0};
    char **dynamic_massive = NULL;
    char *p_start = main_string;
    char *p_end = main_string;
    char *p_right = NULL;
    char *p_left = NULL;
    int check = 0;
    int count = 0;
    int realloc_amount = 0;
    size_t length;

    dynamic_massive = (char**)malloc(sizeof(char*));
    realloc_amount++;

    if(dynamic_massive == NULL)
    {
        printf("allocate fail!\n");
        free(dynamic_massive);
        return NULL;
    }
    fgets(main_string, MAX_MAIN_STRING, stdin);
    printf("Исходная строка: %s\n", main_string);

    while(*p_start != '\0' && *p_start != '\n')
    {
        while(*p_end != ' ' && *p_end != '\n' && *p_end != '\0')
        {
            p_end++;
        } 
    
        length = p_end - p_start;

        if(length % 2 == 0 || length < 7)
        {
            printf("Нечётное, либо слишком маленькое слово!\n");
            p_end++;
            p_start = p_end;
            continue;
        }

            p_right = p_end - (length / 2);
            p_left = p_start + (length / 2) - 1;

            for(int i = 0; i < (length / 2); i++)
            {
                if(strncmp(p_right, p_left, 1) != 0)
                {
                    printf("слово не симметрично!\n");
                    goto stop;
                }
                p_right++;
                p_left--;
            }

                dynamic_massive[count] = (char*)calloc(length + 1, sizeof(char));

                if(dynamic_massive[count] == NULL)
                {
                    printf("allocate fail!\n");
                    free(dynamic_massive); /*а остальные строки и массив указателей, кто освобождать будет?*/
                    return dynamic_massive; /*зачем вовзращать не удачный массив? Так как ты его не NULL, но частично освободил, ф-ия получит указатель на память, подумает что все ок и упадет*/
                }

                snprintf(dynamic_massive[count], length + 1, "%s", p_start);
                snprintf(dynamic_massive[count] + length, 2, "%c", '\0');

                realloc_amount++;
                char **massive_realloc = (char**)realloc(dynamic_massive, realloc_amount * sizeof(char*));

                if(massive_realloc == NULL)
                {
                    printf("realloc failed!\n");
                    free(dynamic_massive);
                    return dynamic_massive;
                }

                dynamic_massive = massive_realloc;
                printf("%s\n", dynamic_massive[count]);
                count++;

            stop: p_end++;
            p_start = p_end;
            length = 0;
            check = 0;
    }
    printf("Количество смметричных слов: %d\n", count);
    printf("Количество указателей в динамическом массиве: %d\n", realloc_amount - 1);

    return dynamic_massive;
}

int main()
{
    char **main_massive;

    main_massive = func_dynamic_massive();
    free(main_massive);

    return 0;
}
//abcdcba abcdcba abcdcba abcdcba
//abab abcdcba abcdcba abcdcba abcdcba qwertytrewq ghjklkjhg kek
