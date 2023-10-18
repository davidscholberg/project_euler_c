#pragma once

#include <stdint.h>

#include "grid.h"

// Finds the number of possible paths in the given grid from current to target
// using the given allowed moves.
//
// The values in the grid array inside count_cache must be initially zeroed out.
int_fast64_t path_count(grid *count_cache, moves *allowed_moves, coordinates *target, coordinates current);
