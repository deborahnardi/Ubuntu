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

class SF_L3 : public ShapeFunction
{
private:

public:

    SF_L3();
    ~SF_L3();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};
class SF_L4 : public ShapeFunction
{
private:

public:

    SF_L4();
    ~SF_L4();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};

class SF_T3 : public ShapeFunction
{
private:

public:

    SF_T3();
    ~SF_T3();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};

class SF_T6 : public ShapeFunction
{
private:

public:

    SF_T6();
    ~SF_T6();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};

class SF_T10 : public ShapeFunction
{
private:

public:

    SF_T10();
    ~SF_T10();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};

class SF_TET10 : public ShapeFunction
{
public:
    SF_TET10();
    ~SF_TET10();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};

class SF_TET4 : public ShapeFunction
{
public:
    SF_TET4();
    ~SF_TET4();

    void evaluateShapeFunction(std::vector<double> &xi) override;
};