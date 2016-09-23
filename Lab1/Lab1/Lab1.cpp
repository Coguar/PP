// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MatrixWorker.h"

const Matrix matrix = 
{
	{3, 2, 3},
	{4, 7, 6},
	{7, 8, 8}
};

int main()
{
	CMatrixWorker worker;
	auto matr = worker.GetInnverseMatrix(matrix);
    return 0;
}

