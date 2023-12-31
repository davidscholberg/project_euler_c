#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "prime_factors.h"

#define prime_factor_buffer_size 50

// Solution for Project Euler problem 3.
//
// Find the largest prime factor of the number 600851475143.
bool solve0003(char *buffer, size_t buffer_size)
{
    uint_fast64_t n = 600851475143;
    uint_fast64_t prime_factor_buffer[prime_factor_buffer_size];
    int factor_count;
    prime_factors(n, prime_factor_buffer, prime_factor_buffer_size, &factor_count);
    if (factor_count == -1 || factor_count == 0)
    {
        return false;
    }
    int ret = snprintf(buffer, buffer_size, "%lu", prime_factor_buffer[factor_count - 1]);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
