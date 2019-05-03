
#ifndef DATA_FUNS
#define DATA_FUNS

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../eigen/Eigen/Dense"

std::vector<double> pullParamLine(std::ifstream&);
std::vector<double> Eigen2stdVec(Eigen::Vector2d);

Eigen::Matrix2d stdVec2EigenM(std::vector<double>, int,int);
Eigen::Vector2d stdVec2EigenV(std::vector<double>, int);
Eigen::RowVector2d stdVec2EigenRV(std::vector<double>, int);
#endif
