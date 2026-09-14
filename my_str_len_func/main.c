#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define NSTR 256
#define ERINPUT "Error: Input error"

size_t my_str_len_ind(const char str[]);
size_t my_str_len_ptr(const char * str);
char * my_gets_s(char * str, size_t n);
void print_start_of_program(void);
void menu(void);

int main(void)
{
    char userStr[NSTR] = "";
    print_start_of_program();
    while (true)
    {
        menu();
        if (!my_gets_s(userStr, NSTR))
        {
            fprintf(stderr, "%s", ERINPUT);
            return 1;
            
        }
        else if (*userStr == '\0')
        {
            exit(EXIT_SUCCESS);

        }    
        printf("The number of characters in your word is - %zd\n", my_str_len_ptr(userStr));
    }
    
    return 0;
}

size_t my_str_len_ind(const char str[]) // Для практики решил использовать в нотации массива
{
    size_t counter = 0;

    for (size_t i = 0; str[i]; i++)
    {
        counter++;
    }
    return counter;
}

size_t my_str_len_ptr(const char * str) // Для практики решил использовать в нотации указателя
{
    size_t counter = 0;

    while (*str)
    {
        counter++;
        str++;
    }
    return counter;
}

char * my_gets_s(char * str, size_t n) 
{
    char * return_val = fgets(str, n, stdin);
    char * find_ch = NULL;
    if (return_val)
    {
        find_ch = strchr(return_val, '\n');
        if(find_ch)
            *find_ch = '\0';
        else
            CLEAR_STDIN;
    }
    return return_val;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("              Start of the character counter\n");
    printf("========================================================\n");
}

void menu(void)
{
    printf("\nFor exit, input enter in the beginning of string\n");
    printf("Input word for calculate characters, no more than %d chars> ", NSTR - 1);
}