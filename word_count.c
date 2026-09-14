// Ввод: строка (максимум 256 символов)
// Вывод: количество слов

// Слово = последовательность непробельных символов
// Множественные пробелы игнорируются:
//   "Hello   world" → 2
//   "  leading spaces" → 2
//   "trailing spaces  " → 2
//   "" → 0
//   "single" → 1

// Использовать fgets для чтения строки

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZES 256
#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)


char * gets_s(char * str, size_t n, const char * welcome);
size_t word_counter(const char * str);
void print_start_of_program(void);

int main(void) 
{   
    print_start_of_program();
    char myStr[SIZES] = "";
    gets_s(myStr, SIZES, "Input your string > ");
    printf("%s\n", myStr);
    printf("Counter of words in %s is %zu", myStr, word_counter(myStr));
    return 0;
}

char * gets_s(char * str, size_t n, const char * welcome) 
{
    printf("%s", welcome);
    char * returnVal = NULL;
    char * find = NULL;
    returnVal = fgets(str, n, stdin);
    
    if(returnVal) 
    {
        find = strchr(returnVal, '\n');
        if(find) 
        {
            *find = '\0';
        }
        else 
        {
            CLEAR_STDIN;
        }
    }
    return returnVal;
}

size_t word_counter(const char * str) 
{
    bool isWord = false;
    size_t counter = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && !isWord) 
        {
            counter++;
            isWord = true;
        }
        if(str[i] == ' ') 
        {
            isWord = false;
        }
    }
    return counter;
    
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("                Start of the FizzBuzz\n");
    printf("========================================================\n");
}