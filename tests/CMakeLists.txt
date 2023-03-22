enable_testing()

find_package(GTest)
include(GoogleTest)

function(add_gtest TARGET SOURCE)
    add_executable(${TARGET} ${SOURCE})
    target_link_libraries(${TARGET} GTest::gtest_main)
    target_include_directories(${TARGET} PRIVATE "../src/")
    gtest_discover_tests(${TARGET})
endfunction(add_gtest)


# Add test targets
add_gtest(
    producer_consumer_pattern_test
    producer_consumer_pattern_test.cpp
)

add_gtest(
    quadratic_equation_test
    quadratic_equation_test.cpp
)

