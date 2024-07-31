#pragma once

#include <iostream>
#include <vector>

#include "../../enumclass.hpp"

class Node
{
private:
    int index;
    std::vector<double> initialCoordinates;

public:
    Node();
    Node(const int &_index, const std::vector<double> &_initialCoordinates);
    ~Node();

    int getIndex()  {return index;}
    std::vector<double> getInitialCoordinates() {return initialCoordinates;}
    double getInitialCoordinates(int dir) {return initialCoordinates[dir];}

    void setindex(const int &_index) {index = _index;}
    void setInitialCoordinates(const std::vector<double> &_initialCoordinates) {initialCoordinates = _initialCoordinates;}
};