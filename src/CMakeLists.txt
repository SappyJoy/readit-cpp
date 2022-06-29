add_library(${PROGRAM_NAME}_lib Mine.cpp)
target_include_directories(${PROGRAM_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROGRAM_NAME} ${PROGRAM_NAME}_lib)