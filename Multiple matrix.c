#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int** data;
	int rows;
	int cols;
} Matrix;

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			printf("%d ", matrix[i][j]);
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

int** transpose(int** matrix, int row, int col) {

	int** matrix_T = (int**)malloc(col * sizeof(int*));

	for (int i = 0; i < col; i++) {
		matrix_T[i] = (int*)malloc(row * sizeof(int));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
			matrix_T[j][i] = matrix[i][j];
		}
	}

	return matrix_T;


}

int** multiplyMatrix(int** A, int** B, int A_row, int B_row, int B_col) {


	int** matrix = malloc(A_row * sizeof(int*));

	for (int i = 0; i < A_row; i++) {
		matrix[i] = malloc(B_col * sizeof(int));
	}

	int** B_t = transpose(B, B_row, B_col);

	for (int i = 0; i < A_row; i++) {
		for (int j = 0; j < B_col; j++) {
			matrix[i][j] = sumProd(A[i], B_t[j], B_row);
		}
	}

	return matrix;
}

int main()
{
	int data_A[] = {1,4,2,5,3,6};
	int data_B[] = {7,8,9,10,11,12};

	Matrix A = { createMatrix(A.rows, A.cols, data_A), 3, 2 };

	//int** A = ;
	//int** B = createMatrix(2, 3, data_B);

	//int** B_t = transpose(B, 2, 3);
	//printMatrix(B_t, 3, 2);

	//int a[] = { -1,1 };
	//int b[] = { 100, 2 };

	//int x = sumProd(&a, &b, 2);
	//printf("%d", x);

	printMatrix(A.data, A.rows, A.cols);
	//printMatrix(B, 2, 3);

	//int** mat = multiplyMatrix(A, B, 3, 2, 3);
	//printMatrix(mat, 3, 3);
}


