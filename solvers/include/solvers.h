#pragma once

#include <stdbool.h>

typedef bool (*solve)(char *, size_t);

extern solve solvers[];
extern size_t solvers_size;

bool solve0001(char *buffer, size_t buffer_size);
bool solve0002(char *buffer, size_t buffer_size);
bool solve0003(char *buffer, size_t buffer_size);
bool solve0004(char *buffer, size_t buffer_size);
bool solve0005(char *buffer, size_t buffer_size);
bool solve0006(char *buffer, size_t buffer_size);
bool solve0007(char *buffer, size_t buffer_size);
