# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /Test/Test/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Test/Test/build

# Include any dependencies generated for this target.
include CMakeFiles/cars.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cars.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cars.dir/flags.make

CMakeFiles/cars.dir/main.cpp.o: CMakeFiles/cars.dir/flags.make
CMakeFiles/cars.dir/main.cpp.o: /Test/Test/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Test/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cars.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cars.dir/main.cpp.o -c /Test/Test/src/main.cpp

CMakeFiles/cars.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cars.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Test/Test/src/main.cpp > CMakeFiles/cars.dir/main.cpp.i

CMakeFiles/cars.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cars.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Test/Test/src/main.cpp -o CMakeFiles/cars.dir/main.cpp.s

CMakeFiles/cars.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/cars.dir/main.cpp.o.requires

CMakeFiles/cars.dir/main.cpp.o.provides: CMakeFiles/cars.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cars.dir/build.make CMakeFiles/cars.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/cars.dir/main.cpp.o.provides

CMakeFiles/cars.dir/main.cpp.o.provides.build: CMakeFiles/cars.dir/main.cpp.o


CMakeFiles/cars.dir/Vector.cpp.o: CMakeFiles/cars.dir/flags.make
CMakeFiles/cars.dir/Vector.cpp.o: /Test/Test/src/Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Test/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cars.dir/Vector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cars.dir/Vector.cpp.o -c /Test/Test/src/Vector.cpp

CMakeFiles/cars.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cars.dir/Vector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Test/Test/src/Vector.cpp > CMakeFiles/cars.dir/Vector.cpp.i

CMakeFiles/cars.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cars.dir/Vector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Test/Test/src/Vector.cpp -o CMakeFiles/cars.dir/Vector.cpp.s

CMakeFiles/cars.dir/Vector.cpp.o.requires:

.PHONY : CMakeFiles/cars.dir/Vector.cpp.o.requires

CMakeFiles/cars.dir/Vector.cpp.o.provides: CMakeFiles/cars.dir/Vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/cars.dir/build.make CMakeFiles/cars.dir/Vector.cpp.o.provides.build
.PHONY : CMakeFiles/cars.dir/Vector.cpp.o.provides

CMakeFiles/cars.dir/Vector.cpp.o.provides.build: CMakeFiles/cars.dir/Vector.cpp.o


# Object files for target cars
cars_OBJECTS = \
"CMakeFiles/cars.dir/main.cpp.o" \
"CMakeFiles/cars.dir/Vector.cpp.o"

# External object files for target cars
cars_EXTERNAL_OBJECTS =

cars: CMakeFiles/cars.dir/main.cpp.o
cars: CMakeFiles/cars.dir/Vector.cpp.o
cars: CMakeFiles/cars.dir/build.make
cars: CMakeFiles/cars.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Test/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cars"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cars.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cars.dir/build: cars

.PHONY : CMakeFiles/cars.dir/build

CMakeFiles/cars.dir/requires: CMakeFiles/cars.dir/main.cpp.o.requires
CMakeFiles/cars.dir/requires: CMakeFiles/cars.dir/Vector.cpp.o.requires

.PHONY : CMakeFiles/cars.dir/requires

CMakeFiles/cars.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cars.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cars.dir/clean

CMakeFiles/cars.dir/depend:
	cd /Test/Test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Test/Test/src /Test/Test/src /Test/Test/build /Test/Test/build /Test/Test/build/CMakeFiles/cars.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cars.dir/depend
