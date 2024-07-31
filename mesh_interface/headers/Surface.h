/* 
This header file defines the Surface class, which is used to represent a surface in 1D, 2D or 3D space.
*/

#pragma once
#include "LineLoop.h"
#include "Material.h"

class Surface
{
    protected: // not private so other subclasses can access it
        int index;
        std::string name;
        LineLoop* lineLoop;
        double ldimension;
        double thickness;
        bool discretization;
        Material *material = nullptr;
        ElementType elementType;

    public:
        Surface();
        Surface(int _index, std::string _name, LineLoop* _lineLoop, const bool &_discretization);
        ~Surface();

        //Setters
        int getIndex() {return index;}
        double getThickness() { return thickness; }
        std::string getName() {return name;}
        LineLoop* getLineLoop() {return lineLoop;}
        bool getDiscretization() {return discretization;}
        Material *getMaterial() { return material; }
        ElementType getElementType() { return elementType; }
        
        // Getters
        void getIndex(int _index) {index = _index; }
        void setName(const std::string _name) {name = _name;}
        void setLineLoop(LineLoop *&_lineLoop) {lineLoop = _lineLoop;}

        std::string virtual getGmshCode(); //virtual because it will be overriden by subclasses
        Surface *operator-();
};