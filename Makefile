# _*_ MakeFile _*_

CC     := g++
CFLAGS := -w -g -Wall

SRC    := src
BIN    := bin
BUILD  := build

SOURCE := $(shell find $(SRC) -type f -regex ".*\.cpp")
OBJECT := $(patsubst %, $(BUILD)/%, $(notdir $(SOURCE:.cpp=.cpp.o)))

.PHONY: all clean

TARGET := cpu

all: $(TARGET)

$(BUILD)/%.cpp.o: $(SRC)/%.cpp
	@echo "Building: $@"; $(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(TARGET): $(OBJECT)
	@echo "Linking: $@"; $(CC) $^ -o $(TARGET) $(LIB)

clean:
	@echo "Cleaning $(TARGET), $(BUILD)"; $(RM) -rf $(OBJECT) $(TARGET)

