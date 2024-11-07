# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# OpenGL libraries
LDFLAGS = -lGL -lGLU -lglut

# Source files
SRC = main.cpp Sierpinski3D.cpp

# Header files
HEADERS = Sierpinski3D.h main.h

# Output executable
TARGET = sierpinski3d

# Build target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)
