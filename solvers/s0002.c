#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max_number 4000000

// Solution for Project Euler problem 2.
//
// Compute the sum of the even-valued fibonacci numbers up to 4000000.
bool solve0002(char *buffer, size_t buffer_size)
{
    int sum = 0;
    int previous = 0;
    int current = 1;
    while (current <= max_number)
    {
        if (current % 2 == 0)
        {
            sum += current;
        }
        int new = current + previous;
        previous = current;
        current = new;
    }
    int ret = snprintf(buffer, buffer_size, "%d", sum);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
