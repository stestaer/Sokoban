CXX = g++
CXXFLAGS +=
LDFLAGS += -lfltk
BINS = $(patsubst %.cpp, %, $(wildcard *.cpp))

GUI = GUI/*.cpp
SHARED = shared/*.cpp
COMMON = *.cpp

main: main.cpp
	g++ ${GUI} ${SHARED} ${COMMON} -o main ${LDFLAGS}

clean:
	rm main

