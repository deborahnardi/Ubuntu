//Testing implemented quadrature

int intPoints = 6;

 ShapeFunction *sf = new SF_T3();
 //ShapeFunction *sf = new SF_L2();
 int nNodes = sf->getNumNodes();
 Quadrature *ql = new QuadTriangle(intPoints);
 //Quadrature *ql = new QuadLine(intPoints);
 double **paramCoords = ql->getParametricCoordinates();
 double *weight = ql->getWeights();
 
 VecDouble X[3];
 
 for (int i = 0; i < 3; i++)
     X[i] = VectorXd::Zero(2);
     
 X[0] << 5, -1;
 X[1] << 5, 5;
 X[2] << 10, 0;
 
 VecDouble x = VectorXd::Zero(2);
 MatDouble dX = MatrixXd::Zero(2,2);
 double integral = 0;
 
 for (int ip = 0; ip < intPoints; ip++)
 {
     x.setZero();
     dX.setZero();
     double *N = sf->evaluateShapeFunction(paramCoords[ip]);
     double **dN = sf->getShapeFunctionDerivative(paramCoords[ip]);
     for(int a = 0; a < nNodes ; a++)
     {
         for (int i = 0; i < 2; i++)
         {
             x(i) += X[a][i] * N[a];
             for (int j = 0; j < 2; j++)
             {
                 dX(i, j) += X[a][i] * dN[a][j];
             }
         }
     }
     double jac = std::abs(dX.determinant());
     integral += (3. * x(0) + 7. * x(1) - 2.) * jac * weight[ip];
 }
 std::cout << "Integral: " << integral << std::endl;