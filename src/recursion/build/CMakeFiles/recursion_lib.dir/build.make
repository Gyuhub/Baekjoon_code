# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/gyubuntu/Documents/Baekjoon/src/recursion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gyubuntu/Documents/Baekjoon/src/recursion/build

# Include any dependencies generated for this target.
include CMakeFiles/recursion_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recursion_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recursion_lib.dir/flags.make

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o: CMakeFiles/recursion_lib.dir/flags.make
CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o: ../src/traversalOfTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gyubuntu/Documents/Baekjoon/src/recursion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o -c /home/gyubuntu/Documents/Baekjoon/src/recursion/src/traversalOfTree.cpp

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gyubuntu/Documents/Baekjoon/src/recursion/src/traversalOfTree.cpp > CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.i

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gyubuntu/Documents/Baekjoon/src/recursion/src/traversalOfTree.cpp -o CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.s

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.requires:

.PHONY : CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.requires

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.provides: CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/recursion_lib.dir/build.make CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.provides.build
.PHONY : CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.provides

CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.provides.build: CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o


# Object files for target recursion_lib
recursion_lib_OBJECTS = \
"CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o"

# External object files for target recursion_lib
recursion_lib_EXTERNAL_OBJECTS =

bin/lib/librecursion_lib.a: CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o
bin/lib/librecursion_lib.a: CMakeFiles/recursion_lib.dir/build.make
bin/lib/librecursion_lib.a: CMakeFiles/recursion_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gyubuntu/Documents/Baekjoon/src/recursion/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library bin/lib/librecursion_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/recursion_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recursion_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recursion_lib.dir/build: bin/lib/librecursion_lib.a

.PHONY : CMakeFiles/recursion_lib.dir/build

CMakeFiles/recursion_lib.dir/requires: CMakeFiles/recursion_lib.dir/src/traversalOfTree.cpp.o.requires

.PHONY : CMakeFiles/recursion_lib.dir/requires

CMakeFiles/recursion_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recursion_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recursion_lib.dir/clean

CMakeFiles/recursion_lib.dir/depend:
	cd /home/gyubuntu/Documents/Baekjoon/src/recursion/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gyubuntu/Documents/Baekjoon/src/recursion /home/gyubuntu/Documents/Baekjoon/src/recursion /home/gyubuntu/Documents/Baekjoon/src/recursion/build /home/gyubuntu/Documents/Baekjoon/src/recursion/build /home/gyubuntu/Documents/Baekjoon/src/recursion/build/CMakeFiles/recursion_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recursion_lib.dir/depend
