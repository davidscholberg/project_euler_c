cmake_minimum_required(VERSION 3.0.0)
project(project_euler_c VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(project_euler_c main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
