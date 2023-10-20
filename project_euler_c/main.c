#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answers.h"
#include "run_solver.h"

#define computed_answer_buffer_size 50

// Program entry point.
//
// The program expects a single argument which represents the project euler
// problem to run the solution for. The program will run the solution for the
// given problem and compare the computed answer to the correct one.
int main(int argc, char **argv)
{
    char *usage = "usage: %s [problem number]\n";
    if (argc != 2)
    {
        printf("error: invalid number of arguments\n");
        printf(usage, argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("error: invalid problem number\n");
        printf(usage, argv[0]);
        return EXIT_FAILURE;
    }
    char computed_answer[computed_answer_buffer_size];
    double time_taken;
    solver_status status = run_solver(n - 1, computed_answer, computed_answer_buffer_size, &time_taken);
    if (status == solver_not_found)
    {
        printf("error: solver not found for problem %d\n", n);
        return EXIT_FAILURE;
    }
    if (status == solver_failure)
    {
        printf("error: solver failed for problem %d\n", n);
        return EXIT_FAILURE;
    }
    printf("problem %d\n", n);
    printf("time taken: %.3fs\n", time_taken);
    char *correct_answer = get_correct_answer(n - 1);
    printf("computed answer: %s\n", computed_answer);
    printf("correct answer:  %s\n", correct_answer);
    if (strcmp(computed_answer, correct_answer))
    {
        printf("❌ back to the drawing board");
    }
    else
    {
        printf("✅ you got it!");
    }
    return EXIT_SUCCESS;
}
