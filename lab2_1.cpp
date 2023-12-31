#include <iostream>
#define N 3

using namespace std;

void printArr(int* arr) {
    for (int i = 0; i < N * N; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    int** matrix = new int* [N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = rand() % 10;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int arr[N * N] = { 0 };
    int k = 0;

    // a) По правым диагоналям, начиная с правого верхнего элемента
    // правая часть
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j <= i; j++) {
            arr[k++] = matrix[j][N - 1 - i + j];
        }
    }
    // левая часть
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= N - 1 - i; j++) {
            arr[k++] = matrix[i + j][j];
        }
    }

    cout << "a) ";
    printArr(arr);

    // б) По левым диагоналям, начиная с левого верхнего элемента
    k = 0;
    // правая часть
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            arr[k++] = matrix[j][i - j];
        }
    }
    // левая часть
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= N - 1 - i; j++) {
            arr[k++] = matrix[i + j][N - 1 - j];
        }
    }
    cout << "b) ";
    printArr(arr);

    // в) по спирали, начиная с центрального элемента

    k = 0;
    int center = N / 2;
    if(center % 2 == 0 && center > 0)
	center -= 1;
    int t = 0;
    int left = 0, right = 0, bottom = 0, top = 0;
    arr[k++] = matrix[center][center];
    while (k < N * N) {
        t++;
        for (int i = 1; i <= t && k < N * N; i++) { //right
            arr[k++] = matrix[center - top][center - left + i];
        }
        right++;
        for (int i = 1; i <= t && k < N * N; i++) { //bottom
            arr[k++] = matrix[center - top + i][center + right];
        }
        bottom++;
        t++;
        for (int i = 1; i <= t && k < N * N; i++) { //left
            arr[k++] = matrix[center + bottom][center + right - i];
        }
        left++;
        for (int i = 1; i <= t && k < N * N; i++) { //top
            arr[k++] = matrix[center + bottom - i][center - left];
        }
        top++;
 
    }
    cout << "c) ";
    printArr(arr);

    // d) по спирали, начиная с левого верхнего элемента

    k = 0;
    left = 0, right = 0, bottom = 0, top = 0;
    t = N;
    while (k < N * N) {
        for (int i = 0; i < t && k < N * N; i++) { // top
            arr[k++] = matrix[top][left + i];
        }
        top++;
        t--;
        for (int i = 0; i < t && k < N * N; i++) {
            arr[k++] = matrix[top + i][N - 1 - right];
        }
        right++;
        for (int i = 0; i < t && k < N * N; i++) {
            arr[k++] = matrix[N - 1 - bottom][N - 1 - right - i];
        }
        t--;
        bottom++;
        for (int i = 0; i < t && k < N * N; i++) {
            arr[k++] = matrix[N - 1 - bottom - i][left];
        }
        left++;

    }
    cout << "d) ";
    printArr(arr);

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

	return 0;
}
