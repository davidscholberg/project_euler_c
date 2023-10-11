#pragma once

#include <stdbool.h>

typedef enum solver_status
{
    solver_not_found,
    solver_success,
    solver_failure
} solver_status;

solver_status run_solver(int n, char *buffer, size_t buffer_size, double *time_taken);
