set (PROGRAM_NAME readit-server)
set (LIBRARY_NAME ${PROGRAM_NAME}_lib)

add_executable(${PROGRAM_NAME} src/main.cpp)


# Add here cpp files you want to compile
# add_library(${LIBRARY_NAME} src/Example.cpp)
# target_include_directories(${LIBRARY_NAME} PUBLIC headers)
# target_link_libraries(${PROGRAM_NAME} ${LIBRARY_NAME})

# Link executable with libraries
target_link_libraries(${PROGRAM_NAME}
                      spdlog::spdlog
                      pqxx
                      util
)

# Testing
add_subdirectory(test)