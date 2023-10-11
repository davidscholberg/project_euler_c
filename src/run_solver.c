#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "solvers.h"

typedef bool (*solve)(char *, size_t);

solve solvers[] = {
    solve0001,
    solve0002,
};

size_t solvers_size = sizeof(solvers) / sizeof(solve);

bool run_solver(int n, char *buffer, size_t buffer_size, double *time_taken)
{
    n--;
    if (n >= solvers_size)
    {
        return false;
    }
    clock_t before = clock();
    bool success = solvers[n](buffer, buffer_size);
    clock_t after = clock();
    *time_taken = (after - before) / CLOCKS_PER_SEC;
    return success;
}
