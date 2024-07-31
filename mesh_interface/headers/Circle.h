/* 
    This header file defines a subclass of the Line class, which is used to represent a circle in 2D space.
*/
#pragma once

#include "Line.h"

class Circle : public Line
{
    public:
        Circle();
        Circle(const int _index, const std::string _name, const std::vector<Point* > _points, const bool &_discretization);
        ~Circle();

        Circle *operator-();
        Point *getCenter() {return points[1];}
        std::vector<Point*> getPoints() {return points;}

        void setCenter(Point* _center) {points[1] = _center;}
        
        std::string getGmshCode() override; // Declared here, defined in Circle.cpp
};