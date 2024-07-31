#include "Material.h"

Material::Material() {}
Material::Material(int _index, double _young, double _poisson, PlaneAnalysis _planeAnalysis)
    : index(_index), young(_young), poisson(_poisson), planeAnalysis(_planeAnalysis)
{
    //Methods
    shearModulus = young / (2. * ( 1. + poisson));
}
Material::~Material() {}