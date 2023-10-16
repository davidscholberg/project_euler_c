add_library(
    primes
    prime_factors.c
    sieve_of_eratosthenes.c
)
target_include_directories(
    primes
    PUBLIC
    include
)
target_compile_features(primes PUBLIC c_std_17)

add_executable(
    primes_tests
    tests/primes_tests.c
)
target_link_libraries(
    primes_tests
    PRIVATE
    primes
)
target_compile_features(primes_tests PUBLIC c_std_17)

add_test(
    NAME primes_tests
    COMMAND $<TARGET_FILE:primes_tests>
)
