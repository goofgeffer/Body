# Project Name
TARGET = body

# Directories
SRC_DIR = src
INC_DIR = include

# Find all .c files in the src/ directory
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -std=c99 -I$(INC_DIR)

# Detect Operating System and set platform-specific flags
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    # Direct link to local static library in root folder
    LIBS = libraylib.a -lopengl32 -lgdi32 -lwinmm
else
    # Unix-based (Linux / macOS)
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        # macOS linking
        LIBS = libraylib.a -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    else
        # Linux linking
        LIBS = libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11
    endif
endif

# Default Build Rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(TARGET)

# Compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the executable after building
run: all
	./$(TARGET)

# Clean up build artifacts (Platform-safe)
clean:
ifeq ($(OS),Windows_NT)
	-@del /q src\*.o 2>nul
	-@del /q $(TARGET) 2>nul
else
	rm -f $(SRC_DIR)/*.o $(TARGET)
endif

.PHONY: all run clean