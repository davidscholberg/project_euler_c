#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"
#include "path_count.h"

#define row_count_def 21
#define column_count_def 21

// Solution for Project Euler problem 15.
//
// Find the number of routes in a 21x21 grid from the top left corner to the
// bottom right corner if you can only move right or down.
//
// The approach taken here is to recursively traverse the grid and cache the
// known path counts along the way to prevent re-traversing paths.
bool solve0015(char *buffer, size_t buffer_size)
{
    int_fast64_t grid_array[row_count_def * column_count_def] = {0};
    grid grid = {
        .grid_array = grid_array,
        .row_count = row_count_def,
        .column_count = column_count_def,
    };
    move allowed_moves_array[] = {
        {
            .row_offset = 0,
            .column_offset = 1,
        },
        {
            .row_offset = 1,
            .column_offset = 0,
        },
    };
    moves allowed_moves = {
        .moves = allowed_moves_array,
        .move_count = sizeof(allowed_moves_array) / sizeof(allowed_moves_array[0]),
    };
    coordinates target = {
        .row = row_count_def - 1,
        .column = column_count_def - 1,
    };
    int_fast64_t result = path_count(&grid, &allowed_moves, &target, (coordinates){0, 0});
    int ret = snprintf(buffer, buffer_size, "%ld", result);
    return ret >= 0 && (unsigned int)ret < buffer_size;
}
