#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answers.h"
#include "run_solver.h"

#define computed_answer_buffer_size 50

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
    char computed_answer[computed_answer_buffer_size];
    if (!run_solver(n, computed_answer, computed_answer_buffer_size))
    {
        return EXIT_FAILURE;
    }
    char *actual_answer = get_actual_answer(n);
    printf("computed answer: %s\n", computed_answer);
    printf("actual answer:   %s\n", actual_answer);
    if (strcmp(computed_answer, actual_answer))
    {
        printf("❌ back to the drawing board");
    }
    else
    {
        printf("✅ you got it!");
    }
    return EXIT_SUCCESS;
}
