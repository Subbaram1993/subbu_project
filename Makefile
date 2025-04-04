# Compiler and flags
CXX = gcc
CFLAGS = -Wall -g

# Source and output directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
TOOLS_DIR = tools

# Find all C source files in the SRC_DIR
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Create corresponding object file names in OBJ_DIR
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target to build all object files
all: $(OBJ_FILES)
	@echo "Build complete!"

# Rule for compiling C files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Building $@"
	$(CXX) $(CFLAGS) -c $< -o $@

# Ensure OBJ_DIR exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Header Generation Tool
generate_headers: $(TOOLS_DIR)/generate_headers | $(INCLUDE_DIR)
	@echo "Generating header files..."
	@./tools/generate_headers

# Compile header generator tool
$(TOOLS_DIR)/generate_headers: $(TOOLS_DIR)/generate_headers.c | $(TOOLS_DIR)
	@echo "Compiling generate_headers tool..."
	$(CXX) $(CFLAGS) $< -o $@

# Ensure INCLUDE_DIR and TOOLS_DIR exist
$(INCLUDE_DIR):
	@mkdir -p $(INCLUDE_DIR)

$(TOOLS_DIR):
	@mkdir -p $(TOOLS_DIR)

# Clean up generated files
clean:
	@rm -rf $(OBJ_DIR) $(INCLUDE_DIR) $(TOOLS_DIR)/generate_headers
	@echo "Clean complete!"
