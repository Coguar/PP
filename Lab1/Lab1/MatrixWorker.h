#pragma once
#include "Matrix.h"


class CMatrixWorker
{
public:
	Matr GetInnverseMatrix(Matr const& sourceMatrix, bool isMultyThreads, int threadsCount);

private:
	void CalculateProcess(bool isMultyThreads, int threadsCount);

	//CMatrix m_usingMatrix;
	Matr m_sourceMatrix;
	Matr m_identityMatrix;
	size_t m_size;
};

