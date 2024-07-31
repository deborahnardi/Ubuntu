#include "../../headers/Elements/Element.h"

Truss::Truss() {}
Truss::Truss(const int &_index, const std::vector<Node* > &_nodesConnec, Material *_material, const int &_physicalEntity, const double &_area)
    : Element(_index, _nodesConnec, _material, _physicalEntity), area(_area) {}
Truss::~Truss() {}
