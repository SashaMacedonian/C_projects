#include <stdio.h>
#include <stdbool.h>

size_t my_strcspn(const char *s, const char *reject);

int main(void)
{
    printf("Result: %zd\n", my_strcspn("129th", "th"));
    printf("Result: %zd\n", my_strcspn("Hello", "xyz"));
    printf("Result: %zd\n", my_strcspn("abc", "c"));    
    printf("Result: %zd (expected 0)\n", my_strcspn("a", "aa"));
    return 0;
}


size_t my_strcspn(const char *s, const char *reject)
{
    size_t elem_i = 0;
    for (; s[elem_i] != '\0'; elem_i++)
    {
        for (size_t j = 0; reject[j] != '\0'; j++)
        {
            if (s[elem_i] == reject[j])
            {
                return elem_i;
            }
        }
    }
    return elem_i;
}