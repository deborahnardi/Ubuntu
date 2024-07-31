#include "../headers/Geometry.h"
#include <iostream> 
#include <sstream>

std::vector<std::string> split (std::string str, char delim) //char represents only ONE character, in this case ","
{
    // Function can be used only by class Geometry
    std::istringstream inputStream(str); // istringstream is a class that allows the reading of strings as entry data
    std::vector<std::string> output;
    std::string dividedStream;

    while (getline(inputStream, dividedStream, delim)) //getline(entry fluxe, string that the new line will be placed, delimiter)
        output.push_back(dividedStream);
    
    return output;
}

Point *Geometry::addPoint(std::vector<double> coordinates, const double &ldimension, const bool &discretization)
{                       //arguments of the class point, i.e, index, name, coordinates, etc.
    Point *p = new Point(points.size(), "p" + std::to_string(points.size()), coordinates, ldimension, discretization);
    // std::cout << "The point size is " << points.size() << std::endl;
    points.push_back(p);
    return p;
}

Line *Geometry::addLine(std::vector<Point*> points, const bool &discretization)
{                      
    Line *l = new Line(lines.size(), "l" + std::to_string(lines.size()), points, discretization);
    lines.push_back(l);
    return l;
}

LineLoop *Geometry::addLineLoop(std::vector<Line*> lines)
{
    LineLoop *ll = new LineLoop(lineLoops.size(), "ll" + std::to_string(lineLoops.size()), lines);
    lineLoops.push_back(ll);
    return ll;
}

Circle *Geometry::addCircle(std::vector<Point*> points, const bool &discretization)
{
    Circle *c = new Circle(lines.size(), "l" + std::to_string(lines.size()), points, discretization);
    lines.push_back(c);
    return c;
}

Surface *Geometry::addSurface(std::vector<Line*> lines, const bool &discretization)
{
    LineLoop *ll = addLineLoop(lines);
    Surface *s = new Surface(surfaces.size(), "s" + std::to_string(surfaces.size()), ll, discretization);
    surfaces.push_back(s);
    return s;
}

Surface *Geometry::addSurface(LineLoop *lineLoop, const bool &discretization)
{
    Surface *s = new Surface(surfaces.size(), "s" + std::to_string(surfaces.size()), lineLoop, discretization);
    surfaces.push_back(s);
    return s;
}

PlaneSurface* Geometry::addPlaneSurface(std::vector<Line*> lines, const bool &discretization)
{
    LineLoop *ll = addLineLoop(lines); //creates object LineLoop named ll calling function addLineLoop
    PlaneSurface *ps = new PlaneSurface(surfaces.size(), "s" + std::to_string(surfaces.size()), ll, discretization);
    surfaces.push_back(ps);
    return ps;
}

PlaneSurface *Geometry::addPlaneSurface(LineLoop *lineLoop, const bool &discretization)
{
    PlaneSurface *ps = new PlaneSurface(surfaces.size(), "s" + std::to_string(surfaces.size()), lineLoop, discretization);
    surfaces.push_back(ps);
    return ps;
}

SurfaceLoop *Geometry::addSurfaceLoop(std::vector<Surface *> surfaces)
{
    SurfaceLoop *sl = new SurfaceLoop(surfaceLoops.size(), "sl" + std::to_string(surfaceLoops.size()), surfaces);
    surfaceLoops.push_back(sl);
    return sl;
}

Volume* Geometry::addVolume(std::vector<Surface *> surfaces, const bool &discretization)
{
    SurfaceLoop *sl = addSurfaceLoop(surfaces);
    Volume *v = new Volume(volumes.size(), "v" + std::to_string(volumes.size()), sl, discretization);
    volumes.push_back(v);
    return v;
}

Volume *Geometry::addVolume(SurfaceLoop*surfaceLoop, const bool &discretization)
{
    Volume *v = new Volume(volumes.size(), "v" + std::to_string(volumes.size()), surfaceLoop, discretization);
    volumes.push_back(v);
    return v;
}

void Geometry::transfiniteLine(std::vector<Line*> lines, const int &divisions, const double &progression)
{
    //Transfinite line is a standard for generating .geo file, see more in Gmsh Manual

    std::stringstream text;
    text << "Transfinite Line {";
    for (size_t i=0; i<lines.size(); i++)
    {
        text << lines[i]->getName();
                if (i != (lines.size() - 1))
            text << ", ";
    }
    text << "} = " << divisions + 1 << " Using Progression " << progression << ";\n//\n";
    gmshFileAppendx += text.str();
}

