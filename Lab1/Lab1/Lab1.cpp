#include "stdafx.h"
#include "MatrixWorker.h"
#include <ctime>
#include <random>

Matr GetMatrix(size_t n)
{
	std::mt19937 rng;
	std::uniform_int_distribution<>num(0, 100);
	Matr matrix;
	matrix.resize(n);
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			matrix[i].push_back(num(rng));
		}
	}
	return matrix;
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		return 1;
	}
	Matr matrix = GetMatrix(1000);
	CMatrixWorker worker;
	size_t time = clock();
	auto matr = worker.GetInnverseMatrix(matrix, true, std::atoi(argv[1]));
	size_t finishTime = clock();
	double processTime = (finishTime - time) / 1000.0;
	std::cout << processTime << std::endl;
	/*
	time = clock();
	matr = worker.GetInnverseMatrix(matrix, false, 1);
	finishTime = clock();
	processTime = (finishTime - time) / 1000.0;
	std::cout << processTime << std::endl;
	*/
    return 0;
}

