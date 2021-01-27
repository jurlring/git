#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, * x, max, tmp, i, j;
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0) {
			if (x[j] < x[j - 1]) {
				tmp = x[j];
				x[j] = x[j - 1];
				x[j - 1] = tmp;
			}
			j--;
		}
	}
	for (int i = 0; i < n; i++)
		printf(" %d", x[i]);
}