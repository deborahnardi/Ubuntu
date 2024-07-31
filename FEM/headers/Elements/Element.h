#pragma once

#include "../Node.h"
#include "../../../mesh_interface/headers/Material.h"

#include <vector>

class Element
{
protected:
    int index;
    std::vector<Node* > nodesConnec;
    Material *material;
    int physicalEntity;

public:
    Element();
    Element(const int &_index, const std::vector<Node* > &_nodesConnec, Material *_material, const int &_physicalEntity);
    // & to avoid copies in caller and constructor
    ~Element();

    int getIndex() {return index;}
    std::vector<Node* > getNodesConnec() {return nodesConnec;}
    Material *getMaterial() {return material;}
    int getPhysicalEntity() {return physicalEntity;}

    void setIndex(int _index) {index = _index;}
    void setNodesConnec(std::vector<Node*> _nodesConnec) { nodesConnec = _nodesConnec;}
};

class Truss : public Element
{
public:
    Truss();
    Truss(const int &_index, const std::vector<Node* > &_nodesConnec, Material *_material, const int &_physicalEntity, const double &_area);
    ~Truss();
private:
    double lenght, area;
};