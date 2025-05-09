# 编译器和编译选项
CC = g++
CFLAGS = -std=c++20 -Wall -ggdb

# 调试模式（默认）

SRC_DIR = .
BUILD_DIR = build
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/functions.cpp \
      $(SRC_DIR)/array.cpp \
      $(SRC_DIR)/linklist.cpp \
      $(SRC_DIR)/hashtable.cpp \
      $(SRC_DIR)/string.cpp \
      $(SRC_DIR)/stack-and-queue.cpp \

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
EXEC = main

# 默认目标
all: $(BUILD_DIR)/$(EXEC)

# 链接生成可执行文件
$(BUILD_DIR)/$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# 编译规则
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理构建产物
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

