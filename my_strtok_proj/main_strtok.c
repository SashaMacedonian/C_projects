#include <stdio.h>
#include <string.h>

char * my_strtok(char *str, const char *delim);
char * my_strchr_ptr(const char* str, int c);

int main(void)
{
    char str[] = "apple, banana, cherry";
    const char * token = NULL;
    
    token = my_strtok(str, ",");
    printf("Token 1:  %s\n", token);

    token = my_strtok(NULL, ",");
    printf("Token 2: %s\n", token);
    
    token = my_strtok(NULL, ",");
    printf("Token 3: %s\n", token);

    char test[] = ",,,";
    char * result = my_strtok(test, ",");
    if (result)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("%s\n", "Result is NULL");
    }
    
    return 0;
}

char *my_strtok(char *str, const char *delim)
{
    static char * savedStr = NULL;
    if (str != NULL)
    {
        savedStr = str;
    }
    if (savedStr == NULL)
    {
        return NULL;
    }
    while (*savedStr != '\0' && my_strchr_ptr(delim, *savedStr))
    {
        savedStr++;
    }
    if (*savedStr == '\0')
    {
        return NULL;
    }
    char * startStr = savedStr;
    while (*savedStr != '\0' && !my_strchr_ptr(delim, *savedStr))
    {
        savedStr++;
    }
    if (*savedStr != '\0')
    {
        *savedStr = '\0';
        savedStr++;
    }
    return startStr;
}

char * my_strchr_ptr(const char* str, int c) // В нотации указателя
{
    while (*str != c)
        if (!*str++)
            return NULL;
    return (char*)str;
}