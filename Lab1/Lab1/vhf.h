#pragma once
#include <vector>

namespace vhf
{

	void DivisionVec(std::vector<double> & vec, double number);

	std::vector<double> MultiplyVec(std::vector<double> const& vec, double number);

	void SubtractVecFromAnother(std::vector<double> const& subtrahend, std::vector<double> & vec, double num);
	
};