#include <iostream>

int main() {
	int row1, col1, row2, col2;

	for (; std::cin >> row1 >> col1 >> row2 >> col2;) {
		int** matrixA = new int* [row1];
		for (int i = 0; i < row1; i++) matrixA[i] = new int[col1];
		int** matrixB = new int* [row2];
		for (int i = 0; i < row2; i++) matrixB[i] = new int[col2];
		int** res = new int* [row1];
		for (int i = 0; i < row1; i++) res[i] = new int[col2] {};

		for (int i = 0; i < row1; i++) {
			for (int k = 0; k < col1; k++) {
				std::cin >> matrixA[i][k];
			}
		}
		for (int i = 0; i < row2; i++) {
			for (int k = 0; k < col2; k++) {
				std::cin >> matrixB[i][k];
			}
		}

		if (row2 == col1) {
			for (int i = 0; i < row1; i++) {
				for (int j = 0; j < col2; j++) {
					for (int k = 0; k < col1; k++) {
						res[i][j] += matrixA[i][k] * matrixB[k][j];
					}
				}
			}

			for (int i = 0; i < row1; i++) {
				for (int k = 0; k < col2; k++) {
					std::cout << res[i][k];
					if (k != col2 - 1) std::cout << ' ';
				}
				std::cout << '\n';
			}
		}
		else {
			std::cout << "Matrix multiplication failed.\n";
		}

		for (int i = 0; i < row1; i++) {
			delete[] matrixA[i];
			delete[] res[i];
		}
		for (int i = 0; i < row2; i++) delete[] matrixB[i];
		delete[] matrixA;
		delete[] matrixB;
		delete[] res;
	}

	return 0;
}