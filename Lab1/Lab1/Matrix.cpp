#include "stdafx.h"
#include "Matrix.h"
#include "vhf.h"


const Matr CMatrix::MakeIdentityMatrix(size_t n)
{
	Matr matrix;
	for (size_t i = 0; i < n; ++i)
	{
		std::vector<double> line(n, 0);
		line[i] = 1;
		matrix.push_back(line);
	}
	return matrix;
}

const bool CMatrix::CheckMatrixOnSquare(Matr const & matrix)
{
	size_t n = matrix.size();
	for (auto &line : matrix)
	{
		if (line.size() != n)
		{
			return false;
		}
	}
	return true;
}

void CMatrix::LineProcess(Matr & source, Matr & identity, int i, int j)
{
	if (j != i)
	{
		vhf::SubtractVecFromAnother(identity[i], identity[j], source[j][i]);
		vhf::SubtractVecFromAnother(source[i], source[j], source[j][i]);
	}
}
