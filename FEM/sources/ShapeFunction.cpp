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

    dN[0][0] = 0.5;
    dN[1][0] = -0.5;

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
    
    parametricCoords[0][0] = -1;
    parametricCoords[1][0] = 1;
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
    
    parametricCoords[0][0] = -1;
    parametricCoords[1][0] = 0;
    parametricCoords[2][0] = 1;
}

// **********************************************************************************************************
//                                          L4 SHAPE FUNCTION
// **********************************************************************************************************
SF_L4::SF_L4(){ numNodes = 4; };
SF_L4::~SF_L4(){};

double *SF_L4::evaluateShapeFunction(double *&xi)
{
    double *N = new double[numNodes];

    N[0] = -(xi[0] - 1.) * (3 * xi[0] - 1.) * (3. * xi[0] + 1.) / 16.;
    N[1] = 9. * (xi[0] - 1.) * (xi[0] + 1.) * (3. * xi[0] - 1.) / 16.;
    N[2] = -9. * (xi[0] - 1.) * (xi[0] + 1.) * (3. * xi[0] + 1.) / 16.;
    N[3] = (xi[0] + 1.) * (3. * xi[0] - 1.) * (3 * xi[0] + 1.) / 16.;

    return N;
}

double **SF_L4::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double *[numNodes];
    for (int i=0; i < numNodes; i++)
    {
        dN[i] = new double[1];
    }

    dN[0][0] = (-27. * xi[0] * xi[0] + 18. * xi[0] + 1.) / 16.;
    dN[1][0] = 9. * (9. * xi[0] * xi[0] - 2. * xi[0] - 3.) / 16.;
    dN[2][0] = -9. * (9. * xi[0] * xi[0] + 2. * xi[0] - 3.) / 16.;
    dN[3][0] = (27. * xi[0] * xi[0] + 18. * xi[0] - 1.) / 16.;
}

void SF_L4::getNodalXi (double **&parametricCoords)
{
    parametricCoords = new double*[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[1];
    }

    parametricCoords[0][0] = -1;
    parametricCoords[1][0] = -1./3.;
    parametricCoords[2][0] = 1./3.;
    parametricCoords[3][0] = 1;
}

// **********************************************************************************************************
//                                          T3 SHAPE FUNCTION
// **********************************************************************************************************
SF_T3::SF_T3(){ numNodes = 3; };
SF_T3::~SF_T3(){};

double *SF_T3::evaluateShapeFunction(double *&xi)
{
    double *N = new double[numNodes];

    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = 1. - xi1 - xi2;

    N[0] = xi3;
    N[1] = xi1;
    N[2] = xi2;

    return N;
}

double **SF_T3::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double *[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        dN[i] = new double[2];
    }

    dN[0][0] = -1.;
    dN[1][0] = 1.;
    dN[2][0] = 0.;

    dN[0][1] = -1.;
    dN[1][1] = 0.;
    dN[2][1] = 1.;

    return dN;
}

void SF_T3::getNodalXi(double **&parametricCoords)
{
    parametricCoords = new double *[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[2];
    }

    parametricCoords[0][0] = 0.;
    parametricCoords[1][0] = 1.;
    parametricCoords[2][0] = 0.;

    parametricCoords[0][1] = 0.;
    parametricCoords[1][1] = 0.;
    parametricCoords[2][1] = 1.;
}

// **********************************************************************************************************
//                                          T3 SHAPE FUNCTION
// **********************************************************************************************************
SF_T6::SF_T6(){ numNodes = 6; };
SF_T6::~SF_T6(){};

double *SF_T6::evaluateShapeFunction(double *&xi)
{
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = 1. - xi1 - xi2;
    double *N = new double[numNodes];
    N[0] = xi3 * (2. * xi3 - 1.);
    N[1] = xi1 * (2. * xi1 - 1.);
    N[2] = xi2 * (2. * xi2 - 1.);
    N[3] = 4. * xi1 * xi3;
    N[4] = 4. * xi1 * xi2;
    N[5] = 4. * xi2 * xi3;
    return N;
}

double **SF_T6::getShapeFunctionDerivative(double *&xi)
{   
    double **dN = new double *[numNodes];
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = 1. - xi[0] - xi[1];

    for (int i = 0; i < numNodes; i++)
    {
        dN[i] = new double[2];
    }

    dN[0][0] = 1. - 4. * xi3;
    dN[1][0] = 4. * xi1 - 1.;
    dN[2][0] = 0.;
    dN[3][0] = 4. * (xi3 - xi1);
    dN[4][0] = 4. * xi2;
    dN[5][0] = -4. * xi2;

    dN[0][1] = 1. - 4. * xi3;
    dN[1][1] = 0.;
    dN[2][1] = 4. * xi2 - 1.;
    dN[3][1] = -4. * xi1;
    dN[4][1] = 4. * xi1;
    dN[5][1] = 4. * (xi3 - xi2);

    return dN;
}

