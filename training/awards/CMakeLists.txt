# Unit library
add_library(awards
  source/awards.cpp
)
target_include_directories(awards PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Unit test
if(BUILD_TESTING)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
