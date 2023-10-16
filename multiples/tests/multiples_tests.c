#undef NDEBUG
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "factors.h"

int cmp_uint_fast64_t(const void *elem1, const void *elem2)
{
    uint_fast64_t f = *((uint_fast64_t *)elem1);
    uint_fast64_t s = *((uint_fast64_t *)elem2);
    return (f > s) - (f < s);
}

void factors_test_case(int n, int *expected_factors, size_t expected_factor_count)
{
    uint_fast64_t factors_buffer[expected_factor_count];
    int factor_count;
    factors(n, factors_buffer, expected_factor_count, &factor_count);
    assert(factor_count == expected_factor_count);
    qsort(factors_buffer, factor_count, sizeof(factors_buffer[0]), cmp_uint_fast64_t);
    for (int i = 0; i < factor_count; i++)
    {
        assert(expected_factors[i] == factors_buffer[i]);
    }
}

void test_factors()
{

    factors_test_case(1, (int[]){1}, 1);
    factors_test_case(2, (int[]){1, 2}, 2);
    factors_test_case(3, (int[]){1, 3}, 2);
    factors_test_case(4, (int[]){1, 2, 4}, 3);
    factors_test_case(5, (int[]){1, 5}, 2);
    factors_test_case(6, (int[]){1, 2, 3, 6}, 4);
    factors_test_case(7, (int[]){1, 7}, 2);
    factors_test_case(8, (int[]){1, 2, 4, 8}, 4);
    factors_test_case(9, (int[]){1, 3, 9}, 3);
    factors_test_case(10, (int[]){1, 2, 5, 10}, 4);
    uint_fast64_t factors_buffer[1];
    int factor_count;
    factors(2, factors_buffer, 1, &factor_count);
    assert(factor_count == -1);
}

int main(void)
{
    test_factors();
    return EXIT_SUCCESS;
}
