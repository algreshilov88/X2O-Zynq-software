cmake_minimum_required(VERSION 2.8)

	project(clock_sync)
	set(CMAKE_C_COMPILER /usr/bin/gcc)
	set(CMAKE_BUILD_TYPE Debug)

	set(CMAKE_C_FLAGS "-lrt")
	set(CMAKE_CXX_FLAGS "-lrt")
	set(SRCS "clock_sync.c" "toml.c" "i2c-chip.c" "semaphore.c")

	set(HDRS_160_LHC "Si5345-160p3144_40p08_in_apexsync-Registers.h" "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(clock_sync_160M_LHC ${SRCS} ${HDRS_160_LHC})
	set_target_properties(clock_sync_160M_LHC PROPERTIES COMPILE_FLAGS "-DF160p3144_LHC")

	set(HDRS_160_NOREF "Si5345-160p3156_no_ref_apexsync-Registers.h" "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(clock_sync_160M_noref ${SRCS} ${HDRS_160_LHC})
	set_target_properties(clock_sync_160M_noref PROPERTIES COMPILE_FLAGS "-DF160p3156")

	set(HDRS_320_LHC "Si5345-320p6288_40p08_in_apexsync-Registers.h" "toml.h" "i2c-chip.h" "semaphore.h")
	add_executable(clock_sync_320M_LHC ${SRCS} ${HDRS_160_LHC})
	set_target_properties(clock_sync_320M_LHC PROPERTIES COMPILE_FLAGS "-DF320p6288_LHC")

