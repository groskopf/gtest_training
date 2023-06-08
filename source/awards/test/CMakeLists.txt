add_executable(awards_test 
  awards_test.cpp
  # awards_test_solution.cpp
)

set_target_properties(awards_test PROPERTIES COMPILE_FLAGS "-g3 -Os -Wall -ggdb" )

target_link_libraries(awards_test awards gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(awards_test awards_test)

