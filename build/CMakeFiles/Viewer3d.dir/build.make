# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/reality-marble/GitProjects/Viewer3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/reality-marble/GitProjects/Viewer3d/build

# Include any dependencies generated for this target.
include CMakeFiles/Viewer3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Viewer3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Viewer3d.dir/flags.make

CMakeFiles/Viewer3d.dir/src/main.cpp.o: CMakeFiles/Viewer3d.dir/flags.make
CMakeFiles/Viewer3d.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reality-marble/GitProjects/Viewer3d/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Viewer3d.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Viewer3d.dir/src/main.cpp.o -c /home/reality-marble/GitProjects/Viewer3d/src/main.cpp

CMakeFiles/Viewer3d.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Viewer3d.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reality-marble/GitProjects/Viewer3d/src/main.cpp > CMakeFiles/Viewer3d.dir/src/main.cpp.i

CMakeFiles/Viewer3d.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Viewer3d.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reality-marble/GitProjects/Viewer3d/src/main.cpp -o CMakeFiles/Viewer3d.dir/src/main.cpp.s

CMakeFiles/Viewer3d.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/Viewer3d.dir/src/main.cpp.o.requires

CMakeFiles/Viewer3d.dir/src/main.cpp.o.provides: CMakeFiles/Viewer3d.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Viewer3d.dir/build.make CMakeFiles/Viewer3d.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Viewer3d.dir/src/main.cpp.o.provides

CMakeFiles/Viewer3d.dir/src/main.cpp.o.provides.build: CMakeFiles/Viewer3d.dir/src/main.cpp.o

CMakeFiles/Viewer3d.dir/src/Shader.cpp.o: CMakeFiles/Viewer3d.dir/flags.make
CMakeFiles/Viewer3d.dir/src/Shader.cpp.o: ../src/Shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reality-marble/GitProjects/Viewer3d/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Viewer3d.dir/src/Shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Viewer3d.dir/src/Shader.cpp.o -c /home/reality-marble/GitProjects/Viewer3d/src/Shader.cpp

CMakeFiles/Viewer3d.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Viewer3d.dir/src/Shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reality-marble/GitProjects/Viewer3d/src/Shader.cpp > CMakeFiles/Viewer3d.dir/src/Shader.cpp.i

CMakeFiles/Viewer3d.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Viewer3d.dir/src/Shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reality-marble/GitProjects/Viewer3d/src/Shader.cpp -o CMakeFiles/Viewer3d.dir/src/Shader.cpp.s

CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.requires:
.PHONY : CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.requires

CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.provides: CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Viewer3d.dir/build.make CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.provides

CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.provides.build: CMakeFiles/Viewer3d.dir/src/Shader.cpp.o

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o: CMakeFiles/Viewer3d.dir/flags.make
CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o: ../src/Mesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reality-marble/GitProjects/Viewer3d/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o -c /home/reality-marble/GitProjects/Viewer3d/src/Mesh.cpp

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Viewer3d.dir/src/Mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reality-marble/GitProjects/Viewer3d/src/Mesh.cpp > CMakeFiles/Viewer3d.dir/src/Mesh.cpp.i

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Viewer3d.dir/src/Mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reality-marble/GitProjects/Viewer3d/src/Mesh.cpp -o CMakeFiles/Viewer3d.dir/src/Mesh.cpp.s

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.requires:
.PHONY : CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.requires

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.provides: CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/Viewer3d.dir/build.make CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.provides

CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.provides.build: CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o

# Object files for target Viewer3d
Viewer3d_OBJECTS = \
"CMakeFiles/Viewer3d.dir/src/main.cpp.o" \
"CMakeFiles/Viewer3d.dir/src/Shader.cpp.o" \
"CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o"

# External object files for target Viewer3d
Viewer3d_EXTERNAL_OBJECTS =

../bin/Viewer3d: CMakeFiles/Viewer3d.dir/src/main.cpp.o
../bin/Viewer3d: CMakeFiles/Viewer3d.dir/src/Shader.cpp.o
../bin/Viewer3d: CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o
../bin/Viewer3d: CMakeFiles/Viewer3d.dir/build.make
../bin/Viewer3d: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/Viewer3d: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/Viewer3d: /usr/lib/x86_64-linux-gnu/libXext.so
../bin/Viewer3d: /usr/local/build/SFML-2.3/lib/libsfml-system.so
../bin/Viewer3d: /usr/local/build/SFML-2.3/lib/libsfml-window.so
../bin/Viewer3d: /usr/local/build/SFML-2.3/lib/libsfml-graphics.so
../bin/Viewer3d: /usr/local/build/SFML-2.3/lib/libsfml-network.so
../bin/Viewer3d: /usr/local/build/SFML-2.3/lib/libsfml-audio.so
../bin/Viewer3d: CMakeFiles/Viewer3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/Viewer3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Viewer3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Viewer3d.dir/build: ../bin/Viewer3d
.PHONY : CMakeFiles/Viewer3d.dir/build

CMakeFiles/Viewer3d.dir/requires: CMakeFiles/Viewer3d.dir/src/main.cpp.o.requires
CMakeFiles/Viewer3d.dir/requires: CMakeFiles/Viewer3d.dir/src/Shader.cpp.o.requires
CMakeFiles/Viewer3d.dir/requires: CMakeFiles/Viewer3d.dir/src/Mesh.cpp.o.requires
.PHONY : CMakeFiles/Viewer3d.dir/requires

CMakeFiles/Viewer3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Viewer3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Viewer3d.dir/clean

CMakeFiles/Viewer3d.dir/depend:
	cd /home/reality-marble/GitProjects/Viewer3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/reality-marble/GitProjects/Viewer3d /home/reality-marble/GitProjects/Viewer3d /home/reality-marble/GitProjects/Viewer3d/build /home/reality-marble/GitProjects/Viewer3d/build /home/reality-marble/GitProjects/Viewer3d/build/CMakeFiles/Viewer3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Viewer3d.dir/depend

