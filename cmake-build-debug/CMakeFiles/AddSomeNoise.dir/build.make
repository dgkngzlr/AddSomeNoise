# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\CLion-Workspace\AddSomeNoise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AddSomeNoise.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AddSomeNoise.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AddSomeNoise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AddSomeNoise.dir/flags.make

CMakeFiles/AddSomeNoise.dir/main.cpp.obj: CMakeFiles/AddSomeNoise.dir/flags.make
CMakeFiles/AddSomeNoise.dir/main.cpp.obj: CMakeFiles/AddSomeNoise.dir/includes_CXX.rsp
CMakeFiles/AddSomeNoise.dir/main.cpp.obj: C:/dev/CLion-Workspace/AddSomeNoise/main.cpp
CMakeFiles/AddSomeNoise.dir/main.cpp.obj: CMakeFiles/AddSomeNoise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AddSomeNoise.dir/main.cpp.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AddSomeNoise.dir/main.cpp.obj -MF CMakeFiles\AddSomeNoise.dir\main.cpp.obj.d -o CMakeFiles\AddSomeNoise.dir\main.cpp.obj -c C:\dev\CLion-Workspace\AddSomeNoise\main.cpp

CMakeFiles/AddSomeNoise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AddSomeNoise.dir/main.cpp.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\CLion-Workspace\AddSomeNoise\main.cpp > CMakeFiles\AddSomeNoise.dir\main.cpp.i

CMakeFiles/AddSomeNoise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AddSomeNoise.dir/main.cpp.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\dev\CLion-Workspace\AddSomeNoise\main.cpp -o CMakeFiles\AddSomeNoise.dir\main.cpp.s

CMakeFiles/AddSomeNoise.dir/noise.cpp.obj: CMakeFiles/AddSomeNoise.dir/flags.make
CMakeFiles/AddSomeNoise.dir/noise.cpp.obj: CMakeFiles/AddSomeNoise.dir/includes_CXX.rsp
CMakeFiles/AddSomeNoise.dir/noise.cpp.obj: C:/dev/CLion-Workspace/AddSomeNoise/noise.cpp
CMakeFiles/AddSomeNoise.dir/noise.cpp.obj: CMakeFiles/AddSomeNoise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AddSomeNoise.dir/noise.cpp.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AddSomeNoise.dir/noise.cpp.obj -MF CMakeFiles\AddSomeNoise.dir\noise.cpp.obj.d -o CMakeFiles\AddSomeNoise.dir\noise.cpp.obj -c C:\dev\CLion-Workspace\AddSomeNoise\noise.cpp

CMakeFiles/AddSomeNoise.dir/noise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AddSomeNoise.dir/noise.cpp.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\CLion-Workspace\AddSomeNoise\noise.cpp > CMakeFiles\AddSomeNoise.dir\noise.cpp.i

CMakeFiles/AddSomeNoise.dir/noise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AddSomeNoise.dir/noise.cpp.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\dev\CLion-Workspace\AddSomeNoise\noise.cpp -o CMakeFiles\AddSomeNoise.dir\noise.cpp.s

# Object files for target AddSomeNoise
AddSomeNoise_OBJECTS = \
"CMakeFiles/AddSomeNoise.dir/main.cpp.obj" \
"CMakeFiles/AddSomeNoise.dir/noise.cpp.obj"

# External object files for target AddSomeNoise
AddSomeNoise_EXTERNAL_OBJECTS =

AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/main.cpp.obj
AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/noise.cpp.obj
AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/build.make
AddSomeNoise.exe: C:/boost_1_80_0/build/lib/libboost_program_options-mgw12-mt-x64-1_80.a
AddSomeNoise.exe: C:/boost_1_80_0/build/lib/libboost_program_options-mgw12-mt-x64-1_80.a
AddSomeNoise.exe: C:/opencv/build/install/x64/mingw/lib/libopencv_world460.dll.a
AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/linklibs.rsp
AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/objects1.rsp
AddSomeNoise.exe: CMakeFiles/AddSomeNoise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AddSomeNoise.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AddSomeNoise.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AddSomeNoise.dir/build: AddSomeNoise.exe
.PHONY : CMakeFiles/AddSomeNoise.dir/build

CMakeFiles/AddSomeNoise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AddSomeNoise.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AddSomeNoise.dir/clean

CMakeFiles/AddSomeNoise.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\CLion-Workspace\AddSomeNoise C:\dev\CLion-Workspace\AddSomeNoise C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug C:\dev\CLion-Workspace\AddSomeNoise\cmake-build-debug\CMakeFiles\AddSomeNoise.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AddSomeNoise.dir/depend

