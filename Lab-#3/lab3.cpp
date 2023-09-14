#include <iostream>

using namespace std;

class Matrix {
private:
	int rows = 0, cols = 0, sum = 0;
	int** matrix = NULL;

	void initMatrix(int row, int col) {
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols]();
		}
	}

	void freeMatrix() {
		for (int i = 0; i < rows; i++) {
			delete [] matrix[i];
		}
		delete [] matrix;
	}

public:
	Matrix(){
		initMatrix(0, 0);
	}
	Matrix(int a): rows(a), cols(a){
		initMatrix(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = (i == j) ? 1 : 0;
			}
		}
	}
	Matrix(int r, int c) : rows(r), cols(c) {
		initMatrix(rows, cols);
	}
	void fillMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = i*j;
			}
		}
	}
	void writingMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "[" << rows - 1 << "|" << cols - 1 << "] " << "[" << i << "|" << j << "]: ";
				cin >> matrix[i][j];
			}
			cout << endl;
		}
	}
	void randMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = rand() % 10;
			}
		}
	}
	void printMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	void getSum() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				sum += matrix[i][j];
			}
		}
		cout << "Sum is: " << sum << endl;
	}
	~Matrix() {
		if(matrix)
			freeMatrix();
	}
};


int main() {
	Matrix M1, M2(3), M3(3, 4), M4(2, 3);
	cout << ">>>>>>>1<<<<<<<" << endl;
	M2.printMatrix();
	M3.printMatrix();
	M4.printMatrix();
	cout << ">>>>>>>2<<<<<<<" << endl;
	M2.fillMatrix();
	M2.printMatrix();
	cout << ">>>>>>>3<<<<<<<" << endl;
	M3.randMatrix();
	M3.printMatrix();
	cout << ">>>>>>>4<<<<<<<" << endl;
	M4.writingMatrix();
	M4.printMatrix();
	cout << ">>>>>>>5<<<<<<<" << endl;
	M3.getSum();
	return 0;
}