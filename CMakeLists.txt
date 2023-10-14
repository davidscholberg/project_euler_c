cmake_minimum_required(VERSION 3.5)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

enable_testing()

include_directories(include)

add_subdirectory(digits)
add_subdirectory(multiples)
add_subdirectory(primes)
add_subdirectory(project_euler_c)
add_subdirectory(solvers)
