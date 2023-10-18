#pragma once

#include <stdbool.h>

// Function pointer type for solver functions.
//
// A solver function is a function that solves a specific project euler problem.
// The inputs are a string buffer and size. The function is meant to write the
// computed answer to the string buffer. The return value tells if the function
// succeeded or not.
typedef bool (*solve)(char *, size_t);

// Array of all solver pointers.
extern solve solvers[];

// Size of the solvers array.
extern size_t solvers_size;

// All function declarations for implemented solvers should go below.

bool solve0001(char *buffer, size_t buffer_size);
bool solve0002(char *buffer, size_t buffer_size);
bool solve0003(char *buffer, size_t buffer_size);
bool solve0004(char *buffer, size_t buffer_size);
bool solve0005(char *buffer, size_t buffer_size);
bool solve0006(char *buffer, size_t buffer_size);
bool solve0007(char *buffer, size_t buffer_size);
bool solve0008(char *buffer, size_t buffer_size);
bool solve0009(char *buffer, size_t buffer_size);
bool solve0010(char *buffer, size_t buffer_size);
bool solve0011(char *buffer, size_t buffer_size);
bool solve0012(char *buffer, size_t buffer_size);
bool solve0013(char *buffer, size_t buffer_size);
bool solve0014(char *buffer, size_t buffer_size);
bool solve0015(char *buffer, size_t buffer_size);
