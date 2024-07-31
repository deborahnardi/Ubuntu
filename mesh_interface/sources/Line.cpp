/*
This file is a .cpp file that defines the Line class.
*/

#include "../headers/Line.h"
#include <sstream> // Include the header file for std::stringstream

Line::Line(){}
Line::Line(int _index, const std::string _name, const std::vector<Point* > _points, bool _discretization)
        :index(_index), name(_name), points(_points), discretization(_discretization) {}
Line::~Line() {}

std::string Line::getGmshCode()
{
    std::stringstream text;
    if (discretization)
    {
        text << name << " = newl; Line(" << name << ") = {" << points[0]->getName();

        for (int i = 1; i < points.size(); ++i)
            text << ", " << points[i]->getName();

        text << "}; Physical Line('" << name << "') = {" << name << "};\n//\n";
    }
    else 
        text << name << " = newl; Line(" << name << ") = {" << points[0]->getName() << ", " << points[1]->getName() << "};\n//\n";
    
    return text.str();
}

Line *Line::operator-()
{
    Line *copy = new Line(index, name, points, discretization);
    copy->setName("-" + name);
    return copy;
}