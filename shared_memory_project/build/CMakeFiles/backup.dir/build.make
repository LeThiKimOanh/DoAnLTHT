# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build

# Include any dependencies generated for this target.
include CMakeFiles/backup.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/backup.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/backup.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/backup.dir/flags.make

CMakeFiles/backup.dir/src/backup.c.o: CMakeFiles/backup.dir/flags.make
CMakeFiles/backup.dir/src/backup.c.o: /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/src/backup.c
CMakeFiles/backup.dir/src/backup.c.o: CMakeFiles/backup.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/backup.dir/src/backup.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/backup.dir/src/backup.c.o -MF CMakeFiles/backup.dir/src/backup.c.o.d -o CMakeFiles/backup.dir/src/backup.c.o -c /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/src/backup.c

CMakeFiles/backup.dir/src/backup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/backup.dir/src/backup.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/src/backup.c > CMakeFiles/backup.dir/src/backup.c.i

CMakeFiles/backup.dir/src/backup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/backup.dir/src/backup.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/src/backup.c -o CMakeFiles/backup.dir/src/backup.c.s

# Object files for target backup
backup_OBJECTS = \
"CMakeFiles/backup.dir/src/backup.c.o"

# External object files for target backup
backup_EXTERNAL_OBJECTS =

backup: CMakeFiles/backup.dir/src/backup.c.o
backup: CMakeFiles/backup.dir/build.make
backup: CMakeFiles/backup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable backup"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/backup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/backup.dir/build: backup
.PHONY : CMakeFiles/backup.dir/build

CMakeFiles/backup.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/backup.dir/cmake_clean.cmake
.PHONY : CMakeFiles/backup.dir/clean

CMakeFiles/backup.dir/depend:
	cd /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build /home/kim-oanh/Documents/LTHT/DACK/shared_memory_project/build/CMakeFiles/backup.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/backup.dir/depend

