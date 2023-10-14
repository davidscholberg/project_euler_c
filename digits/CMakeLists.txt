add_library(
    digits
    palindromes.c
)
target_include_directories(
    digits
    PUBLIC
    include
)
target_compile_features(digits PUBLIC c_std_17)

add_executable(
    digits_tests
    tests/digits_tests.c
)
target_link_libraries(
    digits_tests
    PRIVATE
    digits
)
target_compile_features(digits_tests PUBLIC c_std_17)

add_test(
    NAME digits_tests
    COMMAND $<TARGET_FILE:digits_tests>
)
