# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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
$$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\00coding\repositories\Smart-Home

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\00coding\repositories\Smart-Home\build

# Include any dependencies generated for this target.
include CentralUnit/CMakeFiles/CentralUnit.dir/depend.make

# Include the progress variables for this target.
include CentralUnit/CMakeFiles/CentralUnit.dir/progress.make

# Include the compile flags for this target's objects.
include CentralUnit/CMakeFiles/CentralUnit.dir/flags.make

CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.obj: CentralUnit/CMakeFiles/CentralUnit.dir/flags.make
CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.obj: CentralUnit/CMakeFiles/CentralUnit.dir/includes_CXX.rsp
CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.obj: ../CentralUnit/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\00coding\repositories\Smart-Home\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.obj"
	cd /d D:\00coding\repositories\Smart-Home\build\CentralUnit && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CentralUnit.dir\main.cpp.obj -c D:\00coding\repositories\Smart-Home\CentralUnit\main.cpp

CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CentralUnit.dir/main.cpp.i"
	cd /d D:\00coding\repositories\Smart-Home\build\CentralUnit && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\00coding\repositories\Smart-Home\CentralUnit\main.cpp > CMakeFiles\CentralUnit.dir\main.cpp.i

CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CentralUnit.dir/main.cpp.s"
	cd /d D:\00coding\repositories\Smart-Home\build\CentralUnit && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\00coding\repositories\Smart-Home\CentralUnit\main.cpp -o CMakeFiles\CentralUnit.dir\main.cpp.s

# Object files for target CentralUnit
CentralUnit_OBJECTS = \
"CMakeFiles/CentralUnit.dir/main.cpp.obj"

# External object files for target CentralUnit
CentralUnit_EXTERNAL_OBJECTS =

CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/main.cpp.obj
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/build.make
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/linklibs.rsp
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/objects1.rsp
CentralUnit/CentralUnit.exe: CentralUnit/CMakeFiles/CentralUnit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\00coding\repositories\Smart-Home\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CentralUnit.exe"
	cd /d D:\00coding\repositories\Smart-Home\build\CentralUnit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CentralUnit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CentralUnit/CMakeFiles/CentralUnit.dir/build: CentralUnit/CentralUnit.exe

.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/build

CentralUnit/CMakeFiles/CentralUnit.dir/clean:
	cd /d D:\00coding\repositories\Smart-Home\build\CentralUnit && $(CMAKE_COMMAND) -P CMakeFiles\CentralUnit.dir\cmake_clean.cmake
.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/clean

CentralUnit/CMakeFiles/CentralUnit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\00coding\repositories\Smart-Home D:\00coding\repositories\Smart-Home\CentralUnit D:\00coding\repositories\Smart-Home\build D:\00coding\repositories\Smart-Home\build\CentralUnit D:\00coding\repositories\Smart-Home\build\CentralUnit\CMakeFiles\CentralUnit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CentralUnit/CMakeFiles/CentralUnit.dir/depend
