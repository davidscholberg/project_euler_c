#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define write_factor_to_buffer(factor)   \
    do                                   \
    {                                    \
        if (buffer_index >= buffer_size) \
        {                                \
            *factor_count = -1;          \
            return;                      \
        }                                \
        buffer[buffer_index] = factor;   \
        buffer_index++;                  \
        (*factor_count)++;               \
    } while (0)

void factors(uint_fast64_t n, uint_fast64_t *buffer, size_t buffer_size, int *factor_count)
{
    buffer[0] = 1;
    *factor_count = 1;
    int buffer_index = 1;
    for (int potential_factor = 2; potential_factor < ((int)sqrt(n)) + 1; potential_factor++)
    {
        if (n % potential_factor == 0)
        {
            write_factor_to_buffer(potential_factor);
            int partner_factor = n / potential_factor;
            if (partner_factor != potential_factor)
            {
                write_factor_to_buffer(partner_factor);
            }
        }
    }
    write_factor_to_buffer(n);
}
