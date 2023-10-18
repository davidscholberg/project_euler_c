#undef NDEBUG
#include <assert.h>
#include <stdlib.h>

#include "grid.h"
#include "path_count.h"

#define row_count_def 3
#define column_count_def 3

void test_path_count()
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
    assert(path_count(&grid, &allowed_moves, &target, (coordinates){0, 0}) == 6);
}

int main(void)
{
    test_path_count();
    return EXIT_SUCCESS;
}
