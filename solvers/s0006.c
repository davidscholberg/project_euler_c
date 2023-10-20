#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Solution for Project Euler problem 6.
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.
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
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
