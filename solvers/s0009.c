#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define target_sum 1000

// Solution for Project Euler problem 9.
//
// Find the only Pythagorean triplet for which a + b + c = 1000 and return
// a * b * c.
//
// The approach taken here is to use a set of two nested for loops to iterate
// through all possible triple-addend combinations that sum to 1000 and that
// have the property a < b < c. I am not actually sure if this algorithm
// produces all such triple addends, but it at least produces enough of them to
// find the solution.
bool solve0009(char *buffer, size_t buffer_size)
{
    int product = 1;
    for (int a = 1; a < target_sum / 3; a++)
    {
        for (int b = a + 1; b < target_sum / 2; b++)
        {
            int c = target_sum - a - b;
            if (c < a || c < b)
            {
                break;
            }
            if ((a * a) + (b * b) == c * c)
            {
                product = a * b * c;
                goto format_result;
            }
        }
    }
format_result:;
    int ret = snprintf(buffer, buffer_size, "%d", product);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
