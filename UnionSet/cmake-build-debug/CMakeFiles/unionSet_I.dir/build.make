# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\IDESoftware\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\IDESoftware\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = S:\algorithm\unionSet\unionSet_I

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = S:\algorithm\unionSet\unionSet_I\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unionSet_I.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unionSet_I.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unionSet_I.dir/flags.make

CMakeFiles/unionSet_I.dir/main.cpp.obj: CMakeFiles/unionSet_I.dir/flags.make
CMakeFiles/unionSet_I.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=S:\algorithm\unionSet\unionSet_I\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unionSet_I.dir/main.cpp.obj"
	G:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\unionSet_I.dir\main.cpp.obj -c S:\algorithm\unionSet\unionSet_I\main.cpp

CMakeFiles/unionSet_I.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unionSet_I.dir/main.cpp.i"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E S:\algorithm\unionSet\unionSet_I\main.cpp > CMakeFiles\unionSet_I.dir\main.cpp.i

CMakeFiles/unionSet_I.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unionSet_I.dir/main.cpp.s"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S S:\algorithm\unionSet\unionSet_I\main.cpp -o CMakeFiles\unionSet_I.dir\main.cpp.s

# Object files for target unionSet_I
unionSet_I_OBJECTS = \
"CMakeFiles/unionSet_I.dir/main.cpp.obj"

# External object files for target unionSet_I
unionSet_I_EXTERNAL_OBJECTS =

unionSet_I.exe: CMakeFiles/unionSet_I.dir/main.cpp.obj
unionSet_I.exe: CMakeFiles/unionSet_I.dir/build.make
unionSet_I.exe: CMakeFiles/unionSet_I.dir/linklibs.rsp
unionSet_I.exe: CMakeFiles/unionSet_I.dir/objects1.rsp
unionSet_I.exe: CMakeFiles/unionSet_I.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=S:\algorithm\unionSet\unionSet_I\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unionSet_I.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\unionSet_I.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unionSet_I.dir/build: unionSet_I.exe

.PHONY : CMakeFiles/unionSet_I.dir/build

CMakeFiles/unionSet_I.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\unionSet_I.dir\cmake_clean.cmake
.PHONY : CMakeFiles/unionSet_I.dir/clean

CMakeFiles/unionSet_I.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" S:\algorithm\unionSet\unionSet_I S:\algorithm\unionSet\unionSet_I S:\algorithm\unionSet\unionSet_I\cmake-build-debug S:\algorithm\unionSet\unionSet_I\cmake-build-debug S:\algorithm\unionSet\unionSet_I\cmake-build-debug\CMakeFiles\unionSet_I.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unionSet_I.dir/depend
