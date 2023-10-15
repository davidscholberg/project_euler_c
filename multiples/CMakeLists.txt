add_library(
    multiples
    factors.c
)
target_include_directories(
    multiples
    PUBLIC
    include
)
target_link_libraries(
    multiples
    PRIVATE
    m
)
target_compile_features(multiples PUBLIC c_std_17)

add_executable(
    multiples_tests
    tests/multiples_tests.c
)
target_link_libraries(
    multiples_tests
    PRIVATE
    multiples
)
target_compile_features(multiples_tests PUBLIC c_std_17)

add_test(
    NAME multiples_tests
    COMMAND $<TARGET_FILE:multiples_tests>
)
