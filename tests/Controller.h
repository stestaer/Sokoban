//
// Created by sacha on 09-12-22.
//

#ifndef F202_CONTROLLER_H
#define F202_CONTROLLER_H


class Controller {
    shared_ptr<Board> board;

public:
        Controller(shared_ptr<Board> board): board{board}{};
        void processKey();
};


#endif //F202_CONTROLLER_H
