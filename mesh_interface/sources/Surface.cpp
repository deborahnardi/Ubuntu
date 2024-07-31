#include "../headers/Surface.h"
#include <sstream>

Surface::Surface() {}
Surface::Surface(int _index, std::string _name, LineLoop* _lineLoop, const bool &_discretization)
        :index(_index), name(_name), lineLoop(_lineLoop), discretization(_discretization) {}
Surface::~Surface(){}

std::string Surface::getGmshCode()
{
    std::stringstream text;
    if (discretization)
        text << name << " = news; Surface(" << name << ") = {" << lineLoop->getName() << "}; Physical Surface('" << name << "') = {" << name << "};\n//\n";
    else
        text << name << " = news; Surface(" << name << ") = {" << lineLoop->getName() << "};\n//\n";
    
    return text.str();
}