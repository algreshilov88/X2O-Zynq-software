cmake_minimum_required(VERSION 2.8)

project(eom)
set(CMAKE_C_COMPILER /usr/bin/g++)
set(CMAKE_C_FLAGS "-lrt -lboost_regex -lboost_filesystem -lboost_system")
set(CMAKE_CXX_FLAGS "-lrt -lboost_regex -lboost_filesystem -lboost_system")
set(CMAKE_BUILD_TYPE Debug)
set(SRCS "eom.cc" "semaphore.c" "i2c-chip.c")
set(HDRS "semaphore.h" "i2c-chip.h")
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
