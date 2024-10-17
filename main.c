#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rows;
	int cols;
	int** data;
} Matrix;

void printMatrix(Matrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {

			printf("%d ", matrix.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int** createMatrix(int rows, int cols, int data[]) {

	int** matrix = malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		matrix[i] = malloc(cols * sizeof(int));
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int index = i * cols + j;
			matrix[i][j] = data[index];
		}
	}
	return matrix;
}

int sumProd(int* arr1, int* arr2, int len) {

	int sum = 0;
	int i = 0;

	while (i < len) {
		sum += *(arr1 + i) * *(arr2 + i);
		i++;
	}

	return sum;
}

Matrix transpose(Matrix M) {


	int** matrix_data = (int**)malloc(M.cols * sizeof(int*));

	for (int i = 0; i < M.cols; i++) {
		matrix_data[i] = (int*)malloc(M.rows * sizeof(int));
	}

	for (int i = 0; i < M.rows; i++) {
		for (int j = 0; j < M.cols; j++){
			matrix_data[j][i] = M.data[i][j];
		}
	}

	Matrix matrix_T = { M.cols, M.rows, matrix_data };


	return matrix_T;


}

Matrix multiplyMatrix(Matrix A, Matrix B) {


	int** matrix = malloc(A.rows * sizeof(int*));

	for (int i = 0; i < A.rows; i++) {
		matrix[i] = malloc(B.cols * sizeof(int));
	}

	Matrix B_t = transpose(B);

	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < B.cols; j++) {
			matrix[i][j] = sumProd(A.data[i], B_t.data[j], B.rows);
		}
	}

	Matrix result = { A.rows, B.cols, matrix };

	return result;
}

int main()
{
	int data_A[] = {1,4,2,5,3,6};
	int data_B[] = {7,8,9,10,11,12};


	Matrix A = { 3, 2, createMatrix(A.rows, A.cols, data_A)};
	Matrix B = { 2, 3, createMatrix(B.rows, B.cols, data_B)};


	printMatrix(A);
	printMatrix(B);

	Matrix mat = multiplyMatrix(A, B);
	printMatrix(mat);
}


