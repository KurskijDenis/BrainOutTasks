cmake_minimum_required(VERSION 3.16)

project(SortVectorOfListsLib VERSION 1.0)

add_library(SortVectorOfListsLib Headers/SortVectorOfLists/SortVectorOfLists.h Sources/SortVectorOfLists.cpp)
target_compile_features(SortVectorOfListsLib PRIVATE cxx_std_17)
target_compile_options(SortVectorOfListsLib PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_include_directories(SortVectorOfListsLib PUBLIC Headers)

add_executable(
  SortVectorOfListsTest
  Tests/Tests.cpp
)
target_link_libraries(SortVectorOfListsTest PRIVATE
  gtest_main
  SortVectorOfListsLib
)
include(GoogleTest)
gtest_discover_tests(SortVectorOfListsTest)
