# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake-3.17.0-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.17.0-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = S:\algorithm\ShortestPath

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = S:\algorithm\ShortestPath\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ShortestPath.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ShortestPath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShortestPath.dir/flags.make

CMakeFiles/ShortestPath.dir/main.cpp.obj: CMakeFiles/ShortestPath.dir/flags.make
CMakeFiles/ShortestPath.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=S:\algorithm\ShortestPath\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ShortestPath.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ShortestPath.dir\main.cpp.obj -c S:\algorithm\ShortestPath\main.cpp

CMakeFiles/ShortestPath.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShortestPath.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E S:\algorithm\ShortestPath\main.cpp > CMakeFiles\ShortestPath.dir\main.cpp.i

CMakeFiles/ShortestPath.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShortestPath.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S S:\algorithm\ShortestPath\main.cpp -o CMakeFiles\ShortestPath.dir\main.cpp.s

# Object files for target ShortestPath
ShortestPath_OBJECTS = \
"CMakeFiles/ShortestPath.dir/main.cpp.obj"

# External object files for target ShortestPath
ShortestPath_EXTERNAL_OBJECTS =

ShortestPath.exe: CMakeFiles/ShortestPath.dir/main.cpp.obj
ShortestPath.exe: CMakeFiles/ShortestPath.dir/build.make
ShortestPath.exe: CMakeFiles/ShortestPath.dir/linklibs.rsp
ShortestPath.exe: CMakeFiles/ShortestPath.dir/objects1.rsp
ShortestPath.exe: CMakeFiles/ShortestPath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=S:\algorithm\ShortestPath\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ShortestPath.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ShortestPath.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShortestPath.dir/build: ShortestPath.exe

.PHONY : CMakeFiles/ShortestPath.dir/build

CMakeFiles/ShortestPath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ShortestPath.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ShortestPath.dir/clean

CMakeFiles/ShortestPath.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" S:\algorithm\ShortestPath S:\algorithm\ShortestPath S:\algorithm\ShortestPath\cmake-build-debug S:\algorithm\ShortestPath\cmake-build-debug S:\algorithm\ShortestPath\cmake-build-debug\CMakeFiles\ShortestPath.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ShortestPath.dir/depend

