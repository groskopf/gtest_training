add_executable(triangle_test 
  triangle_test.cpp
#  triangle_test_solution.cpp
)

set_target_properties(triangle_test PROPERTIES COMPILE_FLAGS "-g3 -Os -Wall -fmessage-length=0 -ggdb -std=c++14" )

target_link_libraries(triangle_test triangle gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(triangle_test triangle_test)

