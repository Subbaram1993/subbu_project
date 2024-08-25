CXX = gcc
CFLAGS = -Wall -g

SRC = .
SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_FILES = $(patsubst $(SRC)/%.c,obj/%.o, $(SRC_FILES))

all: $(OBJ_FILES)
	@echo "done!"

obj/%.o: $(SRC)/%.c
	@echo "building $@"
	@$(CXX) -o $@ -c $< $(CFLAGS)