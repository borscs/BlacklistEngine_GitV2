# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/borscs/.local/share/JetBrains/Toolbox/apps/CLion/ch-1/183.2940.13/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/borscs/.local/share/JetBrains/Toolbox/apps/CLion/ch-1/183.2940.13/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/main.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/main.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/main.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/main.cpp

src/CMakeFiles/src.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/main.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/main.cpp > CMakeFiles/src.dir/main.cpp.i

src/CMakeFiles/src.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/main.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/main.cpp -o CMakeFiles/src.dir/main.cpp.s

src/CMakeFiles/src.dir/Database.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Database.cpp.o: ../src/Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/Database.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Database.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Database.cpp

src/CMakeFiles/src.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Database.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Database.cpp > CMakeFiles/src.dir/Database.cpp.i

src/CMakeFiles/src.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Database.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Database.cpp -o CMakeFiles/src.dir/Database.cpp.s

src/CMakeFiles/src.dir/Engine.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Engine.cpp.o: ../src/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/Engine.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Engine.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Engine.cpp

src/CMakeFiles/src.dir/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Engine.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Engine.cpp > CMakeFiles/src.dir/Engine.cpp.i

src/CMakeFiles/src.dir/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Engine.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/Engine.cpp -o CMakeFiles/src.dir/Engine.cpp.s

src/CMakeFiles/src.dir/EngineHandler.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/EngineHandler.cpp.o: ../src/EngineHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/EngineHandler.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/EngineHandler.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/EngineHandler.cpp

src/CMakeFiles/src.dir/EngineHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/EngineHandler.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/EngineHandler.cpp > CMakeFiles/src.dir/EngineHandler.cpp.i

src/CMakeFiles/src.dir/EngineHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/EngineHandler.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/EngineHandler.cpp -o CMakeFiles/src.dir/EngineHandler.cpp.s

src/CMakeFiles/src.dir/JsonHelper.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/JsonHelper.cpp.o: ../src/JsonHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/JsonHelper.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/JsonHelper.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/JsonHelper.cpp

src/CMakeFiles/src.dir/JsonHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/JsonHelper.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/JsonHelper.cpp > CMakeFiles/src.dir/JsonHelper.cpp.i

src/CMakeFiles/src.dir/JsonHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/JsonHelper.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src/JsonHelper.cpp -o CMakeFiles/src.dir/JsonHelper.cpp.s

src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o: src/src_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o -c /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src/src_autogen/mocs_compilation.cpp

src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.i"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src/src_autogen/mocs_compilation.cpp > CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.i

src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.s"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src/src_autogen/mocs_compilation.cpp -o CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/main.cpp.o" \
"CMakeFiles/src.dir/Database.cpp.o" \
"CMakeFiles/src.dir/Engine.cpp.o" \
"CMakeFiles/src.dir/EngineHandler.cpp.o" \
"CMakeFiles/src.dir/JsonHelper.cpp.o" \
"CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/src: src/CMakeFiles/src.dir/main.cpp.o
src/src: src/CMakeFiles/src.dir/Database.cpp.o
src/src: src/CMakeFiles/src.dir/Engine.cpp.o
src/src: src/CMakeFiles/src.dir/EngineHandler.cpp.o
src/src: src/CMakeFiles/src.dir/JsonHelper.cpp.o
src/src: src/CMakeFiles/src.dir/src_autogen/mocs_compilation.cpp.o
src/src: src/CMakeFiles/src.dir/build.make
src/src: /home/borscs/Qt/5.11.0/gcc_64/lib/libQt5Sql.so.5.11.0
src/src: /home/borscs/Qt/5.11.0/gcc_64/lib/libQt5Core.so.5.11.0
src/src: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable src"
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/src

.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2 /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/src /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src /home/borscs/Dokumentumok/opswat/BlacklistEngine_Cilion_Git_V2/cmake-build-debug/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

