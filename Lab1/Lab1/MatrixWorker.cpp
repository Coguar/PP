#include "stdafx.h"
#include "MatrixWorker.h"
#include "vhf.h"
#include <iostream>
#include <Windows.h>

Matr CMatrixWorker::GetInnverseMatrix(Matr const & sourceMatrix, bool isMultyThreads, int threadsCount)
{
	if (CMatrix::CheckMatrixOnSquare(sourceMatrix))
	{
		m_size = sourceMatrix.size();
		m_sourceMatrix = sourceMatrix;
		m_identityMatrix = CMatrix::MakeIdentityMatrix(m_size);
		CalculateProcess(isMultyThreads, threadsCount);
	}
	return m_identityMatrix;
}

void DoStep(Matr & identityMatrix, Matr & usingMatrix, size_t size, size_t posx, size_t posy)
{

	for (size_t i = posx; i < posy; ++i)
	{
		vhf::DivisionVec(identityMatrix[i], usingMatrix[i][i]);
		vhf::DivisionVec(usingMatrix[i], usingMatrix[i][i]);
		for (size_t j = 0; j < size; ++j)
		{
			CMatrix::LineProcess(usingMatrix, identityMatrix, i, j);
		}
	}
}

void CMatrixWorker::CalculateProcess(bool isMultyThreads, int threadsCount)
{
	SetProcessAffinityMask(GetCurrentProcess(), 3);

	std::vector <std::thread> thrs;
	thrs.resize(threadsCount);
	if (isMultyThreads)
	{
		auto step = size_t(m_size / threadsCount);
		for (size_t i = 0; i < threadsCount; ++i)
		{
			size_t x = i * step;
			size_t y = x + step;
			if (i == m_size - 1)
			{
				y = m_size;
			}
			thrs[i] = std::thread(DoStep, m_identityMatrix, m_sourceMatrix, m_size, x, y);
		}
		for (auto &it : thrs)
		{
			it.join();
		}
	}
	else
	{
		DoStep(m_identityMatrix, m_sourceMatrix, m_size, 0, m_size);
	}
}
