#include <stdlib.h>

#include "solvers.h"

solve solvers[] = {
    solve0001,
    solve0002,
    solve0003,
    solve0004,
    solve0005,
    solve0006,
    solve0007,
};

size_t solvers_size = sizeof(solvers) / sizeof(solve);
