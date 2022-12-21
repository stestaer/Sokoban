CXX = g++
CXXFLAGS +=
LDFLAGS += -lfltk
BINS = $(patsubst %.cpp, %, $(wildcard *.cpp))

GUI = GUI/*.cpp
SHARED = shared/*.cpp
COMMON = *.cpp
LEVELS = ../levels/*.cpp

main: main.cpp
	g++ ${GUI} ${SHARED} ${COMMON} ${LEVELS} -o main ${LDFLAGS}

clean:
	rm main

