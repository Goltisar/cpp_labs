/*
    Бобылев Ярослав
    РИ-280002
*/
#include <iostream>
#include "Matrix3x3.h"
#include "MatrixNxN.h"
#include "LinkedList.h"

void Matrix3x3Test()
{
    auto matrix = Matrix3x3();
    matrix.fillRandomElements(-10, 10);
    cout << "Matrix3x3: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << matrix.element(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << "Sum of elements of " << i << " row: " << matrix.sumRow(i) << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << "Min element of " << i << " column: " << matrix.minColumn(i) <<
        "\nMax element of " << i << " column: " << matrix.maxColumn(i) << "\n\n";

    cout << "Sum of principle diagonal: " << matrix.sumPrincipleDiag() << endl;
    cout << "Product of principle diagonal: " << matrix.productPrincipleDiag() << endl << endl;
    cout << "Sum of secondary diagonal: " << matrix.sumSecondaryDiag() << endl;
    cout << "Product of secondary diagonal: " << matrix.productSecondaryDiag() << endl << endl;
}

void MatrixNxNTest(int dim)
{
    auto matrix = MatrixNxN(dim);
    matrix.fillRandomElements(-10, 10);
    cout << "Matrix" << dim << "x" << dim << ": " << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            cout << matrix.element(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < dim; i++)
        cout << "Sum of elements of " << i << " row: " << matrix.sumRow(i) << endl;
    cout << endl;
    for (int i = 0; i < dim; i++)
        cout << "Min element of " << i << " column: " << matrix.minColumn(i) <<
        "\nMax element of " << i << " column: " << matrix.maxColumn(i) << "\n\n";
    cout << "Sum of principle diagonal: " << matrix.sumPrincipleDiag() << endl;
    cout << "Product of principle diagonal: " << matrix.productPrincipleDiag() << endl << endl;
    cout << "Sum of secondary diagonal: " << matrix.sumSecondaryDiag() << endl;
    cout << "Product of secondary diagonal: " << matrix.productSecondaryDiag() << endl << endl;
}

void kthElementTest(LinkedList<int>* list)
{
    int index = 3;
    auto ending = "th";
    if (!(index % 100 == 11 || index % 100 == 12 || index % 100 == 13))
        switch (index % 10)
        {
        case 1:
            ending = "st";
            break;
        case 2:
            ending = "nd";
            break;
        case 3:
            ending = "rd";
            break;
        }
    cout << "\nThe " << index << ending << " element from the end: ";
    cout << list->getElementFromEnd(index) << endl;
}

void LinkedListTest()
{
    LinkedList<int> list;
    for (int i = 0; i < 25; i++)
        list.push_back(i % 4);
    list.push_back(12);
    list.push_back(-23);
    list.push_back(-23);
    list.push_back(12);
    list.push_back(0);
    list.push_back(-8);
    cout << "Linked list with duplicates:" << endl;
    for (int i = 0; i < list.getSize(); i++)
        cout << list[i] << " ";
    list.deleteDuplicates();
    cout << "\n\n";
    cout << "Linked list without duplicates:" << endl;
    for (int i = 0; i < list.getSize(); i++)
        cout << list[i] << " ";
    cout << endl;
    kthElementTest(&list);
}

int main()
{
    //task 1.1
    Matrix3x3Test();
    //task 1.2
    MatrixNxNTest(4);
    //task 2, 3
    LinkedListTest();
}