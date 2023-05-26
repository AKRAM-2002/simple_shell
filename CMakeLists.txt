cmake_minimum_required(VERSION 3.0.0)
project(shell VERSION 0.1.0)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -pedantic")

file(GLOB SOURCES "*.c")

add_executable(shell ${SOURCES})
