# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Costa/Technopark/AaSD/Seminar_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Seminar_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Seminar_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Seminar_5.dir/flags.make

CMakeFiles/Seminar_5.dir/main.cpp.o: CMakeFiles/Seminar_5.dir/flags.make
CMakeFiles/Seminar_5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Seminar_5.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Seminar_5.dir/main.cpp.o -c /Users/Costa/Technopark/AaSD/Seminar_5/main.cpp

CMakeFiles/Seminar_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Seminar_5.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Costa/Technopark/AaSD/Seminar_5/main.cpp > CMakeFiles/Seminar_5.dir/main.cpp.i

CMakeFiles/Seminar_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Seminar_5.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Costa/Technopark/AaSD/Seminar_5/main.cpp -o CMakeFiles/Seminar_5.dir/main.cpp.s

# Object files for target Seminar_5
Seminar_5_OBJECTS = \
"CMakeFiles/Seminar_5.dir/main.cpp.o"

# External object files for target Seminar_5
Seminar_5_EXTERNAL_OBJECTS =

Seminar_5: CMakeFiles/Seminar_5.dir/main.cpp.o
Seminar_5: CMakeFiles/Seminar_5.dir/build.make
Seminar_5: CMakeFiles/Seminar_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Seminar_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Seminar_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Seminar_5.dir/build: Seminar_5

.PHONY : CMakeFiles/Seminar_5.dir/build

CMakeFiles/Seminar_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Seminar_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Seminar_5.dir/clean

CMakeFiles/Seminar_5.dir/depend:
	cd /Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Costa/Technopark/AaSD/Seminar_5 /Users/Costa/Technopark/AaSD/Seminar_5 /Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug /Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug /Users/Costa/Technopark/AaSD/Seminar_5/cmake-build-debug/CMakeFiles/Seminar_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Seminar_5.dir/depend
