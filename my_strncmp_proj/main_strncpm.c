#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void print_start_of_program(void);
int my_strcmp(const char * s1, const char * s2);
int my_strncmp(const char * s1, const char * s2, size_t n);
int my_strcmptr(const char * s1, const char * s2);
int my_strcmnptr(const char * s1, const char * s2, size_t n);

int main(void)
{
    print_start_of_program();
    char * s1 = "Hello";
    char * s2 = "Hello!";
    int result = 0;
    result = my_strncmp(s1, s2, 5);
    if (!result)
    {
        printf("%s is equal %s\n", s1, s2);
    }
    else
    {
        printf("%s not is equal %s\n", s1, s2);
    }

    result = my_strncmp(s1, s2, 6);
    if (!result)
    {
        printf("%s is equal %s\n", s1, s2);
    }
    else
    {
        printf("%s not is equal %s\n", s1, s2);
    }
    return 0;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("              Start of the programm\n");
    printf("========================================================\n");
}

int my_strcmp(const char * s1, const char * s2) // функция без n в нотации массива
{
    size_t i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;   
    }
    return 0;
}

int my_strncmp(const char * s1, const char * s2, size_t n) // функция с n в нотации массива
{
    size_t i = 0;
    while ((s1[i] || s2[i]) && i < n)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
        
    }
    return 0;
}

int my_strcmptr(const char * s1, const char * s2) // функция без n в нотации указателя
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}

int my_strcmnptr(const char * s1, const char * s2, size_t n) // функция с n в нотации указателя
{
    size_t i = 0;
    while ((*s1 || *s2) && i < n)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
        i++;
    }
    return 0;
}