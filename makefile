CXX = clang++
CXXFLAGS = -Iinclude -std=c++23 -Wall -Wextra -O2
SRC = $(wildcard ./*.cpp src/Array/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = binary

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
