#include "stdafx.h"
#include "vhf.h"

void vhf::DivisionVec(std::vector<double>& vec, double number)

{
	for (auto &it : vec)
	{
		it /= number;
	}
}

std::vector<double> vhf::MultiplyVec(std::vector<double> const & vec, double number)
{
	std::vector<double> result = vec;
	for (auto &it : result)
	{
		it *= number;
	}
	return result;
}

void vhf::SubtractVecFromAnother(std::vector<double> const & subtrahend, std::vector<double>& vec, double num)
{
	std::vector<double> subVec = MultiplyVec(subtrahend, num);
	for (size_t i = 0; i < vec.size(); ++i)
	{
		vec[i] -= subVec[i];
	}
}
