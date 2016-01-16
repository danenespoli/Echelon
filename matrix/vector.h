#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
	int *x;
	int rows;
} vector;

vector vectorMake(int rows);


#endif