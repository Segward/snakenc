cmake_minimum_required(VERSION 3.10)
project(snakenc CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(snakenc src/snakenc.cpp)

target_link_libraries(snakenc ${CURSES_LIBRARIES})
