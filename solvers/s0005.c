#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Solution for Project Euler problem 5.
//
// Find the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20.
//
// The approach taken here is to iterate through multiples of 20, and test the
// factors in reverse order (largest to smallest), because the larger factors
// should be more rare and thus we can break out of non-matches quicker. We also
// exclude factors 1-10 and 20 from testing. We exclude the numbers 1-10 because
// they are already factors of the numbers 11-20, so there's no need to test
// them separately. And we exclude 20 because we already know that the numbers
// we are testing are multiples of 20.
bool solve0005(char *buffer, size_t buffer_size)
{
    int factors_to_check[] = {19, 18, 17, 16, 15, 14, 13, 12, 11};
    size_t factors_to_check_count = sizeof(factors_to_check) / sizeof(factors_to_check[0]);
    int result = 20;
    while (1)
    {
        bool found = true;
        for (int i = 0; i < factors_to_check_count; i++)
        {
            if (result % factors_to_check[i] != 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            break;
        }
        result += 20;
    }
    int ret = snprintf(buffer, buffer_size, "%d", result);
    return ret >= 0 && ret < buffer_size;
}
