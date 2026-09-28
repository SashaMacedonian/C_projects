#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int my_atoi(const char *str)
{
    while (isspace(*str))
    {
        str++;
    }
    bool isNegative = false;
    if (*str == '-')
    {
        isNegative = true;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    
    int result  = 0;
    while (*str != '\0' && *str >= '0' && *str <= '9')
    {
        if (result > (INT_MAX - (*str - '0')) / 10) 
        {
            return isNegative ? INT_MIN : INT_MAX;
        }
        result = (result * 10) + (*str - '0');
        str++;
    }
    if (isNegative)
    {
        result = result * -1;
    }
    
    return result;
}