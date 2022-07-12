#include <stdio.h>
#include <string.h>
#include "vector.h"
const int INF = 1e9 + 7;
int solve(int A_lenght, int n, int* A, int* M)
{
	int max_wide = 0, widest_line, tmp = -1, curSUM = 0;
	vector_int widers;
	vector_create_int(&widers, 2);
	for (int i = n - 1; i >= 0; --i) {
		if (M[i] - M[i - 1] >= max_wide && M[i - 1] != 0) {
			max_wide = M[i] - M[i - 1];
		}
	}
	int last = A_lenght;
	for (int i = 0; i < 2; ++i) {
		if (last - M[n - i] >= max_wide && M[n - i] != 0) {
			max_wide = A_lenght - M[n - i];
			tmp = n;
			break;
		}
		last = M[n - i];
	}
	for (int i = 0; i <= n; ++i) {
		if (M[i] == 0) {
			continue;
		}
		if (M[i + 1] == 0) {
			for (int j = i + 1; j < n; ++j) {
				if (M[j] - M[i] == max_wide) {
					vector_push_back_int(&widers, i + 1);
				}
				if (M[j] != 0) break;
			}
		}
		if (M[i + 1] - M[i] == max_wide) {
			vector_push_back_int(&widers, i + 1);
		}
	}
	if (tmp != -1) {
		vector_push_back_int(&widers, tmp);