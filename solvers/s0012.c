#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "factors.h"

#define factors_buffer_size 500

// Solution for Project Euler problem 12.
//
// Find the value of the first triangle number to have over five hundred
// divisors.
bool solve0012(char *buffer, size_t buffer_size)
{
    uint_fast64_t factors_buffer[factors_buffer_size];
    int factor_count;
    int triangle_number = 0;
    for (int natural_number = 1; true; natural_number++)
    {
        triangle_number += natural_number;
        factors(triangle_number, factors_buffer, factors_buffer_size, &factor_count);
        if (factor_count == -1)
        {
            break;
        }
    }
    int ret = snprintf(buffer, buffer_size, "%d", triangle_number);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
