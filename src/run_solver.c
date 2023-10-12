#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "run_solver.h"
#include "solvers.h"

typedef bool (*solve)(char *, size_t);

solve solvers[] = {
    solve0001,
    solve0002,
    solve0003,
    solve0004,
    solve0005,
    solve0006,
};

size_t solvers_size = sizeof(solvers) / sizeof(solve);

solver_status run_solver(int n, char *buffer, size_t buffer_size, double *time_taken)
{
    n--;
    if (n >= solvers_size)
    {
        return solver_not_found;
    }
    clock_t before = clock();
    bool success = solvers[n](buffer, buffer_size);
    clock_t after = clock();
    *time_taken = (after - before) / CLOCKS_PER_SEC;
    return success ? solver_success : solver_failure;
}
