#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *my_strpbrk(const char *s, const char *accept);

int main(void)
{
    const char * s = "Hello";
    const char * accept = "xyz";
    printf("Start: %p, Result:%p\n", s, my_strpbrk(s, accept));
    s = "Hello";
    accept = "aeiou";
    printf("Start: %p, Result:%p\n", s, my_strpbrk(s, accept));
    s = "129th";
    accept = "th";
    printf("Start: %p, Result:%p\n", s, my_strpbrk(s, accept));
    return 0;
}

char *my_strpbrk(const char *s, const char *accept)
{
    size_t el_i = 0;
    for (; s[el_i] != '\0'; el_i++)
    {
        for (size_t j = 0; accept[j] != '\0'; j++)
        {
            if (s[el_i] == accept[j])
            {
                return (char*)s + el_i;
            }
        }
    }
    return NULL;
}