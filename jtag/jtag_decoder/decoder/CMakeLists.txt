cmake_minimum_required(VERSION 2.8)

project(jtag_decoder)
set(CMAKE_C_COMPILER /usr/bin/g++)
set(CMAKE_C_FLAGS "-D_FILE_OFFSET_BITS=64")
set(CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64")
set(CMAKE_BUILD_TYPE Debug)
set(SRCS "jtag_decoder.cc")
add_executable(${PROJECT_NAME} ${SRCS})
