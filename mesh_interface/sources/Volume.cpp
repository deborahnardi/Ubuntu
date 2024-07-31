#include "../headers/Volume.h"
#include <sstream>

std::string Volume::getGmshCode()
{
    std::stringstream text;
    if (discretization)
        text << name << " = newv; Volume(" << name << ") = {" << surfaceLoop->getName() << "}; Physical Volume('" << name << "') = {" << name << "};\n//\n";
    else
        text << name << " = newv; Volume(" << name << ") = {" << surfaceLoop->getName() << "};\n//\n";
    return text.str();
}