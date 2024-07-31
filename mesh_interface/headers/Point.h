/* 
    This header file defines the Point class, which is used to represent a point in 1D, 2D or 3D space.
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

class Point {
private:
    int index;
    std::string name;
    std::vector<double> coordinates;
    double ldimension;
    bool discretization;
        
public:
    Point(int _index, const std::string& _name, const std::vector<double>& _coordinates, const double &_ldimension, const bool &_discretization)
/* 
    std vector for initializing the coordinates of the point is better than using Eigen::VectorXd because it is more efficient
*/

{
    index = _index;
    name = _name;
    coordinates = _coordinates;
    ldimension = _ldimension;
    discretization = _discretization;
}
~Point(){};
    
    // Getters
    int getIndex() {return index;}
    std::string getName() {return name;}
    std::vector<double> getCoordinates() {return coordinates;}
    double getLdimension() {return ldimension;}
    bool getDiscretization() {return discretization;}

    double getX() {return coordinates[0];}
    double getY() {return coordinates[1];}
    double getZ() {return coordinates[2];}

    // Setters
    void setIndex(int _index) {index = _index; }
    void setName(const std::string& _name) {name = _name;}
    void setCoordinates(const std::vector<double>& _coordinates) {coordinates = _coordinates;}
    void setCoordinate(const int& index, const double& _coordinate) {coordinates[index] = _coordinate;}
    void setLdimension(double _ldimension) {ldimension = _ldimension;}
    void setDiscretization(bool _discretization) {discretization = _discretization;}

    std::string getGmshCode(); // Declared here, defined in Point.cpp
    /*
    the function getGmshCode() is declared with a return type of std::string. This means that when the function is called, it is expected to return a value of type std::string
    */
};