# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = C:/Users/czupa/scoop/apps/cmake/3.17.3/bin/cmake.exe

# The command to remove a file.
RM = C:/Users/czupa/scoop/apps/cmake/3.17.3/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/00coding/repositories/Smart-Home

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/00coding/repositories/Smart-Home/build

# Include any dependencies generated for this target.
include CentralUnit/CMakeFiles/CentralUnit.dir/depend.make

# Include the progress variables for this target.
include CentralUnit/CMakeFiles/CentralUnit.dir/progress.make

# Include the compile flags for this target's objects.
include CentralUnit/CMakeFiles/CentralUnit.dir/flags.make

CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.obj: CentralUnit/CMakeFiles/CentralUnit.dir/flags.make
CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.obj: CentralUnit/CMakeFiles/CentralUnit.dir/includes_CXX.rsp
CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.obj: ../CentralUnit/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/00coding/repositories/Smart-Home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.obj"
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/gcc/current/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CentralUnit.dir/source/main.cpp.obj -c D:/00coding/repositories/Smart-Home/CentralUnit/source/main.cpp

CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CentralUnit.dir/source/main.cpp.i"
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/gcc/current/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/00coding/repositories/Smart-Home/CentralUnit/source/main.cpp > CMakeFiles/CentralUnit.dir/source/main.cpp.i

CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CentralUnit.dir/source/main.cpp.s"
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/gcc/current/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/00coding/repositories/Smart-Home/CentralUnit/source/main.cpp -o CMakeFiles/CentralUnit.dir/source/main.cpp.s

# Object files for target CentralUnit
CentralUnit_OBJECTS = \
"CMakeFiles/CentralUnit.dir/source/main.cpp.obj"

# External object files for target CentralUnit
CentralUnit_EXTERNAL_OBJECTS =

CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/source/main.cpp.obj
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/build.make
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/linklibs.rsp
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/00coding/repositories/Smart-Home/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CentralUnit.exe"
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/cmake/3.17.3/bin/cmake.exe -E rm -f CMakeFiles/CentralUnit.dir/objects.a
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/gcc/9.3.0-1/bin/ar.exe cr CMakeFiles/CentralUnit.dir/objects.a @CMakeFiles/CentralUnit.dir/objects1.rsp
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && C:/Users/czupa/scoop/apps/gcc/current/bin/g++.exe -g   -Wl,--whole-archive CMakeFiles/CentralUnit.dir/objects.a -Wl,--no-whole-archive  -o CentralUnit.exe -Wl,--out-implib,libCentralUnit.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/CentralUnit.dir/linklibs.rsp

# Rule to build all files generated by this target.
CentralUnit/CMakeFiles/CentralUnit.dir/build: CentralUnit/CentralUnit.exe

.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/build

CentralUnit/CMakeFiles/CentralUnit.dir/clean:
	cd D:/00coding/repositories/Smart-Home/build/CentralUnit && $(CMAKE_COMMAND) -P CMakeFiles/CentralUnit.dir/cmake_clean.cmake
.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/clean

CentralUnit/CMakeFiles/CentralUnit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/00coding/repositories/Smart-Home D:/00coding/repositories/Smart-Home/CentralUnit D:/00coding/repositories/Smart-Home/build D:/00coding/repositories/Smart-Home/build/CentralUnit D:/00coding/repositories/Smart-Home/build/CentralUnit/CMakeFiles/CentralUnit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/depend

