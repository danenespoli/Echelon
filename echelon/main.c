#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void help() {
	printf("mult            multiply two matrices\n");
	printf("eigen           calculate eigenvalues and eigenvectors of a matrix\n");
}

void mult() {
	printf("Enter dimensions of Matrix A & Matrix B:\n");
	int rowsA, colsA, rowsB, colsB;
	printf("A   Rows Cols:\n");
	scanf("%d %d", &rowsA, &colsA);
	printf("B   Rows Cols:\n");
	scanf("%d %d", &rowsB, &colsB);
	if (colsA != rowsB) { printf("Columns in A must equal rows in B"); return; }

	matrix A = scanMatrix(rowsA, colsA);
	printf("\n");
	matrixPrint(A);
	matrix B = scanMatrix(rowsB, colsB);
	printf("\n");
	matrixPrint(B);
	printf("AxB:\n");
	matrixPrint(matrixMult(A, B));
}



int main() {
	//printf("\nEchelon\nEnter 'help' for instructions\n");
	matrix A = matrixMake(3, 4);
	matrix B = matrixMake(4, 3);
	matrixPrint(A);
	printf("%g\n", matVal(B, 0, 0));
	printf("%g\n", matVal(B, 2, 2));
	printf("%g\n", matVal(B, 3, 2));
	//matVal(B, 0, 0);
	//matrixPrint(B);
	// while(1) {
	// 	printf("\n\n");

	// 	char *cmd;
	// 	scanf("%s", cmd);
	// 	printf("\n");
	// 	if (!strcmp(cmd, "exit")) break;
	// 	if (!strcmp(cmd, "help")) help();
	// 	if (!strcmp(cmd, "mult")) mult();
	// }

	return 0;
}

