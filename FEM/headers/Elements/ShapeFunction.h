#pragma once

#include <vector>
#include <string>

class ShapeFunction
{
protected:

public:
    ShapeFunction();
    ~ShapeFunction();

    void virtual evaluateShapeFunction(std::vector<double> &xi);
    virtual double **getShapeFunctionDerivative(); // ** is a Matrix
    /*
    virtual double **getShapeFunctionDerivative() is equivalent to std::vector<std::vector<double>> but one
    has control over memory allocation
     */
};

class SF_L2 : public ShapeFunction
{
private:

public:

    SF_L2();
    ~SF_L2();

    void evaluateShapeFunction(std::vector<double> &xi) override;
    /*
    If override is not written, the base version will be used
    */
};