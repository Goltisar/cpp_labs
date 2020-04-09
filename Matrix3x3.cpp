#include "Matrix3x3.h"

using namespace std;

Matrix3x3::Matrix3x3() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
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
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Matrix3x3::matrix[i][j] = rand() % (maxVal - minVal) + minVal;
}

int Matrix3x3::sumPrincipleDiag() const
{
	return Matrix3x3::matrix[0][0] + Matrix3x3::matrix[1][1] + Matrix3x3::matrix[2][2];
}

int Matrix3x3::sumSecondaryDiag() const
{
	return Matrix3x3::matrix[0][2] + Matrix3x3::matrix[1][1] + Matrix3x3::matrix[2][0];
}

int Matrix3x3::productPrincipleDiag() const
{
	return Matrix3x3::matrix[0][0] * Matrix3x3::matrix[1][1] * Matrix3x3::matrix[2][2];
}

int Matrix3x3::productSecondaryDiag() const
{
	return Matrix3x3::matrix[0][2] * Matrix3x3::matrix[1][1] * Matrix3x3::matrix[2][0];
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += Matrix3x3::matrix[iRow][i];
	return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = Matrix3x3::matrix[0][iCol];
	for (int i = 0; i < 3; i++)
		if (Matrix3x3::matrix[i][iCol] < min)
			min = Matrix3x3::matrix[i][iCol];
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = Matrix3x3::matrix[0][iCol];
	for (int i = 0; i < 3; i++)
		if (Matrix3x3::matrix[i][iCol] > max)
			max = Matrix3x3::matrix[i][iCol];
	return max;
}