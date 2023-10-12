#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "return_types.h"
#include "palindromes.h"

#define digits_buffer_size 50

bool solve0004(char *buffer, size_t buffer_size)
{
    char digits_buffer[digits_buffer_size];
    int largest_palindromic_number = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = i + 1; j < 1000; j++)
        {
            int product = i * j;
            bool_or_error status = is_palindromic_number(product, digits_buffer, digits_buffer_size);
            if (status == error_condition)
            {
                return false;
            }
            if (status == bool_true)
            {
                if (product > largest_palindromic_number)
                {
                    largest_palindromic_number = product;
                }
            }
        }
    }
    int ret = snprintf(buffer, buffer_size, "%d", largest_palindromic_number);
    return ret >= 0 && ret < buffer_size;
}
