#include "dataFuns.h"

std::vector<double> pullParamLine(std::ifstream& paramFile)
{
	//takes a string which looks like "z = [1,2,3,4] and returns "1,2,3,4" as juice
	//and "z = " as label. It's really looking for what's inside the [] and what's before it
	std::string line;
	std::string label;
	std::string juice;


	std::getline(paramFile,line);
	std::stringstream iss(line);
	std::getline(iss, label,'[');
	std::getline(iss, juice,']');
	std::cout << label << juice <<"\n";
	
	std::stringstream sstream(juice);
	if (!sstream.good())
	{
		std::cout << "\n\nERROR:stream bad, probably got to the end of the file??\n\n";
	}

	double num;
	std::vector<double> nums;
	
	while(sstream >> num)
	{
		//std::cout << num << "\n";
		nums.push_back(num);
		//A<<num;
	}
	return nums;
}

std::vector<double> Eigen2stdVec(Eigen::Vector2d x_evec)
{
    std::vector<double>x_std(x_evec.data(),x_evec.data()+x_evec.size());
    return x_std;

}


//could certainly replace these with one function with a type template: 
//http://www.cplusplus.com/doc/tutorial/functions2/
Eigen::Matrix2d stdVec2EigenM(std::vector<double> dataVec, int nrows, int ncols)
{
	Eigen::Map<Eigen::Matrix2d> EigMat(dataVec.data(),nrows,ncols);
	return EigMat;
}

Eigen::Vector2d stdVec2EigenV(std::vector<double> dataVec, int nrows)
{
	Eigen::Map<Eigen::Vector2d> EigMat(dataVec.data(),nrows,1);
	return EigMat;
}

Eigen::RowVector2d stdVec2EigenRV(std::vector<double> dataVec, int ncols)
{
	Eigen::Map<Eigen::RowVector2d> EigMat(dataVec.data(),1,ncols);
	return EigMat;
}






























