#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "digits.h"

#define sliding_window_size 13

// Solution for Project Euler problem 8.
//
// Find the thirteen adjacent digits in the given 1000-digit number that have
// the greatest product and return that product.
//
// The approach taken here is to store and cycle through the integer digits of
// the number using a ring buffer. Once the ring buffer is full, the program
// keeps a running product variable that simply gets divided from and multiplied
// to as the ring buffer moves through the digits of the number. If a zero digit
// is encountered in the number, the ring buffer is "emptied" and refilled
// starting from the digit after the zero.
bool solve0008(char *buffer, size_t buffer_size)
{
    char big_number_str[] =
        "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";
    size_t big_number_size = (sizeof(big_number_str) / sizeof(big_number_str[0])) - 1;
    int sliding_window[sliding_window_size];
    uint_fast64_t product = 1;
    uint_fast64_t max_product = 1;
    int fill_counter = 0;
    for (int i = 0; (unsigned int)i < big_number_size; i++)
    {
        if (big_number_str[i] == '0')
        {
            fill_counter = 0;
            product = 1;
            continue;
        }
        int sliding_window_index = i % sliding_window_size;
        if (fill_counter < sliding_window_size)
        {
            sliding_window[sliding_window_index] = ascii_digit_to_integer(big_number_str[i]);
            product *= sliding_window[sliding_window_index];
            fill_counter++;
            if (fill_counter == sliding_window_size)
            {
                if (product > max_product)
                {
                    max_product = product;
                }
            }
        }
        else
        {
            product /= sliding_window[sliding_window_index];
            sliding_window[sliding_window_index] = ascii_digit_to_integer(big_number_str[i]);
            product *= sliding_window[sliding_window_index];
            if (product > max_product)
            {
                max_product = product;
            }
        }
    }
    int ret = snprintf(buffer, buffer_size, "%lu", max_product);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
