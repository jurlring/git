#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, * x, max, tmp;
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = n - 1; i > 0; i--) {
		max = i;
		for (int j = 0; j <= i; j++) {
			if (x[max] < x[j])
				max = j;
		}
		tmp = x[max];
		x[max] = x[i];
		x[i] = tmp;
	}
	for (int i = 0; i < n; i++)
		printf(" %d", x[i]);
}