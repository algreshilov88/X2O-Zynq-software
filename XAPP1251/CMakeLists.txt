cmake_minimum_required(VERSION 2.8)

project(xvcserver_uio)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_BUILD_TYPE Debug)
set(SRCS "xvcserver_uio.c")
add_executable(${PROJECT_NAME} ${SRCS})
