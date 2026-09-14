#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    bool* arr = NULL;
    int n = 30;
    arr = (bool*)malloc((n + 1) * sizeof(bool));
    if (arr)
        for (size_t i = 0; i <= n; i++)
            arr[i] = true;
    else
    {
        printf("Error with memory");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 2; i <= n; i++)
    {
        if (arr[i])
            for (size_t j = i * i; j <= n; j += i)
                arr[j] = false;
    }

    for (int i = 2; i <= n; ++i)
        if (arr[i])
            printf("%d ", i);

    free(arr);
    arr = NULL;

    return 0;
}
