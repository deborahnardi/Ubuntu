/* 
    This header file defines the Volume class, which is used to represent a volume of the element.
*/

#pragma once

#include "SurfaceLoop.h"
#include "Material.h"  
#include "../../enumclass.hpp"

class Volume {
    private:
        int index;
        std::string name;
        SurfaceLoop* surfaceLoop;
        bool discretization;
        Material *material = nullptr;
        ElementType elementType;

    public:
        Volume(const int &_index, const std::string &_name, SurfaceLoop *_surfaceLoop, const bool &_discretization)
        {
            index = _index;
            name = _name;
            surfaceLoop = _surfaceLoop;
            discretization = _discretization;
        }

        ~Volume(){};

        //Setters

        int getIndex() {return index;}
        std::string getName() {return name;}
        SurfaceLoop *getSurfaceLoop() {return surfaceLoop;}
        bool getDiscretization() {return discretization;}
        Material *getMaterial() { return material; }
        ElementType getElementType() { return elementType; }

        // Getters
        void setIndex(int _index) {index = _index; }
        void setName(const std::string _name) {name = _name;}
        void setSurfaceLoop(SurfaceLoop *_surfaceLoop) {surfaceLoop = _surfaceLoop;}
        void setDiscretization(bool _discretization) {discretization = _discretization;}

        std::string getGmshCode();
};