# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MatchingParenthesis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MatchingParenthesis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MatchingParenthesis.dir/flags.make

CMakeFiles/MatchingParenthesis.dir/main.cpp.o: CMakeFiles/MatchingParenthesis.dir/flags.make
CMakeFiles/MatchingParenthesis.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MatchingParenthesis.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MatchingParenthesis.dir/main.cpp.o -c /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/main.cpp

CMakeFiles/MatchingParenthesis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatchingParenthesis.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/main.cpp > CMakeFiles/MatchingParenthesis.dir/main.cpp.i

CMakeFiles/MatchingParenthesis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatchingParenthesis.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/main.cpp -o CMakeFiles/MatchingParenthesis.dir/main.cpp.s

# Object files for target MatchingParenthesis
MatchingParenthesis_OBJECTS = \
"CMakeFiles/MatchingParenthesis.dir/main.cpp.o"

# External object files for target MatchingParenthesis
MatchingParenthesis_EXTERNAL_OBJECTS =

MatchingParenthesis: CMakeFiles/MatchingParenthesis.dir/main.cpp.o
MatchingParenthesis: CMakeFiles/MatchingParenthesis.dir/build.make
MatchingParenthesis: CMakeFiles/MatchingParenthesis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MatchingParenthesis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MatchingParenthesis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MatchingParenthesis.dir/build: MatchingParenthesis

.PHONY : CMakeFiles/MatchingParenthesis.dir/build

CMakeFiles/MatchingParenthesis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MatchingParenthesis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MatchingParenthesis.dir/clean

CMakeFiles/MatchingParenthesis.dir/depend:
	cd /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug /Users/anthonycortes/Documents/Class/AlgorithmDesign/MatchingParenthesis/cmake-build-debug/CMakeFiles/MatchingParenthesis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MatchingParenthesis.dir/depend

