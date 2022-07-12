#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <stdio.h>
typedef struct vector_int {
	int number_of_elements;
	int capacity;
	int* elem;
} vector_int;
int is_vector_empty(vector_int* v);
int size(vector_int* v);
void vector_create_int(vector_int* v, int size);
void vector_push_back_int(vector_int* v, int c);
void resize_int(vector_int* v);
void vector_print_int(vector_int* v);
#endif