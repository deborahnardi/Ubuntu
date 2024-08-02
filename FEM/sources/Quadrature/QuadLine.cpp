#include "../../headers/Quadrature/Quadrature.h"

// paramCoordinates --> [ endereço de array 1, endereço de array 2, ... , endereço de array numRows ]
// 
// endereço de array 1 --> [ valor, valor, ..., valor ]
// endereço de array 2 --> [ valor, valor, ..., valor ]
// caso seja new double[2] tem-se
//coordinates --> [ endereço de array 1, endereço de array 2, endereço de array 3 ]

// endereço de array 1 --> [ valor1, valor2 ]
// endereço de array 2 --> [ valor3, valor4 ]
// endereço de array 3 --> [ valor5, valor6 ]
// ...

//weights --> [ 0.0, 1.0, 2.0, 3.0, 4.0 ] diretamente os valores


QuadLine::QuadLine() {}
QuadLine::QuadLine(int numIntegrationPoints)
        : Quadrature(numIntegrationPoints) 
        {
            weights = new double[numIntegrationPoints]; //Setting up the memory for the weights
            paramCoordinates = new double*[numIntegrationPoints]; //Setting up the memory for the parametric paramCoordinates
            for (int i = 0; i < numIntegrationPoints; i++)
            {
                paramCoordinates[i] = new double[1]; //Setting up the memory for the parametric paramCoordinates
            }
            getQuadrature(); //Calling the getQuadrature function, so the user doesn't have to call it
        }
QuadLine::~QuadLine() {}

void QuadLine::getQuadrature()
{
    //Gauss-Legendre Quadrature according to the number of integration points

    double xmga = 0.0, xlga = 1.0, zga, p1ga, p2ga, p3ga, ppga, z1ga;
    int mga = (numIntegrationPoints + 1) / 2;

    for (int iga = 1; iga <= mga; iga++)
    {
        zga = std::cos(M_PI * (double(iga) - 0.25) / (double(numIntegrationPoints) + 0.5));
    g1:
        p1ga = 1.0;
        p2ga = 0.0;
        for (int jga = 1; jga <= numIntegrationPoints; jga++)
        {
            p3ga = p2ga;
            p2ga = p1ga;
            p1ga = ((2.0 * double(jga) - 1.0) * zga * p2ga - (double(jga) - 1.0) * p3ga) / (double(jga));
        }

        ppga = numIntegrationPoints * (zga * p1ga - p2ga) / (zga * zga - 1.0);
        z1ga = zga;
        zga = z1ga - p1ga / ppga;

        if (fabs(zga - z1ga) > 1.0e-15)
            goto g1;

        paramCoordinates[iga - 1][0] = xmga - xlga * zga;
        paramCoordinates[numIntegrationPoints - iga][0] = xmga + xlga * zga;

        weights[iga - 1] = 2.0 * xlga / ((1.0 - zga * zga) * ppga * ppga);
        weights[numIntegrationPoints - iga] = weights[iga - 1];
    }
}