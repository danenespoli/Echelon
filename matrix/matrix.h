#ifndef MATRIX_H
#define MATRIX_H

typedef struct vector {
	double *x;
	int rows;
} vector;

vector vectorMake(int rows);
double vecVal(vector v, int r);
void vectorSet(vector v, int r, double val);
void vectorPrint(vector v);

double dotProduct(vector p, vector q);



typedef struct matrix {
	int rows;
	int cols;
	double **e;
} matrix;

matrix matrixMake(int rows, int cols);
double matVal(matrix a, int r, int c);
void matrixSet(matrix a, int r, int c, double val);
void matrixPrint(matrix a);
matrix scanMatrix(int rows, int cols);

// vector vectorFromCol(matrix a, int col);
// vector vectorFromRow(matrix a, int row);
matrix matrixMult(matrix a, matrix b);



#endif