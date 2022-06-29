cmake_minimum_required(VERSION 3.19)
project(hello-world
        LANGUAGES CXX
        VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        MESSAGE("-- Using Clang compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        MESSAGE("-- Using GCC compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
        MESSAGE("-- Using Intel compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        MESSAGE("-- Using MSVC compiler")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++17 -Wall -Werror -g")
set(CMAKE_CXX_FLAGS_SANITIZED "-std=c++17 -Wall -Werror -g -fsanitize=address,undefined,leak")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -Wall -Werror -g -O3")
mark_as_advanced(
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_SANITIZED
        CMAKE_CXX_FLAGS_RELEASE
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Code completion. Generates compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CCache
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

set (PROGRAM_NAME readit-books)

add_executable(${PROGRAM_NAME} src/main.cpp)
add_subdirectory(src)

# Testing
enable_testing()
add_subdirectory(test)