void SF_T6::getNodalXi(double **&parametricCoords)
{
    parametricCoords = new double *[numNodes];

    for (int i = 0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[2];
    }

    parametricCoords[0][0] = 0.;
    parametricCoords[1][0] = 1.;
    parametricCoords[2][0] = 0.;
    parametricCoords[3][0] = 0.5;
    parametricCoords[4][0] = 0.5;
    parametricCoords[5][0] = 0.;

    parametricCoords[0][1] = 0.;
    parametricCoords[1][1] = 0.;
    parametricCoords[2][1] = 1.;
    parametricCoords[3][1] = 0.;
    parametricCoords[4][1] = 0.5;
    parametricCoords[5][1] = 0.5;
}

// **********************************************************************************************************
//                                          T10 SHAPE FUNCTION
// **********************************************************************************************************
SF_T10::SF_T10(){ numNodes = 10; };
SF_T10::~SF_T10(){};

double *SF_T10::evaluateShapeFunction(double *&xi)
{
    double *N = new double[numNodes];

    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = 1. - xi1 - xi2;

    N[0] = xi3 * (3. * xi3 - 2.) * (3. * xi3 - 1.) / 2.;
    N[1] = xi1 * (3. * xi1 - 2.) * (3. * xi1 - 1.) / 2.;
    N[2] = xi2 * (3. * xi2 - 2.) * (3. * xi2 - 1.) / 2.;
    N[3] = 9. * xi1 * xi3 * (3. * xi3 - 1.) / 2.;
    N[4] = 9. * xi1 * xi3 * (3. * xi1 - 1.) / 2.;
    N[5] = 9. * xi1 * xi2 * (3. * xi1 - 1.) / 2.;
    N[6] = 9. * xi1 * xi2 * (3. * xi2 - 1.) / 2.;
    N[7] = 9. * xi2 * xi3 * (3. * xi2 - 1.) / 2.;
    N[8] = 9. * xi2 * xi3 * (3. * xi3 - 1.) / 2.;
    N[9] = 27. * xi1 * xi2 * xi3;

    return N;
}

double **SF_T10::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double *[numNodes];
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = 1. - xi1 - xi2;

    for (int i=0; i < numNodes; i++)
    {
        dN[i] = new double[2];
    }

    dN[0][0] = (-27. * xi3 * xi3 + 18. * xi3 - 2.) / 2.;
    dN[1][0] = (27. * xi1 * xi1 - 18. * xi1 + 2.) / 2.;
    dN[2][0] = 0.;
    dN[3][0] = (27. * xi3 * (xi3 - 2. * xi1) + 9. * (xi1 - xi3)) / 2.;
    dN[4][0] = (27. * xi1 * (2. * xi3 - xi1) + 9. * (xi1 - xi3)) / 2.;
    dN[5][0] = 9. * xi2 * (6. * xi1 - 1.) / 2.;
    dN[6][0] = 9. * xi2 * (3. * xi2 - 1.) / 2.;
    dN[7][0] = -9. * xi2 * (3. * xi2 - 1.) / 2.;
    dN[8][0] = -9. * xi2 * (6. * xi3 - 1.) / 2.;
    dN[9][0] = 27. * xi2 * (xi3 - xi1);

    dN[0][1] = (-27. * xi3 * xi3 + 18. * xi3 - 2.) / 2.;
    dN[1][1] = 0.;
    dN[2][1] = (27. * xi2 * xi2 - 18. * xi2 + 2.) / 2.;
    dN[3][1] = (9. * xi1 * (1. - 6. * xi3)) / 2.;
    dN[4][1] = (-9. * xi1 * (3. * xi1 - 1.)) / 2.;
    dN[5][1] = (9. * xi1 * (3. * xi1 - 1.)) / 2.;
    dN[6][1] = (9. * xi1 * (6. * xi2 - 1.)) / 2.;
    dN[7][1] = (27. * xi2 * (2. * xi3 - xi2) + 9. * (xi2 - xi3)) / 2.;
    dN[8][1] = (27. * xi3 * (xi3 - 2. * xi2) + 9. * (xi2 - xi3)) / 2.;
    dN[9][1] = 27. * xi1 * (xi3 - xi2);

    return dN;
}

void SF_T10::getNodalXi(double **&parametricCoords)
{
    parametricCoords = new double *[numNodes];

    for (int i=0; i < numNodes; i++)
    {
        parametricCoords[i] = new double[2];
    }

    parametricCoords[0][0] = 0.;
    parametricCoords[1][0] = 1.;
    parametricCoords[2][0] = 0.;
    parametricCoords[3][0] = 1./3.;
    parametricCoords[4][0] = 2./3.;
    parametricCoords[5][0] = 2./3.;
    parametricCoords[6][0] = 1./3.;
    parametricCoords[7][0] = 0.;
    parametricCoords[8][0] = 0.;
    parametricCoords[9][0] = 1./3.;

    parametricCoords[0][1] = 0.;
    parametricCoords[1][1] = 0.;
    parametricCoords[2][1] = 1.;
    parametricCoords[3][1] = 0.;
    parametricCoords[4][1] = 0.;
    parametricCoords[5][1] = 1./3.;
    parametricCoords[6][1] = 2./3.;
    parametricCoords[7][1] = 2./3.;
    parametricCoords[8][1] = 1./3.;
    parametricCoords[9][1] = 1./3.;
}

