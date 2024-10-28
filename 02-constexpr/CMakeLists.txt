cmake_minimum_required(VERSION 3.0)

get_filename_component(EXAMPLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(EXE_NAME example_${EXAMPLE_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRC_FILES
        "*.cpp"
        "*.h"
)

add_executable(${EXE_NAME} ${SRC_FILES})
