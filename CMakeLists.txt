cmake_minimum_required(VERSION 3.5)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(project_euler_c main.c)
target_compile_features(project_euler_c PUBLIC c_std_17)
