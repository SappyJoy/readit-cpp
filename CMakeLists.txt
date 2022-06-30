cmake_minimum_required(VERSION 3.19)
project(readit
        LANGUAGES CXX
        VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

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


# Code completion. Generates compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#### Libraries ####

# Libary binaries (e.g. tests) will be in this directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/third_party/bin)

include(FetchContent)
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/third_party CACHE PATH "Missing description." FORCE)

# spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.x
)

FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

if(TARGET spdlog)
    message("-- spdlog defined!")
endif()

# libpqxx
FetchContent_Declare(
  libpqxx
  GIT_REPOSITORY https://github.com/jtv/libpqxx.git
  GIT_TAG 7.7.3
)

FetchContent_MakeAvailable(libpqxx)

if(TARGET spdlog)
    message("-- libpqxx defined!")
endif()

# gtest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
  CMAKE_CACHE_ARGS "${googletest_cmake_args}"
)
FetchContent_MakeAvailable(googletest)

# Function that provide simple adding Unit Tests
function(ADD_GTEST TEST_NAME)
  add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
  target_include_directories(${TEST_NAME} PUBLIC ${UNIT_UNDER_TEST_INCLUDE_DIR} )
  target_link_libraries(${TEST_NAME} gtest gtest_main gmock gmock_main ${LIBRARY_NAME})
  add_test(NAME ${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
endfunction()

# CCache
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_TEST_DIR ${CMAKE_BINARY_DIR}/test)

enable_testing()
add_subdirectory(src)
