# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amsadowski/submarineRacers/lib/libpng-1.6.29

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amsadowski/submarineRacers/lib/libpng-1.6.29

# Include any dependencies generated for this target.
include CMakeFiles/png.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/png.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/png.dir/flags.make

pnglibconf.h: pnglibconf.out
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating pnglibconf.h"
	/usr/bin/cmake -DOUTPUT=pnglibconf.h -P /home/amsadowski/submarineRacers/lib/libpng-1.6.29/scripts/gensrc.cmake

pngprefix.h:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating pngprefix.h"
	/usr/bin/cmake -DOUTPUT=pngprefix.h -P /home/amsadowski/submarineRacers/lib/libpng-1.6.29/scripts/gensrc.cmake

pnglibconf.out: pnglibconf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating pnglibconf.out"
	/usr/bin/cmake -DINPUT=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/pnglibconf.c -DOUTPUT=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/pnglibconf.out -P /home/amsadowski/submarineRacers/lib/libpng-1.6.29/scripts/genout.cmake

pnglibconf.c: scripts/pnglibconf.dfa
pnglibconf.c: scripts/options.awk
pnglibconf.c: pngconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating pnglibconf.c"
	/usr/bin/cmake -DOUTPUT=pnglibconf.c -P /home/amsadowski/submarineRacers/lib/libpng-1.6.29/scripts/gensrc.cmake

CMakeFiles/png.dir/png.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/png.c.o: png.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/png.dir/png.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/png.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/png.c

CMakeFiles/png.dir/png.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/png.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/png.c > CMakeFiles/png.dir/png.c.i

CMakeFiles/png.dir/png.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/png.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/png.c -o CMakeFiles/png.dir/png.c.s

CMakeFiles/png.dir/png.c.o.requires:

.PHONY : CMakeFiles/png.dir/png.c.o.requires

CMakeFiles/png.dir/png.c.o.provides: CMakeFiles/png.dir/png.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/png.c.o.provides.build
.PHONY : CMakeFiles/png.dir/png.c.o.provides

CMakeFiles/png.dir/png.c.o.provides.build: CMakeFiles/png.dir/png.c.o


CMakeFiles/png.dir/pngerror.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngerror.c.o: pngerror.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/png.dir/pngerror.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngerror.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngerror.c

CMakeFiles/png.dir/pngerror.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngerror.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngerror.c > CMakeFiles/png.dir/pngerror.c.i

CMakeFiles/png.dir/pngerror.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngerror.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngerror.c -o CMakeFiles/png.dir/pngerror.c.s

CMakeFiles/png.dir/pngerror.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngerror.c.o.requires

CMakeFiles/png.dir/pngerror.c.o.provides: CMakeFiles/png.dir/pngerror.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngerror.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngerror.c.o.provides

CMakeFiles/png.dir/pngerror.c.o.provides.build: CMakeFiles/png.dir/pngerror.c.o


CMakeFiles/png.dir/pngget.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngget.c.o: pngget.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/png.dir/pngget.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngget.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngget.c

CMakeFiles/png.dir/pngget.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngget.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngget.c > CMakeFiles/png.dir/pngget.c.i

CMakeFiles/png.dir/pngget.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngget.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngget.c -o CMakeFiles/png.dir/pngget.c.s

CMakeFiles/png.dir/pngget.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngget.c.o.requires

CMakeFiles/png.dir/pngget.c.o.provides: CMakeFiles/png.dir/pngget.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngget.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngget.c.o.provides

CMakeFiles/png.dir/pngget.c.o.provides.build: CMakeFiles/png.dir/pngget.c.o


CMakeFiles/png.dir/pngmem.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngmem.c.o: pngmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/png.dir/pngmem.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngmem.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngmem.c

CMakeFiles/png.dir/pngmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngmem.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngmem.c > CMakeFiles/png.dir/pngmem.c.i

CMakeFiles/png.dir/pngmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngmem.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngmem.c -o CMakeFiles/png.dir/pngmem.c.s

CMakeFiles/png.dir/pngmem.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngmem.c.o.requires

CMakeFiles/png.dir/pngmem.c.o.provides: CMakeFiles/png.dir/pngmem.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngmem.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngmem.c.o.provides

CMakeFiles/png.dir/pngmem.c.o.provides.build: CMakeFiles/png.dir/pngmem.c.o


CMakeFiles/png.dir/pngpread.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngpread.c.o: pngpread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/png.dir/pngpread.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngpread.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngpread.c

CMakeFiles/png.dir/pngpread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngpread.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngpread.c > CMakeFiles/png.dir/pngpread.c.i

CMakeFiles/png.dir/pngpread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngpread.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngpread.c -o CMakeFiles/png.dir/pngpread.c.s

