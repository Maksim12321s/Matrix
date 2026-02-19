cmake_minimum_required(VERSION 3.14)

project(Matrix LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(matrix STATIC src/Matrix.cpp)


add_executable(matrixProject main.cpp)

target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(matrixProject
    PRIVATE
    matrix
)
