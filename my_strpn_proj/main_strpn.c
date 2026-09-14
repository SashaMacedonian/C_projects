#include <stdio.h>
#include <stdbool.h>

size_t my_strspn(const char *s, const char *accept);

int main(void)
{
    printf("Result: %zd\n", my_strspn("129th", "1234567890"));
    printf("Result: %zd\n", my_strspn("Hello", "xyz"));
    printf("Result: %zd\n", my_strspn("123", "12345"));    
    printf("Result: %zd (expected 1)\n", my_strspn("a", "aa"));
    return 0;
}

size_t my_strspn(const char *s, const char *accept)
{
    bool isFound = false;
    size_t i = 0;
    for (; s[i] != '\0'; i++)
    {
        isFound = false;
        for (size_t j = 0; accept[j] != '\0'; j++)
        {
            if (s[i] == accept[j])
                isFound = true;
        }
        if (!isFound)
            return i;        
    }
    return i;
}
