// Created by Damir on 16.08.2026.
//
// Программа спрашивает: "Введите выражение (например: 5 + 3):"
// Пользователь вводит: 5 + 3
// Программа выводит: 5 + 3 = 8

// Поддержать операции: +, -, *, /
// Обработать деление на ноль: "Ошибка: деление на ноль"

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define EXAMPLE "\nPlease enter your data in the format 5 + 4 > "
#define VALIDATION_MESSAGE "\nInvalid input\n"
#define DBZ "\nError: division by zero"

typedef struct
{
    int num1;
    int num2;
    char oper;
    int result;
} Calculation;


void print_start_of_program(void);
bool read_calculation(Calculation* st);
int calculation(Calculation *cst);
bool save_to_history(const char *filename, const Calculation *calc);
char* my_gets(char* str, size_t n);
bool file_is_empty(const char * filename);
void show_n_history(const char *filename, int last_n);
void show_history(const char *filename);
int line_counter(const char *filename);
void print_menu(void);

int main(void)
{
    Calculation cstc = {0};
    int lctr = 0;
    char input[256] = "";

    print_start_of_program();

    while (true)
    {
        print_menu();
        my_gets(input, sizeof(input));
        if (input[0] == '\0')
        {
            printf("%s", EXAMPLE);
            if (!read_calculation(&cstc))
            {
                fprintf(stdout, "%s", VALIDATION_MESSAGE);
                continue;
            }
            if (cstc.oper == '/' && cstc.num2 == 0)
            {
                fprintf(stderr, "%s", DBZ);
                continue;  
            }
            printf("result: %d\n", calculation(&cstc));
            save_to_history("history.txt", &cstc);
        }
        else if (!strncmp(input, "history", 7))
        {
            if(file_is_empty("history.txt"))
            {
                printf("File is empty!\n");
                continue;
            }
            lctr = line_counter("history.txt");
            if (lctr < 10)
                show_history("history.txt");
            else
                show_n_history("history.txt", lctr - 10);
        }
        else if (!strncmp(input, "clear", 5))
        {
            if (!remove("history.txt"))
            {
                printf("all records was deleted\n");
            }
            else
            {
                perror("Error deleted\n");
            }
        }
        else if (!strncmp(input, "exit", 4))
        {
            exit(EXIT_SUCCESS);
        }
    
    }
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("                Start of the calculator\n");
    printf("========================================================\n");
}

void print_menu(void)
{
    printf("\n");
    printf("Input enter for calculate\n");
    printf("Input history for print last 10 records\n");
    printf("Input clear for clear all records\n");
    printf("Input exit > ");
}

bool read_calculation(Calculation* st)
{
    if (fscanf(stdin, "%d %c %d", &st->num1, &st->oper, &st->num2) != 3 || getchar() != '\n')
    {
            CLEAR_STDIN;
            return false;
    }
    return true; 
}


int calculation(Calculation *cst)
{
    switch (cst->oper)
    {
    case '+':
        cst->result = cst->num1 + cst->num2;
        break;
    case '-':
        cst->result = cst->num1 - cst->num2;
        break;
    case '*':
        cst->result = cst->num1 * cst->num2;
        break;
    case '/':
        cst->result = cst->num1 / cst->num2;
        break;
    default:
        printf("Invalid operator\n");
        return cst->result = -1;
    }
    return cst->result;
    
}

bool save_to_history(const char *filename, const Calculation *calc)
{
    FILE* fp = fopen(filename, "a");
    if (!fp)
    {
        perror("Cannot open history file");
        return false;
    }
    fprintf(fp, "%d %c %d = %d\n", calc->num1, calc->oper, calc->num2, calc->result);
    fclose(fp);
    return true;
}

void show_n_history(const char *filename, int last_n)
{
    FILE* fp = fopen(filename, "r");
    size_t line = 0;
    size_t r_counter = 0;
    char buffer[256] = "";
    if (!fp)
        return;
    
    while(fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (line >= last_n)
            printf("%zd. %s\n", ++r_counter, buffer);
        line++;
    }

    fclose(fp);
}

void show_history(const char *filename)
{
    FILE* fp = fopen(filename, "r");
    size_t line = 0;
    char buffer[256] = "";
    if (!fp)
        return;
    
    while(fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%zd. %s\n", ++line, buffer);

    }

    fclose(fp);
}

bool file_is_empty(const char * filename)
{
    FILE *fptr = fopen(filename, "r");
    if (!fptr)
        return false;

    fseek(fptr, 0, SEEK_END);
    size_t sfile = ftell(fptr);
    rewind(fptr);
    fclose(fptr);
    
    return (sfile == 0);
}

int line_counter(const char *filename)
{
    char buffer[256] = "";
    int counter = 0;
    FILE * fptr = fopen(filename, "r");
    if(!fptr)
        return -1;
    
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        if (buffer[0] != '\n')
            counter++;
    }
    fclose(fptr);
    return counter;
}

char* my_gets(char* str, size_t n)
{
    char* returnVal = NULL;
    char* find = NULL;

    returnVal = fgets(str, n, stdin);
    if (returnVal)
    {
        find = strchr(returnVal, '\n');
        if (find)
            *find = '\0';
        else
            CLEAR_STDIN;
    }
    return returnVal;
}
