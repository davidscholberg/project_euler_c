#include <stdlib.h>

#include "solvers.h"

typedef char *(*solve)();

char *run_solver(int n)
{
    solve solvers[] = {
        solve0001,
    };
    size_t size = sizeof(solvers) / sizeof(solve);
    n--;
    if (n >= size)
    {
        return NULL;
    }
    return solvers[n]();
}