CMakeFiles/png.dir/pngpread.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngpread.c.o.requires

CMakeFiles/png.dir/pngpread.c.o.provides: CMakeFiles/png.dir/pngpread.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngpread.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngpread.c.o.provides

CMakeFiles/png.dir/pngpread.c.o.provides.build: CMakeFiles/png.dir/pngpread.c.o


CMakeFiles/png.dir/pngread.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngread.c.o: pngread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/png.dir/pngread.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngread.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngread.c

CMakeFiles/png.dir/pngread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngread.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngread.c > CMakeFiles/png.dir/pngread.c.i

CMakeFiles/png.dir/pngread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngread.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngread.c -o CMakeFiles/png.dir/pngread.c.s

CMakeFiles/png.dir/pngread.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngread.c.o.requires

CMakeFiles/png.dir/pngread.c.o.provides: CMakeFiles/png.dir/pngread.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngread.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngread.c.o.provides

CMakeFiles/png.dir/pngread.c.o.provides.build: CMakeFiles/png.dir/pngread.c.o


CMakeFiles/png.dir/pngrio.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngrio.c.o: pngrio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/png.dir/pngrio.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngrio.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrio.c

CMakeFiles/png.dir/pngrio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngrio.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrio.c > CMakeFiles/png.dir/pngrio.c.i

CMakeFiles/png.dir/pngrio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngrio.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrio.c -o CMakeFiles/png.dir/pngrio.c.s

CMakeFiles/png.dir/pngrio.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngrio.c.o.requires

CMakeFiles/png.dir/pngrio.c.o.provides: CMakeFiles/png.dir/pngrio.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngrio.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngrio.c.o.provides

CMakeFiles/png.dir/pngrio.c.o.provides.build: CMakeFiles/png.dir/pngrio.c.o


CMakeFiles/png.dir/pngrtran.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngrtran.c.o: pngrtran.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/png.dir/pngrtran.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngrtran.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrtran.c

CMakeFiles/png.dir/pngrtran.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngrtran.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrtran.c > CMakeFiles/png.dir/pngrtran.c.i

CMakeFiles/png.dir/pngrtran.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngrtran.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrtran.c -o CMakeFiles/png.dir/pngrtran.c.s

CMakeFiles/png.dir/pngrtran.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngrtran.c.o.requires

CMakeFiles/png.dir/pngrtran.c.o.provides: CMakeFiles/png.dir/pngrtran.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngrtran.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngrtran.c.o.provides

CMakeFiles/png.dir/pngrtran.c.o.provides.build: CMakeFiles/png.dir/pngrtran.c.o


CMakeFiles/png.dir/pngrutil.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngrutil.c.o: pngrutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/png.dir/pngrutil.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngrutil.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrutil.c

CMakeFiles/png.dir/pngrutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngrutil.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrutil.c > CMakeFiles/png.dir/pngrutil.c.i

CMakeFiles/png.dir/pngrutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngrutil.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngrutil.c -o CMakeFiles/png.dir/pngrutil.c.s

CMakeFiles/png.dir/pngrutil.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngrutil.c.o.requires

CMakeFiles/png.dir/pngrutil.c.o.provides: CMakeFiles/png.dir/pngrutil.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngrutil.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngrutil.c.o.provides

CMakeFiles/png.dir/pngrutil.c.o.provides.build: CMakeFiles/png.dir/pngrutil.c.o


CMakeFiles/png.dir/pngset.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngset.c.o: pngset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/png.dir/pngset.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngset.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngset.c

CMakeFiles/png.dir/pngset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngset.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngset.c > CMakeFiles/png.dir/pngset.c.i

CMakeFiles/png.dir/pngset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngset.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngset.c -o CMakeFiles/png.dir/pngset.c.s

CMakeFiles/png.dir/pngset.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngset.c.o.requires

CMakeFiles/png.dir/pngset.c.o.provides: CMakeFiles/png.dir/pngset.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngset.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngset.c.o.provides

CMakeFiles/png.dir/pngset.c.o.provides.build: CMakeFiles/png.dir/pngset.c.o


CMakeFiles/png.dir/pngtrans.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngtrans.c.o: pngtrans.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/png.dir/pngtrans.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngtrans.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngtrans.c

CMakeFiles/png.dir/pngtrans.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngtrans.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngtrans.c > CMakeFiles/png.dir/pngtrans.c.i

CMakeFiles/png.dir/pngtrans.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngtrans.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngtrans.c -o CMakeFiles/png.dir/pngtrans.c.s

CMakeFiles/png.dir/pngtrans.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngtrans.c.o.requires

CMakeFiles/png.dir/pngtrans.c.o.provides: CMakeFiles/png.dir/pngtrans.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngtrans.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngtrans.c.o.provides

