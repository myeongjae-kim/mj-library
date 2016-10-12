# Compiler and Compile options.
C = gcc
# CFLAGS = -g -Wall

# Macros specifying path for compile.
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
BIN = ./bin/
INC = ./include/
LIB = ./lib/ -lpthread

# Pre-Processor.
CFLAGS += -I$(INC)

# Compile command.
TARGET = a.out
$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(BIN)$(TARGET) $(OBJS) -L$(LIB)
	$(BIN)$(TARGET)

# Delete binary & object files.
clean:
	rm $(BIN)$(TARGET) $(OBJS)
