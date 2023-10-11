cmake_minimum_required(VERSION 3.5)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(
    project_euler_c
    src/answers.c
    src/main.c
    src/run_solver.c
    src/solvers/s0001.c
    src/solvers/s0002.c
)
target_compile_features(project_euler_c PUBLIC c_std_17)
target_include_directories(project_euler_c PUBLIC include)