CMakeFiles/png.dir/pngtrans.c.o.provides.build: CMakeFiles/png.dir/pngtrans.c.o


CMakeFiles/png.dir/pngwio.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngwio.c.o: pngwio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/png.dir/pngwio.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngwio.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwio.c

CMakeFiles/png.dir/pngwio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngwio.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwio.c > CMakeFiles/png.dir/pngwio.c.i

CMakeFiles/png.dir/pngwio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngwio.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwio.c -o CMakeFiles/png.dir/pngwio.c.s

CMakeFiles/png.dir/pngwio.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngwio.c.o.requires

CMakeFiles/png.dir/pngwio.c.o.provides: CMakeFiles/png.dir/pngwio.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngwio.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngwio.c.o.provides

CMakeFiles/png.dir/pngwio.c.o.provides.build: CMakeFiles/png.dir/pngwio.c.o


CMakeFiles/png.dir/pngwrite.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngwrite.c.o: pngwrite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/png.dir/pngwrite.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngwrite.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwrite.c

CMakeFiles/png.dir/pngwrite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngwrite.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwrite.c > CMakeFiles/png.dir/pngwrite.c.i

CMakeFiles/png.dir/pngwrite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngwrite.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwrite.c -o CMakeFiles/png.dir/pngwrite.c.s

CMakeFiles/png.dir/pngwrite.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngwrite.c.o.requires

CMakeFiles/png.dir/pngwrite.c.o.provides: CMakeFiles/png.dir/pngwrite.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngwrite.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngwrite.c.o.provides

CMakeFiles/png.dir/pngwrite.c.o.provides.build: CMakeFiles/png.dir/pngwrite.c.o


CMakeFiles/png.dir/pngwtran.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngwtran.c.o: pngwtran.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/png.dir/pngwtran.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngwtran.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwtran.c

CMakeFiles/png.dir/pngwtran.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngwtran.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwtran.c > CMakeFiles/png.dir/pngwtran.c.i

CMakeFiles/png.dir/pngwtran.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngwtran.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwtran.c -o CMakeFiles/png.dir/pngwtran.c.s

CMakeFiles/png.dir/pngwtran.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngwtran.c.o.requires

CMakeFiles/png.dir/pngwtran.c.o.provides: CMakeFiles/png.dir/pngwtran.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngwtran.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngwtran.c.o.provides

CMakeFiles/png.dir/pngwtran.c.o.provides.build: CMakeFiles/png.dir/pngwtran.c.o


CMakeFiles/png.dir/pngwutil.c.o: CMakeFiles/png.dir/flags.make
CMakeFiles/png.dir/pngwutil.c.o: pngwutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/png.dir/pngwutil.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/png.dir/pngwutil.c.o   -c /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwutil.c

CMakeFiles/png.dir/pngwutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/png.dir/pngwutil.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwutil.c > CMakeFiles/png.dir/pngwutil.c.i

CMakeFiles/png.dir/pngwutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/png.dir/pngwutil.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amsadowski/submarineRacers/lib/libpng-1.6.29/pngwutil.c -o CMakeFiles/png.dir/pngwutil.c.s

CMakeFiles/png.dir/pngwutil.c.o.requires:

.PHONY : CMakeFiles/png.dir/pngwutil.c.o.requires

CMakeFiles/png.dir/pngwutil.c.o.provides: CMakeFiles/png.dir/pngwutil.c.o.requires
	$(MAKE) -f CMakeFiles/png.dir/build.make CMakeFiles/png.dir/pngwutil.c.o.provides.build
.PHONY : CMakeFiles/png.dir/pngwutil.c.o.provides

CMakeFiles/png.dir/pngwutil.c.o.provides.build: CMakeFiles/png.dir/pngwutil.c.o


# Object files for target png
png_OBJECTS = \
"CMakeFiles/png.dir/png.c.o" \
"CMakeFiles/png.dir/pngerror.c.o" \
"CMakeFiles/png.dir/pngget.c.o" \
"CMakeFiles/png.dir/pngmem.c.o" \
"CMakeFiles/png.dir/pngpread.c.o" \
"CMakeFiles/png.dir/pngread.c.o" \
"CMakeFiles/png.dir/pngrio.c.o" \
"CMakeFiles/png.dir/pngrtran.c.o" \
"CMakeFiles/png.dir/pngrutil.c.o" \
"CMakeFiles/png.dir/pngset.c.o" \
"CMakeFiles/png.dir/pngtrans.c.o" \
"CMakeFiles/png.dir/pngwio.c.o" \
"CMakeFiles/png.dir/pngwrite.c.o" \
"CMakeFiles/png.dir/pngwtran.c.o" \
"CMakeFiles/png.dir/pngwutil.c.o"

# External object files for target png
png_EXTERNAL_OBJECTS =

