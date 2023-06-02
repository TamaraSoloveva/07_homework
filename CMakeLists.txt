cmake_minimum_required(VERSION 3.5)

project(07_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -g)
endif()

add_executable(07_homework main.cpp base_container.h list_container.cpp sequence_container.cpp)

enable_testing()

add_subdirectory(gtests)

