#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Implementation of the sieve of eratosthenes algorithm for enumerating prime
// numbers up to a given maximum.
//
// Composites buffer is a boolean buffer whose values will indicate whether or
// not the corresponding index number is composite. The size of the composites
// buffer should be the maximum desired number + 2. Note that currently the
// final value in the composites buffer is not guaranteed to be accurate.
void sieve_of_eratosthenes(bool *composites_buffer, size_t composites_buffer_size);
