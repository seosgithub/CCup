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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seo/Dev/CCup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seo/Dev/CCup/build

# Include any dependencies generated for this target.
include CMakeFiles/ccup.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ccup.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ccup.dir/flags.make

CMakeFiles/ccup.dir/CCup.cpp.o: CMakeFiles/ccup.dir/flags.make
CMakeFiles/ccup.dir/CCup.cpp.o: ../CCup.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/seo/Dev/CCup/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ccup.dir/CCup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ccup.dir/CCup.cpp.o -c /Users/seo/Dev/CCup/CCup.cpp

CMakeFiles/ccup.dir/CCup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccup.dir/CCup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/seo/Dev/CCup/CCup.cpp > CMakeFiles/ccup.dir/CCup.cpp.i

CMakeFiles/ccup.dir/CCup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccup.dir/CCup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/seo/Dev/CCup/CCup.cpp -o CMakeFiles/ccup.dir/CCup.cpp.s

CMakeFiles/ccup.dir/CCup.cpp.o.requires:
.PHONY : CMakeFiles/ccup.dir/CCup.cpp.o.requires

CMakeFiles/ccup.dir/CCup.cpp.o.provides: CMakeFiles/ccup.dir/CCup.cpp.o.requires
	$(MAKE) -f CMakeFiles/ccup.dir/build.make CMakeFiles/ccup.dir/CCup.cpp.o.provides.build
.PHONY : CMakeFiles/ccup.dir/CCup.cpp.o.provides

CMakeFiles/ccup.dir/CCup.cpp.o.provides.build: CMakeFiles/ccup.dir/CCup.cpp.o

CMakeFiles/ccup.dir/Network.cpp.o: CMakeFiles/ccup.dir/flags.make
CMakeFiles/ccup.dir/Network.cpp.o: ../Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/seo/Dev/CCup/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ccup.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ccup.dir/Network.cpp.o -c /Users/seo/Dev/CCup/Network.cpp

CMakeFiles/ccup.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccup.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/seo/Dev/CCup/Network.cpp > CMakeFiles/ccup.dir/Network.cpp.i

CMakeFiles/ccup.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccup.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/seo/Dev/CCup/Network.cpp -o CMakeFiles/ccup.dir/Network.cpp.s

CMakeFiles/ccup.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/ccup.dir/Network.cpp.o.requires

CMakeFiles/ccup.dir/Network.cpp.o.provides: CMakeFiles/ccup.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/ccup.dir/build.make CMakeFiles/ccup.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/ccup.dir/Network.cpp.o.provides

CMakeFiles/ccup.dir/Network.cpp.o.provides.build: CMakeFiles/ccup.dir/Network.cpp.o

# Object files for target ccup
ccup_OBJECTS = \
"CMakeFiles/ccup.dir/CCup.cpp.o" \
"CMakeFiles/ccup.dir/Network.cpp.o"

# External object files for target ccup
ccup_EXTERNAL_OBJECTS =

libccup.a: CMakeFiles/ccup.dir/CCup.cpp.o
libccup.a: CMakeFiles/ccup.dir/Network.cpp.o
libccup.a: CMakeFiles/ccup.dir/build.make
libccup.a: CMakeFiles/ccup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libccup.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ccup.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ccup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ccup.dir/build: libccup.a
.PHONY : CMakeFiles/ccup.dir/build

CMakeFiles/ccup.dir/requires: CMakeFiles/ccup.dir/CCup.cpp.o.requires
CMakeFiles/ccup.dir/requires: CMakeFiles/ccup.dir/Network.cpp.o.requires
.PHONY : CMakeFiles/ccup.dir/requires

CMakeFiles/ccup.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ccup.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ccup.dir/clean

CMakeFiles/ccup.dir/depend:
	cd /Users/seo/Dev/CCup/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seo/Dev/CCup /Users/seo/Dev/CCup /Users/seo/Dev/CCup/build /Users/seo/Dev/CCup/build /Users/seo/Dev/CCup/build/CMakeFiles/ccup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ccup.dir/depend

