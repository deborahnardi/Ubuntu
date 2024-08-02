static char help[] = "Solves the phase-field problem using Finete Element Method "
                     "Start date: July 22nd, 2024 "
                     "Written by: Deborah Nardi"
                     "Advisor: Prof. Edson Denner Leonel"
                     "Co-advisor: Prof. Ayrton Ferreira"
                     "São Carlos School of Engineering - University of São Paulo";

#include "mesh_interface/headers/Geometry.h"
#include "FEM/headers/ShapeFunction.h"
#include "FEM/headers/Quadrature/Quadrature.h"
#include "FEM/headers/DenseEigen.h"

int main (int argc, char **args)
{
    PetscInitialize(&argc, &args, (char *)0, help); // Starts main program invoking PETSc

    //#include "examples/Example01.cpp"
    #include "examples/NumericalIntegration.cpp"

    PetscFinalize(); // Finalize main program
    return 0;
}