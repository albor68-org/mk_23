# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stud134/projects/mk_23

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud134/projects/mk_23/buid

# Include any dependencies generated for this target.
include CMakeFiles/mk_23.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mk_23.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mk_23.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mk_23.dir/flags.make

CMakeFiles/mk_23.dir/src/main.cpp.obj: CMakeFiles/mk_23.dir/flags.make
CMakeFiles/mk_23.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/mk_23.dir/src/main.cpp.obj: CMakeFiles/mk_23.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stud134/projects/mk_23/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mk_23.dir/src/main.cpp.obj"
	/usr/bin/arm-none-eabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mk_23.dir/src/main.cpp.obj -MF CMakeFiles/mk_23.dir/src/main.cpp.obj.d -o CMakeFiles/mk_23.dir/src/main.cpp.obj -c /home/stud134/projects/mk_23/src/main.cpp

CMakeFiles/mk_23.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mk_23.dir/src/main.cpp.i"
	/usr/bin/arm-none-eabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stud134/projects/mk_23/src/main.cpp > CMakeFiles/mk_23.dir/src/main.cpp.i

CMakeFiles/mk_23.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mk_23.dir/src/main.cpp.s"
	/usr/bin/arm-none-eabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stud134/projects/mk_23/src/main.cpp -o CMakeFiles/mk_23.dir/src/main.cpp.s

# Object files for target mk_23
mk_23_OBJECTS = \
"CMakeFiles/mk_23.dir/src/main.cpp.obj"

# External object files for target mk_23
mk_23_EXTERNAL_OBJECTS =

mk_23: CMakeFiles/mk_23.dir/src/main.cpp.obj
mk_23: CMakeFiles/mk_23.dir/build.make
mk_23: _deps/libopencm3_repo-src/lib/libopencm3_stm32f3.a
mk_23: CMakeFiles/mk_23.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stud134/projects/mk_23/buid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mk_23"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mk_23.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mk_23.dir/build: mk_23
.PHONY : CMakeFiles/mk_23.dir/build

CMakeFiles/mk_23.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mk_23.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mk_23.dir/clean

CMakeFiles/mk_23.dir/depend:
	cd /home/stud134/projects/mk_23/buid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud134/projects/mk_23 /home/stud134/projects/mk_23 /home/stud134/projects/mk_23/buid /home/stud134/projects/mk_23/buid /home/stud134/projects/mk_23/buid/CMakeFiles/mk_23.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mk_23.dir/depend

