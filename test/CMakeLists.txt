set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

include(CMakeLists.gtest.txt)

add_gtest(MineTest)