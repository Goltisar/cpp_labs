#pragma once
#include <cstdlib>
#include <ctime>

using namespace std;

class MatrixNxN
{
public:
	class Manager
	{
	public:
		int** getMatrix() const
		{ 
			return matrix;
		}

		void setMatrix(int iDim)
		{
			matrix = new int* [iDim];
			for (int i = 0; i < iDim; i++)
				matrix[i] = new int[iDim];
		}

		~Manager() { delete[] matrix; }

	private:
		int** matrix;
	};
	Manager mngr = Manager{};
	MatrixNxN(const int iDim);
	int dim;
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
};