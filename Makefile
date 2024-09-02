# Compiler and flags
CXX = gcc
CFLAGS = -Wall -g

 # Source and output directories
 SRC_DIR = src
 OBJ_DIR = obj

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

# Clean up generated files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clean complete!"
