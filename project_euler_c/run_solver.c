#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "run_solver.h"
#include "solvers.h"

solver_status run_solver(unsigned int n, char *buffer, size_t buffer_size, double *time_taken)
{
    if (n >= solvers_size)
    {
        return solver_not_found;
    }
    clock_t before = clock();
    bool success = solvers[n](buffer, buffer_size);
    clock_t after = clock();
    *time_taken = ((double)(after - before)) / CLOCKS_PER_SEC;
    return success ? solver_success : solver_failure;
}
