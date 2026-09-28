#include <stdio.h>
#include "string_utils.h"

int main(void)
{
    int test = 0;
    test = my_atoi("4193 with words");
    printf("%d\n", test);

    test = my_atoi("words and 987");
    printf("%d\n", test);

    test = my_atoi("+42");
    printf("%d\n", test);

    test = my_atoi("-42");
    printf("%d\n", test);

    test = my_atoi("   1024");
    printf("%d\n", test);

    test = my_atoi("99999999999999");
    printf("%d\n", test);

    return 0;
}