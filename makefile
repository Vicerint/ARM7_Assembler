

CC = g++
CFLAGS = -std=c++11
SRC = ARM.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = Assembler

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
