#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "digits.h"
#include "gmp.h"

#define number_base 10

// Solution for Project Euler problem 16.
//
// Find the sum of the digits of the 1000th power of 2.
bool solve0016(char *buffer, size_t buffer_size)
{
    mpz_t power;
    mpz_init(power);
    mpz_set_ui(power, 2);
    mpz_pow_ui(power, power, 1000);
    char power_str[mpz_sizeinbase(power, number_base) + 2];
    mpz_get_str(power_str, number_base, power);
    mpz_clear(power);
    int digit_sum = 0;
    for (int i = 0; power_str[i] != 0; i++)
    {
        digit_sum += ascii_digit_to_integer(power_str[i]);
    }
    int ret = snprintf(buffer, buffer_size, "%d", digit_sum);
    return ret >= 0 && ret < buffer_size;
}
