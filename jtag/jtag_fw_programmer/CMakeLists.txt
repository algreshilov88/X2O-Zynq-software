cmake_minimum_required(VERSION 2.8)

project(jtag_fw_programmer)
set(CMAKE_C_COMPILER /usr/bin/g++)
set(CMAKE_BUILD_TYPE Debug)
set(SRCS "jtag_fw_programmer.cc" "semaphore.c")
set(HDRS "xvc_ioctl.h" "semaphore.h")
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
