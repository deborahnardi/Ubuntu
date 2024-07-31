#include "../headers/Circle.h"
#include <sstream>

Circle::Circle() {}
Circle::Circle(const int _index, const std::string _name, const std::vector<Point* > _points, const bool &_discretization)
        : Line(_index, _name, _points, _discretization) {}
Circle::~Circle() {}

std::string Circle::getGmshCode()
{
    std::stringstream text;
    if (discretization)
       text << name << " = newl; Circle(" << name << ") = {" << points[0]->getName() << ", " << points[1]->getName() << ", " << points[2]->getName() << "}; Physical Line('" << name << "') = {" << name << "};\n//\n";
    else
        text << name << " = newl; Circle(" << name << ") = {" << points[0]->getName() << ", " << points[1]->getName() << ", " << points[2]->getName() << "};\n//\n";
        
    return text.str();
}