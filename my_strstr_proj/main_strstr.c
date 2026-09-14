#include <stdio.h>
#include <string.h>

char *my_strstrind(const char * src, const char * dest);
char *my_strstrptr(const char * src, const char * dest);

int main(void)
{

    const char * result = NULL;
    result = my_strstrind("Hello, World!", "World!");
    printf("Tests with index version\n");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }

    result = my_strstrind("Hello", "Z");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }

    result = my_strstrind("Hello", "");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }

    result = my_strstrptr("Hello, World!", "World!");
    printf("Tests with ptr version\n");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }

    result = my_strstrptr("Hello", "Z");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }

    result = my_strstrptr("Hello", "");
    if (!result)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Result is %s\n", result);
    }
    
    return 0;
}

char *my_strstrind(const char * src, const char * dest)
{
    if (dest[0] == '\0')
        return (char*)src;
    
    size_t ctr = 0;
    size_t sizeSrc = strlen(dest);
    for (size_t i = 0; src[i]; i++)
    {        
        ctr = 0;
        for (size_t j = 0; dest[j] && src[j + i] == dest[j]; j++)
        {
            ctr++;
        }
        if (ctr == sizeSrc)
        {
            return (char*)&src[i];
        }
    }
    return NULL;
}

char *my_strstrptr(const char * src, const char * dest)
{
    if (*dest == '\0')
        return (char*)src;
    
    size_t sizeSrc = strlen(dest);
    char * tempS = NULL;
    const char * tempD = dest;
    while (*src)
    {
        tempS = src;
        dest = tempD;
        while (*dest && *src == *dest)
        {
            src++;
            dest++;
        }
        if (*dest == '\0')
            return (char*)tempS;
        src++;
    }
    return NULL;
}