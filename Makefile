# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = missile
COMP_DIR = missile/components
OBJ_DIR = obj

# Source files
MAIN_SRC = main.cpp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
COMP_FILES = $(wildcard $(COMP_DIR)/*.cpp)
ALL_FILES = $(MAIN_SRC) $(SRC_FILES) $(COMP_FILES)

# Object files (placing .o files inside obj/)
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(ALL_FILES))

# Target executable
TARGET = missile_simulator

# Ensure obj directories exist
$(shell mkdir -p $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(COMP_DIR))

# Build target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile main.cpp separately
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile source files into object files
$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile component files into object files
$(OBJ_DIR)/$(COMP_DIR)/%.o: $(COMP_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all
