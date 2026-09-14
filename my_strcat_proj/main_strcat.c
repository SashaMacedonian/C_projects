#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define VALIDATION_MESSAGE_INP "Error: when reading input"
#define ARRS 256

char * my_gets_s(char * str, size_t n);
char * my_strcat(char* dest, const char* src);
char * my_strcat_ptr(char* dest, const char* src);
void print_start_of_program(void);

int main(void)
{
    char userInpF[ARRS] = "";
    char userInpS[ARRS] = "";
    size_t sz = 0;
    print_start_of_program();
    while (true)
    {
        printf("\nFor exit, input enter in the beginning of string\n");
        printf("Input first word for no more than %d chars> ", ARRS - 1);
        if (!my_gets_s(userInpF, ARRS))
        {
            exit(EXIT_FAILURE);
        }
        sz = strlen(userInpF);
        if (*userInpF == '\0')
        {
            exit(EXIT_SUCCESS);
        }
        printf("Input second word for no more than %d chars> ", ARRS - strlen(userInpF));
        if (!my_gets_s(userInpS, ARRS - sz))
        {
            exit(EXIT_FAILURE);
        }
        printf("Result: %s\n", my_strcat(userInpF, userInpS));

    }
    
    return 0;
}

char * my_gets_s(char * str, size_t n)
{
    char * returnVal = NULL;
    char * findCh = NULL;
    if (returnVal = fgets(str, n, stdin))
    {
        if (findCh = strchr(returnVal, '\n'))
        {
            *findCh = '\0';
        }
        else
        {
            CLEAR_STDIN;
        }
    }
    return returnVal;
    
}

char * my_strcat(char* dest, const char* src) // в нотации массива
{
    size_t i = 0, j = 0;
    for (; dest[i]; i++)
        ;
    for (; src[j]; i++, j++)
    {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}

char * my_strcat_ptr(char* dest, const char* src) // в нотации указателя
{
    char * temp = dest;
    while (*dest)
        dest++;
    
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    dest = temp;
    
    return dest;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("              Start of the string concatenation\n");
    printf("========================================================\n");
}
