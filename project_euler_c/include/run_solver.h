#pragma once

#include <stdbool.h>

// Enum used to indicate the exit status of the run_solver function.
typedef enum solver_status
{
    solver_not_found,
    solver_success,
    solver_failure
} solver_status;

// Run the solver for the given project euler problem.
//
// n will be used as an index of the array of project euler solvers and
// therefore should be one less than the corresponding problem number. The
// passed-in string buffer will have the computed answer written to it, and the
// amount of time in seconds the solver takes will be written to time_taken.
solver_status run_solver(unsigned int n, char *buffer, size_t buffer_size, double *time_taken);
