#include <iostream>

#include "Matrix.cpp"
#include "СVector.cpp"
#include "PVector.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	double b;

	cout << "Введите b: ";
	cin >> b;

	CVector** testCVectors = new CVector*[3];
	for (int i = 0; i < 3; i++) {
		testCVectors[i] = new CVector[3];

		for (int j = 0; j < 3; j++) {
			testCVectors[i][j] = CVector::newRandCVector(rand() % 2 + 2);
		}
	}
	
	Matrix<CVector> A = Matrix<CVector>(3, 3, testCVectors);
	Matrix<CVector> B = Matrix<CVector>(3, 3);

	cout << "\nМатрица A<CVector>" << endl;
	A.print();

	B = A * b;

	cout << "\n\nМатрица B = A * " << b << endl;
	B.print();

	cout << "\n\n--------------------------------------" << endl;

	PVector** testPVectors = new PVector*[3];
	for (int i = 0; i < 3; i++) {
		testPVectors[i] = new PVector[3];

		for (int j = 0; j < 3; j++) {
			testPVectors[i][j] = PVector::newRandPVector();
		}
	}

	Matrix<PVector> Ap = Matrix<PVector>(3, 3, testPVectors);
	Matrix<PVector> Bp = Matrix<PVector>(3, 3);

	cout << "\n\nМатрица A<PVector>" << endl;
	Ap.print();

	Bp = Ap * b;

	cout << "\n\nМатрица B = A * " << b << endl;
	Bp.print();

	system("pause > nul");
	return 0;
}
