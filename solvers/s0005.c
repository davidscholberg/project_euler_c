#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
