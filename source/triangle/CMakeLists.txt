# Unit library
add_library(triangle
  source/triangle.cpp
)
target_include_directories(triangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Unit test
if(BUILD_TESTING)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
