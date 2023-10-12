#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sieve_of_eratosthenes.h"

#define nth 10001
// this is the upper bound for the 10001st prime number, calculated via:
// n * math.ceil(math.log(n) + math.log(math.log(n)))
// the above is good for n >=6
#define upper_bound 120012
#define composites_buffer_size upper_bound + 2

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
    return ret >= 0 && ret < buffer_size;
}
