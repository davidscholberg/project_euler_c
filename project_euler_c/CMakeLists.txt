add_executable(
    project_euler_c
    answers.c
    main.c
    run_solver.c
)
target_include_directories(
    project_euler_c
    PUBLIC
    include
)
target_link_libraries(
    project_euler_c
    PRIVATE
    solvers
)
target_compile_features(project_euler_c PUBLIC c_std_17)
