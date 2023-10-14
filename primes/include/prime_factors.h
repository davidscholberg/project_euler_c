#pragma once

#include <stdint.h>
#include <stdlib.h>

// Prime factorization algorithm based on the sieve of eratosthenes algorithm.
//
// The prime factors will be written to the given buffer and the number of
// factors will be written to factor_count. factor_count will be set to negative
// if the number of factors exceeds the provided buffer size.
void prime_factors(uint_fast64_t n, uint_fast64_t *buffer, size_t buffer_size, int *factor_count);
