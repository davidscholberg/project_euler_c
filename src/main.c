#include <stdio.h>
#include <stdlib.h>

#include "run_solver.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (n == 0)
    {
        return EXIT_FAILURE;
    }
    // TODO: free answer once it changes to being malloced
    char *answer = run_solver(n);
    if (answer == NULL)
    {
        return EXIT_FAILURE;
    }
    printf("answer: %s\n", answer);
    return EXIT_SUCCESS;
}
