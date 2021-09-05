cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

project(BrainOutTasks VERSION 1.0)

enable_testing()

add_subdirectory(Tasks/MedianTwoSortedArrays)

add_executable(BrainOutTasks main.cpp)
target_compile_features(BrainOutTasks PRIVATE cxx_std_17)
target_compile_options(BrainOutTasks PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_link_libraries(BrainOutTasks PRIVATE
  MedianTwoSortedArraysLib
)
