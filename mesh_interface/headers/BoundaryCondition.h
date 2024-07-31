/*
This head file defines the class Boundary Condition
*/
#pragma once
#include <iostream>
#include <vector>
#include "../../enumclass.hpp"

class BoundaryCondition
{
private:
    int index;
    std::string entityName;
    std::vector<std::pair<DOFType,double>> entries;
    BoundaryType bcType;
    
public:
    BoundaryCondition();
    BoundaryCondition(const int &_index, const std::string &_entityName, const std::vector<std::pair<DOFType, double>> &_entries, const BoundaryType &_bcType);
    ~BoundaryCondition();

    //Getters
    int getIndex() const {return index;}
    std::string getEntityName() const { return entityName; }
    std::vector<std::pair<DOFType, double>> getBcEntry() const {return entries;}
    BoundaryType getBoundaryType() {return bcType;}
};