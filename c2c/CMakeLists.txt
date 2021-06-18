cmake_minimum_required(VERSION 2.8)

	project(c2c_tests)
	set(CMAKE_C_COMPILER /usr/bin/g++)
	set(CMAKE_BUILD_TYPE Debug)
	set(CMAKE_C_FLAGS "-lrt")
	set(CMAKE_CXX_FLAGS "-lrt")
	set(SRCS_MEMCPY "c2c_memcpy.cpp")
	add_executable(c2c_memcpy ${SRCS_MEMCPY})
	set(SRCS_PTR "c2c_ptr.cpp")
	add_executable(c2c_ptr ${SRCS_PTR})

