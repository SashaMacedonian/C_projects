//
// Created by Damir on 16.08.2026.
//
// Вывести числа от 1 до 100
// Если число делится на 3 → вывести "Fizz"
// Если число делится на 5 → вывести "Buzz"
// Если делится и на 3, и на 5 → вывести "FizzBuzz"
// Иначе → вывести само число

// Пример вывода:
// 1
// 2
// Fizz
// 4
// Buzz
// Fizz
// ...
// 14
// FizzBuzz
// ...

#include <stdio.h>

#define ARRSIZE 100

void init_array(int * arr, size_t n);
void print_start_of_program();
void print_FizzBuzz(const int * arr, size_t n);

int main(void) 
{
    
    print_start_of_program();
    
    int arr[ARRSIZE] = {0};
    
    init_array(arr, ARRSIZE);

    print_FizzBuss(arr, ARRSIZE);
    
    return 0;
}

void print_start_of_program(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("                Start of the FizzBuzz\n");
    printf("========================================================\n");
}

void init_array(int * arr, size_t n) 
{
    for(size_t i = 0; i < n; i++) {
        *(arr + i) = i + 1;
    }
}


void print_FizzBuzz(const int * arr, size_t n) 
{
    for (size_t i = 0; i < n; i++)
    {
        if (*(arr + i) % 3 == 0 && *(arr + i) % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (*(arr + i) % 5 == 0) 
        {
            printf("Buzz\n");
        }
        else if (*(arr + i) % 3 == 0) 
        {
            printf("Fizz\n");
        }
        else 
        {
            printf("%d\n", *(arr + i));
        }
    }
    
}

