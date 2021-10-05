#pragma once
#include <iostream>
#include <string>

using namespace std;

class PVector
{
private:
	double radius;
	double angle;

public:
	static PVector newRandPVector()
	{
		PVector result;
		result.angle = rand() % 361 + (double)(rand() % 100) / 100;
		result.radius = rand() % 11 + (double)(rand() % 100) / 100;

		return result;
	}

	string toString()
	{
		string result;

		string rounded = to_string(radius);
		rounded.erase(rounded.length() - 4);
		result += rounded + ", ";

		rounded = to_string(angle);
		rounded.erase(rounded.length() - 4);
		result += rounded + "°";

		return result;
	}

	PVector()
	{
		radius = 0;
		angle = 0;
	}

	PVector(const PVector& right)
	{
		radius = right.radius;
		angle = right.angle;
	}

	PVector& operator=(const PVector& right)
	{
		radius = right.radius;
		angle = right.angle;

		return *this;
	}

	friend PVector operator*(PVector& left, double right)
	{
		PVector result(left);

		if (right >= 0) {
			result.radius *= right;
		}
		else {
			result.radius *= -right;
			result.angle += 180;
		}

		return result;
	}

	friend string operator+(PVector& pVector)
	{
		return pVector.toString();
	}
};