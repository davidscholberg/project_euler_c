#include <stdbool.h>
#include <stdlib.h>

#include "solvers.h"

typedef bool (*solve)(char *, size_t);

bool run_solver(int n, char *buffer, size_t buffer_size)
{
    solve solvers[] = {
        solve0001,
        solve0002,
    };
    size_t size = sizeof(solvers) / sizeof(solve);
    n--;
    if (n >= size)
    {
        return false;
    }
    return solvers[n](buffer, buffer_size);
}
