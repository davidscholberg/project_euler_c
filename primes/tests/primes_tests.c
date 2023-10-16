#undef NDEBUG
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "prime_factors.h"
#include "sieve_of_eratosthenes.h"

void prime_factors_test_case(int n, int *expected_factors, size_t expected_factor_count)
{
    uint_fast64_t prime_factors_buffer[expected_factor_count];
    int prime_factor_count;
    prime_factors(n, prime_factors_buffer, expected_factor_count, &prime_factor_count);
    assert(prime_factor_count == expected_factor_count);
    for (int i = 0; i < prime_factor_count; i++)
    {
        assert(expected_factors[i] == prime_factors_buffer[i]);
    }
}

void sieve_test_case(int n, int *expected_primes, size_t expected_prime_count)
{
    bool composites_buffer[n + 2];
    size_t composites_buffer_size = sizeof(composites_buffer) / sizeof(composites_buffer[0]);
    sieve_of_eratosthenes(composites_buffer, composites_buffer_size);
    int prime_count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!composites_buffer[i])
        {
            assert(expected_primes[prime_count] == i);
            prime_count++;
        }
    }
    assert(expected_prime_count == prime_count);
}

void test_prime_factors()
{
    prime_factors_test_case(1, (int[]){}, 0);
    prime_factors_test_case(2, (int[]){2}, 1);
    prime_factors_test_case(3, (int[]){3}, 1);
    prime_factors_test_case(7919, (int[]){7919}, 1);
    prime_factors_test_case(348349349, (int[]){15017, 23197}, 2);
    uint_fast64_t buffer[1];
    int factor_count;
    prime_factors(6, buffer, 1, &factor_count);
    assert(factor_count == -1);
}

void test_sieve_of_eratosthenes()
{
    sieve_test_case(10, (int[]){2, 3, 5, 7}, 4);
    sieve_test_case(11, (int[]){2, 3, 5, 7, 11}, 5);
    sieve_test_case(12, (int[]){2, 3, 5, 7, 11}, 5);
    sieve_test_case(71, (int[]){2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71}, 20);
}

int main(void)
{
    test_prime_factors();
    test_sieve_of_eratosthenes();
    return EXIT_SUCCESS;
}
