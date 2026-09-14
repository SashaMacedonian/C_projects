#include <stdio.h>

char *my_strrchrptr(const char *s, int c);

int main(void)
{
    const char * str = "Hello";
    char * find = NULL;
    
    find = my_strrchrptr(str, 'l');
    if (!find)
        printf("Result: NULL (not found)\n");
    else
        printf("Result: %s\n", find);

    find = my_strrchrptr(str, 'z');
    if (!find)
        printf("Result: NULL (not found)\n");
    else
        printf("Result: %s\n", find);
    
    find = my_strrchrptr(str, '\0');
    if (!find)
        printf("Result: NULL (not found)\n");
    else
        printf("Result: %s\n", find);
    return 0;
}

char *my_strrchrptr(const char *s, int c)
{
    char * end = (char*)s;
    while (*end++)
        ;
    while (*end != c)
    {
        if (end == s)
            return NULL;
        end--;
    }
    return end;
}
