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
include CMakeFiles/wordCount.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wordCount.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wordCount.dir/flags.make

CMakeFiles/wordCount.dir/wordCount.cpp.o: CMakeFiles/wordCount.dir/flags.make
CMakeFiles/wordCount.dir/wordCount.cpp.o: ../wordCount.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wordCount.dir/wordCount.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wordCount.dir/wordCount.cpp.o -c /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/wordCount.cpp

CMakeFiles/wordCount.dir/wordCount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wordCount.dir/wordCount.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/wordCount.cpp > CMakeFiles/wordCount.dir/wordCount.cpp.i

CMakeFiles/wordCount.dir/wordCount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wordCount.dir/wordCount.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/wordCount.cpp -o CMakeFiles/wordCount.dir/wordCount.cpp.s

# Object files for target wordCount
wordCount_OBJECTS = \
"CMakeFiles/wordCount.dir/wordCount.cpp.o"

# External object files for target wordCount
wordCount_EXTERNAL_OBJECTS =

wordCount: CMakeFiles/wordCount.dir/wordCount.cpp.o
wordCount: CMakeFiles/wordCount.dir/build.make
wordCount: CMakeFiles/wordCount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wordCount"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wordCount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wordCount.dir/build: wordCount

.PHONY : CMakeFiles/wordCount.dir/build

CMakeFiles/wordCount.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wordCount.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wordCount.dir/clean

CMakeFiles/wordCount.dir/depend:
	cd /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug /mnt/c/Users/user/Desktop/Github/LearningtheCpp/class/accelerated/cmake-build-debug/CMakeFiles/wordCount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wordCount.dir/depend

