# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw"

# Include any dependencies generated for this target.
include examples/CMakeFiles/particles.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/particles.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/particles.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/particles.dir/flags.make

examples/CMakeFiles/particles.dir/particles.c.o: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/particles.c.o: examples/particles.c
examples/CMakeFiles/particles.dir/particles.c.o: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/particles.dir/particles.c.o"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/particles.c.o -MF CMakeFiles/particles.dir/particles.c.o.d -o CMakeFiles/particles.dir/particles.c.o -c "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples/particles.c"

examples/CMakeFiles/particles.dir/particles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/particles.dir/particles.c.i"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples/particles.c" > CMakeFiles/particles.dir/particles.c.i

examples/CMakeFiles/particles.dir/particles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/particles.dir/particles.c.s"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples/particles.c" -o CMakeFiles/particles.dir/particles.c.s

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o: deps/tinycthread.c
examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o -MF CMakeFiles/particles.dir/__/deps/tinycthread.c.o.d -o CMakeFiles/particles.dir/__/deps/tinycthread.c.o -c "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/tinycthread.c"

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/tinycthread.c.i"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/tinycthread.c" > CMakeFiles/particles.dir/__/deps/tinycthread.c.i

examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/tinycthread.c.s"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/tinycthread.c" -o CMakeFiles/particles.dir/__/deps/tinycthread.c.s

examples/CMakeFiles/particles.dir/__/deps/getopt.c.o: examples/CMakeFiles/particles.dir/flags.make
examples/CMakeFiles/particles.dir/__/deps/getopt.c.o: deps/getopt.c
examples/CMakeFiles/particles.dir/__/deps/getopt.c.o: examples/CMakeFiles/particles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/CMakeFiles/particles.dir/__/deps/getopt.c.o"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/particles.dir/__/deps/getopt.c.o -MF CMakeFiles/particles.dir/__/deps/getopt.c.o.d -o CMakeFiles/particles.dir/__/deps/getopt.c.o -c "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/getopt.c"

examples/CMakeFiles/particles.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/getopt.c.i"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/getopt.c" > CMakeFiles/particles.dir/__/deps/getopt.c.i

examples/CMakeFiles/particles.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/getopt.c.s"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/deps/getopt.c" -o CMakeFiles/particles.dir/__/deps/getopt.c.s

# Object files for target particles
particles_OBJECTS = \
"CMakeFiles/particles.dir/particles.c.o" \
"CMakeFiles/particles.dir/__/deps/tinycthread.c.o" \
"CMakeFiles/particles.dir/__/deps/getopt.c.o"

# External object files for target particles
particles_EXTERNAL_OBJECTS =

examples/particles: examples/CMakeFiles/particles.dir/particles.c.o
examples/particles: examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o
examples/particles: examples/CMakeFiles/particles.dir/__/deps/getopt.c.o
examples/particles: examples/CMakeFiles/particles.dir/build.make
examples/particles: src/libglfw3.a
examples/particles: /usr/lib64/libm.so
examples/particles: /usr/lib64/librt.a
examples/particles: examples/CMakeFiles/particles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable particles"
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/particles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/particles.dir/build: examples/particles
.PHONY : examples/CMakeFiles/particles.dir/build

examples/CMakeFiles/particles.dir/clean:
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" && $(CMAKE_COMMAND) -P CMakeFiles/particles.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/particles.dir/clean

examples/CMakeFiles/particles.dir/depend:
	cd "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw" "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw" "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples" "/home/coldest/Documents/c++ stuff/openglProject/lib/glfw/examples/CMakeFiles/particles.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/particles.dir/depend

