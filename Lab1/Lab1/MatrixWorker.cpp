#include "stdafx.h"
#include "MatrixWorker.h"
#include <iostream>

namespace
{
	void PrintMatrix(Matrix const& matrix)
	{
		for (auto &it : matrix)
		{
			for (auto & i : it)
			{
				std::cout << i << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	Matrix MakeIdentityMatrix(size_t n)
	{
		Matrix matrix;
		for (size_t i = 0; i < n; ++i)
		{
			std::vector<double> line(n, 0);
			line[i] = 1;
			matrix.push_back(line);
		}
		return matrix;
	}

	bool CheckMatrixOnSquare(Matrix const& matrix)
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

	void DivisionVec(std::vector<double> & vec, double number)
	{
		for (auto &it : vec)
		{
			it /= number;
		}
	}

	std::vector<double> MultiplyVec(std::vector<double> const& vec, double number)
	{
		std::vector<double> result = vec;
		for (auto &it : result)
		{
			it *= number;
		}
		return result;
	}

	void SubtractVecFromAnother(std::vector<double> const& subtrahend, std::vector<double> & vec, double num)
	{
		std::vector<double> subVec = MultiplyVec(subtrahend, num);
		for (size_t i = 0; i < vec.size(); ++i)
		{
			vec[i] -= subVec[i];
		}
	}
}

CMatrixWorker::CMatrixWorker()
{
}


CMatrixWorker::~CMatrixWorker()
{
}

Matrix CMatrixWorker::GetInnverseMatrix(Matrix const & sourceMatrix)
{
	if (CheckMatrixOnSquare(sourceMatrix))
	{
		m_size = sourceMatrix.size();
		m_usingMatrix = sourceMatrix;
		m_identityMatrix = MakeIdentityMatrix(m_size);
		CalculateProcess();
	}
	return m_identityMatrix;
}

void CMatrixWorker::CalculateProcess()
{
	for (size_t i = 0; i < m_size; ++i)
	{
		DivisionVec(m_identityMatrix[i], m_usingMatrix[i][i]);
		DivisionVec(m_usingMatrix[i], m_usingMatrix[i][i]);
		std::cout << "DIVISION " << i << " line ON " << m_usingMatrix[i][i] << std::endl;
		for (size_t j = 0; j < m_size; ++j)
		{
			if (j != i)
			{
				SubtractVecFromAnother(m_identityMatrix[i], m_identityMatrix[j], m_usingMatrix[j][i]);
				SubtractVecFromAnother(m_usingMatrix[i], m_usingMatrix[j], m_usingMatrix[j][i]);
			}
		}
		PrintMatrix(m_identityMatrix);
	}
}