void Geometry::transfiniteSurface(std::vector<Surface *> Surfaces, std::string orientation, std::vector<Point *> points)
{
    std::stringstream text;
    text << "Transfinite Surface {";
    for (size_t i = 0; i < Surfaces.size(); i++)
    {
        text << Surfaces[i]->getName();
        if (i != (Surfaces.size() - 1))
            text << ", ";
    }
    text << "} ";
    if (points.size() != 0)
    {
        text << "= {";
        for (size_t i = 0; i < points.size(); i++)
        {
            text << points[i]->getName();
            if (i != (points.size() - 1))
                text << ", ";
        }
        text << "} " << orientation << ";\n//\n";
    }
    else
        text << orientation << ";\n//\n";
    gmshFileAppendx += text.str();
}

void Geometry::transfiniteVolume(std::vector<Volume *> volumes)
{
    std::stringstream text;
    text << "Transfinite Volume {";
    for (size_t i = 0; i < volumes.size(); i++)
    {
        text << volumes[i]->getName();
        if (i != (volumes.size() - 1))
            text << ", ";
    }
    text << "};\n//\n";

    gmshFileAppendx += text.str();
}

BoundaryCondition *Geometry::addBoundaryConditions(Line* line, const BoundaryType &bcType, const std::vector<std::pair<DOFType, double>> &entries)
{
    BoundaryCondition *bc = new BoundaryCondition(boundaryConditions.size(), line->getName(), entries, bcType);
    boundaryConditions.push_back(bc);
    return bc;
}

BoundaryCondition *Geometry::addBoundaryConditions(Point* point, const BoundaryType &bcType, const std::vector<std::pair<DOFType, double>> &entries)
{
    BoundaryCondition *bc = new BoundaryCondition(boundaryConditions.size(), point->getName(), entries, bcType);
    boundaryConditions.push_back(bc);
    return bc;
}

void Geometry::generateGeoFile()
{
    std::string geofile = name + ".geo";
    std::ofstream file(geofile.c_str()); //generates .geo file, c_str converts everything to a string

    for (auto p : points)
        file << p->getGmshCode();
    for (auto l : lines)
        file << l->getGmshCode();
    for (auto ll : lineLoops)
        file << ll->getGmshCode();
    for (auto s : surfaces)
        file << s->getGmshCode();
    for (auto sl : surfaceLoops)
        file << sl->getGmshCode();
    for (auto v : volumes)
        file << v->getGmshCode();;
    
    file << gmshFileAppendx;

    file.close();
}

void Geometry::generateMesh(const ElementName &elementType, const MeshAlgorithm &algorithm, const bool &plotMesh, const bool &showInfo)
{
    PetscPrintf(PETSC_COMM_WORLD, "Generating mesh...");
    
    int rank, size;

    MPI_Comm_rank(PETSC_COMM_WORLD, &rank);

    if (rank == 0) //If it is the master rank
    {
        generateGeoFile();
        createMesh(elementType, algorithm, plotMesh, showInfo);
    }
    
    PetscPrintf(PETSC_COMM_WORLD, " Done!\n");
}

std::pair<std::string, bool> Geometry::createMesh(const ElementName &elementName, const MeshAlgorithm &algorithm, const bool &plotMesh, const bool &showInfo)
{
    struct ElementData
    {
        std::string dimension;
        std::string order;
    };

    const std::unordered_map<ElementName, ElementData> elementData = {
        // lines
        {L2, {"3", "1"}}, //Element name "L2", Element data {"dimension", "order"} 
        {L3, {"3", "2"}},
        {L4, {"3", "3"}},
        // triangles
        {T3, {"2", "1"}},
        {T6, {"2", "2"}},
        {T10, {"2", "3"}},
        // quadrilaterals
        {Q4, {"2", "1"}},
        {Q9, {"2", "2"}},
        {Q16, {"2", "3"}},
        // tetrahedrons
        {TET4, {"3", "1"}},
        {TET10, {"3", "2"}},
        {TET20, {"3", "3"}}};

    deg = std::stoi(elementData.at(elementName).order); //Converts the above order string elementData to an intenger number

    std::string geofile, mshfile;
    bool deleteFiles = name.empty();
    if (deleteFiles)
        mshfile = name + "temp.msh",
        geofile = name + "temp.geo";
    else
        mshfile = name + ".msh",
        geofile = name + ".geo";

    std::string cmd = "gmsh";
    cmd += " -clscale 1.0 " + geofile + " -o " + mshfile + " -format msh2"; //Opens the terminal and generate the mesh in Gmsh

    switch (algorithm)
    {
    case FRONT:
        // cmd += " -algo front" + dimension.at(elementName) + "d";
        cmd += " -algo front2d";
        break;
    case DELAUNAY:
        cmd += " -algo del" + elementData.at(elementName).dimension + "d";
        break;
    case ADAPT:
        cmd += " -algo meshadapt";
        break;
    case PACK:
        cmd += " -algo pack";
        break;
    case QUAD:
        cmd += " -algo delquad";
        break;
    case BAMG:
        cmd += " -algo bamg";
        break;
    case HXT:
        cmd += " -algo hxt";
        break;
    }
    cmd += " -" + elementData.at(elementName).dimension + " -order " + elementData.at(elementName).order;
    cmd += (!showInfo) ? " -v 0" : "";

    system(cmd.c_str());

    if (deleteFiles)
        system((rm + geofile).c_str());

    if (plotMesh)
        system(("gmsh " + mshfile).c_str());

    return std::make_pair(mshfile, deleteFiles);
}

