/* 
    This header file defines a class for the geometry of the element.
    The geometry is defined by points, lines, lineloops, surfaces and volumes.
*/
#pragma once

#include "Point.h"
#include "Line.h"
#include "LineLoop.h"
#include "Surface.h"
#include "Volume.h"
#include "Circle.h"
#include "PlaneSurface.h"
#include "BoundaryCondition.h"
#include "Material.h"
#include "../../enumclass.hpp"

#include "hdf5.h"
#include <petscsnes.h>
#include <petscksp.h>
#include <petscdraw.h>
#include <petscmat.h>

#include <fstream>
#include <unordered_map>

#define rm "rm "

class Geometry {
private:
    int dim = 0, deg = 0;
    std::string name;
    std::vector<Point*> points;
    std::vector<Line*> lines;
    std::vector<LineLoop*> lineLoops;
    std::vector<Surface*> surfaces;
    std::vector<Volume*> volumes;
    std::vector<SurfaceLoop*> surfaceLoops;
    std::vector<BoundaryCondition* > boundaryConditions;
    std::vector<Material *> materials;
    std::string gmshFileAppendx;

public:
    Geometry(const std::string _name)
    {
        name = _name;
    }
    ~Geometry(){};

    //Functions
    Point *addPoint(std::vector<double> coordinates, const double &ldimension = 1.0, const bool &discretization = true);
    Line *addLine(std::vector<Point*> points, const bool &discretization = true);
    Circle *addCircle(std::vector<Point*> points, const bool &discretization = true);
    LineLoop *addLineLoop(std::vector<Line*> lines);
    Surface *addSurface(std::vector<Line*> lines, const bool &discretization = true);
    Surface *addSurface(LineLoop *lineLoop, const bool &discretization = true);
    PlaneSurface* addPlaneSurface(std::vector<Line*> lines, const bool &discretization = true);
    PlaneSurface* addPlaneSurface(LineLoop *lineLoop, const bool &discretization = true);
    SurfaceLoop *addSurfaceLoop(std::vector<Surface *> surfaces);
    Volume *addVolume(std::vector<Surface *> surfaces, const bool &discretization = true);
    Volume *addVolume(SurfaceLoop *surfaceLoop, const bool &discretization = true);
    BoundaryCondition *addBoundaryConditions(Line* line, const BoundaryType &bcType, const std::vector<std::pair<DOFType, double>> &entries);
    BoundaryCondition *addBoundaryConditions(Point* point, const BoundaryType &bcType, const std::vector<std::pair<DOFType, double>> &entries);

    //Getters
    std::vector<Point*> getPoints() {return points;}
    Point *getPoint(const int index) { return points[index]; }

    std::vector<Line*> getLines() {return lines;}
    Line *getLine(const int index) {return lines[index];}

    std::vector<LineLoop*> getLineLoops() {return lineLoops;}
    LineLoop *getLineLoop(const int index) {return lineLoops[index];}

    std::vector<Surface*> getSurfaces() {return surfaces;}
    Surface *getSurface(const int index) {return surfaces[index];}

    std::vector<Volume*> getVolumes() {return volumes;}
    Volume *getVolume(const int index) {return volumes[index];}

    void generateGeoFile();
    void transfiniteLine(std::vector<Line*> lines, const int &divisions, const double &progression  = 1);
    void transfiniteSurface(std::vector<Surface *> Surfaces, std::string orientation, std::vector<Point *> points);
    void transfiniteVolume(std::vector<Volume *> volumes);
    void generateMesh(const ElementName &elementType, const MeshAlgorithm &algorithm, const bool &plotMesh, const bool &showInfo);
    std::pair<std::string, bool> createMesh(const ElementName &elementType, const MeshAlgorithm &algorithm, const bool &plotMesh, const bool &showInfo);
    void generateMirFile();
};