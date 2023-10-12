#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "return_types.h"

bool_or_error is_palindromic_number(int n, char *buffer, size_t buffer_size)
{
    int digit_count = snprintf(buffer, buffer_size, "%d", n);
    if (digit_count <= 0 || digit_count >= buffer_size)
    {
        return error_condition;
    }
    for (int i = 0; i < digit_count / 2; i++)
    {
        if (buffer[i] != buffer[digit_count - i - 1])
        {
            return bool_false;
        }
    }
    return bool_true;
}
