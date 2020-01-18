# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/apetukhov/projects/made/libsvm2csv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/apetukhov/projects/made/libsvm2csv

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/apetukhov/projects/made/libsvm2csv/CMakeFiles /home/apetukhov/projects/made/libsvm2csv/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/apetukhov/projects/made/libsvm2csv/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named svm2csv

# Build rule for target.
svm2csv: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 svm2csv
.PHONY : svm2csv

# fast build rule for target.
svm2csv/fast:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/build
.PHONY : svm2csv/fast

convert.o: convert.cpp.o

.PHONY : convert.o

# target to build an object file
convert.cpp.o:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/convert.cpp.o
.PHONY : convert.cpp.o

convert.i: convert.cpp.i

.PHONY : convert.i

# target to preprocess a source file
convert.cpp.i:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/convert.cpp.i
.PHONY : convert.cpp.i

convert.s: convert.cpp.s

.PHONY : convert.s

# target to generate assembly for a file
convert.cpp.s:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/convert.cpp.s
.PHONY : convert.cpp.s

svm2csv.o: svm2csv.cpp.o

.PHONY : svm2csv.o

# target to build an object file
svm2csv.cpp.o:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/svm2csv.cpp.o
.PHONY : svm2csv.cpp.o

svm2csv.i: svm2csv.cpp.i

.PHONY : svm2csv.i

# target to preprocess a source file
svm2csv.cpp.i:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/svm2csv.cpp.i
.PHONY : svm2csv.cpp.i

svm2csv.s: svm2csv.cpp.s

.PHONY : svm2csv.s

# target to generate assembly for a file
svm2csv.cpp.s:
	$(MAKE) -f CMakeFiles/svm2csv.dir/build.make CMakeFiles/svm2csv.dir/svm2csv.cpp.s
.PHONY : svm2csv.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... svm2csv"
	@echo "... edit_cache"
	@echo "... convert.o"
	@echo "... convert.i"
	@echo "... convert.s"
	@echo "... svm2csv.o"
	@echo "... svm2csv.i"
	@echo "... svm2csv.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

