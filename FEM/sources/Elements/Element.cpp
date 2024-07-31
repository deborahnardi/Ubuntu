#pragma once

#include "../../headers/Elements/Element.h"

Element::Element() {}
Element::Element(const int &_index, const std::vector<Node* > &_nodesConnec, Material *_material, const int &_physicalEntity)  
    : index(_index), nodesConnec(_nodesConnec), material(_material), physicalEntity(_physicalEntity) {}
Element::~Element() {}