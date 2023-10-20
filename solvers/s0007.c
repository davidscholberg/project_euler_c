#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sieve_of_eratosthenes.h"

#define nth 10001
// This is the upper bound for the 10001st prime number, calculated via:
// n * math.ceil(math.log(n) + math.log(math.log(n)))
// The above upper bound formula is good for n >=6.
#define upper_bound 120012
#define composites_buffer_size upper_bound + 2

// Solution for Project Euler problem 7.
//
// Find the 10001st prime number.
//
// The approach taken here was to pre-calculate the upper bound of the 10001st
// prime number using the formula above, calling the sieve_of_eratosthenes
// function to calculate all prime numbers up to that upper bound, and then
// counting the generated primes up to the 10001st.
bool solve0007(char *buffer, size_t buffer_size)
{
    bool composites_buffer[composites_buffer_size];
    sieve_of_eratosthenes(composites_buffer, composites_buffer_size);
    int result = 0;
    int prime_count = 0;
    for (int i = 2; i < composites_buffer_size; i++)
    {
        if (!composites_buffer[i])
        {
            prime_count++;
        }
        if (prime_count == nth)
        {
            result = i;
            break;
        }
    }
    int ret = snprintf(buffer, buffer_size, "%d", result);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