// ===============================================
// ============= TET4 SHAPE FUNCTION =============
// ===============================================

SF_TET4::SF_TET4() { numNodes = 4; }
SF_TET4::~SF_TET4() {}

double *SF_TET4::evaluateShapeFunction(double *&xi)
{
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = xi[2];
    double xi4 = 1. - xi1 - xi2 - xi3;
    double *N = new double[numNodes];
    N[0] = xi4;
    N[1] = xi1;
    N[2] = xi2;
    N[3] = xi3;
    return N;
}

double **SF_TET4::getShapeFunctionDerivative(double *&xi)
{
    double **dN = new double *[numNodes];
    for (int i = 0; i < numNodes; i++)
        dN[i] = new double[3];

    dN[0][0] = -1.;
    dN[1][0] = 1.;
    dN[2][0] = 0.;
    dN[3][0] = 0.;

    dN[0][1] = -1.;
    dN[1][1] = 0.;
    dN[2][1] = 1.;
    dN[3][1] = 0.;

    dN[0][2] = -1.;
    dN[1][2] = 0.;
    dN[2][2] = 0.;
    dN[3][2] = 1.;

    return dN;
}

void SF_TET4::getNodalXi(double **&coord)
{
    coord = new double *[numNodes]
    {new double[3]{0., 0., 0.},
     new double[3]{1., 0., 0.},
     new double[3]{0., 1., 0.},
     new double[3]{0., 0., 1.} };
}

// ===============================================
// ============= TET10 SHAPE FUNCTION ============
// ===============================================

SF_TET10::SF_TET10() { numNodes = 10; }
SF_TET10::~SF_TET10() {}

double *SF_TET10::evaluateShapeFunction(double *&xi)
{
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = xi[2];
    double xi4 = 1. - xi1 - xi2 - xi3;
    double *N = new double[numNodes];
    N[0] = xi4 * (2. * xi4 - 1.);
    N[1] = xi1 * (2. * xi1 - 1.);
    N[2] = xi2 * (2. * xi2 - 1.);
    N[3] = xi3 * (2. * xi3 - 1.);
    N[4] = 4. * xi1 * xi4;
    N[5] = 4. * xi1 * xi2;
    N[6] = 4. * xi2 * xi4;
    N[7] = 4. * xi3 * xi4;
    N[8] = 4. * xi2 * xi3;
    N[9] = 4. * xi1 * xi3;
    return N;
}

double **SF_TET10::getShapeFunctionDerivative(double *&xi)
{
    double xi1 = xi[0];
    double xi2 = xi[1];
    double xi3 = xi[2];
    double xi4 = 1. - xi1 - xi2 - xi3;
    double **dN = new double *[numNodes];
    for (int i = 0; i < numNodes; i++)
        dN[i] = new double[3];

    dN[0][0] = 1. - 4. * xi4;
    dN[1][0] = 4. * xi1 - 1.;
    dN[2][0] = 0.;
    dN[3][0] = 0.;
    dN[4][0] = 4. * (xi4 - xi1);
    dN[5][0] = 4. * xi2;
    dN[6][0] = -4. * xi2;
    dN[7][0] = -4. * xi3;
    dN[8][0] = 0.;
    dN[9][0] = 4. * xi3;

    dN[0][1] = 1. - 4. * xi4;
    dN[1][1] = 0.;
    dN[2][1] = 4. * xi2 - 1.;
    dN[3][1] = 0.;
    dN[4][1] = -4. * xi1;
    dN[5][1] = 4. * xi1;
    dN[6][1] = 4. * (xi4 - xi2);
    dN[7][1] = -4. * xi3;
    dN[8][1] = 4. * xi3;
    dN[9][1] = 0.;

    dN[0][2] = 1. - 4. * xi4;
    dN[1][2] = 0.;
    dN[2][2] = 0.;
    dN[3][2] = 4. * xi3 - 1.;
    dN[4][2] = -4. * xi1;
    dN[5][2] = 0.;
    dN[6][2] = -4. * xi2;
    dN[7][2] = 4. * (xi4 - xi3);
    dN[8][2] = 4. * xi2;
    dN[9][2] = 4. * xi1;

    return dN;
}

void SF_TET10::getNodalXi(double **&coord)
{
    coord = new double *[numNodes]
    {new double[3]{0., 0., 0.},
     new double[3]{1., 0., 0.},
     new double[3]{0., 1., 0.},
     new double[3]{0., 0., 1.},
     new double[3]{0.5, 0., 0.},
     new double[3]{0.5, 0.5, 0.},
     new double[3]{0., 0.5, 0.},
     new double[3]{0., 0., 0.5},
     new double[3]{0., 0.5, 0.5},
     new double[3]{0.5, 0., 0.5} };
}