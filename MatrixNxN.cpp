#include "MatrixNxN.h"
using namespace std;

MatrixNxN::MatrixNxN(const int iDim) 
{
	mngr.setMatrix(iDim);
	this->dim = iDim;
	for (int i = 0; i < iDim; i++)
		for (int j = 0; j < iDim; j++)
			mngr.getMatrix()[i][j] = 0;
}

int MatrixNxN::element(const int i, const int j) const
{
	return MatrixNxN::mngr.getMatrix()[i][j];
}

void MatrixNxN::setElement(const int i, const int j, const int value)
{
	MatrixNxN::mngr.getMatrix()[i][j] = value;
}
void MatrixNxN::fillRandomElements(const int minVal, const int maxVal)
{
	srand(unsigned(time(0)));
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			MatrixNxN::mngr.getMatrix()[i][j] = rand() % (maxVal - minVal) + minVal;
}

int MatrixNxN::sumPrincipleDiag() const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i == j)
				sum += MatrixNxN::mngr.getMatrix()[i][j];
	return sum;
}

int MatrixNxN::sumSecondaryDiag() const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i + j == dim -1)
				sum += MatrixNxN::mngr.getMatrix()[i][j];
	return sum;
}

int MatrixNxN::productPrincipleDiag() const
{
	int product = 1;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i == j)
				product *= MatrixNxN::mngr.getMatrix()[i][j];
	return product;
}

int MatrixNxN::productSecondaryDiag() const
{
	int product = 1;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i + j == dim - 1)
				product *= MatrixNxN::mngr.getMatrix()[i][j];
	return product;
}

int MatrixNxN::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += MatrixNxN::mngr.getMatrix()[iRow][i];
	return sum;
}

int MatrixNxN::minColumn(const int iCol) const
{
	int min = MatrixNxN::mngr.getMatrix()[0][iCol];
	for (int i = 0; i < dim; i++)
		if (MatrixNxN::mngr.getMatrix()[i][iCol] < min)
			min = MatrixNxN::mngr.getMatrix()[i][iCol];
	return min;
}

int MatrixNxN::maxColumn(const int iCol) const
{
	int max = MatrixNxN::mngr.getMatrix()[0][iCol];
	for (int i = 0; i < dim; i++)
		if (MatrixNxN::mngr.getMatrix()[i][iCol] > max)
			max = MatrixNxN::mngr.getMatrix()[i][iCol];
	return max;
}