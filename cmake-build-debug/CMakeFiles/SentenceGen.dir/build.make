# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\togla\OneDrive\Bureau\SentenceGen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SentenceGen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SentenceGen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SentenceGen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SentenceGen.dir/flags.make

CMakeFiles/SentenceGen.dir/main.c.obj: CMakeFiles/SentenceGen.dir/flags.make
CMakeFiles/SentenceGen.dir/main.c.obj: ../main.c
CMakeFiles/SentenceGen.dir/main.c.obj: CMakeFiles/SentenceGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SentenceGen.dir/main.c.obj"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SentenceGen.dir/main.c.obj -MF CMakeFiles\SentenceGen.dir\main.c.obj.d -o CMakeFiles\SentenceGen.dir\main.c.obj -c C:\Users\togla\OneDrive\Bureau\SentenceGen\main.c

CMakeFiles/SentenceGen.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SentenceGen.dir/main.c.i"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\togla\OneDrive\Bureau\SentenceGen\main.c > CMakeFiles\SentenceGen.dir\main.c.i

CMakeFiles/SentenceGen.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SentenceGen.dir/main.c.s"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\togla\OneDrive\Bureau\SentenceGen\main.c -o CMakeFiles\SentenceGen.dir\main.c.s

CMakeFiles/SentenceGen.dir/struct.c.obj: CMakeFiles/SentenceGen.dir/flags.make
CMakeFiles/SentenceGen.dir/struct.c.obj: ../struct.c
CMakeFiles/SentenceGen.dir/struct.c.obj: CMakeFiles/SentenceGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SentenceGen.dir/struct.c.obj"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SentenceGen.dir/struct.c.obj -MF CMakeFiles\SentenceGen.dir\struct.c.obj.d -o CMakeFiles\SentenceGen.dir\struct.c.obj -c C:\Users\togla\OneDrive\Bureau\SentenceGen\struct.c

CMakeFiles/SentenceGen.dir/struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SentenceGen.dir/struct.c.i"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\togla\OneDrive\Bureau\SentenceGen\struct.c > CMakeFiles\SentenceGen.dir\struct.c.i

CMakeFiles/SentenceGen.dir/struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SentenceGen.dir/struct.c.s"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\togla\OneDrive\Bureau\SentenceGen\struct.c -o CMakeFiles\SentenceGen.dir\struct.c.s

CMakeFiles/SentenceGen.dir/file.c.obj: CMakeFiles/SentenceGen.dir/flags.make
CMakeFiles/SentenceGen.dir/file.c.obj: ../file.c
CMakeFiles/SentenceGen.dir/file.c.obj: CMakeFiles/SentenceGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SentenceGen.dir/file.c.obj"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SentenceGen.dir/file.c.obj -MF CMakeFiles\SentenceGen.dir\file.c.obj.d -o CMakeFiles\SentenceGen.dir\file.c.obj -c C:\Users\togla\OneDrive\Bureau\SentenceGen\file.c

CMakeFiles/SentenceGen.dir/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SentenceGen.dir/file.c.i"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\togla\OneDrive\Bureau\SentenceGen\file.c > CMakeFiles\SentenceGen.dir\file.c.i

CMakeFiles/SentenceGen.dir/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SentenceGen.dir/file.c.s"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\togla\OneDrive\Bureau\SentenceGen\file.c -o CMakeFiles\SentenceGen.dir\file.c.s

CMakeFiles/SentenceGen.dir/tag.c.obj: CMakeFiles/SentenceGen.dir/flags.make
CMakeFiles/SentenceGen.dir/tag.c.obj: ../tag.c
CMakeFiles/SentenceGen.dir/tag.c.obj: CMakeFiles/SentenceGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SentenceGen.dir/tag.c.obj"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SentenceGen.dir/tag.c.obj -MF CMakeFiles\SentenceGen.dir\tag.c.obj.d -o CMakeFiles\SentenceGen.dir\tag.c.obj -c C:\Users\togla\OneDrive\Bureau\SentenceGen\tag.c

CMakeFiles/SentenceGen.dir/tag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SentenceGen.dir/tag.c.i"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\togla\OneDrive\Bureau\SentenceGen\tag.c > CMakeFiles\SentenceGen.dir\tag.c.i

CMakeFiles/SentenceGen.dir/tag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SentenceGen.dir/tag.c.s"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\togla\OneDrive\Bureau\SentenceGen\tag.c -o CMakeFiles\SentenceGen.dir\tag.c.s

CMakeFiles/SentenceGen.dir/menu.c.obj: CMakeFiles/SentenceGen.dir/flags.make
CMakeFiles/SentenceGen.dir/menu.c.obj: ../menu.c
CMakeFiles/SentenceGen.dir/menu.c.obj: CMakeFiles/SentenceGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SentenceGen.dir/menu.c.obj"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SentenceGen.dir/menu.c.obj -MF CMakeFiles\SentenceGen.dir\menu.c.obj.d -o CMakeFiles\SentenceGen.dir\menu.c.obj -c C:\Users\togla\OneDrive\Bureau\SentenceGen\menu.c

CMakeFiles/SentenceGen.dir/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SentenceGen.dir/menu.c.i"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\togla\OneDrive\Bureau\SentenceGen\menu.c > CMakeFiles\SentenceGen.dir\menu.c.i

CMakeFiles/SentenceGen.dir/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SentenceGen.dir/menu.c.s"
	C:\Users\togla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\togla\OneDrive\Bureau\SentenceGen\menu.c -o CMakeFiles\SentenceGen.dir\menu.c.s

# Object files for target SentenceGen
SentenceGen_OBJECTS = \
"CMakeFiles/SentenceGen.dir/main.c.obj" \
"CMakeFiles/SentenceGen.dir/struct.c.obj" \
"CMakeFiles/SentenceGen.dir/file.c.obj" \
"CMakeFiles/SentenceGen.dir/tag.c.obj" \
"CMakeFiles/SentenceGen.dir/menu.c.obj"

# External object files for target SentenceGen
SentenceGen_EXTERNAL_OBJECTS =

SentenceGen.exe: CMakeFiles/SentenceGen.dir/main.c.obj
SentenceGen.exe: CMakeFiles/SentenceGen.dir/struct.c.obj
SentenceGen.exe: CMakeFiles/SentenceGen.dir/file.c.obj
SentenceGen.exe: CMakeFiles/SentenceGen.dir/tag.c.obj
SentenceGen.exe: CMakeFiles/SentenceGen.dir/menu.c.obj
SentenceGen.exe: CMakeFiles/SentenceGen.dir/build.make
SentenceGen.exe: CMakeFiles/SentenceGen.dir/linklibs.rsp
SentenceGen.exe: CMakeFiles/SentenceGen.dir/objects1.rsp
SentenceGen.exe: CMakeFiles/SentenceGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable SentenceGen.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SentenceGen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SentenceGen.dir/build: SentenceGen.exe
.PHONY : CMakeFiles/SentenceGen.dir/build

CMakeFiles/SentenceGen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SentenceGen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SentenceGen.dir/clean

CMakeFiles/SentenceGen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\togla\OneDrive\Bureau\SentenceGen C:\Users\togla\OneDrive\Bureau\SentenceGen C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug C:\Users\togla\OneDrive\Bureau\SentenceGen\cmake-build-debug\CMakeFiles\SentenceGen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SentenceGen.dir/depend

