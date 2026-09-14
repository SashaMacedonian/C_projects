#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define VALIDATION_MESSAGE_INP "Error: when reading input"
#define ARRS 256

char * my_gets_s(char * str, size_t n);
void print_start_of_program(void);
void menu(void);
char* my_strcpy_ptr(char* dest, const char* src);
char* my_strcpy(char* dest, const char* src);

int main(void)
{
    char userStr[ARRS] = "";
    char destBuff[ARRS] = "";
    print_start_of_program();
    while (true)
    {
        
        menu();
        if (!my_gets_s(userStr, ARRS))
        {
            printf("%s", VALIDATION_MESSAGE_INP);
            exit(EXIT_FAILURE);
        }
        else if (!(*userStr))
        {
            exit(EXIT_SUCCESS);
        }
        
        my_strcpy(destBuff, userStr);
        printf("Original string: %s, copy of the string: %s\n", userStr, destBuff);
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

char* my_strcpy_ptr(char* dest, const char* src) // В нотации указателя
{
    char * tempPtr = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    dest = tempPtr;
    return dest;
}

char* my_strcpy(char* dest, const char* src)
{
    size_t i = 0;
    for (; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("              Start of the string copy\n");
    printf("========================================================\n");
}

void menu(void)
{
    printf("\nFor exit, input enter in the beginning of string\n");
    printf("\nPlease enter your word for copy, max %d chars > ", ARRS - 1);
}