cmake_minimum_required(VERSION 2.8)

	project(clock_async_250M)
	project(clock_async_322M)
	set(CMAKE_C_COMPILER /usr/bin/gcc)
	set(CMAKE_BUILD_TYPE Debug)

	set(CMAKE_C_FLAGS "-lrt")
	set(CMAKE_CXX_FLAGS "-lrt")
	set(SRCS "clock_async.c" "toml.c" "i2c-chip.c" "semaphore.c")

	set(HDRS_250M "Si5332-GM1-RevD-Registers.h" "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(clock_async_250M ${SRCS} ${HDRS_250M})
	set_target_properties(clock_async_250M PROPERTIES COMPILE_FLAGS "-DF250")

	set(HDRS_322M "si5332-322.x-all-Registers.h" "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(clock_async_322M ${SRCS} ${HDRS_322M})
	set_target_properties(clock_async_322M PROPERTIES COMPILE_FLAGS "-DF322")
