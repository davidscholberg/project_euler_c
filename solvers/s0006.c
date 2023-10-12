#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool solve0006(char *buffer, size_t buffer_size)
{
    int sum_of_squares = 0;
    int sum = 0;
    for (int n = 1; n <= 100; n++)
    {
        sum_of_squares += n * n;
        sum += n;
    }
    int ret = snprintf(buffer, buffer_size, "%d", (sum * sum) - sum_of_squares);
    return ret >= 0 && ret < buffer_size;
}
