#include <stdint.h>

#include "grid.h"

int_fast64_t path_count(grid *count_cache, moves *allowed_moves, coordinates *target, coordinates current)
{
    if (coordinates_equal(current, (*target)))
    {
        return 1;
    }
    int_fast64_t cached_path_count = grid_access((*count_cache), current);
    if (cached_path_count != 0)
    {
        return cached_path_count;
    }
    int_fast64_t path_count_sum = 0;
    for (int i = 0; i < allowed_moves->move_count; i++)
    {
        coordinates next;
        next.row = current.row + allowed_moves->moves[i].row_offset;
        next.column = current.column + allowed_moves->moves[i].column_offset;
        if (out_of_bounds((*count_cache), next))
        {
            continue;
        }
        path_count_sum += path_count(count_cache, allowed_moves, target, next);
    }
    grid_access((*count_cache), current) = path_count_sum;
    return path_count_sum;
}
