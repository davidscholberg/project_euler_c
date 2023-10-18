add_library(
    grids
    path_count.c
)
target_include_directories(
    grids
    PUBLIC
    include
)
target_compile_features(grids PUBLIC c_std_17)

add_executable(
    grids_tests
    tests/grids_tests.c
)
target_link_libraries(
    grids_tests
    PRIVATE
    grids
)
target_compile_features(grids_tests PUBLIC c_std_17)

add_test(
    NAME grids_tests
    COMMAND $<TARGET_FILE:grids_tests>
)
