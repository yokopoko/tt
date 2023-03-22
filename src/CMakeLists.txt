
# Add square_solver executable
add_executable(square_solver square_solver.cpp)
find_package(Threads)
target_link_libraries(square_solver Threads::Threads)
