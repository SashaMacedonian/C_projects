#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define CLEAR_STDIN do { int c; while ((c = getchar()) != '\n' && c != EOF); } while(0)
#define EXAMPLE "\nPlease enter number of elements > "
#define INVALID_INPUT "\nError: invalid input\n"
#define INVALID_SIZE "\nError: size must be positive\n"
#define INVALID_MEMORY "\nError: memory allocation failed\n"

bool my_get_int(int64_t * n);
void print_start_of_program(void);
int64_t* create_array(size_t size);
void fill_array(int64_t* arr, size_t size);
void print_array(const int64_t* arr, size_t size);

int main(void)
{
    int64_t userNum = 0;
    int64_t * userArr = NULL;
    print_start_of_program();
    while (true)
    {
        printf("%s", EXAMPLE);
        if (!my_get_int(&userNum))
        {
            printf("%s", INVALID_INPUT);
            exit(EXIT_FAILURE);
        }
        else if (userNum <= 0)
        {
            printf("%s", INVALID_SIZE);
            exit(EXIT_FAILURE);

        }
        userArr = create_array(userNum);
        if (!userArr)
        {
            printf("%s", INVALID_MEMORY);
            exit(EXIT_FAILURE);

        }
        fill_array(userArr, userNum);
        print_array(userArr, userNum);
        free(userArr);
        userArr = NULL;
        exit(EXIT_SUCCESS); 
    }
    
    return 0;
}

bool my_get_int(int64_t * n)
{
    if(fscanf(stdin, "%ld", n) != 1)
        return false;
    CLEAR_STDIN;
    return true;
}

int64_t* create_array(size_t size)
{
    int64_t * n = (int64_t*)malloc(size * sizeof(*n));
    return n;
}

void fill_array(int64_t* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        *(arr + i) = i * 10;
    
}

void print_array(const int64_t* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("[%ld] = %ld ", i, *(arr+i));
    
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("                Start of the program\n");
    printf("========================================================\n");
}