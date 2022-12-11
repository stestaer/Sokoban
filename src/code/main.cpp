//
// Created by sacha on 11-11-22.
//

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>

#include "Board.h"
#include "GUI/MainWindow.h"

//int main.o(){
//    Board board{"../levels/level_1.txt"}; // add a path to load a matrix
//    board.printBoard();
//    return 0;
//}

int main(int argc, char *argv[]) {
    srand(static_cast<unsigned>(time(nullptr)));
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}