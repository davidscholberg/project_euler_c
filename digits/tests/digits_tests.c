#undef NDEBUG
#include <assert.h>
#include <stdlib.h>

#include "palindromes.h"

#define palindrome_buffer_size 50

void test_palindromes();

int main(void)
{
    test_palindromes();
    return EXIT_SUCCESS;
}

void test_palindromes()
{
    char buffer[palindrome_buffer_size];
    assert(is_palindromic_number(0, buffer, palindrome_buffer_size) == bool_true);
    assert(is_palindromic_number(1, buffer, palindrome_buffer_size) == bool_true);
    assert(is_palindromic_number(22, buffer, palindrome_buffer_size) == bool_true);
    assert(is_palindromic_number(343, buffer, palindrome_buffer_size) == bool_true);
    assert(is_palindromic_number(567765, buffer, palindrome_buffer_size) == bool_true);
    assert(is_palindromic_number(10, buffer, palindrome_buffer_size) == bool_false);
    assert(is_palindromic_number(233, buffer, palindrome_buffer_size) == bool_false);
    assert(is_palindromic_number(4445, buffer, palindrome_buffer_size) == bool_false);
    assert(is_palindromic_number(567765, buffer, 5) == error_condition);
}
