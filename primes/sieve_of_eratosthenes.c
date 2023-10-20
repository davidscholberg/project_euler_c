#include <stdbool.h>
#include <stdlib.h>

void sieve_of_eratosthenes(bool *composites_buffer, size_t composites_buffer_size)
{
    for (int i = 0; (unsigned int)i < composites_buffer_size; i++)
    {
        composites_buffer[i] = false;
    }
    int current_prime = 2;
    int max_number = composites_buffer_size - 2;
    while (current_prime <= max_number)
    {
        for (int multiple = current_prime * 2; multiple <= max_number; multiple += current_prime)
        {
            composites_buffer[multiple] = true;
        }
        current_prime++;
        while (composites_buffer[current_prime])
        {
            current_prime++;
        }
    }
}