void Geometry::generateMirFile()
{
    PetscPrintf(PETSC_COMM_WORLD, "Generating mir file..."); // PETSC_COMM_WORLD: global comunicator, all the ranks are going to exhibit this message
    
    /*
     * The `ifstream` class is used to open a file for input. It provides methods for reading data from the file.
     * In this code snippet, the `input` object of type `ifstream` is used to open a file with the name `name + ".msh"`.
     */
    std::ifstream input(name + ".msh");
    std::string line;

    std::string mirfile = name + ".mir";
    std::ofstream file(mirfile.c_str()); //Writtes a file

    std::unordered_map<std::string, int> physicalEntities; //Associates a string to a int value

    while (line != "$PhysicalNames")
        std::getline(input, line);
    
    int nEntities;
    input >> nEntities; //Reads a value from input file and storages it in the variable nEntities
    std::string name[nEntities]; //Array named name of size nEntities
    std::getline(input, line);

    for (int i = 0; i < nEntities; i++)
    {
        std::getline(input, line);
        std::vector<std::string> token = split(line, ' '); //Result from split function is stored into a vector of strings named token
        token[2] = token[2].substr(1, token[2].size() -2);
        physicalEntities[token[2]] = std::stoi(token[1]);
        name[i] = token[2];
        if (std::stoi(token[0])>dim)
            dim = std::stoi(token[0]);
    }
    // **************************** FIRST LINE OF .mir FILE ****************************
    file << dim << " " << deg << std::endl;
    // **************************** SECOND LINE OF .mir FILE ***************************
    file << "$Materials" << std::endl;
    // **************************** THIRD LINE OF .mir FILE ****************************
    file << materials.size() << std::endl;
    // **************************** NEXT LINES OF .mir FILE ****************************
    for (auto *m : materials)
        file << m->getIndex() + 1 << " " << m->getYoungModulus() << " " << m->getPoisson() << " " << m->getDensity() << " " << m->getPlaneAnalysis() << std::endl;
    file << "$EndMaterials" << std::endl;

    //**************************** WRITING TO .mir FILE ********************************
    file << "$PhysicalNames" << std::endl;
    file << nEntities << std::endl;
    int i = 1;

    for (auto p : points)
        file << i++ << " " << p->getName() << std::endl;
    for (auto l : lines)
    {
        file << i++ << " " << l->getName();
        if (l->getMaterial() != nullptr)
            file << " " << l->getMaterial()->getIndex() + 1 << " " << l->getArea() << " " << l->getElementType();
        file << std::endl;
    }
    for (auto s : surfaces)
    {
        file << i++ << " " << s->getName();
        if (s->getMaterial() != nullptr)
            file << " " << s->getMaterial()->getIndex() + 1 << " " << s->getThickness() << " " << s->getElementType();
        file << std::endl;
    }
    for (auto v : volumes)
    {
        file << i++ << " " << v->getName();
        if (v->getMaterial() != nullptr)
            file << " " << v->getMaterial()->getIndex() + 1 << " " << 0 << " " << v->getElementType();
        file << std::endl;
    }
    file << "$EndPhysicalNames" << std::endl;

    // reading nodes from msh file and writing to mir file
    while (line != "$Nodes")
        std::getline(input, line);
    int nNodes;
    input >> nNodes;
    std::getline(input, line);

    file << "$Nodes" << std::endl;
    file << nNodes << std::endl;
    for (int i = 0; i < nNodes; i++)
    {
        std::getline(input, line);
        file << line << std::endl;
    }
    file << "$EndNodes" << std::endl;

    // reading elements from msh file and writing to mir file
    while (line != "$Elements")
        std::getline(input, line);
    int nElements;
    input >> nElements;
    std::getline(input, line);

    file << "$Elements" << std::endl;
    file << nElements << std::endl;
    for (int i = 0; i < nElements; i++)
    {
        std::getline(input, line);
        file << line << std::endl;
    }
    file << "$EndElements" << std::endl;

    // writing boundary conditions
    file << "$BoundaryConditions" << std::endl;
    file << boundaryConditions.size() << std::endl;
    for (auto *bc : boundaryConditions)
    {
        file << bc->getIndex() + 1 << " " << bc->getBoundaryType() << " " << physicalEntities[bc->getEntityName()] << " ";
        for (auto value : bc->getBcEntry())
        {
            file << value.first << " " << value.second;
            if (value != bc->getBcEntry().back())
                file << " ";
        }
        file << std::endl;
    }
    file << "$EndBoundaryConditions" << std::endl;

    input.close();
    file.close();
    PetscPrintf(PETSC_COMM_WORLD, " Done!\n");
}


