/* 
    This header file defines the Line class, which is used to represent a line in 1D, 2D or 3D space.
*/
#pragma once

#include "Point.h"
#include "Material.h"

class Line 
{
    protected:
        int index;
        double area;
        std::string name;
        std::vector<Point*> points;
        Material *material = nullptr;
        bool discretization;
        ElementType elementType;

    public:
        Line();
        Line(int _index, const std::string _name, const std::vector<Point* > _points, bool _discretization);
        ~Line();
        
        // Getters
        int getIndex() {return index;}
        double getArea() { return area; }
        std::string getName() {return name;}
        std::vector<Point*> getPoints() {return points;}
        Point *getPoint(const int &index) { return points[index]; }
        bool getDiscretization() {return discretization;}
        Material *getMaterial() { return material; }
        ElementType getElementType() { return elementType; }

        // Setters
        void setIndex(int _index) {index = _index; }
        void setName(const std::string _name) {name = _name;}
        void setPoints(const std::vector<Point*> _points) {points = _points;}
        void setPoint(const int index, Point* _point) {points[index] = _point;}
        bool setDiscretization(bool _discretization) {discretization = _discretization;}

        std::string virtual getGmshCode(); // Declared here, defined in Line.cpp
        Line *operator-(); //Defines the unary operator - for the Line class, i.e, it returns a new Line object with the same points but in reverse order (due to the minus sign)
};