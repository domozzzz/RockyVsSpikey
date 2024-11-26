CC = gcc
CFLAGS = -Wall -g -IC:/MinGW_SDL/include/SDL2
LDFLAGS = -LC:/MinGW_SDL/lib -lmingw32 -lSDL2main -lSDL2
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/game.c $(SRC_DIR)/movement.c $(SRC_DIR)/render.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/rockyVsSpikey

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
