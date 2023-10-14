#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define number_cap 1000

// Solution for Project Euler problem 1.
//
// Compute the sum of all natural numbers under 1000 that are a multiple of 3 or
// 5 (or both).
//
// The approach taken here is to first iterate through all multiples of three up
// to 1000 and sum them, but exclude multiples of 3 that are also multiples of
// 5. Then we iterate through all multiples of 5 under 1000 and add them to the
// initial sum. This approach avoids adding duplicate numbers to the sum that
// are multiples of both 3 and 5.
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
