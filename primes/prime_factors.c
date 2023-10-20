#include <stdint.h>
#include <stdlib.h>

void prime_factors(uint_fast64_t n, uint_fast64_t *buffer, size_t buffer_size, int *factor_count)
{
    int buffer_index = 0;
    *factor_count = 0;
    uint_fast64_t potential_prime_factor = 2;
    while (n > 1)
    {
        if (n % potential_prime_factor == 0)
        {
            if ((unsigned int)buffer_index >= buffer_size)
            {
                *factor_count = -1;
                return;
            }
            buffer[buffer_index] = potential_prime_factor;
            n /= potential_prime_factor;
            buffer_index++;
            (*factor_count)++;
        }
        else
        {
            potential_prime_factor++;
        }
    }
}
