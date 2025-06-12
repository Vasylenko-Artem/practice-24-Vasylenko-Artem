CPP := g++
CPPFLAGS := -std=c++20 -g -Wall -Wextra -Wpedantic -Wshadow -Wunused-variable -Wuninitialized -Wconversion -Wdeprecated-declarations -Wformat -Wswitch -Wvla -Wunreachable-code -fsanitize=address
INCLUDES := -Iinclude -Isrc

LDFLAGS := -lncurses 

BUILD_DIR := build

SRC_DIR := src
TARGET := $(BUILD_DIR)/main

SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

TEST_DIR := test
TEST_TARGET := $(BUILD_DIR)/testProgram

TEST_SRCS := $(shell find $(TEST_DIR) -name "*.cpp")
TEST_OBJS := $(filter-out $(BUILD_DIR)/src/main.o, $(OBJS) $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o))

.PHONY: all build run clean test init

all: build run

init:
	@mkdir -p $(SRC_DIR) $(TEST_DIR) $(BUILD_DIR) include
	@test -f $(SRC_DIR)/main.cpp || echo '#include <iostream>\n\nint main() {\n    std::cout << "Hello, World!" << std::endl;\n    return 0;\n}' > $(SRC_DIR)/main.cpp
	@test -f include/utils.h || echo '// Example header\n#pragma once\n\nvoid hello();' > include/utils.h
	@test -f $(TEST_DIR)/app.cpp || echo '#include <iostream>\n\nint main() {\n    std::cout << "Running tests..." << std::endl;\n    return 0;\n}' > $(TEST_DIR)/main.cpp
	@echo "Project structure initialized."

build: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CPPFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

test: $(TEST_TARGET)
	@$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CPPFLAGS) $(INCLUDES) $(TEST_OBJS) $(LDFLAGS) -o $(TEST_TARGET)

run: build
	@$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)