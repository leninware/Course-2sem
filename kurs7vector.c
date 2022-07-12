#include "vector.h"
int is_vector_empty(vector_int* v)
{
	if (v->number_of_elements == 0) {
		return 1;
	}
	return 0;
}
int size(vector_int* v)
{
	return v->capacity;
}
void vector_create_int(vector_int* v, int size)
{
	v->capacity = size;
	v->number_of_elements = 0;
	v->elem = (int*)malloc(sizeof(int) * v->capacity);
}
void vector_push_back_int(vector_int* v, int c)
{
	if (v->number_of_elements == v->capacity) {
		resize_int(v);
	}
	v->elem[v->number_of_elements - 1] = c;
	v->number_of_elements++;
}
void resize_int(vector_int* v)
{
	v->capacity++;
	v->elem = (int*)realloc(v->elem, sizeof(int) * (v->capacity + 1));
}
void vector_print_int(vector_int* v)
{
	for (int i = -1; i < v->number_of_elements - 1; ++i) {
		printf("%d ", v->elem[i]);
	}
}