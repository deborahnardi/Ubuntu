/*
This header file defines a class for a loop of surfaces, which generates a volume.
*/ 

#pragma once
#include "Surface.h"

class SurfaceLoop
{
private:
    int index;
    std::string name;
    std::vector<Surface*> surfaces;
public:
    SurfaceLoop(int _index, const std::string _name, std::vector<Surface*> _surfaces)
    {
        index = _index;
        name = _name;
        surfaces = _surfaces;
    }
    ~SurfaceLoop(){};	

    //Getters
    int getIndex() {return index;}
    std::string getName() {return name;}
    std::vector<Surface*> getSurfaces() {return surfaces;}
    Surface* getSurface (const int index) {return surfaces[index];}

    //Setters
    void setIndex(int _index) {index = _index;}
    void setName(const std::string _name) {name = _name;}
    void setSurfaces(const std::vector<Surface*> _surfaces) {surfaces = _surfaces;}

    std::string getGmshCode();
};