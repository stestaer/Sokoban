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
#include "MainWindow.h"

//int main(){
//    Board board{"../levels/level_1.txt"}; // add a path to load a matrix
//    board.printBoard();
//    return 0;
//}

int main(int argc, char *argv[]) {
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}