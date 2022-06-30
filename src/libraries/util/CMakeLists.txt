set (LIBRARY_NAME util)

# Add here cpp files you want to compile
add_library(${LIBRARY_NAME} src/Adder.cpp)
target_include_directories(${LIBRARY_NAME} PUBLIC headers)

set (UNIT_UNDER_TEST_INCLUDE_DIR, headers)
add_subdirectory(test)