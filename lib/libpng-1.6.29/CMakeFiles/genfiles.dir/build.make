# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ashwin/repo/submarines/lib/libpng-1.6.29

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ashwin/repo/submarines/lib/libpng-1.6.29

# Utility rule file for genfiles.

# Include the progress variables for this target.
include CMakeFiles/genfiles.dir/progress.make

CMakeFiles/genfiles: libpng.sym
CMakeFiles/genfiles: libpng.vers
CMakeFiles/genfiles: pnglibconf.c
CMakeFiles/genfiles: pnglibconf.h
CMakeFiles/genfiles: pnglibconf.out
CMakeFiles/genfiles: pngprefix.h
CMakeFiles/genfiles: scripts/intprefix.out
CMakeFiles/genfiles: scripts/pnglibconf.c
CMakeFiles/genfiles: scripts/prefix.out
CMakeFiles/genfiles: scripts/sym.out
CMakeFiles/genfiles: scripts/symbols.chk
CMakeFiles/genfiles: scripts/symbols.out
CMakeFiles/genfiles: scripts/vers.out


libpng.sym: scripts/sym.out
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating libpng.sym"
	/usr/bin/cmake -E remove /home/ashwin/repo/submarines/lib/libpng-1.6.29/libpng.sym
	/usr/bin/cmake -E copy /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/sym.out /home/ashwin/repo/submarines/lib/libpng-1.6.29/libpng.sym

libpng.vers: scripts/vers.out
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating libpng.vers"
	/usr/bin/cmake -E remove /home/ashwin/repo/submarines/lib/libpng-1.6.29/libpng.vers
	/usr/bin/cmake -E copy /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/vers.out /home/ashwin/repo/submarines/lib/libpng-1.6.29/libpng.vers

pnglibconf.c: scripts/pnglibconf.dfa
pnglibconf.c: scripts/options.awk
pnglibconf.c: pngconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating pnglibconf.c"
	/usr/bin/cmake -DOUTPUT=pnglibconf.c -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/gensrc.cmake

pnglibconf.h: pnglibconf.out
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating pnglibconf.h"
	/usr/bin/cmake -DOUTPUT=pnglibconf.h -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/gensrc.cmake

pnglibconf.out: pnglibconf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Generating pnglibconf.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/pnglibconf.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/pnglibconf.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

pngprefix.h:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Generating pngprefix.h"
	/usr/bin/cmake -DOUTPUT=pngprefix.h -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/gensrc.cmake

scripts/intprefix.out: scripts/intprefix.c
scripts/intprefix.out: pnglibconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Generating scripts/intprefix.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/intprefix.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/intprefix.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

scripts/pnglibconf.c: scripts/pnglibconf.dfa
scripts/pnglibconf.c: scripts/options.awk
scripts/pnglibconf.c: pngconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Generating scripts/pnglibconf.c"
	/usr/bin/cmake -DOUTPUT=scripts/pnglibconf.c -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/gensrc.cmake

scripts/prefix.out: scripts/prefix.c
scripts/prefix.out: png.h
scripts/prefix.out: pngconf.h
scripts/prefix.out: pnglibconf.out
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Generating scripts/prefix.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/prefix.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/prefix.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

scripts/sym.out: scripts/sym.c
scripts/sym.out: pnglibconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Generating scripts/sym.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/sym.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/sym.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

scripts/symbols.chk: scripts/symbols.out
scripts/symbols.chk: scripts/checksym.awk
scripts/symbols.chk: scripts/symbols.def
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Generating scripts/symbols.chk"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/symbols.out -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/symbols.chk -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genchk.cmake

scripts/symbols.out: scripts/symbols.c
scripts/symbols.out: png.h
scripts/symbols.out: pngconf.h
scripts/symbols.out: scripts/pnglibconf.h.prebuilt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Generating scripts/symbols.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/symbols.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/symbols.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

scripts/vers.out: scripts/vers.c
scripts/vers.out: png.h
scripts/vers.out: pngconf.h
scripts/vers.out: pnglibconf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Generating scripts/vers.out"
	/usr/bin/cmake -DINPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/vers.c -DOUTPUT=/home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/vers.out -P /home/ashwin/repo/submarines/lib/libpng-1.6.29/scripts/genout.cmake

genfiles: CMakeFiles/genfiles
genfiles: libpng.sym
genfiles: libpng.vers
genfiles: pnglibconf.c
genfiles: pnglibconf.h
genfiles: pnglibconf.out
genfiles: pngprefix.h
genfiles: scripts/intprefix.out
genfiles: scripts/pnglibconf.c
genfiles: scripts/prefix.out
genfiles: scripts/sym.out
genfiles: scripts/symbols.chk
genfiles: scripts/symbols.out
genfiles: scripts/vers.out
genfiles: CMakeFiles/genfiles.dir/build.make

.PHONY : genfiles

# Rule to build all files generated by this target.
CMakeFiles/genfiles.dir/build: genfiles

.PHONY : CMakeFiles/genfiles.dir/build

CMakeFiles/genfiles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/genfiles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/genfiles.dir/clean

CMakeFiles/genfiles.dir/depend:
	cd /home/ashwin/repo/submarines/lib/libpng-1.6.29 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashwin/repo/submarines/lib/libpng-1.6.29 /home/ashwin/repo/submarines/lib/libpng-1.6.29 /home/ashwin/repo/submarines/lib/libpng-1.6.29 /home/ashwin/repo/submarines/lib/libpng-1.6.29 /home/ashwin/repo/submarines/lib/libpng-1.6.29/CMakeFiles/genfiles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/genfiles.dir/depend

