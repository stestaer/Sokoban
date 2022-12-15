//
// Created by sacha on 09-12-22.
//

#ifndef F202_UI_H
#define F202_UI_H


class Ui {
    shared_ptr<Board> board;

public:
    Ui(shared_ptr<Board> board): board{board}{};
    void display(); // for each cell in cells, cell->draw
};


#endif //F202_UI_H
