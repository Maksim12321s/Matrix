cmake_minimum_required(VERSION 3.14)

project(Matrix LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(matrix STATIC src/Matrix.cpp)
target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(matrixProject main.cpp)

target_link_libraries(matrixProject
    PRIVATE
    matrix
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(matrixTests tests/test.cpp)

target_link_libraries(matrixTests
    PRIVATE
    matrix
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(matrixTests)
