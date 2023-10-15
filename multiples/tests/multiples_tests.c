#undef NDEBUG
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "factors.h"

// We use a variadic macro here so that we can pass in an initialization list as
// the third argument, which is meant to be the expected factors for the given
// test case.
#define factors_test_case(n, expected_factor_count, ...)                                   \
    do                                                                                     \
    {                                                                                      \
        factors(n, factors_buffer, factors_buffer_size, &factor_count);                    \
        assert(factor_count == expected_factor_count);                                     \
        qsort(factors_buffer, factor_count, sizeof(factors_buffer[0]), cmp_uint_fast64_t); \
        uint_fast64_t expected_factors[] = __VA_ARGS__;                                    \
        for (int i = 0; i < factor_count; i++)                                             \
        {                                                                                  \
            assert(expected_factors[i] == factors_buffer[i]);                              \
        }                                                                                  \
    } while (0)

#define factors_buffer_size 50

int cmp_uint_fast64_t(const void *elem1, const void *elem2)
{
    uint_fast64_t f = *((uint_fast64_t *)elem1);
    uint_fast64_t s = *((uint_fast64_t *)elem2);
    return (f > s) - (f < s);
}

void test_factors()
{
    uint_fast64_t factors_buffer[factors_buffer_size];
    int factor_count;
    factors_test_case(1, 1, {1});
    factors_test_case(2, 2, {1, 2});
    factors_test_case(3, 2, {1, 3});
    factors_test_case(4, 3, {1, 2, 4});
    factors_test_case(5, 2, {1, 5});
    factors_test_case(6, 4, {1, 2, 3, 6});
    factors_test_case(7, 2, {1, 7});
    factors_test_case(8, 4, {1, 2, 4, 8});
    factors_test_case(9, 3, {1, 3, 9});
    factors_test_case(10, 4, {1, 2, 5, 10});
    factors(2, factors_buffer, 1, &factor_count);
    assert(factor_count == -1);
}

int main(void)
{
    test_factors();
    return EXIT_SUCCESS;
}
