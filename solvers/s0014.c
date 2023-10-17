#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define next_collatz_number(n) (n % 2 == 0) ? n / 2 : (3 * n) + 1

#define sequence_buffer_size 10000000
#define max_starting_number 999999
#define sequence_length_cache_size max_starting_number + 1

// Solution for Project Euler problem 14.
//
// Find the starting number, under one million, that produces the longest
// Collatz sequence.
//
// The approach taken here is to use an integer array to cache the collatz
// sequence lengths so that the lengths do not have to be recalculated for each
// input. The integer array size is limited to 1000000, which means that the
// sequence lengths of some collatz numbers can't be cached, but the alternative
// approaches (increasing the cache size or using a hashmap) have their own
// performance tradeoffs (the former's being space and the latter's being time).
bool solve0014(char *buffer, size_t buffer_size)
{
    int *sequence_length_cache = calloc(sequence_length_cache_size, sizeof(int));
    sequence_length_cache[1] = 1;
    uint_fast64_t *sequence_buffer = malloc(sequence_buffer_size * sizeof(uint_fast64_t));
    int max_sequence_length = 1;
    int target_starting_number = 1;
    bool return_status = false;
    for (int n = 2; n <= max_starting_number; n++)
    {
        uint_fast64_t sequence_number = n;
        int sequence_length = 0;
        size_t sequence_buffer_index = 0;
        while (true)
        {
            if (sequence_number < sequence_length_cache_size && sequence_length_cache[sequence_number] != 0)
            {
                sequence_length += sequence_length_cache[sequence_number];
                if (sequence_length > max_sequence_length)
                {
                    max_sequence_length = sequence_length;
                    target_starting_number = n;
                }
                break;
            }
            if (sequence_buffer_index >= sequence_buffer_size)
            {
                goto cleanup;
            }
            sequence_buffer[sequence_buffer_index] = sequence_number;
            sequence_buffer_index++;
            sequence_number = next_collatz_number(sequence_number);
            sequence_length++;
        }
        for (int i = 0; i < sequence_buffer_index; i++)
        {
            if (sequence_buffer[i] < sequence_length_cache_size)
            {
                sequence_length_cache[sequence_buffer[i]] = sequence_length - i;
            }
        }
    }
    int chars_written = snprintf(buffer, buffer_size, "%d", target_starting_number);
    return_status = chars_written >= 0 && chars_written < buffer_size;
cleanup:
    free(sequence_buffer);
    free(sequence_length_cache);
    return return_status;
}
