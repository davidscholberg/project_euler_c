#pragma once

#include <stdint.h>
#include <stdlib.h>

// Represents a 2D grid of integers.
//
// The internal grid_array pointer should point to a 1D array of size
// row_count * column_count. Accessing a value from the grid can be done by
// passing the grid and a coordinate object to the grid_access macro.
typedef struct grid
{
    int_fast64_t *grid_array;
    size_t row_count;
    size_t column_count;
} grid;

// Represents a location in a grid.
typedef struct coordinates
{
    int row;
    int column;
} coordinates;

#define coordinates_equal(c1, c2) (c1.row == c2.row && c1.column == c2.column)
#define out_of_bounds_up(c) c.row < 0
#define out_of_bounds_down(g, c) c.row >= g.row_count
#define out_of_bounds_left(c) c.column < 0
#define out_of_bounds_right(g, c) c.column >= g.column_count
#define out_of_bounds(g, c) (out_of_bounds_up(c) || out_of_bounds_down(g, c) || out_of_bounds_left(c) || out_of_bounds_right(g, c))
#define in_bounds(g, c) !out_of_bounds(g, c)
#define grid_access(g, c) g.grid_array[(c.row * g.column_count) + c.column]

// Represents an offset that can be applied to a coordinate to "move" it.
typedef struct move
{
    int row_offset;
    int column_offset;
} move;

// Structure that holds an array of moves and the size of the array.
typedef struct moves
{
    move *moves;
    int move_count;
} moves;
