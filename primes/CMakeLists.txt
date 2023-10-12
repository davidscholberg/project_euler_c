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
