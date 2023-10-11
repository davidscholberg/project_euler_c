#include <stdio.h>
#include <stdlib.h>

#include "run_solver.h"

#define answer_buffer_size 50

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
    char answer[answer_buffer_size];
    if (!run_solver(n, answer, answer_buffer_size))
    {
        return EXIT_FAILURE;
    }
    printf("answer: %s\n", answer);
    return EXIT_SUCCESS;
}
