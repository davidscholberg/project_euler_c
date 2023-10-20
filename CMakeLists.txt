cmake_minimum_required(VERSION 3.24)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

# TODO: the below options currently assume gcc or clang
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

enable_testing()

include_directories(include)

add_subdirectory(digits)
add_subdirectory(external)
add_subdirectory(grids)
add_subdirectory(multiples)
add_subdirectory(primes)
add_subdirectory(project_euler_c)
add_subdirectory(solvers)
