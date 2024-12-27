cmake_minimum_required(VERSION 3.10)
project(Sierpinski3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_compile_options(-Wall)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Manually specify source files to exclude unnecessary backends
set(SOURCES
    src/main.cpp
    src/Sierpinski.cpp
    src/helper.cpp
    src/Axes.cpp
    src/Camera.cpp
    src/Console.cpp
    lib/imgui/imgui.cpp
    lib/imgui/imgui_demo.cpp
    lib/imgui/imgui_draw.cpp
    lib/imgui/imgui_widgets.cpp
    lib/imgui/imgui_tables.cpp
    lib/imgui/backends/imgui_impl_glut.cpp
    lib/imgui/backends/imgui_impl_opengl2.cpp
)

set(HEADERS
    src/main.h
    src/Sierpinski.h
    src/helper.h
    src/Axes.h
    src/Camera.h
    src/Console.h
    lib/imgui/imgui.h
    lib/imgui/backends/imgui_impl_glut.h
    lib/imgui/backends/imgui_impl_opengl2.h
)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} lib/imgui lib/imgui/backends src)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create executable
add_executable(openviz ${SOURCES} ${HEADERS})

# Link OpenGL and GLUT
target_link_libraries(openviz ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
