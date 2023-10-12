#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define number_cap 1000

bool solve0001(char *buffer, size_t buffer_size)
{
    int sum = 0;
    int multiple = 3;
    while (multiple < number_cap)
    {
        if (multiple % 5 != 0)
        {
            sum += multiple;
        }
        multiple += 3;
    }
    multiple = 5;
    while (multiple < number_cap)
    {
        sum += multiple;
        multiple += 5;
    }
    int ret = snprintf(buffer, buffer_size, "%d", sum);
    return ret >= 0 && ret < buffer_size;
}
