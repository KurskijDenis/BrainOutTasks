cmake_minimum_required(VERSION 3.16)

project(MedianTwoSortedArraysLib VERSION 1.0)

add_library(MedianTwoSortedArraysLib Headers/MedianTwoSortedArrays/MedianTwoSortedArrays.h Sources/MedianTwoSortedArrays.cpp)
target_compile_features(MedianTwoSortedArraysLib PRIVATE cxx_std_17)
target_compile_options(MedianTwoSortedArraysLib PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_include_directories(MedianTwoSortedArraysLib PUBLIC Headers)

add_executable(
  MedianTwoSortedArraysTest
  Tests/Test.cpp
)
target_link_libraries(MedianTwoSortedArraysTest PRIVATE
  gtest_main
  MedianTwoSortedArraysLib
)
include(GoogleTest)
gtest_discover_tests(MedianTwoSortedArraysTest)
