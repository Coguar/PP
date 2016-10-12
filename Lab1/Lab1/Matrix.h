#pragma once
#include <mutex>
typedef std::vector<std::vector<double>> Matr;

class CMatrix
{
public:

	static const Matr MakeIdentityMatrix(size_t n);
	static const bool CheckMatrixOnSquare(Matr const& matrix);
	static void LineProcess(Matr & source, Matr & identity, int i, int j);
private:

};

