#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "digits.h"

#define n_min 1
#define n_max 1000
#define n_str_size 5

// Solution for Project Euler problem 17.
//
// Find how many letters would be used if all the numbers from 1 to 1000
// inclusive were written out in words.
//
// The approach taken here was to create arrays that map the digit values to the
// letter counts of those digits based on where the digits lie in the number.
// Then instead of building up the number phrase, we can just add up the letter
// counts.
bool solve0017(char *buffer, size_t buffer_size)
{
    int ones_counts[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    int teens_counts[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int tens_counts[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    int and_count = 3;
    int hundred_count = 7;
    int thousand_count = 8;
    int letter_count = 0;
    for (int n = n_min; n <= n_max; n++)
    {
        char n_str[n_str_size];
        int digit_count = snprintf(n_str, n_str_size, "%d", n);
        if (digit_count <= 0 || (unsigned int)digit_count >= n_str_size)
        {
            return false;
        }
        int digit = -1;
        for (int exponent = 0; exponent < digit_count; exponent++)
        {
            int digit_index = digit_count - exponent - 1;
            int previous_digit = digit;
            digit = ascii_digit_to_integer(n_str[digit_index]);
            switch (exponent)
            {
            case 0:
                letter_count += ones_counts[digit];
                break;
            case 1:
                if (digit == 1)
                {
                    letter_count -= ones_counts[previous_digit];
                    letter_count += teens_counts[previous_digit];
                }
                else
                {
                    if (previous_digit == 0)
                    {
                        letter_count -= ones_counts[previous_digit];
                    }
                    letter_count += tens_counts[digit];
                }
                break;
            case 2:
                if (digit != 0)
                {
                    letter_count += ones_counts[digit];
                    letter_count += hundred_count;
                    if (n_str[digit_index + 1] != '0' || n_str[digit_index + 2] != '0')
                    {
                        letter_count += and_count;
                    }
                }
                break;
            case 3:
                letter_count += ones_counts[digit];
                letter_count += thousand_count;
                if (n_str[digit_index + 1] == '0' && (n_str[digit_index + 2] != '0' || n_str[digit_index + 3] != '0'))
                {
                    letter_count += and_count;
                }
            }
        }
    }
    int ret = snprintf(buffer, buffer_size, "%d", letter_count);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
