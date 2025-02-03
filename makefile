# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Include Eigen directory
INCLUDES = -I/usr/include/eigen3

# Source files
SRC = missile.cpp
OBJ = $(SRC:.cpp=.o)
EXE = missile_sim

# Build executable
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXE)

# Compile source files
%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(EXE)