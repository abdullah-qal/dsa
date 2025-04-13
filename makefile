CXX = clang++
CXXFLAGS = -ITree/include -std=c++23 -Wall -Wextra -O2
SRC = $(wildcard ./*.cpp Tree/src/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = binary

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
