TARGET = rlg
SRC_DIR = src
OBJ_DIR = obj
TARGET_DIR = bin
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
CXX = g++
CXXFLAGS += -Wall
LDFLAGS += -lncurses -ggdb

.PHONY: all clean

default: all

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking "$(TARGET_DIR)/$(TARGET)":..." 
	$(CXX) $^ -o $(TARGET_DIR)/$(TARGET) $(LDFLAGS)
	@echo 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\n*****Compiling "$< "to" $@"*****"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo

clean: 
	@echo "Cleaning up" $(OBJ_DIR) "and" $(TARGET_DIR) "...\n"
	rm $(OBJ)
	rm $(TARGET_DIR)/$(TARGET)

