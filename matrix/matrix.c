#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

//VECTOR ALGEBRA
vector vectorMake(int rows) {
	vector v = {.rows = rows, .x = calloc(rows, sizeof(double))};
	return v;
}
double *vec(vector v, int r) {	//vector value at r
	return (v.x+r);
}
double vecVal(vector v, int r) {
	return *vec(v, r);
}
void vectorSet(vector v, int r, double val) {
	*vec(v, r) = val;
}
void vectorPrint(vector v) {
	for (int r=0; r<v.rows; r++) printf("%g\n", *vec(v,r));
}

double dotProduct(vector p, vector q) {
	assert(p.rows == q.rows);	//two vectors must have same domain
	double dot = 0;
	for (int r=0; r<p.rows; r++) dot += vecVal(p, r) * vecVal(q, r);	//sum product of corresponding row entries
	return dot;
}
vector vectorScalarMult(vector v, double t) {
	for (int r=0; r<v.rows; r++) {
		vectorSet(v, r, t * vecVal(v, r));
	}
}
double norm(vector v) {
	return sqrt(dotProduct(v, v));
}
vector proj(vector x, vector n) {
	assert(x.rows == n.rows);	//must have same domain

}



//MATRIX ALGEBRA
matrix matrixMake(int rows, int cols) {
	matrix A = {.rows = rows, .cols = cols, .e = malloc(rows * sizeof(double *))};
	for (int i=0; i<cols; i++) *(A.e+i) = calloc(cols, sizeof(double));
	return A;
}
double *mat(matrix A, int r, int c) {	//matrix value at (r, c)
	//assumes user calls first row 'row 0', first col 'col 0'
	return (*(A.e+r)+c);
}
double matVal(matrix A, int r, int c) {
	return *mat(A, r, c);
}
void matrixSet(matrix A, int r, int c, double val) {
	*mat(A, r, c) = val;
}
void matrixPrint(matrix A) {
	for (int r=0; r<A.rows; r++) {
		for (int c=0; c<A.cols; c++) printf("%g ", *mat(A, r, c));
		printf("\n");
	}
	printf("\n");
}
matrix scanMatrix(int rows, int cols) {
	matrix A = matrixMake(rows, cols);
	printf("Enter Matrix:\n");
	for (int r=0; r<rows; r++) {
		for (int c=0; c<cols; c++) {
			scanf("%lg", mat(A, r, c)); 
		}           
	}
	printf("\n");
	return A;
}

vector vectorFromCol(matrix A, int col) {
	vector v = vectorMake(A.rows);	//vector will have 'rows' # of entries
	for (int r=0; r<A.rows; r++) vectorSet(v, r, matVal(A, r, col));	//iterate through rows of matrix, setting vector@row = matrix@(row, specified col)
	return v;
}
vector vectorFromRow(matrix A, int row) {
	vector v = vectorMake(A.cols);	//vector will have 'cols' # of entries
	for (int c=0; c<a.cols; c++) vectorSet(v, c, matVal(A, row, c));	//iterate through cols of matrix, setting vector@col = matrix@(specified row, col)
	return v;
}
matrix matrixMult(matrix A, matrix B) {
	assert(A.cols == B.rows);	//if A is mxn, B must be nxo
	matrix AB = matrixMake(A.rows, B.cols);	//resulting matrix is mxo
	for (int r=0; r<A.rows; r++) {
		for (int c=0; c<B.cols; c++) {
			vector p = vectorFromRow(A, r);
			vector q = vectorFromCol(B, c);
			matrixSet(AB, r, c, dotProduct(p, q));	//dot rows of a with columns of b
		}
	}
	return AB;
}
matrix matrixScalarMult(matrix A, double t) {
	matrix Z = matrixMake(A.rows, A.cols);
	for (int r=0; r<A.rows; r++) {
		for (int c=0; c<A.cols; c++) {
			matrixSet(Z, r, c, t * matVal(A, r, c));
		}
	}
}

int orthogonalMatrix(matrix A) {
	for (int c0=0; c0<A.cols; c0++) {
		for (int c1=c0+1; c1<A.cols; c1++) {	//dot every column with every other column, must dot to 0 to be orthogonal
			if (dotProduct(vectorFromCol(A, c0), vectorFromCol(A, c1)) != 0) return 0;
		}
	}
	return 1;
}

//Square Matrices
double tr(matrix A) {
	//sum of diagonal components
	assert(A.rows == A.cols);
	double trace = 0;
	for (int i=0; i<A.rows; i++) trace += matVal(A, i, i);
	return trace;
}
double eigen(matrix A) {
	
}
double det(matrix A) {
	//cofactor expansion along first column

}




