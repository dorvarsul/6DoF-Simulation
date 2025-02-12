# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = .
COMP_DIR = components
OBJ_DIR = obj

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
COMP_FILES = $(wildcard $(COMP_DIR)/*.cpp)
ALL_FILES = $(SRC_FILES) $(COMP_FILES)

# Object files (placing .o files inside obj/)
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(ALL_FILES))

# Target executable
TARGET = missile_simulator

# Ensure obj directories exist
$(shell mkdir -p $(OBJ_DIR)/$(COMP_DIR))

# Build target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source and component files into object files
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure object files inside Components/ go into obj/Components/
$(OBJ_DIR)/$(COMP_DIR)/%.o: $(COMP_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all
