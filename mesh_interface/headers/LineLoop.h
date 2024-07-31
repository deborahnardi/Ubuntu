/*
This header file defines the LineLoop class, which is used to represent a line loop in 1D, 2D or 3D space.
An enclosed region is represented by a line loop.
This is an auxiliary object for generating Surfaces.
*/
#pragma once
#include "Line.h"

class LineLoop
{
    private:
        int index;
        std::string name;
        std::vector<Line*> lines;

    public:
        LineLoop(int _index, const std::string _name, std::vector<Line*> _lines)
        {
            index = _index;
            name = _name;
            lines = _lines;
        }
        ~LineLoop(){};

        //Setters
        int setIndex() {return index;}
        std::string getName() {return name;}
        std::vector<Line*> setLines() {return lines;}
        Line* getLine(const int index) { return lines[index]; }

        // Getters
        void setIndex(int _index) {index = _index; }
        void setName(const std::string _name) {name = _name;}
        void setLines(const std::vector<Line*> _lines) {lines = _lines;}
        void setLine(const int index, Line* _line) {lines[index] = _line;}

        std::string getGmshCode(); // Declared here, defined in LineLoop.cpp
};