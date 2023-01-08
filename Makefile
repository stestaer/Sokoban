CC = g++
CFLAGS = -Isrc
LDFLAGS = -lfltk

EXE = sokoban

SRC = $(wildcard src/*.cpp src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(EXE)
