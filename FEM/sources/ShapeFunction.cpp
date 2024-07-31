#include "../headers/ShapeFunction.h"

#include <iostream>

ShapeFunction::ShapeFunction() {}
ShapeFunction::~ShapeFunction() {}

// **********************************************************************************************************
//                                          L3 SHAPE FUNCTION
// **********************************************************************************************************

SF_L2::SF_L2() { numNodes = 2; }
SF_L2::~SF_L2() {}

double *SF_L2::evaluateShapeFunction(double *&xi) 
{
    //*&xi is a pointer to an array of doubles and depends on the number of integration points
    
    double *N = new double[numNodes];
    N[0] = 0.5 * (1 - xi[0]); //xi[0] is the parametric coordinate in the x direction
    N[1] = 0.5 * (1 + xi[0]);
    return N;
}

double **SF_L2::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double*[numNodes]; //Number of lines of the "matrix"

    for (int i = 0; i < numNodes ; i++)
    {
        dN[i] = new double[1]; // Setting the number of columns of the "matrix"
    }

    dN[0][1] = 0.5;
    dN[0][1] = -0.5;

    return dN;
}

void SF_L2::getNodalXi(double **&parametricCoords) 
{
    //Gets nodal parametric coordinates

    parametricCoords = new double*[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[1];
    };
    
    parametricCoords[0][1] = -1;
    parametricCoords[1][1] = 1;
}

// **********************************************************************************************************
//                                          L3 SHAPE FUNCTION
// **********************************************************************************************************
SF_L3::SF_L3(){ numNodes = 3; };
SF_L3::~SF_L3(){};

double *SF_L3::evaluateShapeFunction(double *&xi)
{
    double *N = new double[numNodes];

    N[0] = 0.5 * xi[0] * (xi[0] - 1.);
    N[1] = 1. - xi[0] * xi[0],
    N[2] = 0.5 * xi[0] * (xi[0] + 1.);
    return N;
}

double **SF_L3::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double *[numNodes];

    for(int i = 0; i < numNodes; i++)
    {
        dN[i] = new double[1];
    }

    dN[0][0] = xi[0] - 0.5;
    dN[1][0] = - xi[0];
    dN[2][0] = xi[0] + 0.5;
}

void SF_L3::getNodalXi(double **&parametricCoords) 
{
    //Gets nodal parametric coordinates

    parametricCoords = new double*[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[1];
    };
    
    parametricCoords[0][1] = -1;
    parametricCoords[1][1] = 0;
    parametricCoords[2][1] = 1;
}

// **********************************************************************************************************
//                                          L4 SHAPE FUNCTION
// **********************************************************************************************************
SF_L4::SF_L4(){ numNodes = 4; };
SF_L4::~SF_L4(){};

double *SF_L4::evaluateShapeFunction(double *&xi)
{

}