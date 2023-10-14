#pragma once

#include <stdlib.h>

#include "return_types.h"

// Tells whether the given number is palindromic or not.
//
// Returns bool_or_error.error_condition if there was an error writing to the
// given string buffer.
bool_or_error is_palindromic_number(int n, char *buffer, size_t buffer_size);
