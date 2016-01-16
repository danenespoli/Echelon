#include <stdio.h>
#include <stdlib.h>
//#include "matrix.h"
//#include "vector.h"

// typedef struct vector {
// 	double *x;
// 	int rows;
// } vector;

vector vectorMake(int rows) {
	vector v = {.rows = rows, .x = calloc(rows, sizeof(double))};
	return v;
}

int *entry(vector v, int r) {
	return (v.x+r);
}



void vectorPrint(vector v) {
	for (int r=0; r<v.rows; r++) printf("%d\n", *entry(v,r));
}