# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/X2O-Zynq-software/c2c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/X2O-Zynq-software/c2c

# Include any dependencies generated for this target.
include CMakeFiles/c2c_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c2c_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c2c_ptr.dir/flags.make

CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o: CMakeFiles/c2c_ptr.dir/flags.make
CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o: c2c_ptr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/X2O-Zynq-software/c2c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o -c /root/X2O-Zynq-software/c2c/c2c_ptr.cpp

CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/X2O-Zynq-software/c2c/c2c_ptr.cpp > CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.i

CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/X2O-Zynq-software/c2c/c2c_ptr.cpp -o CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.s

# Object files for target c2c_ptr
c2c_ptr_OBJECTS = \
"CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o"

# External object files for target c2c_ptr
c2c_ptr_EXTERNAL_OBJECTS =

c2c_ptr: CMakeFiles/c2c_ptr.dir/c2c_ptr.cpp.o
c2c_ptr: CMakeFiles/c2c_ptr.dir/build.make
c2c_ptr: CMakeFiles/c2c_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/X2O-Zynq-software/c2c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable c2c_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c2c_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c2c_ptr.dir/build: c2c_ptr

.PHONY : CMakeFiles/c2c_ptr.dir/build

CMakeFiles/c2c_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c2c_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c2c_ptr.dir/clean

CMakeFiles/c2c_ptr.dir/depend:
	cd /root/X2O-Zynq-software/c2c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/X2O-Zynq-software/c2c /root/X2O-Zynq-software/c2c /root/X2O-Zynq-software/c2c /root/X2O-Zynq-software/c2c /root/X2O-Zynq-software/c2c/CMakeFiles/c2c_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c2c_ptr.dir/depend
