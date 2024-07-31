#include "../headers/SurfaceLoop.h"
#include <sstream>

std::string SurfaceLoop::getGmshCode()
{
    std::stringstream text;
    text << name << " = newsl; Surface Loop(" << name << ") = {";
    for (size_t i = 0; i < surfaces.size(); i++)
    {
        text << surfaces[i]->getName();
        if (i != (surfaces.size() - 1))
            text << ", ";
    }
    text << "};\n//\n";
    return text.str();
}