#include <stdio.h>
#include <stdlib.h>

#include "solutions.h"

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
    char *answer = get_answer(n);
    if (answer == NULL)
    {
        return EXIT_FAILURE;
    }
    printf("answer: %s\n", answer);
    return EXIT_SUCCESS;
}
