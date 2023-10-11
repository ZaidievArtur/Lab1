//
// Created by User on 04.10.2023.
//

#ifndef LAB1ALGOR_PROGRAM_H
#define LAB1ALGOR_PROGRAM_H

#include <iostream>
#include <string>
#include "Human.h"
#include "LinkedList.h"
#include <fstream>

class Program {
private:
    std::string fileName;
    List<Human> list;

    void readFile();

    void print();

    void filter();

public:
    void run();
};



#endif //LAB1ALGOR_PROGRAM_H
