# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build

# Include any dependencies generated for this target.
include CMakeFiles/sierpinski3d.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sierpinski3d.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sierpinski3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sierpinski3d.dir/flags.make

CMakeFiles/sierpinski3d.dir/src/main.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/sierpinski3d.dir/src/main.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sierpinski3d.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/main.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/main.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/main.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/main.cpp

CMakeFiles/sierpinski3d.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/main.cpp > CMakeFiles/sierpinski3d.dir/src/main.cpp.i

CMakeFiles/sierpinski3d.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/main.cpp -o CMakeFiles/sierpinski3d.dir/src/main.cpp.s

CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o: ../src/Sierpinski.cpp
CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Sierpinski.cpp

CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Sierpinski.cpp > CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.i

CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Sierpinski.cpp -o CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.s

CMakeFiles/sierpinski3d.dir/src/helper.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/helper.cpp.o: ../src/helper.cpp
CMakeFiles/sierpinski3d.dir/src/helper.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sierpinski3d.dir/src/helper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/helper.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/helper.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/helper.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/helper.cpp

CMakeFiles/sierpinski3d.dir/src/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/helper.cpp > CMakeFiles/sierpinski3d.dir/src/helper.cpp.i

CMakeFiles/sierpinski3d.dir/src/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/helper.cpp -o CMakeFiles/sierpinski3d.dir/src/helper.cpp.s

CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o: ../src/Axes.cpp
CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Axes.cpp

CMakeFiles/sierpinski3d.dir/src/Axes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/Axes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Axes.cpp > CMakeFiles/sierpinski3d.dir/src/Axes.cpp.i

CMakeFiles/sierpinski3d.dir/src/Axes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/Axes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Axes.cpp -o CMakeFiles/sierpinski3d.dir/src/Axes.cpp.s

CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o: ../src/Camera.cpp
CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Camera.cpp

CMakeFiles/sierpinski3d.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Camera.cpp > CMakeFiles/sierpinski3d.dir/src/Camera.cpp.i

CMakeFiles/sierpinski3d.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Camera.cpp -o CMakeFiles/sierpinski3d.dir/src/Camera.cpp.s

CMakeFiles/sierpinski3d.dir/src/Console.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/src/Console.cpp.o: ../src/Console.cpp
CMakeFiles/sierpinski3d.dir/src/Console.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sierpinski3d.dir/src/Console.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/src/Console.cpp.o -MF CMakeFiles/sierpinski3d.dir/src/Console.cpp.o.d -o CMakeFiles/sierpinski3d.dir/src/Console.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Console.cpp

CMakeFiles/sierpinski3d.dir/src/Console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/src/Console.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Console.cpp > CMakeFiles/sierpinski3d.dir/src/Console.cpp.i

CMakeFiles/sierpinski3d.dir/src/Console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/src/Console.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/src/Console.cpp -o CMakeFiles/sierpinski3d.dir/src/Console.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o: ../lib/imgui/imgui.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o: ../lib/imgui/imgui_demo.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_demo.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_demo.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_demo.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o: ../lib/imgui/imgui_draw.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_draw.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_draw.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_draw.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o: ../lib/imgui/imgui_widgets.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_widgets.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_widgets.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_widgets.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o: ../lib/imgui/imgui_tables.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_tables.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_tables.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/imgui_tables.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o: ../lib/imgui/backends/imgui_impl_glut.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_glut.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_glut.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_glut.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.s

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o: CMakeFiles/sierpinski3d.dir/flags.make
CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o: ../lib/imgui/backends/imgui_impl_opengl2.cpp
CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o: CMakeFiles/sierpinski3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o -MF CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o.d -o CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o -c /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_opengl2.cpp

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_opengl2.cpp > CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.i

CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/lib/imgui/backends/imgui_impl_opengl2.cpp -o CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.s

# Object files for target sierpinski3d
sierpinski3d_OBJECTS = \
"CMakeFiles/sierpinski3d.dir/src/main.cpp.o" \
"CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o" \
"CMakeFiles/sierpinski3d.dir/src/helper.cpp.o" \
"CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o" \
"CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o" \
"CMakeFiles/sierpinski3d.dir/src/Console.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o" \
"CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o"

# External object files for target sierpinski3d
sierpinski3d_EXTERNAL_OBJECTS =

bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/main.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/Sierpinski.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/helper.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/Axes.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/Camera.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/src/Console.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/imgui.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_demo.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_draw.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_widgets.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/imgui_tables.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_glut.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/lib/imgui/backends/imgui_impl_opengl2.cpp.o
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/build.make
bin/sierpinski3d: /usr/lib/x86_64-linux-gnu/libGL.so
bin/sierpinski3d: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/sierpinski3d: /usr/lib/x86_64-linux-gnu/libglut.so
bin/sierpinski3d: /usr/lib/x86_64-linux-gnu/libXmu.so
bin/sierpinski3d: /usr/lib/x86_64-linux-gnu/libXi.so
bin/sierpinski3d: CMakeFiles/sierpinski3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable bin/sierpinski3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sierpinski3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sierpinski3d.dir/build: bin/sierpinski3d
.PHONY : CMakeFiles/sierpinski3d.dir/build

CMakeFiles/sierpinski3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sierpinski3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sierpinski3d.dir/clean

CMakeFiles/sierpinski3d.dir/depend:
	cd /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build /home/ege/Desktop/gsu2025/graphics/project/Sierpinski3D/build/CMakeFiles/sierpinski3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sierpinski3d.dir/depend

