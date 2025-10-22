cmake_minimum_required(VERSION 3.10)
project(StackQueueProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

file(GLOB SRCS "*.cpp")

foreach(SRC ${SRCS})
    get_filename_component(BIN_NAME ${SRC} NAME_WE)
    add_executable(${BIN_NAME} ${SRC})
endforeach()