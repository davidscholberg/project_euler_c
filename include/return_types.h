#pragma once

// Enum meant to be used by functions that want to return either a bool or
// an error condition.
typedef enum bool_or_error
{
    bool_true,
    bool_false,
    error_condition
} bool_or_error;
