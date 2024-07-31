#include "../headers/LineLoop.h"
#include <sstream>

std::string LineLoop::getGmshCode()
{
    std::stringstream text;
    text << name << " = newll; Line Loop(" << name << ") = {";
    
    for(size_t i=0; i < lines.size(); i++) //size_t due to the size of the vector
    {
        text << lines[i]->getName();
        if (i != ( lines.size()-1 )) //verifies if i is different from the last element in vector lines
            text << ", ";
    } 
    text << "};\n//\n";
    return text.str();
}