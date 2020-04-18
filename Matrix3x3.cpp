#include "Matrix3x3.h"

using namespace std;

Matrix3x3::Matrix3x3() {
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			Matrix3x3::matrix[i][j] = 0;
}

int Matrix3x3::element(const int i, const int j) const
{
	return Matrix3x3::matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	Matrix3x3::matrix[i][j] = value;
}
void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	srand(unsigned(time(0)));
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			Matrix3x3::matrix[i][j] = rand() % (maxVal - minVal) + minVal;
}

int Matrix3x3::sumPrincipleDiag() const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i == j)
				sum += Matrix3x3::matrix[i][j];
	return sum;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i + j == dim - 1)
				sum += Matrix3x3::matrix[i][j];
	return sum;
}

int Matrix3x3::productPrincipleDiag() const
{
	int product = 1;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i == j)
				product *= Matrix3x3::matrix[i][j];
	return product;
}

int Matrix3x3::productSecondaryDiag() const
{
	int product = 1;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (i + j == dim - 1)
				product *= Matrix3x3::matrix[i][j];
	return product;
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += Matrix3x3::matrix[iRow][i];
	return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = Matrix3x3::matrix[0][iCol];
	for (int i = 0; i < dim; i++)
		if (Matrix3x3::matrix[i][iCol] < min)
			min = Matrix3x3::matrix[i][iCol];
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = Matrix3x3::matrix[0][iCol];
	for (int i = 0; i < dim; i++)
		if (Matrix3x3::matrix[i][iCol] > max)
			max = Matrix3x3::matrix[i][iCol];
	return max;
}