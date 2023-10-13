#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define target_sum 1000

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
format_result:
    int ret = snprintf(buffer, buffer_size, "%d", product);
    return ret >= 0 && ret < buffer_size;
}
