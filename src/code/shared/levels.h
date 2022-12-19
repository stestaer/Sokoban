//
// Created by sacha on 19-12-22.
//
#include <string>

#ifndef F202_LEVELS_H
#define F202_LEVELS_H


struct levels{
    std::string lastCalled = level1;
    const std::string level1 = "../levels/level_1.txt";
    const std::string level2 = "../levels/level_2.txt";
    const std::string level3 = "../levels/level_3.txt";
};
#endif //F202_LEVELS_H
