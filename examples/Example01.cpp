/*
EXAMPLE 01 - UNDERSTANDING HOW .GEO FILE IS GENERATED AND .MSH FILE IS OBTAINED
             THIS EXAMPLE TREATS A SQUARE WITHIN A HOLE
*/
#include "../mesh_interface/headers/Geometry.h" // Update the include path to the correct location of the header file

std::string projectName = "exemplo1";
Geometry *ex01 = new Geometry(projectName);

double L=5., H=5., R=1.; // Separate the variable declarations with commas

std::vector<Point *> ex01Points;
std::vector<Line *> ex01Lines;
std::vector<Surface *> ex01Surfaces;
std::vector<BoundaryCondition *> ex01BCs;

ex01Points.push_back(ex01->addPoint({0., 0., 0.}));
ex01Points.push_back(ex01->addPoint({L, 0., 0.}));
ex01Points.push_back(ex01->addPoint({L, H, 0.}));
ex01Points.push_back(ex01->addPoint({0., H, 0.}));

/*
GMSH STANDARD FOR CREATING CIRCLES:
Add first the start point, then the middle one, and the the last one
Then you add the last point, the middle one, and the start one
*/
ex01Points.push_back(ex01->addPoint({L/2. - R, H/2., 0.}, 1.0));
ex01Points.push_back(ex01->addPoint({L/2., H/2., 0.}, 1.0, false));
ex01Points.push_back(ex01->addPoint({L/2. + R, H/2., 0.}, 1.0));

ex01Lines.push_back(ex01->addLine({ex01Points[0], ex01Points[1]}));
ex01Lines.push_back(ex01->addLine({ex01Points[1], ex01Points[2]}));
ex01Lines.push_back(ex01->addLine({ex01Points[2], ex01Points[3]}));
ex01Lines.push_back(ex01->addLine({ex01Points[3], ex01Points[0]}));

ex01Lines.push_back(ex01->addCircle({ex01Points[4], ex01Points[5], ex01Points[6]}));
ex01Lines.push_back(ex01->addCircle({ex01Points[6], ex01Points[5], ex01Points[4]}));

ex01Surfaces.push_back(ex01->addPlaneSurface({ex01Lines[0], ex01Lines[1], ex01Lines[2], ex01Lines[3], ex01Lines[4], ex01Lines[5]}));
ex01->transfiniteLine({ex01Lines[0], ex01Lines[1], ex01Lines[2], ex01Lines[3]}, 4);

ex01BCs.push_back(ex01->addBoundaryConditions(ex01Lines[3], DIRICHLET, {{X, 0.}, {Y, 0.}, {Z, 0.}}));
ex01BCs.push_back(ex01->addBoundaryConditions(ex01Lines[1], NEUMANN, {{X, 10.}}));

ex01->generateMesh(T6, DELAUNAY, true, false);

ex01->generateMirFile();


