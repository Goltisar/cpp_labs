#pragma once
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix3x3
{
public:
	Matrix3x3();
	int element(const int i, const int j) const;
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipleDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipleDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;
	static const int dim = 3;
private:
	int matrix[dim][dim];
};