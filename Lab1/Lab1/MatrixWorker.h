#pragma once

typedef std::vector<std::vector<double>> Matrix;

class CMatrixWorker
{
public:
	CMatrixWorker();
	~CMatrixWorker();

	Matrix GetInnverseMatrix(Matrix const& sourceMatrix);

private:
	void CalculateProcess();

	Matrix m_usingMatrix;
	Matrix m_identityMatrix;
	size_t m_size;
};

