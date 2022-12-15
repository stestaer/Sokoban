CXX = g++
CXXFLAGS +=
LDFLAGS += -lfltk
BINS = $(patsubst %.cpp, %, $(wildcard *.cpp))

GUI = /GUI/CELL/*.cpp
SHARED = /

main: main.cpp
	g++ ${GUI} -o main ${LDFLAGS}

