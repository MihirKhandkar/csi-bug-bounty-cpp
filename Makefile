CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Iutils
SRC := $(wildcard src/*.cpp) $(wildcard utils/*.cpp)
TARGET := wallet

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
