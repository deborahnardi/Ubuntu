#include "../headers/PlaneSurface.h"
#include <sstream>

PlaneSurface::PlaneSurface() {}
PlaneSurface::PlaneSurface(const int &index, const std::string &name, LineLoop *lineLoop, const bool &discretization)
    : Surface(index, name, lineLoop, discretization) {}
PlaneSurface::~PlaneSurface() {}

std::string PlaneSurface::getGmshCode()
{
    std::stringstream text;
    if (discretization)
        text << name << " = news; Plane Surface(" << name << ") = {" << lineLoop->getName() << "}; Physical Surface('" << name << "') = {" << name << "};\n//\n";
    else
        text << name << " = news; Plane Surface(" << name << ") = {" << lineLoop->getName() << "};\n//\n";
    
    return text.str();
}