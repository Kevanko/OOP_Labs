#include <iostream>

using namespace std;

template <class T>
class Matrix {
private:
	int rows, cols;
	T** matrix;

	void initMatrix() {
		matrix = new T* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new T[cols]();
		}
	}

	void freeMatrix() {
		if (matrix == nullptr) return;
		for (int i = 0; i < rows; i++) {
			delete [] matrix[i];
		}
		delete [] matrix;
	}

public:
	Matrix() : rows(0), cols(0){
		initMatrix();
	}
	Matrix(int r, int c) : rows(r), cols(c) {
		initMatrix();
	}

	T GetM(int i, int j) {
		if (i < 0 || j < 0 || i >= rows || j >= cols) return 0;
		return matrix[i][j];
	}

	void SetM(int i, int j, T value) {
		if (i < 0 || j < 0 || i >= rows || j >= cols) return;
		matrix[i][j] = value;
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	Matrix &operator=(const Matrix& M) {
		freeMatrix();
		rows = M.rows;
		cols = M.cols;
		initMatrix();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = M.matrix[i][j];
			}
		}
		return *this;
	}

	~Matrix() {
		freeMatrix();
	}
};


int main() {
	int i, j;
	cout << "PART 1" << endl;
	Matrix<int> M1(3, 4), M2(1, 1);
	M1.print();
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			M1.SetM(i, j, i + j);
	M2 = M1;
	M2.print();
	cout << "PART 2" << endl;
	Matrix<float> M3(3, 4), M4(1, 1);
	M3.print();
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			M3.SetM(i, j, (i + j) * 0.5);
	M4 = M3;
	M4.print();
	return 0;
}