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