libpng16.so.16.29.0: CMakeFiles/png.dir/png.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngerror.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngget.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngmem.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngpread.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngread.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngrio.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngrtran.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngrutil.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngset.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngtrans.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngwio.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngwrite.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngwtran.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/pngwutil.c.o
libpng16.so.16.29.0: CMakeFiles/png.dir/build.make
libpng16.so.16.29.0: /usr/lib/x86_64-linux-gnu/libz.so
libpng16.so.16.29.0: /usr/lib/x86_64-linux-gnu/libm.so
libpng16.so.16.29.0: CMakeFiles/png.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking C shared library libpng16.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/png.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libpng16.so.16.29.0 libpng16.so.16 libpng16.so

libpng16.so.16: libpng16.so.16.29.0
	@$(CMAKE_COMMAND) -E touch_nocreate libpng16.so.16

libpng16.so: libpng16.so.16.29.0
	@$(CMAKE_COMMAND) -E touch_nocreate libpng16.so

# Rule to build all files generated by this target.
CMakeFiles/png.dir/build: libpng16.so

.PHONY : CMakeFiles/png.dir/build

# Object files for target png
png_OBJECTS = \
"CMakeFiles/png.dir/png.c.o" \
"CMakeFiles/png.dir/pngerror.c.o" \
"CMakeFiles/png.dir/pngget.c.o" \
"CMakeFiles/png.dir/pngmem.c.o" \
"CMakeFiles/png.dir/pngpread.c.o" \
"CMakeFiles/png.dir/pngread.c.o" \
"CMakeFiles/png.dir/pngrio.c.o" \
"CMakeFiles/png.dir/pngrtran.c.o" \
"CMakeFiles/png.dir/pngrutil.c.o" \
"CMakeFiles/png.dir/pngset.c.o" \
"CMakeFiles/png.dir/pngtrans.c.o" \
"CMakeFiles/png.dir/pngwio.c.o" \
"CMakeFiles/png.dir/pngwrite.c.o" \
"CMakeFiles/png.dir/pngwtran.c.o" \
"CMakeFiles/png.dir/pngwutil.c.o"

# External object files for target png
png_EXTERNAL_OBJECTS =

CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/png.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngerror.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngget.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngmem.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngpread.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngread.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngrio.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngrtran.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngrutil.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngset.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngtrans.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngwio.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngwrite.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngwtran.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/pngwutil.c.o
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/build.make
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: /usr/lib/x86_64-linux-gnu/libz.so
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: /usr/lib/x86_64-linux-gnu/libm.so
CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0: CMakeFiles/png.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking C shared library CMakeFiles/CMakeRelink.dir/libpng16.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/png.dir/relink.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0 CMakeFiles/CMakeRelink.dir/libpng16.so.16 CMakeFiles/CMakeRelink.dir/libpng16.so

CMakeFiles/CMakeRelink.dir/libpng16.so.16: CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/CMakeRelink.dir/libpng16.so.16

CMakeFiles/CMakeRelink.dir/libpng16.so: CMakeFiles/CMakeRelink.dir/libpng16.so.16.29.0
	@$(CMAKE_COMMAND) -E touch_nocreate CMakeFiles/CMakeRelink.dir/libpng16.so

# Rule to relink during preinstall.
CMakeFiles/png.dir/preinstall: CMakeFiles/CMakeRelink.dir/libpng16.so

.PHONY : CMakeFiles/png.dir/preinstall

CMakeFiles/png.dir/requires: CMakeFiles/png.dir/png.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngerror.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngget.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngmem.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngpread.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngread.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngrio.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngrtran.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngrutil.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngset.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngtrans.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngwio.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngwrite.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngwtran.c.o.requires
CMakeFiles/png.dir/requires: CMakeFiles/png.dir/pngwutil.c.o.requires

.PHONY : CMakeFiles/png.dir/requires

CMakeFiles/png.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/png.dir/cmake_clean.cmake
.PHONY : CMakeFiles/png.dir/clean

CMakeFiles/png.dir/depend: pnglibconf.h
CMakeFiles/png.dir/depend: pngprefix.h
CMakeFiles/png.dir/depend: pnglibconf.out
CMakeFiles/png.dir/depend: pnglibconf.c
	cd /home/amsadowski/submarineRacers/lib/libpng-1.6.29 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amsadowski/submarineRacers/lib/libpng-1.6.29 /home/amsadowski/submarineRacers/lib/libpng-1.6.29 /home/amsadowski/submarineRacers/lib/libpng-1.6.29 /home/amsadowski/submarineRacers/lib/libpng-1.6.29 /home/amsadowski/submarineRacers/lib/libpng-1.6.29/CMakeFiles/png.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/png.dir/depend

