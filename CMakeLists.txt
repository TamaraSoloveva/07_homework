cmake_minimum_required(VERSION 3.5)

project(07_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp base_container.h list_container.cpp sequence_container.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(07_homework PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(07_homework PRIVATE /EHsc /W4 /WX)

 endif()


enable_testing()

add_subdirectory(gtests)

