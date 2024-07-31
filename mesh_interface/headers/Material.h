#pragma once

#include "../../enumclass.hpp"

class Material
{
private:
    int index;
    double young;
    double poisson;
    double shearModulus;
    double density;
    PlaneAnalysis planeAnalysis;

public:
    Material();
    Material(int _index, double _young, double _poisson, PlaneAnalysis _planeAnalysis = PLANE_STRESS);
    ~Material();

    //Getters
    int getIndex() const {return index;}
    double getYoungModulus() const {return young;}
    double getPoisson() const {return poisson;}
    double getShearModulus() const {return shearModulus;}
    double getDensity() const {return density;}
    PlaneAnalysis getPlaneAnalysis() const {return planeAnalysis;}

    //Setters
    void setIndex(int _index) {index = _index;}
    void setYoungModulus(double _young) {young = _young;}
    void setPoisson(double _poisson) {poisson = _poisson;}
    void setPlaneAnalysis(PlaneAnalysis _planeAnalysis) {planeAnalysis = _planeAnalysis;}
};