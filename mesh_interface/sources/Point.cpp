/*
This file is a .cpp file that defines the Point class.
*/

#include "../headers/Point.h"
#include <sstream>

/*
Pattern: type class::function, for example: std::string (type), Point (class) :: getGmshCode() (function)
*/

std::string Point::getGmshCode() //Defined here, declared in .h
{
    std::stringstream text; // Used for formating and converting data from and to strings - Fluxe of data
    text << std::fixed;     // Manipulation of floating numbers

    if(discretization)  //if == true
        text << name << " = newp; Point(" << name << ") = {" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ", " << ldimension << "}; Physical Point('" << name << "') = {" << name << "};\n//\n";
    else
        text << name << " = newp; Point(" << name << ") = {" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ", " << ldimension << "};\n//\n";

    return text.str(); // .str() :: Return object of type std::stringstream
}