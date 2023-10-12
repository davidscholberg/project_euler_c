#pragma once

#include <stdbool.h>
#include <stdlib.h>

// composites_buffer_size should be the maximum desired number + 2
void sieve_of_eratosthenes(bool *composites_buffer, size_t composites_buffer_size);
