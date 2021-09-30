#pragma once
#include <iostream>
#include <string>

using namespace std;

class CVector
{
private:
	int size;
	double* coordinates;

public:
	static CVector newRandCVector(int size)
	{
		CVector result(size);
		for (int i = 0; i < size; i++) {
			result.coordinates[i] = (rand() % 21 - 10) + (double)(rand() % 100) / 100;
		}
		return result;
	}

	string toString()
	{
		string result;
		for (int i = 0; i < size; i++) {
			string rounded = to_string(coordinates[i]);
			rounded.erase(rounded.length() - 4);

			result += rounded;
			if (i < size - 1) result += ", ";
		}
		return result;
	}

	CVector() 
	{
		size = 0;
		coordinates = nullptr;
	}

	CVector(int size)
	{
		this->size = size;
		coordinates = new double[size];
	}

	CVector(const CVector& right)
	{
		this->size = right.size;

		coordinates = new double[size];
		for (int i = 0; i < size; i++) {
			coordinates[i] = right.coordinates[i];
		}
	}

	~CVector()
	{
		delete[] coordinates;
	}

	CVector& operator=(const CVector& right)
	{
		size = right.size;

		if (coordinates != nullptr) {
			delete[] coordinates;
		}

		coordinates = new double[right.size];
		for (int i = 0; i < size; i++) {
			coordinates[i] = right.coordinates[i];
		}

		return *this;
	}

	friend CVector operator*(CVector& right, double left)
	{
		CVector result(right);

		for (int i = 0; i < result.size; i++) {
			result.coordinates[i] *= left;
		}

		return result;
	}

	friend string operator+(string left, CVector& right)
	{
		return left + right.toString();
	}
};