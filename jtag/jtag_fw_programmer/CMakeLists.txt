cmake_minimum_required(VERSION 2.8)

project(jtag_fw_programmer)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_BUILD_TYPE Debug)
set(SRCS "jtag_fw_programmer.cc")
set(HDRS "xvc_ioctl.h")
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
