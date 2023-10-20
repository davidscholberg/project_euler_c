#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "sieve_of_eratosthenes.h"

#define prime_bound 1999999
#define composites_buffer_size prime_bound + 2

// Solution for Project Euler problem 10.
//
// Find the sum of all the primes below two million.
//
// This solution is a pretty straightforward application of the sieve of
// eratosthenes.
bool solve0010(char *buffer, size_t buffer_size)
{
    bool composites_buffer[composites_buffer_size];
    sieve_of_eratosthenes(composites_buffer, composites_buffer_size);
    uint_fast64_t sum = 0;
    for (int i = 2; i <= prime_bound; i++)
    {
        if (!composites_buffer[i])
        {
            sum += i;
        }
    }
    int ret = snprintf(buffer, buffer_size, "%lu", sum);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
