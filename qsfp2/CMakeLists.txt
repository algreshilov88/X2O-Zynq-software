cmake_minimum_required(VERSION 2.8)

	project(qsfp_monitor)
	set(CMAKE_C_COMPILER /usr/bin/gcc)
	set(CMAKE_BUILD_TYPE Debug)

	set(CMAKE_C_FLAGS "-lrt")
	set(CMAKE_CXX_FLAGS "-lrt")
	set(SRCS "qsfp_monitor.c" "toml.c" "i2c-chip.c" "semaphore.c")

	set(QSFP_MON "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(qsfp_monitor ${SRCS} ${QSFP_MON})
	set_target_properties(qsfp_monitor PROPERTIES COMPILE_FLAGS "-ggdb")

