/* 
    This header file defines a subclass of the Surface class, which is used to represent a plane surface in 2D space.
*/

#include "Surface.h"

class PlaneSurface : public Surface
{
public:
    PlaneSurface();
    PlaneSurface(const int &index, const std::string &name, LineLoop *lineLoop, const bool &discretization = true);
    ~PlaneSurface();

    std::string getGmshCode() override;
};