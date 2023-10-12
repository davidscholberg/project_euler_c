#pragma once

#include <stdint.h>
#include <stdlib.h>

void prime_factors(uint_fast64_t n, uint_fast64_t *buffer, size_t buffer_size, int *factor_count);
