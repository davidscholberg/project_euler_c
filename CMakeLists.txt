cmake_minimum_required(VERSION 3.5)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_library(
    primes
    src/util/primes/prime_factors.c
    src/util/primes/sieve_of_eratosthenes.c
)
target_include_directories(
    primes
    PUBLIC
    include/util/primes
)
target_compile_features(primes PUBLIC c_std_17)

add_library(
    digits
    src/util/digits/palindromes.c
)
target_include_directories(
    digits
    PUBLIC
    include
    include/util/digits
)
target_compile_features(digits PUBLIC c_std_17)

add_executable(
    project_euler_c
    src/answers.c
    src/main.c
    src/run_solver.c
    src/solvers/s0001.c
    src/solvers/s0002.c
    src/solvers/s0003.c
    src/solvers/s0004.c
    src/solvers/s0005.c
    src/solvers/s0006.c
    src/solvers/s0007.c
)
target_include_directories(
    project_euler_c
    PUBLIC
    include
)
target_link_libraries(project_euler_c PRIVATE primes digits)
target_compile_features(project_euler_c PUBLIC c_std_17)
