# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/score4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/score4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/score4.dir/flags.make

CMakeFiles/score4.dir/score4.cpp.o: CMakeFiles/score4.dir/flags.make
CMakeFiles/score4.dir/score4.cpp.o: ../score4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/score4.dir/score4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/score4.dir/score4.cpp.o -c /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/score4.cpp

CMakeFiles/score4.dir/score4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/score4.dir/score4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/score4.cpp > CMakeFiles/score4.dir/score4.cpp.i

CMakeFiles/score4.dir/score4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/score4.dir/score4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/score4.cpp -o CMakeFiles/score4.dir/score4.cpp.s

# Object files for target score4
score4_OBJECTS = \
"CMakeFiles/score4.dir/score4.cpp.o"

# External object files for target score4
score4_EXTERNAL_OBJECTS =

score4: CMakeFiles/score4.dir/score4.cpp.o
score4: CMakeFiles/score4.dir/build.make
score4: CMakeFiles/score4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable score4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/score4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/score4.dir/build: score4

.PHONY : CMakeFiles/score4.dir/build

CMakeFiles/score4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/score4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/score4.dir/clean

CMakeFiles/score4.dir/depend:
	cd /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles/score4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/score4.dir/depend

