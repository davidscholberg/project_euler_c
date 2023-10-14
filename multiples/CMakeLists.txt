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
