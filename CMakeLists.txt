cmake_minimum_required(VERSION 3.10)
project(Sierpinski3D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Set source files
set(SOURCES
    src/main.cpp
    src/Sierpinski.cpp
    src/helper.cpp
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
    lib/imgui/imgui.h
    lib/imgui/backends/imgui_impl_glut.h
    lib/imgui/backends/imgui_impl_opengl2.h
)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} lib/imgui lib/imgui/backends src)

# Create executable
add_executable(sierpinski3d ${SOURCES} ${HEADERS})

# Link OpenGL and GLUT
target_link_libraries(sierpinski3d ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
