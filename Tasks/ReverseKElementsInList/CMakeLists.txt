cmake_minimum_required(VERSION 3.16)

project(ReverseKElementsInListLib VERSION 1.0)

add_library(ReverseKElementsInListLib Headers/ReverseKElementsInList/ReverseKElementsInList.h Sources/ReverseKElementsInList.cpp)
target_compile_features(ReverseKElementsInListLib PRIVATE cxx_std_17)
target_compile_options(ReverseKElementsInListLib PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_include_directories(ReverseKElementsInListLib PUBLIC Headers)

add_executable(
  ReverseKElementsInListTest
  Tests/Tests.cpp
)
target_link_libraries(ReverseKElementsInListTest PRIVATE
  gtest_main
  ReverseKElementsInListLib
)
include(GoogleTest)
gtest_discover_tests(ReverseKElementsInListTest)
