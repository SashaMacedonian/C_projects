#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define VALIDATION_MESSAGE_INP "Error: when reading input"
#define ARRS 256

void print_start_of_program(void);
char * my_strchr(const char* str, int c);
char * my_strchr_ptr(const char* str, int c);

int main(void)
{
    print_start_of_program();
    char testWord[ARRS] =  "Hello";
    char * ch = NULL;
    ch = my_strchr("Hello", 'o');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr("Hello", '\0');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr("Hello", 'z');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr("Hello", 'H');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr("", '\0');
    printf("str=%p, found=%p\n\n", (void*)testWord, (void*)ch);

    ch = NULL;
    ch = my_strchr_ptr("Hello", 'o');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr_ptr("Hello", '\0');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr_ptr("Hello", 'z');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr_ptr("Hello", 'H');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    ch = my_strchr_ptr("", '\0');
    printf("str=%p, found=%p\n", (void*)testWord, (void*)ch);
    return 0;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("              Start of the programm\n");
    printf("========================================================\n");
}

char * my_strchr(const char* str, int c) // В нотации массива
{
    size_t i = 0;
    while (str[i] != c)
        if (!str[i++])
            return NULL;
    return (char*)&str[i];
}

char * my_strchr_ptr(const char* str, int c) // В нотации указателя
{
    while (*str != c)
        if (!*str++)
            return NULL;
    return (char*)str;
}