#include "../headers/BoundaryCondition.h"

BoundaryCondition::BoundaryCondition() {}
BoundaryCondition::BoundaryCondition(const int &_index, const std::string &_entityName, const std::vector<std::pair<DOFType, double>> &_entries, const BoundaryType &_bcType)
    : index(_index), entityName(_entityName), entries(_entries), bcType(_bcType) {}
BoundaryCondition::~BoundaryCondition(){}