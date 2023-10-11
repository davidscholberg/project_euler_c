#include <stdbool.h>
#include <stdlib.h>

#include "solvers.h"

typedef bool (*solve)(char *, size_t);

solve solvers[] = {
    solve0001,
    solve0002,
};

size_t solvers_size = sizeof(solvers) / sizeof(solve);

bool run_solver(int n, char *buffer, size_t buffer_size)
{
    n--;
    if (n >= solvers_size)
    {
        return false;
    }
    return solvers[n](buffer, buffer_size);
}
