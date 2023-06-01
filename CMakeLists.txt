cmake_minimum_required(VERSION 3.22)

project(gtest_training LANGUAGES CXX C)

set(BUILD_TESTING ON)

enable_testing()

include(cmake/googletest.cmake)
add_subdirectory(training)