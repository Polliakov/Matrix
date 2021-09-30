#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
private:
	int _rows;
	int _columns;
	T** _values;

public:
	void print() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				cout << (string)"" + _values[i][j] << ";  ";
			}
			cout << endl;
		}
	}

	Matrix(int rows, int columns) {
		_rows = rows;
		_columns = columns;

		_values = new T*[rows];
		for (int i = 0; i < rows; i++) {
			_values[i] = new T[columns];
		}
	}

	Matrix(int rows, int columns, T** arr) : Matrix(rows, columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				_values[i][j] = arr[i][j];
			}
		}
	}

	Matrix(const Matrix<T>& matrix) {
		_rows = matrix._rows;
		_columns = matrix._columns;

		_values = new T* [_rows];
		for (int i = 0; i < _rows; i++) {
			_values[i] = new T[_columns];

			for (int j = 0; j < _columns; j++) {
				_values[i][j] = matrix._values[i][j];
			}
		}
	}

	~Matrix() {
		if (_values != nullptr) {
			for (int i = 0; i < _rows; i++) {
				delete[] _values[i];
			}
			delete[] _values;
		}
	}

	Matrix<T>& operator=(const Matrix<T>& right) {
		_rows = right._rows;
		_columns = right._columns;

		for (int i = 0; i < _rows; i++) {
			delete[] _values[i];
		}
		delete[] _values;

		_values = new T*[_rows];
		for (int i = 0; i < _rows; i++) {
			_values[i] = new T[_columns];

			for (int j = 0; j < _columns; j++) {
				_values[i][j] = right._values[i][j];
			}
		}

		return *this;
	}

	friend Matrix<T> operator*(Matrix<T>& left, double right) {
		Matrix<T> result = left;

		for (int i = 0; i < result._rows; i++) {
			for (int j = 0; j < result._columns; j++) {
				result._values[i][j] = result._values[i][j] * right;
			}
		}

		return result;
	}
};
