#include <stdlib.h>

#include "solutions.h"

typedef char *(*solve)();

char *get_answer(int n)
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
