#pragma once

#include <math.h>

class Quadrature
{
protected:

    int numIntegrationPoints;
    double **paramCoordinates;
    double *weights;

public:
    Quadrature();
    Quadrature(int numIntegrationPoints);
    ~Quadrature();

    virtual void getQuadrature() {};
    double **getParametricCoordinates() {return paramCoordinates;}
    double *getWeights() {return weights;}
};

class QuadLine : public Quadrature
{
public:
    QuadLine();
    QuadLine(int numIntegrationPoints);
    ~QuadLine();

    void getQuadrature() override;

};

class QuadTriangle : public Quadrature
{
public:
    QuadTriangle();
    QuadTriangle(int numIntegrationPoints);
    ~QuadTriangle();

    void getQuadrature() override;
};

class QuadTetrahedron : public Quadrature
{
public:
    QuadTetrahedron();
    QuadTetrahedron(int numIntegrationPoints);
    ~QuadTetrahedron();

    void getQuadrature() override;
};